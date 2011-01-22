#include "TRandom.h"
#include "TH1D.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TChain.h"
#include "TF2.h"
#include "TLegend.h"
#include "TH1F.h"
#include "TPostScript.h"
#include "TLine.h"
#include "TEllipse.h"
#include "TMath.h"
#include "TMatrixD.h"
#include "TMatrixDBase.h"
#include "TLatex.h"

#include <TMath.h>
#include <TFitter.h>
#include <TVector.h>
#include <TF1.h>
#include <TGraph.h>
#include "TUnfold.h"
#include "TSystem.h"
#include "TCanvas.h"
#include "TFile.h"

using namespace std;
void tree1r()
{
  TChain myTree("demo/MuonTree");
  //myTree.Add("/data2/efe/ntuples/386/DY_powheg_wo_HLT_filter.root");
  ////myTree.Add("/data2/efe/ntuples/386/386_2_minbias_sept17_132440_135735.root");                                                                     
  myTree.Add("/data2/efe/ntuples/386/386_Run2010B_Nov4ReReco_v1_146428_149442.root");
  myTree.Add("/data2/efe/ntuples/386/386_2_Run2010A_Nov4ReReco_v1_136033_144114.root");  
  TH1::AddDirectory(true);
  int event,run,lumi,bxnumber,realdata;
  int hlt_trigger_fired;
  int sort_index_for_mu_tree;
  float RecMuonPt[50], RecMuonEta[50], RecMuonPhi[50],RecMuonPx[50], RecMuonPy[50], RecMuonPz[50], RecMuonM[50], RecMuonE[50], RecMuonGlobalType[50], RecMuonTrackerType[50], RecMuonStandAloneType[50], RecMuonIsoSumPt[50], RecMuonIsoRelative[50], RecMuonIsoCalComb[50], RecMuonIsoDY[50], RecMuonglmuon_dxy[50], RecMuonglmuon_dz[50], RecMuonglmuon_normalizedChi2[50];
  int RecMuonglmuon_trackerHits[50],RecMuontkmuon_pixelhits[50],RecMuonglmuon_muonHits[50],RecNumberOfUsedStations[50],hltmatchedmuon[50],hltmatched_Dimuon[50] ;
 
  //particle information
  int par_index, mom[50], daug[50];
  float ParticlePt[50], ParticleEta[50], ParticlePhi[50], ParticlePx[50], ParticlePy[50], ParticlePz[50], ParticleE[50], ParticleM[50];
  int ParticleId[50], ParticleStatus[50], ParticleMother[50][10], ParticleDaughter[50][10];
  //  int id_muon[20];
  int RecMuonglmuon_charge[50];
  //reco jets 
  int reco_jet,pfNjets;
  float RecJetPt[50], RecJetEta[50], RecJetPhi[50], RecJetPx[50], RecJetPy[50], RecJetPz[50], RecJetE[50];
  int techTrigger[44];
  float RecCorrJetPt[50];
  float JetEMF[50],JetN90[50],JetFHPD[50],JetFRBX[50];
  float PFjetEta[30], PFjetPhi[30],PFjetPt[30],PFCorrjetPt[30],PFjetCEMF[30],PFjetNEMF[30];

  //met 
  float caloMET, caloSET, pfMET, pfSET;
  float caloMETX, pfMETX;
  float caloMETY, pfMETY;
  float muCorrMET, muCorrSET;

  int nVertices;
  myTree.SetBranchAddress("event",  &event);
  myTree.SetBranchAddress("run", &run);
  myTree.SetBranchAddress("lumi", &lumi);
  myTree.SetBranchAddress("bxnumber", &bxnumber);
  myTree.SetBranchAddress("realdata",&realdata);
  myTree.SetBranchAddress("hlt_trigger_fired",&hlt_trigger_fired);
  myTree.SetBranchAddress("sort_index_for_mu_tree",&sort_index_for_mu_tree);
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
  myTree.SetBranchAddress("RecMuonglmuon_dxy",RecMuonglmuon_dxy);
  myTree.SetBranchAddress("RecMuonglmuon_normalizedChi2",RecMuonglmuon_normalizedChi2);
  myTree.SetBranchAddress("RecMuonglmuon_trackerHits",RecMuonglmuon_trackerHits);
  myTree.SetBranchAddress("RecMuonglmuon_muonHits",RecMuonglmuon_muonHits);
  myTree.SetBranchAddress("RecMuontkmuon_pixelhits",RecMuontkmuon_pixelhits);
  myTree.SetBranchAddress("RecMuonglmuon_charge",RecMuonglmuon_charge);
  myTree.SetBranchAddress("hltmatchedmuon",hltmatchedmuon);
  myTree.SetBranchAddress("hltmatched_Dimuon",hltmatchedmuon);
  //  myTree.SetBranchAddress("id_muon",id_muon);
  myTree.SetBranchAddress("techTrigger",techTrigger);
  myTree.SetBranchAddress("par_index", &par_index);
  myTree.SetBranchAddress("ParticlePt", ParticlePt);
  myTree.SetBranchAddress("ParticleEta", ParticleEta);
  myTree.SetBranchAddress("ParticlePhi", ParticlePhi);
  myTree.SetBranchAddress("ParticlePx", ParticlePx);
  myTree.SetBranchAddress("ParticlePy", ParticlePy);
  myTree.SetBranchAddress("ParticlePz", ParticlePz);
  myTree.SetBranchAddress("ParticleE", ParticleE);
  myTree.SetBranchAddress("ParticleM", ParticleM);
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
  myTree.SetBranchAddress("RecNumberOfUsedStations",RecNumberOfUsedStations);

  myTree.SetBranchAddress("pfNjets",&pfNjets);
  myTree.SetBranchAddress("PFjetEta",PFjetEta);
  myTree.SetBranchAddress("PFjetPhi",PFjetPhi);
  myTree.SetBranchAddress("PFjetPt",PFjetPt);
  myTree.SetBranchAddress("PFjetCEMF",PFjetCEMF);
  myTree.SetBranchAddress("PFjetNEMF",PFjetNEMF);
  myTree.SetBranchAddress("PFCorrjetPt",PFCorrjetPt);

  myTree.SetBranchAddress("nVertices",&nVertices);

  //
 
  /*
  float xAxis_AFB[14] = {15,30,40,50,60,76,86,91,96,106,120,150,200,600};
  float xAxis_AFB_TOPLOT[13] = {22.5,35,45,55,68,81,88.5,93.5,101,113,135,175,400};
  */

  int nb = 11;
  float xAxis_AFB[12] = {40,50,60,76,86,91,96,106,120,150,200,600};
  float xAxis_AFB_TOPLOT[11] = {45,55,68,81,88.5,93.5,101,113,135,175,400};
  

  TFile *theFile = new TFile("Muon_out.root","RECREATE");
  theFile->cd();

  TH1F *h_MZ_F = new TH1F("h_MZ_F","M(Z)#rightarrow #mu#mu",nb,xAxis_AFB  );
  TH1F *h_MZmuon_F = new TH1F("h_MZmuon_F","M(Z)#rightarrow #mu#mu",nb,xAxis_AFB );
  TH1F *h_MZmuon_B = new TH1F("h_MZmuon_B","M(Z)#rightarrow #mu#mu",nb,xAxis_AFB );
  TH1F *h_MZobs_F = new TH1F("h_MZobs_F","M(Z)#rightarrow #mu#mu",nb,xAxis_AFB );
  h_MZobs_F->Sumw2();
  TH1F *h_MZobs_B = new TH1F("h_MZobs_B","M(Z)#rightarrow #mu#mu",nb,xAxis_AFB );
  h_MZobs_B->Sumw2();
  TH1F *h_gen_costhetaCSreco = new TH1F("h_gen_costhetaCSreco","",24,-1.,1.);
  TH1F *h_gen_costhetaCSreco_Acc = new TH1F("h_gen_costhetaCSreco_Acc","",24,-1.,1.);
  TH1F *h_costhetaCSreco__RECO = new TH1F("h_costhetaCSreco__RECO","",24,-1.,1.);


  TH1F *hTrue_F = new TH1F("hTrue_F", "Test Truth F",nb,xAxis_AFB );
  TH1F *hTrue_B = new TH1F("hTrue_B", "Test Truth B",nb,xAxis_AFB );
  TH1F *hTrue_F_before_cuts = new TH1F("hTrue_F_before_cuts", "Test Truth F_before_cuts",nb,xAxis_AFB );
  TH1F *hTrue_B_before_cuts = new TH1F("hTrue_B_before_cuts", "Test Truth B_before_cuts",nb,xAxis_AFB );
  TH1F *h_Unfolded_F = new TH1F("h_Unfolded_F", "Unfolded_F", nb,xAxis_AFB );
  TH1F *h_Unfolded_B = new TH1F("h_Unfolded_B", "Unfolded_B", nb,xAxis_AFB );

  TH1F *h_Unfolded_over_Truth_F = new TH1F("h_Unfolded_over_Truth_F", "", nb,xAxis_AFB );
  TH1F *h_Unfolded_over_Truth_B = new TH1F("h_Unfolded_over_Truth_B", "", nb,xAxis_AFB );

  TH1F *h_AFB_Gen = new TH1F("h_AFB_Gen","h_AFB_Gen",nb,xAxis_AFB );
  h_AFB_Gen->Sumw2();
  TH1F *h_AFB_Gen_Tmp1 = new TH1F("h_AFB_Gen_Tmp1","h_AFB_Gen_Tmp1",nb,xAxis_AFB );
  TH1F *h_AFB_Gen_Tmp2 = new TH1F("h_AFB_Gen_Tmp2","h_AFB_Gen_Tmp2",nb,xAxis_AFB );
  TH1F *h_AFB_Gen_before_cuts = new TH1F("h_AFB_Gen_before_cuts","h_AFB_Gen_before_cuts",nb,xAxis_AFB );
  h_AFB_Gen_before_cuts->Sumw2();
  TH1F *h_AFB_Gen_Tmp1_before_cuts = new TH1F("h_AFB_Gen_Tmp1_before_cuts","h_AFB_Gen_Tmp1_before_cuts",nb,xAxis_AFB );
  TH1F *h_AFB_Gen_Tmp2_before_cuts = new TH1F("h_AFB_Gen_Tmp2_before_cuts","h_AFB_Gen_Tmp2_before_cuts",nb,xAxis_AFB );
  TH1F *h_AFB_Reco = new TH1F("h_AFB_Reco","h_AFB_Reco",nb,xAxis_AFB );
  TH1F *h_AFB_Reco_Tmp1 = new TH1F("h_AFB_Reco_Tmp1","h_AFB_Reco_Tmp1",nb,xAxis_AFB );
  TH1F *h_AFB_Reco_Tmp2 = new TH1F("h_AFB_Reco_Tmp2","h_AFB_Reco_Tmp2",nb,xAxis_AFB );
  TH1F *h_AFB_Obs = new TH1F("h_AFB_Obs","h_AFB_Obs",nb,xAxis_AFB );
  h_AFB_Obs->Sumw2();
  TH1F *h_AFB_Obs_Tmp1 = new TH1F("h_AFB_Obs_Tmp1","h_AFB_Obs_Tmp1",nb,xAxis_AFB );
  h_AFB_Obs_Tmp1->Sumw2();
  TH1F *h_AFB_Obs_Tmp2 = new TH1F("h_AFB_Obs_Tmp2","h_AFB_Obs_Tmp2",nb,xAxis_AFB );  
  h_AFB_Obs_Tmp2->Sumw2();
  TH1F *h_AFB_Unfolded = new TH1F("h_AFB_Unfolded","h_AFB_Unfolded",nb,xAxis_AFB );
  h_AFB_Unfolded->Sumw2();
  TH1F *h_AFB_Unfolded_Tmp1 = new TH1F("h_AFB_Unfolded_Tmp1","h_AFB_Unfolded_Tmp1",nb,xAxis_AFB );
  h_AFB_Unfolded_Tmp1->Sumw2();
  TH1F *h_AFB_Unfolded_Tmp2 = new TH1F("h_AFB_Unfolded_Tmp2","h_AFB_Unfolded_Tmp2",nb,xAxis_AFB );
  h_AFB_Unfolded_Tmp2->Sumw2();
  TH1F *h_acc_corr = new TH1F("h_acc_corr","h_acc_corr",nb,xAxis_AFB );
  h_acc_corr->Sumw2();
  TH1F *h_acc_corr_F = new TH1F("h_acc_corr_F","h_acc_corr_F",nb,xAxis_AFB );
  h_acc_corr_F->Sumw2();
  TH1F *h_acc_corr_B = new TH1F("h_acc_corr_B","h_acc_corr_B",nb,xAxis_AFB );
  h_acc_corr_B->Sumw2();
  TH1F *h_AFB_Unfolded_and_Acceptance_Corrected = new TH1F("h_AFB_Unfolded_and_Acceptance_Corrected"," h_AFB_Unfolded_and_Acceptance_Corrected",nb,xAxis_AFB );
  h_AFB_Unfolded_and_Acceptance_Corrected->Sumw2();
  TH1F *h_Unfolded_and_AcceptanceCorrected_F = new TH1F("h_Unfolded_and_AcceptanceCorrected_F","h_Unfolded_and_AcceptanceCorrected_F",nb,xAxis_AFB);
  TH1F *h_Unfolded_and_AcceptanceCorrected_B = new TH1F("h_Unfolded_and_AcceptanceCorrected_B","h_Unfolded_and_AcceptanceCorrected_B",nb,xAxis_AFB);
  TH1F *h_Unfolded_and_AcceptanceCorrected_Total = new TH1F("h_Unfolded_and_AcceptanceCorrected_Total","h_Unfolded_and_AcceptanceCorrected_Total",nb,xAxis_AFB);
  TH1F *h_Unfolded_and_AcceptanceCorrected_Total_Tmp1 = new TH1F("h_Unfolded_and_AcceptanceCorrected_Total_Tmp1","h_Unfolded_and_AcceptanceCorrected_Total_Tmp1",nb,xAxis_AFB);
  TH1F *h_Unfolded_and_AcceptanceCorrected_Total_Tmp2 = new TH1F("h_Unfolded_and_AcceptanceCorrected_Total_Tmp2","h_Unfolded_and_AcceptanceCorrected_Total_Tmp2",nb,xAxis_AFB);


  TH2F *h_RFF = new TH2F("h_RFF","",nb, xAxis_AFB, nb, xAxis_AFB);
  TH2F *h_RFF_Normalized = new TH2F("h_RFF_Normalized","",nb, xAxis_AFB, nb, xAxis_AFB);
  h_RFF_Normalized->SetTitle("R_{ij}^{FF}");
  h_RFF_Normalized->GetXaxis()->SetTitle("Generated Mass [GeV]");
  h_RFF_Normalized->GetYaxis()->SetTitle("Reconstructed Mass [GeV]");
  TH1F *h_NF_o = new TH1F("h_NF_o","",nb, xAxis_AFB);

  TH2F *h_RBB = new TH2F("h_RBB","",nb, xAxis_AFB, nb, xAxis_AFB);
  TH2F *h_RBB_Normalized = new TH2F("h_RBB_Normalized","",nb, xAxis_AFB, nb, xAxis_AFB);
  h_RBB_Normalized->SetTitle("R_{ij}^{BB}");
  h_RBB_Normalized->GetXaxis()->SetTitle("Generated Mass [GeV]");
  h_RBB_Normalized->GetYaxis()->SetTitle("Reconstructed Mass [GeV]");
  TH1F *h_NB_o = new TH1F("h_NB_o","",nb, xAxis_AFB);

  TH2F *h_RFB = new TH2F("h_RFB","",nb, xAxis_AFB, nb, xAxis_AFB);
  TH2F *h_RFB_Normalized = new TH2F("h_RFB_Normalized","",nb, xAxis_AFB, nb, xAxis_AFB);
  h_RFB_Normalized->SetTitle("R_{ij}^{FB}");
  h_RFB_Normalized->GetXaxis()->SetTitle("Generated Mass [GeV]");
  h_RFB_Normalized->GetYaxis()->SetTitle("Reconstructed Mass [GeV]");

  TH2F *h_RBF = new TH2F("h_RBF","",nb, xAxis_AFB, nb, xAxis_AFB);
  TH2F *h_RBF_Normalized = new TH2F("h_RBF_Normalized","",nb, xAxis_AFB, nb, xAxis_AFB);
  h_RBF_Normalized->SetTitle("R_{ij}^{BF}");
  h_RBF_Normalized->GetXaxis()->SetTitle("Generated Mass [GeV]");
  h_RBF_Normalized->GetYaxis()->SetTitle("Reconstructed Mass [GeV]");

  TH1F *h_abs_genlevel = new TH1F("h_abs_genlevel","",nb,xAxis_AFB);
  TH1F *h_abs_genlevel_F = new TH1F("h_abs_genlevel_F","",nb,xAxis_AFB);
  TH1F *h_abs_genlevel_B = new TH1F("h_abs_genlevel_B","",nb,xAxis_AFB);
  
  TH1F *h_cos_qq = new TH1F("h_cos_qq","",24,-1.,1.);

  TH1F *h_AFB_abs_genlevel = new TH1F("h_AFB_abs_genlevel","",nb,xAxis_AFB);
  TH1F *h_AFB_abs_genlevel_Tmp1 = new TH1F("h_AFB_abs_genlevel_Tmp1","",nb,xAxis_AFB); 
  TH1F *h_AFB_abs_genlevel_Tmp2 = new TH1F("h_AFB_abs_genlevel_Tmp2","",nb,xAxis_AFB);

  float rap_axis[6] = {0,0.5,1,1.5,2,2.5};
  TH2F *hTrue_F_nondiluted = new TH2F("hTrue_F_nondiluted","",nb,xAxis_AFB,5,rap_axis);
  TH2F *hTrue_B_nondiluted = new TH2F("hTrue_B_nondiluted","",nb,xAxis_AFB,5,rap_axis);
  TH2F *hTrue_F_beforecuts_for_dilution = new TH2F("hTrue_F_beforecuts_for_dilution","",nb,xAxis_AFB,5,rap_axis);
  TH2F *hTrue_B_beforecuts_for_dilution = new TH2F("hTrue_B_beforecuts_for_dilution","",nb,xAxis_AFB,5,rap_axis);
  TH2F *h_w = new TH2F("h_w","",nb,xAxis_AFB,5,rap_axis);
  TH1F *hTrue_F_beforecuts_for_dilution_1D_Y = new TH1F("hTrue_F_beforecuts_for_dilution_1D_Y","",5,rap_axis);
  TH1F *hTrue_B_beforecuts_for_dilution_1D_Y = new TH1F("hTrue_B_beforecuts_for_dilution_1D_Y","",5,rap_axis);

  Int_t nevent = myTree.GetEntries();
  float r_test = 0.5;

  int yield_VBTF = 0;
  for (Int_t iev=0;iev<nevent;iev++) {
    if (iev%100000 == 0) cout<<iev<<"/"<<nevent<<endl;
    myTree.GetEntry(iev);
  

    int parpar = 0;
    float parton_pt[50] = {};
    float parton_eta[50] = {};
    float parton_phi[50] = {};
    float parton_px[50] = {};
    float parton_py[50] = {};
    float parton_pz[50] = {};
    float parton_m[50] = {};
    float parton_e[50] = {};
    int parton_id[50] = {};
    int parton_charge[50] = {};

    int qq = 0;
    float quark_pt[50] = {};
    float quark_eta[50] = {};
    float quark_phi[50] = {};
    float quark_px[50] = {};
    float quark_py[50] = {};
    float quark_pz[50] = {};
    float quark_m[50] = {};
    float quark_e[50] = {};
    int quark_id[50] = {};
    int quark_charge[50] = {};
    float emitpart_e = -99.;
    float emitpart_px = -99.;
    float emitpart_py = -99.;
    float emitpart_pz = -99.;
    float emitpart_p = -99.;
    float Z_e = -99.;
    float Z_px = -99.;
    float Z_py = -99.;
    float Z_pz = -99.;
    float Z_p = -99.;

    int posid = -999;
    int negid = -999;
    int quark_pos_id = -999;
    int quark_neg_id = -999;
    for (int ppo = 0;ppo<50;++ppo) parton_id[ppo] = 9999;
    for (int j = 0;j<par_index;++j){
      if (ParticleStatus[j] != 3) continue;
//      cout<<j<<"  "<<ParticleId[j]<<"   "<<ParticleE[j]<<"  "<<sqrt(pow(ParticleE[j],2)-pow(ParticlePx[j],2)-pow(ParticlePy[j],2)-pow(ParticlePz[j],2))<<endl;
      if (abs(ParticleId[j]) == 13){
	parton_pt[parpar] = ParticlePt[j];
	parton_eta[parpar] = ParticleEta[j];
	parton_phi[parpar] = ParticlePhi[j];
	parton_id[parpar] = ParticleId[j];
	parton_px[parpar] = ParticlePx[j];
	parton_py[parpar] = ParticlePy[j];
	parton_pz[parpar] = ParticlePz[j];
	parton_m[parpar] = ParticleM[j];
	parton_e[parpar] = ParticleE[j];
	parton_charge[parpar] = -ParticleId[j]/abs(ParticleId[j]);//because mu- is = 13 not -13
        if (parton_charge[parpar] == -1) posid = parpar;
        if (parton_charge[parpar] == +1) negid = parpar; 
	++parpar;
      }
      if (fabs(ParticleId[j]) >= 1 && fabs(ParticleId[j]) < 5 && j >= 4 && j <= 5){
	quark_pt[qq] = ParticlePt[j];
	quark_eta[qq] = ParticleEta[j];
	quark_phi[qq] = ParticlePhi[j];
	quark_id[qq] = ParticleId[j];
	quark_px[qq] = ParticlePx[j];
	quark_py[qq] = ParticlePy[j];
	quark_pz[qq] = ParticlePz[j];
	quark_m[qq] = ParticleM[j];
	quark_e[qq] = ParticleE[j];
        quark_charge[qq] = ParticleId[j]/abs(ParticleId[j]);
        if (quark_charge[qq] ==  1) quark_pos_id = qq;
        if (quark_charge[qq] == -1) quark_neg_id = qq;
	++qq;
      }
      if (ParticleId[j] == 23){
        Z_e = ParticleE[j];
        Z_px = ParticlePx[j];
        Z_py = ParticlePy[j];
        Z_pz = ParticlePz[j];
        Z_p = sqrt(pow(Z_px,2)+pow(Z_py,2)+pow(Z_pz,2));
      }
      if (j == 7){
        emitpart_e = ParticleE[j];
        emitpart_px = ParticlePx[j];
        emitpart_py = ParticlePy[j];
        emitpart_pz = ParticlePz[j];
        emitpart_p = sqrt(pow(emitpart_px,2)+pow(emitpart_py,2)+pow(emitpart_pz,2));
      }
    }

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

 
    /*
    if (qq == 2 && quark_charge[0]*quark_charge[1] == -1){
      
      float dilepton_angle = (parton_pz[0] + parton_pz[1])/sqrt(pow(parton_px[0]+parton_px[1],2)+pow(parton_py[0]+parton_py[1],2)+pow(parton_pz[0]+parton_pz[1],2));
      float dipx = parton_px[0]+parton_px[1];
      float dipy = parton_py[0]+parton_py[1];
      float dipz = parton_pz[0]+parton_pz[1];
   
      //  cout<<dilepton_angle<<"  "<<Z_pz/Z_p<<endl;
      float muonpos_angle = acos((Z_pz-parton_pz[posid])/sqrt(pow(Z_px-parton_px[posid],2)+pow(Z_py-parton_py[posid],2)+pow(Z_pz-parton_pz[posid],2)));
      float muonneg_angle = acos((Z_pz-parton_pz[negid])/sqrt(pow(Z_px-parton_px[negid],2)+pow(Z_py-parton_py[negid],2)+pow(Z_pz-parton_pz[negid],2)));
      float quarkpos_angle = acos((Z_pz-quark_pz[quark_pos_id]-emitpart_pz)/sqrt(pow(Z_px-quark_px[quark_pos_id]-emitpart_px,2)+pow(Z_py-quark_py[quark_pos_id]-emitpart_py,2)+pow(Z_pz-quark_pz[quark_pos_id]-emitpart_pz,2)));
      float quarkneg_angle = acos((Z_pz-quark_pz[quark_neg_id]-emitpart_pz)/sqrt(pow(Z_px-quark_px[quark_neg_id]-emitpart_px,2)+pow(Z_py-quark_py[quark_neg_id]-emitpart_py,2)+pow(Z_pz-quark_pz[quark_neg_id]-emitpart_pz,2)));
//        cout<<"E : "<<quark_e[0]+quark_e[1]-emitpart_e<<"    "<<sqrt( pow(quark_e[0]+quark_e[1]-emitpart_e,2) - ( pow(quark_px[0]+quark_px[1]-emitpart_px,2)+pow(quark_py[0]+quark_py[1]-emitpart_py,2)+pow(quark_pz[0]+quark_pz[1]-emitpart_pz,2) ))  <<   endl;
        float MZ_test = sqrt( pow(quark_e[0]+quark_e[1]-emitpart_e,2) - ( pow(quark_px[0]+quark_px[1]-emitpart_px,2)+pow(quark_py[0]+quark_py[1]-emitpart_py,2)+pow(quark_pz[0]+quark_pz[1]-emitpart_pz,2) ));
    	h_abs_genlevel->Fill(MZ_test);
	float true_costheta = -99;
	//	true_costheta = (parton_pz[negid]-quark_pz[quark_pos_id])/sqrt(pow(parton_px[negid]-quark_px[quark_pos_id],2)+pow(parton_py[negid]-quark_py[quark_pos_id],2)+pow(parton_pz[negid]-quark_pz[quark_pos_id],2));
	
	true_costheta = cos(muonpos_angle-quarkpos_angle);
	h_cos_qq->Fill(true_costheta);       
	if (true_costheta > 0) h_abs_genlevel_F->Fill(MZ_test);
	if (true_costheta < 0 && true_costheta > -1.0) h_abs_genlevel_B->Fill(MZ_test);
       
    }
    */
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


    //if (!realdata && parpar!=2) continue;

    float MZ = 0;
    float gen_sab = 1./sqrt(2.);
    float gen_costhetaCSreco = -9999;
    float gen_Qreco = -9999;
    float gen_QZreco = -9999;
    float gen_QTreco = -9999;
    float gen_P1preco = -9999;
    float gen_P2preco = -9999;
    float gen_P1mreco = -9999;
    float gen_P2mreco = -9999;
    float p1dotp2_b = -9999.;

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
    p1dotp2_b = parton_px[0]*parton_px[1]+parton_py[0]*parton_py[1]+parton_pz[0]*parton_pz[1];
    MZ = parton_m[0]+parton_m[1]+2*(parton_e[0]*parton_e[1]-p1dotp2_b);
    //if (MZ < 0.) MZ = -1.*sqrt(fabs(MZ));
    MZ = sqrt(MZ);
    
    
    h_MZ_F->Fill(MZ);
    
    gen_Qreco = MZ;
    gen_QTreco = sqrt(pow((parton_px[0]+parton_px[1]),2)+pow((parton_py[0]+parton_py[1]),2));
    if (parton_charge[0] == -1){
      gen_P1preco = gen_sab*(parton_e[0]+parton_pz[0]);
      gen_P1mreco = gen_sab*(parton_e[0]-parton_pz[0]);
      gen_P2preco = gen_sab*(parton_e[1]+parton_pz[1]);
      gen_P2mreco = gen_sab*(parton_e[1]-parton_pz[1]);
    }
    if (parton_charge[0] == +1){
      gen_P1preco = gen_sab*(parton_e[1]+parton_pz[1]);
      gen_P1mreco = gen_sab*(parton_e[1]-parton_pz[1]);
      gen_P2preco = gen_sab*(parton_e[0]+parton_pz[0]);
      gen_P2mreco = gen_sab*(parton_e[0]-parton_pz[0]);
    }
    gen_QZreco = parton_pz[0]+parton_pz[1];
    gen_costhetaCSreco = (2/(gen_Qreco*sqrt(gen_Qreco*gen_Qreco+gen_QTreco*gen_QTreco)))*(gen_P1preco*gen_P2mreco-gen_P1mreco*gen_P2preco);
    //@@@@@@@
    float true_costheta = -99;
    if (qq == 2 && quark_charge[0]*quark_charge[1] == -1){
      float MZ_test = sqrt( pow(quark_e[0]+quark_e[1]-emitpart_e,2) - ( pow(quark_px[0]+quark_px[1]-emitpart_px,2)+pow(quark_py[0]+quark_py[1]-emitpart_py,2)+pow(quark_pz[0]+quark_pz[1]-emitpart_pz,2) ));
      h_abs_genlevel->Fill(MZ_test);

      true_costheta = (2/(gen_Qreco*sqrt(gen_Qreco*gen_Qreco+gen_QTreco*gen_QTreco)))*(gen_P1preco*gen_P2mreco-gen_P1mreco*gen_P2preco);
      if (quark_pz[quark_pos_id] < 0) true_costheta = -true_costheta;
      h_cos_qq->Fill(true_costheta);       
      if (true_costheta > 0) h_abs_genlevel_F->Fill(MZ_test);
      if (true_costheta < 0 && true_costheta > -1.0) h_abs_genlevel_B->Fill(MZ_test);
    }
    //@@@@@@@@@@
    if (gen_QZreco < 0.) gen_costhetaCSreco = -gen_costhetaCSreco;
    h_gen_costhetaCSreco->Fill(gen_costhetaCSreco);
    
    float dimuonrapidity = 0.5*log((parton_e[0]+parton_e[1]+parton_pz[0]+parton_pz[1])/(parton_e[0]+parton_e[1]-parton_pz[0]-parton_pz[1]));



    int common = 0;
    float ptcut = 20;
    int index1[10],index2[10];//if (RecMuonIsoSumPt[j]/RecMuonPt[j] > 0.15) continue;
    for (int j = 0; j < sort_index_for_mu_tree; ++j){
      for (int jk = j; jk < sort_index_for_mu_tree  ; ++jk){
        if (j == jk) continue;
        if ((RecMuonglmuon_charge[j]*RecMuonglmuon_charge[jk]) == -1 && //common1
            RecMuonPt[j] > ptcut && RecMuonPt[jk] > ptcut && //common2
            RecMuonIsoSumPt[j] < 3. && RecMuonIsoSumPt[jk] < 3. &&
            fabs(RecMuonEta[j]) <2.1 && fabs(RecMuonEta[jk]) <2.1 && //common3
	    (hltmatchedmuon[j] == 1 || hltmatchedmuon[jk] == 1) &&
            fabs(RecMuonglmuon_dxy[j]) < 0.2 && fabs(RecMuonglmuon_dxy[jk]) < 0.2){
            index1[common] = j;
            index2[common] = jk;
            common++;
          }
      }
    }

    int loose1 = 0;
    int loose2 = 0;
    int tight_hltalso1 = 0;
    int tight_hltalso2 = 0;
    int select = 0;
    float MZmuon = 0;
    int ind1 = -99;
    int ind2 = -99;
    //if (MZ > 40. && parton_pt[0] > 20. && parton_pt[1] > 20. && fabs(parton_eta[0]) < 2.1 && fabs(parton_eta[1]) < 2.1){


    //------------------------Muon ID--------------------------------------------

    for (int gg = 0;gg<common;++gg){
      ind1 = index1[gg];
      ind2 = index2[gg];
      if (RecMuontkmuon_pixelhits[ind1] >= 1 && RecMuonglmuon_trackerHits[ind1] > 10) loose1 = 1;
      if (RecMuontkmuon_pixelhits[ind2] >= 1 && RecMuonglmuon_trackerHits[ind2] > 10) loose2 = 1;
      if (RecMuonglmuon_normalizedChi2[ind1] < 10 && RecMuonglmuon_muonHits[ind1] >= 1 && RecNumberOfUsedStations[ind1] > 1) tight_hltalso1 = 1;
      if (RecMuonglmuon_normalizedChi2[ind2] < 10 && RecMuonglmuon_muonHits[ind2] >= 1 && RecNumberOfUsedStations[ind2] > 1) tight_hltalso2 = 1;
    }
    //if (ind1 == -99 || ind2 == -99) continue;

    if (((loose1 && tight_hltalso2) && (loose2 && tight_hltalso1)) && ind1!=-99 && ind2!=-99){//or replaced by and
      float p1dotp2 = RecMuonPx[ind1]*RecMuonPx[ind2]+RecMuonPy[ind1]*RecMuonPy[ind2]+RecMuonPz[ind1]*RecMuonPz[ind2];
      MZmuon = RecMuonM[ind1]+RecMuonM[ind2]+2*(RecMuonE[ind1]*RecMuonE[ind2]-p1dotp2);
      if (MZmuon < 0.) MZmuon = -1.*sqrt(fabs(MZmuon));
      if (MZmuon > 0.) MZmuon = sqrt(MZmuon);
      // if (MZmuon > 20.){
      if (MZmuon > 60. && MZmuon < 120.) ++yield_VBTF;
      if (MZmuon > 40.){
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

        h_costhetaCSreco__RECO->Fill(costhetaCSreco__RECO);

      }//mass window
    } ///tight...loose



    // }

    

    if (iev > nevent*r_test && select){
      //------------------FF-----------------------------------------
      if (gen_costhetaCSreco >= 0){
	if (costhetaCSreco__RECO >= 0)
	  h_RFF->Fill(MZ, MZmuon);
      }
      if (costhetaCSreco__RECO >= 0) h_NF_o->Fill(MZmuon);
      //------------------End of FF-----------------------------------------
      //------------------BB-----------------------------------------
      if (gen_costhetaCSreco < 0 && gen_costhetaCSreco >= -1){
	if (costhetaCSreco__RECO < 0 && costhetaCSreco__RECO >= -1)
	  h_RBB->Fill(MZ, MZmuon);
      }
      if (costhetaCSreco__RECO < 0 && costhetaCSreco__RECO >= -1) h_NB_o->Fill(MZmuon);
      //------------------End of BB-----------------------------------------
      //------------------FB-----------------------------------------
      if (gen_costhetaCSreco >= 0){
	if (costhetaCSreco__RECO < 0 && costhetaCSreco__RECO >= -1)
	  h_RFB->Fill(MZ, MZmuon);
      }
      //------------------End of FB-----------------------------------------
      //------------------BF-----------------------------------------
      if (gen_costhetaCSreco < 0 && gen_costhetaCSreco >= -1){
	if (costhetaCSreco__RECO >= 0)
	  h_RBF->Fill(MZ, MZmuon);
      }
      //------------------End of BF-----------------------------------------
    }

 
    if (iev < nevent*r_test){ 
      if (MZ > 40.){
	if (gen_costhetaCSreco >= 0) hTrue_F_before_cuts->Fill(MZ);
	if (gen_costhetaCSreco < 0 && gen_costhetaCSreco >= -1) hTrue_B_before_cuts->Fill(MZ);
	//for dilution corr
	if (true_costheta >= 0) hTrue_F_nondiluted->Fill(MZ,fabs(dimuonrapidity));
	if (true_costheta < 0 && true_costheta >= -1) hTrue_B_nondiluted->Fill(MZ,fabs(dimuonrapidity));
	if (gen_costhetaCSreco >= 0){ 
	  hTrue_F_beforecuts_for_dilution->Fill(MZ,fabs(dimuonrapidity));
	  hTrue_F_beforecuts_for_dilution_1D_Y->Fill(fabs(dimuonrapidity));
	}
	if (gen_costhetaCSreco < 0 && gen_costhetaCSreco >= -1){ 
	  hTrue_B_beforecuts_for_dilution->Fill(MZ,fabs(dimuonrapidity));
	  hTrue_B_beforecuts_for_dilution_1D_Y->Fill(fabs(dimuonrapidity));
	}
	//
      }
    if (select){
	if (MZ > 40. && parton_pt[0] > 20. && parton_pt[1] > 20. && fabs(parton_eta[0]) < 2.1 && fabs(parton_eta[1]) < 2.1){
	  h_gen_costhetaCSreco_Acc->Fill(gen_costhetaCSreco);
	  if (gen_costhetaCSreco >= 0) hTrue_F->Fill(MZ);
	  if (gen_costhetaCSreco < 0 && gen_costhetaCSreco >= -1) hTrue_B->Fill(MZ);	  
	}
	if (costhetaCSreco__RECO >= 0) h_MZmuon_F->Fill(MZmuon);
	if (costhetaCSreco__RECO < 0  && costhetaCSreco__RECO >= -1) h_MZmuon_B->Fill(MZmuon);
      }
  }
    



    if (select){
	if (costhetaCSreco__RECO >= 0) h_MZobs_F->Fill(MZmuon);
	if (costhetaCSreco__RECO < 0  && costhetaCSreco__RECO >= -1) h_MZobs_B->Fill(MZmuon);      
    }
    


  }
  
  float forward[50] = {};
  float backward[50] = {};
  for (int i=1;i<=nb;i++){
    for (int j=1;j<=nb;j++){
      h_RFF_Normalized->SetBinContent(i,j,h_RFF->GetBinContent(i,j)/h_NF_o->GetBinContent(i));
      h_RBB_Normalized->SetBinContent(i,j,h_RBB->GetBinContent(i,j)/h_NB_o->GetBinContent(i));
      h_RFB_Normalized->SetBinContent(i,j,h_RFB->GetBinContent(i,j)/h_NB_o->GetBinContent(i));
      h_RBF_Normalized->SetBinContent(i,j,h_RBF->GetBinContent(i,j)/h_NF_o->GetBinContent(i));
      forward[i] += h_RFF_Normalized->GetBinContent(i,j)*h_MZmuon_F->GetBinContent(i)+h_RFB_Normalized->GetBinContent(i,j)*h_MZmuon_B->GetBinContent(i);
      backward[i] += h_RBB_Normalized->GetBinContent(i,j)*h_MZmuon_B->GetBinContent(i)+h_RBF_Normalized->GetBinContent(i,j)*h_MZmuon_F->GetBinContent(i);
    }
    h_Unfolded_F->SetBinContent(i,forward[i]);
    h_Unfolded_B->SetBinContent(i,backward[i]);
  }


  h_Unfolded_over_Truth_F->Add(h_Unfolded_F);
  h_Unfolded_over_Truth_F->Divide(hTrue_F);

  h_Unfolded_over_Truth_B->Add(h_Unfolded_B);
  h_Unfolded_over_Truth_B->Divide(hTrue_B);

  


  h_AFB_Gen_before_cuts->Add(hTrue_F_before_cuts);
  h_AFB_Gen_Tmp1_before_cuts->Add(hTrue_B_before_cuts);
  h_AFB_Gen_Tmp1_before_cuts->Scale(-1.);
  h_AFB_Gen_before_cuts->Add(h_AFB_Gen_Tmp1_before_cuts);
  h_AFB_Gen_Tmp2_before_cuts->Add(hTrue_F_before_cuts);
  h_AFB_Gen_Tmp2_before_cuts->Add(hTrue_B_before_cuts);
  h_AFB_Gen_before_cuts->Divide(h_AFB_Gen_Tmp2_before_cuts);

  h_AFB_Gen->Add(hTrue_F);
  h_AFB_Gen_Tmp1->Add(hTrue_B);
  h_AFB_Gen_Tmp1->Scale(-1.);
  h_AFB_Gen->Add(h_AFB_Gen_Tmp1);
  h_AFB_Gen_Tmp2->Add(hTrue_F);
  h_AFB_Gen_Tmp2->Add(hTrue_B);
  h_AFB_Gen->Divide(h_AFB_Gen_Tmp2);

  h_AFB_Reco->Add(h_MZmuon_F);
  h_AFB_Reco_Tmp1->Add(h_MZmuon_B);
  h_AFB_Reco_Tmp1->Scale(-1);
  h_AFB_Reco->Add(h_AFB_Reco_Tmp1);
  h_AFB_Reco_Tmp2->Add(h_MZmuon_F);
  h_AFB_Reco_Tmp2->Add(h_MZmuon_B);
  h_AFB_Reco->Divide(h_AFB_Reco_Tmp2);

  h_AFB_Unfolded->Add(h_Unfolded_F);
  h_AFB_Unfolded_Tmp1->Add(h_Unfolded_B);
  h_AFB_Unfolded_Tmp1->Scale(-1);
  h_AFB_Unfolded->Add(h_AFB_Unfolded_Tmp1);
  h_AFB_Unfolded_Tmp2->Add(h_Unfolded_F);
  h_AFB_Unfolded_Tmp2->Add(h_Unfolded_B);
  h_AFB_Unfolded->Divide(h_AFB_Unfolded_Tmp2);

  
  h_AFB_Gen_Tmp1->Delete();
  h_AFB_Gen_Tmp2->Delete();
  h_AFB_Reco_Tmp1->Delete();
  h_AFB_Reco_Tmp2->Delete();
  h_AFB_Unfolded_Tmp1->Delete();
  h_AFB_Unfolded_Tmp2->Delete();


  h_acc_corr->Add(h_AFB_Gen);
  h_acc_corr->Divide(h_AFB_Gen_before_cuts);
  h_AFB_Unfolded_and_Acceptance_Corrected->Add(h_AFB_Unfolded);
  h_AFB_Unfolded_and_Acceptance_Corrected->Divide(h_acc_corr);

  h_acc_corr_F->Add(hTrue_F);
  h_acc_corr_F->Divide(hTrue_F_before_cuts);
  h_Unfolded_and_AcceptanceCorrected_F->Add(h_Unfolded_F);
  h_Unfolded_and_AcceptanceCorrected_F->Divide(h_acc_corr_F);

  h_acc_corr_B->Add(hTrue_B);
  h_acc_corr_B->Divide(hTrue_B_before_cuts);
  h_Unfolded_and_AcceptanceCorrected_B->Add(h_Unfolded_B);
  h_Unfolded_and_AcceptanceCorrected_B->Divide(h_acc_corr_B);

  h_Unfolded_and_AcceptanceCorrected_Total->Add(h_Unfolded_and_AcceptanceCorrected_F);
  h_Unfolded_and_AcceptanceCorrected_Total_Tmp1->Add(h_Unfolded_and_AcceptanceCorrected_B);
  h_Unfolded_and_AcceptanceCorrected_Total_Tmp1->Scale(-1);
  h_Unfolded_and_AcceptanceCorrected_Total->Add(h_Unfolded_and_AcceptanceCorrected_Total_Tmp1);
  h_Unfolded_and_AcceptanceCorrected_Total_Tmp2->Add(h_Unfolded_and_AcceptanceCorrected_F);
  h_Unfolded_and_AcceptanceCorrected_Total_Tmp2->Add(h_Unfolded_and_AcceptanceCorrected_B);  
  h_Unfolded_and_AcceptanceCorrected_Total->Divide(h_Unfolded_and_AcceptanceCorrected_Total_Tmp2);


  cout<<"Mass Bin:         Forward corr   backward corr       Acceptance Corr factor"<<endl;    
  for (int i=1;i<=nb;i++) cout<<i<<"                 "<<hTrue_F->GetBinContent(i)<<" / "<<hTrue_F_before_cuts->GetBinContent(i)<<" = "<<h_acc_corr_F->GetBinContent(i)<<"  "<<hTrue_B->GetBinContent(i)<<" / "<<hTrue_B_before_cuts->GetBinContent(i)<<" = "<<h_acc_corr_B->GetBinContent(i)<<endl;


  cout<<"Yield in 60-120 GeV:   "<<yield_VBTF<<endl;

  h_MZobs_F->SaveAs("h_MZobs_F.C");
  h_MZobs_B->SaveAs("h_MZobs_B.C");


  h_AFB_Obs->Add(h_MZobs_F);
  h_AFB_Obs_Tmp1->Add(h_MZobs_B);
  h_AFB_Obs_Tmp1->Scale(-1);
  h_AFB_Obs->Add(h_AFB_Obs_Tmp1);
  h_AFB_Obs_Tmp2->Add(h_MZobs_F);
  h_AFB_Obs_Tmp2->Add(h_MZobs_B);
  h_AFB_Obs->Divide(h_AFB_Obs_Tmp2);

  h_AFB_Obs->SaveAs("Observed_AFB.C");

//---
  h_AFB_abs_genlevel->Add(h_abs_genlevel_F);
  h_AFB_abs_genlevel_Tmp1->Add(h_abs_genlevel_B);
  h_AFB_abs_genlevel_Tmp1->Scale(-1);
  h_AFB_abs_genlevel->Add(h_AFB_abs_genlevel_Tmp1); 
  h_AFB_abs_genlevel_Tmp2->Add(h_abs_genlevel_F);
  h_AFB_abs_genlevel_Tmp2->Add(h_abs_genlevel_B);
  h_AFB_abs_genlevel->Divide(h_AFB_abs_genlevel_Tmp2);
//----

  float w[20][20];
  float w_av[20];
  for (int i=1;i<=nb;i++){
    w_av[i] = 0;
    for (int j=1;j<=5;j++){
      w[i][j] = hTrue_B_beforecuts_for_dilution->GetBinContent(i,j)*hTrue_F_nondiluted->GetBinContent(i,j)-hTrue_F_beforecuts_for_dilution->GetBinContent(i,j)*hTrue_B_nondiluted->GetBinContent(i,j);
      w[i][j] /= (hTrue_F_beforecuts_for_dilution->GetBinContent(i,j)+hTrue_B_beforecuts_for_dilution->GetBinContent(i,j))*(hTrue_F_nondiluted->GetBinContent(i,j)-hTrue_B_nondiluted->GetBinContent(i,j));
      h_w->SetBinContent(i,j,w[i][j]); 
      w_av[i] += w[i][j];
   }
    w_av[i] /= 5.;
    cout<<i<<"   "<<w_av[i]<<endl;

  }

  TCanvas *c0 = new TCanvas();
  c0->cd();
  h_costhetaCSreco__RECO->GetYaxis()->SetTitle("Number of events / 0.083");
  h_costhetaCSreco__RECO->GetXaxis()->SetTitle("cos#theta_{CS}^{*}");  
  h_costhetaCSreco__RECO->SaveAs("costheta.C");

  TCanvas *c1 = new TCanvas();
  c1->Divide(2,2);
  c1->cd(1);
  gPad->SetLogy();
  gPad->SetLogx();
  h_RFF_Normalized->Draw("colz");
  c1->cd(2);
  gPad->SetLogy();
  gPad->SetLogx();
  h_RFB_Normalized->Draw("colz");
  c1->cd(3);
  gPad->SetLogy();
  gPad->SetLogx();
  h_RBF_Normalized->Draw("colz");
  c1->cd(4);
  gPad->SetLogy();
  gPad->SetLogx();
  h_RBB_Normalized->Draw("colz");
  c1->SaveAs("unfolding_matrices_2D.C");

  TCanvas *c2 = new TCanvas();
  c2->Divide(2,2);
  c2->cd(1);
  gPad->SetLogy();
  gPad->SetLogx();
  h_RFF_Normalized->Draw("lego");
  c2->cd(2);
  gPad->SetLogy();
  gPad->SetLogx();
  h_RFB_Normalized->Draw("lego");
  c2->cd(3);
  gPad->SetLogy();
  gPad->SetLogx();
  h_RBF_Normalized->Draw("lego");
  c2->cd(4);
  gPad->SetLogy();
  gPad->SetLogx();
  h_RBB_Normalized->Draw("lego");
  c2->SaveAs("unfolding_matrices_3D.C");

  TCanvas *c3 = new TCanvas();
  c3->Divide(2,1);
  c3->cd(1);
  gPad->SetLogy();
  gPad->SetLogx();
  hTrue_F->Draw();
  hTrue_F->SetTitle("Forward");
  hTrue_F->GetXaxis()->SetTitle("M_{ll} [GeV]");
  h_MZmuon_F->SetLineColor(4);
  h_MZmuon_F->Draw("sames");
  h_Unfolded_F->SetLineColor(2);
  h_Unfolded_F->SetMarkerColor(2);
  h_Unfolded_F->SetMarkerStyle(8);
  h_Unfolded_F->Draw("e1sames");
  c3->cd(2);
  gPad->SetLogy();
  gPad->SetLogx();
  hTrue_B->Draw();
  hTrue_B->SetTitle("Backward");
  hTrue_B->GetXaxis()->SetTitle("M_{ll} [GeV]");
  h_MZmuon_B->SetLineColor(4);
  h_MZmuon_B->Draw("sames");
  h_Unfolded_B->SetLineColor(2);
  h_Unfolded_B->SetMarkerColor(2);
  h_Unfolded_B->SetMarkerStyle(8);
  h_Unfolded_B->Draw("e1sames");  
  c3->SaveAs("closure.C");

  TCanvas *c4 = new TCanvas();
  c4->Divide(2,1);
  c4->cd(1);
  gPad->SetLogx();
  h_Unfolded_over_Truth_F->GetYaxis()->SetRangeUser(0.89,1.11);
  h_Unfolded_over_Truth_F->SetTitle("Forward");
  h_Unfolded_over_Truth_F->GetXaxis()->SetTitle("M_{ll} [GeV]");
  h_Unfolded_over_Truth_F->Draw();
  c4->cd(2);
  gPad->SetLogx();
  h_Unfolded_over_Truth_B->GetYaxis()->SetRangeUser(0.89,1.11);
  h_Unfolded_over_Truth_B->SetTitle("Backward");
  h_Unfolded_over_Truth_B->GetXaxis()->SetTitle("M_{ll} [GeV]");
  h_Unfolded_over_Truth_B->Draw();
  c4->SaveAs("closure_ratio.C");

  TCanvas *c5 = new TCanvas();
  c5->cd();
  gPad->SetLogx();
  h_AFB_Gen->GetXaxis()->SetTitle("M_{ll} [GeV]");
  h_AFB_Gen->Draw();
  h_AFB_Reco->SetLineColor(4);
  h_AFB_Reco->Draw("sames");
  h_AFB_Unfolded->SetMarkerColor(2);
  h_AFB_Unfolded->SetMarkerStyle(8);
  h_AFB_Unfolded->SetLineColor(2);
  h_AFB_Unfolded->Draw("e1sames");
  c5->SaveAs("afb_closure_test.C");

  TCanvas *c6 = new TCanvas();
  gPad->SetLogx();
  h_acc_corr_F->GetYaxis()->SetRangeUser(0,1);
  h_acc_corr_F->GetXaxis()->SetTitle("M_{ll} [GeV]");
  h_acc_corr_F->GetYaxis()->SetTitle("Acc");
  h_acc_corr_F->SetLineColor(2);
  h_acc_corr_F->SetMarkerColor(2);
  h_acc_corr_F->Draw("e1");
  h_acc_corr_B->SetLineColor(4);
  h_acc_corr_B->SetMarkerColor(4);
  h_acc_corr_B->Draw("e1sames"); 
  c6->SaveAs("acceptance.C");

  TCanvas *c7 = new TCanvas();
  gPad->SetLogx();
  h_AFB_Gen_before_cuts->GetXaxis()->SetTitle("M_{ll} [GeV]");
  h_AFB_Gen_before_cuts->Draw();
  h_AFB_Gen->SetLineColor(4);
  h_AFB_Gen->Draw("sames");
  c7->SaveAs("AFB_acceptance_effects.C");

  


  theFile->Write();
  theFile->Close();



}//end void  

int main(int argc,char **argv){
  tree1r();
}


