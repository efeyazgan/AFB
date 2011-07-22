//=====================================================================-*-C++-*-
// File and Version Information:
//      $Id: RooUnfoldExample.cxx 248 2010-10-04 22:18:19Z T.J.Adye $
//
// Description:
//      Simple example usage of the RooUnfold package using toy MC.
//
// Authors: Tim Adye <T.J.Adye@rl.ac.uk> and Fergus Wilson <fwilson@slac.stanford.edu>
//          Applied to CMS AFB analysis by Efe Yazgan <efe.yazgan@cern.ch>
//
//==============================================================================

#if !defined(__CINT__) || defined(__MAKECINT__)
#include <iostream>
using std::cout;
using std::endl;

#include "TRandom.h"
#include "TH1.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH1F.h"
#include "TChain.h"
#include "TMath.h"
#include <TVector.h>
#include <TVector3.h>
#include "TCanvas.h"
#include "TFile.h"
#include "Riostream.h"
#include <fstream>

#include "RooGlobalFunc.h"
#include "RooUnfold.h"
#include "RooUnfoldResponse.h"
#include "RooUnfoldBayes.h"
#include "RooUnfoldSvd.h"
#include "RooUnfoldBinByBin.h"
#include "RooUnfoldErrors.h"
#endif

//==============================================================================
// Global definitions
//==============================================================================

const Double_t cutdummy= -99999.0;

//==============================================================================
// Gaussian smearing, systematic translation, and variable inefficiency
//==============================================================================

Double_t smear (Double_t xt)
{
  Double_t xeff= 0.3 + (1.0-0.3)/20*(xt+10.0);  // efficiency
  Double_t x= gRandom->Rndm();
  if (x>xeff) return cutdummy;
  Double_t xsmear= gRandom->Gaus(-2.5,0.2);     // bias and smear
  return xt+xsmear;
}

//==============================================================================
// Example Unfolding
//==============================================================================

void RooUnfoldExample()
{
#ifdef __CINT__
  gSystem->Load("libRooUnfold");
#endif

  TFile *file_cov = new TFile("Data_output.root","RECREATE");
  file_cov->cd(); 

 
  /*
    TChain myTree("demo/MuonTree");
    myTree.Add("/data2/efe/ntuples/386/DY_MuMu_UPDATED_powheg_wo_HLT_filter.root");
  */
  //myTree.Add("/tmp/efe/DY_MuMu_UPDATED_powheg_wo_HLT_filter.root");
 
  TChain myTree("analyzeBasicPat/MuonTree");
/*
  myTree.Add("/data2/efe/ntuples/keng/DoubleMu_May10ReReco_v2.root");
  myTree.Add("/data2/efe/ntuples/keng/DoubleMu_Run2011A_June24.root");
*/

  myTree.Add("/data1/efe/ntuples/keng/data/DoubleMu_May10ReReco_MuPhysR2.root");
  myTree.Add("/data1/efe/ntuples/keng/data/DoubleMu_Run2011A_July06_MuPhys.root");	


  ///MC///
  /*
  myTree.Add("/data2/efe/ntuples/keng/DYToMuMu_winter10_v3_1.root");
  myTree.Add("/data2/efe/ntuples/keng/DYToMuMu_winter10_v3_2.root");
  myTree.Add("/data2/efe/ntuples/keng/DYToMuMu_winter10_v3_3.root");
  myTree.Add("/data2/efe/ntuples/keng/DYToMuMu_winter10_v3_4.root");
  myTree.Add("/data2/efe/ntuples/keng/DYToMuMu_winter10_v3_5.root");
  myTree.Add("/data2/efe/ntuples/keng/DYToMuMu_winter10_v3_6.root");
  myTree.Add("/data2/efe/ntuples/keng/DYToMuMu_winter10_v3_7.root");
  myTree.Add("/data2/efe/ntuples/keng/DYToMuMu_winter10_v3_8.root");
  myTree.Add("/data2/efe/ntuples/keng/DYToMuMu_winter10_v3_9.root");
  myTree.Add("/data2/efe/ntuples/keng/DYToMuMu_winter10_v3_10.root");
  myTree.Add("/data2/efe/ntuples/keng/DYToMuMu_winter10_v3_11.root");
  myTree.Add("/data2/efe/ntuples/keng/DYToMuMu_winter10_v3_12.root");
  myTree.Add("/data2/efe/ntuples/keng/DYToMuMu_winter10_v3_13.root");
  */
  ////
  TH1::AddDirectory(true);
  int event; 
  //  int run,lumi,bxnumber;
  int realdata;
  //  int hlt_trigger_fired;
  //int sort_index_for_mu_tree;
  int MuInx;
  float RecMuonPt[50], RecMuonEta[50], RecMuonPhi[50],RecMuonPx[50], RecMuonPy[50], RecMuonPz[50], RecMuonM[50], RecMuonE[50], RecMuonGlobalType[50], RecMuonTrackerType[50], RecMuonStandAloneType[50], RecMuonIsoSumPt[50], RecMuonIsoRelative[50], RecMuonIsoCalComb[50], RecMuonIsoDY[50], RecMuonglmuon_dxy[50];
  //float RecMuonglmuon_dz[50];
  float RecMuonglmuon_normalizedChi2[50];
  //float RecMuonIsoHad[50],RecMuonIsoEm[50];
  int RecMuonglmuon_trackerHits[50],RecMuontkmuon_pixelhits[50],RecMuonglmuon_muonHits[50],RecNumberOfUsedStations[50];
  //int hltmatchedmuon[50],hltmatched_Dimuon[50];
   
  //particle information
  //int par_index, mom[50], daug[50]; 
  int GenInx;
  float ParticlePt[500], ParticleEta[500], ParticlePhi[500], ParticlePx[500], ParticlePy[500], ParticlePz[500], ParticleE[500], ParticleM[500];
  //int ParticleId[50], ParticleStatus[50], ParticleMother[50][10], ParticleDaughter[50][10];
  int GenStatus[50], GenID[50] ;
  //  int id_muon[20];
  int RecMuonglmuon_charge[50];
  //reco jets 
  //int reco_jet;
  int pfNjets;
  //float RecJetPt[50], RecJetEta[50], RecJetPhi[50], RecJetPx[50], RecJetPy[50], RecJetPz[50], RecJetE[50];
  //int techTrigger[44];
  //  float RecCorrJetPt[50];
  //  float JetEMF[50],JetN90[50],JetFHPD[50],JetFRBX[50];
  //  float PFjetEta[30], PFjetPhi[30],PFjetPt[30],PFCorrjetPt[30],PFjetCEMF[30],PFjetNEMF[30];
  float PFjetEta[100], PFjetPhi[100],PFjetPt[100],PFjetRawPt[100],PFjetCEMF[100],PFjetNEMF[100];

  //met 
  //float caloMET, caloSET, pfMET, pfSET;
  //float caloMETX, pfMETX;
  //float caloMETY, pfMETY;
  //float muCorrMET, muCorrSET;

  int nVertices;
  int nGoodVertices;
  float vtxZ[50],vtxZerr[50];
  float vtxY[50],vtxYerr[50];
  float vtxX[50],vtxXerr[50];
  int vtxisValid[50],vtxisFake[50];
  myTree.SetBranchAddress("event",  &event);
  //  myTree.SetBranchAddress("run", &run);
  //  myTree.SetBranchAddress("lumi", &lumi);
  //  myTree.SetBranchAddress("bxnumber", &bxnumber);
  myTree.SetBranchAddress("realdata",&realdata);
  //  myTree.SetBranchAddress("hlt_trigger_fired",&hlt_trigger_fired);
  //  myTree.SetBranchAddress("sort_index_for_mu_tree",&sort_index_for_mu_tree);
  myTree.SetBranchAddress("MuInx",&MuInx);
  myTree.SetBranchAddress("RecMuonPt",RecMuonPt);
  myTree.SetBranchAddress("RecMuonEta",RecMuonEta);
  myTree.SetBranchAddress("RecMuonPhi",RecMuonPhi);
  myTree.SetBranchAddress("RecMuonPx",RecMuonPx);
  myTree.SetBranchAddress("RecMuonPy",RecMuonPy);
  myTree.SetBranchAddress("RecMuonPz",RecMuonPz);
  myTree.SetBranchAddress("RecMuonE",RecMuonE);
  myTree.SetBranchAddress("RecMuonM",RecMuonM);
  myTree.SetBranchAddress("RecMuonGlobalType",RecMuonGlobalType);
  myTree.SetBranchAddress("RecMuonTrackerType",RecMuonTrackerType);
  myTree.SetBranchAddress("RecMuonStandAloneType",RecMuonStandAloneType);
  myTree.SetBranchAddress("RecMuonIsoSumPt",RecMuonIsoSumPt);
  myTree.SetBranchAddress("RecMuonIsoRelative",RecMuonIsoRelative);
  myTree.SetBranchAddress("RecMuonIsoCalComb",RecMuonIsoCalComb);
  myTree.SetBranchAddress("RecMuonIsoDY",RecMuonIsoDY);
  //
  /*
    myTree.SetBranchAddress("RecMuonIsoHad",RecMuonIsoHad);
    myTree.SetBranchAddress("RecMuonIsoEm",RecMuonIsoEm);
  */
  //
  myTree.SetBranchAddress("RecMuonglmuon_dxy",RecMuonglmuon_dxy);
  myTree.SetBranchAddress("RecMuonglmuon_normalizedChi2",RecMuonglmuon_normalizedChi2);
  myTree.SetBranchAddress("RecMuonglmuon_trackerHits",RecMuonglmuon_trackerHits);
  myTree.SetBranchAddress("RecMuonglmuon_muonHits",RecMuonglmuon_muonHits);
  myTree.SetBranchAddress("RecMuontkmuon_pixelhits",RecMuontkmuon_pixelhits);
  myTree.SetBranchAddress("RecMuonglmuon_charge",RecMuonglmuon_charge);
  /*
    myTree.SetBranchAddress("hltmatchedmuon",hltmatchedmuon);
    myTree.SetBranchAddress("hltmatched_Dimuon",hltmatchedmuon);
  */
  //  myTree.SetBranchAddress("id_muon",id_muon);
  /*
    myTree.SetBranchAddress("techTrigger",techTrigger);
    myTree.SetBranchAddress("par_index", &par_index);
  */
  myTree.SetBranchAddress("GenInx", &GenInx);
  myTree.SetBranchAddress("GenStatus", GenStatus);
  myTree.SetBranchAddress("GenID", GenID);
  myTree.SetBranchAddress("ParticlePt", ParticlePt);
  myTree.SetBranchAddress("ParticleEta", ParticleEta);
  myTree.SetBranchAddress("ParticlePhi", ParticlePhi);
  myTree.SetBranchAddress("ParticlePx", ParticlePx);
  myTree.SetBranchAddress("ParticlePy", ParticlePy);
  myTree.SetBranchAddress("ParticlePz", ParticlePz);
  myTree.SetBranchAddress("ParticleE", ParticleE);
  myTree.SetBranchAddress("ParticleM", ParticleM);
  /*
    myTree.SetBranchAddress("ParticleId", ParticleId);
    myTree.SetBranchAddress("mom", mom);
    myTree.SetBranchAddress("daug", daug);
    myTree.SetBranchAddress("ParticleStatus", ParticleStatus);
    myTree.SetBranchAddress("ParticleMother", ParticleMother);
    myTree.SetBranchAddress("ParticleDaughter", ParticleDaughter);


    //recojets
    myTree.SetBranchAddress("reco_jet",&reco_jet);

    myTree.SetBranchAddress("RecCorrJetPt",RecCorrJetPt);
    myTree.SetBranchAddress("JetEMF",JetEMF);
    myTree.SetBranchAddress("JetN90",JetN90);
    myTree.SetBranchAddress("JetFHPD",JetFHPD);
    myTree.SetBranchAddress("JetFRBX",JetFRBX);

    myTree.SetBranchAddress("RecJetPt",RecJetPt);
    myTree.SetBranchAddress("RecJetEta",RecJetEta);
    myTree.SetBranchAddress("RecJetPhi",RecJetPhi);
    myTree.SetBranchAddress("RecJetPx",RecJetPx);
    myTree.SetBranchAddress("RecJetPy",RecJetPy);
    myTree.SetBranchAddress("RecJetPz",RecJetPz);
    myTree.SetBranchAddress("RecJetE",RecJetE);
    myTree.SetBranchAddress("caloMET", &caloMET);
    myTree.SetBranchAddress("caloSET", &caloSET);
    myTree.SetBranchAddress("pfMET", &pfMET);
    myTree.SetBranchAddress("pfSET", &pfSET);
    myTree.SetBranchAddress("caloMETX", &caloMETX);
    myTree.SetBranchAddress("pfMETX", &pfMETX);
    myTree.SetBranchAddress("caloMETY", &caloMETY);
    myTree.SetBranchAddress("pfMETY", &pfMETY);
    myTree.SetBranchAddress("muCorrMET", &muCorrMET);
    myTree.SetBranchAddress("muCorrSET", &muCorrSET);
  */
  myTree.SetBranchAddress("RecNumberOfUsedStations",RecNumberOfUsedStations);

  myTree.SetBranchAddress("pfNjets",&pfNjets);
  myTree.SetBranchAddress("PFjetEta",PFjetEta);
  myTree.SetBranchAddress("PFjetPhi",PFjetPhi);
  myTree.SetBranchAddress("PFjetPt",PFjetPt);
  myTree.SetBranchAddress("PFjetRawPt",PFjetRawPt);
  myTree.SetBranchAddress("PFjetCEMF",PFjetCEMF);
  myTree.SetBranchAddress("PFjetNEMF",PFjetNEMF);
  //  myTree.SetBranchAddress("PFCorrjetPt",PFCorrjetPt);

  myTree.SetBranchAddress("nVertices",&nVertices);
  myTree.SetBranchAddress("nGoodVertices",&nGoodVertices);
  myTree.SetBranchAddress("vtxX",vtxX);
  myTree.SetBranchAddress("vtxY",vtxY);
  myTree.SetBranchAddress("vtxZ",vtxZ);
  myTree.SetBranchAddress("vtxXerr",vtxXerr);
  myTree.SetBranchAddress("vtxYerr",vtxYerr);
  myTree.SetBranchAddress("vtxZerr",vtxZerr);
  myTree.SetBranchAddress("vtxisValid",vtxisValid);
  myTree.SetBranchAddress("vtxisFake",vtxisFake);


  int nb = 13;
  int nbcos = 8;
  float xAxis_AFB[nb+1]; 
  xAxis_AFB[0] = 40;
  xAxis_AFB[1] = 50;
  xAxis_AFB[2] = 60;
  xAxis_AFB[3] = 70;
  xAxis_AFB[4] = 80;
  xAxis_AFB[5]  = 88.5;
  xAxis_AFB[6]  = 93.5;
  xAxis_AFB[7] = 96;
  xAxis_AFB[8] = 106;
  xAxis_AFB[9] = 120;
  xAxis_AFB[10] = 150;
  xAxis_AFB[11] = 200;
  xAxis_AFB[12] = 600;
  xAxis_AFB[13] = 1500;
  /*
    xAxis_AFB[0] = 40;
    xAxis_AFB[1] = 50;
    xAxis_AFB[2] = 60;
    xAxis_AFB[3] = 76;
    xAxis_AFB[4] = 86;
    xAxis_AFB[5] = 91;
    xAxis_AFB[6] = 96;
    xAxis_AFB[7] = 106;
    xAxis_AFB[8] = 120;
    xAxis_AFB[9] = 150;
    xAxis_AFB[10] = 200;
    xAxis_AFB[11] = 600;
  */
  int nb_Y = 4;
  float Y_bin_limits[nb_Y+1]; 
  Y_bin_limits[0] = 0.0;
  Y_bin_limits[1] = 1.0;
  Y_bin_limits[2] = 1.25;
  Y_bin_limits[3] = 1.5;
  Y_bin_limits[4] = 2.1;
 
  char name_h[100];
  TH1D *hMeasCos_M_Y[30][5];
  for (int i=0;i<nb;i++){
    for (int j=0;j<nb_Y;j++){
      sprintf(name_h,"hMeasCos_M_%i_Y_%i_",i,j);
      hMeasCos_M_Y[i][j] = new TH1D(name_h,name_h,nbcos,-1.,1.);
      hMeasCos_M_Y[i][j]->Sumw2();
    }
  }  

  TH1D *hMass = new TH1D("hMass","hMass",nb,xAxis_AFB);
  hMass->Sumw2();

  Int_t nevent = myTree.GetEntries();
  //nevent = 2000000;
  for (Int_t iev=0;iev<nevent;iev++) {
    if (iev%100000 == 0) cout<<iev<<"/"<<nevent<<endl;
    myTree.GetEntry(iev);


    int common = 0;
    float ptcut = 20;





    float MZ__RECO = 0;
    float sab__RECO = 1./sqrt(2.);
    float costhetaCSreco__RECO = -9999;
    float Qreco__RECO = -9999;
    float QZreco__RECO = -9999;
    float QTreco__RECO = -9999;
    float P1preco__RECO = -9999;
    float P2preco__RECO = -9999;
    float P1mreco__RECO = -9999;
    float P2mreco__RECO = -9999;
    float p1dotp2__RECO = -9999;
  
    int index1[10],index2[10];//if (RecMuonIsoSumPt[j]/RecMuonPt[j] > 0.15) continue;   
    for (int j = 0; j < MuInx; ++j){
      for (int jk = j; jk < MuInx; ++jk){
	/*
	  for (int j = 0; j < sort_index_for_mu_tree; ++j){
	  for (int jk = j; jk < sort_index_for_mu_tree; ++jk){
	*/
        if (j == jk) continue;
        TVector3 mom1(RecMuonPx[j],RecMuonPy[j],RecMuonPz[j]);
        TVector3 mom2(RecMuonPx[jk],RecMuonPy[jk],RecMuonPz[jk]);
        float cosine = mom1.Angle(mom2) - TMath::Pi();    
        if ((RecMuonglmuon_charge[j]*RecMuonglmuon_charge[jk]) == -1 && //common1
            RecMuonPt[j] > ptcut && RecMuonPt[jk] > ptcut && //common2
	    RecMuonIsoSumPt[j] < 3. && RecMuonIsoSumPt[jk] < 3. &&
	    //            RecMuonIsoDY[j] < 0.15 && RecMuonIsoDY[jk] < 0.15 &&
	    //(RecMuonIsoSumPt[j] + RecMuonIsoHad[j])/RecMuonPt[j] < 0.15 && (RecMuonIsoSumPt[jk] + RecMuonIsoHad[jk])/RecMuonPt[jk] < 0.15 &&//!!!!!!!!!
            fabs(RecMuonEta[j]) <2.1 && fabs(RecMuonEta[jk]) <2.1 && //common3
	    //	    (hltmatchedmuon[j] == 1 || hltmatchedmuon[jk] == 1) &&//!!!!!!!!!!!!!!!!!!!!
            fabs(RecMuonglmuon_dxy[j]) < 0.2 && fabs(RecMuonglmuon_dxy[jk]) < 0.2){
	  if (cosine < -0.025){
	    index1[common] = j;
	    index2[common] = jk;
	    common++;
          }
	}
      }
    }

    int loose1 = 0;
    int loose2 = 0;
    int tight_hltalso1 = 0;
    int tight_hltalso2 = 0;
    int select = 0;
    float MZmuon = 0;
    float Ymuon = -9999.;
    float qT = 0;
    int ind1 = -99;
    int ind2 = -99;

    //------------------------Muon ID--------------------------------------------

    for (int gg = 0;gg<common;++gg){
      ind1 = index1[gg];
      ind2 = index2[gg];
      if (RecMuontkmuon_pixelhits[ind1] >= 1 && RecMuonglmuon_trackerHits[ind1] > 10) loose1 = 1;
      if (RecMuontkmuon_pixelhits[ind2] >= 1 && RecMuonglmuon_trackerHits[ind2] > 10) loose2 = 1;
      if (RecMuonglmuon_normalizedChi2[ind1] < 10 && RecMuonglmuon_muonHits[ind1] >= 1 && RecNumberOfUsedStations[ind1] > 1) tight_hltalso1 = 1;
      if (RecMuonglmuon_normalizedChi2[ind2] < 10 && RecMuonglmuon_muonHits[ind2] >= 1 && RecNumberOfUsedStations[ind2] > 1) tight_hltalso2 = 1;
    }

    if (((loose1 && tight_hltalso2) && (loose2 && tight_hltalso1)) && ind1!=-99 && ind2!=-99){//or replaced by and
      float p1dotp2 = RecMuonPx[ind1]*RecMuonPx[ind2]+RecMuonPy[ind1]*RecMuonPy[ind2]+RecMuonPz[ind1]*RecMuonPz[ind2];
      MZmuon = RecMuonM[ind1]+RecMuonM[ind2]+2*(RecMuonE[ind1]*RecMuonE[ind2]-p1dotp2);
      if (MZmuon < 0.) MZmuon = -1.*sqrt(fabs(MZmuon));
      if (MZmuon > 0.) MZmuon = sqrt(MZmuon);
      Ymuon = 0.5*log((RecMuonE[ind1]+RecMuonE[ind2]+RecMuonPz[ind1]+RecMuonPz[ind2])/(RecMuonE[ind1]+RecMuonE[ind2]-RecMuonPz[ind1]-RecMuonPz[ind2]));
      qT = sqrt(pow(RecMuonPx[ind1] + RecMuonPx[ind2],2)+pow(RecMuonPy[ind1] + RecMuonPy[ind2],2));
      if (MZmuon > 40.){   
	hMass->Fill(MZmuon);
	select = 1;
	p1dotp2__RECO = RecMuonPx[ind1]*RecMuonPx[ind2]+RecMuonPy[ind1]*RecMuonPy[ind2]+RecMuonPz[ind1]*RecMuonPz[ind2];
	MZ__RECO  = RecMuonM[ind1]+RecMuonM[ind2]+2*(RecMuonE[ind1]*RecMuonE[ind2]-p1dotp2__RECO);
	MZ__RECO = sqrt(MZ__RECO);
	Qreco__RECO = MZ__RECO;
	QTreco__RECO = sqrt(pow((RecMuonPx[ind1]+RecMuonPx[ind2]),2)+pow((RecMuonPy[ind1]+RecMuonPy[ind2]),2));
	if (RecMuonglmuon_charge[ind1] == -1){
	  P1preco__RECO = sab__RECO*(RecMuonE[ind1]+RecMuonPz[ind1]);
	  P1mreco__RECO = sab__RECO*(RecMuonE[ind1]-RecMuonPz[ind1]);
	  P2preco__RECO = sab__RECO*(RecMuonE[ind2]+RecMuonPz[ind2]);
	  P2mreco__RECO = sab__RECO*(RecMuonE[ind2]-RecMuonPz[ind2]);
	}
	if (RecMuonglmuon_charge[ind1] == +1){
	  P1preco__RECO = sab__RECO*(RecMuonE[ind2]+RecMuonPz[ind2]);
	  P1mreco__RECO = sab__RECO*(RecMuonE[ind2]-RecMuonPz[ind2]);
	  P2preco__RECO = sab__RECO*(RecMuonE[ind1]+RecMuonPz[ind1]);
	  P2mreco__RECO = sab__RECO*(RecMuonE[ind1]-RecMuonPz[ind1]);
	}
	QZreco__RECO = RecMuonPz[ind1]+RecMuonPz[ind2];
	costhetaCSreco__RECO = (2/(Qreco__RECO*sqrt(Qreco__RECO*Qreco__RECO+QTreco__RECO*QTreco__RECO)))*(P1preco__RECO*P2mreco__RECO-P1mreco__RECO*P2preco__RECO);
	if (QZreco__RECO < 0.) costhetaCSreco__RECO = -costhetaCSreco__RECO;
      }//mass window
      // break;
    }




      if (select){
	for (int j=0;j<nb_Y;j++){
	  for (int i=0;i<nb;i++){
	    if (MZmuon > xAxis_AFB[i] && MZmuon < xAxis_AFB[i+1]){
	      if (fabs(Ymuon) > Y_bin_limits[j] && fabs(Ymuon) < Y_bin_limits[j+1]){ 
		hMeasCos_M_Y[i][j]->Fill(costhetaCSreco__RECO);
	      }
	    }
	  }
	}
      }

    

    

  }//end of event loop
  

  TCanvas *c_rap[nb_Y];
  char name_outfile[100];
  for (int j=0;j<nb_Y;j++){
    c_rap[j] = new TCanvas();
    c_rap[j]->Divide(4,3);
    for (int i=0;i<nb;i++){
      c_rap[j]->cd(i+1);
      hMeasCos_M_Y[i][j]->Draw("SAMES");//!!!!
    }
    sprintf(name_outfile,"Data_Y%i_%i_costheta.C",j,j+1);
    c_rap[j]->SaveAs(name_outfile);
  }

  
  TCanvas *c_AFB = new TCanvas();
  c_AFB->Divide(2,2);
  char name_outhisto[100];
  TH1D *h_Meas_Y[nb_Y]; 
  int bin_min,bin_mid,bin_mid_for_backward,bin_max;
  float NF_meas, NB_meas, afb, binw;
  TAxis *axis = hMeasCos_M_Y[0][0]->GetXaxis();
  bin_mid = axis->FindBin(0.);
  bin_mid_for_backward = bin_mid - 1;
  cout<<"middle bin = "<<bin_mid<<endl;
  bin_min = axis->FindBin(-1.);
  bin_max = axis->FindBin(1.) - 1;
  binw = axis->GetBinWidth(bin_mid);
  for (int j=0;j<nb_Y;j++){
    c_AFB->cd(j+1);
    gPad->SetLogx();
    sprintf(name_outhisto,"h_Meas_Y%i",j+1);
    h_Meas_Y[j] = new TH1D(name_outhisto,name_outhisto,nb, xAxis_AFB);
    for (int i=0;i<nb;i++){
      NF_meas = hMeasCos_M_Y[i][j]->Integral(bin_mid,bin_max);//!!!!
      NB_meas = hMeasCos_M_Y[i][j]->Integral(bin_min,bin_mid_for_backward);//!!!!
      afb = (NF_meas-NB_meas)/(NF_meas+NB_meas);
      h_Meas_Y[j]->SetBinContent(i+1,afb);
      h_Meas_Y[j]->SetBinError(i+1,sqrt((1-afb*afb)/(binw*(NF_meas+NB_meas))));
    }
    h_Meas_Y[j]->SetLineColor(4);
    h_Meas_Y[j]->GetYaxis()->SetRangeUser(-1,1);
    h_Meas_Y[j]->Draw("");
  }
  
  c_AFB->SaveAs("Data_AFB.C");
  
  for (int i=0;i<nb;i++){
    for (int j=0;j<nb_Y;j++){
      sprintf(name_h,"DATA_meas_%i_%i",i,j);
      file_cov->WriteTObject(hMeasCos_M_Y[i][j],name_h);
    }
  }
  file_cov->Write();


  TCanvas *del = new TCanvas();
  hMass->Draw();
  del->SaveAs("hMass_data.C");


}

#ifndef __CINT__
int main () { RooUnfoldExample(); return 0; }  // Main program when run stand-alone
#endif
