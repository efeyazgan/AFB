#include "afbbase.h"

using namespace std;

void tree1r()
{

 // TFile *file_cov = new TFile("MUON_MC_Meas_NoFsr_ForClosure.root","RECREATE"); float r_test = 0.5; 
  TFile *file_cov = new TFile("Data_output_new_2fb_eta24_Y25.root","RECREATE"); float r_test = 1.0;
  //  TFile *file_cov = new TFile("RELVAL_NEW_Data_output_new_2fb.root","RECREATE"); float r_test = 1.0;
  file_cov->cd(); 
 
  /*
    TChain myTree("demo/MuonTree");
    myTree.Add("/data2/efe/ntuples/386/DY_MuMu_UPDATED_powheg_wo_HLT_filter.root");
  */
  //myTree.Add("/tmp/efe/DY_MuMu_UPDATED_powheg_wo_HLT_filter.root");
 
  TChain myTree("analyzeBasicPat/MuonTree");
  //main data file///
/*
  myTree.Add("/data1/efe/ntuples/keng/data/DoubleMu_May10ReReco_MuPhysR2.root");
  myTree.Add("/data1/efe/ntuples/keng/data/DoubleMu_Run2011A_July06_MuPhys.root");
*/

//2.2 fb-1 data file

  myTree.Add("/data2/efe/ntuples/keng/2invfb/DoubleMu_May10ReReco_R3_calo.root");//215.146 pb-1
  myTree.Add("/data2/efe/ntuples/keng/2invfb/DoubleMu_Run2011A_167913_calo.root");//930.228
  myTree.Add("/data2/efe/ntuples/keng/2invfb/DoubleMu_05Aug2011_calo.root");//370.915
  myTree.Add("/data2/efe/ntuples/keng/2invfb/DoubleMu_Run2011A_173692_calo.root");//662.967	

  /////


  //RelVal Old Geometry
  //myTree.Add("/data2/efe/ntuples/keng/alignment/DoubleMu_Relval_old_ntuple.root");
  //RelVal New geometry
  //myTree.Add("/data2/efe/ntuples/keng/alignment/DoubleMu_Relval_special_ntuple.root");
   
  //old geometry
  //myTree.Add("/data2/efe/ntuples/keng/alignment/DoubleMu_Relval_old_ntuple.root");

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


  //  cout<<"r_TESTTTTTT = "<<r_test<<endl;
  //  cout<<"USING  "<< r_test*100 <<"   PERCENT OF ALL EVENTS FOR THE MEASURED!!!!!!"<<endl;
  int nb = 10;/////!!!!!!
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
  Y_bin_limits[3] = 1.50;//!!!!!!!
  Y_bin_limits[4] = 2.5;///

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

  TH1D *h_debug_eta1 = new TH1D("h_debug_eta1","h_debug_eta1",20,-2.6,2.6);
  TH1D *h_debug_eta2 = new TH1D("h_debug_eta2","h_debug_eta2",20,-2.6,2.6);

  TH1D *h_debug_eta1_control = new TH1D("h_debug_eta1_control","h_debug_eta1_control",20,-2.6,2.6);
  TH1D *h_debug_eta2_control = new TH1D("h_debug_eta2_control","h_debug_eta2_control",20,-2.6,2.6);

  TH1D *h_debug_pt1 = new TH1D("h_debug_pt1","h_debug_pt1",60,0,300);
  TH1D *h_debug_pt2 = new TH1D("h_debug_pt2","h_debug_pt2",60,0,300);

  TH1D *h_debug_pt1_control = new TH1D("h_debug_pt1_control","h_debug_pt1_control",60,0,300);
  TH1D *h_debug_pt2_control = new TH1D("h_debug_pt2_control","h_debug_pt2_control",60,0,300);

  TH1D *h_debug_y = new TH1D("h_debug_y","h_debug_y",50,-3,3);
  TH1D *h_debug_y_control = new TH1D("h_debug_y_control","h_debug_y_control",50,-3,3);

  TH1D *h_debug_costheta = new TH1D("h_debug_costheta","h_debug_costheta",22,-1.05,1.05);
  TH1D *h_debug_costheta_control = new TH1D("h_debug_costheta_control","h_debug_costheta_control",22,-1.05,1.05);

  TProfile *h_debug_y_vs_costheta = new TProfile("h_debug_y_vs_costheta","h_debug_y_vs_costheta",10,-2.4,2.4);

  TProfile *h_costheta_vs_mass = new TProfile("h_costheta_vs_mass","h_costheta_vs_mass",22,-1.05,1.05);

  for (int j=0;j<nb_Y;j++){
    sprintf(name_h,"hMeasCos_Forward_Y_%i_",j);
    hMeasCos_M_Y_Forward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    hMeasCos_M_Y_Forward[j]->Sumw2();
    sprintf(name_h,"hMeasCos_Backward_Y_%i_",j);
    hMeasCos_M_Y_Backward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    hMeasCos_M_Y_Backward[j]->Sumw2();

    sprintf(name_h,"hMeasCos_Forward_Y_FineBin_%i_",j);
    hMeasCos_M_Y_Forward_FineBin[j] = new TH1D(name_h,name_h,100,40,640);
    hMeasCos_M_Y_Forward_FineBin[j]->Sumw2();
    sprintf(name_h,"hMeasCos_Backward_Y_FineBin_%i_",j);
    hMeasCos_M_Y_Backward_FineBin[j] = new TH1D(name_h,name_h,100,40,640);
    hMeasCos_M_Y_Backward_FineBin[j]->Sumw2();
  }



  TH1D *hMass = new TH1D("hMass","hMass",nb,xAxis_AFB);


  Int_t nevent = myTree.GetEntries();
  //nevent = 200000;
  for (Int_t iev=0;iev<nevent;iev++) {
    if (iev%100000 == 0) cout<<iev<<"/"<<nevent<<endl;
    myTree.GetEntry(iev);


    int common = 0;
    float ptcut = 20.;
    float etacut = 2.4;

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
            fabs(RecMuonEta[j]) <etacut && fabs(RecMuonEta[jk]) <etacut && //common3
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
	//eo debug
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
	
	h_costheta_vs_mass->Fill(costhetaCSreco__RECO,MZmuon);

	//debug Y>1.50
	if (MZmuon > 200. && MZmuon < 600.){
	  h_debug_y_vs_costheta->Fill(Ymuon,costhetaCSreco__RECO);
	  if (fabs(Ymuon) > 1.50 && fabs(Ymuon) < etacut){
	    h_debug_eta1->Fill(RecMuonEta[ind1]);
	    h_debug_eta2->Fill(RecMuonEta[ind2]);
	    
	    h_debug_pt1->Fill(RecMuonPt[ind1]);
	    h_debug_pt2->Fill(RecMuonPt[ind2]);
	    
	    h_debug_y->Fill(Ymuon);
	    h_debug_costheta->Fill(costhetaCSreco__RECO);
	  }
	  if (fabs(Ymuon) > 1.25 && fabs(Ymuon) < 1.50 ){
	    h_debug_eta1_control->Fill(RecMuonEta[ind1]);
	    h_debug_eta2_control->Fill(RecMuonEta[ind2]);
	    
	    h_debug_pt1_control->Fill(RecMuonPt[ind1]);
	    h_debug_pt2_control->Fill(RecMuonPt[ind2]);
	    
	    h_debug_y_control->Fill(Ymuon);
	    h_debug_costheta_control->Fill(costhetaCSreco__RECO);
	  }	
	}
    	
      }//mass cut
    }

    if (realdata){

      if (select){
       	for (int j=0;j<nb_Y;j++){
	  if (fabs(Ymuon) > Y_bin_limits[j] && fabs(Ymuon) < Y_bin_limits[j+1]){ 
	    //if (MZ__RECO > 200. && fabs(Ymuon) > 1.5 ) cout<<costhetaCSreco__RECO<<"   "<<MZ__RECO<<endl;
	    if (costhetaCSreco__RECO > 0){ 
	      hMeasCos_M_Y_Forward[j]->Fill(MZ__RECO);
	      hMeasCos_M_Y_Forward_FineBin[j]->Fill(MZ__RECO);
	    }
	    if (costhetaCSreco__RECO < 0 && costhetaCSreco__RECO >= -1.){
	      hMeasCos_M_Y_Backward[j]->Fill(MZ__RECO);
	      hMeasCos_M_Y_Backward_FineBin[j]->Fill(MZ__RECO);
	    }
	  }
	}
      }
    }

  }//end of event loop
  



  for (int j=0;j<nb_Y;j++){
    sprintf(name_h,"MC_DATA_meas_Forward_%i",j);
    file_cov->WriteTObject(hMeasCos_M_Y_Forward[j],name_h);
    sprintf(name_h,"MC_DATA_meas_Backward_%i",j);
    file_cov->WriteTObject(hMeasCos_M_Y_Backward[j],name_h);

    sprintf(name_h,"MC_DATA_meas_Forward_FineBin%i",j);
    file_cov->WriteTObject(hMeasCos_M_Y_Forward_FineBin[j],name_h);
    sprintf(name_h,"MC_DATA_meas_Backward_FineBin%i",j);
    file_cov->WriteTObject(hMeasCos_M_Y_Backward_FineBin[j],name_h);
  }


    TCanvas *c1 = new TCanvas();
    c1->cd();
    h_debug_eta1->Draw();
    h_debug_eta1_control->SetLineColor(4);
    h_debug_eta1_control->Draw("sames");
    h_debug_eta2->SetLineColor(2);
    h_debug_eta2->Draw("sames");
    h_debug_eta2_control->SetLineColor(6);
    h_debug_eta2_control->Draw("sames");
    c1->SaveAs("data_eta.C");

    TCanvas *c2 = new TCanvas();
    c2->cd();
    h_debug_pt1->Draw();
    h_debug_pt1_control->SetLineColor(4);
    h_debug_pt1_control->Draw("sames");
    h_debug_pt2->SetLineColor(2);
    h_debug_pt2->Draw("sames");
    h_debug_pt2_control->SetLineColor(6);
    h_debug_pt2_control->Draw("sames");
    c2->SaveAs("data_pt.C");


    TCanvas *c3 = new TCanvas();
    c3->cd();
    h_debug_y->Draw();
    h_debug_y_control->SetLineColor(4);
    h_debug_y_control->Draw("sames");
    c3->SaveAs("data_y.C");

    TCanvas *c4 = new TCanvas();
    c4->cd();
    h_debug_costheta->Draw();
    h_debug_costheta_control->SetLineColor(4);
    h_debug_costheta_control->Draw("sames");
    c4->SaveAs("data_costheta.C");
    
    h_debug_y_vs_costheta->SaveAs("data_y_vs_costheta.C");

    hMass->SaveAs("mass.C");

    h_costheta_vs_mass->SaveAs("mass_vs_costheta.C");
}

int main (int argc, char **argv){ 
  tree1r(); 
}

// 
