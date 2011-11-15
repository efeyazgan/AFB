#include "afbbase.h"

using namespace std;


void tree1r()
{


  char name_ang[100];
  int angle_value = 2212;
  sprintf(name_ang,"sin2thetaW%i_MUON_MC_Meas_NoFsr.root",angle_value);
  TFile *file_cov = new TFile(name_ang,"RECREATE");
  file_cov->cd(); 
 
  TChain myTree("angles");
  
  sprintf(name_ang,"/data2/efe/ntuples/sin2theta/%i_0to49.root",angle_value);
  myTree.Add(name_ang);


  TH1::AddDirectory(true);

   myTree.SetBranchAddress("p1id", &p1id);
   myTree.SetBranchAddress("p2id", &p2id);
   myTree.SetBranchAddress("p1_px", &p1_px);
   myTree.SetBranchAddress("p1_py", &p1_py);
   myTree.SetBranchAddress("p1_pz", &p1_pz);
   myTree.SetBranchAddress("p1_E", &p1_E);
   myTree.SetBranchAddress("p2_px", &p2_px);
   myTree.SetBranchAddress("p2_py", &p2_py);
   myTree.SetBranchAddress("p2_pz", &p2_pz);
   myTree.SetBranchAddress("p2_E", &p2_E);
   myTree.SetBranchAddress("Mll_gen", &Mll_gen);
   myTree.SetBranchAddress("costheta_gen", &costheta_gen);
   myTree.SetBranchAddress("phi_gen", &phi_gen);
   myTree.SetBranchAddress("costheta_true", &costheta_true);
   myTree.SetBranchAddress("phi_true", &phi_true);
   myTree.SetBranchAddress("yZ_gen", &yZ_gen);
   myTree.SetBranchAddress("zpT_gen", &zpT_gen);
   myTree.SetBranchAddress("l_px_gen", &l_px_gen);
   myTree.SetBranchAddress("l_py_gen", &l_py_gen);
   myTree.SetBranchAddress("l_pz_gen", &l_pz_gen);
   myTree.SetBranchAddress("l_E_gen", &l_E_gen);
   myTree.SetBranchAddress("lbar_px_gen", &lbar_px_gen);
   myTree.SetBranchAddress("lbar_py_gen", &lbar_py_gen);
   myTree.SetBranchAddress("lbar_pz_gen", &lbar_pz_gen);
   myTree.SetBranchAddress("lbar_E_gen", &lbar_E_gen);
   myTree.SetBranchAddress("l_eta_gen", &l_eta_gen);
   myTree.SetBranchAddress("l_pt_gen", &l_pt_gen);
   myTree.SetBranchAddress("lbar_eta_gen", &lbar_eta_gen);
   myTree.SetBranchAddress("lbar_pt_gen", &lbar_pt_gen);
   myTree.SetBranchAddress("Mll_genfsr", &Mll_genfsr);
   myTree.SetBranchAddress("costheta_genfsr", &costheta_genfsr);
   myTree.SetBranchAddress("phi_genfsr", &phi_genfsr);
   myTree.SetBranchAddress("yZ_genfsr", &yZ_genfsr);
   myTree.SetBranchAddress("zpT_genfsr", &zpT_genfsr);
   myTree.SetBranchAddress("l_px_genfsr", &l_px_genfsr);
   myTree.SetBranchAddress("l_py_genfsr", &l_py_genfsr);
   myTree.SetBranchAddress("l_pz_genfsr", &l_pz_genfsr);
   myTree.SetBranchAddress("l_E_genfsr", &l_E_genfsr);
   myTree.SetBranchAddress("lbar_px_genfsr", &lbar_px_genfsr);
   myTree.SetBranchAddress("lbar_py_genfsr", &lbar_py_genfsr);
   myTree.SetBranchAddress("lbar_pz_genfsr", &lbar_pz_genfsr);
   myTree.SetBranchAddress("lbar_E_genfsr", &lbar_E_genfsr);
   myTree.SetBranchAddress("l_eta_genfsr", &l_eta_genfsr);
   myTree.SetBranchAddress("l_pt_genfsr", &l_pt_genfsr);
   myTree.SetBranchAddress("lbar_eta_genfsr", &lbar_eta_genfsr);
   myTree.SetBranchAddress("lbar_pt_genfsr", &lbar_pt_genfsr);
   myTree.SetBranchAddress("Mll_reco", &Mll_reco);
   myTree.SetBranchAddress("costheta_reco", &costheta_reco);
   myTree.SetBranchAddress("phi_reco", &phi_reco);
   myTree.SetBranchAddress("yZ_reco", &yZ_reco);
   myTree.SetBranchAddress("zpT_reco", &zpT_reco);
   myTree.SetBranchAddress("l_px_reco", &l_px_reco);
   myTree.SetBranchAddress("l_py_reco", &l_py_reco);
   myTree.SetBranchAddress("l_pz_reco", &l_pz_reco);
   myTree.SetBranchAddress("l_E_reco", &l_E_reco);
   myTree.SetBranchAddress("lbar_px_reco", &lbar_px_reco);
   myTree.SetBranchAddress("lbar_py_reco", &lbar_py_reco);
   myTree.SetBranchAddress("lbar_pz_reco", &lbar_pz_reco);
   myTree.SetBranchAddress("lbar_E_reco", &lbar_E_reco);
   myTree.SetBranchAddress("l_eta_reco", &l_eta_reco);
   myTree.SetBranchAddress("l_pt_reco", &l_pt_reco);
   myTree.SetBranchAddress("lbar_eta_reco", &lbar_eta_reco);
   myTree.SetBranchAddress("lbar_pt_reco", &lbar_pt_reco);

   // float r_test = 1.;
  int nb = 8;
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
  /*
  xAxis_AFB[10] = 600;
  xAxis_AFB[11] = 1500;
  */
  int nb_Y = 4;
  float Y_bin_limits[nb_Y+1]; 
  Y_bin_limits[0] = 0.0;
  Y_bin_limits[1] = 1.0;
  Y_bin_limits[2] = 1.25;
  Y_bin_limits[3] = 1.5;
  Y_bin_limits[4] = 2.5;
 



  

    for (int j=0;j<nb_Y;j++){
      sprintf(name_h,"h_Sin%i_MeasCos_Forward_Y_%i_",angle_value,j);
      h_Sin_MeasCos_M_Y_Forward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
      sprintf(name_h,"h_Sin%i_MeasCos_Backward_Y_%i_",angle_value,j);
      h_Sin_MeasCos_M_Y_Backward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
      
      sprintf(name_h,"Response_Sin%i_UnDetector_Forward_Y_%i_",angle_value,j);
      Response_Sin_UnDetector_Forward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);
      sprintf(name_h,"Response_Sin%i_UnDetector_Backward_Y_%i_",angle_value,j);
      Response_Sin_UnDetector_Backward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);
      
      sprintf(name_h,"Response_Sin%i_NoFsr_Forward_Y_%i_",angle_value,j);
      Response_Sin_NoFsr_Forward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);
      sprintf(name_h,"Response_Sin%i_NoFsr_Backward_Y_%i_",angle_value,j);
      Response_Sin_NoFsr_Backward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);
      
      sprintf(name_h,"Inv_Response_Sin%i_UnDetector_Forward_Y_%i_",angle_value,j);
      Inv_Response_Sin_UnDetector_Forward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);
      sprintf(name_h,"Inv_Response_Sin%i_UnDetector_Backward_Y_%i_",angle_value,j);
      Inv_Response_Sin_UnDetector_Backward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);
      
      sprintf(name_h,"Inv_Response_Sin%i_NoFsr_Forward_Y_%i_",angle_value,j);
      Inv_Response_Sin_NoFsr_Forward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);
      sprintf(name_h,"Inv_Response_Sin%i_NoFsr_Backward_Y_%i_",angle_value,j);
      Inv_Response_Sin_NoFsr_Backward[j] = new TH2D(name_h,name_h,nb, xAxis_AFB,nb, xAxis_AFB);
      
      /*
	sprintf(name_h,"sin2thetaW%i_TrueMass_%i_%i",angle_value,i,j);
	hTrueCos_MASS_M_Y[i][j] = new TH1D(name_h,name_h,100,xAxis_AFB[i],xAxis_AFB[i+1]);
      */
      //
    }
  

  TH1D* h_MZ_st3 = new TH1D("h_MZ_st3","",nb, xAxis_AFB);
  TH1D* h_MZ_st1 = new TH1D("h_MZ_st1","",nb, xAxis_AFB);

  TH1D *hMass = new TH1D("hMass","hMass",nb,xAxis_AFB);

  TH1D *h_MZ_true = new TH1D("h_MZ_true","h_MZ_true",nb,xAxis_AFB);

   
  Int_t nevent = myTree.GetEntries();
  //nevent = 1000000;
  for (Int_t iev=0;iev<nevent;iev++) {
    if (iev%100000 == 0) cout<<iev<<"/"<<nevent<<endl;
    myTree.GetEntry(iev);


    float ptcut = 20;
    float eta_cut = 2.4;

  
    float parton_pt[50] = {};
    float parton_eta[50] = {};
    float parton_phi[50] = {};
    float parton_px[50] = {};
    float parton_py[50] = {};
    float parton_pz[50] = {};
    float parton_e[50] = {};
  
    float parton_pt_st1[50] = {};
    float parton_eta_st1[50] = {};
    float parton_phi_st1[50] = {};
    float parton_px_st1[50] = {};
    float parton_py_st1[50] = {};
    float parton_pz_st1[50] = {};
    float parton_e_st1[50] = {};

    //   float quark_pt[50] = {};
    //    float quark_eta[50] = {};
    //    float quark_phi[50] = {};
    float quark_px[50] = {};
    float quark_py[50] = {};
    float quark_pz[50] = {};
    //   float quark_m[50] = {};
    float quark_e[50] = {};
    //    int quark_id[50] = {};
    //    int quark_charge[50] = {};
  



    parton_pt[0] = l_pt_gen;
    parton_pt[1] = lbar_pt_gen;
    parton_eta[0] = l_eta_gen;
    parton_eta[1] = lbar_eta_gen;
    parton_phi[0] = atan2(l_py_gen,l_px_gen);
    parton_phi[1] = atan2(lbar_py_gen,lbar_px_gen);
    parton_px[0] = l_px_gen;
    parton_px[1] = lbar_px_gen;
    parton_py[0] = l_py_gen;
    parton_py[1] = lbar_py_gen;
    parton_pz[0] = l_pz_gen;
    parton_pz[1] = lbar_pz_gen;
    parton_e[0] = l_E_gen;
    parton_e[1] = lbar_E_gen;

    parton_pt_st1[0] = l_pt_genfsr;
    parton_pt_st1[1] = lbar_pt_genfsr;
    parton_eta_st1[0] = l_eta_genfsr;
    parton_eta_st1[1] = lbar_eta_genfsr;
    parton_phi_st1[0] = atan2(l_py_genfsr,l_px_genfsr);
    parton_phi_st1[1] = atan2(lbar_py_genfsr,lbar_px_genfsr);
    parton_px_st1[0] = l_px_genfsr;
    parton_px_st1[1] = lbar_px_genfsr;
    parton_py_st1[0] = l_py_genfsr;
    parton_py_st1[1] = lbar_py_genfsr;
    parton_pz_st1[0] = l_pz_genfsr;
    parton_pz_st1[1] = lbar_pz_genfsr;
    parton_e_st1[0] = l_E_genfsr;
    parton_e_st1[1] = lbar_E_genfsr;

    double MZ = Mll_gen;
    double MZmuon = Mll_reco;
    double MZ_st1 = Mll_genfsr;
    double gen_costhetaCSreco = costheta_gen;
    double gen_costhetaCSreco_st1 = costheta_genfsr;
    double costhetaCSreco__RECO = costheta_reco;
    double dimuonrapidity = yZ_gen;
    double RecMuonPx[2],RecMuonPy[2],RecMuonPz[2],RecMuonPt[2],RecMuonEta[2];
    double Ymuon = yZ_reco;
    RecMuonPx[0] = l_px_reco;
    RecMuonPx[1] = lbar_px_reco;
    RecMuonPy[0] = l_py_reco;
    RecMuonPy[1] = lbar_py_reco;
    RecMuonPz[0] = l_pz_reco;
    RecMuonPz[1] = lbar_pz_reco;
    RecMuonEta[0] = l_eta_reco;
    RecMuonEta[1] = lbar_eta_reco;
    RecMuonPt[0] = l_pt_reco;
    RecMuonPt[1] = lbar_pt_reco;

    quark_px[0] = p1_px;
    quark_px[1] = p2_px;
    quark_py[0] = p1_py;
    quark_py[1] = p2_py;
    quark_pz[0] = p1_pz;
    quark_pz[1] = p2_pz;
    quark_e[0] = p1_E;
    quark_e[1] = p2_E;
    double MZ_test = sqrt(pow(quark_e[0]+quark_e[1],2) - (pow(quark_px[0]+quark_px[1],2)+pow(quark_py[0]+quark_py[1],2)+pow(quark_pz[0]+quark_pz[1],2) ));
    //    double rapidity = 0.5*log((quark_e[0]+quark_e[1]+quark_pz[0]+quark_pz[1])/(quark_e[0]+quark_e[1]-quark_pz[0]-quark_pz[1]));

    h_MZ_st3->Fill(MZ);
    h_MZ_st1->Fill(MZ_st1);
    h_MZ_true->Fill(MZ_test);

    int gen_select = 0;
    int gen_st1_select = 0;
    int select = 0;

    if (MZ > 40. && parton_pt[0] > ptcut &&  parton_pt[1] > ptcut && fabs(parton_eta[0]) < eta_cut && fabs(parton_eta[1]) < eta_cut) gen_select = 1;
    if (MZ_st1 > 40. && parton_pt_st1[0] > ptcut &&  parton_pt_st1[1] > ptcut && fabs(parton_eta_st1[0]) < eta_cut && fabs(parton_eta_st1[1]) < eta_cut) gen_st1_select = 1;

    TVector3 mom1(RecMuonPx[0],RecMuonPy[0],RecMuonPz[0]);
    TVector3 mom2(RecMuonPx[1],RecMuonPy[1],RecMuonPz[1]);
    float cosine = mom1.Angle(mom2) - TMath::Pi();    
    if (RecMuonPt[0] > ptcut && RecMuonPt[1] > ptcut && fabs(RecMuonEta[0]) <eta_cut && fabs(RecMuonEta[1]) <eta_cut && cosine < -0.025 && MZmuon > 40.){
      select = 1;
      hMass->Fill(MZmuon);
    }

      if (select){
       	for (int j=0;j<nb_Y;j++){
	  if (fabs(Ymuon) > Y_bin_limits[j] && fabs(Ymuon) < Y_bin_limits[j+1]){ 
	    if (costhetaCSreco__RECO > 0) h_Sin_MeasCos_M_Y_Forward[j]->Fill(MZmuon);
	    if (costhetaCSreco__RECO < 0 && costhetaCSreco__RECO >= -1.) h_Sin_MeasCos_M_Y_Backward[j]->Fill(MZmuon);

	    if (gen_st1_select){	      
	      if (costhetaCSreco__RECO > 0 && gen_costhetaCSreco_st1 > 0) Response_Sin_UnDetector_Forward[j]->Fill(MZ_st1, MZmuon);
	      if (costhetaCSreco__RECO < 0 && gen_costhetaCSreco_st1 < 0 && costhetaCSreco__RECO >= -1. && gen_costhetaCSreco_st1 >= -1.) Response_Sin_UnDetector_Backward[j]->Fill(MZ_st1, MZmuon);
	    }
	    if (gen_select){
	      if (costhetaCSreco__RECO > 0 && gen_costhetaCSreco > 0) Response_Sin_NoFsr_Forward[j]->Fill(MZ, MZmuon);
	      if (costhetaCSreco__RECO < 0 && gen_costhetaCSreco < 0 && costhetaCSreco__RECO >= -1 && gen_costhetaCSreco >= -1) Response_Sin_NoFsr_Backward[j]->Fill(MZ, MZmuon);		
	    }
	  }
	}
      }
    



     
  }//end of event loop
  
  double norm_factor_forward[nb][nb_Y];
  double norm_factor_backward[nb][nb_Y];

  double norm_factor_fsr_forward[nb][nb_Y];
  double norm_factor_fsr_backward[nb][nb_Y];

  for (int k=0;k<nb_Y;k++){
    for (int i=0;i<nb;i++){
      norm_factor_forward[i][k] = 0;
      norm_factor_backward[i][k] = 0;

      norm_factor_fsr_forward[i][k] = 0;
      norm_factor_fsr_backward[i][k] = 0;

      for (int j=0;j<nb;j++){
	norm_factor_forward[i][k] += Response_Sin_UnDetector_Forward[k]->GetBinContent(i+1,j+1);
	norm_factor_backward[i][k] += Response_Sin_UnDetector_Backward[k]->GetBinContent(i+1,j+1);

	norm_factor_fsr_forward[i][k] += Response_Sin_NoFsr_Forward[k]->GetBinContent(i+1,j+1);
	norm_factor_fsr_backward[i][k] += Response_Sin_NoFsr_Backward[k]->GetBinContent(i+1,j+1);
      }
      if (norm_factor_forward[i][k] != 0.) for (int j=0;j<nb;j++) Response_Sin_UnDetector_Forward[k]->SetBinContent(i+1,j+1,Response_Sin_UnDetector_Forward[k]->GetBinContent(i+1,j+1)/norm_factor_forward[i][k]);
      if (norm_factor_backward[i][k] != 0.) for (int j=0;j<nb;j++) Response_Sin_UnDetector_Backward[k]->SetBinContent(i+1,j+1,Response_Sin_UnDetector_Backward[k]->GetBinContent(i+1,j+1)/norm_factor_backward[i][k]);

      if (norm_factor_fsr_forward[i][k] != 0.) for (int j=0;j<nb;j++) Response_Sin_NoFsr_Forward[k]->SetBinContent(i+1,j+1,Response_Sin_NoFsr_Forward[k]->GetBinContent(i+1,j+1)/norm_factor_fsr_forward[i][k]);
      if (norm_factor_fsr_backward[i][k] != 0.) for (int j=0;j<nb;j++) Response_Sin_NoFsr_Backward[k]->SetBinContent(i+1,j+1,Response_Sin_NoFsr_Backward[k]->GetBinContent(i+1,j+1)/norm_factor_fsr_backward[i][k]);
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
      ff_0[k] = Response_Sin_UnDetector_Forward[0]->GetBinContent(i+1,j+1);
      ff_1[k] = Response_Sin_UnDetector_Forward[1]->GetBinContent(i+1,j+1);
      ff_2[k] = Response_Sin_UnDetector_Forward[2]->GetBinContent(i+1,j+1);
      ff_3[k] = Response_Sin_UnDetector_Forward[3]->GetBinContent(i+1,j+1);

      ff_NoFsr_0[k] = Response_Sin_NoFsr_Forward[0]->GetBinContent(i+1,j+1);
      ff_NoFsr_1[k] = Response_Sin_NoFsr_Forward[1]->GetBinContent(i+1,j+1);
      ff_NoFsr_2[k] = Response_Sin_NoFsr_Forward[2]->GetBinContent(i+1,j+1);
      ff_NoFsr_3[k] = Response_Sin_NoFsr_Forward[3]->GetBinContent(i+1,j+1);

      bb_0[k] = Response_Sin_UnDetector_Backward[0]->GetBinContent(i+1,j+1);
      bb_1[k] = Response_Sin_UnDetector_Backward[1]->GetBinContent(i+1,j+1);
      bb_2[k] = Response_Sin_UnDetector_Backward[2]->GetBinContent(i+1,j+1);
      bb_3[k] = Response_Sin_UnDetector_Backward[3]->GetBinContent(i+1,j+1);

      bb_NoFsr_0[k] = Response_Sin_NoFsr_Backward[0]->GetBinContent(i+1,j+1);
      bb_NoFsr_1[k] = Response_Sin_NoFsr_Backward[1]->GetBinContent(i+1,j+1);
      bb_NoFsr_2[k] = Response_Sin_NoFsr_Backward[2]->GetBinContent(i+1,j+1);
      bb_NoFsr_3[k] = Response_Sin_NoFsr_Backward[3]->GetBinContent(i+1,j+1);

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
   
      Inv_Response_Sin_UnDetector_Forward[0]->SetBinContent(i+1,j+1,inv_ff_0[k]);
      Inv_Response_Sin_UnDetector_Forward[1]->SetBinContent(i+1,j+1,inv_ff_1[k]);
      Inv_Response_Sin_UnDetector_Forward[2]->SetBinContent(i+1,j+1,inv_ff_2[k]);
      Inv_Response_Sin_UnDetector_Forward[3]->SetBinContent(i+1,j+1,inv_ff_3[k]);

      Inv_Response_Sin_NoFsr_Forward[0]->SetBinContent(i+1,j+1,inv_ff_NoFsr_0[k]);
      Inv_Response_Sin_NoFsr_Forward[1]->SetBinContent(i+1,j+1,inv_ff_NoFsr_1[k]);
      Inv_Response_Sin_NoFsr_Forward[2]->SetBinContent(i+1,j+1,inv_ff_NoFsr_2[k]);
      Inv_Response_Sin_NoFsr_Forward[3]->SetBinContent(i+1,j+1,inv_ff_NoFsr_3[k]);

      Inv_Response_Sin_UnDetector_Backward[0]->SetBinContent(i+1,j+1,inv_bb_0[k]);
      Inv_Response_Sin_UnDetector_Backward[1]->SetBinContent(i+1,j+1,inv_bb_1[k]);
      Inv_Response_Sin_UnDetector_Backward[2]->SetBinContent(i+1,j+1,inv_bb_2[k]);
      Inv_Response_Sin_UnDetector_Backward[3]->SetBinContent(i+1,j+1,inv_bb_3[k]);

      Inv_Response_Sin_NoFsr_Backward[0]->SetBinContent(i+1,j+1,inv_bb_NoFsr_0[k]);
      Inv_Response_Sin_NoFsr_Backward[1]->SetBinContent(i+1,j+1,inv_bb_NoFsr_1[k]);
      Inv_Response_Sin_NoFsr_Backward[2]->SetBinContent(i+1,j+1,inv_bb_NoFsr_2[k]);
      Inv_Response_Sin_NoFsr_Backward[3]->SetBinContent(i+1,j+1,inv_bb_NoFsr_3[k]);
    }
  }


    for (int j=0;j<nb_Y;j++){
      sprintf(name_h,"Sin%i_MC_meas_Forward_%i",angle_value,j);
      file_cov->WriteTObject(h_Sin_MeasCos_M_Y_Forward[j],name_h);
      sprintf(name_h,"Sin%i_MC_meas_Backward_%i",angle_value,j);
      file_cov->WriteTObject(h_Sin_MeasCos_M_Y_Backward[j],name_h);

      sprintf(name_h,"response_sin%i_undetector_forward_%i",angle_value,j);
      file_cov->WriteTObject(Response_Sin_UnDetector_Forward[j],name_h);
      sprintf(name_h,"response_sin%i_undetector_backward_%i",angle_value,j);
      file_cov->WriteTObject(Response_Sin_UnDetector_Backward[j],name_h);

      sprintf(name_h,"response_sin%i_nofsr_forward_%i",angle_value,j);
      file_cov->WriteTObject(Response_Sin_NoFsr_Forward[j],name_h);
      sprintf(name_h,"response_sin%i_nofsr_backward_%i",angle_value,j);
      file_cov->WriteTObject(Response_Sin_NoFsr_Backward[j],name_h);

      sprintf(name_h,"inv_response_sin%i_undetector_forward_%i",angle_value,j);
      file_cov->WriteTObject(Inv_Response_Sin_UnDetector_Forward[j],name_h);
      sprintf(name_h,"inv_response_sin%i_undetector_backward_%i",angle_value,j);
      file_cov->WriteTObject(Inv_Response_Sin_UnDetector_Backward[j],name_h);

      sprintf(name_h,"inv_response_sin%i_nofsr_forward_%i",angle_value,j);
      file_cov->WriteTObject(Inv_Response_Sin_NoFsr_Forward[j],name_h);
      sprintf(name_h,"inv_response_sin%i_nofsr_backward_%i",angle_value,j);
      file_cov->WriteTObject(Inv_Response_Sin_NoFsr_Backward[j],name_h);
    }

 

  TCanvas *del = new TCanvas();
  hMass->Draw();
  h_MZ_st3->SetLineColor(2);
  h_MZ_st3->Draw("sames");
  sprintf(name_ang,"sin2thetaW%i_hMass_MC.C",angle_value);
  del->SaveAs(name_ang);


}

int main (int argc, char **argv){ 
  tree1r(); 
} 

