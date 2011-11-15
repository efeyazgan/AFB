#include "afbbase.h"

using namespace std;

void tree1r()
{

 // TFile *file_cov = new TFile("MUON_MC_Meas_NoFsr_ForClosure.root","RECREATE"); float r_test = 0.5; 
  TFile *file_cov = new TFile("MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Telescope.root","RECREATE"); float r_test = 1.0;
  file_cov->cd(); 
 
  /*
    TChain myTree("demo/MuonTree");
    myTree.Add("/data2/efe/ntuples/386/DY_MuMu_UPDATED_powheg_wo_HLT_filter.root");
  */
  //myTree.Add("/tmp/efe/DY_MuMu_UPDATED_powheg_wo_HLT_filter.root");
 
  //  TChain myTree("analyzeBasicPat/MuonTree");
  //myTree.Add("/data2/efe/ntuples/keng/DoubleMu_May10ReReco.root");

  //  myTree.Add("/data1/efe/ntuples/keng/mc/DYToMuMu_M-20_Summer11-PU_S4.root");

  TChain myTree("demo/MuonTree"); 
  myTree.Add("/data1/efe/ntuples/nhan/sin2thW_weakmodes/Telescope/newmuons.root");

  TH1::AddDirectory(true);
  int event; 
  //  int run,lumi,bxnumber;
  int realdata;
  //  int hlt_trigger_fired;
  int sort_index_for_mu_tree;
  //int MuInx;
  float RecMuonPt[50], RecMuonEta[50], RecMuonPhi[50],RecMuonPx[50], RecMuonPy[50], RecMuonPz[50], RecMuonM[50], RecMuonE[50], RecMuonGlobalType[50], RecMuonTrackerType[50], RecMuonStandAloneType[50], RecMuonIsoSumPt[50], RecMuonIsoRelative[50], RecMuonIsoCalComb[50], RecMuonIsoDY[50], RecMuonglmuon_dxy[50];
  //float RecMuonglmuon_dz[50];
  float RecMuonglmuon_normalizedChi2[50];
  //float RecMuonIsoHad[50],RecMuonIsoEm[50];
  int RecMuonglmuon_trackerHits[50],RecMuontkmuon_pixelhits[50],RecMuonglmuon_muonHits[50],RecNumberOfUsedStations[50];
  //int hltmatchedmuon[50],hltmatched_Dimuon[50];
   
  //particle information
  int par_index, mom[50], daug[50]; 
  //int GenInx;
  float ParticlePt[500], ParticleEta[500], ParticlePhi[500], ParticlePx[500], ParticlePy[500], ParticlePz[500], ParticleE[500], ParticleM[500];
  int ParticleId[50], ParticleStatus[50], ParticleMother[50][10], ParticleDaughter[50][10];
  //int GenStatus[50], GenID[50] ;
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
  myTree.SetBranchAddress("sort_index_for_mu_tree",&sort_index_for_mu_tree);
  //myTree.SetBranchAddress("MuInx",&MuInx);
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
  
    //  myTree.SetBranchAddress("techTrigger",techTrigger);
    myTree.SetBranchAddress("par_index", &par_index);
  
  /*
  myTree.SetBranchAddress("GenInx", &GenInx);
  myTree.SetBranchAddress("GenStatus", GenStatus);
  myTree.SetBranchAddress("GenID", GenID);
  */
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

    /*
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


  //  cout<<"r_TESTTTTTT = "<<r_test<<endl;
  //  cout<<"USING  "<< r_test*100 <<"   PERCENT OF ALL EVENTS FOR THE MEASURED!!!!!!"<<endl;
  int nb = 10;
  //  int nbcos = 20;//!!!!!nominal = 8

  // cout<<"@@@@@@=====> NUMBER OF COSTHETA BINS IS    "<<nbcos<<endl;

  float xAxis_AFB[nb+1]; 

  //DY high mass bins
  xAxis_AFB[0] = 40;
  xAxis_AFB[1] = 50;
  xAxis_AFB[2] = 60;
  xAxis_AFB[3] = 76;
  xAxis_AFB[4] = 86;
  xAxis_AFB[5]  = 96;
  xAxis_AFB[6]  = 106;
  xAxis_AFB[7] = 120;
  xAxis_AFB[8] = 150;
  xAxis_AFB[9] = 200;
  xAxis_AFB[10] = 2000;
  

 /* 
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
*/  


  int nb_Y = 4;
  float Y_bin_limits[nb_Y+1]; 
  Y_bin_limits[0] = 0.0;
  Y_bin_limits[1] = 1.0;
  Y_bin_limits[2] = 1.25;
  Y_bin_limits[3] = 1.5;
  Y_bin_limits[4] = 2.5;
 
 // eta and pt dependence efficiency (DoubleMuon HLT + ID) to each muon leg..
 const Float_t etlow[5]   = {20,30,40,50,1000};
 const Float_t etalow[11] = {-2.5,-2.0,-1.5,-1.0,-0.5,0.0,0.5,1.0,1.5,2.0,2.5};
 // efficiency scale....
  float scl_eff[4][10] = {{0.978971,0.985087,0.978348,0.97011,0.97656,0.981229,0.989604,0.972174,1.00218,0.981141},
			  {0.96554,0.999062,0.984348,0.981431,0.982378,0.980314,0.989259,0.979383,0.989701,0.977227},
			  {0.966041,0.997964,0.987181,0.987912,0.981217,0.987673,0.989819,0.993106,1.00265,0.993692},
			  {1.07848,0.928631,0.982425,0.973578,0.97559,0.970705,0.975343,0.948695,1.01482,0.895468}};//to apply to each leg


// vertex weighting.. 0-11, then >11
 float vtx_scale[12] = {0,0.132328,0.728345,1.35569,1.84319,1.93182,1.79917,1.44223,1.03293,0.691829,0.46149,0.170495};
 float vtx_scale_err[12] = {0.0,0.00417728,0.0121021,0.0160448,0.0186817,0.0191781,0.0188025,0.0173093,0.0153488,0.0134817,0.012101,0.00447711};
////////////////////////////////////////


  TH1D *hNoFsrTruthCos_M_Y[30][5];
  TH1D *hdummy_m2[30][5];
  TH1D *hdummy_t2[30][5];
  char name_1[100],name_2[100];


  for (int j=0;j<nb_Y;j++){
    sprintf(name_h,"hMeasCos_Forward_Y_%i_",j);
    Align_Telescope_hMeasCos_M_Y_Forward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"hMeasCos_Backward_Y_%i_",j);
    Align_Telescope_hMeasCos_M_Y_Backward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);


    sprintf(name_h,"hUnDetetorCos_Forward_Y_%i",j);
    hUnDetectorCos_M_Y_Forward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    //   hUnDetectorCos_M_Y_Forward[j]->Sumw2();
    sprintf(name_h,"hUnDetectorCos_Backward_Y_%i",j);
    hUnDetectorCos_M_Y_Backward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    //    hUnDetectorCos_M_Y_Backward[j]->Sumw2();


    sprintf(name_h,"hNoFsrTruthCos_Forward_Y_%i_",j);
    hNoFsrTruthCos_M_Y_Forward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    //    hNoFsrTruthCos_M_Y_Forward[j]->Sumw2();
    sprintf(name_h,"hNoFsrTruthCos_Backward_Y_%i_",j);
    hNoFsrTruthCos_M_Y_Backward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    //    hNoFsrTruthCos_M_Y_Backward[j]->Sumw2();

    sprintf(name_h,"Response_UnDetector_Forward_Y_%i_",j);
    Response_UnDetector_Forward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);
    sprintf(name_h,"Response_UnDetector_Backward_Y_%i_",j);
    Response_UnDetector_Backward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);

    sprintf(name_h,"Response_UnDetector_ForwardBackward_Y_%i_",j);
    Response_UnDetector_ForwardBackward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);
    sprintf(name_h,"Response_UnDetector_BackwardForward_Y_%i_",j);
    Response_UnDetector_BackwardForward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);

    sprintf(name_h,"Response_UnDetector_Forward_NO_NORM_Y_%i_",j);
    Response_UnDetector_Forward_NO_NORM[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);
    sprintf(name_h,"Response_UnDetector_Backward_NO_NORM_Y_%i_",j);
    Response_UnDetector_Backward_NO_NORM[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);

    sprintf(name_h,"Response_UnDetector_ForwardBackward_NO_NORM_Y_%i_",j);
    Response_UnDetector_ForwardBackward_NO_NORM[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);
    sprintf(name_h,"Response_UnDetector_BackwardForward_NO_NORM_Y_%i_",j);
    Response_UnDetector_BackwardForward_NO_NORM[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);

    sprintf(name_h,"Response_NoFsr_Forward_Y_%i_",j);
    Response_NoFsr_Forward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);
    sprintf(name_h,"Response_NoFsr_Backward_Y_%i_",j);
    Response_NoFsr_Backward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);


    sprintf(name_h,"Align_Telescope_Inv_Response_UnDetector_Forward_Y_%i_",j);
    Align_Telescope_Inv_Response_UnDetector_Forward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);
    sprintf(name_h,"Align_Telescope_Inv_Response_UnDetector_Backward_Y_%i_",j);
    Align_Telescope_Inv_Response_UnDetector_Backward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);

    sprintf(name_h,"Align_Telescope_Inv_Response_NoFsr_Forward_Y_%i_",j);
    Align_Telescope_Inv_Response_NoFsr_Forward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);
    sprintf(name_h,"Align_Telescope_Inv_Response_NoFsr_Backward_Y_%i_",j);
    Align_Telescope_Inv_Response_NoFsr_Backward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);


  }

  TH1D* h_MZ_st3 = new TH1D("h_MZ_st3","",nb, xAxis_AFB);
  TH1D* h_MZ_st1 = new TH1D("h_MZ_st1","",nb, xAxis_AFB);
  TH1D* h_MZ_st1_minus_st3 = new TH1D("h_MZ_st1_minus_st3","",100,-20, 10);  

  TH1D* h_EneDiff_P = new TH1D("h_EneDiff_P","h_EneDiff_P",1000,-20,20);
  TH1D* h_EneDiff_N = new TH1D("h_EneDiff_N","h_EneDiff_N",1000,-20,20);


  TH1D *hMass = new TH1D("hMass","hMass",nb,xAxis_AFB);


  Int_t nevent = myTree.GetEntries();
  //nevent = 2000000;
  for (Int_t iev=0;iev<nevent;iev++) {
    if (iev%100000 == 0) cout<<iev<<"/"<<nevent<<endl;
    myTree.GetEntry(iev);


    int common = 0;
    float ptcut = 20;
    float eta_cut = 2.4;

    int parpar = 0;
    int parpar_st1 = 0;
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

    float parton_pt_st1[50] = {};
    float parton_eta_st1[50] = {};
    float parton_phi_st1[50] = {};
    float parton_px_st1[50] = {};
    float parton_py_st1[50] = {};
    float parton_pz_st1[50] = {};
    float parton_m_st1[50] = {};
    float parton_e_st1[50] = {};
    int parton_id_st1[50] = {};
    int parton_charge_st1[50] = {};

  
    int posid = -999;
    int negid = -999;
    int posid_st1 = -999;
    int negid_st1 = -999;

    for (int ppo = 0;ppo<50;++ppo) parton_id[ppo] = 9999;
    //if (realdata) GenInx = 0;
    if (realdata) par_index = 0;
    //for (int j = 0; j < GenInx; ++j){
    for (int j = 0;j<par_index;++j){
      //      if (abs(ParticleId[j]) == 22) cout<<ParticleId[j]<<"   "<<ParticleStatus[j]<<"  "<<ParticlePt[j]<<"   "<<ParticleEta[j]<<endl;
      //if (abs(GenID[j]) == 22) cout<<GenID[j]<<"   "<<GenStatus[j]<<"  "<<ParticlePt[j]<<"   "<<ParticleEta[j]<<endl;
      //if (ParticleStatus[j] != 3 ) continue;
      //if (GenStatus[j] == 1 && abs(GenID[j]) == 13){
      if (ParticleStatus[j] == 1 && abs(ParticleId[j]) == 13){     
	parton_pt_st1[parpar_st1] = ParticlePt[j];
	parton_eta_st1[parpar_st1] = ParticleEta[j];
	parton_phi_st1[parpar_st1] = ParticlePhi[j];
	//	parton_id_st1[parpar_st1] = GenID[j];
	parton_id_st1[parpar_st1] = ParticleId[j];
	parton_px_st1[parpar_st1] = ParticlePx[j];
	parton_py_st1[parpar_st1] = ParticlePy[j];
	parton_pz_st1[parpar_st1] = ParticlePz[j];
	parton_m_st1[parpar_st1] = ParticleM[j];
	parton_e_st1[parpar_st1] = ParticleE[j];
	//	parton_charge_st1[parpar_st1] = -GenID[j]/abs(GenID[j]);//because mu- is = 13 not -13
	parton_charge_st1[parpar_st1] = -ParticleId[j]/abs(ParticleId[j]);//because mu- is = 13 not -13

        if (parton_charge_st1[parpar_st1] == -1) posid_st1 = parpar_st1;
        if (parton_charge_st1[parpar_st1] == +1) negid_st1 = parpar_st1;       
	++parpar_st1;
      }
      //if (GenStatus[j] != 3) continue;
      //      if (abs(ParticleId[j]) == 13){///////
      //if (abs(GenID[j]) == 13 && GenStatus[j] == 3){
      if (abs(ParticleId[j]) == 13 && ParticleStatus[j] == 3){
	parton_pt[parpar] = ParticlePt[j];
	parton_eta[parpar] = ParticleEta[j];
	parton_phi[parpar] = ParticlePhi[j];
	parton_id[parpar] = ParticleId[j];
		//parton_id[parpar] = GenID[j];
	parton_px[parpar] = ParticlePx[j];
	parton_py[parpar] = ParticlePy[j];
	parton_pz[parpar] = ParticlePz[j];
	parton_m[parpar] = ParticleM[j];
	parton_e[parpar] = ParticleE[j];
	parton_charge[parpar] = -ParticleId[j]/abs(ParticleId[j]);//because mu- is = 13 not -13
	//parton_charge[parpar] = -GenID[j]/abs(GenID[j]);//because mu- is = 13 not -13
        if (parton_charge[parpar] == -1) posid = parpar;
        if (parton_charge[parpar] == +1) negid = parpar;       
	++parpar;
      }

      //      if (abs(ParticleId[j]) >= 1 && abs(ParticleId[j]) < 5 && j >= 4 && j <= 5){
      //      if (ParticleId[j] == 23){
    }

    float MZ = 0;
    float MZ_st1 = 0;
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
    float p1dotp2_b_st1 = -9999.;
    float gen_costhetaCSreco_st1 = -9999;
    float gen_Qreco_st1 = -9999;
    float gen_QZreco_st1 = -9999;
    float gen_QTreco_st1 = -9999;
    float gen_P1preco_st1 = -9999;
    float gen_P2preco_st1 = -9999;
    float gen_P1mreco_st1 = -9999;
    float gen_P2mreco_st1 = -9999;

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
  
    int gen_select = 0;
    int gen_st1_select = 0;

    float dimuonrapidity = -9999.;

    p1dotp2_b = parton_px[0]*parton_px[1]+parton_py[0]*parton_py[1]+parton_pz[0]*parton_pz[1];
    MZ = parton_m[0]+parton_m[1]+2*(parton_e[0]*parton_e[1]-p1dotp2_b);
    //if (MZ < 0.) MZ = -1.*sqrt(abs(MZ));
    MZ = sqrt(MZ);

    p1dotp2_b_st1 = parton_px_st1[0]*parton_px_st1[1]+parton_py_st1[0]*parton_py_st1[1]+parton_pz_st1[0]*parton_pz_st1[1];
    MZ_st1 = parton_m_st1[0]+parton_m_st1[1]+2*(parton_e_st1[0]*parton_e_st1[1]-p1dotp2_b_st1);
    MZ_st1 = sqrt(MZ_st1);   

    h_MZ_st3->Fill(MZ);
    h_MZ_st1->Fill(MZ_st1);


    float pos_diff_E_muon = 0;
    float neg_diff_E_muon = 0;
    float weight_up = 1.;
    float weight_down = 1.;
    pos_diff_E_muon = parton_e[posid] - parton_e_st1[posid_st1];
    neg_diff_E_muon = parton_e[negid] - parton_e_st1[negid_st1];
    h_EneDiff_P->Fill(pos_diff_E_muon);
    h_EneDiff_N->Fill(neg_diff_E_muon);
    if (pos_diff_E_muon > 1. || neg_diff_E_muon > 1.){ 
      weight_up = 1.05;
      weight_down = 0.95;
    }
    

    if (MZ > 40. && parton_pt[0] > ptcut &&  parton_pt[1] > ptcut && fabs(parton_eta[0]) < eta_cut && fabs(parton_eta[1]) < eta_cut) gen_select = 1;

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

    //status 1@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
    if (MZ_st1 > 40. && parton_pt_st1[0] > ptcut &&  parton_pt_st1[1] > ptcut && fabs(parton_eta_st1[0]) < eta_cut && fabs(parton_eta_st1[1]) < eta_cut) gen_st1_select = 1;


    gen_Qreco_st1 = MZ_st1;
    gen_QTreco_st1 = sqrt(pow((parton_px_st1[0]+parton_px_st1[1]),2)+pow((parton_py_st1[0]+parton_py_st1[1]),2));

    if (parton_charge_st1[0] == -1){
      gen_P1preco_st1 = gen_sab*(parton_e_st1[0]+parton_pz_st1[0]);
      gen_P1mreco_st1 = gen_sab*(parton_e_st1[0]-parton_pz_st1[0]);
      gen_P2preco_st1 = gen_sab*(parton_e_st1[1]+parton_pz_st1[1]);
      gen_P2mreco_st1 = gen_sab*(parton_e_st1[1]-parton_pz_st1[1]);
    }
    if (parton_charge_st1[0] == +1){
      gen_P1preco_st1 = gen_sab*(parton_e_st1[1]+parton_pz_st1[1]);
      gen_P1mreco_st1 = gen_sab*(parton_e_st1[1]-parton_pz_st1[1]);
      gen_P2preco_st1 = gen_sab*(parton_e_st1[0]+parton_pz_st1[0]);
      gen_P2mreco_st1 = gen_sab*(parton_e_st1[0]-parton_pz_st1[0]);
    }
    gen_QZreco_st1 = parton_pz_st1[0]+parton_pz_st1[1];
    gen_costhetaCSreco_st1 = (2/(gen_Qreco_st1*sqrt(gen_Qreco_st1*gen_Qreco_st1+gen_QTreco_st1*gen_QTreco_st1)))*(gen_P1preco_st1*gen_P2mreco_st1-gen_P1mreco_st1*gen_P2preco_st1);
    if (gen_QZreco_st1 < 0.) gen_costhetaCSreco_st1 = -gen_costhetaCSreco_st1;
    //cout<<gen_costhetaCSreco_st1<<"   "<<MZ_st1<<"   "<<parton_pt_st1[0]<<"   "<<parton_pt_st1[1]<<"   "<<parton_eta_st1[0]<<"   "<<parton_eta_st1[1]<<endl;
    //eof fsr@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
    dimuonrapidity = 0.5*log((parton_e[0]+parton_e[1]+parton_pz[0]+parton_pz[1])/(parton_e[0]+parton_e[1]-parton_pz[0]-parton_pz[1]));
  
float weight = 1;

//-----------------------Pileup Reweighting -------------------------
   float vtx_wgt = 1;
   for (int ip=0; ip<12; ip++) {
     if (nGoodVertices < 12) vtx_wgt = vtx_scale[int(nGoodVertices)];
     else                   vtx_wgt = vtx_scale[11];
   }

 
//efficiency correction////////////////////////////////////////////////////////
    float eff_wgt_0 = 1;
    float eff_wgt_1 = 1;
    /*
    for (int i = 0; i < MuInx; ++i){
     for (int j = i; j < MuInx; ++j){
    */
    for (int i = 0; i < sort_index_for_mu_tree; ++i){
      for (int j = i; j < sort_index_for_mu_tree; ++j){
	    
      if (i == j) continue;
      for (int ib=0; ib<4; ib++) {
	    for (int ie=0; ie<10; ie++) {
	      if (RecMuonPt[i]>etlow[ib] && RecMuonPt[i]<etlow[ib+1]) {
		if (RecMuonEta[i]>etalow[ie] && RecMuonEta[i]<etalow[ie+1]) {
		  eff_wgt_0 = scl_eff[ib][ie];                
		} 
	      }
	      if (RecMuonPt[j]>etlow[ib] && RecMuonPt[j]<etlow[ib+1]) {
		if (RecMuonEta[j]>etalow[ie] && RecMuonEta[j]<etalow[ie+1]) {
		  eff_wgt_1 = scl_eff[ib][ie];                
		} 
	      }
	    }
	  }
      }
    }
/////////////////////////////////////////////////////////////////////////////// 
   
weight = vtx_wgt*eff_wgt_0*eff_wgt_1;
//cout<<"weight:     "<<weight<<endl;

    int index1[10],index2[10];//if (RecMuonIsoSumPt[j]/RecMuonPt[j] > 0.15) continue;   

/*
    for (int j = 0; j < MuInx; ++j){
      for (int jk = j; jk < MuInx; ++jk){
*/
	for (int j = 0; j < sort_index_for_mu_tree; ++j){
	  for (int jk = j; jk < sort_index_for_mu_tree; ++jk){
	
        if (j == jk) continue;
        TVector3 mom1(RecMuonPx[j],RecMuonPy[j],RecMuonPz[j]);
        TVector3 mom2(RecMuonPx[jk],RecMuonPy[jk],RecMuonPz[jk]);
        float cosine = mom1.Angle(mom2) - TMath::Pi();    
        if ((RecMuonglmuon_charge[j]*RecMuonglmuon_charge[jk]) == -1 && //common1
            RecMuonPt[j] > ptcut && RecMuonPt[jk] > ptcut && //common2
	    RecMuonIsoSumPt[j] < 3. && RecMuonIsoSumPt[jk] < 3. &&
	    //            RecMuonIsoDY[j] < 0.15 && RecMuonIsoDY[jk] < 0.15 &&
	    //(RecMuonIsoSumPt[j] + RecMuonIsoHad[j])/RecMuonPt[j] < 0.15 && (RecMuonIsoSumPt[jk] + RecMuonIsoHad[jk])/RecMuonPt[jk] < 0.15 &&//!!!!!!!!!
            fabs(RecMuonEta[j]) < eta_cut && fabs(RecMuonEta[jk]) < eta_cut && //common3
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
      }//mass cut
    }


    if (!realdata){

      if (select){
       	for (int j=0;j<nb_Y;j++){
	  if (fabs(Ymuon) > Y_bin_limits[j] && fabs(Ymuon) < Y_bin_limits[j+1]){ 
	    if (costhetaCSreco__RECO > 0) Align_Telescope_hMeasCos_M_Y_Forward[j]->Fill(MZ__RECO);
	    if (costhetaCSreco__RECO < 0 && costhetaCSreco__RECO >= -1.) Align_Telescope_hMeasCos_M_Y_Backward[j]->Fill(MZ__RECO);
	 
	    if (gen_st1_select){
	      if (gen_costhetaCSreco_st1 > 0){ 
		hUnDetectorCos_M_Y_Forward[j]->Fill(MZ_st1);
	      }
	      if (gen_costhetaCSreco_st1 < 0 && gen_costhetaCSreco_st1 >= -1.){ 
		hUnDetectorCos_M_Y_Backward[j]->Fill(MZ_st1);
	      }
	      if (costhetaCSreco__RECO > 0 && gen_costhetaCSreco_st1 > 0){ 
		Response_UnDetector_Forward[j]->Fill(MZ_st1, MZ__RECO);
	      }
	      if (costhetaCSreco__RECO < 0 && gen_costhetaCSreco_st1 < 0 && costhetaCSreco__RECO >= -1. && gen_costhetaCSreco_st1 >= -1.) Response_UnDetector_Backward[j]->Fill(MZ_st1, MZ__RECO);
	      if (costhetaCSreco__RECO < 0 && gen_costhetaCSreco_st1 > 0 && costhetaCSreco__RECO >= -1.) Response_UnDetector_ForwardBackward[j]->Fill(MZ_st1, MZ__RECO);
	      if (costhetaCSreco__RECO > 0 && gen_costhetaCSreco_st1 < 0 && gen_costhetaCSreco_st1 >= -1.) Response_UnDetector_BackwardForward[j]->Fill(MZ_st1, MZ__RECO);
	    }
	    if (gen_select){
	      if (gen_costhetaCSreco > 0) hNoFsrTruthCos_M_Y_Forward[j]->Fill(MZ);
	      if (gen_costhetaCSreco < 0 && gen_costhetaCSreco >= -1.) hNoFsrTruthCos_M_Y_Backward[j]->Fill(MZ);
	      if (costhetaCSreco__RECO > 0 && gen_costhetaCSreco > 0){ 
		Response_NoFsr_Forward[j]->Fill(MZ, MZ__RECO);
	      }
	      if (costhetaCSreco__RECO < 0 && gen_costhetaCSreco < 0 && costhetaCSreco__RECO >= -1 && gen_costhetaCSreco >= -1){
		Response_NoFsr_Backward[j]->Fill(MZ, MZ__RECO);	
	      }
	    }
	  }
	}
      }

 
    }

  }//end of event loop
  
  for (int k=0;k<nb_Y;k++){
    Response_UnDetector_Forward_NO_NORM[k]->Add(Response_UnDetector_Forward[k]);
    Response_UnDetector_Backward_NO_NORM[k]->Add(Response_UnDetector_Backward[k]);
    Response_UnDetector_ForwardBackward_NO_NORM[k]->Add(Response_UnDetector_ForwardBackward[k]);
    Response_UnDetector_BackwardForward_NO_NORM[k]->Add(Response_UnDetector_BackwardForward[k]);
  }

  double norm_factor_forward[nb][nb_Y];
  double norm_factor_backward[nb][nb_Y];

  double norm_factor_forwardbackward[nb][nb_Y];
  double norm_factor_backwardforward[nb][nb_Y];

  double norm_factor_fsr_forward[nb][nb_Y];
  double norm_factor_fsr_backward[nb][nb_Y];

  for (int k=0;k<nb_Y;k++){
    for (int i=0;i<nb;i++){
      norm_factor_forward[i][k] = 0;
      norm_factor_backward[i][k] = 0;

      norm_factor_fsr_forward[i][k] = 0;
      norm_factor_fsr_backward[i][k] = 0;

      for (int j=0;j<nb;j++){
	norm_factor_forward[i][k] += Response_UnDetector_Forward[k]->GetBinContent(i+1,j+1);
	norm_factor_backward[i][k] += Response_UnDetector_Backward[k]->GetBinContent(i+1,j+1);

        norm_factor_forwardbackward[i][k] += Response_UnDetector_ForwardBackward[k]->GetBinContent(i+1,j+1);        
        norm_factor_backwardforward[i][k] += Response_UnDetector_BackwardForward[k]->GetBinContent(i+1,j+1);

	norm_factor_fsr_forward[i][k] += Response_NoFsr_Forward[k]->GetBinContent(i+1,j+1);
	norm_factor_fsr_backward[i][k] += Response_NoFsr_Backward[k]->GetBinContent(i+1,j+1);

      }
      if (norm_factor_forward[i][k] != 0.) for (int j=0;j<nb;j++) Response_UnDetector_Forward[k]->SetBinContent(i+1,j+1,Response_UnDetector_Forward[k]->GetBinContent(i+1,j+1)/norm_factor_forward[i][k]);
      if (norm_factor_backward[i][k] != 0.) for (int j=0;j<nb;j++) Response_UnDetector_Backward[k]->SetBinContent(i+1,j+1,Response_UnDetector_Backward[k]->GetBinContent(i+1,j+1)/norm_factor_backward[i][k]);

      if (norm_factor_forwardbackward[i][k] != 0.) for (int j=0;j<nb;j++) Response_UnDetector_ForwardBackward[k]->SetBinContent(i+1,j+1,Response_UnDetector_ForwardBackward[k]->GetBinContent(i+1,j+1)/norm_factor_forwardbackward[i][k]);
      if (norm_factor_backwardforward[i][k] != 0.) for (int j=0;j<nb;j++) Response_UnDetector_BackwardForward[k]->SetBinContent(i+1,j+1,Response_UnDetector_BackwardForward[k]->GetBinContent(i+1,j+1)/norm_factor_backwardforward[i][k]);

      if (norm_factor_fsr_forward[i][k] != 0.) for (int j=0;j<nb;j++) Response_NoFsr_Forward[k]->SetBinContent(i+1,j+1,Response_NoFsr_Forward[k]->GetBinContent(i+1,j+1)/norm_factor_fsr_forward[i][k]);
      if (norm_factor_fsr_backward[i][k] != 0.) for (int j=0;j<nb;j++) Response_NoFsr_Backward[k]->SetBinContent(i+1,j+1,Response_NoFsr_Backward[k]->GetBinContent(i+1,j+1)/norm_factor_fsr_backward[i][k]);

    } 
  }


  TMatrixD Rij_UnDet_FF_0(nb,nb);
  TMatrixD Rij_UnDet_FF_1(nb,nb);
  TMatrixD Rij_UnDet_FF_2(nb,nb);
  TMatrixD Rij_UnDet_FF_3(nb,nb);

  TMatrixD Rij_NoFsr_FF_0(nb,nb);
  TMatrixD Rij_NoFsr_FF_1(nb,nb);
  TMatrixD Rij_NoFsr_FF_2(nb,nb);
  TMatrixD Rij_NoFsr_FF_3(nb,nb);

  TMatrixD Rij_UnDet_BB_0(nb,nb);
  TMatrixD Rij_UnDet_BB_1(nb,nb);
  TMatrixD Rij_UnDet_BB_2(nb,nb);
  TMatrixD Rij_UnDet_BB_3(nb,nb);

  TMatrixD Rij_NoFsr_BB_0(nb,nb);
  TMatrixD Rij_NoFsr_BB_1(nb,nb);
  TMatrixD Rij_NoFsr_BB_2(nb,nb);
  TMatrixD Rij_NoFsr_BB_3(nb,nb);

  TMatrixD Orig_Rij_UnDet_FF_0(nb,nb);
  TMatrixD Orig_Rij_UnDet_FF_1(nb,nb);
  TMatrixD Orig_Rij_UnDet_FF_2(nb,nb);
  TMatrixD Orig_Rij_UnDet_FF_3(nb,nb);

  TMatrixD Orig_Rij_NoFsr_FF_0(nb,nb);
  TMatrixD Orig_Rij_NoFsr_FF_1(nb,nb);
  TMatrixD Orig_Rij_NoFsr_FF_2(nb,nb);
  TMatrixD Orig_Rij_NoFsr_FF_3(nb,nb);

  TMatrixD Orig_Rij_UnDet_BB_0(nb,nb);
  TMatrixD Orig_Rij_UnDet_BB_1(nb,nb);
  TMatrixD Orig_Rij_UnDet_BB_2(nb,nb);
  TMatrixD Orig_Rij_UnDet_BB_3(nb,nb);

  TMatrixD Orig_Rij_NoFsr_BB_0(nb,nb);
  TMatrixD Orig_Rij_NoFsr_BB_1(nb,nb);
  TMatrixD Orig_Rij_NoFsr_BB_2(nb,nb);
  TMatrixD Orig_Rij_NoFsr_BB_3(nb,nb);

  TMatrixD Inv_Rij_UnDet_FF_0(nb,nb);
  TMatrixD Inv_Rij_UnDet_FF_1(nb,nb);
  TMatrixD Inv_Rij_UnDet_FF_2(nb,nb);
  TMatrixD Inv_Rij_UnDet_FF_3(nb,nb);

  TMatrixD Inv_Rij_NoFsr_FF_0(nb,nb);
  TMatrixD Inv_Rij_NoFsr_FF_1(nb,nb);
  TMatrixD Inv_Rij_NoFsr_FF_2(nb,nb);
  TMatrixD Inv_Rij_NoFsr_FF_3(nb,nb);

  TMatrixD Inv_Rij_UnDet_BB_0(nb,nb);
  TMatrixD Inv_Rij_UnDet_BB_1(nb,nb);
  TMatrixD Inv_Rij_UnDet_BB_2(nb,nb);
  TMatrixD Inv_Rij_UnDet_BB_3(nb,nb);

  TMatrixD Inv_Rij_NoFsr_BB_0(nb,nb);
  TMatrixD Inv_Rij_NoFsr_BB_1(nb,nb);
  TMatrixD Inv_Rij_NoFsr_BB_2(nb,nb);
  TMatrixD Inv_Rij_NoFsr_BB_3(nb,nb);


  TMatrixD Test_Rij_UnDet_FF_0(nb,nb);
  TMatrixD Test_Rij_UnDet_FF_1(nb,nb);
  TMatrixD Test_Rij_UnDet_FF_2(nb,nb);
  TMatrixD Test_Rij_UnDet_FF_3(nb,nb);

  TMatrixD Test_Rij_NoFsr_FF_0(nb,nb);
  TMatrixD Test_Rij_NoFsr_FF_1(nb,nb);
  TMatrixD Test_Rij_NoFsr_FF_2(nb,nb);
  TMatrixD Test_Rij_NoFsr_FF_3(nb,nb);

  TMatrixD Test_Rij_UnDet_BB_0(nb,nb);
  TMatrixD Test_Rij_UnDet_BB_1(nb,nb);
  TMatrixD Test_Rij_UnDet_BB_2(nb,nb);
  TMatrixD Test_Rij_UnDet_BB_3(nb,nb);

  TMatrixD Test_Rij_NoFsr_BB_0(nb,nb);
  TMatrixD Test_Rij_NoFsr_BB_1(nb,nb);
  TMatrixD Test_Rij_NoFsr_BB_2(nb,nb);
  TMatrixD Test_Rij_NoFsr_BB_3(nb,nb);

  int totdim = nb*nb;
  TArrayD ff_0(totdim);
  TArrayD ff_1(totdim);
  TArrayD ff_2(totdim);
  TArrayD ff_3(totdim);

  TArrayD ff_NoFsr_0(totdim);
  TArrayD ff_NoFsr_1(totdim);
  TArrayD ff_NoFsr_2(totdim);
  TArrayD ff_NoFsr_3(totdim);

  TArrayD bb_0(totdim);
  TArrayD bb_1(totdim);
  TArrayD bb_2(totdim);
  TArrayD bb_3(totdim);

  TArrayD bb_NoFsr_0(totdim);
  TArrayD bb_NoFsr_1(totdim);
  TArrayD bb_NoFsr_2(totdim);
  TArrayD bb_NoFsr_3(totdim);

  for (int i=0;i<nb;i++){
    for (int j=0;j<nb;j++){
      int k = nb*i+j;
      ff_0[k] = Response_UnDetector_Forward[0]->GetBinContent(i+1,j+1);
      ff_1[k] = Response_UnDetector_Forward[1]->GetBinContent(i+1,j+1);
      ff_2[k] = Response_UnDetector_Forward[2]->GetBinContent(i+1,j+1);
      ff_3[k] = Response_UnDetector_Forward[3]->GetBinContent(i+1,j+1);

      ff_NoFsr_0[k] = Response_NoFsr_Forward[0]->GetBinContent(i+1,j+1);
      ff_NoFsr_1[k] = Response_NoFsr_Forward[1]->GetBinContent(i+1,j+1);
      ff_NoFsr_2[k] = Response_NoFsr_Forward[2]->GetBinContent(i+1,j+1);
      ff_NoFsr_3[k] = Response_NoFsr_Forward[3]->GetBinContent(i+1,j+1);

      bb_0[k] = Response_UnDetector_Backward[0]->GetBinContent(i+1,j+1);
      bb_1[k] = Response_UnDetector_Backward[1]->GetBinContent(i+1,j+1);
      bb_2[k] = Response_UnDetector_Backward[2]->GetBinContent(i+1,j+1);
      bb_3[k] = Response_UnDetector_Backward[3]->GetBinContent(i+1,j+1);

      bb_NoFsr_0[k] = Response_NoFsr_Backward[0]->GetBinContent(i+1,j+1);
      bb_NoFsr_1[k] = Response_NoFsr_Backward[1]->GetBinContent(i+1,j+1);
      bb_NoFsr_2[k] = Response_NoFsr_Backward[2]->GetBinContent(i+1,j+1);
      bb_NoFsr_3[k] = Response_NoFsr_Backward[3]->GetBinContent(i+1,j+1);

    }
  }
  Rij_UnDet_FF_0.SetMatrixArray(ff_0.GetArray());
  Rij_UnDet_FF_1.SetMatrixArray(ff_1.GetArray());
  Rij_UnDet_FF_2.SetMatrixArray(ff_2.GetArray());
  Rij_UnDet_FF_3.SetMatrixArray(ff_3.GetArray());

  Rij_NoFsr_FF_0.SetMatrixArray(ff_NoFsr_0.GetArray());
  Rij_NoFsr_FF_1.SetMatrixArray(ff_NoFsr_1.GetArray());
  Rij_NoFsr_FF_2.SetMatrixArray(ff_NoFsr_2.GetArray());
  Rij_NoFsr_FF_3.SetMatrixArray(ff_NoFsr_3.GetArray());

  Rij_UnDet_BB_0.SetMatrixArray(bb_0.GetArray());
  Rij_UnDet_BB_1.SetMatrixArray(bb_1.GetArray());
  Rij_UnDet_BB_2.SetMatrixArray(bb_2.GetArray());
  Rij_UnDet_BB_3.SetMatrixArray(bb_3.GetArray());

  Rij_NoFsr_BB_0.SetMatrixArray(bb_NoFsr_0.GetArray());
  Rij_NoFsr_BB_1.SetMatrixArray(bb_NoFsr_1.GetArray());
  Rij_NoFsr_BB_2.SetMatrixArray(bb_NoFsr_2.GetArray());
  Rij_NoFsr_BB_3.SetMatrixArray(bb_NoFsr_3.GetArray());

  Orig_Rij_UnDet_FF_0 = Rij_UnDet_FF_0;
  Orig_Rij_UnDet_FF_1 = Rij_UnDet_FF_1;
  Orig_Rij_UnDet_FF_2 = Rij_UnDet_FF_2;
  Orig_Rij_UnDet_FF_3 = Rij_UnDet_FF_3;

  Orig_Rij_NoFsr_FF_0 = Rij_NoFsr_FF_0;
  Orig_Rij_NoFsr_FF_1 = Rij_NoFsr_FF_1;
  Orig_Rij_NoFsr_FF_2 = Rij_NoFsr_FF_2;
  Orig_Rij_NoFsr_FF_3 = Rij_NoFsr_FF_3;


  Orig_Rij_UnDet_BB_0 = Rij_UnDet_BB_0;
  Orig_Rij_UnDet_BB_1 = Rij_UnDet_BB_1;
  Orig_Rij_UnDet_BB_2 = Rij_UnDet_BB_2;
  Orig_Rij_UnDet_BB_3 = Rij_UnDet_BB_3;

  Orig_Rij_NoFsr_BB_0 = Rij_NoFsr_BB_0;
  Orig_Rij_NoFsr_BB_1 = Rij_NoFsr_BB_1;
  Orig_Rij_NoFsr_BB_2 = Rij_NoFsr_BB_2;
  Orig_Rij_NoFsr_BB_3 = Rij_NoFsr_BB_3;

  Inv_Rij_UnDet_FF_0 = Rij_UnDet_FF_0.Invert();
  Inv_Rij_UnDet_FF_1 = Rij_UnDet_FF_1.Invert();
  Inv_Rij_UnDet_FF_2 = Rij_UnDet_FF_2.Invert();
  Inv_Rij_UnDet_FF_3 = Rij_UnDet_FF_3.Invert();

  Inv_Rij_NoFsr_FF_0 = Rij_NoFsr_FF_0.Invert();
  Inv_Rij_NoFsr_FF_1 = Rij_NoFsr_FF_1.Invert();
  Inv_Rij_NoFsr_FF_2 = Rij_NoFsr_FF_2.Invert();
  Inv_Rij_NoFsr_FF_3 = Rij_NoFsr_FF_3.Invert();

  Inv_Rij_UnDet_BB_0 = Rij_UnDet_BB_0.Invert();
  Inv_Rij_UnDet_BB_1 = Rij_UnDet_BB_1.Invert();
  Inv_Rij_UnDet_BB_2 = Rij_UnDet_BB_2.Invert();
  Inv_Rij_UnDet_BB_3 = Rij_UnDet_BB_3.Invert();

  Inv_Rij_NoFsr_BB_0 = Rij_NoFsr_BB_0.Invert();
  Inv_Rij_NoFsr_BB_1 = Rij_NoFsr_BB_1.Invert();
  Inv_Rij_NoFsr_BB_2 = Rij_NoFsr_BB_2.Invert();
  Inv_Rij_NoFsr_BB_3 = Rij_NoFsr_BB_3.Invert();



  Test_Rij_UnDet_FF_0 = Inv_Rij_UnDet_FF_0*Orig_Rij_UnDet_FF_0;
  Test_Rij_UnDet_FF_1 = Inv_Rij_UnDet_FF_1*Orig_Rij_UnDet_FF_1;
  Test_Rij_UnDet_FF_2 = Inv_Rij_UnDet_FF_2*Orig_Rij_UnDet_FF_2;
  Test_Rij_UnDet_FF_3 = Inv_Rij_UnDet_FF_3*Orig_Rij_UnDet_FF_3;

  Test_Rij_NoFsr_FF_0 = Inv_Rij_NoFsr_FF_0*Orig_Rij_NoFsr_FF_0;
  Test_Rij_NoFsr_FF_1 = Inv_Rij_NoFsr_FF_1*Orig_Rij_NoFsr_FF_1;
  Test_Rij_NoFsr_FF_2 = Inv_Rij_NoFsr_FF_2*Orig_Rij_NoFsr_FF_2;
  Test_Rij_NoFsr_FF_3 = Inv_Rij_NoFsr_FF_3*Orig_Rij_NoFsr_FF_3;

  Test_Rij_UnDet_BB_0 = Inv_Rij_UnDet_BB_0*Orig_Rij_UnDet_BB_0;
  Test_Rij_UnDet_BB_1 = Inv_Rij_UnDet_BB_1*Orig_Rij_UnDet_BB_1;
  Test_Rij_UnDet_BB_2 = Inv_Rij_UnDet_BB_2*Orig_Rij_UnDet_BB_2;
  Test_Rij_UnDet_BB_3 = Inv_Rij_UnDet_BB_3*Orig_Rij_UnDet_BB_3;

  Test_Rij_NoFsr_BB_0 = Inv_Rij_NoFsr_BB_0*Orig_Rij_NoFsr_BB_0;
  Test_Rij_NoFsr_BB_1 = Inv_Rij_NoFsr_BB_1*Orig_Rij_NoFsr_BB_1;
  Test_Rij_NoFsr_BB_2 = Inv_Rij_NoFsr_BB_2*Orig_Rij_NoFsr_BB_2;
  Test_Rij_NoFsr_BB_3 = Inv_Rij_NoFsr_BB_3*Orig_Rij_NoFsr_BB_3;



  const double *test_ff_0 = Test_Rij_UnDet_FF_0.GetMatrixArray();
  const double *test_ff_1 = Test_Rij_UnDet_FF_1.GetMatrixArray();
  const double *test_ff_2 = Test_Rij_UnDet_FF_2.GetMatrixArray();
  const double *test_ff_3 = Test_Rij_UnDet_FF_3.GetMatrixArray();

  const double *test_ff_NoFsr_0 = Test_Rij_NoFsr_FF_0.GetMatrixArray();
  const double *test_ff_NoFsr_1 = Test_Rij_NoFsr_FF_1.GetMatrixArray();
  const double *test_ff_NoFsr_2 = Test_Rij_NoFsr_FF_2.GetMatrixArray();
  const double *test_ff_NoFsr_3 = Test_Rij_NoFsr_FF_3.GetMatrixArray();

  const double *test_bb_0 = Test_Rij_UnDet_BB_0.GetMatrixArray();
  const double *test_bb_1 = Test_Rij_UnDet_BB_1.GetMatrixArray();
  const double *test_bb_2 = Test_Rij_UnDet_BB_2.GetMatrixArray();
  const double *test_bb_3 = Test_Rij_UnDet_BB_3.GetMatrixArray();

  const double *test_bb_NoFsr_0 = Test_Rij_NoFsr_BB_0.GetMatrixArray();
  const double *test_bb_NoFsr_1 = Test_Rij_NoFsr_BB_1.GetMatrixArray();
  const double *test_bb_NoFsr_2 = Test_Rij_NoFsr_BB_2.GetMatrixArray();
  const double *test_bb_NoFsr_3 = Test_Rij_NoFsr_BB_3.GetMatrixArray();


  const double *inv_ff_0 = Inv_Rij_UnDet_FF_0.GetMatrixArray();
  const double *inv_ff_1 = Inv_Rij_UnDet_FF_1.GetMatrixArray();
  const double *inv_ff_2 = Inv_Rij_UnDet_FF_2.GetMatrixArray();
  const double *inv_ff_3 = Inv_Rij_UnDet_FF_3.GetMatrixArray();

  const double *inv_ff_NoFsr_0 = Inv_Rij_NoFsr_FF_0.GetMatrixArray();
  const double *inv_ff_NoFsr_1 = Inv_Rij_NoFsr_FF_1.GetMatrixArray();
  const double *inv_ff_NoFsr_2 = Inv_Rij_NoFsr_FF_2.GetMatrixArray();
  const double *inv_ff_NoFsr_3 = Inv_Rij_NoFsr_FF_3.GetMatrixArray();

  const double *inv_bb_0 = Inv_Rij_UnDet_BB_0.GetMatrixArray();
  const double *inv_bb_1 = Inv_Rij_UnDet_BB_1.GetMatrixArray();
  const double *inv_bb_2 = Inv_Rij_UnDet_BB_2.GetMatrixArray();
  const double *inv_bb_3 = Inv_Rij_UnDet_BB_3.GetMatrixArray();

  const double *inv_bb_NoFsr_0 = Inv_Rij_NoFsr_BB_0.GetMatrixArray();
  const double *inv_bb_NoFsr_1 = Inv_Rij_NoFsr_BB_1.GetMatrixArray();
  const double *inv_bb_NoFsr_2 = Inv_Rij_NoFsr_BB_2.GetMatrixArray();
  const double *inv_bb_NoFsr_3 = Inv_Rij_NoFsr_BB_3.GetMatrixArray();


  for (int i=0;i<nb;i++){
    for (int j=0;j<nb;j++){
      int k = nb*i+j;
      
      if (i == j){
	if (test_ff_0[k] != 1) cout<<"diagonal for the inv x resp for forward det matrix "<< i<<"   "<<j<<"   "<<test_ff_0[k]<<endl;
	if (test_ff_1[k] != 1) cout<<"diagonal for the inv x resp for forward det matrix  "<< i<<"   "<<j<<"   "<<test_ff_1[k]<<endl;
	if (test_ff_2[k] != 1) cout<<"diagonal for the inv x resp for forward det matrix  "<< i<<"   "<<j<<"   "<<test_ff_2[k]<<endl;
	if (test_ff_3[k] != 1) cout<<"diagonal for the inv x resp for forward det matrix  "<< i<<"   "<<j<<"   "<<test_ff_3[k]<<endl;

	if (test_ff_NoFsr_0[k] != 1) cout<<"diagonal for the inv x resp for forward fsr matrix "<< i<<"   "<<j<<"   "<<test_ff_NoFsr_0[k]<<endl;
	if (test_ff_NoFsr_1[k] != 1) cout<<"diagonal for the inv x resp for forward fsr matrix  "<< i<<"   "<<j<<"   "<<test_ff_NoFsr_1[k]<<endl;
	if (test_ff_NoFsr_2[k] != 1) cout<<"diagonal for the inv x resp for forward fsr matrix  "<< i<<"   "<<j<<"   "<<test_ff_NoFsr_2[k]<<endl;
	if (test_ff_NoFsr_3[k] != 1) cout<<"diagonal for the inv x resp for forward fsr matrix  "<< i<<"   "<<j<<"   "<<test_ff_NoFsr_3[k]<<endl;

	if (test_bb_0[k] != 1) cout<<"diagonal for the inv x resp for backward det matrix "<< i<<"   "<<j<<"   "<<test_bb_0[k]<<endl;
	if (test_bb_1[k] != 1) cout<<"diagonal for the inv x resp for backward det matrix  "<< i<<"   "<<j<<"   "<<test_bb_1[k]<<endl;
	if (test_bb_2[k] != 1) cout<<"diagonal for the inv x resp for backward det matrix  "<< i<<"   "<<j<<"   "<<test_bb_2[k]<<endl;
	if (test_bb_3[k] != 1) cout<<"diagonal for the inv x resp for backward det matrix  "<< i<<"   "<<j<<"   "<<test_bb_3[k]<<endl;

	if (test_bb_NoFsr_0[k] != 1) cout<<"diagonal for the inv x resp for backward fsr matrix "<< i<<"   "<<j<<"   "<<test_bb_NoFsr_0[k]<<endl;
	if (test_bb_NoFsr_1[k] != 1) cout<<"diagonal for the inv x resp for backward fsr matrix  "<< i<<"   "<<j<<"   "<<test_bb_NoFsr_1[k]<<endl;
	if (test_bb_NoFsr_2[k] != 1) cout<<"diagonal for the inv x resp for backward fsr matrix  "<< i<<"   "<<j<<"   "<<test_bb_NoFsr_2[k]<<endl;
	if (test_bb_NoFsr_3[k] != 1) cout<<"diagonal for the inv x resp for backward fsr matrix  "<< i<<"   "<<j<<"   "<<test_bb_NoFsr_3[k]<<endl;
      }
   
      Align_Telescope_Inv_Response_UnDetector_Forward[0]->SetBinContent(i+1,j+1,inv_ff_0[k]);
      Align_Telescope_Inv_Response_UnDetector_Forward[1]->SetBinContent(i+1,j+1,inv_ff_1[k]);
      Align_Telescope_Inv_Response_UnDetector_Forward[2]->SetBinContent(i+1,j+1,inv_ff_2[k]);
      Align_Telescope_Inv_Response_UnDetector_Forward[3]->SetBinContent(i+1,j+1,inv_ff_3[k]);

      Align_Telescope_Inv_Response_NoFsr_Forward[0]->SetBinContent(i+1,j+1,inv_ff_NoFsr_0[k]);
      Align_Telescope_Inv_Response_NoFsr_Forward[1]->SetBinContent(i+1,j+1,inv_ff_NoFsr_1[k]);
      Align_Telescope_Inv_Response_NoFsr_Forward[2]->SetBinContent(i+1,j+1,inv_ff_NoFsr_2[k]);
      Align_Telescope_Inv_Response_NoFsr_Forward[3]->SetBinContent(i+1,j+1,inv_ff_NoFsr_3[k]);

      Align_Telescope_Inv_Response_UnDetector_Backward[0]->SetBinContent(i+1,j+1,inv_bb_0[k]);
      Align_Telescope_Inv_Response_UnDetector_Backward[1]->SetBinContent(i+1,j+1,inv_bb_1[k]);
      Align_Telescope_Inv_Response_UnDetector_Backward[2]->SetBinContent(i+1,j+1,inv_bb_2[k]);
      Align_Telescope_Inv_Response_UnDetector_Backward[3]->SetBinContent(i+1,j+1,inv_bb_3[k]);

      Align_Telescope_Inv_Response_NoFsr_Backward[0]->SetBinContent(i+1,j+1,inv_bb_NoFsr_0[k]);
      Align_Telescope_Inv_Response_NoFsr_Backward[1]->SetBinContent(i+1,j+1,inv_bb_NoFsr_1[k]);
      Align_Telescope_Inv_Response_NoFsr_Backward[2]->SetBinContent(i+1,j+1,inv_bb_NoFsr_2[k]);
      Align_Telescope_Inv_Response_NoFsr_Backward[3]->SetBinContent(i+1,j+1,inv_bb_NoFsr_3[k]);
    }
  }


    for (int j=0;j<nb_Y;j++){
      sprintf(name_h,"Align_Telescope_MC_meas_Forward_%i",j);
      file_cov->WriteTObject(Align_Telescope_hMeasCos_M_Y_Forward[j],name_h);
      sprintf(name_h,"Align_Telescope_MC_meas_Backward_%i",j);
      file_cov->WriteTObject(Align_Telescope_hMeasCos_M_Y_Backward[j],name_h);


      sprintf(name_h,"Align_Telescope_inv_response_undetector_forward_%i",j);
      file_cov->WriteTObject(Align_Telescope_Inv_Response_UnDetector_Forward[j],name_h);
      sprintf(name_h,"Align_Telescope_inv_response_undetector_backward_%i",j);
      file_cov->WriteTObject(Align_Telescope_Inv_Response_UnDetector_Backward[j],name_h);

      sprintf(name_h,"Align_Telescope_inv_response_nofsr_forward_%i",j);
      file_cov->WriteTObject(Align_Telescope_Inv_Response_NoFsr_Forward[j],name_h);
      sprintf(name_h,"Align_Telescope_inv_response_nofsr_backward_%i",j);
      file_cov->WriteTObject(Align_Telescope_Inv_Response_NoFsr_Backward[j],name_h);
    }
  //  file_cov->Write();

    //  h_MZ_st1_minus_st3->SaveAs("fsr_check.C");

    /*
  TCanvas *del = new TCanvas();
  hMass->Draw();
  del->SaveAs("hMass_MC.C");

  TCanvas *del2 = new TCanvas();
  h_EneDiff_P->Draw();
  h_EneDiff_N->SetLineColor(2);
  h_EneDiff_N->Draw("sames");
  del2->SaveAs("fsr_tail.C");
    */
}

int main (int argc, char **argv){ 
  tree1r(); 
} 
