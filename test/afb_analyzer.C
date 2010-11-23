#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH2.h"
#include "TH3.h"
#include "TRandom.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "math.h"
#include <fstream>
#include <string>
#include <iostream>
#include <TStyle.h>
#include "TCanvas.h"
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
using namespace std;
void tree1r()
{


  gStyle->SetPalette(1);
  float DeltaR(float eta1, float eta2, float phi1, float phi2);
  float DeltaPhi(float phi1, float phi2);

  TChain myTree("demo/MuonTree");


  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@final set 198.1 nb-1 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  /*
    myTree.Add("/data1/efe/ntuples/7TeV/june14_firstbunch_Zs_monday_wpixandvtx.root");
    myTree.Add("/data1/efe/ntuples/7TeV/135149_monday_wpixandvtx.root");
    myTree.Add("/data1/efe/ntuples/7TeV/muons_promptreco.root");
    myTree.Add("/data1/efe/ntuples/7TeV/muons_july_rereco.root");
    myTree.Add("/data1/efe/ntuples/7TeV/muons_july_rereco_140126_for_missing_event.root");
  */
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //-------------------rest-----------------------------------------------------------------
  /*
    myTree.Add("/data1/efe/ntuples/7TeV/ZASYM/new_wjson_combined_updated.root");
    //myTree.Add("/data2/efe/ntuples/aug23_142928_143179.root");
    myTree.Add("/data2/efe/ntuples/new_wjson_combined_updated_NEW_142928_143336.root");
    myTree.Add("/data2/efe/ntuples/muons_143337_144114_jsonv1.root");
  */
  //----------------------------------------------------------------------------------------

  //@@@@@@@@ 2010B @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //myTree.Add("/data2/efe/ntuples/mureco_2010B_145762_147454.root");
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  //-----------------------------MC  Z_asymmetry---------------------------------------------------------
  //myTree.Add("/data2/efe/ntuples/powheg_very_new.root");

  //-----------------------------MC V+Jets-----------------------------------------------
  //     myTree.Add("/data2/efe/ntuples/zjets_madgraph_Spring10_START3X_V26_S09_v1.root");
  //  myTree.Add("/data2/efe/ntuples/wjets_madgraph_Spring10_START3X_V26_S09_v1.root");
  //  myTree.Add("/data2/efe/ntuples/ttbar_madgraph_Spring10_START3X_V26_S09_v1.root");
  //--------------------------------------------------------------------------------------


  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%3_8_3%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  //data
  /*
  myTree.Add("/data2/efe/ntuples/383/minbias_sept17.root");
  myTree.Add("/data2/efe/ntuples/383/mu_sept17.root");
  myTree.Add("/data2/efe/ntuples/383/2010B_sept17.root");
  */
  myTree.Add("/data2/efe/ntuples/383/DY_powheg.root");
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  //myTree.Add("/data2/efe/pythia.root");
  //myTree.Add("/data1/efe/ntuples/7TeV/zmmpowheg_qedfsr_off.root"); 
  //myTree.Add("/data1/efe/ntuples/7TeV/Aug5_muons_140182_141961.root"); 
  //myTree.Add("/data1/efe/ntuples/7TeV/powhegnew.root");
  //myTree.Add("/data1/efe/ntuples/7TeV/FSRONOFF/fsron_DYToMuMu_M_20_7TeV_powheg_pythia6_Spring10_START3X_V26_v1_WITHGEN.root");//old

  TH1::AddDirectory(true);

  int event,run,lumi,bxnumber,realdata;
  int hlt_trigger_fired;
  int sort_index_for_mu_tree;
  float RecMuonPt[50], RecMuonEta[50], RecMuonPhi[50],RecMuonPx[50], RecMuonPy[50], RecMuonPz[50], RecMuonM[50], RecMuonE[50], RecMuonGlobalType[50], RecMuonTrackerType[50], RecMuonStandAloneType[50], RecMuonIsoSumPt[50], RecMuonIsoRelative[50], RecMuonIsoCalComb[50], RecMuonglmuon_dxy[50], RecMuonglmuon_dz[50], RecMuonglmuon_normalizedChi2[50]; 
  int RecMuonglmuon_trackerHits[50],RecMuontkmuon_pixelhits[50],RecMuonglmuon_muonHits[50],RecNumberOfUsedStations[50],hltmatchedmuon[50];

  //particle information
  int par_index, mom[50], daug[50];
  float ParticlePt[50], ParticleEta[50], ParticlePhi[50], ParticlePx[50], ParticlePy[50], ParticlePz[50], ParticleE[50], ParticleM[50];
  int ParticleId[50], ParticleStatus[50], ParticleMother[50][10], ParticleDaughter[50][10];
  //  int id_muon[20];
  int RecMuonglmuon_charge[50];
  //reco jets 
  int reco_jet,jpt_c,cjpt_c,pfNjets;
  float RecJetPt[50], RecJetEta[50], RecJetPhi[50], RecJetPx[50], RecJetPy[50], RecJetPz[50], RecJetE[50];
  int techTrigger[44];
  float RecCorrJetPt[50];
  float JetEMF[50],JetN90[50],JetFHPD[50],JetFRBX[50];
  float PFjetEta[30], PFjetPhi[30],PFjetPt[30],PFCorrjetPt[30],PFjetCEMF[30],PFjetNEMF[30];
  float JPTPt[50], JPTEta[50], JPTPhi[50], JPTPx[50], JPTPy[50], JPTPz[50], JPTE[50];

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
  myTree.SetBranchAddress("RecMuonglmuon_dxy",RecMuonglmuon_dxy);
  myTree.SetBranchAddress("RecMuonglmuon_normalizedChi2",RecMuonglmuon_normalizedChi2);
  myTree.SetBranchAddress("RecMuonglmuon_trackerHits",RecMuonglmuon_trackerHits);
  myTree.SetBranchAddress("RecMuonglmuon_muonHits",RecMuonglmuon_muonHits);
  myTree.SetBranchAddress("RecMuontkmuon_pixelhits",RecMuontkmuon_pixelhits);
  myTree.SetBranchAddress("RecMuonglmuon_charge",RecMuonglmuon_charge);
  myTree.SetBranchAddress("hltmatchedmuon",hltmatchedmuon);
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

  myTree.SetBranchAddress("jpt_c",&jpt_c);
  myTree.SetBranchAddress("JPTPt",JPTPt);
  myTree.SetBranchAddress("JPTEta",JPTEta);
  myTree.SetBranchAddress("JPTPhi",JPTPhi);
  myTree.SetBranchAddress("JPTPx",JPTPx);
  myTree.SetBranchAddress("JPTPy",JPTPy);
  myTree.SetBranchAddress("JPTPz",JPTPz);
  myTree.SetBranchAddress("JPTE",JPTE);

  myTree.SetBranchAddress("pfNjets",&pfNjets);
  myTree.SetBranchAddress("PFjetEta",PFjetEta);
  myTree.SetBranchAddress("PFjetPhi",PFjetPhi);
  myTree.SetBranchAddress("PFjetPt",PFjetPt);
  myTree.SetBranchAddress("PFjetCEMF",PFjetCEMF);
  myTree.SetBranchAddress("PFjetNEMF",PFjetNEMF);
  myTree.SetBranchAddress("PFCorrjetPt",PFCorrjetPt);

  myTree.SetBranchAddress("nVertices",&nVertices);


  TFile *theFile = new TFile("Muon_out.root","RECREATE");
  theFile->cd();
  /*  
  float xAxis_AFB[15] = {40,70,78,86,88,90,92,94,100,105,110,140,200,300,600}; 
  float xAxis_AFB_TOPLOT[14] = {55,74,82,87,89,91,93,97,102.5,107.5,125,170,250,450}; 
  */

  float xAxis_AFB[10] = {40,60,80,85,89,93,97,102,120,140}; 
  float xAxis_AFB_TOPLOT[9] = {50,70,82.5,87,91,95,99.5,111,130}; 

  float xAxis_AFB5[6] = {40,70,85,95,110,140}; 
  float xAxis_AFB5_TOPLOT[5] = {55,77.5,90,102.5,125}; 

  float xAxis_AFB8[9] =        {40,70,82,88  ,91,93  ,98   ,115,140}; 
  float xAxis_AFB8_TOPLOT[8] = {55,76,85,89.5,92,95.5,106.5,127.5}; 


  float AFB_F[30],AFB_B[30];
  float AFB_Freco[30],AFB_Breco[30];
  for (int hhh=0;hhh<30;hhh++){
    AFB_F[hhh] = 0;
    AFB_B[hhh] = 0;
    AFB_Freco[hhh] = 0;
    AFB_Breco[hhh] = 0;
  }

  TH1F *h_MZ = new TH1F("h_MZ","M(Z)#rightarrow #mu#mu",90, 20,160 );
  TH1F *h_MZ__RECO = new TH1F("h_MZ__RECO","M(Z)#rightarrow #mu#mu",90, 20,160 );

  TH1F *h_costhetaCSreco = new TH1F("h_costhetaCSreco","",6,-1.,1.);
  TH1F *h_costhetaCSreco_morebins = new TH1F("h_costhetaCSreco_morebins","",24,-1.,1.);
  TH1F *h_costhetaCSreco_y_gt_1 = new TH1F("h_costhetaCSreco_y_gt_1","",6,-1.,1.);
  TH1F *h_costhetaCSreco_y_lt_1 = new TH1F("h_costhetaCSreco_y_lt_1","",6,-1.,1.);

  TH1F *h_gen_costhetaCSreco = new TH1F("h_gen_costhetaCSreco","",6,-1.,1.);
  TH1F *h_costhetaCSreco__RECO = new TH1F("h_costhetaCSreco__RECO","",6,-1.,1.);



  TH1F *h_gen_eta3_costhetaCSreco = new TH1F("h_gen_eta3_costhetaCSreco","",6,-1.,1.);
  TH1F *h_gen_costhetaCSreco_y_gt_1 = new TH1F("h_gen_costhetaCSreco_y_gt_1","",6,-1.,1.);
  TH1F *h_gen_costhetaCSreco_y_lt_1 = new TH1F("h_gen_costhetaCSreco_y_lt_1","",6,-1.,1.);
  TH1F *h_pt_mu_0 = new TH1F("h_pt_mu_0","",50,-5,45);
  h_pt_mu_0->GetXaxis()->SetTitle("p_{T}(#mu) (GeV/c)");
  h_pt_mu_0->SetTitle("After basic event seletion");
  TH1F *h_pt_mu_1 = new TH1F("h_pt_mu_1","",50,-5,45);
  h_pt_mu_1->GetXaxis()->SetTitle("p_{T}(#mu) (GeV/c)");
  h_pt_mu_1->SetTitle("+ muon ID");
  TH1F *h_pt_mu_2 = new TH1F("h_pt_mu_2","",50,-5,45);
  h_pt_mu_2->GetXaxis()->SetTitle("p_{T}(#mu) (GeV/c)");
  h_pt_mu_2->SetTitle("+ muon isolation");
  TH1F *h_charge_0 = new TH1F("h_charge_0","",3,-1.5,1.5);
  h_charge_0->GetXaxis()->SetTitle("Muon Charge");
  h_charge_0->SetTitle("After basic event seletion");
  TH1F *h_charge_1 = new TH1F("h_charge_1","",3,-1.5,1.5);
  h_charge_1->GetXaxis()->SetTitle("Muon Charge");
  h_charge_1->SetTitle("+ muon ID");
  TH1F *h_charge_2 = new TH1F("h_charge_2","",3,-1.5,1.5);
  h_charge_2->GetXaxis()->SetTitle("Muon Charge");
  h_charge_2->SetTitle("+ muon isolation");
  TH1F *h_ntrkhits_0 = new TH1F("h_ntrkhits_0","",36,-2,34);
  h_ntrkhits_0->GetXaxis()->SetTitle("# Trk Hits");
  h_ntrkhits_0->SetTitle("After basic event seletion");
  TH1F *h_ntrkhits_1 = new TH1F("h_ntrkhits_1","",36,-2,34);
  h_ntrkhits_1->GetXaxis()->SetTitle("# Trk Hits");
  h_ntrkhits_1->SetTitle("+ muon ID");
  TH1F *h_ntrkhits_2 = new TH1F("h_ntrkhits_2","",36,-2,34);
  h_ntrkhits_2->GetXaxis()->SetTitle("# Trk Hits");
  h_ntrkhits_2->SetTitle("+ muon isolation");
  TH1F *h_chi2_0 = new TH1F("h_chi2_0","",24,-2,100);
  h_chi2_0->GetXaxis()->SetTitle("Normalized #chi^{2}");
  h_chi2_0->SetTitle("After basic event seletion");
  TH1F *h_chi2_1 = new TH1F("h_chi2_1","",24,-2,100);
  h_chi2_1->GetXaxis()->SetTitle("Normalized #chi^{2}");
  h_chi2_1->SetTitle("+ muon ID");
  TH1F *h_chi2_2 = new TH1F("h_chi2_2","",24,-2,100);
  h_chi2_2->GetXaxis()->SetTitle("Normalized #chi^{2}");
  h_chi2_2->SetTitle("+ muon isolation");
  TH1F* h_muon_hits_0 = new TH1F("h_muon_hits_0","",57,-2,55);
  h_muon_hits_0->GetXaxis()->SetTitle("# muon Hits");
  h_muon_hits_0->SetTitle("After basic event seletion");
  TH1F* h_muon_hits_1 = new TH1F("h_muon_hits_1","",57,-2,55);
  h_muon_hits_1->GetXaxis()->SetTitle("# muon Hits");
  h_muon_hits_1->SetTitle("+ muon ID");
  TH1F* h_muon_hits_2 = new TH1F("h_muon_hits_2","",57,-2,55);
  h_muon_hits_2->GetXaxis()->SetTitle("# muon Hits");
  h_muon_hits_2->SetTitle("+ muon isolation");
  TH1F *h_dxy_0 = new TH1F("h_dxy_0","",100,-1,1);
  h_dxy_0->GetXaxis()->SetTitle("XY Impact Parameter");
  h_dxy_0->SetTitle("After basic event seletion");
  TH1F *h_dxy_1 = new TH1F("h_dxy_1","",100,-1,1);
  h_dxy_1->GetXaxis()->SetTitle("XY Impact Parameter");
  h_dxy_1->SetTitle("+ muon ID");
  TH1F *h_dxy_2 = new TH1F("h_dxy_2","",100,-1,1);
  h_dxy_2->GetXaxis()->SetTitle("XY Impact Parameter");
  h_dxy_2->SetTitle("+ muon isolation");
  TH1F *h_eta_mu_0 = new TH1F("h_eta_mu_0","",25,-4,4);
  h_eta_mu_0->GetXaxis()->SetTitle("#eta(#mu)");
  h_eta_mu_0->SetTitle("After basic event seletion");
  TH1F *h_eta_mu_1 = new TH1F("h_eta_mu_1","",25,-4,4);
  h_eta_mu_1->GetXaxis()->SetTitle("#eta(#mu)");
  h_eta_mu_1->SetTitle("+ muon ID");
  TH1F *h_eta_mu_2 = new TH1F("h_eta_mu_2","",25,-4,4);
  h_eta_mu_2->GetXaxis()->SetTitle("#eta(#mu)");
  h_eta_mu_2->SetTitle("+ muon isolation");
  TH1F *h_RelCombIso_0 = new TH1F("h_RelCombIso_0","",100,-0.02,5);
  h_RelCombIso_0->GetXaxis()->SetTitle("RelCombIso Variable");
  h_RelCombIso_0->SetTitle("After basic event seletion");
  TH1F *h_RelCombIso_1 = new TH1F("h_RelCombIso_1","",100,-0.02,5);
  h_RelCombIso_1->GetXaxis()->SetTitle("RelCombIso Variable");
  h_RelCombIso_1->SetTitle("+ muon ID");
  TH1F *h_RelCombIso_2 = new TH1F("h_RelCombIso_2","",100,-0.02,5);
  h_RelCombIso_2->GetXaxis()->SetTitle("RelCombIso Variable");
  h_RelCombIso_2->SetTitle("+ muon isolation");
  TH1F *h_N_0 = new TH1F("h_N_0","",5,-0.5,4.5);  
  h_N_0->GetXaxis()->SetTitle("# muons");
  h_N_0->SetTitle("After basic event seletion");
  TH1F *h_N_1 = new TH1F("h_N_1","",5,-0.5,4.5);
  h_N_1->GetXaxis()->SetTitle("# muons");
  h_N_1->SetTitle("+ muon ID");
  TH1F *h_N_2 = new TH1F("h_N_2","",5,-0.5,4.5);
  h_N_2->GetXaxis()->SetTitle("# muons");
  h_N_2->SetTitle("+ muon isolation");
  TH1F *h_DR_rec_mu_recjet = new TH1F("h_DR_rec_mu_recjet","",110,-0.1,1.);
  TH1F *h_MZmuon = new TH1F("h_MZmuon","M(Z)#rightarrow #mu#mu",70, 20.,160.);
  TH1F *h_jet_pt = new TH1F("h_jet_pt","Corrected AK5CaloJet",200,0,100);
  h_jet_pt->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  TH1F *h_jet_pt_after_ID = new TH1F("h_jet_pt_after_ID","Corrected AK5CaloJet",200,0,100);
  h_jet_pt_after_ID->GetXaxis()->SetTitle("p_{T} (GeV/c) (after ID)");
  TH1F *h_jet_eta = new TH1F("h_jet_eta","AK5CaloJet",100,-5.2,5.2);
  h_jet_eta->GetXaxis()->SetTitle("#eta");
  TH1F *h_jet_eta_after_ID = new TH1F("h_jet_eta_after_ID","AK5CaloJet",100,-5.2,5.2);
  h_jet_eta_after_ID->GetXaxis()->SetTitle("#eta (after ID)");
  TH1F *h_jet_phi = new TH1F("h_jet_phi","AK5CaloJet",100,-3.2,3.2);
  h_jet_phi->GetXaxis()->SetTitle("#phi");
  TH1F *h_jetmultip = new TH1F("h_jetmultip","AK5CaloJet",13,-0.5,12.5);
  h_jetmultip->GetXaxis()->SetTitle("Jet Multiplicity");
  TH1F *h_jetmultip_before = new TH1F("h_jetmultip_before","AK5CaloJet",13,-0.5,12.5);
  h_jetmultip_before->GetXaxis()->SetTitle("Jet Multiplicity (before ID cuts)");
  TH1F *h_jetmultip_HBHE = new TH1F("h_jetmultip_HBHE","AK5CaloJet",13,-0.5,12.5);
  h_jetmultip_HBHE->GetXaxis()->SetTitle("Jet Multiplicity (HBHE)");
  TH1F *h_jetmultip_HBHE_before = new TH1F("h_jetmultip_HBHE_before","AK5CaloJet",13,-0.5,12.5);
  h_jetmultip_HBHE_before->GetXaxis()->SetTitle("Jet Multiplicity (HBHE) (before ID cuts)");
  TH1F *h_jetmultip_HF = new TH1F("h_jetmultip_HF","AK5CaloJet",13,-0.5,12.5);
  h_jetmultip_HF->GetXaxis()->SetTitle("Jet Multiplicity (HF)");
  TH1F *h_jetmultip_HF_before = new TH1F("h_jetmultip_HF_before","AK5CaloJet",13,-0.5,12.5);
  h_jetmultip_HF_before->GetXaxis()->SetTitle("Jet Multiplicity (HF) (before ID cuts)");
  TH1F *h_jet_EMF_HBHE = new TH1F("h_jet_EMF_HBHE","AK5CaloJet",100,-0.1,1.1);
  h_jet_EMF_HBHE->GetXaxis()->SetTitle("EMF (HBHE)");
  TH1F *h_jet_EMF_HF = new TH1F("h_jet_EMF_HF","AK5CaloJet",100,-1.1,1.1);
  h_jet_EMF_HF->GetXaxis()->SetTitle("R=(L-S)/(L+S)");
  TH1F *h_jet_FHPD = new TH1F("h_jet_FHPD","AK5CaloJet",100,-0.1,1.1);
  h_jet_FHPD->GetXaxis()->SetTitle("FHPD");
  TH1F *h_jet_N90 = new TH1F("h_jet_N90","AK5CaloJet",100,0,100);
  h_jet_N90->GetXaxis()->SetTitle("N90hits");
  TH1F *h_jet_FHPD_after = new TH1F("h_jet_FHPD_after","AK5CaloJet",100,-0.1,1.1);
  h_jet_FHPD_after->GetXaxis()->SetTitle("FHPD (after)");
  TH1F *h_MET = new TH1F("h_MET","",250,0,250);
  h_MET->GetXaxis()->SetTitle("calo #slashE_{T} [GeV]");
  TH1F *h_METX = new TH1F("h_METX","",200,-100,100);
  h_METX->GetXaxis()->SetTitle("calo #slashE_{X} [GeV]");
  TH1F *h_METY = new TH1F("h_METY","",200,-100,100);
  h_METY->GetXaxis()->SetTitle("calo #slashE_{Y} [GeV]");
  TH1F *h_SET = new TH1F("h_SET","",400,0,400);
  h_SET->GetXaxis()->SetTitle("calo #SigmaE_{T} [GeV]");
  TH1F *h_pfMET = new TH1F("h_pfMET","",250,0,250);
  h_pfMET->GetXaxis()->SetTitle("pf#slashE_{T} [GeV]");
  TH1F *h_pfMETX = new TH1F("h_pfMETX","",200,-100,100);
  h_pfMETX->GetXaxis()->SetTitle("pf#slashE_{X} [GeV]");
  TH1F *h_pfMETY = new TH1F("h_pfMETY","",200,-100,100);
  h_pfMETY->GetXaxis()->SetTitle("pf#slashE_{Y} [GeV]");
  TH1F *h_pfSET = new TH1F("h_pfSET","",400,0,400);
  h_pfSET->GetXaxis()->SetTitle("pf#SigmaE_{T} [GeV]");
  TH1F *h_massT = new TH1F("h_massT","",100,0,50);
  h_massT->GetXaxis()->SetTitle("m_{T} [GeV]");
  TH1F *h_ai_massT = new TH1F("h_ai_massT","",100,0,50);
  h_ai_massT->SetTitle("After muon id and isolation");
  h_ai_massT->GetXaxis()->SetTitle("m_{T} [GeV]");
  TH1F *h_pf_massT = new TH1F("h_pf_massT","",100,0,50);
  TH2F *h_pt_vs_massT = new TH2F("h_pt_vs_massT","",100,0,100,140,0,140);
  TH1F *h_muCorrMet = new TH1F("h_muCorrMet","",250,0,250);
  TH1F* h_qt = new TH1F("h_qt","",20,0,100);
  TH1F* h_etadimuon = new TH1F("h_etadimuon","",20,-2.6,2.6);
  TH1F* h_etadimuon_gen = new TH1F("h_etadimuon_gen","",20,-2.6,2.6);
  TH1F* h_muon_PT = new TH1F("h_muon_PT","",25,-5,120);
  TH1F* h_muon_E_rap_p = new TH1F("h_muon_E_rap_p","",60,0,360);
  TH1F* h_muon_E_rap_m = new TH1F("h_muon_E_rap_m","",60,0,360);
  TH1F* h_muon_Pz_rap_p = new TH1F("h_muon_Pz_rap_p","",20,0,300);
  TH1F* h_muon_Pz_rap_m = new TH1F("h_muon_Pz_rap_m","",20,0,300);
  TH1F* E_rap_p_test = new TH1F("E_rap_p_test","",30,0,360);
  TH1F* E_rap_m_test = new TH1F("E_rap_m_test","",30,0,360);
  TH1F* Pz_rap_p_test = new TH1F("Pz_rap_p_test","",20,0,300);
  TH1F* Pz_rap_m_test = new TH1F("Pz_rap_m_test","",20,0,300);
  TH1F* Pt_rap_p_test = new TH1F("Pt_rap_p_test","",15,0,300);
  TH1F* Pt_rap_m_test = new TH1F("Pt_rap_m_test","",15,0,300);
  TH1F *Phi_rap_p_test = new TH1F("Phi_rap_p_test","",12,-3.2,3.2);
  TH1F *Phi_rap_m_test = new TH1F("Phi_rap_m_test","",12,-3.2,3.2);
  TH1F* h_muon_rapidity = new TH1F("h_muon_rapidity","",50,-2.5,2.5); //24.
  TH1F* h_Z_rap_test = new TH1F("h_Z_rap_test","",12,-3,3); 
  TH1F* h_muon_rapidity_endcap = new TH1F("h_muon_rapidity_endcap","",24,-3,3);
  TH1F* h_muon_rapidity_barrel = new TH1F("h_muon_rapidity_barrel","",24,-3,3);
  TH1F* h_muon_rapidity_0inbarrel_1inendcap = new TH1F("h_muon_rapidity_0inbarrel_1inendcap","",24,-3,-3);
  TH1F* h_muon_rapidity_1inbarrel_0inendcap = new TH1F("h_muon_rapidity_1inbarrel_0inendcap","",24,-3,-3);
  TH1F* h_dimuonphi = new TH1F("h_dimuonphi","",12,-3.2,3.2);
  TH1F* h_muon_leading_PT = new TH1F("h_muon_leading_PT","h_muon_leading_PT",38,20,170);
  TH1F *h_jet_uncorpt = new TH1F("h_jet_uncorpt","UnCorrected AK5CaloJet",200,0,200);
  h_jet_uncorpt->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  TH1F *h_vtx = new TH1F("h_vtx","",7,-0.5,6.5);
  TH1F *h_dphi_z_pfjet = new TH1F("h_dphi_z_pfjet","",33,0,3.3);
  TH1F *h_dphi_z_pfjet_leading = new TH1F("h_dphi_z_pfjet_leading","",33,0,3.3);
  TH1F *h_pfjet_corrPt = new TH1F("h_pfjet_corrPt","",200,0,200);
  TH1F *h_pfjet_corr_leading_Pt = new TH1F("h_pfjet_corr_leading_Pt","",200,0,200);
  TH1F *h_pfjet_eta = new TH1F("h_pfjet_eta","",30,-3,3);
  TH1F *h_pfjet_eta_leading_jet = new TH1F("h_pfjet_eta_leading_jet","",30,-3,3);
  TH2F *h_ptz_eta_pfjet = new TH2F("h_ptz_eta_pfjet","",40,0,200,30,-3,3);
  TH2F *h_ptz_eta_pfjet_leading = new TH2F("h_ptz_eta_pfjet_leading","",40,0,200,30,-3,3);
  TProfile *h_eta_mass = new TProfile("h_eta_mass","",10,-2,2);

  TH1F *h_dr_gr = new TH1F("h_dr_gr","",100,0,2);

  TProfile2D *h_FF = new TProfile2D("h_FF","",9,-0.5,8.5,9,-0.5,8.5,0,40);
  TProfile2D *h_FB = new TProfile2D("h_FB","",9,-0.5,8.5,9,-0.5,8.5,0,40);
  TProfile2D *h_BF = new TProfile2D("h_BF","",9,-0.5,8.5,9,-0.5,8.5,0,40);
  TProfile2D *h_BB = new TProfile2D("h_BB","",9,-0.5,8.5,9,-0.5,8.5,0,40);

  TProfile2D *h_FF_test = new TProfile2D("h_FF_test","",10,-0.5,9.5,10,-0.5,9.5,0,40);

  TH2F *h_mzmz = new TH2F("h_mzmz","",10,40,140,10,40,140);

  TH1F *h_gen_eta = new TH1F("h_gen_eta","",100,-6,6);

  float jetscale = 0.1;
  float jetscale_jpt = 0.05;
  float jetetascale =  0.02;

  int cnt0 = 0;
  int cnt1 = 0;
  int cnt2 = 0;
  int cnt3 = 0;
  int cnt4 = 0;
  int cnt5 = 0;
  int cnt6 = 0;
  int cntend = 0;
  int vjets_count = 0;
  int vjets_count_all = 0;

  float AFB_Fbin1 = 0;
  float AFB_Bbin1 = 0;
  float AFB_Fbin2 = 0;
  float AFB_Bbin2 = 0;
  float AFB_Fbin3 = 0;
  float AFB_Bbin3 = 0;





  float AFB_Fbin[30] = {};
  float AFB_Bbin[30] = {};
  float AFB_FbinGEN[30] = {};
  float AFB_BbinGEN[30] = {};
  float AFB_FbinREC[30] = {};
  float AFB_BbinREC[30] = {};
  float AFB_FbinREC_CORR[30] = {};
  float AFB_BbinREC_CORR[30] = {};

  float AFB_Fbin5[6] = {};
  float AFB_Bbin5[6] = {};
  float AFB_Fbin8[9] = {};
  float AFB_Bbin8[9] = {};

  int comparison_count = 0;




  Int_t nevent = myTree.GetEntries();
  //nevent = 50;
  for (Int_t iev=0;iev<nevent;iev++) {
    if (iev%100000 == 0) cout<<iev<<"/"<<nevent<<endl;
    myTree.GetEntry(iev);      

    ++cnt0;

    int accept_0 = 0;
    int accept_a = 0;
    int accept_b = 0;
    int accept_c = 0;
    int accept_event = 0;
    if (techTrigger[0]) accept_0 =1 ; 
    //accept_0 = 1; //FOR MC
    if (techTrigger[40] || techTrigger[41]) accept_a = 1;
    accept_a = 1;
    if (techTrigger[36] || techTrigger[37] || techTrigger[38] || techTrigger[39]) accept_b = 1;
    if ((techTrigger[42] && !techTrigger[43]) || (techTrigger[43] && !techTrigger[42])) accept_c = 1;    
    //    if (realdata && !accept_0) continue;// 
    if (accept_a && !accept_b && !accept_c) accept_event = 1;
    //     if (!accept_event) continue;///!!!!!!!!!!!!!!!!!!!!
    
    ++cnt1;

  
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


    for (int ppo = 0;ppo<50;++ppo) parton_id[ppo] = 9999; 
    for (int j = 0;j<par_index;++j){
      if (ParticleStatus[j] != 3) continue;
      if (abs(ParticleId[j]) != 13) continue;
      //    if (fabs(ParticleEta[j]) > 2.1) continue;
      //if (ParticlePt[j] < 20.) continue;
      h_gen_eta->Fill(ParticleEta[j]);
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
      ++parpar;
    }

    if (!realdata && parpar!=2) continue;
    if (sort_index_for_mu_tree < 2) continue;


    //@@@@@@@@@@@@@@@@@@@@@@@@@@ Z at the parton level @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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
    float p1dotp2_b = parton_px[0]*parton_px[1]+parton_py[0]*parton_py[1]+parton_pz[0]*parton_pz[1];
    MZ = parton_m[0]+parton_m[1]+2*(parton_e[0]*parton_e[1]-p1dotp2_b);
    if (MZ < 0.) MZ = -1.*sqrt(fabs(MZ));
    if (MZ > 0.) MZ = sqrt(MZ);
    /*
    if (parton_pt[0] < 20.) continue;
    if (parton_pt[1] < 20.) continue;
    if (fabs(parton_eta[0]) > 2.1) continue;
    if (fabs(parton_eta[1]) > 2.1) continue;
    */
    if (MZ > 40. && MZ < 140.){
	h_MZ->Fill(MZ);

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
	if (gen_QZreco < 0.) gen_costhetaCSreco = -gen_costhetaCSreco;
	h_gen_costhetaCSreco->Fill(gen_costhetaCSreco);
	if (fabs(parton_eta[0]) < 3. && fabs(parton_eta[1]) < 3.) h_gen_eta3_costhetaCSreco->Fill(gen_costhetaCSreco);
	float gen_rap = 0.5*log((parton_e[0]+parton_e[1]+parton_pz[0]+parton_pz[1])/(parton_e[0]+parton_e[1]-parton_pz[0]-parton_pz[1]));
	if (fabs(gen_rap) > 1.0) h_gen_costhetaCSreco_y_gt_1->Fill(gen_costhetaCSreco); 
	if (fabs(gen_rap) < 1.0) h_gen_costhetaCSreco_y_lt_1->Fill(gen_costhetaCSreco); 
	h_etadimuon_gen->Fill(gen_rap);

	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	  
      }
      //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

      //@@@@@@@@@@@@@@@@@@@@@@@@@@Z at reco level@@@@@@@@@@@@@@@@@@@
      //      if (sort_index_for_mu_tree !=2) continue;
      float dr_gr = - 9999.;
      int check_dr = 0;
      if (TMath::Max(parton_pt[0],parton_pt[1]) == parton_pt[0]){ 
	dr_gr = DeltaR(parton_eta[0],RecMuonEta[0],parton_phi[0],RecMuonPhi[0]);
	if (dr_gr < 0.4) check_dr++; 
	dr_gr = DeltaR(parton_eta[1],RecMuonEta[1],parton_phi[1],RecMuonPhi[1]);
	if (dr_gr < 0.4) check_dr++; 
	h_dr_gr->Fill(dr_gr);
      }
      if (TMath::Max(parton_pt[0],parton_pt[1]) == parton_pt[1]){
	dr_gr = DeltaR(parton_eta[1],RecMuonEta[0],parton_phi[1],RecMuonPhi[0]);
	if (dr_gr < 0.4) check_dr++; 
	dr_gr = DeltaR(parton_eta[0],RecMuonEta[1],parton_phi[0],RecMuonPhi[1]);
	if (dr_gr < 0.4) check_dr++; 
	h_dr_gr->Fill(dr_gr);
      }
     
      /*
      for (int yy = 0;yy<sort_index_for_mu_tree;yy++){
	for (int yy_2 = 0;yy_2<parpar;yy_2++){
	  dr_gr = DeltaR(parton_eta[yy_2],RecMuonEta[yy],parton_phi[yy_2],RecMuonPhi[yy]);
	  h_dr_gr->Fill(dr_gr);
	}
      }
      */

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
      float p1dotp2__RECO = RecMuonPx[0]*RecMuonPx[1]+RecMuonPy[0]*RecMuonPy[1]+RecMuonPz[0]*RecMuonPz[1];
      MZ__RECO  = RecMuonM[0]+RecMuonM[1]+2*(RecMuonE[0]*RecMuonE[1]-p1dotp2__RECO);
      //    if (event != 72675) continue;
      /*
      cout<<"-----------------------"<<endl;
      cout<<"event  "<<event<<endl;
      cout<<"gen eta:    "<<parton_eta[0]<<"   "<<parton_eta[1]<<endl;
      cout<<"reco eta:   "<<RecMuonEta[0]<<"   "<<RecMuonEta[1]<<endl;
      cout<<"gen pt:    "<<parton_pt[0]<<"   "<<parton_pt[1]<<endl;
      cout<<"reco pt:   "<<RecMuonPt[0]<<"   "<<RecMuonPt[1]<<endl;      
      cout<<"number of reco muons:  "<<sort_index_for_mu_tree<<endl;
      cout<<"for mass reco:  "<<p1dotp2__RECO<<"  "<<MZ__RECO<<endl;
      */
      if (MZ__RECO < 0.) MZ__RECO = -1.*sqrt(fabs(MZ__RECO));
      if (MZ__RECO > 0.) MZ__RECO = sqrt(MZ__RECO);

      if (MZ__RECO > 40. && MZ__RECO < 140.){
	h_MZ__RECO->Fill(MZ__RECO);
	h_mzmz->Fill(MZ,MZ__RECO);
	Qreco__RECO = MZ__RECO;
	QTreco__RECO = sqrt(pow((RecMuonPx[0]+RecMuonPx[1]),2)+pow((RecMuonPy[0]+RecMuonPy[1]),2));
	if (RecMuonglmuon_charge[0] == -1){ 
	  P1preco__RECO = sab__RECO*(RecMuonE[0]+RecMuonPz[0]);
	  P1mreco__RECO = sab__RECO*(RecMuonE[0]-RecMuonPz[0]);
	  P2preco__RECO = sab__RECO*(RecMuonE[1]+RecMuonPz[1]);
	  P2mreco__RECO = sab__RECO*(RecMuonE[1]-RecMuonPz[1]);
	} 
	if (RecMuonglmuon_charge[0] == +1){ 
	  P1preco__RECO = sab__RECO*(RecMuonE[1]+RecMuonPz[1]);
	  P1mreco__RECO = sab__RECO*(RecMuonE[1]-RecMuonPz[1]);
	  P2preco__RECO = sab__RECO*(RecMuonE[0]+RecMuonPz[0]);
	  P2mreco__RECO = sab__RECO*(RecMuonE[0]-RecMuonPz[0]);
	}    
	QZreco__RECO = RecMuonPz[0]+RecMuonPz[1];   
	costhetaCSreco__RECO = (2/(Qreco__RECO*sqrt(Qreco__RECO*Qreco__RECO+QTreco__RECO*QTreco__RECO)))*(P1preco__RECO*P2mreco__RECO-P1mreco__RECO*P2preco__RECO);
	if (QZreco__RECO < 0.) costhetaCSreco__RECO = -costhetaCSreco__RECO;
	h_costhetaCSreco__RECO->Fill(costhetaCSreco__RECO);   


	/*
	for (int jjj = 0; jjj<9; jjj++){
	  if (MZ > xAxis_AFB[jjj] && MZ < xAxis_AFB[jjj+1]){
	    if (gen_costhetaCSreco >= 0) AFB_Fbin_Reco[jjj]++;
	    if (gen_costhetaCSreco < 0) AFB_Bbin_Reco[jjj]++;
	  }  	
	}
	*/

	
      }
      //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  	float AFB_Fbin_Reco[11] = {0,0,0,0,0,0,0,0,0,0,0};
	float AFB_Bbin_Reco[11] = {0,0,0,0,0,0,0,0,0,0,0};
	float AFB_Fbin_Gen[11] = {0,0,0,0,0,0,0,0,0,0,0};
	float AFB_Bbin_Gen[11] = {0,0,0,0,0,0,0,0,0,0,0};
    
	for (int jjj_k = 0; jjj_k<9; jjj_k++){//
	  if (MZ > xAxis_AFB[jjj_k] && MZ < xAxis_AFB[jjj_k+1]){
	    if (gen_costhetaCSreco >= 0){ 
	      AFB_Fbin_Gen[jjj_k] = 1;
	      AFB_FbinGEN[jjj_k]++;
	    }
	    if (gen_costhetaCSreco < 0){ 
	      AFB_Bbin_Gen[jjj_k] = 1;
	      AFB_BbinGEN[jjj_k]++;	      
	    }
	  }  	
	}

	for (int jjj_k = 0; jjj_k<9; jjj_k++){
	  if (MZ__RECO > xAxis_AFB[jjj_k] && MZ__RECO < xAxis_AFB[jjj_k+1]){
	    if (costhetaCSreco__RECO >= 0){ 
	      AFB_Fbin_Reco[jjj_k] = 1;
	      AFB_FbinREC[jjj_k]++;
	    }
	    if (costhetaCSreco__RECO < 0){
	      AFB_Bbin_Reco[jjj_k] = 1;
	      AFB_BbinREC[jjj_k]++;    
	    }
	  }  	
	}
	
	/*
	cout<<"MASS GEN:   "<<MZ<<"   MASS RECO:   "<<MZ__RECO<<endl;
	cout<<"Q GEN:   "<<parton_charge[0]<<"    "<<parton_charge[1]<<endl;
	cout<<"Q RECO:   "<<RecMuonglmuon_charge[0]<<"    "<<RecMuonglmuon_charge[1]<<endl;
	cout<<"costheta GEN:    "<<gen_costhetaCSreco<<"   costheta RECO:    "<<costhetaCSreco__RECO<<endl;
	*/

	float RijFF[20][20]={};
	float RijFB[20][20]={};
	float RijBF[20][20]={};
	float RijBB[20][20]={};
	for (int i=0;i<9;i++){
	  for (int j=0;j<9;j++){
	    if (AFB_Fbin_Gen[j] != 0){
	      RijFF[i][j] = AFB_Fbin_Reco[i]*1./AFB_Fbin_Gen[j]*1.;
	      h_FF->Fill(i*1.,j*1.,RijFF[i][j],1);
	    }
	    if (AFB_Fbin_Gen[j] != 0){
	      RijFB[i][j] = AFB_Bbin_Reco[i]*1./AFB_Fbin_Gen[j]*1.;
	      h_FB->Fill(i*1.,j*1.,RijFB[i][j],1);
	    }
	    if (AFB_Bbin_Gen[j] != 0){
	      RijBF[i][j] = AFB_Fbin_Reco[i]*1./AFB_Bbin_Gen[j]*1.;
	      h_BF->Fill(i*1.,j*1.,RijBF[i][j],1);
	    }
	    if (AFB_Bbin_Gen[j] != 0){
	      RijBB[i][j] = AFB_Bbin_Reco[i]*1./AFB_Bbin_Gen[j]*1.;
	      h_BB->Fill(i*1.,j*1.,RijBB[i][j],1);
	    }
	  }
	}

    //calo jets
    int sel_reco_jet = 0;
    float sel_reco_jet_eta[100] = {};
    float sel_reco_jet_phi[100] = {};
    float sel_reco_jet_pt[100] = {};
    float sel_reco_jet_px[100] = {};
    float sel_reco_jet_py[100] = {};
    float sel_reco_jet_pz[100] = {};
    float sel_reco_jet_E[100] = {};
    float sel_reco_jet_corrPt[100] = {};
    float sel_reco_jet_EMF[100] = {};
    float sel_reco_jet_N90[100] = {};
    float sel_reco_jet_FHPD[100] = {};
    float sel_reco_jet_FRBX[100] = {};
    for (int j = 0;j<reco_jet;++j){
      sel_reco_jet_eta[sel_reco_jet] = RecJetEta[j];
      sel_reco_jet_phi[sel_reco_jet] = RecJetPhi[j];
      sel_reco_jet_pt[sel_reco_jet] = RecJetPt[j];
      sel_reco_jet_px[sel_reco_jet] = RecJetPx[j];
      sel_reco_jet_py[sel_reco_jet] = RecJetPy[j];
      sel_reco_jet_pz[sel_reco_jet] = RecJetPz[j];
      sel_reco_jet_E[sel_reco_jet] = RecJetE[j];
      sel_reco_jet_corrPt[sel_reco_jet] = RecCorrJetPt[j];
      sel_reco_jet_EMF[sel_reco_jet] = JetEMF[j];
      sel_reco_jet_N90[sel_reco_jet] = JetN90[j];
      sel_reco_jet_FHPD[sel_reco_jet] = JetFHPD[j];
      sel_reco_jet_FRBX[sel_reco_jet] = JetFRBX[j];
      ++sel_reco_jet;
    }


    float sorted_reco_jet_eta[100] = {};
    float sorted_reco_jet_phi[100] = {};
    float sorted_reco_jet_pt[100] = {};
    float sorted_reco_jet_px[100] = {};
    float sorted_reco_jet_py[100] = {};
    float sorted_reco_jet_pz[100] = {};
    float sorted_reco_jet_E[100] = {};
    float sorted_reco_jet_corrPt[100] = {};
    float sorted_reco_jet_EMF[100] = {};
    float sorted_reco_jet_N90[100] = {};
    float sorted_reco_jet_FHPD[100] = {};
    float sorted_reco_jet_FRBX[100] = {};


    int sorted_jet_index[100] = {};
    int sort_reco_jet = 0;
    int sort_jet_counter = 0;
    float jetsum = 0;
    int jetcounter_before = 0;
    TMath::Sort(sel_reco_jet,sel_reco_jet_corrPt,sorted_jet_index);
    for (int jind=0;jind<sel_reco_jet;++jind){
      sort_reco_jet = sorted_jet_index[sort_jet_counter];
      sorted_reco_jet_eta[sort_jet_counter] = sel_reco_jet_eta[sort_reco_jet];
      sorted_reco_jet_phi[sort_jet_counter] = sel_reco_jet_phi[sort_reco_jet];
      sorted_reco_jet_pt[sort_jet_counter] = sel_reco_jet_pt[sort_reco_jet];
      sorted_reco_jet_px[sort_jet_counter] = sel_reco_jet_px[sort_reco_jet];
      sorted_reco_jet_py[sort_jet_counter] = sel_reco_jet_py[sort_reco_jet];
      sorted_reco_jet_pz[sort_jet_counter] = sel_reco_jet_pz[sort_reco_jet];
      sorted_reco_jet_E[sort_jet_counter] = sel_reco_jet_E[sort_reco_jet];
      sorted_reco_jet_corrPt[sort_jet_counter] = sel_reco_jet_corrPt[sort_reco_jet];
      sorted_reco_jet_EMF[sort_jet_counter] = sel_reco_jet_EMF[sort_reco_jet];
      sorted_reco_jet_N90[sort_jet_counter] = sel_reco_jet_N90[sort_reco_jet];
      sorted_reco_jet_FHPD[sort_jet_counter] = sel_reco_jet_FHPD[sort_reco_jet];
      sorted_reco_jet_FRBX[sort_jet_counter] = sel_reco_jet_FRBX[sort_reco_jet];
      ++sort_jet_counter;
    }

    int hlpr_0 = 0;
    int hlpr_1 = 0;
    int hlpr_2 = 0;

    //@@@@@@@@@@@@@@ SIMPLE TEST @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    for (int j = 0; j < sort_index_for_mu_tree; ++j){  
      for (int jk = j; jk < sort_index_for_mu_tree  ; ++jk){
	if (j == jk) continue;
	if (RecMuonPt[j] > 10. && RecMuonPt[jk] > 10 && fabs(RecMuonEta[j]) <2.1 && fabs(RecMuonEta[jk]) <2.1){
	  //	if (RecMuonPt[j] > 10. && RecMuonPt[jk] > 10){
	  float p1dotp2 = RecMuonPx[j]*RecMuonPx[jk]+RecMuonPy[j]*RecMuonPy[jk]+RecMuonPz[j]*RecMuonPz[jk];
	  float MZmuon_test = RecMuonM[j]+RecMuonM[jk]+2*(RecMuonE[j]*RecMuonE[jk]-p1dotp2);
	  if (MZmuon_test < 0.) MZmuon_test = -1.*sqrt(fabs(MZmuon_test));
	  if (MZmuon_test > 0.) MZmuon_test = sqrt(MZmuon_test);
	  if (MZmuon_test < 40. || MZmuon_test > 140.) continue;
	  float dimuonpt = sqrt(pow((RecMuonPx[0]+RecMuonPx[1]),2) +pow((RecMuonPy[0]+RecMuonPy[1]),2));
	  //if (dimuonpt < 40.) continue;
	  //if (MZmuon_test < 20.) continue;
	  float dimuonrapidity = 0.5*log((RecMuonE[0]+RecMuonE[1]+RecMuonPz[0]+RecMuonPz[1])/(RecMuonE[0]+RecMuonE[1]-RecMuonPz[0]-RecMuonPz[1]));
	  float dimuonphi = atan2(RecMuonPy[0]+RecMuonPy[1],RecMuonPx[0]+RecMuonPx[1]);
	  h_Z_rap_test->Fill(dimuonrapidity);
	  if (dimuonrapidity > 0.){
	    E_rap_p_test->Fill(RecMuonE[0]+RecMuonE[1]);
	    Pz_rap_p_test->Fill(RecMuonPz[0]+RecMuonPz[1]);
	    Pt_rap_p_test->Fill(dimuonpt);
	    Phi_rap_p_test->Fill(dimuonphi);
	  }
	  if (dimuonrapidity < 0.){
	    E_rap_m_test->Fill(RecMuonE[0]+RecMuonE[1]);
	    Pz_rap_m_test->Fill(fabs(RecMuonPz[0]+RecMuonPz[1]));
	    Pt_rap_m_test->Fill(dimuonpt);
	    Phi_rap_m_test->Fill(dimuonphi);
	  }
	  // }
	}
      }
    }
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


    int numberofrecmuons_0 = 0;
    int numberofrecmuons_1 = 0;
    int numberofrecmuons_2 = 0;
    int abs_jet_mu_tag = 0;
    int common = 0;
    float ptcut = 20;
    int index1[10],index2[10];//if (RecMuonIsoSumPt[j]/RecMuonPt[j] > 0.15) continue;
    for (int j = 0; j < sort_index_for_mu_tree; ++j){  
      for (int jk = j; jk < sort_index_for_mu_tree  ; ++jk){
	if (j == jk) continue;
	if ((RecMuonglmuon_charge[j]*RecMuonglmuon_charge[jk]) == -1 && //common1
	    RecMuonPt[j] > ptcut && RecMuonPt[jk] > ptcut && //common2
	    RecMuonIsoSumPt[j] < 3. && RecMuonIsoSumPt[jk] < 3. && 
	    //(RecMuonIsoCalComb[j] + RecMuonIsoSumPt[j])/RecMuonPt[j] < 0.15 && (RecMuonIsoCalComb[jk] + RecMuonIsoSumPt[jk])/RecMuonPt[jk] < 0.15 && ????
	    fabs(RecMuonEta[j]) <2.1 && fabs(RecMuonEta[jk]) <2.1 && //common3
	    //	      ((hltmatchedmuon[j] == 1 && fabs(RecMuonEta[j]) <2.1) || (hltmatchedmuon[jk] == 1 && fabs(RecMuonEta[jk]) <2.1)) && 
	    fabs(RecMuonglmuon_dxy[j]) < 0.2 && fabs(RecMuonglmuon_dxy[jk]) < 0.2) //common4
	{ 
	             index1[common] = j;
	             index2[common] = jk;
	             common++;
	}
      }
      
      //if (common > 1) cout<<"common   "<<common<<endl;

      h_pt_mu_0->Fill(RecMuonPt[j]);
      h_charge_0->Fill(RecMuonglmuon_charge[j]);
      h_ntrkhits_0->Fill(RecMuonglmuon_trackerHits[j]);    
      h_chi2_0->Fill(RecMuonglmuon_normalizedChi2[j]);
      h_muon_hits_0->Fill(RecMuonglmuon_muonHits[j]);
      h_dxy_0->Fill(RecMuonglmuon_dxy[j]);      

      h_RelCombIso_0->Fill(RecMuonIsoSumPt[j]/RecMuonPt[j]);
      hlpr_0 = 1;
      ++numberofrecmuons_0;
      //===mT=============================================
      float w_et = caloMET + RecMuonPt[j];
      float w_px = caloMETX + RecMuonPx[j];
      float w_py = caloMETY + RecMuonPy[j];
      float massT = w_et*w_et - w_px*w_px - w_py*w_py;
      massT = (massT>0) ? sqrt(massT) : 0;
      h_massT->Fill(massT);
      h_pt_vs_massT->Fill(RecMuonPt[j],massT);
      h_pt_mu_2->Fill(RecMuonPt[j]);
      h_charge_2->Fill(RecMuonglmuon_charge[j]);

      h_ntrkhits_2->Fill(RecMuonglmuon_trackerHits[j]);    
      h_chi2_2->Fill(RecMuonglmuon_normalizedChi2[j]);
      h_muon_hits_2->Fill(RecMuonglmuon_muonHits[j]);
      h_dxy_2->Fill(RecMuonglmuon_dxy[j]);      
      h_eta_mu_2->Fill(RecMuonEta[j]);

      h_RelCombIso_2->Fill(RecMuonIsoRelative[j]);
      hlpr_2 = 1;
      ++numberofrecmuons_2; 
      for (int kkj = 0; kkj < jetcounter_before; ++kkj){
	float deltar = DeltaR(sorted_reco_jet_eta[kkj],RecMuonEta[j],sorted_reco_jet_phi[kkj],RecMuonPhi[j]);
	h_DR_rec_mu_recjet->Fill(deltar);
	if (deltar < 0.43) abs_jet_mu_tag = 1;
      }
      //===mT=============================================
      float ai_w_et = caloMET + RecMuonPt[j];
      float ai_w_px = caloMETX + RecMuonPx[j];
      float ai_w_py = caloMETY + RecMuonPy[j];
      float ai_massT = ai_w_et*ai_w_et - ai_w_px*ai_w_px - ai_w_py*ai_w_py;
      ai_massT = (ai_massT>0) ? sqrt(ai_massT) : 0;
      h_ai_massT->Fill(ai_massT);
      //==================================================

      float pf_w_et = pfMET + RecMuonPt[j];
      float pf_w_px = pfMETX + RecMuonPx[j];
      float pf_w_py = pfMETY + RecMuonPy[j];
      float pf_massT = pf_w_et*pf_w_et - pf_w_px*w_px - pf_w_py*w_py;
      pf_massT = (pf_massT>0) ? sqrt(pf_massT) : 0;
      h_pf_massT->Fill(pf_massT);



    }

    if (hlpr_0) ++cnt2;
    if (hlpr_1) ++cnt3;
    if (hlpr_2) ++cnt4;

    if (numberofrecmuons_2 == 2){
      h_MET->Fill(caloMET);
      h_METX->Fill(caloMETX);
      h_METY->Fill(caloMETY);
      h_SET->Fill(caloSET);
      h_pfMET->Fill(pfMET);
      h_pfMETX->Fill(pfMETX);
      h_pfMETY->Fill(pfMETY);
      h_pfSET->Fill(pfSET); 
      h_muCorrMet->Fill(muCorrMET);
    }

    h_N_0->Fill(numberofrecmuons_0);
    h_N_1->Fill(numberofrecmuons_1);
    h_N_2->Fill(numberofrecmuons_2);
	  
    //==================================================
    //------------------------Muon ID--------------------------------------------
	  
    int loose1 = 0;
    int loose2 = 0;
    int tight_hltalso1 = 0;
    int tight_hltalso2 = 0;
    int select = 0;	
    float MZmuon = 0;
    int ind1 = -99;
    int ind2 = -99;
    for (int gg = 0;gg<common;++gg){
      ind1 = index1[gg];
      ind2 = index2[gg];
      /*
      if (common > 1){
	cout<<gg<<"  "<<RecMuonPt[ind1]<<"   "<<RecMuonPt[ind2]<<endl;
	cout<<"ind1   "<<ind1<<"   ind2    "<<ind2<<endl;
      }
      */
      if (RecMuontkmuon_pixelhits[ind1] >= 1 && RecMuonglmuon_trackerHits[ind1] > 10) loose1 = 1; 
      if (RecMuontkmuon_pixelhits[ind2] >= 1 && RecMuonglmuon_trackerHits[ind2] > 10) loose2 = 1; 
      if (RecMuonglmuon_normalizedChi2[ind1] < 10 && RecMuonglmuon_muonHits[ind1] >= 1) tight_hltalso1 = 1;
      if (RecMuonglmuon_normalizedChi2[ind2] < 10 && RecMuonglmuon_muonHits[ind2] >= 1) tight_hltalso2 = 1;
    }

    if (ind1 == -99 || ind2 == -99) continue;

    if (((loose1 && tight_hltalso2) && (loose2 && tight_hltalso1))){//or replaced by and
      float p1dotp2 = RecMuonPx[ind1]*RecMuonPx[ind2]+RecMuonPy[ind1]*RecMuonPy[ind2]+RecMuonPz[ind1]*RecMuonPz[ind2];
      MZmuon = RecMuonM[ind1]+RecMuonM[ind2]+2*(RecMuonE[ind1]*RecMuonE[ind2]-p1dotp2);
      if (MZmuon < 0.) MZmuon = -1.*sqrt(fabs(MZmuon));
      if (MZmuon > 0.) MZmuon = sqrt(MZmuon);
      h_muon_leading_PT->Fill(TMath::Max(RecMuonPt[ind1],RecMuonPt[ind2]));				  
          // if (MZmuon > 20.){
      if (MZmuon > 40. && MZmuon < 140.){
	select = 1;
	float dimuonpt = sqrt(pow((RecMuonPx[ind1]+RecMuonPx[ind2]),2) +pow((RecMuonPy[ind1]+RecMuonPy[ind2]),2));
	float dimuonrapidity = 0.5*log((RecMuonE[ind1]+RecMuonE[ind2]+RecMuonPz[ind1]+RecMuonPz[ind2])/(RecMuonE[ind1]+RecMuonE[ind2]-RecMuonPz[ind1]-RecMuonPz[ind2]));
	float dimuonphi = atan2(RecMuonPy[ind1]+RecMuonPy[ind2],RecMuonPx[ind1]+RecMuonPx[ind2]);
	h_dimuonphi->Fill(dimuonphi);
	h_muon_PT->Fill(dimuonpt);
	h_muon_rapidity->Fill(dimuonrapidity);
	if (fabs(RecMuonEta[ind1]) > 1.2 && fabs(RecMuonEta[ind2]) > 1.2) h_muon_rapidity_endcap->Fill(dimuonrapidity);
	if (fabs(RecMuonEta[ind1]) < 1.2 && fabs(RecMuonEta[ind2]) < 1.2) h_muon_rapidity_barrel->Fill(dimuonrapidity);
	if (fabs(RecMuonEta[ind1]) < 1.2 && fabs(RecMuonEta[ind2]) > 1.2) h_muon_rapidity_0inbarrel_1inendcap->Fill(dimuonrapidity);
	if (fabs(RecMuonEta[ind1]) > 1.2 && fabs(RecMuonEta[ind2]) < 1.2) h_muon_rapidity_1inbarrel_0inendcap->Fill(dimuonrapidity);
	h_MZmuon->Fill(MZmuon);
	h_eta_mass->Fill(dimuonrapidity,MZmuon);
	if (dimuonrapidity > 0.){
	  h_muon_E_rap_p->Fill(RecMuonE[ind1]+RecMuonE[ind2]);
	  h_muon_Pz_rap_p->Fill(RecMuonPz[ind1]+RecMuonPz[ind2]);
	}
	if (dimuonrapidity < 0.){ 
	  h_muon_E_rap_m->Fill(RecMuonE[ind1]+RecMuonE[ind2]);
	  h_muon_Pz_rap_m->Fill(fabs(RecMuonPz[ind1]+RecMuonPz[ind2]));
	}
	
	h_vtx->Fill(nVertices);
	h_eta_mu_0->Fill(RecMuonEta[ind1]);
	h_eta_mu_1->Fill(RecMuonEta[ind2]);
      }//mass window
    } ///tight...loose
    

	  
	  
    if (select == 0) continue;
    if (MZmuon < 40.) continue;
    if (MZmuon > 140.) continue;

    ++cntend;

    float sab = 1./sqrt(2.);
    /*
      Q = MZ;
      QT = sqrt(pow((parton_px[0]+parton_px[1]),2)+pow((parton_py[0]+parton_py[1]),2));
      if (parton_charge[0] == 1){ //-1
      P1p = sab*(parton_e[0]+parton_pz[0]);
      P1m = sab*(parton_e[0]-parton_pz[0]);
      P2p = sab*(parton_e[1]+parton_pz[1]);
      P2m = sab*(parton_e[1]-parton_pz[1]);
      }
      if (parton_charge[0] == -1){ //1
      P1p = sab*(parton_e[1]+parton_pz[1]);
      P1m = sab*(parton_e[1]-parton_pz[1]);
      P2p = sab*(parton_e[0]+parton_pz[0]);
      P2m = sab*(parton_e[0]-parton_pz[0]);
      }    
      QZ = parton_pz[0]+parton_pz[1];
    */


    float costhetaCSreco = -9999;
    float Qreco = -9999;
    float QZreco = -9999;
    float QTreco = -9999;
    float P1preco = -9999;
    float P2preco = -9999;
    float P1mreco = -9999;
    float P2mreco = -9999;

    //@@@@@@@reco costheta*@@@@@@@@@@@@@@@@@@@@
    Qreco = MZmuon;
    QTreco = sqrt(pow((RecMuonPx[0]+RecMuonPx[1]),2)+pow((RecMuonPy[0]+RecMuonPy[1]),2));
    h_qt->Fill(QTreco);
    if (RecMuonglmuon_charge[0] == -1){ 
      P1preco = sab*(RecMuonE[0]+RecMuonPz[0]);
      P1mreco = sab*(RecMuonE[0]-RecMuonPz[0]);
      P2preco = sab*(RecMuonE[1]+RecMuonPz[1]);
      P2mreco = sab*(RecMuonE[1]-RecMuonPz[1]);
    } 
    if (RecMuonglmuon_charge[0] == +1){ 
      P1preco = sab*(RecMuonE[1]+RecMuonPz[1]);
      P1mreco = sab*(RecMuonE[1]-RecMuonPz[1]);
      P2preco = sab*(RecMuonE[0]+RecMuonPz[0]);
      P2mreco = sab*(RecMuonE[0]-RecMuonPz[0]);
    }    
    QZreco = RecMuonPz[0]+RecMuonPz[1];
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    /*
      if (parpar == 0) continue;
      if (MZ<40.) continue;

      costhetaCS = (2/(Q*sqrt(Q*Q+QT*QT)))*(P1p*P2m-P1m*P2p);
      if (QZ < 0.) costhetaCS = -costhetaCS;
      h_costhetaCS->Fill(costhetaCS);
      if (MZ>40. && MZ<78.) h_costhetaCS40_78->Fill(costhetaCS);
      if (MZ>78. && MZ<105.) h_costhetaCS78_105->Fill(costhetaCS);
      if (MZ>105.) h_costhetaCS105->Fill(costhetaCS);
    
      for (int uu = 0; uu<16; uu++){
      if (MZ > xAxis_AFB[uu] && MZ < xAxis_AFB[uu+1]){
      if (costhetaCS > 0) AFB_F[uu]++;
      }
      if (MZ > xAxis_AFB[uu] && MZ < xAxis_AFB[uu+1]){
      if (costhetaCS < 0) AFB_B[uu]++;
      }
      }
    */

    //     if (MZmuon < 78 || MZmuon > 105) continue;//!!!!!!!!
        
    costhetaCSreco = (2/(Qreco*sqrt(Qreco*Qreco+QTreco*QTreco)))*(P1preco*P2mreco-P1mreco*P2preco);
    if (QZreco < 0.) costhetaCSreco = -costhetaCSreco;
    h_costhetaCSreco->Fill(costhetaCSreco);
    h_costhetaCSreco_morebins->Fill(costhetaCSreco);
    //      cout<<"costhetaCS:    "<<costhetaCSreco<<endl;

    float rap = 0.5*log((RecMuonE[0]+RecMuonE[1]+RecMuonPz[0]+RecMuonPz[1])/(RecMuonE[0]+RecMuonE[1]-RecMuonPz[0]-RecMuonPz[1]));
    if (fabs(rap) > 1.0) h_costhetaCSreco_y_gt_1->Fill(costhetaCSreco); 
    if (fabs(rap) < 1.0) h_costhetaCSreco_y_lt_1->Fill(costhetaCSreco); 
    h_etadimuon->Fill(rap);

     
 
    //      if (MZmuon > 40 && MZmuon < 78){

    if (MZmuon > 60 && MZmuon < 120) comparison_count++; 
 
    if (MZmuon > 40 && MZmuon < 70){	
      if (costhetaCSreco >= 0){ 
	AFB_Fbin1++;
	//	AFB_Fbin[0]++;
      }
      if (costhetaCSreco < 0){ 
	AFB_Bbin1++;	
	//	AFB_Bbin[0]++;
      }
    }

    for (int jjj = 0; jjj<9; jjj++){
      if (MZmuon > xAxis_AFB[jjj] && MZmuon < xAxis_AFB[jjj+1]){
	if (costhetaCSreco >= 0) AFB_Fbin[jjj]++;
	if (costhetaCSreco < 0) AFB_Bbin[jjj]++;
      }  	
    }

    for (int jjj = 0; jjj<5; jjj++){
      if (MZmuon > xAxis_AFB5[jjj] && MZmuon < xAxis_AFB5[jjj+1]){
	if (costhetaCSreco >= 0) AFB_Fbin5[jjj]++;
	if (costhetaCSreco < 0) AFB_Bbin5[jjj]++;
      }  	
    } 

    for (int jjj = 0; jjj<8; jjj++){
      if (MZmuon > xAxis_AFB8[jjj] && MZmuon < xAxis_AFB8[jjj+1]){
	if (costhetaCSreco >= 0) AFB_Fbin8[jjj]++;
	if (costhetaCSreco < 0) AFB_Bbin8[jjj]++;
      }  	
    } 


    //      if (MZmuon > 78 && MZmuon < 105){ 
    if (MZmuon >= 70 && MZmuon < 110){ 
      if (costhetaCSreco >= 0) AFB_Fbin2++;
      if (costhetaCSreco < 0) AFB_Bbin2++;	
    }
    //      if (MZmuon > 105 && MZmuon < 140){ 
    if (MZmuon >= 110 && MZmuon < 140){
      if (costhetaCSreco >= 0) AFB_Fbin3++;
      if (costhetaCSreco < 0) AFB_Bbin3++;	
    }     




    for (int uu = 0; uu<9; uu++){
      if (MZmuon > xAxis_AFB[uu] && MZmuon < xAxis_AFB[uu+1]){
	if (costhetaCSreco >= 0) AFB_Freco[uu]++;
	if (costhetaCSreco < 0) AFB_Breco[uu]++;
      }
    }
      
    /*
      if (numberofrecmuons > 1){
      if (costhetaCSreco > 0) h_MZmuonforward->Fill(MZmuon);
      if (costhetaCSreco < 0) h_MZmuonbackward->Fill(MZmuon);
      }
    */


    //##########
    if (MZmuon >= 60 && MZmuon < 110){
      ++vjets_count_all; 
      int numberofjets = 0;
      int numberofjets_up = 0;
      int numberofjets_down = 0;
      int numberofjets_etaup = 0;
      int numberofjets_etadown = 0;
      int numberofjets_combup = 0;
      int numberofjets_combdown = 0;	
      int muon_recjet_tag = 0;
      int jetveto = 0;
      for (int kk=0;kk<sort_jet_counter;kk++){
	//      if (kk == 0){ 
	h_jet_pt->Fill(sorted_reco_jet_corrPt[kk]);
	h_jet_uncorpt->Fill(sorted_reco_jet_pt[kk]);
	//      }
	h_jet_eta->Fill(sorted_reco_jet_eta[kk]);
	if (fabs(sorted_reco_jet_eta[kk]) > 3) continue;
	//
	for (int j=0;j<sort_index_for_mu_tree;j++){
	  float deltar = DeltaR(sorted_reco_jet_eta[kk],RecMuonEta[j],sorted_reco_jet_phi[kk],RecMuonPhi[j]);
	  h_DR_rec_mu_recjet->Fill(deltar);
	  if (deltar<0.5) muon_recjet_tag = 1;//increase to 0.5
	}
	//
	if (muon_recjet_tag == 0){
	  if (sorted_reco_jet_corrPt[kk] > 30.) ++numberofjets;
	  if ((sorted_reco_jet_corrPt[kk]*(1+jetscale)) > 30.) ++numberofjets_up;
	  if ((sorted_reco_jet_corrPt[kk]*(1-jetscale)) > 30.) ++numberofjets_down;
	  if ((sorted_reco_jet_corrPt[kk]*(1+jetetascale*fabs(sorted_reco_jet_eta[kk]))) > 30.) ++numberofjets_etaup;
	  if ((sorted_reco_jet_corrPt[kk]*(1-jetetascale*fabs(sorted_reco_jet_eta[kk]))) > 30.) ++numberofjets_etadown;
	  if ((sorted_reco_jet_corrPt[kk]*(1+jetetascale*fabs(sorted_reco_jet_eta[kk])+jetscale)) > 30.) ++numberofjets_combup;
	  if ((sorted_reco_jet_corrPt[kk]*(1-jetetascale*fabs(sorted_reco_jet_eta[kk])-jetscale)) > 30.) ++numberofjets_combdown;   
	}
	if ((sorted_reco_jet_EMF[kk] < 0.01 && fabs(sorted_reco_jet_eta[kk]) < 2.6) || (sorted_reco_jet_FHPD[kk] > 0.98) || (sorted_reco_jet_N90[kk] < 1)) jetveto = 1;
	jetsum += sorted_reco_jet_pt[kk];
      }
      //if (jetveto == 1) continue;
      //   if (muon_recjet_tag == 1) continue;//!!!!!!! 



      //Particle flow
      int numberofpfjets = 0;
      int numberofpfjets_up = 0;
      int numberofpfjets_down = 0;
      int numberofpfjets_etaup = 0;
      int numberofpfjets_etadown = 0;
      int numberofpfjets_combup = 0;
      int numberofpfjets_combdown = 0;		
      int check = 0;
      for (int pf=0;pf < pfNjets ;pf++){
	int markpfjet = 0;
	for (int j=0;j<sort_index_for_mu_tree;j++){
	  if (fabs(PFjetEta[pf]) > 2.5) continue;
	  float deltar = DeltaR(PFjetEta[pf],RecMuonEta[j],PFjetPhi[pf],RecMuonPhi[j]);
	  if (deltar<0.5) markpfjet = 1; 
        }
	if (markpfjet == 1) continue;
        if (fabs(PFjetEta[pf]) > 2.5) continue;
	if (PFCorrjetPt[pf] > 15.) ++numberofpfjets;
	if (PFCorrjetPt[pf] > 15.){
	  h_pfjet_corrPt->Fill(PFCorrjetPt[pf]);
	  h_pfjet_eta->Fill(PFjetEta[pf]);
	  float dimuonpt = sqrt(pow((RecMuonPx[0]+RecMuonPx[1]),2) +pow((RecMuonPy[0]+RecMuonPy[1]),2));
	  float dimuonphi = atan2(RecMuonPy[0]+RecMuonPy[1],RecMuonPx[0]+RecMuonPx[1]);
	  h_ptz_eta_pfjet->Fill(dimuonpt,fabs(PFjetEta[pf]));
	  h_dphi_z_pfjet->Fill(DeltaPhi(dimuonphi,PFjetPhi[pf]));
	  if (check == 0){ 
	    ++vjets_count;
	    h_pfjet_corr_leading_Pt->Fill(PFCorrjetPt[pf]);
	    h_pfjet_eta_leading_jet->Fill(PFjetEta[pf]);
	    h_ptz_eta_pfjet_leading->Fill(dimuonpt,fabs(PFjetEta[pf]));
	    h_dphi_z_pfjet_leading->Fill(DeltaPhi(dimuonphi,PFjetPhi[pf]));
	    check = 1;
	  }
	}
	if ((PFCorrjetPt[pf]*(1+jetscale_jpt)) > 15.) ++numberofpfjets_up;
        if ((PFCorrjetPt[pf]*(1-jetscale_jpt)) > 15.) ++numberofpfjets_down;
        if ((PFCorrjetPt[pf]*(1+jetetascale*fabs(PFjetEta[pf]))) > 15.) ++numberofpfjets_etaup;
        if ((PFCorrjetPt[pf]*(1-jetetascale*fabs(PFjetEta[pf]))) > 15.) ++numberofpfjets_etadown;
        if ((PFCorrjetPt[pf]*(1+jetetascale*fabs(PFjetEta[pf])+jetscale_jpt)) > 15.) ++numberofpfjets_combup;
        if ((PFCorrjetPt[pf]*(1-jetetascale*fabs(PFjetEta[pf])-jetscale_jpt)) > 15.) ++numberofpfjets_combdown;
      }
    }

  }// end of event loop

  /*
  cout<<"-----------------------------------------------------------"<<endl;
  cout<<"cnt0   "<<cnt0<<"    "<<100.*cnt0/(1.0*cnt0)<<endl;
  cout<<"cnt1   "<<cnt1<<"    "<<100.*cnt1/(1.0*cnt1)<<endl;
  cout<<"cnt2   "<<cnt2<<"    "<<100.*cnt2/(1.0*cnt1)<<endl;
  cout<<"cnt3   "<<cnt3<<"    "<<100.*cnt3/(1.0*cnt1)<<endl;
  cout<<"cnt4   "<<cnt4<<"    "<<100.*cnt4/(1.0*cnt1)<<endl;
  cout<<"cnt5   "<<cnt5<<"    "<<100.*cnt5/(1.0*cnt1)<<endl;
  cout<<"cnt6   "<<cnt6<<"    "<<100.*cnt6/(1.0*cnt1)<<endl;
  cout<<"-----------------------------------------------------------"<<endl;

  cout<<"tot eff = "<<(1.*cntend)/(1.*cnt0)<<endl;
  cout<<"#Z+1jet events and tot eff(Vjets) = "<<vjets_count<<"  "<<(1.*vjets_count)/(1.*cnt0)<<endl;
  cout<<"#Z+Njet events and tot eff(Vjets) = "<<vjets_count_all<<"  "<<(1.*vjets_count_all)/(1.*cnt0)<<endl;
  */

  float massbinbin[3];
  float error[3];
  massbinbin[0] = 55;
  massbinbin[1] = 90;
  massbinbin[2] = 125;
  error[0] = 15;
  error[1] = 20;
  error[2] = 15;

  float massbin[3] = {0,0,0};
  float massbinerror[3] = {0,0,0};
  massbin[0] = (AFB_Fbin1-AFB_Bbin1)/(AFB_Fbin1+AFB_Bbin1);
  massbin[1] = (AFB_Fbin2-AFB_Bbin2)/(AFB_Fbin2+AFB_Bbin2);
  massbin[2] = (AFB_Fbin3-AFB_Bbin3)/(AFB_Fbin3+AFB_Bbin3);
  massbinerror[0] = sqrt((1-massbin[0]*massbin[0])/(AFB_Fbin1+AFB_Bbin1)); 
  massbinerror[1] = sqrt((1-massbin[1]*massbin[1])/(AFB_Fbin2+AFB_Bbin2));
  massbinerror[2] = sqrt((1-massbin[2]*massbin[2])/(AFB_Fbin3+AFB_Bbin3));
  /*
  cout<<"Bin 1:   "<< massbin[0]<<"   "<<massbinerror[0]<<"  NF+NB=N="<<AFB_Fbin1<<"+"<<AFB_Bbin1<<"="<<AFB_Fbin1+AFB_Bbin1<<endl;
  cout<<"Bin 2:   "<<  massbin[1] <<"    "<<massbinerror[1]<<"  NF+NB=N="<<AFB_Fbin2<<"+"<<AFB_Bbin2<<"="<<AFB_Fbin2+AFB_Bbin2<<endl;
  cout<<"Bin 3:   "<<  massbin[2]<<"    "<<massbinerror[2]<<"  NF+NB=N="<<AFB_Fbin3<<"+"<<AFB_Bbin3<<"="<<AFB_Fbin3+AFB_Bbin3<<endl;

  cout<<"  "<<endl;
  cout<<" Number of events in M=60-120 GeV:   "<<comparison_count<<endl; 
  */
  //___________________________________________________________

  ofstream f_ff,f_fb,f_bf,f_bb;
  f_ff.open("Rij_FF.txt");
  f_fb.open("Rij_FB.txt");
  f_bf.open("Rij_BF.txt");
  f_bb.open("Rij_BB.txt");

  int dim = 9;
  TMatrixD Rij__ff(dim,dim);
  TMatrixD Rij__fb(dim,dim);
  TMatrixD Rij__bf(dim,dim);
  TMatrixD Rij__bb(dim,dim);
  TArrayI row(dim),col(dim);
  int totdim = dim*dim;
  TArrayD data__ff(totdim);
  TArrayD data__fb(totdim);
  TArrayD data__bf(totdim);
  TArrayD data__bb(totdim);
  for (int i= 0;i<dim;i++){
      row[i] = i;
      col[i] = i;
      for (int j=0;j<dim;j++){
	int k = dim*i+j;//9 is the number of rows
	data__ff[k] = h_FF->GetBinContent(i+1,j+1);
	data__fb[k] = h_FB->GetBinContent(i+1,j+1);
	data__bf[k] = h_BF->GetBinContent(i+1,j+1);
	data__bb[k] = h_BB->GetBinContent(i+1,j+1);
	f_ff << i <<"  "<< j <<"  "<<data__ff[k]<<endl;
	f_fb << i <<"  "<< j <<"  "<<data__fb[k]<<endl;
	f_bf << i <<"  "<< j <<"  "<<data__bf[k]<<endl;
	f_bb << i <<"  "<< j <<"  "<<data__bb[k]<<endl;
      }
  }
  Rij__ff.SetMatrixArray(data__ff.GetArray());
  Rij__fb.SetMatrixArray(data__fb.GetArray());
  Rij__bf.SetMatrixArray(data__bf.GetArray());
  Rij__bb.SetMatrixArray(data__bb.GetArray());

  f_ff.close();
  f_fb.close();
  f_bf.close();
  f_bb.close();

  const double *pData__ff = Rij__ff.GetMatrixArray();
  const double *pData__fb = Rij__fb.GetMatrixArray();
  const double *pData__bf = Rij__bf.GetMatrixArray();
  const double *pData__bb = Rij__bb.GetMatrixArray();
  /*  
  cout<<"FF"<<endl;
  for (int i= 0;i<dim;i++){
    for (int j=0;j<dim;j++){
      int k = dim*i+j;//9 is the number of rows
      if (pData__ff[k]) cout<<i<<"  "<<j<<"  "<<pData__ff[k]<<endl;
      
    }
  }
  cout<<"FB"<<endl;
  for (int i= 0;i<dim;i++){
    for (int j=0;j<dim;j++){
      int k = dim*i+j;//9 is the number of rows
      if (pData__fb[k]) cout<<i<<"  "<<j<<"  "<<pData__fb[k]<<endl;
    }
  }
  cout<<"BF"<<endl;
  for (int i= 0;i<dim;i++){
    for (int j=0;j<dim;j++){
      int k = dim*i+j;//9 is the number of rows
      if (pData__bf[k]) cout<<i<<"  "<<j<<"  "<<pData__bf[k]<<endl;
    }
  }
  cout<<"BB"<<endl;
  for (int i= 0;i<dim;i++){
    for (int j=0;j<dim;j++){
      int k = dim*i+j;//9 is the number of rows
      if (pData__bb[k]) cout<<i<<"  "<<j<<"  "<<pData__bb[k]<<endl;
    }
  }
  */
  TMatrixD Orig_Rij__ff(dim,dim);
  TMatrixD Orig_Rij__fb(dim,dim);
  TMatrixD Orig_Rij__bf(dim,dim);
  TMatrixD Orig_Rij__bb(dim,dim);
  Orig_Rij__ff = Rij__ff;
  Orig_Rij__fb = Rij__fb;
  Orig_Rij__bf = Rij__bf;
  Orig_Rij__bb = Rij__bb;
  TMatrixD Inv_Rij__ff(dim,dim);
  TMatrixD Inv_Rij__fb(dim,dim);
  TMatrixD Inv_Rij__bf(dim,dim);
  TMatrixD Inv_Rij__bb(dim,dim);
  Inv_Rij__ff = Rij__ff.Invert();
  Inv_Rij__fb = Rij__fb.Invert();
  Inv_Rij__bf = Rij__bf.Invert();
  Inv_Rij__bb = Rij__bb.Invert();
  TMatrixD test__ff(dim,dim);
  TMatrixD test__fb(dim,dim);
  TMatrixD test__bf(dim,dim);
  TMatrixD test__bb(dim,dim);
  //multiplication with inverse for test
  test__ff = Inv_Rij__ff*Orig_Rij__ff;
  test__fb = Inv_Rij__fb*Orig_Rij__fb;
  test__bf = Inv_Rij__bf*Orig_Rij__bf;
  test__bb = Inv_Rij__bb*Orig_Rij__bb;

  const double *testData__ff = test__ff.GetMatrixArray();
  const double *testData__fb = test__fb.GetMatrixArray();
  const double *testData__bf = test__bf.GetMatrixArray();
  const double *testData__bb = test__bb.GetMatrixArray();
  
  for (int i= 0;i<dim;i++){
    for (int j=0;j<dim;j++){
      int k = dim*i+j;//9 is the number of rows
      if (i == j) cout<<i<<"  "<<j<<"  "<<testData__ff[k]<<endl;
      
    }
  }
  for (int i= 0;i<dim;i++){
    for (int j=0;j<dim;j++){
      int k = dim*i+j;//9 is the number of rows
      if (i == j) cout<<i<<"  "<<j<<"  "<<testData__fb[k]<<endl;
    }
  }
  for (int i= 0;i<dim;i++){
    for (int j=0;j<dim;j++){
      int k = dim*i+j;//9 is the number of rows
      if (i == j) cout<<i<<"  "<<j<<"  "<<testData__bf[k]<<endl;
    }
  }
  for (int i= 0;i<dim;i++){
    for (int j=0;j<dim;j++){
      int k = dim*i+j;//9 is the number of rows
      if (i == j) cout<<i<<"  "<<j<<"  "<<testData__bb[k]<<endl;
    }
  }
  

  const double *invData__ff = Inv_Rij__ff.GetMatrixArray();
  const double *invData__fb = Inv_Rij__fb.GetMatrixArray();
  const double *invData__bf = Inv_Rij__bf.GetMatrixArray();
  const double *invData__bb = Inv_Rij__bb.GetMatrixArray();

  ofstream invf_ff,invf_fb,invf_bf,invf_bb;
  invf_ff.open("InvRij_FF.txt");
  invf_fb.open("InvRij_FB.txt");
  invf_bf.open("InvRij_BF.txt");
  invf_bb.open("InvRij_BB.txt");

  for (int i= 0;i<dim;i++){
    for (int j=0;j<dim;j++){
      int k = dim*i+j;//9 is the number of rows
      invf_ff << i <<"  "<< j <<"  "<< invData__ff[k] <<endl;
      invf_fb << i <<"  "<< j <<"  "<< invData__fb[k] <<endl;
      invf_bf << i <<"  "<< j <<"  "<< invData__bf[k] <<endl;
      invf_bb << i <<"  "<< j <<"  "<< invData__bb[k] <<endl;      
    }
  }

  invf_ff.close();
  invf_fb.close();
  invf_bf.close();
  invf_bb.close();
  //___________________________________________________________


  ifstream matrixfile_ff, matrixfile_fb, matrixfile_bf, matrixfile_bb;
  
  matrixfile_ff.open("InvRij_FF.txt");
  matrixfile_fb.open("InvRij_FB.txt");
  matrixfile_bf.open("InvRij_BF.txt");
  matrixfile_bb.open("InvRij_BB.txt");
  
  /*
  matrixfile_ff.open("Rij_FF.txt");
  matrixfile_fb.open("Rij_FB.txt");
  matrixfile_bf.open("Rij_BF.txt");
  matrixfile_bb.open("Rij_BB.txt");
  */

  int ff_counter = 0;
  int fb_counter = 0;
  int bf_counter = 0;
  int bb_counter = 0;

  int a_ff, b_ff;
  float c_ff;
  int a_fb, b_fb;
  float c_fb;
  int a_bf, b_bf;
  float c_bf;
  int a_bb, b_bb;
  float c_bb;
  
  int FF_corr_in_row[1000],FF_corr_in_col[1000];
  float FF_corr_in_value[1000];
  int FB_corr_in_row[1000],FB_corr_in_col[1000];
  float FB_corr_in_value[1000];
  int BF_corr_in_row[1000],BF_corr_in_col[1000];
  float BF_corr_in_value[1000];
  int BB_corr_in_row[1000],BB_corr_in_col[1000];
  float BB_corr_in_value[1000];
  

  while(1){
    if (!matrixfile_ff.good()) break;
    matrixfile_ff >> a_ff >> b_ff >> c_ff;
    FF_corr_in_row[ff_counter] = a_ff;
    FF_corr_in_col[ff_counter] = b_ff;
    FF_corr_in_value[ff_counter] = c_ff;
    ++ff_counter;
  }
  while(1){
    if (!matrixfile_fb.good()) break;
    matrixfile_fb >> a_fb >> b_fb >> c_fb;
    FB_corr_in_row[fb_counter] = a_fb;
    FB_corr_in_col[fb_counter] = b_fb;
    FB_corr_in_value[fb_counter] = c_fb;    
    ++fb_counter;  
  }
  while(1){
    if (!matrixfile_bf.good()) break;
    matrixfile_bf >> a_bf >> b_bf >> c_bf;
    BF_corr_in_row[bf_counter] = a_bf;
    BF_corr_in_col[bf_counter] = b_bf;
    BF_corr_in_value[bf_counter] = c_bf;    
    ++bf_counter;  
  }
  while(1){
    if (!matrixfile_bb.good()) break;
    matrixfile_bb >> a_bb >> b_bb >> c_bb;
    BB_corr_in_row[bb_counter] = a_bb;
    BB_corr_in_col[bb_counter] = b_bb;
    BB_corr_in_value[bb_counter] = c_bb;    
    ++bb_counter;  
  }



  float afb_massbin_many[30] = {};
  float afb_error_massbin_many[30] = {};
  float afb_massbin_manyGEN[30] = {};
  float afb_error_massbin_manyGEN[30] = {};
  float afb_massbin_manyREC[30] = {};
  float afb_error_massbin_manyREC[30] = {};
  float afb_massbin_manyREC_CORR[30] = {};
  float afb_error_massbin_manyREC_CORR[30] = {};
  for (int jjj=0;jjj<9;jjj++){
    afb_massbin_many[jjj] = (AFB_Fbin[jjj]-AFB_Bbin[jjj])/(AFB_Fbin[jjj]+AFB_Bbin[jjj]);
    afb_error_massbin_many[jjj] = sqrt((1-afb_massbin_many[jjj]*afb_massbin_many[jjj])/(AFB_Fbin[jjj]+AFB_Bbin[jjj])); 

    afb_massbin_manyGEN[jjj] = (AFB_FbinGEN[jjj]-AFB_BbinGEN[jjj])/(AFB_FbinGEN[jjj]+AFB_BbinGEN[jjj]);
    afb_error_massbin_manyGEN[jjj] = sqrt((1-afb_massbin_manyGEN[jjj]*afb_massbin_manyGEN[jjj])/(AFB_FbinGEN[jjj]+AFB_BbinGEN[jjj])); 

    afb_massbin_manyREC[jjj] = (AFB_FbinREC[jjj]-AFB_BbinREC[jjj])/(AFB_FbinREC[jjj]+AFB_BbinREC[jjj]);
    afb_error_massbin_manyREC[jjj] = sqrt((1-afb_massbin_manyREC[jjj]*afb_massbin_manyREC[jjj])/(AFB_FbinREC[jjj]+AFB_BbinREC[jjj])); 
  }

  for (int i=0;i<9;i++){
    for (int j=0;j<9;j++){
      int k = dim*i+j;
      AFB_FbinREC_CORR[i] += AFB_FbinREC[j]*FF_corr_in_value[k] + AFB_BbinREC[j]*FB_corr_in_value[k];
      AFB_BbinREC_CORR[i] += AFB_BbinREC[j]*BB_corr_in_value[k] + AFB_FbinREC[j]*BF_corr_in_value[k];
      cout <<"@@@-->   "<<i<<"  "<<j<<"  "<<k<<"  "<<AFB_FbinREC[j]<<" * "<<FF_corr_in_value[k]<<"  "<< AFB_BbinREC[j]<<" *  "<<FB_corr_in_value[k]<<"  "<<AFB_FbinREC_CORR[i]<<endl;
    }
    afb_massbin_manyREC_CORR[i] = (AFB_FbinREC_CORR[i]-AFB_BbinREC_CORR[i])/(AFB_FbinREC_CORR[i]+AFB_BbinREC_CORR[i]);
    afb_error_massbin_manyREC_CORR[i] = sqrt((1-afb_massbin_manyREC_CORR[i]*afb_massbin_manyREC_CORR[i])/(AFB_FbinREC_CORR[i]+AFB_BbinREC_CORR[i])); 
  }

  float afb_massbin_5[6] = {};
  float afb_error_massbin_5[6] = {};
  for (int jjj=0;jjj<5;jjj++){
    afb_massbin_5[jjj] = (AFB_Fbin5[jjj]-AFB_Bbin5[jjj])/(AFB_Fbin5[jjj]+AFB_Bbin5[jjj]);
    afb_error_massbin_5[jjj] = sqrt((1-afb_massbin_5[jjj]*afb_massbin_5[jjj])/(AFB_Fbin5[jjj]+AFB_Bbin5[jjj])); 
  }

  float afb_massbin_8[9] = {};
  float afb_massbin_8_CORR[9] = {};
  float afb_error_massbin_8[9] = {};
  float corr[9] = {0.135,0.176,0.338,0.192,0.140,0.176,0.202,0.230};
  float afb_error_massbin_8_X[9] = {15,6,3,1.5,1,1.5,8.5,12.5};

  for (int jjj=0;jjj<8;jjj++){
    afb_massbin_8[jjj] = (AFB_Fbin8[jjj]-AFB_Bbin8[jjj])/(AFB_Fbin8[jjj]+AFB_Bbin8[jjj]);
    afb_massbin_8_CORR[jjj] = afb_massbin_8[jjj]/corr[jjj];
    afb_error_massbin_8[jjj] = sqrt((1-afb_massbin_8[jjj]*afb_massbin_8[jjj])/(AFB_Fbin8[jjj]+AFB_Bbin8[jjj])); 
  }

  /*

  

  float AFB[30];
  for (int kk = 0; kk < 16; kk++){
  if ((AFB_F[kk] + AFB_B[kk])!=0) AFB[kk] = (AFB_F[kk] - AFB_B[kk])/(AFB_F[kk] + AFB_B[kk]);
  }

  */

  /*
    TCanvas *c1 = new TCanvas();
    TGraph *p_AFB = new TGraph(16,xAxis_AFB,AFB);
    c1->cd();
    p_AFB->SetMarkerStyle(26);
    p_AFB->Draw("AP");
    c1->SaveAs("afb.C");
  */

  float AFBreco[30];
  for (int kk = 0; kk < 16; kk++){
    if ((AFB_Freco[kk] + AFB_Breco[kk])!=0) AFBreco[kk] = (AFB_Freco[kk] - AFB_Breco[kk])/(AFB_Freco[kk] + AFB_Breco[kk]);
  }

 
  TCanvas *c1_ewk = new TCanvas();
  c1_ewk->cd();
  h_muon_PT->Draw();
  c1_ewk->SaveAs("dimuonPT.C");

  TCanvas *c2_ewk = new TCanvas();
  c2_ewk->cd();
  h_muon_rapidity->Draw();
  c2_ewk->SaveAs("dimuonRAPIDITY.C");
  
  TCanvas *c2_010_ewk = new TCanvas();
  c2_010_ewk->cd();
  h_dimuonphi->Draw();
  c2_010_ewk->SaveAs("dimuonPHI.C");

  TCanvas *c2_05_ewk = new TCanvas();
  c2_05_ewk->cd();
  h_MZmuon->Draw();
  c2_05_ewk->SaveAs("dimuonMASS.C");

  TCanvas *c2_1_ewk = new TCanvas();
  c2_1_ewk = new TCanvas();
  h_costhetaCSreco->Draw();
  c2_1_ewk->SaveAs("muonCOSTHETA.C"); 

  TCanvas *c2_1p_ewk = new TCanvas();
  c2_1p_ewk = new TCanvas();
  h_costhetaCSreco_morebins->Draw();
  c2_1p_ewk->SaveAs("muonCOSTHETA_morebins.C"); 

  TCanvas *c3_ewk = new TCanvas();
  TGraph *p_3bins = new TGraphErrors(3,massbinbin,massbin,error,massbinerror);
  p_3bins->SetMarkerStyle(26); 
  p_3bins->Draw("AP");
  c3_ewk->SaveAs("afb3bins.C");
  
 
  TCanvas *cn_ewk = new TCanvas();
  TGraph *p_manybins = new TGraphErrors(9, xAxis_AFB_TOPLOT,afb_massbin_many,0,afb_error_massbin_many);
  p_manybins->SetMarkerStyle(26); 
  p_manybins->Draw("AP");
  cn_ewk->SaveAs("afbmanybins.C");

  TCanvas *cn_ewkGEN = new TCanvas();
  TGraph *p_manybinsGEN = new TGraphErrors(9, xAxis_AFB_TOPLOT,afb_massbin_manyGEN,0,afb_error_massbin_manyGEN);
  p_manybinsGEN->SetMarkerColor(4);
  p_manybinsGEN->SetMarkerStyle(26); 
  p_manybinsGEN->Draw("AP");
  TGraph *p_manybinsREC = new TGraphErrors(9, xAxis_AFB_TOPLOT,afb_massbin_manyREC,0,afb_error_massbin_manyREC);
  p_manybinsREC->SetMarkerStyle(24); 
  p_manybinsREC->Draw("P");
  TGraph *p_manybinsREC_CORR = new TGraph(9, xAxis_AFB_TOPLOT,afb_massbin_manyREC_CORR);
  p_manybinsREC_CORR->SetMarkerColor(2);
  p_manybinsREC_CORR->SetMarkerStyle(23); 
  p_manybinsREC_CORR->Draw("P");
  cn_ewkGEN->SaveAs("afbmanybinsGEN.C");



  TCanvas *cn5_ewk = new TCanvas();
  TGraph *p_5bins = new TGraphErrors(5, xAxis_AFB5_TOPLOT,afb_massbin_5,0,afb_error_massbin_5);
  p_5bins->SetMarkerStyle(26); 
  p_5bins->Draw("AP");
  cn5_ewk->SaveAs("afb5bins.C");

  TCanvas *cn8_ewk = new TCanvas();
  cn8_ewk->cd();
  TGraph *p_8bins = new TGraphErrors(8, xAxis_AFB8_TOPLOT,afb_massbin_8,afb_error_massbin_8_X,afb_error_massbin_8);
  p_8bins->SetMarkerStyle(26); 
  p_8bins->Draw("AP");
  /*
    TGraph *p_8binsCorr = new TGraphErrors(8, xAxis_AFB8_TOPLOT,afb_massbin_8_CORR,afb_error_massbin_8_X,afb_error_massbin_8);
    p_8binsCorr->SetMarkerColor(4);
    p_8binsCorr->Draw("P");
    cn8_ewk->SaveAs("afb8bins.C");
  */




  theFile->Write();
  theFile->Close();

}//end void  

int main(int argc,char **argv){
  tree1r();
}


float DeltaR(float eta1, float eta2, float phi1, float phi2)
{
  float deta = eta2 - eta1;
  float dphi = phi2 - phi1;
  if (fabs(dphi) > 3.14) dphi = 6.28 - fabs(dphi);
  float DELTAR = sqrt(pow(dphi,2)+pow(deta,2))*1.0;
  return DELTAR;
}
float DeltaPhi(float phi1, float phi2)
{
  float dphi = phi2 - phi1;
  if (fabs(dphi) > 3.14) dphi = 6.28 - fabs(dphi);
  return dphi;
}
