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
#include <TLorentzVector.h>
#include <TTree.h>

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


void RooUnfoldDeriveFSR()
{
#ifdef __CINT__
  gSystem->Load("libRooUnfold");
#endif

  //TFile *f = new TFile("/uscms_data/d2/goodyoun/work/grad/summer11met_zee2_skim.root");
  //TFile *f = new TFile("/data1/efe/ntuples/censkim_rest1_hfres2_summer11big_zee.root");
  TFile *f = new TFile("/tmp/efe/censkim_rest1_hfres2_summer11big_zee.root");
  TFile *file_cov = new TFile("Electron_MCpowheg_Meas_NoFsr_eta25_res_fixedJul27.root","RECREATE");
  file_cov->cd(); 
 
  TTree* myTree;
  myTree = (TTree*)f->Get("tree");
  //myTree = (TTree*)f->Get("myzeeEGTree/EGTree");
  //TChain myTree("myzeeEGTree/EGTree");

  TH1::AddDirectory(true);

  Int_t event, run, realdata;
  float mass, cs, y, genMZ, genMZ_st1, genCS, genY;
  int genS, recoS;
  
  myTree->SetBranchAddress("mass",&mass);
  myTree->SetBranchAddress("cs",&cs);
  myTree->SetBranchAddress("y",&y);
  myTree->SetBranchAddress("genMZ",&genMZ);
  myTree->SetBranchAddress("genMZ_st1",&genMZ_st1);
  myTree->SetBranchAddress("genCS",&genCS);
  myTree->SetBranchAddress("genY",&genY);
  myTree->SetBranchAddress("genS",&genS);
  myTree->SetBranchAddress("recoS",&recoS);

  myTree->SetBranchAddress("event",&event);
  myTree->SetBranchAddress("run",&run);
  myTree->SetBranchAddress("realdata",&realdata);

  //myTree->SetBranchAddress("genPx",genPx_);
  //myTree->SetBranchAddress("genPy",genPy_);
  //myTree->SetBranchAddress("genPz",genPz_);
  //myTree->SetBranchAddress("genE",genE_);

  //myTree->SetBranchAddress("sort_index_for_e_tree",&sort_index_for_e_tree); 
  //myTree->SetBranchAddress("RecEPx",RecEPx_);
  //myTree->SetBranchAddress("RecEPy",RecEPy_);
  //myTree->SetBranchAddress("RecEPz",RecEPz_);
  //myTree->SetBranchAddress("RecEE",RecEE_);

  float r_test = 0.5;
  int nb = 13;
  int nbcos = 8;
  float xAxis_AFB[14]; 
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
  
  int nb_Y = 4;
  float Y_bin_limits[5]; 
  Y_bin_limits[0] = 0.0;
  Y_bin_limits[1] = 1.0;
  Y_bin_limits[2] = 1.25;
  Y_bin_limits[3] = 1.5;
  Y_bin_limits[4] = 2.1;

  TH1D *hMeasCos_M_Y[30][5];
  TH1D *hNoFsrTruthCos_M_Y[30][5];
  TH1D *hdummy_m2[30][5];
  TH1D *hdummy_t2[30][5];
  char name_h[100],name_1[100],name_2[100];
  RooUnfoldResponse* resp_2[13][4];
  TH1D *hMeasCos_M_Y_fsr_up[30][5];
  TH1D *hMeasCos_M_Y_fsr_down[30][5];
  for (int i=0;i<nb;i++){
    for (int j=0;j<nb_Y;j++){
      sprintf(name_h,"hMeasCos_M_%i_Y_%i_",i,j);
      hMeasCos_M_Y[i][j] = new TH1D(name_h,name_h,nbcos,-1.,1.);
      hMeasCos_M_Y[i][j]->Sumw2();
      sprintf(name_h,"hNoFsrTruthCos_M_%i_Y_%i",i,j);
      hNoFsrTruthCos_M_Y[i][j] = new TH1D(name_h,name_h,nbcos,-1.,1.);
      hNoFsrTruthCos_M_Y[i][j]->Sumw2();

      sprintf(name_1,"dummy_m2_M_%i_Y_%i",i,j);
      hdummy_m2[i][j] = new TH1D(name_1,name_1,nbcos,-1.,1.);
      sprintf(name_1,"dummy_t2_M_%i_Y_%i",i,j);
      hdummy_t2[i][j] = new TH1D(name_1,name_1,nbcos,-1.,1.);
      sprintf(name_2,"respCos2_M_%i_Y_%i",i,j);
      resp_2[i][j] = new RooUnfoldResponse(hdummy_m2[i][j],hdummy_t2[i][j],name_2,name_2);

      sprintf(name_h,"hMeasCos_fsr_up_M_%i_Y_%i_",i,j);
      hMeasCos_M_Y_fsr_up[i][j] = new TH1D(name_h,name_h,nbcos,-1.,1.);
      sprintf(name_h,"hMeasCos__fsr_down_M_%i_Y_%i_",i,j);
      hMeasCos_M_Y_fsr_down[i][j] = new TH1D(name_h,name_h,nbcos,-1.,1.);
    }
  }
  TH1D* h_MZ_st3 = new TH1D("h_MZ_st3","",nb, xAxis_AFB);
  TH1D* h_MZ_st1 = new TH1D("h_MZ_st1","",nb, xAxis_AFB);
  TH1D* h_MZ_st1_minus_st3 = new TH1D("h_MZ_st1_minus_st3","",100,-20, 10);  
  
  TH1D *hMass = new TH1D("hMass","hMass",nb,xAxis_AFB);

  Int_t nevent = myTree->GetEntries();

  for (Int_t iev=0;iev<nevent;iev++) {
    if (iev%100000 == 0) cout<<iev<<"/"<<nevent<<endl;
    myTree->GetEntry(iev);

    double MZ=0; double MZ_st1=0; 
    double gen_costhetaCSreco = 0;
    double dielecrapidity = 0;
    int gen_select = 0;
    	
   


    //if(!realdata){

    //TLorentzVector p4gen1(genPx_[0],genPy_[0],genPz_[0],genE_[0]); 
    //TLorentzVector p4gen2(genPx_[1],genPy_[1],genPz_[1],genE_[1]);	

    MZ = genMZ;    
    gen_costhetaCSreco = genCS;
    dielecrapidity = genY;
    if(genS==21 || genS==25)gen_select = 1;

    MZ_st1 = genMZ_st1;

    float delta_fsr = MZ_st1-MZ;
    h_MZ_st1_minus_st3->Fill(delta_fsr);
    
    int tag_event = 0;tag_event = 1;
    if (delta_fsr < -1) tag_event = 1;
    

    int select = 0;
    double MZelec = 0; double Yelec = 0;
    double costhetaCSreco__RECO = 0;
    
    MZelec= mass;

    if(recoS==21 || recoS==25)select = 1; 
    costhetaCSreco__RECO = cs;
    Yelec = y;	

 
    
    if (!realdata){
      if (iev && gen_select){// < nevent*r_test && gen_select){//!!!!!!
 	for (int j=0;j<nb_Y;j++){
	  for (int i=0;i<nb;i++){
	    if (MZ > xAxis_AFB[i] && MZ < xAxis_AFB[i+1]){
	      if (fabs(dielecrapidity) >= Y_bin_limits[j] && fabs(dielecrapidity) < Y_bin_limits[j+1]){ 
		hNoFsrTruthCos_M_Y[i][j]->Fill(gen_costhetaCSreco);
		if (select) resp_2[i][j]->Fill(costhetaCSreco__RECO,gen_costhetaCSreco);
		if (!select) resp_2[i][j]->Miss(gen_costhetaCSreco);
	      }
	    }
	  }
	}       
      }
      
      //      if (iev > nevent*r_test && select){
      if (select){
       	for (int j=0;j<nb_Y;j++){
	  for (int i=0;i<nb;i++){
	    if (MZelec > xAxis_AFB[i] && MZelec < xAxis_AFB[i+1]){
	      if (fabs(Yelec) > Y_bin_limits[j] && fabs(Yelec) < Y_bin_limits[j+1]){ 
		hMeasCos_M_Y[i][j]->Fill(costhetaCSreco__RECO);
	      }
	    }
	    //---FSR systematics----
	    float MZelec_fsr_up = MZelec;
	    float MZelec_fsr_down = MZelec;
	    if (tag_event) MZelec_fsr_up = 1.05*MZelec;
	    if (tag_event) MZelec_fsr_down = 0.95*MZelec;
	    if (MZelec_fsr_up > xAxis_AFB[i] && MZelec_fsr_up < xAxis_AFB[i+1]){
	      if (fabs(Yelec) > Y_bin_limits[j] && fabs(Yelec) < Y_bin_limits[j+1]) hMeasCos_M_Y_fsr_up[i][j]->Fill(costhetaCSreco__RECO);
	    }
	    if (MZelec_fsr_down > xAxis_AFB[i] && MZelec_fsr_down < xAxis_AFB[i+1]){
	      if (fabs(Yelec) > Y_bin_limits[j] && fabs(Yelec) < Y_bin_limits[j+1]) hMeasCos_M_Y_fsr_down[i][j]->Fill(costhetaCSreco__RECO);
	    }	    
	    //----------------------
	  }
	}
      }
    }
    
    
  }//end of event loop
  
  for (int i=0;i<nb;i++){
    for (int j=0;j<nb_Y;j++){
      sprintf(name_h,"MC_meas_%i_%i",i,j);
      file_cov->WriteTObject(hMeasCos_M_Y[i][j],name_h);
      sprintf(name_h,"truth_no_fsr_%i_%i",i,j);
      file_cov->WriteTObject(hNoFsrTruthCos_M_Y[i][j],name_h);
      sprintf(name_h,"response2_%i_%i",i,j);
      file_cov->WriteTObject(resp_2[i][j],name_h);

      sprintf(name_h,"MC_meas_fsr_up_%i_%i",i,j);
      file_cov->WriteTObject(hMeasCos_M_Y_fsr_up[i][j],name_h);
      sprintf(name_h,"MC_meas_fsr_down_%i_%i",i,j);
      file_cov->WriteTObject(hMeasCos_M_Y_fsr_down[i][j],name_h);
    }
  }
  //  file_cov->Write();

  h_MZ_st1_minus_st3->SaveAs("fsr_check.C");

  TCanvas *del = new TCanvas();
  hMass->Draw();
  del->SaveAs("hMass_MC.C");
 
 
  //file_cov->Write();



  //}
}

#ifndef __CINT__
int main () { RooUnfoldDeriveFSR(); return 0; }  // Main program when run stand-alone
#endif


