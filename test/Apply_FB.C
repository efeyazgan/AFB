#include "afbbase.h"

using namespace std;

void tree1r()
{

  double AFB(double forward, double backward);
  double RAWAFBERROR(double rawafb, double forward, double backward);

  int nb = 10;
  int nb_sin = 7;//nominal 8 but not much stats for > 7
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

  //  int nb_Y = 4;
  float Y_bin_limits[nb_Y+1];
  Y_bin_limits[0] = 0.0;
  Y_bin_limits[1] = 1.0;
  Y_bin_limits[2] = 1.25;
  Y_bin_limits[3] = 1.5;
  Y_bin_limits[4] = 2.5;//!!!!!


  //BACKGROUNDS //2.1 fb-1

  float qcd_plus[10][4]={{15.6101,3.46891,2.55067,2.55067},{24.5417,5.4537,4.01007,4.01007},{36.5309,8.11797,5.96909,5.96909},{17.4426,3.53268,1.10396,1.10396},{14.1604,2.86793,0.896228,0.896228},{12.0035,2.43109,0.759717,0.759717},{10.4171,1.65149,0.762228,0.381114},{12.7757,2.02542,0.934808,0.467404},{5.50338,0.872487,0.402686,0.201343},{3.04651,0.482984,0.222916,0.111458}};


  float comb_plus[10][4]={{176.405,37.7656,31.4891,34.3481},{318.07,70.8696,60.1018,68.1324},{403.192,86.0883,71.3106,77.3539},{143.77,26.8729,18.1013,15.3864},{261.095,50.7725,36.7792,35.0576},{95.1678,17.1673,10.5926,8.37181},{118.669,14.9827,8.94244,5.33676},{178.23,21.5657,12.6419,7.5251},{136.861,16.3665,9.69521,5.8249},{96.3007,11.6071,6.92302,4.19616}};



  float qcd_minus[10][4]={{15.1603,3.36896,2.47717,2.47717},{26.1044,5.80099,4.26543,4.26543},{38.3942,8.53203,6.27355,6.27355},{20.2823,4.10781,1.28369,1.28369},{15.5777,3.15497,0.985928,0.985928},{12.4412,2.51974,0.787419,0.787419},{10.1892,1.61537,0.745554,0.372777},{10.9562,1.73695,0.801671,0.400836},{7.34063,1.16376,0.53712,0.26856},{4.05378,0.642673,0.296618,0.148309}};


  float comb_minus[10][4]={{179.121,38.2966,31.5463,34.3583},{312.948,69.5977,59.3277,67.0476},{387.857,82.9255,69.0072,74.7536},{164.584,30.1733,19.5697,16.1114},{257.498,49.9133,35.8412,34.1424},{96.4092,17.3195,10.5584,8.28502},{114.431,14.1187,8.32072,4.9818},{174.835,21.496,12.6558,7.43768},{163.891,19.3096,11.2994,6.68423},{91.055,10.8845,6.43549,3.87916}};


  float comb_plus_qcd_up[11][4];
  float comb_minus_qcd_up[11][4];
  float comb_plus_qcd_down[11][4];
  float comb_minus_qcd_down[11][4];

  float qcd_scale = 100.;//100%
  for (int i=0;i<nb;i++){
    for (int j=0;j<nb_Y;j++){
      comb_plus_qcd_up[i][j] = comb_plus[i][j] - qcd_plus[i][j] + (1.+qcd_scale/100.)*qcd_plus[i][j]; 
      comb_minus_qcd_up[i][j] = comb_minus[i][j] - qcd_minus[i][j] + (1.+qcd_scale/100.)*qcd_minus[i][j]; 
      comb_plus_qcd_down[i][j] = comb_plus[i][j] - qcd_plus[i][j] + (1.-qcd_scale/100.)*qcd_plus[i][j]; 
      comb_minus_qcd_down[i][j] = comb_minus[i][j] - qcd_minus[i][j] + (1.-qcd_scale/100.)*qcd_minus[i][j]; 
    }
  }
  //



  int n_ct = 53;
  int n_mstw = 41;
  int n_nnpdf = 101;


  int ct10as_index = 11;//ct10weights 0 to 10 are alphas uncertainties in the ct10as file 

  int nPDF; ///!!!
  //pdf set 0: CT10, 1: nnpdf, 2: MSTW, 3: CT10as
  int pdf_set = 0;
  
  if (pdf_set == 0){ 
	cout<<"PDF SET :  CT10"<<endl;
	nPDF = n_ct;
  }
  if (pdf_set == 1){ 
	cout<<"PDF SET :  NNPDF"<<endl;
        nPDF = n_nnpdf;
  }
  if (pdf_set == 2){ 
	cout<<"PDF SET :  MSTW"<<endl;
        nPDF = n_mstw;
  } 
  if (pdf_set == 3){
    cout<<"PDF SET : CT10 alphas"<<endl;//MSTW in the root file = ct10as
	nPDF = ct10as_index;
  }

  TH1D *hMeasCos_M_Y_Forward_PDF_ct10[nb_Y][n_ct];
  TH1D *hMeasCos_M_Y_Backward_PDF_ct10[nb_Y][n_ct];
  TH2D *Inv_Response_UnDetector_Forward_PDF_ct10[nb_Y];
  TH2D *Inv_Response_UnDetector_Backward_PDF_ct10[nb_Y];
  TH2D *Inv_Response_NoFsr_Forward_PDF_ct10[nb_Y];
  TH2D *Inv_Response_NoFsr_Backward_PDF_ct10[nb_Y];

  TH1D *hMeasCos_M_Y_Forward_PDF_mstw[nb_Y][n_mstw];
  TH1D *hMeasCos_M_Y_Backward_PDF_mstw[nb_Y][n_mstw];


  TH1D *hMeasCos_M_Y_Forward_PDF_nnpdf[nb_Y][n_nnpdf];
  TH1D *hMeasCos_M_Y_Backward_PDF_nnpdf[nb_Y][n_nnpdf];


  TH1D *hMeasCos_M_Y_Forward_PDF_alpha_s[nb_Y][ct10as_index];
  TH1D *hMeasCos_M_Y_Backward_PDF_alpha_s[nb_Y][ct10as_index];



  float delta_plus = -999.;
  float delta_minus = -999.;
  float afb_p = -999.;
  float afb_m = -999.;
  float afb_0 = -999.;
  float afb_0_mstw = -999.;
  float afb_nnpdf = -999.;
  float afb_alphas0 = -999.;
  float afb_alphas5 = -999.;
  float afb_alphas10 = -999.;

  float DeltaXmaxPlus[nb][nb_Y];
  float DeltaXmaxMinus[nb][nb_Y];
  float sigma[nb][nb_Y];

  float delta_plus_undet = -999.;
  float delta_minus_undet = -999.;
  float afb_p_undet = -999.;
  float afb_m_undet = -999.;
  float afb_0_undet = -999.;



  float DeltaXmaxPlus_undet[nb][nb_Y];
  float DeltaXmaxMinus_undet[nb][nb_Y];
  float sigma_undet[nb][nb_Y];


//  TFile input_fsr_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated.root","read");
//  TFile input_fsr_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_plus_highmass.root","read"); 

//  TFile input_fsr_file("RootFiles/MC_Meas_UnDetector_NoFsr_DYbins_Updated_plus_highmass_eff_pu.root","read");
//  TFile input_fsr_file("RootFiles/MC_Meas_UnDetector_NoFsr_DYbins_Updated_plus_highmass_eff_pu_bincentering.root","read");

//====> for eta<2.1  TFile input_fsr_file("RootFiles/MC_Meas_UnDetector_NoFsr_DYbins_Updated_plus_highmass_eff_pu_bincentering_new.root","read");
//  TFile input_fsr_file("RootFiles/MC_Meas_UnDetector_NoFsr_Y25_eta24.root","read");
  TFile input_fsr_file("RootFiles/MC_Y25_eta24_Weights.root","read"); 
// TFile input_fsr_file("RootFiles/MC_Y25_eta24_Weights_wo_parton_weight.root","read");
//TFile input_fsr_file("RootFiles/MC_Y25_eta24_Weights_noconst.root","read");

//  TFile input_fsr_file("TEST_MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_plus_highmass.root","read");
//TFile input_fsr_file("TEST_YLAST_1_75_MC_Meas_UnDetector_NoFsr_DYbins_Updated_plus_highmass_eff_pu.root","read");

////  TFile input_data_file("RootFiles/MUON_DATA_DYbins.root","read");
//
 //===> For eta<2.1 TFile input_data_file("RootFiles/Data_output_new_2fb.root","read");
  TFile input_data_file("RootFiles/Data_output_new_2fb_eta24_Y25.root","read");

  //TFile input_data_file("RootFiles/RELVAL_OLD_Data_output_new_2fb.root","read");
  //TFile input_data_file("RootFiles/RELVAL_NEW_Data_output_new_2fb.root","read");
  


  TFile input_sin2312_file("RootFiles/sin2thetaW2312_MUON_MC_Meas_NoFsr.root","read");
  TFile input_sin2412_file("RootFiles/sin2thetaW2412_MUON_MC_Meas_NoFsr.root","read");
  TFile input_sin2212_file("RootFiles/sin2thetaW2212_MUON_MC_Meas_NoFsr.root","read");
  TFile input_Align_Bowing_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Bowing.root","read");
  TFile input_Align_Elliptical_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Elliptical.root","read");
  TFile input_Align_Radial_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Radial.root","read");
  TFile input_Align_Sagitta_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Sagitta.root","read");
  TFile input_Align_Skew_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Skew.root","read");
  TFile input_Align_Telescope_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Telescope.root","read");
  TFile input_Align_CurlV2TF_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_CurlV2TF.root","read");
  TFile input_Align_Twist_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Twist.root","read");
  TFile input_Align_Zexpansion_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Zexpansion.root","read");
  //  TFile input_Align_Ideal_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Ideal.root","read");
  TFile input_Align_Ideal_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Ideal_plus_finebin.root","read");
  TFile input_Align_Startup_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Startup.root","read");
  //  TFile input_PDF_ct10_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_CT10.root","read");
  TFile input_PDF_ct10_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_CT10_new.root","read");
  //  TFile input_PDF_mstw_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_MSTW.root","read");
  TFile input_PDF_mstw_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_MSTW_new.root","read");
  //  TFile input_PDF_nnpdf_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_NNPDF.root","read");
  TFile input_PDF_nnpdf_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_NNPDF_new.root","read");
  //  TFile input_PDF_alpha_s_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_ALPHA_S.root","read");
  TFile input_PDF_alpha_s_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_ALPHA_S_new.root","read");//OK

  for (int j=0;j<nb_Y;j++){
    sprintf(name_h,"MC_meas_Forward_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"MC_meas_Backward_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Backward[j]);

    sprintf(name_h,"MC_true_Forward_%i",j);
    input_fsr_file.GetObject(name_h,hTrueCos_M_Y_Forward[j]);
    sprintf(name_h,"MC_true_Backward_%i",j);
    input_fsr_file.GetObject(name_h,hTrueCos_M_Y_Backward[j]);

    for (int ii=0;ii<nb;ii++){
      sprintf(name_h,"hExpectedMass_RAW_M_Y_%i_%i",j,ii);
      input_fsr_file.GetObject(name_h,hExpectedMass_RAW_M_Y[j][ii]);
      sprintf(name_h,"hExpectedMass_UnDet_M_Y_%i_%i",j,ii);
      input_fsr_file.GetObject(name_h,hExpectedMass_UnDet_M_Y[j][ii]);
      sprintf(name_h,"hExpectedMass_NoFsr_M_Y_%i_%i",j,ii);
      input_fsr_file.GetObject(name_h,hExpectedMass_NoFsr_M_Y[j][ii]);


    }

    sprintf(name_h,"MC_meas_Forward_FSR_UP_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Forward_FSR_UP[j]);
    sprintf(name_h,"MC_meas_Backward_FSR_UP_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Backward_FSR_UP[j]);
    sprintf(name_h,"MC_meas_Forward_FSR_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Forward_FSR_DOWN[j]);
    sprintf(name_h,"MC_meas_Backward_FSR_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Backward_FSR_DOWN[j]);

//
    sprintf(name_h,"MC_meas_Forward_ES_UP_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Forward_ES_UP[j]);
    sprintf(name_h,"MC_meas_Backward_ES_UP_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Backward_ES_UP[j]);
    sprintf(name_h,"MC_meas_Forward_ES_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Forward_ES_DOWN[j]);
    sprintf(name_h,"MC_meas_Backward_ES_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Backward_ES_DOWN[j]);
//

    sprintf(name_h,"undetector_forward_%i",j);
    input_fsr_file.GetObject(name_h,hUnDetectorCos_M_Y_Forward[j]);
    sprintf(name_h,"undetector_backward_%i",j);
    input_fsr_file.GetObject(name_h,hUnDetectorCos_M_Y_Backward[j]);

    sprintf(name_h,"undetector_forward_FSR_UP_%i",j);
    input_fsr_file.GetObject(name_h,hUnDetectorCos_M_Y_Forward_FSR_UP[j]);
    sprintf(name_h,"undetector_backward_FSR_UP_%i",j);
    input_fsr_file.GetObject(name_h,hUnDetectorCos_M_Y_Backward_FSR_UP[j]);
    sprintf(name_h,"undetector_forward_FSR_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,hUnDetectorCos_M_Y_Forward_FSR_DOWN[j]);
    sprintf(name_h,"undetector_backward_FSR_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,hUnDetectorCos_M_Y_Backward_FSR_DOWN[j]);

    sprintf(name_h,"truth_no_fsr_forward_%i",j);
    input_fsr_file.GetObject(name_h,hNoFsrTruthCos_M_Y_Forward[j]);
    sprintf(name_h,"truth_no_fsr_backward_%i",j);
    input_fsr_file.GetObject(name_h,hNoFsrTruthCos_M_Y_Backward[j]);

    sprintf(name_h,"response_undetector_forward_%i",j);
    input_fsr_file.GetObject(name_h,Response_UnDetector_Forward[j]);
    sprintf(name_h,"response_undetector_backward_%i",j);
    input_fsr_file.GetObject(name_h,Response_UnDetector_Backward[j]);

    sprintf(name_h,"response_undetector_forwardbackward_%i",j);
    input_fsr_file.GetObject(name_h,Response_UnDetector_ForwardBackward[j]);
    sprintf(name_h,"response_undetector_backwardforward_%i",j);
    input_fsr_file.GetObject(name_h,Response_UnDetector_BackwardForward[j]);

    sprintf(name_h,"response_undetector_forward_no_norm_%i",j);
    input_fsr_file.GetObject(name_h,Response_UnDetector_Forward_NO_NORM[j]);
    sprintf(name_h,"response_undetector_backward_no_norm_%i",j);
    input_fsr_file.GetObject(name_h,Response_UnDetector_Backward_NO_NORM[j]);

    sprintf(name_h,"response_undetector_forwardbackward_no_norm_%i",j);
    input_fsr_file.GetObject(name_h,Response_UnDetector_ForwardBackward_NO_NORM[j]);
    sprintf(name_h,"response_undetector_backwardforward_no_norm_%i",j);
    input_fsr_file.GetObject(name_h,Response_UnDetector_BackwardForward_NO_NORM[j]);

    sprintf(name_h,"response_nofsr_forward_%i",j);
    input_fsr_file.GetObject(name_h,Response_NoFsr_Forward[j]);
    sprintf(name_h,"response_nofsr_backward_%i",j);
    input_fsr_file.GetObject(name_h,Response_NoFsr_Backward[j]);

    sprintf(name_h,"response_nofsr_forward_FSR_UP_%i",j);
    input_fsr_file.GetObject(name_h,Response_NoFsr_Forward_FSR_UP[j]);
    sprintf(name_h,"response_nofsr_backward_FSR_UP_%i",j);
    input_fsr_file.GetObject(name_h,Response_NoFsr_Backward_FSR_UP[j]);
    sprintf(name_h,"response_nofsr_forward_FSR_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,Response_NoFsr_Forward_FSR_DOWN[j]);
    sprintf(name_h,"response_nofsr_backward_FSR_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,Response_NoFsr_Backward_FSR_DOWN[j]);

    sprintf(name_h,"inv_response_undetector_forward_%i",j);
    input_fsr_file.GetObject(name_h,Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"inv_response_undetector_backward_%i",j);
    input_fsr_file.GetObject(name_h,Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"inv_response_nofsr_forward_%i",j);
    input_fsr_file.GetObject(name_h,Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"inv_response_nofsr_backward_%i",j);
    input_fsr_file.GetObject(name_h,Inv_Response_NoFsr_Backward[j]);

    sprintf(name_h,"inv_response_nofsr_forward_FSR_UP_%i",j);
    input_fsr_file.GetObject(name_h,Inv_Response_NoFsr_Forward_FSR_UP[j]);
    sprintf(name_h,"inv_response_nofsr_backward_FSR_UP_%i",j);
    input_fsr_file.GetObject(name_h,Inv_Response_NoFsr_Backward_FSR_UP[j]);
    sprintf(name_h,"inv_response_nofsr_forward_FSR_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,Inv_Response_NoFsr_Forward_FSR_DOWN[j]);
    sprintf(name_h,"inv_response_nofsr_backward_FSR_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,Inv_Response_NoFsr_Backward_FSR_DOWN[j]);

    sprintf(name_h,"inv_response_undet_forward_FSR_UP_%i",j);
    input_fsr_file.GetObject(name_h,Inv_Response_UnDet_Forward_FSR_UP[j]);
    sprintf(name_h,"inv_response_undet_backward_FSR_UP_%i",j);
    input_fsr_file.GetObject(name_h,Inv_Response_UnDet_Backward_FSR_UP[j]);
    sprintf(name_h,"inv_response_undet_forward_FSR_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,Inv_Response_UnDet_Forward_FSR_DOWN[j]);
    sprintf(name_h,"inv_response_undet_backward_FSR_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,Inv_Response_UnDet_Backward_FSR_DOWN[j]);



    sprintf(name_h,"MC_DATA_meas_Forward_%i",j);
    input_data_file.GetObject(name_h,hDataMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"MC_DATA_meas_Backward_%i",j);
    input_data_file.GetObject(name_h,hDataMeasCos_M_Y_Backward[j]);

    //relval
    sprintf(name_h,"MC_DATA_meas_Forward_FineBin%i",j);
    input_data_file.GetObject(name_h,hDataMeasCos_M_Y_Forward_FineBin[j]);
    sprintf(name_h,"MC_DATA_meas_Backward_FineBin%i",j);
    input_data_file.GetObject(name_h,hDataMeasCos_M_Y_Backward_FineBin[j]);
    //end of relval


    sprintf(name_h,"MC_meas_Forward_bkg_%i",j);
    hMeasCos_M_Y_Forward_bkg[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_meas_Backward_bkg_%i",j);
    hMeasCos_M_Y_Backward_bkg[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"MC_meas_Forward_bkg_UP_%i",j);
    hMeasCos_M_Y_Forward_bkg_UP[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_meas_Backward_bkg_UP_%i",j);
    hMeasCos_M_Y_Backward_bkg_UP[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_meas_Forward_bkg_DOWN_%i",j);
    hMeasCos_M_Y_Forward_bkg_DOWN[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_meas_Backward_bkg_DOWN_%i",j);
    hMeasCos_M_Y_Backward_bkg_DOWN[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    //background subtraction
    float luminosity_scale_factor = 2.1/2.2;
    float luminosity_scale_factor_MC = 17.4/2.2;
    /*
    luminosity_scale_factor = 0;
    cout<<"LUMINOSITY SCALE FACTOR ===== 0!!!!"<<endl;
    cout<<"!!!!!!!!!!!!"<<endl;
    */
    for (int ijk = 0;ijk<nb;ijk++){
      float back_subed_signal_plus = hDataMeasCos_M_Y_Forward[j]->GetBinContent(ijk+1) - luminosity_scale_factor*comb_plus[ijk][j];
      hDataMeasCos_M_Y_Forward[j]->SetBinContent(ijk+1,back_subed_signal_plus);
      float back_subed_signal_minus = hDataMeasCos_M_Y_Backward[j]->GetBinContent(ijk+1) - luminosity_scale_factor*comb_minus[ijk][j];
      hDataMeasCos_M_Y_Backward[j]->SetBinContent(ijk+1,back_subed_signal_minus);


      float back_subed_signal_plus_MC = hMeasCos_M_Y_Forward[j]->GetBinContent(ijk+1) + luminosity_scale_factor_MC*comb_plus[ijk][j];
      float back_subed_signal_minus_MC = hMeasCos_M_Y_Backward[j]->GetBinContent(ijk+1) + luminosity_scale_factor_MC*comb_minus[ijk][j];
      hMeasCos_M_Y_Forward_bkg[j]->SetBinContent(ijk+1,back_subed_signal_plus_MC);
      hMeasCos_M_Y_Backward_bkg[j]->SetBinContent(ijk+1,back_subed_signal_minus_MC);

      back_subed_signal_plus_MC += luminosity_scale_factor_MC*comb_plus[ijk][j];
      back_subed_signal_minus_MC += luminosity_scale_factor_MC*comb_minus[ijk][j];


      float back_subed_signal_plus_UP = back_subed_signal_plus_MC - luminosity_scale_factor_MC*comb_plus_qcd_up[ijk][j];
      hMeasCos_M_Y_Forward_bkg_UP[j]->SetBinContent(ijk+1,back_subed_signal_plus_UP);
      float back_subed_signal_plus_DOWN = back_subed_signal_plus_MC - luminosity_scale_factor_MC*comb_plus_qcd_down[ijk][j];
      hMeasCos_M_Y_Forward_bkg_DOWN[j]->SetBinContent(ijk+1,back_subed_signal_plus_DOWN);
      float back_subed_signal_minus_UP = back_subed_signal_minus_MC - luminosity_scale_factor_MC*comb_minus_qcd_up[ijk][j];
      hMeasCos_M_Y_Backward_bkg_UP[j]->SetBinContent(ijk+1,back_subed_signal_minus_UP);
      float back_subed_signal_minus_DOWN = back_subed_signal_minus_MC - luminosity_scale_factor_MC*comb_minus_qcd_down[ijk][j];
      hMeasCos_M_Y_Backward_bkg_DOWN[j]->SetBinContent(ijk+1,back_subed_signal_minus_DOWN);
    }
    //end of background subtraction


    //sin2thetaW 2312
    sprintf(name_h,"Sin2312_MC_meas_Forward_%i",j);
    input_sin2312_file.GetObject(name_h,h_Sin2312_MeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Sin2312_MC_meas_Backward_%i",j);
    input_sin2312_file.GetObject(name_h,h_Sin2312_MeasCos_M_Y_Backward[j]);

    sprintf(name_h,"response_sin2312_undetector_forward_%i",j);
    input_sin2312_file.GetObject(name_h,Response_Sin2312_UnDetector_Forward[j]);
    sprintf(name_h,"response_sin2312_undetector_backward_%i",j);
    input_sin2312_file.GetObject(name_h,Response_Sin2312_UnDetector_Backward[j]);

    sprintf(name_h,"response_sin2312_nofsr_forward_%i",j);
    input_sin2312_file.GetObject(name_h,Response_Sin2312_NoFsr_Forward[j]);
    sprintf(name_h,"response_sin2312_nofsr_backward_%i",j);
    input_sin2312_file.GetObject(name_h,Response_Sin2312_NoFsr_Backward[j]);

    sprintf(name_h,"inv_response_sin2312_undetector_forward_%i",j);
    input_sin2312_file.GetObject(name_h,Inv_Response_Sin2312_UnDetector_Forward[j]);
    sprintf(name_h,"inv_response_sin2312_undetector_backward_%i",j);
    input_sin2312_file.GetObject(name_h,Inv_Response_Sin2312_UnDetector_Backward[j]);

    sprintf(name_h,"inv_response_sin2312_nofsr_forward_%i",j);
    input_sin2312_file.GetObject(name_h,Inv_Response_Sin2312_NoFsr_Forward[j]);
    sprintf(name_h,"inv_response_sin2312_nofsr_backward_%i",j);
    input_sin2312_file.GetObject(name_h,Inv_Response_Sin2312_NoFsr_Backward[j]);
    //eof 2312
    //sin2thetaW 2412
    sprintf(name_h,"Sin2412_MC_meas_Forward_%i",j);
    input_sin2412_file.GetObject(name_h,h_Sin2412_MeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Sin2412_MC_meas_Backward_%i",j);
    input_sin2412_file.GetObject(name_h,h_Sin2412_MeasCos_M_Y_Backward[j]);

    sprintf(name_h,"response_sin2412_undetector_forward_%i",j);
    input_sin2412_file.GetObject(name_h,Response_Sin2412_UnDetector_Forward[j]);
    sprintf(name_h,"response_sin2412_undetector_backward_%i",j);
    input_sin2412_file.GetObject(name_h,Response_Sin2412_UnDetector_Backward[j]);

    sprintf(name_h,"response_sin2412_nofsr_forward_%i",j);
    input_sin2412_file.GetObject(name_h,Response_Sin2412_NoFsr_Forward[j]);
    sprintf(name_h,"response_sin2412_nofsr_backward_%i",j);
    input_sin2412_file.GetObject(name_h,Response_Sin2412_NoFsr_Backward[j]);

    sprintf(name_h,"inv_response_sin2412_undetector_forward_%i",j);
    input_sin2412_file.GetObject(name_h,Inv_Response_Sin2412_UnDetector_Forward[j]);
    sprintf(name_h,"inv_response_sin2412_undetector_backward_%i",j);
    input_sin2412_file.GetObject(name_h,Inv_Response_Sin2412_UnDetector_Backward[j]);

    sprintf(name_h,"inv_response_sin2412_nofsr_forward_%i",j);
    input_sin2412_file.GetObject(name_h,Inv_Response_Sin2412_NoFsr_Forward[j]);
    sprintf(name_h,"inv_response_sin2412_nofsr_backward_%i",j);
    input_sin2412_file.GetObject(name_h,Inv_Response_Sin2412_NoFsr_Backward[j]);
    //eof 2412
    //sin2thetaW 2212
    sprintf(name_h,"Sin2212_MC_meas_Forward_%i",j);
    input_sin2212_file.GetObject(name_h,h_Sin2212_MeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Sin2212_MC_meas_Backward_%i",j);
    input_sin2212_file.GetObject(name_h,h_Sin2212_MeasCos_M_Y_Backward[j]);

    sprintf(name_h,"response_sin2212_undetector_forward_%i",j);
    input_sin2212_file.GetObject(name_h,Response_Sin2212_UnDetector_Forward[j]);
    sprintf(name_h,"response_sin2212_undetector_backward_%i",j);
    input_sin2212_file.GetObject(name_h,Response_Sin2212_UnDetector_Backward[j]);

    sprintf(name_h,"response_sin2212_nofsr_forward_%i",j);
    input_sin2212_file.GetObject(name_h,Response_Sin2212_NoFsr_Forward[j]);
    sprintf(name_h,"response_sin2212_nofsr_backward_%i",j);
    input_sin2212_file.GetObject(name_h,Response_Sin2212_NoFsr_Backward[j]);

    sprintf(name_h,"inv_response_sin2212_undetector_forward_%i",j);
    input_sin2212_file.GetObject(name_h,Inv_Response_Sin2212_UnDetector_Forward[j]);
    sprintf(name_h,"inv_response_sin2212_undetector_backward_%i",j);
    input_sin2212_file.GetObject(name_h,Inv_Response_Sin2212_UnDetector_Backward[j]);

    sprintf(name_h,"inv_response_sin2212_nofsr_forward_%i",j);
    input_sin2212_file.GetObject(name_h,Inv_Response_Sin2212_NoFsr_Forward[j]);
    sprintf(name_h,"inv_response_sin2212_nofsr_backward_%i",j);
    input_sin2212_file.GetObject(name_h,Inv_Response_Sin2212_NoFsr_Backward[j]);
    //eof 2212

    //Align_Bowing
    sprintf(name_h,"Align_Bowing_MC_meas_Forward_%i",j);
    input_Align_Bowing_file.GetObject(name_h,Align_Bowing_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Bowing_MC_meas_Backward_%i",j);
    input_Align_Bowing_file.GetObject(name_h,Align_Bowing_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Bowing_inv_response_undetector_forward_%i",j);
    input_Align_Bowing_file.GetObject(name_h,Align_Bowing_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Bowing_inv_response_undetector_backward_%i",j);
    input_Align_Bowing_file.GetObject(name_h,Align_Bowing_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Bowing_inv_response_nofsr_forward_%i",j);
    input_Align_Bowing_file.GetObject(name_h,Align_Bowing_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Bowing_inv_response_nofsr_backward_%i",j);
    input_Align_Bowing_file.GetObject(name_h,Align_Bowing_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Bowing

 
    //Align_Elliptical
    sprintf(name_h,"Align_Elliptical_MC_meas_Forward_%i",j);
    input_Align_Elliptical_file.GetObject(name_h,Align_Elliptical_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Elliptical_MC_meas_Backward_%i",j);
    input_Align_Elliptical_file.GetObject(name_h,Align_Elliptical_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Elliptical_inv_response_undetector_forward_%i",j);
    input_Align_Elliptical_file.GetObject(name_h,Align_Elliptical_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Elliptical_inv_response_undetector_backward_%i",j);
    input_Align_Elliptical_file.GetObject(name_h,Align_Elliptical_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Elliptical_inv_response_nofsr_forward_%i",j);
    input_Align_Elliptical_file.GetObject(name_h,Align_Elliptical_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Elliptical_inv_response_nofsr_backward_%i",j);
    input_Align_Elliptical_file.GetObject(name_h,Align_Elliptical_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Elliptical

    //Align_Radial
    sprintf(name_h,"Align_Radial_MC_meas_Forward_%i",j);
    input_Align_Radial_file.GetObject(name_h,Align_Radial_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Radial_MC_meas_Backward_%i",j);
    input_Align_Radial_file.GetObject(name_h,Align_Radial_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Radial_inv_response_undetector_forward_%i",j);
    input_Align_Radial_file.GetObject(name_h,Align_Radial_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Radial_inv_response_undetector_backward_%i",j);
    input_Align_Radial_file.GetObject(name_h,Align_Radial_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Radial_inv_response_nofsr_forward_%i",j);
    input_Align_Radial_file.GetObject(name_h,Align_Radial_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Radial_inv_response_nofsr_backward_%i",j);
    input_Align_Radial_file.GetObject(name_h,Align_Radial_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Radial

    //Align_Sagitta
    sprintf(name_h,"Align_Sagitta_MC_meas_Forward_%i",j);
    input_Align_Sagitta_file.GetObject(name_h,Align_Sagitta_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Sagitta_MC_meas_Backward_%i",j);
    input_Align_Sagitta_file.GetObject(name_h,Align_Sagitta_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Sagitta_inv_response_undetector_forward_%i",j);
    input_Align_Sagitta_file.GetObject(name_h,Align_Sagitta_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Sagitta_inv_response_undetector_backward_%i",j);
    input_Align_Sagitta_file.GetObject(name_h,Align_Sagitta_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Sagitta_inv_response_nofsr_forward_%i",j);
    input_Align_Sagitta_file.GetObject(name_h,Align_Sagitta_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Sagitta_inv_response_nofsr_backward_%i",j);
    input_Align_Sagitta_file.GetObject(name_h,Align_Sagitta_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Sagitta

    //Align_Skew
    sprintf(name_h,"Align_Skew_MC_meas_Forward_%i",j);
    input_Align_Skew_file.GetObject(name_h,Align_Skew_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Skew_MC_meas_Backward_%i",j);
    input_Align_Skew_file.GetObject(name_h,Align_Skew_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Skew_inv_response_undetector_forward_%i",j);
    input_Align_Skew_file.GetObject(name_h,Align_Skew_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Skew_inv_response_undetector_backward_%i",j);
    input_Align_Skew_file.GetObject(name_h,Align_Skew_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Skew_inv_response_nofsr_forward_%i",j);
    input_Align_Skew_file.GetObject(name_h,Align_Skew_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Skew_inv_response_nofsr_backward_%i",j);
    input_Align_Skew_file.GetObject(name_h,Align_Skew_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Skew

    //Align_Telescope
    sprintf(name_h,"Align_Telescope_MC_meas_Forward_%i",j);
    input_Align_Telescope_file.GetObject(name_h,Align_Telescope_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Telescope_MC_meas_Backward_%i",j);
    input_Align_Telescope_file.GetObject(name_h,Align_Telescope_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Telescope_inv_response_undetector_forward_%i",j);
    input_Align_Telescope_file.GetObject(name_h,Align_Telescope_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Telescope_inv_response_undetector_backward_%i",j);
    input_Align_Telescope_file.GetObject(name_h,Align_Telescope_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Telescope_inv_response_nofsr_forward_%i",j);
    input_Align_Telescope_file.GetObject(name_h,Align_Telescope_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Telescope_inv_response_nofsr_backward_%i",j);
    input_Align_Telescope_file.GetObject(name_h,Align_Telescope_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Telescope

    //Align_CurlV2TF
    sprintf(name_h,"Align_CurlV2TF_MC_meas_Forward_%i",j);
    input_Align_CurlV2TF_file.GetObject(name_h,Align_CurlV2TF_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_CurlV2TF_MC_meas_Backward_%i",j);
    input_Align_CurlV2TF_file.GetObject(name_h,Align_CurlV2TF_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_CurlV2TF_inv_response_undetector_forward_%i",j);
    input_Align_CurlV2TF_file.GetObject(name_h,Align_CurlV2TF_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_CurlV2TF_inv_response_undetector_backward_%i",j);
    input_Align_CurlV2TF_file.GetObject(name_h,Align_CurlV2TF_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_CurlV2TF_inv_response_nofsr_forward_%i",j);
    input_Align_CurlV2TF_file.GetObject(name_h,Align_CurlV2TF_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_CurlV2TF_inv_response_nofsr_backward_%i",j);
    input_Align_CurlV2TF_file.GetObject(name_h,Align_CurlV2TF_Inv_Response_NoFsr_Backward[j]);
    //eo Align_CurlV2TF

    //Align_Twist
    sprintf(name_h,"Align_Twist_MC_meas_Forward_%i",j);
    input_Align_Twist_file.GetObject(name_h,Align_Twist_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Twist_MC_meas_Backward_%i",j);
    input_Align_Twist_file.GetObject(name_h,Align_Twist_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Twist_inv_response_undetector_forward_%i",j);
    input_Align_Twist_file.GetObject(name_h,Align_Twist_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Twist_inv_response_undetector_backward_%i",j);
    input_Align_Twist_file.GetObject(name_h,Align_Twist_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Twist_inv_response_nofsr_forward_%i",j);
    input_Align_Twist_file.GetObject(name_h,Align_Twist_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Twist_inv_response_nofsr_backward_%i",j);
    input_Align_Twist_file.GetObject(name_h,Align_Twist_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Twist

    //Align_Zexpansion
    sprintf(name_h,"Align_Zexpansion_MC_meas_Forward_%i",j);
    input_Align_Zexpansion_file.GetObject(name_h,Align_Zexpansion_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Zexpansion_MC_meas_Backward_%i",j);
    input_Align_Zexpansion_file.GetObject(name_h,Align_Zexpansion_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Zexpansion_inv_response_undetector_forward_%i",j);
    input_Align_Zexpansion_file.GetObject(name_h,Align_Zexpansion_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Zexpansion_inv_response_undetector_backward_%i",j);
    input_Align_Zexpansion_file.GetObject(name_h,Align_Zexpansion_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Zexpansion_inv_response_nofsr_forward_%i",j);
    input_Align_Zexpansion_file.GetObject(name_h,Align_Zexpansion_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Zexpansion_inv_response_nofsr_backward_%i",j);
    input_Align_Zexpansion_file.GetObject(name_h,Align_Zexpansion_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Zexpansion

    //Align_Ideal
    sprintf(name_h,"Align_Ideal_MC_meas_Forward_%i",j);
    input_Align_Ideal_file.GetObject(name_h,Align_Ideal_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Ideal_MC_meas_Backward_%i",j);
    input_Align_Ideal_file.GetObject(name_h,Align_Ideal_hMeasCos_M_Y_Backward[j]);

    //
    sprintf(name_h,"Align_Ideal_MC_meas_Forward_FineBin_%i",j);
    input_Align_Ideal_file.GetObject(name_h,Align_Ideal_hMeasCos_M_Y_Forward_FineBin[j]);
    sprintf(name_h,"Align_Ideal_MC_meas_Backward_FineBin_%i",j);
    input_Align_Ideal_file.GetObject(name_h,Align_Ideal_hMeasCos_M_Y_Backward_FineBin[j]);
    //

    sprintf(name_h,"Align_Ideal_inv_response_undetector_forward_%i",j);
    input_Align_Ideal_file.GetObject(name_h,Align_Ideal_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Ideal_inv_response_undetector_backward_%i",j);
    input_Align_Ideal_file.GetObject(name_h,Align_Ideal_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Ideal_inv_response_nofsr_forward_%i",j);
    input_Align_Ideal_file.GetObject(name_h,Align_Ideal_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Ideal_inv_response_nofsr_backward_%i",j);
    input_Align_Ideal_file.GetObject(name_h,Align_Ideal_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Ideal

    //Align_Startup
    sprintf(name_h,"Align_Startup_MC_meas_Forward_%i",j);
    input_Align_Startup_file.GetObject(name_h,Align_Startup_hMeasCos_M_Y_Forward[j]);

    sprintf(name_h,"Align_Startup_MC_meas_Backward_%i",j);
    input_Align_Startup_file.GetObject(name_h,Align_Startup_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Startup_inv_response_undetector_forward_%i",j);
    input_Align_Startup_file.GetObject(name_h,Align_Startup_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Startup_inv_response_undetector_backward_%i",j);
    input_Align_Startup_file.GetObject(name_h,Align_Startup_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Startup_inv_response_nofsr_forward_%i",j);
    input_Align_Startup_file.GetObject(name_h,Align_Startup_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Startup_inv_response_nofsr_backward_%i",j);
    input_Align_Startup_file.GetObject(name_h,Align_Startup_Inv_Response_NoFsr_Backward[j]);

    //eo Align_Startup



    sprintf(name_h,"Raw_Forward_%i",j);
    h_Raw_Forward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"Raw_Backward_%i",j);
    h_Raw_Backward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"Raw_AFB_%i",j);
    h_Raw_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"Raw_AFB_FineBin_%i",j);
    h_Raw_AFB_FineBin[j] = new TH1D(name_h,name_h,100, 40, 640);

    sprintf(name_h,"MC_True_AFB_%i",j);
    h_MC_True_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"MC_Raw_AFB_%i",j);
    h_MC_Raw_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_FSR_UP_%i",j);
    h_MC_Raw_AFB_FSR_UP[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_FSR_DOWN_%i",j);
    h_MC_Raw_AFB_FSR_DOWN[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_FSR_Diff_Up_%i",j);
    h_MC_Raw_AFB_FSR_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_FSR_Diff_Down_%i",j);
    h_MC_Raw_AFB_FSR_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"MC_Raw_AFB_ES_UP_%i",j);
    h_MC_Raw_AFB_ES_UP[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_ES_DOWN_%i",j);
    h_MC_Raw_AFB_ES_DOWN[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_ES_Diff_Up_%i",j);
    h_MC_Raw_AFB_ES_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_ES_Diff_Down_%i",j);
    h_MC_Raw_AFB_ES_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);



    sprintf(name_h,"MC_Raw_AFB_bkg_%i",j);
    h_MC_Raw_AFB_bkg[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_bkg_UP_%i",j);
    h_MC_Raw_AFB_bkg_UP[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_bkg_DOWN_%i",j);
    h_MC_Raw_AFB_bkg_DOWN[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_bkg_Diff_Up_%i",j);
    h_MC_Raw_AFB_bkg_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_bkg_Diff_Down_%i",j);
    h_MC_Raw_AFB_bkg_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    //sin2theta systematics
    sprintf(name_h,"MC_Raw_sin2412m2312_AFB_%i",j);
    h_MC_Raw_sin2412m2312_AFB[j] = new TH1D(name_h,name_h,nb_sin, xAxis_AFB);
    sprintf(name_h,"MC_Raw_sin2212m2312_AFB_%i",j);
    h_MC_Raw_sin2212m2312_AFB[j] = new TH1D(name_h,name_h,nb_sin, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_AFB_Diff_sin2412m2312_%i",j);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[j] = new TH1D(name_h,name_h,nb_sin, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_AFB_Diff_sin2212m2312_%i",j);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2212m2312[j] = new TH1D(name_h,name_h,nb_sin, xAxis_AFB);     
    sprintf(name_h,"MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312_%i",j);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[j] = new TH1D(name_h,name_h,nb_sin, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_AFB_Diff_sin2212m2312_%i",j);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2212m2312[j] = new TH1D(name_h,name_h,nb_sin, xAxis_AFB);     
    //end of sin2theta systematics

    //alignment systematics
    //Raw
    sprintf(name_h,"MC_Raw_Align_Bowing_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Bowing_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_Align_Elliptical_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Elliptical_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);    
    sprintf(name_h,"MC_Raw_Align_Radial_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Radial_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);    
    sprintf(name_h,"MC_Raw_Align_Sagitta_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Sagitta_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);    
    sprintf(name_h,"MC_Raw_Align_Skew_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Skew_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);  
    sprintf(name_h,"MC_Raw_Align_Telescope_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Telescope_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_Align_CurlV2Tf_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_CurlV2TF_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_Align_Twist_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Twist_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_Align_Zexpansion_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Zexpansion_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_Align_Startup_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Startup_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_MC_Raw_alignment_total_plus_%i",j);
    h_MC_Raw_alignment_total_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_MC_Raw_alignment_total_minus_%i",j);
    h_MC_Raw_alignment_total_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_MC_Bare_alignment_total_plus_%i",j);
    h_MC_Bare_alignment_total_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_MC_Bare_alignment_total_minus_%i",j);
    h_MC_Bare_alignment_total_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_MC_Born_alignment_total_plus_%i",j);
    h_MC_Born_alignment_total_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_MC_Born_alignment_total_minus_%i",j);
    h_MC_Born_alignment_total_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);


    sprintf(name_h,"h_Systematics_fsr_raw_plus_%i",j);
    h_Systematics_fsr_raw_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_fsr_raw_minus_%i",j);
    h_Systematics_fsr_raw_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);


    sprintf(name_h,"h_Systematics_es_raw_plus_%i",j);
    h_Systematics_es_raw_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_es_raw_minus_%i",j);
    h_Systematics_es_raw_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);


    sprintf(name_h,"h_Systematics_bkg_raw_plus_%i",j);
    h_Systematics_bkg_raw_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_bkg_raw_minus_%i",j);
    h_Systematics_bkg_raw_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Systematics_sin_raw_plus_%i",j);
    h_Systematics_sin_raw_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_sin_raw_minus_%i",j);
    h_Systematics_sin_raw_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    //
    sprintf(name_h,"h_Systematics_fsr_bare_plus_%i",j);
    h_Systematics_fsr_bare_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_fsr_bare_minus_%i",j);
    h_Systematics_fsr_bare_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Systematics_es_bare_plus_%i",j);
    h_Systematics_es_bare_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_es_bare_minus_%i",j);
    h_Systematics_es_bare_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);


    sprintf(name_h,"h_Systematics_bkg_bare_plus_%i",j);
    h_Systematics_bkg_bare_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_bkg_bare_minus_%i",j);
    h_Systematics_bkg_bare_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Systematics_sin_bare_plus_%i",j);
    h_Systematics_sin_bare_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_sin_bare_minus_%i",j);
    h_Systematics_sin_bare_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    //
    sprintf(name_h,"h_Systematics_fsr_Born_plus_%i",j);
    h_Systematics_fsr_Born_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_fsr_Born_minus_%i",j);
    h_Systematics_fsr_Born_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Systematics_es_Born_plus_%i",j);
    h_Systematics_es_Born_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_es_Born_minus_%i",j);
    h_Systematics_es_Born_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);



    sprintf(name_h,"h_Systematics_bkg_Born_plus_%i",j);
    h_Systematics_bkg_Born_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_bkg_Born_minus_%i",j);
    h_Systematics_bkg_Born_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Systematics_sin_Born_plus_%i",j);
    h_Systematics_sin_Born_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_sin_Born_minus_%i",j);
    h_Systematics_sin_Born_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);


    //Unfolded Bare Lepton
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Bowing_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Bowing_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Elliptical_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Elliptical_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Radial_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Radial_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Sagitta_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Sagitta_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Skew_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Skew_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Telescope_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Telescope_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_CurlV2TF_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_CurlV2TF_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Twist_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Twist_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Zexpansion_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Zexpansion_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    //Unfolded Born Level
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Bowing_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Bowing_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Elliptical_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Elliptical_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Radial_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Radial_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Sagitta_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Sagitta_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Skew_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Skew_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Telescope_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Telescope_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_CurlV2TF_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_CurlV2TF_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Twist_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Twist_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Zexpansion_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Zexpansion_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    //eo alignment systematics


    sprintf(name_h,"Unfolded_UnDet_Forward_%i",j);
    h_Unfolded_UnDet_Forward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"Unfolded_UnDet_Backward_%i",j);
    h_Unfolded_UnDet_Backward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"Unfolded_UnDet_AFB_%i",j);
    h_Unfolded_UnDet_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"MC_UnDet_AFB_%i",j);
    h_MC_UnDet_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_UnDet_AFB_FSR_UP%i",j);
    h_MC_UnDet_AFB_FSR_UP[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_UnDet_AFB_FSR_DOWN%i",j);
    h_MC_UnDet_AFB_FSR_DOWN[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_UnDet_AFB_FSR_Diff_Up%i",j);
    h_MC_UnDet_AFB_FSR_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_UnDet_AFB_FSR_Diff_Down%i",j);
    h_MC_UnDet_AFB_FSR_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"MC_UnDet_AFB_ES_UP%i",j);
    h_MC_UnDet_AFB_ES_UP[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_UnDet_AFB_ES_DOWN%i",j);
    h_MC_UnDet_AFB_ES_DOWN[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_UnDet_AFB_ES_Diff_Up%i",j);
    h_MC_UnDet_AFB_ES_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_UnDet_AFB_ES_Diff_Down%i",j);
    h_MC_UnDet_AFB_ES_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);


    sprintf(name_h,"MC_Unfolded_UnDet_AFB_bkg%i",j);
    h_MC_Unfolded_UnDet_AFB_bkg[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_AFB_bkg_UP%i",j);
    h_MC_Unfolded_UnDet_AFB_bkg_UP[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_AFB_bkg_DOWN%i",j);
    h_MC_Unfolded_UnDet_AFB_bkg_DOWN[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_AFB_bkg_Diff_Up%i",j);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_AFB_bkg_Diff_Down%i",j);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"Unfolded_NoFsr_Forward_%i",j);
    h_Unfolded_NoFsr_Forward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"Unfolded_NoFsr_Backward_%i",j);
    h_Unfolded_NoFsr_Backward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"Unfolded_NoFsr_AFB_%i",j);
    h_Unfolded_NoFsr_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"MC_NoFsr_AFB_%i",j);
    h_MC_NoFsr_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"Closure_Unfolded_UnDet_Forward_%i",j);
    h_Closure_Unfolded_UnDet_Forward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"Closure_Unfolded_UnDet_Backward_%i",j);
    h_Closure_Unfolded_UnDet_Backward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"Closure_Unfolded_UnDet_AFB_%i",j);
    h_Closure_Unfolded_UnDet_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"Closure_Unfolded_NoFsr_Forward_%i",j);
    h_Closure_Unfolded_NoFsr_Forward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"Closure_Unfolded_NoFsr_Backward_%i",j);
    h_Closure_Unfolded_NoFsr_Backward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Up_%i",j);
    h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Down_%i",j);
    h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up_%i",j);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_MC_Unfolded_NoFsr_AFB_ES_Diff_Down_%i",j);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);


    sprintf(name_h,"h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up_%i",j);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Down_%i",j);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up_%i",j);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_MC_Unfolded_UnDet_AFB_bkg_Diff_Down_%i",j);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);


    //pdf
    for (int k=0;k<n_ct;k++){
      sprintf(name_h,"MC_meas_Forward_PDF_%i_pdf_%i_set_%i",j,k,0);
      input_PDF_ct10_file.GetObject(name_h,hMeasCos_M_Y_Forward_PDF_ct10[j][k]);
      sprintf(name_h,"MC_meas_Backward_PDF_%i_pdf_%i_set_%i",j,k,0);
      input_PDF_ct10_file.GetObject(name_h,hMeasCos_M_Y_Backward_PDF_ct10[j][k]);
    }
    for (int k=0;k<n_mstw;k++){
      sprintf(name_h,"MC_meas_Forward_PDF_%i_pdf_%i_set_%i",j,k,2);
      input_PDF_mstw_file.GetObject(name_h,hMeasCos_M_Y_Forward_PDF_mstw[j][k]);
      sprintf(name_h,"MC_meas_Backward_PDF_%i_pdf_%i_set_%i",j,k,2);
      input_PDF_mstw_file.GetObject(name_h,hMeasCos_M_Y_Backward_PDF_mstw[j][k]);
    }
    for (int k=0;k<n_nnpdf;k++){
      sprintf(name_h,"MC_meas_Forward_PDF_%i_pdf_%i_set_%i",j,k,1);
      input_PDF_nnpdf_file.GetObject(name_h,hMeasCos_M_Y_Forward_PDF_nnpdf[j][k]);
      sprintf(name_h,"MC_meas_Backward_PDF_%i_pdf_%i_set_%i",j,k,1);
      input_PDF_nnpdf_file.GetObject(name_h,hMeasCos_M_Y_Backward_PDF_nnpdf[j][k]);
    }
    for (int k=0;k<ct10as_index;k++){
      sprintf(name_h,"MC_meas_Forward_PDF_%i_pdf_%i_set_%i",j,k,3);
      input_PDF_alpha_s_file.GetObject(name_h,hMeasCos_M_Y_Forward_PDF_alpha_s[j][k]);
      sprintf(name_h,"MC_meas_Backward_PDF_%i_pdf_%i_set_%i",j,k,3);
      input_PDF_alpha_s_file.GetObject(name_h,hMeasCos_M_Y_Backward_PDF_alpha_s[j][k]);
    }

    sprintf(name_h,"inv_response_undetector_forward_PDF_%i_set_%i",j,pdf_set);
    input_PDF_ct10_file.GetObject(name_h,Inv_Response_UnDetector_Forward_PDF_ct10[j]);
    sprintf(name_h,"inv_response_undetector_backward_PDF_%i_set_%i",j,pdf_set);
    input_PDF_ct10_file.GetObject(name_h,Inv_Response_UnDetector_Backward_PDF_ct10[j]);
    
    sprintf(name_h,"inv_response_nofsr_forward_PDF_%i_set_%i",j,pdf_set);
    input_PDF_ct10_file.GetObject(name_h,Inv_Response_NoFsr_Forward_PDF_ct10[j]);
    sprintf(name_h,"inv_response_nofsr_backward_PDF_%i_set_%i",j,pdf_set);
    input_PDF_ct10_file.GetObject(name_h,Inv_Response_NoFsr_Backward_PDF_ct10[j]);

    sprintf(name_h,"h_DeltaXmaxPlus_ct10_%i",j);
    h_DeltaXmaxPlus_ct10[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_DeltaXmaxMinus_ct10_%i",j);
    h_DeltaXmaxMinus_ct10[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_DeltaXmaxPlus_undet_ct10_%i",j);
    h_DeltaXmaxPlus_undet_ct10[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_DeltaXmaxMinus_undet_ct10_%i",j);
    h_DeltaXmaxMinus_undet_ct10[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_DeltaXmaxPlus_mstw_%i",j);
    h_DeltaXmaxPlus_mstw[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_DeltaXmaxMinus_mstw_%i",j);
    h_DeltaXmaxMinus_mstw[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_sigma_%i",j);
    h_sigma[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Delta_AFB_alphas_PLUS_%i",j);
    h_Delta_AFB_alphas_PLUS[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Delta_AFB_alphas_MINUS_%i",j);
    h_Delta_AFB_alphas_MINUS[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_DeltaX_CT10_ALPHAS_PLUS_%i",j);
    h_DeltaX_CT10_ALPHAS_PLUS[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_DeltaX_CT10_ALPHAS_MINUS_%i",j);
    h_DeltaX_CT10_ALPHAS_MINUS[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_envelope_sigma_%i",j);
    h_envelope_sigma[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_envelope_sigma_plus%i",j);
    h_envelope_sigma_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_envelope_sigma_minus%i",j);
    h_envelope_sigma_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_total_plus_%i",j);
    h_total_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_total_minus_%i",j);
    h_total_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_total_plus_undet%i",j);
    h_total_plus_undet[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_total_minus_undet%i",j);
    h_total_minus_undet[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_total_plus_nofsr%i",j);
    h_total_plus_nofsr[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_total_minus_nofsr%i",j);
    h_total_minus_nofsr[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Ideal_Geo_AFB_%i",j);
    h_Ideal_Geo_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);    

    sprintf(name_h,"h_Ideal_Geo_AFB_FineBin_%i",j);
    h_Ideal_Geo_AFB_FineBin[j] = new TH1D(name_h,name_h,100,40,640);  
    //eo pdf
  } //eo j nb_Y


//  cout<<"nire"<<endl;

  double MC_True_AFB[nb];


  double Raw_AFB[nb];
  double Raw_error[nb];
  double Raw_AFB_FineBin[nb];
  double Raw_error_FineBin[nb];
  double MC_Raw_AFB[nb];
  double MC_Raw_AFB_FSR_UP[nb];
  double MC_Raw_AFB_FSR_DOWN[nb];
  double MC_Raw_AFB_FSR_Diff_Up[nb];
  double MC_Raw_AFB_FSR_Diff_Down[nb];
  double MC_Raw_AFB_bkg[nb];
  double MC_Raw_AFB_bkg_UP[nb];
  double MC_Raw_AFB_bkg_DOWN[nb];
  double MC_Raw_AFB_bkg_Diff_Up[nb];
  double MC_Raw_AFB_bkg_Diff_Down[nb];

  double MC_Raw_AFB_ES_UP[nb];
  double MC_Raw_AFB_ES_DOWN[nb];
  double MC_Raw_AFB_ES_Diff_Up[nb];
  double MC_Raw_AFB_ES_Diff_Down[nb];


  double MC_Raw_sin2312_AFB[nb_sin];
  double MC_Raw_sin2412_AFB[nb_sin];
  double MC_Raw_sin2212_AFB[nb_sin];
  double MC_Unfolded_UnDet_sin2312_AFB[nb_sin];
  double MC_Unfolded_UnDet_sin2412_AFB[nb_sin];
  double MC_Unfolded_UnDet_sin2212_AFB[nb_sin];
  double MC_Unfolded_UnDet_sin2312_Forward[nb_Y][nb_sin];
  double MC_Unfolded_UnDet_sin2312_Backward[nb_Y][nb_sin];
  double MC_Unfolded_UnDet_sin2412_Forward[nb_Y][nb_sin];
  double MC_Unfolded_UnDet_sin2412_Backward[nb_Y][nb_sin];
  double MC_Unfolded_UnDet_sin2212_Forward[nb_Y][nb_sin];
  double MC_Unfolded_UnDet_sin2212_Backward[nb_Y][nb_sin];
  double MC_Unfolded_NoFsr_sin2312_AFB[nb_sin];
  double MC_Unfolded_NoFsr_sin2412_AFB[nb_sin];
  double MC_Unfolded_NoFsr_sin2212_AFB[nb_sin];
  double MC_Unfolded_NoFsr_sin2312_Forward[nb_Y][nb_sin];
  double MC_Unfolded_NoFsr_sin2312_Backward[nb_Y][nb_sin];
  double MC_Unfolded_NoFsr_sin2412_Forward[nb_Y][nb_sin];
  double MC_Unfolded_NoFsr_sin2412_Backward[nb_Y][nb_sin];
  double MC_Unfolded_NoFsr_sin2212_Forward[nb_Y][nb_sin];
  double MC_Unfolded_NoFsr_sin2212_Backward[nb_Y][nb_sin];

  //alignment
  double MC_Raw_Align_Ideal_AFB[nb];   
  double MC_Raw_Align_Ideal_AFB_FineBin[nb];   
  double MC_Raw_Align_Startup_AFB[nb];   
  double MC_Raw_Align_Bowing_AFB[nb];   
  double MC_Raw_Align_Elliptical_AFB[nb];   
  double MC_Raw_Align_Radial_AFB[nb];   
  double MC_Raw_Align_Sagitta_AFB[nb];   
  double MC_Raw_Align_Skew_AFB[nb];   
  double MC_Raw_Align_Telescope_AFB[nb];   
  double MC_Raw_Align_CurlV2TF_AFB[nb];   
  double MC_Raw_Align_Twist_AFB[nb];   
  double MC_Raw_Align_Zexpansion_AFB[nb];   
 
  double MC_UnDet_Align_Ideal_AFB[nb];   
  double MC_UnDet_Align_Startup_AFB[nb];   
  double MC_UnDet_Align_Bowing_AFB[nb];   
  double MC_UnDet_Align_Elliptical_AFB[nb];   
  double MC_UnDet_Align_Radial_AFB[nb];   
  double MC_UnDet_Align_Sagitta_AFB[nb];   
  double MC_UnDet_Align_Skew_AFB[nb];   
  double MC_UnDet_Align_Telescope_AFB[nb];   
  double MC_UnDet_Align_CurlV2TF_AFB[nb];   
  double MC_UnDet_Align_Twist_AFB[nb];   
  double MC_UnDet_Align_Zexpansion_AFB[nb];  

  double MC_UnDet_Align_Ideal_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Startup_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Bowing_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Elliptical_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Radial_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Sagitta_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Skew_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Telescope_Forward[nb_Y][nb];   
  double MC_UnDet_Align_CurlV2TF_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Twist_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Zexpansion_Forward[nb_Y][nb];  

  double MC_UnDet_Align_Ideal_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Startup_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Bowing_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Elliptical_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Radial_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Sagitta_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Skew_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Telescope_Backward[nb_Y][nb];   
  double MC_UnDet_Align_CurlV2TF_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Twist_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Zexpansion_Backward[nb_Y][nb]; 

  double MC_NoFsr_Align_Ideal_AFB[nb];   
  double MC_NoFsr_Align_Startup_AFB[nb];   
  double MC_NoFsr_Align_Bowing_AFB[nb];    
  double MC_NoFsr_Align_Elliptical_AFB[nb];   
  double MC_NoFsr_Align_Radial_AFB[nb];   
  double MC_NoFsr_Align_Sagitta_AFB[nb];   
  double MC_NoFsr_Align_Skew_AFB[nb];   
  double MC_NoFsr_Align_Telescope_AFB[nb];   
  double MC_NoFsr_Align_CurlV2TF_AFB[nb];   
  double MC_NoFsr_Align_Twist_AFB[nb];   
  double MC_NoFsr_Align_Zexpansion_AFB[nb];  

  double MC_NoFsr_Align_Ideal_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Startup_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Bowing_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Elliptical_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Radial_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Sagitta_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Skew_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Telescope_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_CurlV2TF_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Twist_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Zexpansion_Forward[nb_Y][nb];  

  double MC_NoFsr_Align_Ideal_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Startup_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Bowing_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Elliptical_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Radial_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Sagitta_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Skew_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Telescope_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_CurlV2TF_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Twist_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Zexpansion_Backward[nb_Y][nb]; 

  //eo alignment


  double Unfolded_UnDet_Forward[nb_Y][nb];
  double Unfolded_UnDet_Backward[nb_Y][nb];
  double Unfolded_UnDet_AFB[nb];
  double first_sum[nb];
  double second_sum[nb];
  double Unfolded_UnDet_error[nb];
  double MC_UnDet_AFB[nb];
  double MC_UnDet_AFB_FSR_UP[nb];
  double MC_UnDet_AFB_FSR_DOWN[nb];
  double MC_UnDet_AFB_FSR_Diff_Up[nb];
  double MC_UnDet_AFB_FSR_Diff_Down[nb];

  double MC_UnDet_AFB_ES_UP[nb];
  double MC_UnDet_AFB_ES_DOWN[nb];
  double MC_UnDet_AFB_ES_Diff_Up[nb];
  double MC_UnDet_AFB_ES_Diff_Down[nb];

  double MC_UnDet_AFB_bkg[nb];
  double MC_UnDet_AFB_bkg_UP[nb];
  double MC_UnDet_AFB_bkg_DOWN[nb];
  double MC_UnDet_AFB_bkg_Diff_Up[nb];
  double MC_UnDet_AFB_bkg_Diff_Down[nb];
  double closure_first_sum[nb];
  double closure_second_sum[nb];
  double closure_Unfolded_UnDet_error[nb];
  double Unfolded_NoFsr_Forward[nb_Y][nb];
  double Unfolded_NoFsr_Backward[nb_Y][nb];
  double Closure_Unfolded_NoFsr_Forward[nb_Y][nb];
  double Closure_Unfolded_NoFsr_Backward[nb_Y][nb];
  double Closure_Unfolded_NoFsr_AFB[nb];
  double Closure_Unfolded_UnDet_Forward[nb_Y][nb];
  double Closure_Unfolded_UnDet_Backward[nb_Y][nb];
  double Closure_Unfolded_UnDet_AFB[nb];

  double MC_Unfolded_UnDet_Forward_FSR_Up[nb_Y][nb];
  double MC_Unfolded_UnDet_Forward_FSR_Down[nb_Y][nb];
  double MC_Unfolded_UnDet_Backward_FSR_Up[nb_Y][nb];
  double MC_Unfolded_UnDet_Backward_FSR_Down[nb_Y][nb];


  double MC_Unfolded_UnDet_Forward_ES_Up[nb_Y][nb];
  double MC_Unfolded_UnDet_Forward_ES_Down[nb_Y][nb];
  double MC_Unfolded_UnDet_Backward_ES_Up[nb_Y][nb];
  double MC_Unfolded_UnDet_Backward_ES_Down[nb_Y][nb];


  double MC_Unfolded_NoFsr_Forward_FSR_Up[nb_Y][nb];
  double MC_Unfolded_NoFsr_Forward_FSR_Down[nb_Y][nb];
  double MC_Unfolded_NoFsr_Backward_FSR_Up[nb_Y][nb];
  double MC_Unfolded_NoFsr_Backward_FSR_Down[nb_Y][nb];
  double MC_Unfolded_NoFsr_AFB_FSR_Up[nb];
  double MC_Unfolded_NoFsr_AFB_FSR_Down[nb];

  double MC_Unfolded_NoFsr_Forward_ES_Up[nb_Y][nb];
  double MC_Unfolded_NoFsr_Forward_ES_Down[nb_Y][nb];
  double MC_Unfolded_NoFsr_Backward_ES_Up[nb_Y][nb];
  double MC_Unfolded_NoFsr_Backward_ES_Down[nb_Y][nb];
  double MC_Unfolded_NoFsr_AFB_ES_Up[nb];
  double MC_Unfolded_NoFsr_AFB_ES_Down[nb];


  double MC_Unfolded_NoFsr_Forward_bkg[nb_Y][nb];
  double MC_Unfolded_NoFsr_Backward_bkg[nb_Y][nb];
  double MC_Unfolded_NoFsr_AFB_bkg[nb];

  double MC_Unfolded_NoFsr_Forward_bkg_Up[nb_Y][nb];
  double MC_Unfolded_NoFsr_Forward_bkg_Down[nb_Y][nb];
  double MC_Unfolded_NoFsr_Backward_bkg_Up[nb_Y][nb];
  double MC_Unfolded_NoFsr_Backward_bkg_Down[nb_Y][nb];
  double MC_Unfolded_NoFsr_AFB_bkg_Up[nb];
  double MC_Unfolded_NoFsr_AFB_bkg_Down[nb];

  double MC_Unfolded_UnDet_Forward_bkg[nb_Y][nb];
  double MC_Unfolded_UnDet_Backward_bkg[nb_Y][nb];

  double MC_Unfolded_UnDet_Forward_bkg_Up[nb_Y][nb];
  double MC_Unfolded_UnDet_Forward_bkg_Down[nb_Y][nb];
  double MC_Unfolded_UnDet_Backward_bkg_Up[nb_Y][nb];
  double MC_Unfolded_UnDet_Backward_bkg_Down[nb_Y][nb];

  double Unfolded_NoFsr_AFB[nb_Y];
  double first_sum_fsr[nb];
  double second_sum_fsr[nb];
  double Unfolded_NoFsr_error[nb];
  double MC_NoFsr_AFB[nb];
  double error_closure_forward[nb];
  double error_closure_backward[nb];
  double error_forward[nb];
  double error_backward[nb];

  double total_plus[nb_Y][nb];
  double total_minus[nb_Y][nb];

  double total_plus_fsr[nb_Y][nb];
  double total_minus_fsr[nb_Y][nb];

  double total_plus_es[nb_Y][nb];
  double total_minus_es[nb_Y][nb];


  double total_plus_bkg[nb_Y][nb];
  double total_minus_bkg[nb_Y][nb];

  double total_plus_sin[nb_Y][nb];
  double total_minus_sin[nb_Y][nb];

  double total_plus_undet[nb_Y][nb];
  double total_minus_undet[nb_Y][nb];

  double total_plus_undet_fsr[nb_Y][nb];
  double total_minus_undet_fsr[nb_Y][nb];

  double total_plus_undet_es[nb_Y][nb];
  double total_minus_undet_es[nb_Y][nb];

  double total_plus_undet_bkg[nb_Y][nb];
  double total_minus_undet_bkg[nb_Y][nb];

  double total_plus_undet_sin[nb_Y][nb];
  double total_minus_undet_sin[nb_Y][nb];

  double total_plus_nofsr[nb_Y][nb];
  double total_minus_nofsr[nb_Y][nb];

  double total_plus_nofsr_fsr[nb_Y][nb];
  double total_minus_nofsr_fsr[nb_Y][nb];

  double total_plus_nofsr_es[nb_Y][nb];
  double total_minus_nofsr_es[nb_Y][nb];


  double total_plus_nofsr_bkg[nb_Y][nb];
  double total_minus_nofsr_bkg[nb_Y][nb];

  double total_plus_nofsr_sin[nb_Y][nb];
  double total_minus_nofsr_sin[nb_Y][nb];

  double alignment_total_plus[nb_Y][nb];
  double alignment_total_minus[nb_Y][nb];

  double alignment_total_plus_undet[nb_Y][nb];
  double alignment_total_minus_undet[nb_Y][nb];

  double alignment_total_plus_nofsr[nb_Y][nb];
  double alignment_total_minus_nofsr[nb_Y][nb];

  //unfolding pdf
  double MC_Unfolded_UnDet_Forward_PDF_ct10[nb_Y][nb][n_ct];
  double MC_Unfolded_UnDet_Backward_PDF_ct10[nb_Y][nb][n_ct];
  double MC_Unfolded_UnDet_AFB_PDF_ct10[nb][n_ct];
  //

  double dilution[nb_Y][nb];

  for (int k=0;k<nb_Y;k++){

      for (int i=0;i<17;i++){
	//relval finebins
	Raw_AFB_FineBin[i] = 0;
	Raw_error_FineBin[i] = 0;
	MC_Raw_Align_Ideal_AFB_FineBin[i] = 0;

	Raw_AFB_FineBin[i] = AFB(hDataMeasCos_M_Y_Forward_FineBin[k]->GetBinContent(i+1),hDataMeasCos_M_Y_Backward_FineBin[k]->GetBinContent(i+1));
	Raw_error_FineBin[i] = RAWAFBERROR(Raw_AFB_FineBin[i],hDataMeasCos_M_Y_Forward_FineBin[k]->GetBinContent(i+1),hDataMeasCos_M_Y_Backward_FineBin[k]->GetBinContent(i+1));
	
	h_Raw_AFB_FineBin[k]->SetBinContent(i+1,Raw_AFB_FineBin[i]);
	h_Raw_AFB_FineBin[k]->SetBinError(i+1,Raw_error_FineBin[i]);


	MC_Raw_Align_Ideal_AFB_FineBin[i] = AFB(Align_Ideal_hMeasCos_M_Y_Forward_FineBin[k]->GetBinContent(i+1),Align_Ideal_hMeasCos_M_Y_Backward_FineBin[k]->GetBinContent(i+1));
	h_Ideal_Geo_AFB_FineBin[k]->SetBinContent(i+1,MC_Raw_Align_Ideal_AFB_FineBin[i]);
	h_Ideal_Geo_AFB_FineBin[k]->SetBinError(i+1,RAWAFBERROR(MC_Raw_Align_Ideal_AFB_FineBin[i],Align_Ideal_hMeasCos_M_Y_Forward_FineBin[k]->GetBinContent(i+1),Align_Ideal_hMeasCos_M_Y_Backward_FineBin[k]->GetBinContent(i+1)));
	//
      }


    for (int i=0;i<nb;i++){
      Unfolded_UnDet_Forward[k][i] = 0;
      Unfolded_UnDet_Backward[k][i] = 0;
      Unfolded_NoFsr_Forward[k][i] = 0;
      Unfolded_NoFsr_Backward[k][i] = 0;
      Closure_Unfolded_NoFsr_Forward[k][i] = 0;
      Closure_Unfolded_NoFsr_Backward[k][i] = 0;
      Closure_Unfolded_NoFsr_AFB[i] = 0;
      Closure_Unfolded_UnDet_Forward[k][i] = 0;
      Closure_Unfolded_UnDet_Backward[k][i] = 0;
      Closure_Unfolded_UnDet_AFB[i] = 0;

      MC_Unfolded_UnDet_Forward_FSR_Up[k][i] = 0;
      MC_Unfolded_UnDet_Forward_FSR_Down[k][i] = 0;
      MC_Unfolded_UnDet_Backward_FSR_Up[k][i] = 0;
      MC_Unfolded_UnDet_Backward_FSR_Down[k][i] = 0;

      MC_Unfolded_UnDet_Forward_ES_Up[k][i] = 0;
      MC_Unfolded_UnDet_Forward_ES_Down[k][i] = 0;
      MC_Unfolded_UnDet_Backward_ES_Up[k][i] = 0;
      MC_Unfolded_UnDet_Backward_ES_Down[k][i] = 0;


      MC_Unfolded_NoFsr_Forward_FSR_Up[k][i] = 0;
      MC_Unfolded_NoFsr_Forward_FSR_Down[k][i] = 0;
      MC_Unfolded_NoFsr_Backward_FSR_Up[k][i] = 0;
      MC_Unfolded_NoFsr_Backward_FSR_Down[k][i] = 0;
      MC_Unfolded_NoFsr_AFB_FSR_Up[i] = 0;
      MC_Unfolded_NoFsr_AFB_FSR_Down[i] = 0;	

      MC_Unfolded_NoFsr_Forward_ES_Up[k][i] = 0;
      MC_Unfolded_NoFsr_Forward_ES_Down[k][i] = 0;
      MC_Unfolded_NoFsr_Backward_ES_Up[k][i] = 0;
      MC_Unfolded_NoFsr_Backward_ES_Down[k][i] = 0;
      MC_Unfolded_NoFsr_AFB_ES_Up[i] = 0;
      MC_Unfolded_NoFsr_AFB_ES_Down[i] = 0;


      MC_Unfolded_NoFsr_Forward_bkg[k][i] = 0;
      MC_Unfolded_NoFsr_Backward_bkg[k][i] = 0;
      MC_Unfolded_NoFsr_AFB_bkg[i] = 0;

      MC_Unfolded_NoFsr_Forward_bkg_Up[k][i] = 0;
      MC_Unfolded_NoFsr_Forward_bkg_Down[k][i] = 0;
      MC_Unfolded_NoFsr_Backward_bkg_Up[k][i] = 0;
      MC_Unfolded_NoFsr_Backward_bkg_Down[k][i] = 0;
      MC_Unfolded_NoFsr_AFB_bkg_Up[i] = 0;
      MC_Unfolded_NoFsr_AFB_bkg_Down[i] = 0;	

      MC_Unfolded_UnDet_Forward_bkg[k][i] = 0;
      MC_Unfolded_UnDet_Backward_bkg[k][i] = 0;

      MC_Unfolded_UnDet_Forward_bkg_Up[k][i] = 0;
      MC_Unfolded_UnDet_Forward_bkg_Down[k][i] = 0;
      MC_Unfolded_UnDet_Backward_bkg_Up[k][i] = 0;
      MC_Unfolded_UnDet_Backward_bkg_Down[k][i] = 0;

      dilution[k][i] = 0;

      first_sum[i] = 0;
      second_sum[i] = 0;
      Unfolded_UnDet_error[i] = 0;
      closure_first_sum[i] = 0;
      closure_second_sum[i] = 0;
      closure_Unfolded_UnDet_error[i] = 0;
      first_sum_fsr[i] = 0;
      second_sum_fsr[i] = 0;
      Unfolded_NoFsr_error[i] = 0;
      Raw_AFB[i] = 0;
      Raw_error[i] = 0;

      MC_True_AFB[i] = 0;


      MC_Raw_AFB[i] = 0;
      MC_Raw_AFB_FSR_UP[i] = 0;
      MC_Raw_AFB_FSR_DOWN[i] = 0;
      MC_Raw_AFB_FSR_Diff_Up[i] = 0;
      MC_Raw_AFB_FSR_Diff_Down[i] = 0;

      MC_Raw_AFB_ES_UP[i] = 0;
      MC_Raw_AFB_ES_DOWN[i] = 0;
      MC_Raw_AFB_ES_Diff_Up[i] = 0;
      MC_Raw_AFB_ES_Diff_Down[i] = 0;

      MC_Raw_AFB_bkg[i] = 0;
      MC_Raw_AFB_bkg_UP[i] = 0;
      MC_Raw_AFB_bkg_DOWN[i] = 0;
      MC_Raw_AFB_bkg_Diff_Up[i] = 0;
      MC_Raw_AFB_bkg_Diff_Down[i] = 0;
      MC_UnDet_AFB[i] = 0;
      MC_UnDet_AFB_FSR_UP[i] = 0;
      MC_UnDet_AFB_FSR_DOWN[i] = 0;
      MC_UnDet_AFB_FSR_Diff_Up[i] = 0;
      MC_UnDet_AFB_FSR_Diff_Down[i] = 0;

      MC_UnDet_AFB_ES_UP[i] = 0;
      MC_UnDet_AFB_ES_DOWN[i] = 0;
      MC_UnDet_AFB_ES_Diff_Up[i] = 0;
      MC_UnDet_AFB_ES_Diff_Down[i] = 0;


      MC_UnDet_AFB_bkg[i] = 0;
      MC_UnDet_AFB_bkg_UP[i] = 0;
      MC_UnDet_AFB_bkg_DOWN[i] = 0;
      MC_UnDet_AFB_bkg_Diff_Up[i] = 0;
      MC_UnDet_AFB_bkg_Diff_Down[i] = 0;      
      MC_NoFsr_AFB[i] = 0;
      error_closure_forward[i] = 0;
      error_closure_backward[i] = 0;
      error_forward[i] = 0;
      error_backward[i] = 0;	
      //pdf
      DeltaXmaxPlus[i][k] = 0;
      DeltaXmaxMinus[i][k] = 0;
      sigma[i][k] = 0;

      DeltaXmaxPlus_undet[i][k] = 0;
      DeltaXmaxMinus_undet[i][k] = 0;
      sigma_undet[i][k] = 0;

      for (int pdfindex = 0; pdfindex<n_ct;pdfindex++){
	MC_Unfolded_UnDet_Forward_PDF_ct10[k][i][pdfindex] = 0;
	MC_Unfolded_UnDet_Backward_PDF_ct10[k][i][pdfindex] = 0;
	MC_Unfolded_UnDet_AFB_PDF_ct10[i][pdfindex] = 0;
      }
      //



      total_plus[k][i] = 0;
      total_minus[k][i] = 0;

      total_plus_fsr[k][i] = 0;
      total_minus_fsr[k][i] = 0;

      total_plus_es[k][i] = 0;
      total_minus_es[k][i] = 0;

      total_plus_bkg[k][i] = 0;
      total_minus_bkg[k][i] = 0;

      total_plus_sin[k][i] = 0;
      total_minus_sin[k][i] = 0;

      total_plus_undet[k][i] = 0;
      total_minus_undet[k][i] = 0;

      total_plus_undet_fsr[k][i] = 0;
      total_minus_undet_fsr[k][i] = 0;

      total_plus_undet_es[k][i] = 0;
      total_minus_undet_es[k][i] = 0;


      total_plus_undet_bkg[k][i] = 0;
      total_minus_undet_bkg[k][i] = 0;

      total_plus_undet_sin[k][i] = 0;
      total_minus_undet_sin[k][i] = 0;

      total_plus_nofsr[k][i] = 0;
      total_minus_nofsr[k][i] = 0;

      total_plus_nofsr_fsr[k][i] = 0;
      total_minus_nofsr_fsr[k][i] = 0;

      total_plus_nofsr_es[k][i] = 0;
      total_minus_nofsr_es[k][i] = 0;


      total_plus_nofsr_bkg[k][i] = 0;
      total_minus_nofsr_bkg[k][i] = 0;

      total_plus_nofsr_sin[k][i] = 0;
      total_minus_nofsr_sin[k][i] = 0;

      alignment_total_plus[k][i] = 0;
      alignment_total_minus[k][i] = 0;
      alignment_total_plus_undet[k][i] = 0;
      alignment_total_minus_undet[k][i] = 0;
      alignment_total_plus_nofsr[k][i] = 0;
      alignment_total_minus_nofsr[k][i] = 0;

      for (int j=0;j<nb;j++){
	//note the j, i order!!!!
	Unfolded_UnDet_Forward[k][i] += Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*hDataMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	Unfolded_UnDet_Backward[k][i] += Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*hDataMeasCos_M_Y_Backward[k]->GetBinContent(j+1);

	Unfolded_NoFsr_Forward[k][i] += Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*hDataMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	Unfolded_NoFsr_Backward[k][i] += Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*hDataMeasCos_M_Y_Backward[k]->GetBinContent(j+1);

	Closure_Unfolded_UnDet_Forward[k][i] += Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	Closure_Unfolded_UnDet_Backward[k][i] += Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);

	Closure_Unfolded_NoFsr_Forward[k][i] += Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	Closure_Unfolded_NoFsr_Backward[k][i] += Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	/////
	MC_Unfolded_UnDet_Forward_FSR_Up[k][i] += Inv_Response_UnDet_Forward_FSR_UP[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_FSR_UP[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_Forward_FSR_Down[k][i] += Inv_Response_UnDet_Forward_FSR_DOWN[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_FSR_DOWN[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_Backward_FSR_Up[k][i] += Inv_Response_UnDet_Backward_FSR_UP[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_FSR_UP[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_Backward_FSR_Down[k][i] += Inv_Response_UnDet_Backward_FSR_DOWN[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_FSR_DOWN[k]->GetBinContent(j+1);

        MC_Unfolded_UnDet_Forward_ES_Up[k][i] += Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_ES_UP[k]->GetBinContent(j+1);
        MC_Unfolded_UnDet_Forward_ES_Down[k][i] += Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_ES_DOWN[k]->GetBinContent(j+1);
        MC_Unfolded_UnDet_Backward_ES_Up[k][i] += Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_ES_UP[k]->GetBinContent(j+1);
        MC_Unfolded_UnDet_Backward_ES_Down[k][i] += Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_ES_DOWN[k]->GetBinContent(j+1);
	/////
	MC_Unfolded_NoFsr_Forward_FSR_Up[k][i] += Inv_Response_NoFsr_Forward_FSR_UP[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_FSR_UP[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_Forward_FSR_Down[k][i] += Inv_Response_NoFsr_Forward_FSR_DOWN[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_FSR_DOWN[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_Backward_FSR_Up[k][i] += Inv_Response_NoFsr_Backward_FSR_UP[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_FSR_UP[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_Backward_FSR_Down[k][i] += Inv_Response_NoFsr_Backward_FSR_DOWN[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_FSR_DOWN[k]->GetBinContent(j+1);

        MC_Unfolded_NoFsr_Forward_ES_Up[k][i] += Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_ES_UP[k]->GetBinContent(j+1);
        MC_Unfolded_NoFsr_Forward_ES_Down[k][i] += Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_ES_DOWN[k]->GetBinContent(j+1);
        MC_Unfolded_NoFsr_Backward_ES_Up[k][i] += Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_ES_UP[k]->GetBinContent(j+1);
        MC_Unfolded_NoFsr_Backward_ES_Down[k][i] += Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_ES_DOWN[k]->GetBinContent(j+1);



	MC_Unfolded_UnDet_Forward_bkg[k][i] += Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_bkg[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_Backward_bkg[k][i] += Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_bkg[k]->GetBinContent(j+1);

	MC_Unfolded_NoFsr_Forward_bkg[k][i] += Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_bkg[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_Backward_bkg[k][i] += Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_bkg[k]->GetBinContent(j+1);


	MC_Unfolded_UnDet_Forward_bkg_Up[k][i] += Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_bkg_UP[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_Forward_bkg_Down[k][i] += Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_bkg_DOWN[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_Backward_bkg_Up[k][i] += Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_bkg_UP[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_Backward_bkg_Down[k][i] += Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_bkg_DOWN[k]->GetBinContent(j+1);

	MC_Unfolded_NoFsr_Forward_bkg_Up[k][i] += Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_bkg_UP[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_Forward_bkg_Down[k][i] += Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_bkg_DOWN[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_Backward_bkg_Up[k][i] += Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_bkg_UP[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_Backward_bkg_Down[k][i] += Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_bkg_DOWN[k]->GetBinContent(j+1);

      }
      Raw_AFB[i] = AFB(hDataMeasCos_M_Y_Forward[k]->GetBinContent(i+1),hDataMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      Raw_error[i] = RAWAFBERROR(Raw_AFB[i],hDataMeasCos_M_Y_Forward[k]->GetBinContent(i+1),hDataMeasCos_M_Y_Backward[k]->GetBinContent(i+1));

      h_Raw_AFB[k]->SetBinContent(i+1,Raw_AFB[i]);
      h_Raw_AFB[k]->SetBinError(i+1,Raw_error[i]);

     
 
      MC_Raw_AFB[i] = AFB(hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      h_MC_Raw_AFB[k]->SetBinContent(i+1,MC_Raw_AFB[i]);

      h_MC_Raw_AFB[k]->SetBinError(i+1,RAWAFBERROR(MC_Raw_AFB[i],hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward[k]->GetBinContent(i+1)));



      MC_Raw_AFB_FSR_UP[i] = AFB(hMeasCos_M_Y_Forward_FSR_UP[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward_FSR_UP[k]->GetBinContent(i+1));
      h_MC_Raw_AFB_FSR_UP[k]->SetBinContent(i+1,MC_Raw_AFB_FSR_UP[i]);
      MC_Raw_AFB_FSR_DOWN[i] = AFB(hMeasCos_M_Y_Forward_FSR_DOWN[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward_FSR_DOWN[k]->GetBinContent(i+1));
      h_MC_Raw_AFB_FSR_DOWN[k]->SetBinContent(i+1,MC_Raw_AFB_FSR_DOWN[i]);
      float diff1 = MC_Raw_AFB_FSR_UP[i]-MC_Raw_AFB[i];
      float diff2 = MC_Raw_AFB_FSR_DOWN[i]-MC_Raw_AFB[i];
      if (diff1 >0. ? total_plus[k][i] += diff1*diff1 : total_minus[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus[k][i] += diff2*diff2 : total_minus[k][i] += diff2*diff2);

      if (diff1 >0. ? total_plus_fsr[k][i] += diff1*diff1 : total_minus_fsr[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus_fsr[k][i] += diff2*diff2 : total_minus_fsr[k][i] += diff2*diff2);      
      if (total_plus_fsr[k][i] != 0){
	h_Systematics_fsr_raw_plus[k]->SetBinContent(i+1,sqrt(total_plus_fsr[k][i]));
	h_Systematics_fsr_raw_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_fsr[k][i] != 0){
	h_Systematics_fsr_raw_minus[k]->SetBinContent(i+1,-sqrt(total_minus_fsr[k][i]));
	h_Systematics_fsr_raw_minus[k]->SetBinError(i+1,0.000000001);
      }

      MC_Raw_AFB_FSR_Diff_Up[i] = diff1;//TMath::Max(diff1,diff2);
      MC_Raw_AFB_FSR_Diff_Down[i] = diff2;//TMath::Min(diff1,diff2);
      h_MC_Raw_AFB_FSR_Diff_Up[k]->SetBinContent(i+1,MC_Raw_AFB_FSR_Diff_Up[i]);
      h_MC_Raw_AFB_FSR_Diff_Down[k]->SetBinContent(i+1,MC_Raw_AFB_FSR_Diff_Down[i]);


      diff1 = 0;
      diff2 = 0;		
      MC_Raw_AFB_ES_UP[i] = AFB(hMeasCos_M_Y_Forward_ES_UP[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward_ES_UP[k]->GetBinContent(i+1));
      h_MC_Raw_AFB_ES_UP[k]->SetBinContent(i+1,MC_Raw_AFB_ES_UP[i]);
      MC_Raw_AFB_ES_DOWN[i] = AFB(hMeasCos_M_Y_Forward_ES_DOWN[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward_ES_DOWN[k]->GetBinContent(i+1));
      h_MC_Raw_AFB_ES_DOWN[k]->SetBinContent(i+1,MC_Raw_AFB_ES_DOWN[i]);
      diff1 = MC_Raw_AFB_ES_UP[i]-MC_Raw_AFB[i];
      diff2 = MC_Raw_AFB_ES_DOWN[i]-MC_Raw_AFB[i];
/*
      if (i == nb-1 && fabs(diff1) > fabs(MC_Raw_AFB_ES_UP[i-1]-MC_Raw_AFB[i-1])) diff1 = MC_Raw_AFB_ES_UP[i-1]-MC_Raw_AFB[i-1];
      if (i == nb-1 && fabs(diff2) > fabs(MC_Raw_AFB_ES_DOWN[i-1]-MC_Raw_AFB[i-1])) diff1 = MC_Raw_AFB_ES_DOWN[i-1]-MC_Raw_AFB[i-1];
*/
      //cout<<k<<"  "<<i<<"   diff1   "<<diff1<<endl;
      //cout<<k<<"  "<<i<<"   diff2   "<<diff2<<endl;
      if (diff1 >0. ? total_plus[k][i] += diff1*diff1 : total_minus[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus[k][i] += diff2*diff2 : total_minus[k][i] += diff2*diff2);

      if (diff1 >0. ? total_plus_es[k][i] += diff1*diff1 : total_minus_es[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus_es[k][i] += diff2*diff2 : total_minus_es[k][i] += diff2*diff2);
      //cout<<total_plus_es[k][i]<<endl;
      //cout<<total_minus_es[k][i]<<endl;
      if (total_plus_es[k][i] != 0){
        h_Systematics_es_raw_plus[k]->SetBinContent(i+1,sqrt(total_plus_es[k][i]));
        h_Systematics_es_raw_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_es[k][i] != 0){
        h_Systematics_es_raw_minus[k]->SetBinContent(i+1,-sqrt(total_minus_es[k][i]));
        h_Systematics_es_raw_minus[k]->SetBinError(i+1,0.000000001);      
      }

      MC_Raw_AFB_ES_Diff_Up[i] = diff1;//TMath::Max(diff1,diff2);
      MC_Raw_AFB_ES_Diff_Down[i] = diff2;//TMath::Min(diff1,diff2);
      h_MC_Raw_AFB_ES_Diff_Up[k]->SetBinContent(i+1,MC_Raw_AFB_ES_Diff_Up[i]);
      h_MC_Raw_AFB_ES_Diff_Down[k]->SetBinContent(i+1,MC_Raw_AFB_ES_Diff_Down[i]);
     
      
      //fsr table raw level
      /*
	if (k == 0 && i == 0){ 
	cout<<"FSR SYSTEMATICS (RAW LEVEL)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
	cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff1<<"  &  "<<setprecision(3)<<diff2<<"    \\\\    "<<endl;
      */
       //end of fsr table raw level
/*
      MC_Raw_AFB_FSR_Diff_Up[i] = diff1;//TMath::Max(diff1,diff2);
      MC_Raw_AFB_FSR_Diff_Down[i] = diff2;//TMath::Min(diff1,diff2);
      h_MC_Raw_AFB_FSR_Diff_Up[k]->SetBinContent(i+1,MC_Raw_AFB_FSR_Diff_Up[i]);
      h_MC_Raw_AFB_FSR_Diff_Down[k]->SetBinContent(i+1,MC_Raw_AFB_FSR_Diff_Down[i]);
*/


      MC_Raw_AFB_bkg[i] = AFB(hMeasCos_M_Y_Forward_bkg[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward_bkg[k]->GetBinContent(i+1));

      MC_Raw_AFB_bkg_UP[i] = AFB(hMeasCos_M_Y_Forward_bkg_UP[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward_bkg_UP[k]->GetBinContent(i+1));
      h_MC_Raw_AFB_bkg_UP[k]->SetBinContent(i+1,MC_Raw_AFB_bkg_UP[i]);
      MC_Raw_AFB_bkg_DOWN[i] = AFB(hMeasCos_M_Y_Forward_bkg_DOWN[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward_bkg_DOWN[k]->GetBinContent(i+1));
      h_MC_Raw_AFB_bkg_DOWN[k]->SetBinContent(i+1,MC_Raw_AFB_bkg_DOWN[i]);
      diff1 = 0;
      diff2 = 0;
      diff1 = MC_Raw_AFB_bkg_UP[i]-MC_Raw_AFB_bkg[i];
      diff2 = MC_Raw_AFB_bkg_DOWN[i]-MC_Raw_AFB_bkg[i];
      if (diff1 >0. ? total_plus[k][i] += diff1*diff1 : total_minus[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus[k][i] += diff2*diff2 : total_minus[k][i] += diff2*diff2);

      if (diff1 >0. ? total_plus_bkg[k][i] += diff1*diff1 : total_minus_bkg[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus_bkg[k][i] += diff2*diff2 : total_minus_bkg[k][i] += diff2*diff2);
      if (total_plus_bkg[k][i] != 0){
	h_Systematics_bkg_raw_plus[k]->SetBinContent(i+1,sqrt(total_plus_bkg[k][i]));
	h_Systematics_bkg_raw_plus[k]->SetBinError(i+1,0.000000001); 
      }
      if (total_minus_bkg[k][i] != 0){
	h_Systematics_bkg_raw_minus[k]->SetBinContent(i+1,-sqrt(total_minus_bkg[k][i]));  
	h_Systematics_bkg_raw_minus[k]->SetBinError(i+1,0.000000001); 
      }
      //bkg systematics table raw level
      /*
	if (k == 0 && i == 0){ 
	cout<<"bkg SYSTEMATICS (RAW LEVEL)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    bkg Up - Nominal           bkg Down - Nominal"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
	cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff1<<"  &  "<<setprecision(3)<<diff2<<"    \\\\    "<<endl;
      */
       //end of bkg table raw level
      MC_Raw_AFB_bkg_Diff_Up[i] = diff1;//TMath::Max(diff1,diff2);
      MC_Raw_AFB_bkg_Diff_Down[i] = diff2;//TMath::Min(diff1,diff2);
      h_MC_Raw_AFB_bkg_Diff_Up[k]->SetBinContent(i+1,MC_Raw_AFB_bkg_Diff_Up[i]);
      h_MC_Raw_AFB_bkg_Diff_Down[k]->SetBinContent(i+1,MC_Raw_AFB_bkg_Diff_Down[i]);


      MC_UnDet_AFB[i] = AFB(hUnDetectorCos_M_Y_Forward[k]->GetBinContent(i+1),hUnDetectorCos_M_Y_Backward[k]->GetBinContent(i+1));
      h_MC_UnDet_AFB[k]->SetBinContent(i+1,MC_UnDet_AFB[i]);

      //fsr systematics bare lepton level
      /*
      MC_UnDet_AFB_FSR_UP[i] = AFB(hUnDetectorCos_M_Y_Forward_FSR_UP[k]->GetBinContent(i+1),hUnDetectorCos_M_Y_Backward_FSR_UP[k]->GetBinContent(i+1));
      MC_UnDet_AFB_FSR_DOWN[i] = AFB(hUnDetectorCos_M_Y_Forward_FSR_DOWN[k]->GetBinContent(i+1),hUnDetectorCos_M_Y_Backward_FSR_DOWN[k]->GetBinContent(i+1));
      */
      MC_UnDet_AFB_FSR_UP[i] = AFB(MC_Unfolded_UnDet_Forward_FSR_Up[k][i],MC_Unfolded_UnDet_Backward_FSR_Up[k][i]);
      MC_UnDet_AFB_FSR_DOWN[i] = AFB(MC_Unfolded_UnDet_Forward_FSR_Down[k][i],MC_Unfolded_UnDet_Backward_FSR_Down[k][i]);
      h_MC_UnDet_AFB_FSR_UP[k]->SetBinContent(i+1,MC_UnDet_AFB_FSR_UP[i]);
      h_MC_UnDet_AFB_FSR_DOWN[k]->SetBinContent(i+1,MC_UnDet_AFB_FSR_DOWN[i]);
      double diff_NoDet1 = MC_UnDet_AFB_FSR_UP[i]-MC_UnDet_AFB[i];
      double diff_NoDet2 = MC_UnDet_AFB_FSR_DOWN[i]-MC_UnDet_AFB[i];
      //
      if (i == nb-1){
	if (fabs(diff_NoDet1) > fabs(MC_UnDet_AFB_FSR_UP[i-1]-MC_UnDet_AFB[i-1])) diff_NoDet1 = MC_UnDet_AFB_FSR_UP[i-1]-MC_UnDet_AFB[i-1];
	if (fabs(diff_NoDet2) > fabs(MC_UnDet_AFB_FSR_DOWN[i-1]-MC_UnDet_AFB[i-1])) diff_NoDet2 = MC_UnDet_AFB_FSR_DOWN[i-1]-MC_UnDet_AFB[i-1];
      }
      //
      if (diff_NoDet1 >0. ? total_plus_undet[k][i] += diff_NoDet1*diff_NoDet1 : total_minus_undet[k][i] += diff_NoDet1*diff_NoDet1);
      if (diff_NoDet2 >0. ? total_plus_undet[k][i] += diff_NoDet2*diff_NoDet2 : total_minus_undet[k][i] += diff_NoDet2*diff_NoDet2);

      if (diff_NoDet1 >0. ? total_plus_undet_fsr[k][i] += diff_NoDet1*diff_NoDet1 : total_minus_undet_fsr[k][i] += diff_NoDet1*diff_NoDet1);
      if (diff_NoDet2 >0. ? total_plus_undet_fsr[k][i] += diff_NoDet2*diff_NoDet2 : total_minus_undet_fsr[k][i] += diff_NoDet2*diff_NoDet2);

      if (total_plus_undet_fsr[k][i] != 0){
	h_Systematics_fsr_bare_plus[k]->SetBinContent(i+1,sqrt(total_plus_undet_fsr[k][i]));
	h_Systematics_fsr_bare_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_undet_fsr[k][i] != 0){
	h_Systematics_fsr_bare_minus[k]->SetBinContent(i+1,-sqrt(total_minus_undet_fsr[k][i]));
	h_Systematics_fsr_bare_minus[k]->SetBinError(i+1,0.000000001);
      }
       //fsr table bare level
      /*
	 if (k == 0 && i == 0){ 
	 cout<<"FSR SYSTEMATICS (BARE LEPTON LEVEL)"<<endl;
	 cout<<"---------------"<<endl;
	 cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
	 cout<<"-------------------------------------------------------------------"<<endl;
	 }
	 cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_NoDet1<<"  &  "<<setprecision(3)<<diff_NoDet2<<"    \\\\    "<<endl;
       //end of fsr table bare lepton level
       */
      MC_UnDet_AFB_FSR_Diff_Up[i] = diff_NoDet1;//TMath::Max(diff1,diff2);
      MC_UnDet_AFB_FSR_Diff_Down[i] = diff_NoDet2;//TMath::Min(diff1,diff2);
      h_MC_UnDet_AFB_FSR_Diff_Up[k]->SetBinContent(i+1,MC_UnDet_AFB_FSR_Diff_Up[i]);
      h_MC_UnDet_AFB_FSR_Diff_Down[k]->SetBinContent(i+1,MC_UnDet_AFB_FSR_Diff_Down[i]);
      //

//es syst at bare lepton
      diff_NoDet1 = 0;
      diff_NoDet2 = 0;

      MC_UnDet_AFB_ES_UP[i] = AFB(MC_Unfolded_UnDet_Forward_ES_Up[k][i],MC_Unfolded_UnDet_Backward_ES_Up[k][i]);
      MC_UnDet_AFB_ES_DOWN[i] = AFB(MC_Unfolded_UnDet_Forward_ES_Down[k][i],MC_Unfolded_UnDet_Backward_ES_Down[k][i]);
      h_MC_UnDet_AFB_ES_UP[k]->SetBinContent(i+1,MC_UnDet_AFB_ES_UP[i]);
      h_MC_UnDet_AFB_ES_DOWN[k]->SetBinContent(i+1,MC_UnDet_AFB_ES_DOWN[i]);
      diff_NoDet1 = MC_UnDet_AFB_ES_UP[i]-MC_UnDet_AFB[i];
      diff_NoDet2 = MC_UnDet_AFB_ES_DOWN[i]-MC_UnDet_AFB[i];
      //
      if (i == nb-1){
	if (fabs(diff_NoDet1) > fabs(MC_UnDet_AFB_ES_UP[i-1]-MC_UnDet_AFB[i-1])) diff_NoDet1 = MC_UnDet_AFB_ES_UP[i-1]-MC_UnDet_AFB[i-1];
	if (fabs(diff_NoDet2) > fabs(MC_UnDet_AFB_ES_DOWN[i-1]-MC_UnDet_AFB[i-1])) diff_NoDet2 = MC_UnDet_AFB_ES_DOWN[i-1]-MC_UnDet_AFB[i-1];
      }
      //
      if (diff_NoDet1 >0. ? total_plus_undet[k][i] += diff_NoDet1*diff_NoDet1 : total_minus_undet[k][i] += diff_NoDet1*diff_NoDet1);
      if (diff_NoDet2 >0. ? total_plus_undet[k][i] += diff_NoDet2*diff_NoDet2 : total_minus_undet[k][i] += diff_NoDet2*diff_NoDet2);
      if (diff_NoDet1 >0. ? total_plus_undet_es[k][i] += diff_NoDet1*diff_NoDet1 : total_minus_undet_es[k][i] += diff_NoDet1*diff_NoDet1);
      if (diff_NoDet2 >0. ? total_plus_undet_es[k][i] += diff_NoDet2*diff_NoDet2 : total_minus_undet_es[k][i] += diff_NoDet2*diff_NoDet2);

      if (total_plus_undet_es[k][i] != 0){
        h_Systematics_es_bare_plus[k]->SetBinContent(i+1,sqrt(total_plus_undet_es[k][i]));
        h_Systematics_es_bare_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_undet_es[k][i] != 0){
        h_Systematics_es_bare_minus[k]->SetBinContent(i+1,-sqrt(total_minus_undet_es[k][i]));
        h_Systematics_es_bare_minus[k]->SetBinError(i+1,0.000000001);
      }
       //fsr table bare level
      /*
         if (k == 0 && i == 0){ 
         cout<<"FSR SYSTEMATICS (BARE LEPTON LEVEL)"<<endl;
         cout<<"---------------"<<endl;
         cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
         cout<<"-------------------------------------------------------------------"<<endl;
         }
         cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_NoDet1<<"  &  "<<setprecision(3)<<diff_NoDet2<<"    \\\\    "<<endl;
       //end of fsr table bare lepton level
       */
      MC_UnDet_AFB_ES_Diff_Up[i] = diff_NoDet1;//TMath::Max(diff1,diff2);
      MC_UnDet_AFB_ES_Diff_Down[i] = diff_NoDet2;//TMath::Min(diff1,diff2);
      h_MC_UnDet_AFB_ES_Diff_Up[k]->SetBinContent(i+1,MC_UnDet_AFB_ES_Diff_Up[i]);
      h_MC_UnDet_AFB_ES_Diff_Down[k]->SetBinContent(i+1,MC_UnDet_AFB_ES_Diff_Down[i]);

//

      //bkg systematics bare lepton level
      MC_UnDet_AFB_bkg[i] = AFB(MC_Unfolded_UnDet_Forward_bkg[k][i],MC_Unfolded_UnDet_Backward_bkg[k][i]);
      h_MC_Unfolded_UnDet_AFB_bkg[k]->SetBinContent(i+1,MC_UnDet_AFB_bkg[i]);

      MC_UnDet_AFB_bkg_UP[i] = AFB(MC_Unfolded_UnDet_Forward_bkg_Up[k][i],MC_Unfolded_UnDet_Backward_bkg_Up[k][i]);
      h_MC_Unfolded_UnDet_AFB_bkg_UP[k]->SetBinContent(i+1,MC_UnDet_AFB_bkg_UP[i]);
      MC_UnDet_AFB_bkg_DOWN[i] = AFB(MC_Unfolded_UnDet_Forward_bkg_Down[k][i],MC_Unfolded_UnDet_Backward_bkg_Down[k][i]);
      h_MC_Unfolded_UnDet_AFB_bkg_DOWN[k]->SetBinContent(i+1,MC_UnDet_AFB_bkg_DOWN[i]);
      diff_NoDet1 = 0;
      diff_NoDet2 = 0;
      diff_NoDet1 = MC_UnDet_AFB_bkg_UP[i]-MC_UnDet_AFB_bkg[i];//MC_UnDet_AFB[i];
      diff_NoDet2 = MC_UnDet_AFB_bkg_DOWN[i]-MC_UnDet_AFB_bkg[i];//MC_UnDet_AFB[i];
      if (diff_NoDet1 >0. ? total_plus_undet[k][i] += diff_NoDet1*diff_NoDet1 : total_minus_undet[k][i] += diff_NoDet1*diff_NoDet1);
      if (diff_NoDet2 >0. ? total_plus_undet[k][i] += diff_NoDet2*diff_NoDet2 : total_minus_undet[k][i] += diff_NoDet2*diff_NoDet2);
      if (diff_NoDet1 >0. ? total_plus_undet_bkg[k][i] += diff_NoDet1*diff_NoDet1 : total_minus_undet_bkg[k][i] += diff_NoDet1*diff_NoDet1);
      if (diff_NoDet2 >0. ? total_plus_undet_bkg[k][i] += diff_NoDet2*diff_NoDet2 : total_minus_undet_bkg[k][i] += diff_NoDet2*diff_NoDet2);
      if (total_plus_undet_bkg[k][i] != 0){
	h_Systematics_bkg_bare_plus[k]->SetBinError(i+1,0.00000001);
	h_Systematics_bkg_bare_plus[k]->SetBinContent(i+1,sqrt(total_plus_undet_bkg[k][i]));
      }
      if (total_minus_undet_bkg[k][i] != 0){
	h_Systematics_bkg_bare_minus[k]->SetBinContent(i+1,-sqrt(total_minus_undet_bkg[k][i]));   
	h_Systematics_bkg_bare_minus[k]->SetBinError(i+1,0.00000001);
      }
      //bkg table bare level
      /*
      if (k == 0 && i == 0){ 
	cout<<"bkg SYSTEMATICS (BARE LEPTON LEVEL)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    bkg Up - Nominal           bkg Down - Nominal"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
      }
      cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_NoDet1<<"  &  "<<setprecision(3)<<diff_NoDet2<<"    \\\\    "<<endl;
      */
      //end of bkg table bare lepton level

      MC_UnDet_AFB_bkg_Diff_Up[i] = diff_NoDet1;//TMath::Max(diff1,diff2);
      MC_UnDet_AFB_bkg_Diff_Down[i] = diff_NoDet2;//TMath::Min(diff1,diff2);
      h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[k]->SetBinContent(i+1,MC_UnDet_AFB_bkg_Diff_Up[i]);
      h_MC_Unfolded_UnDet_AFB_bkg_Diff_Down[k]->SetBinContent(i+1,MC_UnDet_AFB_bkg_Diff_Down[i]);
      //

      MC_NoFsr_AFB[i] = AFB(hNoFsrTruthCos_M_Y_Forward[k]->GetBinContent(i+1),hNoFsrTruthCos_M_Y_Backward[k]->GetBinContent(i+1));
      h_MC_NoFsr_AFB[k]->SetBinContent(i+1,MC_NoFsr_AFB[i]);

      //
      MC_True_AFB[i] = AFB(hTrueCos_M_Y_Forward[k]->GetBinContent(i+1),hTrueCos_M_Y_Backward[k]->GetBinContent(i+1));
      h_MC_True_AFB[k]->SetBinContent(i+1,MC_True_AFB[i]);
      dilution[k][i] = MC_True_AFB[i]/MC_NoFsr_AFB[i];
      //cout<<k<<"  "<<i<<"   "<<MC_True_AFB[i]<<"   "<<MC_NoFsr_AFB[i]<<"   "<<dilution[k][i]<<endl;
     //


      for (int j=0;j<nb;j++){
	error_forward[i] += pow(Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1),2)*hDataMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	error_backward[i] += pow(Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1),2)*hDataMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
      }
      error_forward[i] = sqrt(error_forward[i]);
      error_backward[i] = sqrt(error_backward[i]);

      h_Unfolded_UnDet_Forward[k]->SetBinContent(i+1,Unfolded_UnDet_Forward[k][i]);
      h_Unfolded_UnDet_Forward[k]->SetBinError(i+1,error_forward[i]);
      h_Unfolded_UnDet_Backward[k]->SetBinContent(i+1,Unfolded_UnDet_Backward[k][i]);
      h_Unfolded_UnDet_Backward[k]->SetBinError(i+1,error_backward[i]);
      Unfolded_UnDet_AFB[i] = AFB(Unfolded_UnDet_Forward[k][i],Unfolded_UnDet_Backward[k][i]);

      Closure_Unfolded_UnDet_AFB[i] = AFB(Closure_Unfolded_UnDet_Forward[k][i],Closure_Unfolded_UnDet_Backward[k][i]);
      Closure_Unfolded_NoFsr_AFB[i] = AFB(Closure_Unfolded_NoFsr_Forward[k][i],Closure_Unfolded_NoFsr_Backward[k][i]);

      for (int j=0;j<nb;j++){
	first_sum[i] += pow(Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1),2)*hDataMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	second_sum[i] += pow(Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1),2)*hDataMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
      }
      first_sum[i] *= 4*pow(Unfolded_UnDet_Forward[k][i],2)/pow(Unfolded_UnDet_Forward[k][i]+Unfolded_UnDet_Backward[k][i],4);
      second_sum[i] *= 4*pow(Unfolded_UnDet_Backward[k][i],2)/pow(Unfolded_UnDet_Forward[k][i]+Unfolded_UnDet_Backward[k][i],4);
      Unfolded_UnDet_error[i] = sqrt(first_sum[i]+second_sum[i]);

      h_Unfolded_UnDet_AFB[k]->SetBinContent(i+1,Unfolded_UnDet_AFB[i]);
      h_Unfolded_UnDet_AFB[k]->SetBinError(i+1,Unfolded_UnDet_error[i]);

      for (int j=0;j<nb;j++){
	first_sum_fsr[i] += pow(Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1),2)*hDataMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	second_sum_fsr[i] += pow(Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1),2)*hDataMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
      }
      first_sum_fsr[i] *= 4*pow(Unfolded_NoFsr_Forward[k][i],2)/pow(Unfolded_NoFsr_Forward[k][i]+Unfolded_NoFsr_Backward[k][i],4);
      second_sum_fsr[i] *= 4*pow(Unfolded_NoFsr_Backward[k][i],2)/pow(Unfolded_NoFsr_Forward[k][i]+Unfolded_NoFsr_Backward[k][i],4);
      Unfolded_NoFsr_error[i] = sqrt(first_sum_fsr[i]+second_sum_fsr[i]);

      h_Unfolded_NoFsr_Forward[k]->SetBinContent(i+1,Unfolded_NoFsr_Forward[k][i]);
      h_Unfolded_NoFsr_Backward[k]->SetBinContent(i+1,Unfolded_NoFsr_Backward[k][i]);
      Unfolded_NoFsr_AFB[i] = AFB(Unfolded_NoFsr_Forward[k][i],Unfolded_NoFsr_Backward[k][i]);
      h_Unfolded_NoFsr_AFB[k]->SetBinContent(i+1,Unfolded_NoFsr_AFB[i]);
      h_Unfolded_NoFsr_AFB[k]->SetBinError(i+1,Unfolded_NoFsr_error[i]);

      for (int j=0;j<nb;j++){
	error_closure_forward[i] += pow(Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1),2)*hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	error_closure_backward[i] += pow(Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1),2)*hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
      }
      error_closure_forward[i] = sqrt(error_closure_forward[i]);
      error_closure_backward[i] = sqrt(error_closure_backward[i]);

      h_Closure_Unfolded_UnDet_Forward[k]->SetBinContent(i+1,Closure_Unfolded_UnDet_Forward[k][i]);
      h_Closure_Unfolded_UnDet_Forward[k]->SetBinError(i+1,error_closure_forward[i]);

      h_Closure_Unfolded_UnDet_Backward[k]->SetBinContent(i+1,Closure_Unfolded_UnDet_Backward[k][i]);
      h_Closure_Unfolded_UnDet_Backward[k]->SetBinError(i+1,error_closure_backward[i]);	

      for (int j=0;j<nb;j++){
	closure_first_sum[i] += pow(Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1),2)*hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	closure_second_sum[i] += pow(Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1),2)*hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
      }
      closure_first_sum[i] *= 4*pow(Closure_Unfolded_UnDet_Forward[k][i],2)/pow(Closure_Unfolded_UnDet_Forward[k][i]+Closure_Unfolded_UnDet_Backward[k][i],4);
      closure_second_sum[i] *= 4*pow(Closure_Unfolded_UnDet_Backward[k][i],2)/pow(Closure_Unfolded_UnDet_Forward[k][i]+Closure_Unfolded_UnDet_Backward[k][i],4);
      closure_Unfolded_UnDet_error[i] = sqrt(closure_first_sum[i]+closure_second_sum[i]);

      h_Closure_Unfolded_UnDet_AFB[k]->SetBinContent(i+1,Closure_Unfolded_UnDet_AFB[i]);
      h_Closure_Unfolded_UnDet_AFB[k]->SetBinError(i+1,closure_Unfolded_UnDet_error[i]);

      h_Closure_Unfolded_NoFsr_Forward[k]->SetBinContent(i+1,Closure_Unfolded_NoFsr_Forward[k][i]);
      h_Closure_Unfolded_NoFsr_Backward[k]->SetBinContent(i+1,Closure_Unfolded_NoFsr_Backward[k][i]);

      MC_Unfolded_NoFsr_AFB_FSR_Up[i] = AFB(MC_Unfolded_NoFsr_Forward_FSR_Up[k][i],MC_Unfolded_NoFsr_Backward_FSR_Up[k][i]);
      MC_Unfolded_NoFsr_AFB_FSR_Down[i] = AFB(MC_Unfolded_NoFsr_Forward_FSR_Down[k][i],MC_Unfolded_NoFsr_Backward_FSR_Down[k][i]);
      float diff_undet1 = MC_Unfolded_NoFsr_AFB_FSR_Up[i]-MC_NoFsr_AFB[i];//Closure_Unfolded_NoFsr_AFB[i];//-MC_UnDet_AFB[i];
      float diff_undet2 = MC_Unfolded_NoFsr_AFB_FSR_Down[i]-MC_NoFsr_AFB[i];//Closure_Unfolded_NoFsr_AFB[i];//-MC_UnDet_AFB[i];
      h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Up[k]->SetBinContent(i+1,diff_undet1);
      h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Down[k]->SetBinContent(i+1,diff_undet2);
      //
      if (i == nb-1){
	if (fabs(diff_undet1) > fabs(MC_Unfolded_NoFsr_AFB_FSR_Up[i-1]-MC_NoFsr_AFB[i-1])) diff_undet1 = MC_Unfolded_NoFsr_AFB_FSR_Up[i-1]-MC_UnDet_AFB[i-1];
	if (fabs(diff_undet2) > fabs(MC_Unfolded_NoFsr_AFB_FSR_Down[i-1]-MC_NoFsr_AFB[i-1])) diff_undet2 = MC_Unfolded_NoFsr_AFB_FSR_Down[i-1]-MC_UnDet_AFB[i-1];
      }
      //
      if (diff_undet1 >0. ? total_plus_nofsr[k][i] += diff_undet1*diff_undet1 : total_minus_nofsr[k][i] += diff_undet1*diff_undet1);
      if (diff_undet2 >0. ? total_plus_nofsr[k][i] += diff_undet2*diff_undet2 : total_minus_nofsr[k][i] += diff_undet2*diff_undet2);

      if (diff_undet1 >0. ? total_plus_nofsr_fsr[k][i] += diff_undet1*diff_undet1 : total_minus_nofsr_fsr[k][i] += diff_undet1*diff_undet1);
      if (diff_undet2 >0. ? total_plus_nofsr_fsr[k][i] += diff_undet2*diff_undet2 : total_minus_nofsr_fsr[k][i] += diff_undet2*diff_undet2);
      if (total_plus_nofsr_fsr[k][i] != 0){
	h_Systematics_fsr_Born_plus[k]->SetBinContent(i+1,sqrt(total_plus_nofsr_fsr[k][i]));
	h_Systematics_fsr_Born_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_nofsr_fsr[k][i] != 0){
	h_Systematics_fsr_Born_minus[k]->SetBinContent(i+1,-sqrt(total_minus_nofsr_fsr[k][i]));
	h_Systematics_fsr_Born_minus[k]->SetBinError(i+1,0.000000001);
      }
    //fsr systematics born level table
      /*
	if (k == 0 && i == 0){ 
	cout<<"FSR SYSTEMATICS (Born Level)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
	cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_undet1<<"  &  "<<setprecision(3)<<diff_undet2<<"    \\\\    "<<endl;
      */
       //end of fsr systematics born level table


//es
      diff_undet1 = 0;
      diff_undet2 = 0;
      MC_Unfolded_NoFsr_AFB_ES_Up[i] = AFB(MC_Unfolded_NoFsr_Forward_ES_Up[k][i],MC_Unfolded_NoFsr_Backward_ES_Up[k][i]);
      MC_Unfolded_NoFsr_AFB_ES_Down[i] = AFB(MC_Unfolded_NoFsr_Forward_ES_Down[k][i],MC_Unfolded_NoFsr_Backward_ES_Down[k][i]);
      diff_undet1 = MC_Unfolded_NoFsr_AFB_ES_Up[i]-MC_NoFsr_AFB[i];//Closure_Unfolded_NoFsr_AFB[i];//-MC_UnDet_AFB[i];
      diff_undet2 = MC_Unfolded_NoFsr_AFB_ES_Down[i]-MC_NoFsr_AFB[i];//Closure_Unfolded_NoFsr_AFB[i];//-MC_UnDet_AFB[i];
      h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[k]->SetBinContent(i+1,diff_undet1);
      h_MC_Unfolded_NoFsr_AFB_ES_Diff_Down[k]->SetBinContent(i+1,diff_undet2);
      //
      if (i == nb-1){
	if (fabs(diff_undet1) > fabs(MC_Unfolded_NoFsr_AFB_ES_Up[i-1]-MC_NoFsr_AFB[i-1])) diff_undet1 = MC_Unfolded_NoFsr_AFB_ES_Up[i-1]-MC_UnDet_AFB[i-1];
	if (fabs(diff_undet2) > fabs(MC_Unfolded_NoFsr_AFB_ES_Down[i-1]-MC_NoFsr_AFB[i-1])) diff_undet2 = MC_Unfolded_NoFsr_AFB_ES_Down[i-1]-MC_UnDet_AFB[i-1];
      }
      //
      if (diff_undet1 >0. ? total_plus_nofsr[k][i] += diff_undet1*diff_undet1 : total_minus_nofsr[k][i] += diff_undet1*diff_undet1);
      if (diff_undet2 >0. ? total_plus_nofsr[k][i] += diff_undet2*diff_undet2 : total_minus_nofsr[k][i] += diff_undet2*diff_undet2);

      if (diff_undet1 >0. ? total_plus_nofsr_es[k][i] += diff_undet1*diff_undet1 : total_minus_nofsr_es[k][i] += diff_undet1*diff_undet1);
      if (diff_undet2 >0. ? total_plus_nofsr_es[k][i] += diff_undet2*diff_undet2 : total_minus_nofsr_es[k][i] += diff_undet2*diff_undet2);
      if (total_plus_nofsr_es[k][i] != 0){
        h_Systematics_es_Born_plus[k]->SetBinContent(i+1,sqrt(total_plus_nofsr_es[k][i]));
        h_Systematics_es_Born_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_nofsr_es[k][i] != 0){
        h_Systematics_es_Born_minus[k]->SetBinContent(i+1,-sqrt(total_minus_nofsr_es[k][i]));
        h_Systematics_es_Born_minus[k]->SetBinError(i+1,0.000000001);
      }
//


      MC_Unfolded_NoFsr_AFB_bkg[i] = AFB(MC_Unfolded_NoFsr_Forward_bkg[k][i],MC_Unfolded_NoFsr_Backward_bkg[k][i]);

      MC_Unfolded_NoFsr_AFB_bkg_Up[i] = AFB(MC_Unfolded_NoFsr_Forward_bkg_Up[k][i],MC_Unfolded_NoFsr_Backward_bkg_Up[k][i]);
      MC_Unfolded_NoFsr_AFB_bkg_Down[i] = AFB(MC_Unfolded_NoFsr_Forward_bkg_Down[k][i],MC_Unfolded_NoFsr_Backward_bkg_Down[k][i]);
      diff_undet1 = 0;
      diff_undet2 = 0;
      diff_undet1 = MC_Unfolded_NoFsr_AFB_bkg_Up[i]-MC_Unfolded_NoFsr_AFB_bkg[i];
      diff_undet2 = MC_Unfolded_NoFsr_AFB_bkg_Down[i]-MC_Unfolded_NoFsr_AFB_bkg[i];
      h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[k]->SetBinContent(i+1,diff_undet1);
      h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Down[k]->SetBinContent(i+1,diff_undet2);
      if (diff_undet1 >0. ? total_plus_nofsr[k][i] += diff_undet1*diff_undet1 : total_minus_nofsr[k][i] += diff_undet1*diff_undet1);
      if (diff_undet2 >0. ? total_plus_nofsr[k][i] += diff_undet2*diff_undet2 : total_minus_nofsr[k][i] += diff_undet2*diff_undet2);

      if (diff_undet1 >0. ? total_plus_nofsr_bkg[k][i] += diff_undet1*diff_undet1 : total_minus_nofsr_bkg[k][i] += diff_undet1*diff_undet1);
      if (diff_undet2 >0. ? total_plus_nofsr_bkg[k][i] += diff_undet2*diff_undet2 : total_minus_nofsr_bkg[k][i] += diff_undet2*diff_undet2);
      if (total_plus_nofsr_bkg[k][i] != 0){
	h_Systematics_bkg_Born_plus[k]->SetBinContent(i+1,sqrt(total_plus_nofsr_bkg[k][i]));
	h_Systematics_bkg_Born_plus[k]->SetBinError(i+1,0.00000000001);
      }
      if (total_minus_nofsr_bkg[k][i] != 0){
	h_Systematics_bkg_Born_minus[k]->SetBinContent(i+1,-sqrt(total_minus_nofsr_bkg[k][i]));
	h_Systematics_bkg_Born_minus[k]->SetBinError(i+1,0.00000000001);
      }
      //bkg systematics born level table
      /*
      if (k == 0 && i == 0){ 
	cout<<"Bkg SYSTEMATICS (Born Level)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    bkg Up - Nominal           bkg Down - Nominal"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
      }
      cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_undet1<<"  &  "<<setprecision(3)<<diff_undet2<<"    \\\\    "<<endl;
      */
      //end of fsr systematics born level table
      
    }  
    for (int i=0;i<nb_sin;i++){
      MC_Raw_sin2312_AFB[i] = 0;
      MC_Raw_sin2412_AFB[i] = 0;
      MC_Raw_sin2212_AFB[i] = 0;
      MC_Unfolded_UnDet_sin2312_Forward[k][i] = 0;
      MC_Unfolded_UnDet_sin2312_Backward[k][i] = 0;
      MC_Unfolded_UnDet_sin2412_Forward[k][i] = 0;
      MC_Unfolded_UnDet_sin2412_Backward[k][i] = 0;
      MC_Unfolded_UnDet_sin2212_Forward[k][i] = 0;
      MC_Unfolded_UnDet_sin2212_Backward[k][i] = 0;
      MC_Unfolded_UnDet_sin2312_AFB[i] = 0;
      MC_Unfolded_UnDet_sin2412_AFB[i] = 0;
      MC_Unfolded_UnDet_sin2212_AFB[i] = 0;
      MC_Unfolded_NoFsr_sin2312_Forward[k][i] = 0;
      MC_Unfolded_NoFsr_sin2312_Backward[k][i] = 0;
      MC_Unfolded_NoFsr_sin2412_Forward[k][i] = 0;
      MC_Unfolded_NoFsr_sin2412_Backward[k][i] = 0;
      MC_Unfolded_NoFsr_sin2212_Forward[k][i] = 0;
      MC_Unfolded_NoFsr_sin2212_Backward[k][i] = 0;
      MC_Unfolded_NoFsr_sin2312_AFB[i] = 0;
      MC_Unfolded_NoFsr_sin2412_AFB[i] = 0;
      MC_Unfolded_NoFsr_sin2212_AFB[i] = 0;
      MC_Raw_sin2312_AFB[i] = AFB(h_Sin2312_MeasCos_M_Y_Forward[k]->GetBinContent(i+1),h_Sin2312_MeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_sin2412_AFB[i] = AFB(h_Sin2412_MeasCos_M_Y_Forward[k]->GetBinContent(i+1),h_Sin2412_MeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_sin2212_AFB[i] = AFB(h_Sin2212_MeasCos_M_Y_Forward[k]->GetBinContent(i+1),h_Sin2212_MeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      float diff1 = MC_Raw_sin2412_AFB[i]-MC_Raw_sin2312_AFB[i];
      float diff2 = MC_Raw_sin2212_AFB[i]-MC_Raw_sin2312_AFB[i];
      h_MC_Raw_sin2412m2312_AFB[k]->SetBinContent(i+1,diff1);
      h_MC_Raw_sin2212m2312_AFB[k]->SetBinContent(i+1,diff2);
      if (diff1 >0. ? total_plus[k][i] += diff1*diff1 : total_minus[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus[k][i] += diff2*diff2 : total_minus[k][i] += diff2*diff2);
      
      if (diff1 >0. ? total_plus_sin[k][i] += diff1*diff1 : total_minus_sin[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus_sin[k][i] += diff2*diff2 : total_minus_sin[k][i] += diff2*diff2);
      if (total_plus_sin[k][i] != 0){
	h_Systematics_sin_raw_plus[k]->SetBinContent(i+1,sqrt(total_plus_sin[k][i]));
	h_Systematics_sin_raw_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_sin[k][i] != 0){
	h_Systematics_sin_raw_minus[k]->SetBinContent(i+1,-sqrt(total_minus_sin[k][i]));
	h_Systematics_sin_raw_minus[k]->SetBinError(i+1,0.000000001);
      }

      /*
      //sin2thetaW systematics raw level table
      if (k == 0 && i == 0){ 
      cout<<"sin2thetaW SYSTEMATICS (Raw Level)"<<endl;
      cout<<"---------------"<<endl;
      cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
      cout<<"-------------------------------------------------------------------"<<endl;
      }
      cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff1<<"  &  "<<setprecision(3)<<diff2<<"    \\\\    "<<endl;
      //end of sin2theta systematics raw level table
      */
      for (int j=0;j<nb;j++){
	MC_Unfolded_UnDet_sin2312_Forward[k][i] += Inv_Response_Sin2312_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*h_Sin2312_MeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_sin2312_Backward[k][i] += Inv_Response_Sin2312_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*h_Sin2312_MeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_sin2412_Forward[k][i] += Inv_Response_Sin2412_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*h_Sin2412_MeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_sin2412_Backward[k][i] += Inv_Response_Sin2412_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*h_Sin2412_MeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_sin2212_Forward[k][i] += Inv_Response_Sin2212_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*h_Sin2212_MeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_sin2212_Backward[k][i] += Inv_Response_Sin2212_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*h_Sin2212_MeasCos_M_Y_Backward[k]->GetBinContent(j+1);

	MC_Unfolded_NoFsr_sin2312_Forward[k][i] += Inv_Response_Sin2312_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*h_Sin2312_MeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_sin2312_Backward[k][i] += Inv_Response_Sin2312_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*h_Sin2312_MeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_sin2412_Forward[k][i] += Inv_Response_Sin2412_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*h_Sin2412_MeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_sin2412_Backward[k][i] += Inv_Response_Sin2412_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*h_Sin2412_MeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_sin2212_Forward[k][i] += Inv_Response_Sin2212_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*h_Sin2212_MeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_sin2212_Backward[k][i] += Inv_Response_Sin2212_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*h_Sin2212_MeasCos_M_Y_Backward[k]->GetBinContent(j+1);
      }
      MC_Unfolded_UnDet_sin2312_AFB[i] = AFB(MC_Unfolded_UnDet_sin2312_Forward[k][i],MC_Unfolded_UnDet_sin2312_Backward[k][i]);
      MC_Unfolded_UnDet_sin2412_AFB[i] = AFB(MC_Unfolded_UnDet_sin2412_Forward[k][i],MC_Unfolded_UnDet_sin2412_Backward[k][i]);
      MC_Unfolded_UnDet_sin2212_AFB[i] = AFB(MC_Unfolded_UnDet_sin2212_Forward[k][i],MC_Unfolded_UnDet_sin2212_Backward[k][i]);
      diff1 = 0;
      diff2 = 0;
      diff1 = MC_Unfolded_UnDet_sin2412_AFB[i]-MC_Unfolded_UnDet_sin2312_AFB[i];
      diff2 = MC_Unfolded_UnDet_sin2212_AFB[i]-MC_Unfolded_UnDet_sin2312_AFB[i];
      h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[k]->SetBinContent(i+1,diff1);
      h_MC_Unfolded_UnDet_AFB_Diff_sin2212m2312[k]->SetBinContent(i+1,diff2);
      if (diff1 >0. ? total_plus_undet[k][i] += diff1*diff1 : total_minus_undet[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus_undet[k][i] += diff2*diff2 : total_minus_undet[k][i] += diff2*diff2);

      if (diff1 >0. ? total_plus_undet_sin[k][i] += diff1*diff1 : total_minus_undet_sin[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus_undet_sin[k][i] += diff2*diff2 : total_minus_undet_sin[k][i] += diff2*diff2);
      if (total_plus_undet_sin[k][i] != 0){
	h_Systematics_sin_bare_plus[k]->SetBinContent(i+1,sqrt(total_plus_undet_sin[k][i]));
	h_Systematics_sin_bare_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_undet_sin[k][i] != 0){
	h_Systematics_sin_bare_minus[k]->SetBinContent(i+1,-sqrt(total_minus_undet_sin[k][i]));
	h_Systematics_sin_bare_minus[k]->SetBinError(i+1,0.000000001);
      }
      //sin2thetaW systematics bare lepton level table
      /*
	if (k == 0 && i == 0){ 
	cout<<"sin2thetaW SYSTEMATICS (Bare Lepton Level)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
	cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff1<<"  &  "<<setprecision(3)<<diff2<<"    \\\\    "<<endl;
      */
      //end of sin2theta systematics bare lepton level table

      MC_Unfolded_NoFsr_sin2312_AFB[i] = AFB(MC_Unfolded_NoFsr_sin2312_Forward[k][i],MC_Unfolded_NoFsr_sin2312_Backward[k][i]);
      MC_Unfolded_NoFsr_sin2412_AFB[i] = AFB(MC_Unfolded_NoFsr_sin2412_Forward[k][i],MC_Unfolded_NoFsr_sin2412_Backward[k][i]);
      MC_Unfolded_NoFsr_sin2212_AFB[i] = AFB(MC_Unfolded_NoFsr_sin2212_Forward[k][i],MC_Unfolded_NoFsr_sin2212_Backward[k][i]);
      diff1 = 0;
      diff2 = 0;
      diff1 = MC_Unfolded_NoFsr_sin2412_AFB[i]-MC_Unfolded_NoFsr_sin2312_AFB[i];
      diff2 = MC_Unfolded_NoFsr_sin2212_AFB[i]-MC_Unfolded_NoFsr_sin2312_AFB[i];
      h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[k]->SetBinContent(i+1,diff1);
      h_MC_Unfolded_NoFsr_AFB_Diff_sin2212m2312[k]->SetBinContent(i+1,diff2);
      if (diff1 >0. ? total_plus_nofsr[k][i] += diff1*diff1 : total_minus_nofsr[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus_nofsr[k][i] += diff2*diff2 : total_minus_nofsr[k][i] += diff2*diff2);

      if (diff1 >0. ? total_plus_nofsr_sin[k][i] += diff1*diff1 : total_minus_nofsr_sin[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus_nofsr_sin[k][i] += diff2*diff2 : total_minus_nofsr_sin[k][i] += diff2*diff2);
      if (total_plus_nofsr_sin[k][i] != 0){
	h_Systematics_sin_Born_plus[k]->SetBinContent(i+1,sqrt(total_plus_nofsr_sin[k][i]));
	h_Systematics_sin_Born_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_nofsr_sin[k][i] != 0){
	h_Systematics_sin_Born_minus[k]->SetBinContent(i+1,-sqrt(total_minus_nofsr_sin[k][i]));
	h_Systematics_sin_Born_minus[k]->SetBinError(i+1,0.000000001);
      }
      //sin2thetaW systematics born lepton level table
      /*
      if (k == 0 && i == 0){ 
	cout<<"sin2thetaW SYSTEMATICS (Born Level)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
      }
      cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff1<<"  &  "<<setprecision(3)<<diff2<<"    \\\\    "<<endl;
      //end of sin2theta systematics born lepton level table
      */
    }
    for (int i=0;i<nb;i++){//alignment loop
      MC_Raw_Align_Ideal_AFB[i] = 0;  
      MC_Raw_Align_Startup_AFB[i] = 0;   
      MC_Raw_Align_Bowing_AFB[i] = 0;   
      MC_Raw_Align_Elliptical_AFB[i] = 0;   
      MC_Raw_Align_Radial_AFB[i] = 0;   
      MC_Raw_Align_Sagitta_AFB[i] = 0;   
      MC_Raw_Align_Skew_AFB[i] = 0;   
      MC_Raw_Align_Telescope_AFB[i] = 0;   
      MC_Raw_Align_CurlV2TF_AFB[i] = 0;   
      MC_Raw_Align_Twist_AFB[i] = 0;   
      MC_Raw_Align_Zexpansion_AFB[i] = 0;   
 
      MC_UnDet_Align_Ideal_AFB[i] = 0;   
      MC_UnDet_Align_Startup_AFB[i] = 0;   
      MC_UnDet_Align_Bowing_AFB[i] = 0;   
      MC_UnDet_Align_Elliptical_AFB[i] = 0;   
      MC_UnDet_Align_Radial_AFB[i] = 0;   
      MC_UnDet_Align_Sagitta_AFB[i] = 0;   
      MC_UnDet_Align_Skew_AFB[i] = 0;   
      MC_UnDet_Align_Telescope_AFB[i] = 0;   
      MC_UnDet_Align_CurlV2TF_AFB[i] = 0;   
      MC_UnDet_Align_Twist_AFB[i] = 0;   
      MC_UnDet_Align_Zexpansion_AFB[i] = 0;  

      MC_UnDet_Align_Ideal_Forward[k][i] = 0;   
      MC_UnDet_Align_Startup_Forward[k][i] = 0;   
      MC_UnDet_Align_Bowing_Forward[k][i] = 0;   
      MC_UnDet_Align_Elliptical_Forward[k][i] = 0;   
      MC_UnDet_Align_Radial_Forward[k][i] = 0;   
      MC_UnDet_Align_Sagitta_Forward[k][i] = 0;   
      MC_UnDet_Align_Skew_Forward[k][i] = 0;   
      MC_UnDet_Align_Telescope_Forward[k][i] = 0;   
      MC_UnDet_Align_CurlV2TF_Forward[k][i] = 0;   
      MC_UnDet_Align_Twist_Forward[k][i] = 0;   
      MC_UnDet_Align_Zexpansion_Forward[k][i] = 0;  

      MC_UnDet_Align_Ideal_Backward[k][i] = 0;   
      MC_UnDet_Align_Startup_Backward[k][i] = 0;   
      MC_UnDet_Align_Bowing_Backward[k][i] = 0;   
      MC_UnDet_Align_Elliptical_Backward[k][i] = 0;   
      MC_UnDet_Align_Radial_Backward[k][i] = 0;   
      MC_UnDet_Align_Sagitta_Backward[k][i] = 0;   
      MC_UnDet_Align_Skew_Backward[k][i] = 0;   
      MC_UnDet_Align_Telescope_Backward[k][i] = 0;   
      MC_UnDet_Align_CurlV2TF_Backward[k][i] = 0;   
      MC_UnDet_Align_Twist_Backward[k][i] = 0;   
      MC_UnDet_Align_Zexpansion_Backward[k][i] = 0; 

      MC_NoFsr_Align_Ideal_AFB[i] = 0;   
      MC_NoFsr_Align_Startup_AFB[i] = 0;   
      MC_NoFsr_Align_Bowing_AFB[i] = 0;   
      MC_NoFsr_Align_Elliptical_AFB[i] = 0;   
      MC_NoFsr_Align_Radial_AFB[i] = 0;   
      MC_NoFsr_Align_Sagitta_AFB[i] = 0;   
      MC_NoFsr_Align_Skew_AFB[i] = 0;   
      MC_NoFsr_Align_Telescope_AFB[i] = 0;   
      MC_NoFsr_Align_CurlV2TF_AFB[i] = 0;   
      MC_NoFsr_Align_Twist_AFB[i] = 0;   
      MC_NoFsr_Align_Zexpansion_AFB[i] = 0;  

      MC_NoFsr_Align_Ideal_Forward[k][i] = 0;   
      MC_NoFsr_Align_Startup_Forward[k][i] = 0;   
      MC_NoFsr_Align_Bowing_Forward[k][i] = 0;   
      MC_NoFsr_Align_Elliptical_Forward[k][i] = 0;   
      MC_NoFsr_Align_Radial_Forward[k][i] = 0;   
      MC_NoFsr_Align_Sagitta_Forward[k][i] = 0;   
      MC_NoFsr_Align_Skew_Forward[k][i] = 0;   
      MC_NoFsr_Align_Telescope_Forward[k][i] = 0;   
      MC_NoFsr_Align_CurlV2TF_Forward[k][i] = 0;   
      MC_NoFsr_Align_Twist_Forward[k][i] = 0;   
      MC_NoFsr_Align_Zexpansion_Forward[k][i] = 0;  

      MC_NoFsr_Align_Ideal_Backward[k][i] = 0;   
      MC_NoFsr_Align_Startup_Backward[k][i] = 0;   
      MC_NoFsr_Align_Bowing_Backward[k][i] = 0;   
      MC_NoFsr_Align_Elliptical_Backward[k][i] = 0;   
      MC_NoFsr_Align_Radial_Backward[k][i] = 0;   
      MC_NoFsr_Align_Sagitta_Backward[k][i] = 0;   
      MC_NoFsr_Align_Skew_Backward[k][i] = 0;   
      MC_NoFsr_Align_Telescope_Backward[k][i] = 0;   
      MC_NoFsr_Align_CurlV2TF_Backward[k][i] = 0;   
      MC_NoFsr_Align_Twist_Backward[k][i] = 0;   
      MC_NoFsr_Align_Zexpansion_Backward[k][i] = 0; 




      MC_Raw_Align_Ideal_AFB[i] = AFB(Align_Ideal_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Ideal_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      h_Ideal_Geo_AFB[k]->SetBinContent(i+1,MC_Raw_Align_Ideal_AFB[i]);
      h_Ideal_Geo_AFB[k]->SetBinError(i+1,RAWAFBERROR(MC_Raw_Align_Ideal_AFB[i],Align_Ideal_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Ideal_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1)));



      MC_Raw_Align_Startup_AFB[i] = AFB(Align_Startup_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Startup_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_Bowing_AFB[i] = AFB(Align_Bowing_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Bowing_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_Elliptical_AFB[i] = AFB(Align_Elliptical_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Elliptical_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_Radial_AFB[i] = AFB(Align_Radial_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Radial_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_Sagitta_AFB[i] = AFB(Align_Sagitta_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Sagitta_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_Skew_AFB[i] = AFB(Align_Skew_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Skew_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_Telescope_AFB[i] = AFB(Align_Telescope_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Telescope_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_CurlV2TF_AFB[i] = AFB(Align_CurlV2TF_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_CurlV2TF_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_Twist_AFB[i] = AFB(Align_Twist_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Twist_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_Zexpansion_AFB[i] = AFB(Align_Zexpansion_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Zexpansion_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));

      float diff_Startup = MC_Raw_Align_Startup_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_Bowing = MC_Raw_Align_Bowing_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_Elliptical = MC_Raw_Align_Elliptical_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_Radial = MC_Raw_Align_Radial_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_Sagitta = MC_Raw_Align_Sagitta_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_Skew = MC_Raw_Align_Skew_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_Telescope = MC_Raw_Align_Telescope_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_CurlV2TF = MC_Raw_Align_CurlV2TF_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_Twist = MC_Raw_Align_Twist_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_Zexpansion = MC_Raw_Align_Zexpansion_AFB[i] - MC_Raw_Align_Ideal_AFB[i];


      h_MC_Raw_Align_Startup_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Bowing);
      h_MC_Raw_Align_Bowing_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Bowing);
      h_MC_Raw_Align_Elliptical_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Elliptical);
      h_MC_Raw_Align_Radial_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Radial);
      h_MC_Raw_Align_Sagitta_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Sagitta);
      h_MC_Raw_Align_Skew_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Skew);
      h_MC_Raw_Align_Telescope_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Telescope);
      h_MC_Raw_Align_CurlV2TF_m_Ideal_AFB[k]->SetBinContent(i+1,diff_CurlV2TF);
      h_MC_Raw_Align_Twist_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Twist);
      h_MC_Raw_Align_Zexpansion_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Zexpansion);

      if (diff_Startup >0. ? total_plus[k][i] += diff_Startup*diff_Startup : total_minus[k][i] += diff_Startup*diff_Startup);
      if (diff_Bowing >0. ? total_plus[k][i] += diff_Bowing*diff_Bowing : total_minus[k][i] += diff_Bowing*diff_Bowing);
      if (diff_Elliptical >0. ? total_plus[k][i] += diff_Elliptical*diff_Elliptical : total_minus[k][i] += diff_Elliptical*diff_Elliptical);
      if (diff_Radial >0. ? total_plus[k][i] += diff_Radial*diff_Radial : total_minus[k][i] += diff_Radial*diff_Radial);
      if (diff_Sagitta >0. ? total_plus[k][i] += diff_Sagitta*diff_Sagitta : total_minus[k][i] += diff_Sagitta*diff_Startup);
      if (diff_Skew >0. ? total_plus[k][i] += diff_Skew*diff_Skew : total_minus[k][i] += diff_Skew*diff_Skew);
      if (diff_Telescope >0. ? total_plus[k][i] += diff_Telescope*diff_Telescope : total_minus[k][i] += diff_Telescope*diff_Telescope);
      if (diff_CurlV2TF >0. ? total_plus[k][i] += diff_CurlV2TF*diff_CurlV2TF : total_minus[k][i] += diff_CurlV2TF*diff_CurlV2TF);
      if (diff_Twist >0. ? total_plus[k][i] += diff_Twist*diff_Twist : total_minus[k][i] += diff_Twist*diff_Twist);
      if (diff_Zexpansion >0. ? total_plus[k][i] += diff_Zexpansion*diff_Zexpansion : total_minus[k][i] += diff_Zexpansion*diff_Zexpansion);

      if (diff_Startup >0. ? alignment_total_plus[k][i] += diff_Startup*diff_Startup : alignment_total_minus[k][i] += diff_Startup*diff_Startup);
      if (diff_Bowing >0. ? alignment_total_plus[k][i] += diff_Bowing*diff_Bowing : alignment_total_minus[k][i] += diff_Bowing*diff_Bowing);
      if (diff_Elliptical >0. ? alignment_total_plus[k][i] += diff_Elliptical*diff_Elliptical : alignment_total_minus[k][i] += diff_Elliptical*diff_Elliptical);
      if (diff_Radial >0. ? alignment_total_plus[k][i] += diff_Radial*diff_Radial : alignment_total_minus[k][i] += diff_Radial*diff_Radial);
      if (diff_Sagitta >0. ? alignment_total_plus[k][i] += diff_Sagitta*diff_Sagitta : alignment_total_minus[k][i] += diff_Sagitta*diff_Sagitta);
      if (diff_Skew >0. ? alignment_total_plus[k][i] += diff_Skew*diff_Skew : alignment_total_minus[k][i] += diff_Skew*diff_Skew);
      if (diff_Telescope >0. ? alignment_total_plus[k][i] += diff_Telescope*diff_Telescope : alignment_total_minus[k][i] += diff_Telescope*diff_Telescope);
      if (diff_CurlV2TF >0. ? alignment_total_plus[k][i] += diff_CurlV2TF*diff_CurlV2TF : alignment_total_minus[k][i] += diff_CurlV2TF*diff_CurlV2TF);
      if (diff_Twist >0. ? alignment_total_plus[k][i] += diff_Twist*diff_Twist : alignment_total_minus[k][i] += diff_Twist*diff_Twist);
      if (diff_Zexpansion >0. ? alignment_total_plus[k][i] += diff_Zexpansion*diff_Zexpansion : alignment_total_minus[k][i] += diff_Zexpansion*diff_Zexpansion);


      alignment_total_plus[k][i] = sqrt(alignment_total_plus[k][i]);
      alignment_total_minus[k][i] = -sqrt(alignment_total_minus[k][i]);
      if (alignment_total_plus[k][i] != 0){
	h_MC_Raw_alignment_total_plus[k]->SetBinContent(i+1,alignment_total_plus[k][i]);
	h_MC_Raw_alignment_total_plus[k]->SetBinError(i+1,0.000000001);
      }	
      if (alignment_total_minus[k][i] != 0){
	h_MC_Raw_alignment_total_minus[k]->SetBinContent(i+1,alignment_total_minus[k][i]);
	h_MC_Raw_alignment_total_minus[k]->SetBinError(i+1,0.000000001);
      }
      /*
      if (k == 0 && i == 0){ 
	cout<<"Misalignment (Raw Level)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    Mis  - Nominal   "<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Startup<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Bowing<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Elliptical<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Radial<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Sagitta<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Skew<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Telescope<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_CurlV2TF<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Twist<<"    \\\\    "<<endl;
//      cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Zexpansion<<"    \\\\    "<<endl;
      */

      for (int j=0;j<nb;j++){
	MC_UnDet_Align_Ideal_Forward[k][i] += Align_Ideal_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Ideal_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Ideal_Backward[k][i] += Align_Ideal_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Ideal_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Startup_Forward[k][i] += Align_Startup_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Startup_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Startup_Backward[k][i] += Align_Startup_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Startup_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Bowing_Forward[k][i] += Align_Bowing_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Bowing_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Bowing_Backward[k][i] += Align_Bowing_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Bowing_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Elliptical_Forward[k][i] += Align_Elliptical_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Elliptical_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Elliptical_Backward[k][i] += Align_Elliptical_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Elliptical_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Radial_Forward[k][i] += Align_Radial_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Radial_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Radial_Backward[k][i] += Align_Radial_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Radial_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);    
	MC_UnDet_Align_Sagitta_Forward[k][i] += Align_Sagitta_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Sagitta_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Sagitta_Backward[k][i] += Align_Sagitta_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Sagitta_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Skew_Forward[k][i] += Align_Skew_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Skew_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Skew_Backward[k][i] += Align_Skew_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Skew_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Telescope_Forward[k][i] += Align_Telescope_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Telescope_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Telescope_Backward[k][i] += Align_Telescope_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Telescope_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_CurlV2TF_Forward[k][i] += Align_CurlV2TF_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_CurlV2TF_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_CurlV2TF_Backward[k][i] += Align_CurlV2TF_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_CurlV2TF_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Twist_Forward[k][i] += Align_Twist_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Twist_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Twist_Backward[k][i] += Align_Twist_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Twist_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Zexpansion_Forward[k][i] += Align_Zexpansion_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Zexpansion_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Zexpansion_Backward[k][i] += Align_Zexpansion_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Zexpansion_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
       
	MC_NoFsr_Align_Ideal_Forward[k][i] += Align_Ideal_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Ideal_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Ideal_Backward[k][i] += Align_Ideal_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Ideal_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Startup_Forward[k][i] += Align_Startup_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Startup_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Startup_Backward[k][i] += Align_Startup_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Startup_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Bowing_Forward[k][i] += Align_Bowing_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Bowing_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Bowing_Backward[k][i] += Align_Bowing_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Bowing_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Elliptical_Forward[k][i] += Align_Elliptical_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Elliptical_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Elliptical_Backward[k][i] += Align_Elliptical_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Elliptical_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Radial_Forward[k][i] += Align_Radial_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Radial_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Radial_Backward[k][i] += Align_Radial_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Radial_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Sagitta_Forward[k][i] += Align_Sagitta_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Sagitta_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Sagitta_Backward[k][i] += Align_Sagitta_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Sagitta_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Skew_Forward[k][i] += Align_Skew_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Skew_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Skew_Backward[k][i] += Align_Skew_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Skew_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Telescope_Forward[k][i] += Align_Telescope_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Telescope_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Telescope_Backward[k][i] += Align_Telescope_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Telescope_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_CurlV2TF_Forward[k][i] += Align_CurlV2TF_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_CurlV2TF_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_CurlV2TF_Backward[k][i] += Align_CurlV2TF_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_CurlV2TF_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Twist_Forward[k][i] += Align_Twist_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Twist_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Twist_Backward[k][i] += Align_Twist_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Twist_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Zexpansion_Forward[k][i] += Align_Zexpansion_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Zexpansion_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Zexpansion_Backward[k][i] += Align_Zexpansion_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Zexpansion_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
		
      }
      MC_UnDet_Align_Ideal_AFB[i] = AFB(MC_UnDet_Align_Ideal_Forward[k][i],MC_UnDet_Align_Ideal_Backward[k][i]);
      MC_UnDet_Align_Startup_AFB[i] = AFB(MC_UnDet_Align_Startup_Forward[k][i],MC_UnDet_Align_Startup_Backward[k][i]);
      MC_UnDet_Align_Bowing_AFB[i] = AFB(MC_UnDet_Align_Bowing_Forward[k][i],MC_UnDet_Align_Bowing_Backward[k][i]);
      MC_UnDet_Align_Elliptical_AFB[i] = AFB(MC_UnDet_Align_Elliptical_Forward[k][i],MC_UnDet_Align_Elliptical_Backward[k][i]);
      MC_UnDet_Align_Radial_AFB[i] = AFB(MC_UnDet_Align_Radial_Forward[k][i],MC_UnDet_Align_Radial_Backward[k][i]);
      MC_UnDet_Align_Sagitta_AFB[i] = AFB(MC_UnDet_Align_Sagitta_Forward[k][i],MC_UnDet_Align_Sagitta_Backward[k][i]);
      MC_UnDet_Align_Skew_AFB[i] = AFB(MC_UnDet_Align_Skew_Forward[k][i],MC_UnDet_Align_Skew_Backward[k][i]);
      MC_UnDet_Align_Telescope_AFB[i] = AFB(MC_UnDet_Align_Telescope_Forward[k][i],MC_UnDet_Align_Telescope_Backward[k][i]);
      MC_UnDet_Align_CurlV2TF_AFB[i] = AFB(MC_UnDet_Align_CurlV2TF_Forward[k][i],MC_UnDet_Align_CurlV2TF_Backward[k][i]);
      MC_UnDet_Align_Twist_AFB[i] = AFB(MC_UnDet_Align_Twist_Forward[k][i],MC_UnDet_Align_Twist_Backward[k][i]);
      MC_UnDet_Align_Zexpansion_AFB[i] = AFB(MC_UnDet_Align_Zexpansion_Forward[k][i],MC_UnDet_Align_Zexpansion_Backward[k][i]);

      diff_Startup = 0;
      diff_Bowing = 0;
      diff_Elliptical = 0;
      diff_Radial = 0;
      diff_Sagitta = 0;
      diff_Skew = 0;
      diff_Telescope = 0;
      diff_CurlV2TF = 0;
      diff_Twist = 0;
      diff_Zexpansion = 0;
      diff_Startup = MC_UnDet_Align_Startup_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_Bowing = MC_UnDet_Align_Bowing_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_Elliptical = MC_UnDet_Align_Elliptical_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_Radial = MC_UnDet_Align_Radial_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_Sagitta = MC_UnDet_Align_Sagitta_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_Skew = MC_UnDet_Align_Skew_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_Telescope = MC_UnDet_Align_Telescope_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_CurlV2TF = MC_UnDet_Align_CurlV2TF_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_Twist = MC_UnDet_Align_Twist_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_Zexpansion = MC_UnDet_Align_Zexpansion_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];

      h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Bowing);
      h_MC_Unfolded_UnDet_Align_Bowing_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Bowing);
      h_MC_Unfolded_UnDet_Align_Elliptical_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Elliptical);
      h_MC_Unfolded_UnDet_Align_Radial_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Radial);
      h_MC_Unfolded_UnDet_Align_Sagitta_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Sagitta);
      h_MC_Unfolded_UnDet_Align_Skew_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Skew);
      h_MC_Unfolded_UnDet_Align_Telescope_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Telescope);
      h_MC_Unfolded_UnDet_Align_CurlV2TF_m_Ideal_AFB[k]->SetBinContent(i+1,diff_CurlV2TF);
      h_MC_Unfolded_UnDet_Align_Twist_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Twist);
      h_MC_Unfolded_UnDet_Align_Zexpansion_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Zexpansion);

      if (diff_Startup >0. ? total_plus_undet[k][i] += diff_Startup*diff_Startup : total_minus_undet[k][i] += diff_Startup*diff_Startup);
      if (diff_Bowing >0. ? total_plus_undet[k][i] += diff_Bowing*diff_Bowing : total_minus_undet[k][i] += diff_Bowing*diff_Bowing);
      if (diff_Elliptical >0. ? total_plus_undet[k][i] += diff_Elliptical*diff_Elliptical : total_minus_undet[k][i] += diff_Elliptical*diff_Elliptical);
      if (diff_Radial >0. ? total_plus_undet[k][i] += diff_Radial*diff_Radial : total_minus_undet[k][i] += diff_Radial*diff_Radial);
      if (diff_Sagitta >0. ? total_plus_undet[k][i] += diff_Sagitta*diff_Sagitta : total_minus_undet[k][i] += diff_Sagitta*diff_Sagitta);
      if (diff_Skew >0. ? total_plus_undet[k][i] += diff_Skew*diff_Skew : total_minus_undet[k][i] += diff_Skew*diff_Skew);
      if (diff_Telescope >0. ? total_plus_undet[k][i] += diff_Telescope*diff_Telescope : total_minus_undet[k][i] += diff_Telescope*diff_Telescope);
      if (diff_CurlV2TF >0. ? total_plus_undet[k][i] += diff_CurlV2TF*diff_CurlV2TF : total_minus_undet[k][i] += diff_CurlV2TF*diff_CurlV2TF);
      if (diff_Twist >0. ? total_plus_undet[k][i] += diff_Twist*diff_Twist : total_minus_undet[k][i] += diff_Twist*diff_Twist);
      if (diff_Zexpansion >0. ? total_plus_undet[k][i] += diff_Zexpansion*diff_Zexpansion : total_minus_undet[k][i] += diff_Zexpansion*diff_Zexpansion);


      if (diff_Startup >0. ? alignment_total_plus_undet[k][i] += diff_Startup*diff_Startup : alignment_total_minus_undet[k][i] += diff_Startup*diff_Startup);
      if (diff_Bowing >0. ? alignment_total_plus_undet[k][i] += diff_Bowing*diff_Bowing : alignment_total_minus_undet[k][i] += diff_Bowing*diff_Bowing);
      if (diff_Elliptical >0. ? alignment_total_plus_undet[k][i] += diff_Elliptical*diff_Elliptical : alignment_total_minus_undet[k][i] += diff_Elliptical*diff_Elliptical);
      if (diff_Radial >0. ? alignment_total_plus_undet[k][i] += diff_Radial*diff_Radial : alignment_total_minus_undet[k][i] += diff_Radial*diff_Radial);
      if (diff_Sagitta >0. ? alignment_total_plus_undet[k][i] += diff_Sagitta*diff_Sagitta : alignment_total_minus_undet[k][i] += diff_Sagitta*diff_Sagitta);
      if (diff_Skew >0. ? alignment_total_plus_undet[k][i] += diff_Skew*diff_Skew : alignment_total_minus_undet[k][i] += diff_Skew*diff_Skew);
      if (diff_Telescope >0. ? alignment_total_plus_undet[k][i] += diff_Telescope*diff_Telescope : alignment_total_minus_undet[k][i] += diff_Telescope*diff_Telescope);
      if (diff_CurlV2TF >0. ? alignment_total_plus_undet[k][i] += diff_CurlV2TF*diff_CurlV2TF : alignment_total_minus_undet[k][i] += diff_CurlV2TF*diff_CurlV2TF);
      if (diff_Twist >0. ? alignment_total_plus_undet[k][i] += diff_Twist*diff_Twist : alignment_total_minus_undet[k][i] += diff_Twist*diff_Twist);
      if (diff_Zexpansion >0. ? alignment_total_plus_undet[k][i] += diff_Zexpansion*diff_Zexpansion : alignment_total_minus_undet[k][i] += diff_Zexpansion*diff_Zexpansion);

      alignment_total_plus_undet[k][i] = sqrt(alignment_total_plus_undet[k][i]);
      alignment_total_minus_undet[k][i] = -sqrt(alignment_total_minus_undet[k][i]);
      if (alignment_total_plus_undet[k][i] != 0){
	h_MC_Bare_alignment_total_plus[k]->SetBinContent(i+1,alignment_total_plus_undet[k][i]);
	h_MC_Bare_alignment_total_plus[k]->SetBinError(i+1,0.00000001);
      }
      if (alignment_total_minus_undet[k][i] != 0){
	h_MC_Bare_alignment_total_minus[k]->SetBinContent(i+1,alignment_total_minus_undet[k][i]);
	h_MC_Bare_alignment_total_minus[k]->SetBinError(i+1,0.00000001);
      }

      /*
      if (k == 0 && i == 0){ 
	cout<<"Misalignment (Bare lepton Level)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    Mis  - Nominal   "<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Startup<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Bowing<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Elliptical<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Radial<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Sagitta<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Skew<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Telescope<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_CurlV2TF<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Twist<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Zexpansion<<"    \\\\    "<<endl;
      */


      MC_NoFsr_Align_Ideal_AFB[i] = AFB(MC_NoFsr_Align_Ideal_Forward[k][i],MC_NoFsr_Align_Ideal_Backward[k][i]);
      MC_NoFsr_Align_Startup_AFB[i] = AFB(MC_NoFsr_Align_Startup_Forward[k][i],MC_NoFsr_Align_Startup_Backward[k][i]);
      MC_NoFsr_Align_Bowing_AFB[i] = AFB(MC_NoFsr_Align_Bowing_Forward[k][i],MC_NoFsr_Align_Bowing_Backward[k][i]);
      MC_NoFsr_Align_Elliptical_AFB[i] = AFB(MC_NoFsr_Align_Elliptical_Forward[k][i],MC_NoFsr_Align_Elliptical_Backward[k][i]);
      MC_NoFsr_Align_Radial_AFB[i] = AFB(MC_NoFsr_Align_Radial_Forward[k][i],MC_NoFsr_Align_Radial_Backward[k][i]);
      MC_NoFsr_Align_Sagitta_AFB[i] = AFB(MC_NoFsr_Align_Sagitta_Forward[k][i],MC_NoFsr_Align_Sagitta_Backward[k][i]);
      MC_NoFsr_Align_Skew_AFB[i] = AFB(MC_NoFsr_Align_Skew_Forward[k][i],MC_NoFsr_Align_Skew_Backward[k][i]);
      MC_NoFsr_Align_Telescope_AFB[i] = AFB(MC_NoFsr_Align_Telescope_Forward[k][i],MC_NoFsr_Align_Telescope_Backward[k][i]);
      MC_NoFsr_Align_CurlV2TF_AFB[i] = AFB(MC_NoFsr_Align_CurlV2TF_Forward[k][i],MC_NoFsr_Align_CurlV2TF_Backward[k][i]);
      MC_NoFsr_Align_Twist_AFB[i] = AFB(MC_NoFsr_Align_Twist_Forward[k][i],MC_NoFsr_Align_Twist_Backward[k][i]);
      MC_NoFsr_Align_Zexpansion_AFB[i] = AFB(MC_NoFsr_Align_Zexpansion_Forward[k][i],MC_NoFsr_Align_Zexpansion_Backward[k][i]);

      diff_Startup = 0;
      diff_Bowing = 0;
      diff_Elliptical = 0;
      diff_Radial = 0;
      diff_Sagitta = 0;
      diff_Skew = 0;
      diff_Telescope = 0;
      diff_CurlV2TF = 0;
      diff_Twist = 0;
      diff_Zexpansion = 0;
      diff_Startup = MC_NoFsr_Align_Startup_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_Bowing = MC_NoFsr_Align_Bowing_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_Elliptical = MC_NoFsr_Align_Elliptical_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_Radial = MC_NoFsr_Align_Radial_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_Sagitta = MC_NoFsr_Align_Sagitta_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_Skew = MC_NoFsr_Align_Skew_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_Telescope = MC_NoFsr_Align_Telescope_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_CurlV2TF = MC_NoFsr_Align_CurlV2TF_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_Twist = MC_NoFsr_Align_Twist_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_Zexpansion = MC_NoFsr_Align_Zexpansion_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];

      h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Bowing);
      h_MC_Unfolded_NoFsr_Align_Bowing_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Bowing);
      h_MC_Unfolded_NoFsr_Align_Elliptical_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Elliptical);
      h_MC_Unfolded_NoFsr_Align_Radial_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Radial);
      h_MC_Unfolded_NoFsr_Align_Sagitta_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Sagitta);
      h_MC_Unfolded_NoFsr_Align_Skew_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Skew);
      h_MC_Unfolded_NoFsr_Align_Telescope_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Telescope);
      h_MC_Unfolded_NoFsr_Align_CurlV2TF_m_Ideal_AFB[k]->SetBinContent(i+1,diff_CurlV2TF);
      h_MC_Unfolded_NoFsr_Align_Twist_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Twist);
      h_MC_Unfolded_NoFsr_Align_Zexpansion_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Zexpansion);

      if (diff_Startup >0. ? total_plus_nofsr[k][i] += diff_Startup*diff_Startup : total_minus_nofsr[k][i] += diff_Startup*diff_Startup);
      if (diff_Bowing >0. ? total_plus_nofsr[k][i] += diff_Bowing*diff_Bowing : total_minus_nofsr[k][i] += diff_Bowing*diff_Bowing);
      if (diff_Elliptical >0. ? total_plus_nofsr[k][i] += diff_Elliptical*diff_Elliptical : total_minus_nofsr[k][i] += diff_Elliptical*diff_Elliptical);
      if (diff_Radial >0. ? total_plus_nofsr[k][i] += diff_Radial*diff_Radial : total_minus_nofsr[k][i] += diff_Radial*diff_Radial);
      if (diff_Sagitta >0. ? total_plus_nofsr[k][i] += diff_Sagitta*diff_Sagitta : total_minus_nofsr[k][i] += diff_Sagitta*diff_Sagitta);
      if (diff_Skew >0. ? total_plus_nofsr[k][i] += diff_Skew*diff_Skew : total_minus_nofsr[k][i] += diff_Skew*diff_Skew);
      if (diff_Telescope >0. ? total_plus_nofsr[k][i] += diff_Telescope*diff_Telescope : total_minus_nofsr[k][i] += diff_Telescope*diff_Telescope);
      if (diff_CurlV2TF >0. ? total_plus_nofsr[k][i] += diff_CurlV2TF*diff_CurlV2TF : total_minus_nofsr[k][i] += diff_CurlV2TF*diff_CurlV2TF);
      if (diff_Twist >0. ? total_plus_nofsr[k][i] += diff_Twist*diff_Twist : total_minus_nofsr[k][i] += diff_Twist*diff_Twist);
      if (diff_Zexpansion >0. ? total_plus_nofsr[k][i] += diff_Zexpansion*diff_Zexpansion : total_minus_nofsr[k][i] += diff_Zexpansion*diff_Zexpansion);

      if (diff_Startup >0. ? alignment_total_plus_nofsr[k][i] += diff_Startup*diff_Startup : alignment_total_minus_nofsr[k][i] += diff_Startup*diff_Startup);
      if (diff_Bowing >0. ? alignment_total_plus_nofsr[k][i] += diff_Bowing*diff_Bowing : alignment_total_minus_nofsr[k][i] += diff_Bowing*diff_Bowing);
      if (diff_Elliptical >0. ? alignment_total_plus_nofsr[k][i] += diff_Elliptical*diff_Elliptical : alignment_total_minus_nofsr[k][i] += diff_Elliptical*diff_Elliptical);
      if (diff_Radial >0. ? alignment_total_plus_nofsr[k][i] += diff_Radial*diff_Radial : alignment_total_minus_nofsr[k][i] += diff_Radial*diff_Radial);
      if (diff_Sagitta >0. ? alignment_total_plus_nofsr[k][i] += diff_Sagitta*diff_Sagitta : alignment_total_minus_nofsr[k][i] += diff_Sagitta*diff_Sagitta);
      if (diff_Skew >0. ? alignment_total_plus_nofsr[k][i] += diff_Skew*diff_Skew : alignment_total_minus_nofsr[k][i] += diff_Skew*diff_Skew);
      if (diff_Telescope >0. ? alignment_total_plus_nofsr[k][i] += diff_Telescope*diff_Telescope : alignment_total_minus_nofsr[k][i] += diff_Telescope*diff_Telescope);
      if (diff_CurlV2TF >0. ? alignment_total_plus_nofsr[k][i] += diff_CurlV2TF*diff_CurlV2TF : alignment_total_minus_nofsr[k][i] += diff_CurlV2TF*diff_CurlV2TF);
      if (diff_Twist >0. ? alignment_total_plus_nofsr[k][i] += diff_Twist*diff_Twist : alignment_total_minus_nofsr[k][i] += diff_Twist*diff_Twist);
      if (diff_Zexpansion >0. ? alignment_total_plus_nofsr[k][i] += diff_Zexpansion*diff_Zexpansion : alignment_total_minus_nofsr[k][i] += diff_Zexpansion*diff_Zexpansion);

      cout<<diff_Startup<<" "<<diff_Bowing<<" "<<diff_Elliptical<<" "<<diff_Radial<<" "<<diff_Sagitta<<" "<<diff_Skew<<" "<<diff_Telescope<<" "<<diff_CurlV2TF<<" "<<diff_Twist<<" "<<diff_Zexpansion <<endl;


      alignment_total_plus_nofsr[k][i] = sqrt(alignment_total_plus_nofsr[k][i]);
      alignment_total_minus_nofsr[k][i] = -sqrt(alignment_total_minus_nofsr[k][i]);
      if (alignment_total_plus_nofsr[k][i]){
	h_MC_Born_alignment_total_plus[k]->SetBinContent(i+1,alignment_total_plus_nofsr[k][i]);
	h_MC_Born_alignment_total_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (alignment_total_minus_nofsr[k][i]){
	h_MC_Born_alignment_total_minus[k]->SetBinContent(i+1,alignment_total_minus_nofsr[k][i]);
	h_MC_Born_alignment_total_minus[k]->SetBinError(i+1,0.000000001);
      }

      /*     
      if (k == 0 && i == 0){ 
	cout<<"Misalignment (Born lepton Level)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    Mis  - Nominal   "<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Startup<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Bowing<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Elliptical<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Radial<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Sagitta<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Skew<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Telescope<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_CurlV2TF<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Twist<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Zexpansion<<"    \\\\    "<<endl;
      */

    }//eo alignment loop


    for (int i=0;i<nb;i++){ //pdf loop
      afb_0 = AFB(hMeasCos_M_Y_Forward_PDF_ct10[k][0]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_ct10[k][0]->GetBinContent(i+1));
      afb_0_mstw = AFB(hMeasCos_M_Y_Forward_PDF_mstw[k][0]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_mstw[k][0]->GetBinContent(i+1));


      afb_alphas0 = AFB(hMeasCos_M_Y_Forward_PDF_alpha_s[k][0]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_alpha_s[k][0]->GetBinContent(i+1));
      afb_alphas5 = AFB(hMeasCos_M_Y_Forward_PDF_alpha_s[k][5]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_alpha_s[k][5]->GetBinContent(i+1));
      afb_alphas10 = AFB(hMeasCos_M_Y_Forward_PDF_alpha_s[k][10]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_alpha_s[k][10]->GetBinContent(i+1));  
      h_Delta_AFB_alphas_PLUS[k]->SetBinContent(i+1,afb_alphas10-afb_alphas5);
      h_Delta_AFB_alphas_MINUS[k]->SetBinContent(i+1,afb_alphas0-afb_alphas5);

      for (int pdfindex = 0; pdfindex<n_ct; pdfindex++){
	for (int j=0;j<nb;j++){
	  MC_Unfolded_UnDet_Forward_PDF_ct10[k][i][pdfindex] += Inv_Response_UnDetector_Forward_PDF_ct10[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_PDF_ct10[k][pdfindex]->GetBinContent(j+1);
	  MC_Unfolded_UnDet_Backward_PDF_ct10[k][i][pdfindex] += Inv_Response_UnDetector_Backward_PDF_ct10[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_PDF_ct10[k][pdfindex]->GetBinContent(j+1);
	}
	MC_Unfolded_UnDet_AFB_PDF_ct10[i][pdfindex] = AFB(MC_Unfolded_UnDet_Forward_PDF_ct10[k][i][pdfindex],MC_Unfolded_UnDet_Backward_PDF_ct10[k][i][pdfindex]);	
      }

      afb_0_undet = MC_Unfolded_UnDet_AFB_PDF_ct10[i][0];

	for (int pdfindex=1; pdfindex<n_ct; pdfindex+=2){
	  afb_p = AFB(hMeasCos_M_Y_Forward_PDF_ct10[k][pdfindex]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_ct10[k][pdfindex]->GetBinContent(i+1));
	  afb_m = AFB(hMeasCos_M_Y_Forward_PDF_ct10[k][pdfindex+1]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_ct10[k][pdfindex+1]->GetBinContent(i+1));
	  delta_plus = afb_p - afb_0;
	  delta_minus = afb_m - afb_0;
	  arrayformax_p[0] = delta_plus;
	  arrayformax_p[1] = delta_minus;
	  arrayformax_p[2] = 0;	  
	  arrayformax_m[0] = -delta_plus;
	  arrayformax_m[1] = -delta_minus;
	  arrayformax_m[2] = 0;
	  DeltaXmaxPlus[i][k] += pow(TMath::MaxElement(3,arrayformax_p),2);
	  DeltaXmaxMinus[i][k] += pow(TMath::MaxElement(3,arrayformax_m),2);

	  afb_p_undet = MC_Unfolded_UnDet_AFB_PDF_ct10[i][pdfindex];
	  afb_m_undet = MC_Unfolded_UnDet_AFB_PDF_ct10[i][pdfindex+1];
	  delta_plus_undet = afb_p_undet - afb_0_undet;
	  delta_minus_undet = afb_m_undet - afb_0_undet;
	  arrayformax_p_undet[0] = delta_plus_undet;
	  arrayformax_p_undet[1] = delta_minus_undet;
	  arrayformax_p_undet[2] = 0;	  
	  arrayformax_m_undet[0] = -delta_plus_undet;
	  arrayformax_m_undet[1] = -delta_minus_undet;
	  arrayformax_m_undet[2] = 0;
	  DeltaXmaxPlus_undet[i][k] += pow(TMath::MaxElement(3,arrayformax_p_undet),2);
	  DeltaXmaxMinus_undet[i][k] += pow(TMath::MaxElement(3,arrayformax_m_undet),2);
	}
	DeltaXmaxPlus[i][k] = sqrt(DeltaXmaxPlus[i][k]);
	DeltaXmaxMinus[i][k] = sqrt(DeltaXmaxMinus[i][k]);
	h_DeltaXmaxPlus_ct10[k]->SetBinContent(i+1,DeltaXmaxPlus[i][k]);
	h_DeltaXmaxMinus_ct10[k]->SetBinContent(i+1,DeltaXmaxMinus[i][k]);
	float DeltaX_CT10_ALPHAS_PLUS = sqrt(pow(DeltaXmaxPlus[i][k],2)+pow(afb_alphas10-afb_alphas5,2));
	float DeltaX_CT10_ALPHAS_MINUS = sqrt(pow(DeltaXmaxMinus[i][k],2)+pow(afb_alphas0-afb_alphas5,2));
	h_DeltaX_CT10_ALPHAS_PLUS[k]->SetBinContent(i+1,DeltaX_CT10_ALPHAS_PLUS);
	h_DeltaX_CT10_ALPHAS_MINUS[k]->SetBinContent(i+1,DeltaX_CT10_ALPHAS_MINUS);

	DeltaXmaxPlus_undet[i][k] = sqrt(DeltaXmaxPlus_undet[i][k]);
	DeltaXmaxMinus_undet[i][k] = sqrt(DeltaXmaxMinus_undet[i][k]);
	h_DeltaXmaxPlus_undet_ct10[k]->SetBinContent(i+1,DeltaXmaxPlus_undet[i][k]);
	h_DeltaXmaxMinus_undet_ct10[k]->SetBinContent(i+1,DeltaXmaxMinus_undet[i][k]);
	//	float DeltaX_CT10_ALPHAS_PLUS = sqrt(pow(DeltaXmaxPlus[i][k],2)+pow(afb_alphas10-afb_alphas5,2));
	//	float DeltaX_CT10_ALPHAS_MINUS = sqrt(pow(DeltaXmaxMinus[i][k],2)+pow(afb_alphas0-afb_alphas5,2));
	//	h_DeltaX_CT10_ALPHAS_PLUS[k]->SetBinContent(i+1,DeltaX_CT10_ALPHAS_PLUS);
	//	h_DeltaX_CT10_ALPHAS_MINUS[k]->SetBinContent(i+1,DeltaX_CT10_ALPHAS_MINUS);

	DeltaXmaxPlus[i][k] = 0;
	DeltaXmaxMinus[i][k] = 0;
	for (int pdfindex=1; pdfindex<n_mstw; pdfindex+=2){
	  afb_p = AFB(hMeasCos_M_Y_Forward_PDF_mstw[k][pdfindex]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_mstw[k][pdfindex]->GetBinContent(i+1));
	  afb_m = AFB(hMeasCos_M_Y_Forward_PDF_mstw[k][pdfindex+1]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_mstw[k][pdfindex+1]->GetBinContent(i+1));
	  delta_plus = afb_p - afb_0_mstw;
	  delta_minus = afb_m - afb_0_mstw;
	  //cout<<afb_0_mstw<<endl;
	  arrayformax_p[0] = delta_plus;
	  arrayformax_p[1] = delta_minus;
	  arrayformax_p[2] = 0;	  
	  arrayformax_m[0] = -delta_plus;
	  arrayformax_m[1] = -delta_minus;
	  arrayformax_m[2] = 0;
	  DeltaXmaxPlus[i][k] += pow(TMath::MaxElement(3,arrayformax_p),2);
	  DeltaXmaxMinus[i][k] += pow(TMath::MaxElement(3,arrayformax_m),2);
	}
	DeltaXmaxPlus[i][k] = sqrt(DeltaXmaxPlus[i][k]);
	DeltaXmaxMinus[i][k] = sqrt(DeltaXmaxMinus[i][k]);
	h_DeltaXmaxPlus_mstw[k]->SetBinContent(i+1,DeltaXmaxPlus[i][k]);
	h_DeltaXmaxMinus_mstw[k]->SetBinContent(i+1,DeltaXmaxMinus[i][k]);


	float average_afb = 0;
	for (int pdfindex=1;pdfindex<n_nnpdf;pdfindex++){
	  afb_nnpdf = AFB(hMeasCos_M_Y_Forward_PDF_nnpdf[k][pdfindex]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_nnpdf[k][pdfindex]->GetBinContent(i+1));
	  average_afb += afb_nnpdf;
	}
	average_afb = average_afb/((n_nnpdf-1)*1.);
	for (int pdfindex=1;pdfindex<n_nnpdf;pdfindex++){
	  afb_nnpdf = AFB(hMeasCos_M_Y_Forward_PDF_nnpdf[k][pdfindex]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_nnpdf[k][pdfindex]->GetBinContent(i+1));
	  sigma[i][k] += pow(afb_nnpdf - average_afb,2);
	}
	sigma[i][k] = sigma[i][k]/(n_nnpdf*1.-2.);
	sigma[i][k] = sqrt(sigma[i][k]);
	h_sigma[k]->SetBinContent(i+1,sigma[i][k]);

	float envelope_p = TMath::Max(afb_0+DeltaX_CT10_ALPHAS_PLUS,average_afb+sigma[i][k]);
	float envelope_m = TMath::Max(afb_0-DeltaX_CT10_ALPHAS_MINUS,average_afb-sigma[i][k]);
	float envelope_pp = TMath::Max(envelope_p,afb_0_mstw+DeltaXmaxPlus[i][k]);
	float envelope_mm = TMath::Max(envelope_m,afb_0_mstw-DeltaXmaxMinus[i][k]);

	float envelope_mean = (envelope_pp + envelope_mm)/2.;
	float diff_env = envelope_pp-envelope_mean;
	h_envelope_sigma[k]->SetBinContent(i+1,diff_env);
	h_envelope_sigma_plus[k]->SetBinContent(i+1,diff_env);
	h_envelope_sigma_minus[k]->SetBinContent(i+1,-diff_env);
	h_envelope_sigma_plus[k]->SetBinError(i+1,0.0000001);
	h_envelope_sigma_minus[k]->SetBinError(i+1,0.0000001);

	total_plus[k][i] += diff_env*diff_env; 
	total_plus[k][i] = sqrt(total_plus[k][i]);
	total_minus[k][i] += diff_env*diff_env;
	total_minus[k][i] = -1.*sqrt(total_minus[k][i]);
	h_total_plus[k]->SetBinContent(i+1,total_plus[k][i]);
	h_total_minus[k]->SetBinContent(i+1,total_minus[k][i]);	
	h_total_plus[k]->SetBinError(i+1,0.000000001);
	h_total_minus[k]->SetBinError(i+1,0.000000001);

	total_plus_undet[k][i] += diff_env*diff_env; 
	total_plus_undet[k][i] = sqrt(total_plus_undet[k][i]);
	total_minus_undet[k][i] += diff_env*diff_env;
	total_minus_undet[k][i] = -1.*sqrt(total_minus_undet[k][i]);	
	h_total_plus_undet[k]->SetBinContent(i+1,total_plus_undet[k][i]);
	h_total_minus_undet[k]->SetBinContent(i+1,total_minus_undet[k][i]);	
	h_total_plus_undet[k]->SetBinError(i+1,0.00000000001);
	h_total_minus_undet[k]->SetBinError(i+1,0.00000000001);

	total_plus_nofsr[k][i] += diff_env*diff_env; 
	total_plus_nofsr[k][i] = sqrt(total_plus_nofsr[k][i]);
	total_minus_nofsr[k][i] += diff_env*diff_env;
	total_minus_nofsr[k][i] = -1.*sqrt(total_minus_nofsr[k][i]);	
	h_total_plus_nofsr[k]->SetBinContent(i+1,total_plus_nofsr[k][i]);
	h_total_minus_nofsr[k]->SetBinContent(i+1,total_minus_nofsr[k][i]);
	h_total_plus_nofsr[k]->SetBinError(i+1,0.00000001);
	h_total_minus_nofsr[k]->SetBinError(i+1,0.00000001);

	/*
      if (k == 0 && i == 0){ 
	cout<<"PDF (Raw Level)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)     Envelope   "<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
      cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_env<<"    \\\\    "<<endl;
	*/
    }//eof pdf loop
  }
  TCanvas *ca_0 = new TCanvas();
  ca_0->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    ca_0->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    hUnDetectorCos_M_Y_Forward[k]->SetLineColor(4);
    hUnDetectorCos_M_Y_Forward[k]->SetLineWidth(2);
    hUnDetectorCos_M_Y_Forward[k]->Scale(h_Unfolded_UnDet_Forward[k]->Integral()*1./hUnDetectorCos_M_Y_Forward[k]->Integral()*1.);
    hUnDetectorCos_M_Y_Forward[k]->GetXaxis()->SetTitle("Forward M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    hUnDetectorCos_M_Y_Forward[k]->SetTitle(name_h);
    hUnDetectorCos_M_Y_Forward[k]->Draw();
    //      hDataMeasCos_M_Y_Forward[k]->Scale(h_Unfolded_UnDet_Forward[k]->Integral()*1./hDataMeasCos_M_Y_Forward[k]->Integral()*1.);
    hDataMeasCos_M_Y_Forward[k]->SetMarkerStyle(8);
    hDataMeasCos_M_Y_Forward[k]->SetMarkerColor(1);
    hDataMeasCos_M_Y_Forward[k]->SetLineWidth(2);
    hDataMeasCos_M_Y_Forward[k]->Draw("e1sames");
    h_Unfolded_UnDet_Forward[k]->SetMarkerStyle(4);
    h_Unfolded_UnDet_Forward[k]->SetMarkerColor(2);
    h_Unfolded_UnDet_Forward[k]->SetLineColor(2);
    h_Unfolded_UnDet_Forward[k]->SetLineWidth(2);
    h_Unfolded_UnDet_Forward[k]->Draw("e1sames");
  }
  ca_0->SaveAs("forward_data.C");
  
  TCanvas *ca_1 = new TCanvas();
  ca_1->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    ca_1->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    hUnDetectorCos_M_Y_Backward[k]->SetLineColor(4);
    hUnDetectorCos_M_Y_Backward[k]->SetLineWidth(2);
    hUnDetectorCos_M_Y_Backward[k]->Scale(h_Unfolded_UnDet_Backward[k]->Integral()*1./hUnDetectorCos_M_Y_Backward[k]->Integral()*1.);
    hUnDetectorCos_M_Y_Backward[k]->GetXaxis()->SetTitle("Backward M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    hUnDetectorCos_M_Y_Backward[k]->SetTitle(name_h);
    hUnDetectorCos_M_Y_Backward[k]->Draw();
    //      hDataMeasCos_M_Y_Forward[k]->Scale(h_Unfolded_UnDet_Forward[k]->Integral()*1./hDataMeasCos_M_Y_Forward[k]->Integral()*1.);
    hDataMeasCos_M_Y_Backward[k]->SetMarkerStyle(8);
    hDataMeasCos_M_Y_Backward[k]->SetMarkerColor(1);
    hDataMeasCos_M_Y_Backward[k]->SetLineWidth(2);
    hDataMeasCos_M_Y_Backward[k]->Draw("e1sames");
    h_Unfolded_UnDet_Backward[k]->SetMarkerStyle(4);
    h_Unfolded_UnDet_Backward[k]->SetMarkerColor(2);
    h_Unfolded_UnDet_Backward[k]->SetLineColor(2);
    h_Unfolded_UnDet_Backward[k]->SetLineWidth(2);
    h_Unfolded_UnDet_Backward[k]->Draw("e1sames");
  }
  ca_1->SaveAs("backward_data.C");


  TCanvas *c1 = new TCanvas();
  c1->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c1->cd(k+1);
    gPad->SetLogx();  
    h_MC_Raw_AFB[k]->GetYaxis()->SetRangeUser(-0.2,0.4);
    h_MC_Raw_AFB[k]->SetLineWidth(2);
    h_MC_Raw_AFB[k]->SetLineColor(4);
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Raw_AFB[k]->SetTitle(name_h);
    h_MC_Raw_AFB[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_MC_Raw_AFB[k]->GetYaxis()->SetTitle("A_{FB}");
    h_MC_Raw_AFB[k]->Draw("e1");
    /*
      h_MC_UnDet_AFB[k]->GetYaxis()->SetRangeUser(-0.2,0.4);
      h_MC_UnDet_AFB[k]->SetLineColor(4);
      h_MC_UnDet_AFB[k]->SetLineWidth(2);
      h_MC_UnDet_AFB[k]->SetLineStyle(2);
      h_MC_UnDet_AFB[k]->Draw();
    */
    h_Raw_AFB[k]->SetMarkerStyle(8);
    h_Raw_AFB[k]->SetLineWidth(2);
    h_Raw_AFB[k]->Draw("e1sames");
    /*
      h_Unfolded_UnDet_AFB[k]->SetMarkerStyle(25);
      h_Unfolded_UnDet_AFB[k]->SetMarkerColor(2);
      h_Unfolded_UnDet_AFB[k]->SetLineColor(2);
      h_Unfolded_UnDet_AFB[k]->SetLineWidth(2);
      h_Unfolded_UnDet_AFB[k]->Draw("e1sames");
    */
  }
  c1->SaveAs("afb_raw.C");
 
  TCanvas *c2 = new TCanvas();
  c2->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c2->cd(k+1);
    gPad->SetLogx(); 
    h_MC_UnDet_AFB[k]->GetYaxis()->SetRangeUser(-0.2,0.4); 
    h_MC_UnDet_AFB[k]->SetLineColor(4);
    h_MC_UnDet_AFB[k]->SetLineWidth(2);
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_UnDet_AFB[k]->SetTitle(name_h);
    h_MC_UnDet_AFB[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_MC_UnDet_AFB[k]->GetYaxis()->SetTitle("A_{FB}");
    h_MC_UnDet_AFB[k]->Draw();
    h_Unfolded_UnDet_AFB[k]->SetMarkerColor(1);
    h_Unfolded_UnDet_AFB[k]->SetLineColor(1);
    h_Unfolded_UnDet_AFB[k]->SetLineWidth(2);
    h_Unfolded_UnDet_AFB[k]->SetMarkerStyle(8);
    h_Unfolded_UnDet_AFB[k]->Draw("e1sames");
  }
  c2->SaveAs("afb_unfolded.C");	

  TCanvas *c3 = new TCanvas();
  c3->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c3->cd(k+1);
    gPad->SetLogx();
    h_MC_NoFsr_AFB[k]->GetYaxis()->SetRangeUser(-0.2,0.4);
    h_MC_NoFsr_AFB[k]->SetLineColor(4);
    h_MC_NoFsr_AFB[k]->SetLineWidth(2);
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_NoFsr_AFB[k]->SetTitle(name_h);
    h_MC_NoFsr_AFB[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_MC_NoFsr_AFB[k]->GetYaxis()->SetTitle("A_{FB}");
    h_MC_NoFsr_AFB[k]->Draw();
    h_Unfolded_NoFsr_AFB[k]->SetMarkerStyle(25);
    h_Unfolded_NoFsr_AFB[k]->SetLineWidth(2);
    h_Unfolded_NoFsr_AFB[k]->Draw("e1sames");
  }
  c3->SaveAs("afb_unfolded_preFSR.C");

  
  TCanvas *c4 = new TCanvas();
  c4->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c4->cd(k+1);
    gPad->SetLogx();  
    h_MC_Raw_AFB[k]->GetYaxis()->SetRangeUser(-0.2,0.4);
    h_MC_Raw_AFB[k]->SetLineWidth(2);
    h_MC_Raw_AFB[k]->Draw();
    h_MC_NoFsr_AFB[k]->SetLineColor(4);
    h_MC_NoFsr_AFB[k]->SetLineWidth(2);
    h_MC_NoFsr_AFB[k]->SetLineStyle(2);
    h_MC_NoFsr_AFB[k]->Draw("sames");
    h_Raw_AFB[k]->SetMarkerStyle(8);
    h_Raw_AFB[k]->SetLineWidth(2);
    h_Raw_AFB[k]->Draw("e1sames");
    h_Unfolded_NoFsr_AFB[k]->SetMarkerStyle(20);
    h_Unfolded_NoFsr_AFB[k]->SetMarkerColor(1);
    h_Unfolded_NoFsr_AFB[k]->SetLineColor(1);
    h_Unfolded_NoFsr_AFB[k]->SetLineWidth(2);
    h_Unfolded_NoFsr_AFB[k]->Draw("e1sames");
  }
  c1->SaveAs("afb_raw_nofsr.C");
 


  TCanvas *c0_1 = new TCanvas();
  c0_1->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c0_1->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    hMeasCos_M_Y_Forward[k]->Scale(h_Closure_Unfolded_UnDet_Forward[k]->Integral()*1./hMeasCos_M_Y_Forward[k]->Integral()*1.);
    hMeasCos_M_Y_Forward[k]->Draw();
    hUnDetectorCos_M_Y_Forward[k]->SetLineColor(4);
    hUnDetectorCos_M_Y_Forward[k]->Scale(h_Closure_Unfolded_UnDet_Forward[k]->Integral()*1./hUnDetectorCos_M_Y_Forward[k]->Integral()*1.);
    hUnDetectorCos_M_Y_Forward[k]->Draw("sames");
    h_Closure_Unfolded_UnDet_Forward[k]->SetMarkerColor(26);
    h_Closure_Unfolded_UnDet_Forward[k]->Draw("e1sames");
  }
  c0_1->SaveAs("forward_MC_test.C");

  TCanvas *c0_2 = new TCanvas();
  c0_2->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c0_2->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    hMeasCos_M_Y_Backward[k]->Scale(h_Closure_Unfolded_UnDet_Backward[k]->Integral()*1./hMeasCos_M_Y_Backward[k]->Integral()*1.);
    hMeasCos_M_Y_Backward[k]->Draw();
    hUnDetectorCos_M_Y_Backward[k]->SetLineColor(4);
    hUnDetectorCos_M_Y_Backward[k]->Scale(h_Closure_Unfolded_UnDet_Backward[k]->Integral()*1./hUnDetectorCos_M_Y_Backward[k]->Integral()*1.);
    hUnDetectorCos_M_Y_Backward[k]->Draw("sames");
    h_Closure_Unfolded_UnDet_Backward[k]->SetMarkerColor(26);
    h_Closure_Unfolded_UnDet_Backward[k]->Draw("e1sames");
  }
  c0_2->SaveAs("backward_MC_test.C");

  TCanvas *c0_3 = new TCanvas();
  c0_3->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c0_3->cd(k+1);
    gPad->SetLogx();
    h_MC_Raw_AFB[k]->GetYaxis()->SetRangeUser(-0.2,0.4);
    h_MC_Raw_AFB[k]->SetLineWidth(2);
    h_MC_Raw_AFB[k]->Draw();
    h_MC_UnDet_AFB[k]->SetLineColor(4);
    h_MC_UnDet_AFB[k]->SetLineWidth(2);
    h_MC_UnDet_AFB[k]->SetLineStyle(2);
    h_MC_UnDet_AFB[k]->Draw("sames");
    h_Closure_Unfolded_UnDet_AFB[k]->SetMarkerColor(26);
    h_Closure_Unfolded_UnDet_AFB[k]->Draw("e1sames");
  }
  c0_3->SaveAs("AFB_MC_test.C");

  gStyle->SetPalette(1);

  TCanvas *r0 = new TCanvas();
  r0->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r0->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    gPad->SetLogz();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    Response_UnDetector_Forward[k]->SetTitle(name_h);
    Response_UnDetector_Forward[k]->GetXaxis()->SetTitle("Forward Gen M(#mu^{+}#mu^{-}) (Bare lepton) [GeV]");
    Response_UnDetector_Forward[k]->GetYaxis()->SetTitle("Forward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Response_UnDetector_Forward[k]->Draw("colz");  
  }
  r0->SaveAs("response_undet_forward.C");

  TCanvas *r1 = new TCanvas();
  r1->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r1->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    gPad->SetLogz();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    Response_UnDetector_Backward[k]->SetTitle(name_h);
    Response_UnDetector_Backward[k]->GetXaxis()->SetTitle("Backward Gen M(#mu^{+}#mu^{-}) (Bare lepton) [GeV]");
    Response_UnDetector_Backward[k]->GetYaxis()->SetTitle("Backward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Response_UnDetector_Backward[k]->Draw("colz");
  }
  r1->SaveAs("response_undet_backward.C");

  TCanvas *r2 = new TCanvas();
  r2->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r2->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    gPad->SetLogz();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    Response_NoFsr_Forward[k]->SetTitle(name_h);
    Response_NoFsr_Forward[k]->GetXaxis()->SetTitle("Forward Gen M(#mu^{+}#mu^{-}) (Born Level) [GeV]");
    Response_NoFsr_Forward[k]->GetYaxis()->SetTitle("Forward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Response_NoFsr_Forward[k]->Draw("colz");
  }
  r2->SaveAs("response_nofsr_forward.C");

  TCanvas *r3 = new TCanvas();
  r3->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r3->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    gPad->SetLogz();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    Response_NoFsr_Backward[k]->SetTitle(name_h);
    Response_NoFsr_Backward[k]->GetXaxis()->SetTitle("Backward Gen M(#mu^{+}#mu^{-}) (Born level) [GeV]");
    Response_NoFsr_Backward[k]->GetYaxis()->SetTitle("Backward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Response_NoFsr_Backward[k]->Draw("colz");
  }
  r3->SaveAs("response_nofsr_backward.C");


  TCanvas *r4 = new TCanvas();
  r4->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r4->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    gPad->SetLogz();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    Response_UnDetector_ForwardBackward_NO_NORM[k]->SetTitle(name_h);
    Response_UnDetector_ForwardBackward_NO_NORM[k]->GetXaxis()->SetTitle("Forward Gen M(#mu^{+}#mu^{-}) (Bare lepton) [GeV]");
    Response_UnDetector_ForwardBackward_NO_NORM[k]->GetYaxis()->SetTitle("Backward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Response_UnDetector_ForwardBackward_NO_NORM[k]->Draw("colz");
  }
  r4->SaveAs("response_undet_forwardbackward_no_norm.C");

  TCanvas *r5 = new TCanvas();
  r5->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r5->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    gPad->SetLogz();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    Response_UnDetector_BackwardForward_NO_NORM[k]->SetTitle(name_h);
    Response_UnDetector_BackwardForward_NO_NORM[k]->GetXaxis()->SetTitle("Backward Gen M(#mu^{+}#mu^{-}) (Bare lepton) [GeV]");
    Response_UnDetector_BackwardForward_NO_NORM[k]->GetYaxis()->SetTitle("Forward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Response_UnDetector_BackwardForward_NO_NORM[k]->Draw("colz");
  }
  r5->SaveAs("response_undet_backwardforward_no_norm.C");

  TCanvas *r4_1 = new TCanvas();
  r4_1->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r4_1->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    gPad->SetLogz();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    Response_UnDetector_Forward_NO_NORM[k]->SetTitle(name_h);
    Response_UnDetector_Forward_NO_NORM[k]->GetXaxis()->SetTitle("Forward Gen M(#mu^{+}#mu^{-}) (Bare lepton) [GeV]");
    Response_UnDetector_Forward_NO_NORM[k]->GetYaxis()->SetTitle("Backward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Response_UnDetector_Forward_NO_NORM[k]->Draw("colz");
  }
  r4_1->SaveAs("response_undet_forward_no_norm.C");

  TCanvas *r5_1 = new TCanvas();
  r5_1->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r5_1->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    gPad->SetLogz();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    Response_UnDetector_Backward_NO_NORM[k]->SetTitle(name_h);
    Response_UnDetector_Backward_NO_NORM[k]->GetXaxis()->SetTitle("Backward Gen M(#mu^{+}#mu^{-}) (Bare lepton) [GeV]");
    Response_UnDetector_Backward_NO_NORM[k]->GetYaxis()->SetTitle("Forward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Response_UnDetector_Backward_NO_NORM[k]->Draw("colz");
  }
  r5_1->SaveAs("response_undet_backward_no_norm.C");

  TCanvas *r6 = new TCanvas();
  r6->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r6->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    gPad->SetLogz();
    sprintf(name_h,"R(FB)/R(FF).   |Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    Response_UnDetector_ForwardBackward_NO_NORM[k]->SetTitle(name_h);
    Response_UnDetector_ForwardBackward_NO_NORM[k]->Divide(Response_UnDetector_Forward_NO_NORM[k]);
    Response_UnDetector_ForwardBackward_NO_NORM[k]->GetXaxis()->SetTitle("Forward Gen M(#mu^{+}#mu^{-}) (Bare lepton) [GeV]");
    Response_UnDetector_ForwardBackward_NO_NORM[k]->GetYaxis()->SetTitle("Backward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Response_UnDetector_ForwardBackward_NO_NORM[k]->Draw("colz");
  }
  r6->SaveAs("response_undet_forwardbackward_divide_forward.C");

  TCanvas *r7 = new TCanvas();
  r7->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r7->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    gPad->SetLogz();
    sprintf(name_h,"R(BF)/R(BB).    |Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    Response_UnDetector_BackwardForward_NO_NORM[k]->SetTitle(name_h);
    Response_UnDetector_BackwardForward_NO_NORM[k]->Divide(Response_UnDetector_Backward_NO_NORM[k]);
    Response_UnDetector_BackwardForward_NO_NORM[k]->GetXaxis()->SetTitle("Backward Gen M(#mu^{+}#mu^{-}) (Bare lepton) [GeV]");
    Response_UnDetector_BackwardForward_NO_NORM[k]->GetYaxis()->SetTitle("Forward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Response_UnDetector_BackwardForward_NO_NORM[k]->Draw("colz");
  }
  r7->SaveAs("response_undet_backwardforward_divide_backward.C");


  //fsr uncertainty plots
  TCanvas *r8 = new TCanvas();
  r8->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r8->cd(k+1);
    gPad->SetLogx();
    h_MC_Raw_AFB_FSR_Diff_Up[k]->SetLineWidth(2);
    h_MC_Raw_AFB_FSR_Diff_Up[k]->SetLineColor(4);
    h_MC_Raw_AFB_FSR_Diff_Up[k]->GetYaxis()->SetRangeUser(-0.002,0.002);
    h_MC_Raw_AFB_FSR_Diff_Up[k]->GetYaxis()->SetTitle("A_{FB}(raw)-A_{FB}(FSR Scaled)");
    h_MC_Raw_AFB_FSR_Diff_Up[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Raw_AFB_FSR_Diff_Up[k]->SetTitle(name_h);
    h_MC_Raw_AFB_FSR_Diff_Up[k]->Draw();
    h_MC_Raw_AFB_FSR_Diff_Down[k]->SetLineWidth(2);
    h_MC_Raw_AFB_FSR_Diff_Down[k]->SetLineColor(2);
    h_MC_Raw_AFB_FSR_Diff_Down[k]->Draw("sames");
  }
  r8->SaveAs("fsr_uncertainty_at_raw.C");

  TCanvas *r8_1 = new TCanvas();
  r8_1->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r8_1->cd(k+1);
    gPad->SetLogx();
    h_MC_UnDet_AFB_FSR_Diff_Up[k]->SetLineWidth(2);
    h_MC_UnDet_AFB_FSR_Diff_Up[k]->SetLineColor(4);
    h_MC_UnDet_AFB_FSR_Diff_Up[k]->GetYaxis()->SetRangeUser(-0.002,0.002);
    h_MC_UnDet_AFB_FSR_Diff_Up[k]->GetYaxis()->SetTitle("A_{FB}(Bare)-A_{FB}(FSR Scaled)");
    h_MC_UnDet_AFB_FSR_Diff_Up[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_UnDet_AFB_FSR_Diff_Up[k]->SetTitle(name_h);
    h_MC_UnDet_AFB_FSR_Diff_Up[k]->Draw();
    h_MC_UnDet_AFB_FSR_Diff_Down[k]->SetLineWidth(2);
    h_MC_UnDet_AFB_FSR_Diff_Down[k]->SetLineColor(2);
    h_MC_UnDet_AFB_FSR_Diff_Down[k]->Draw("sames");
  }
  r8_1->SaveAs("fsr_uncertainty_at_bare_lepton.C");

  TCanvas *r9 = new TCanvas();
  r9->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r9->cd(k+1);
    gPad->SetLogx();
    h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Up[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Up[k]->SetLineColor(4);
    h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Up[k]->GetYaxis()->SetRangeUser(-0.002,0.002);
    h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Up[k]->GetYaxis()->SetTitle("A_{FB}(Born)-A_{FB}(FSR Scaled)");
    h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Up[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Up[k]->SetTitle(name_h);
    h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Up[k]->Draw();
    h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Down[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Down[k]->SetLineColor(2);
    h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Down[k]->Draw("sames");
  }
  r9->SaveAs("fsr_uncertainty_at_born_level.C");
  //end of fsr uncertainty plots


  //bkg uncertainty plots
  TCanvas *r8_bkg = new TCanvas();
  r8_bkg->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r8_bkg->cd(k+1);
    gPad->SetLogx();
    h_MC_Raw_AFB_bkg_Diff_Up[k]->SetLineWidth(2);
    h_MC_Raw_AFB_bkg_Diff_Up[k]->SetLineColor(4);
    h_MC_Raw_AFB_bkg_Diff_Up[k]->GetYaxis()->SetRangeUser(-0.0015,0.0015);
    h_MC_Raw_AFB_bkg_Diff_Up[k]->GetYaxis()->SetTitle("A_{FB}(raw)-A_{FB}(bkg Scaled)");
    h_MC_Raw_AFB_bkg_Diff_Up[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Raw_AFB_bkg_Diff_Up[k]->SetTitle(name_h);
    h_MC_Raw_AFB_bkg_Diff_Up[k]->Draw();
    h_MC_Raw_AFB_bkg_Diff_Down[k]->SetLineWidth(2);
    h_MC_Raw_AFB_bkg_Diff_Down[k]->SetLineColor(2);
    h_MC_Raw_AFB_bkg_Diff_Down[k]->Draw("sames");
  }
  r8_bkg->SaveAs("bkg_uncertainty_at_raw.C");

  TCanvas *r8_bkg_1 = new TCanvas();
  r8_bkg_1->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r8_bkg_1->cd(k+1);
    gPad->SetLogx();
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[k]->SetLineColor(4);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[k]->GetYaxis()->SetRangeUser(-0.0015,0.0015);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[k]->GetYaxis()->SetTitle("A_{FB}(Bare)-A_{FB}(bkg Scaled)");
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[k]->SetTitle(name_h);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[k]->Draw();
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Down[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Down[k]->SetLineColor(2);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Down[k]->Draw("sames");
  }
  r8_bkg_1->SaveAs("bkg_uncertainty_at_bare_lepton.C");

  TCanvas *r9_bkg = new TCanvas();
  r9_bkg->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r9_bkg->cd(k+1);
    gPad->SetLogx();
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[k]->SetLineColor(4);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[k]->GetYaxis()->SetRangeUser(-0.0015,0.0015);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[k]->GetYaxis()->SetTitle("A_{FB}(Born)-A_{FB}(bkg Scaled)");
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[k]->SetTitle(name_h);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[k]->Draw();
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Down[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Down[k]->SetLineColor(2);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Down[k]->Draw("sames");
  }
  r9_bkg->SaveAs("bkg_uncertainty_at_born_level.C");
  //end of bkg uncertainty plots


  TCanvas *r10 = new TCanvas();
  r10->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r10->cd(k+1);
    gPad->SetLogx();
    h_MC_Raw_sin2412m2312_AFB[k]->SetLineWidth(2);
    h_MC_Raw_sin2412m2312_AFB[k]->SetLineColor(4);
    h_MC_Raw_sin2412m2312_AFB[k]->GetYaxis()->SetRangeUser(-0.04,0.04);
    h_MC_Raw_sin2412m2312_AFB[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_MC_Raw_sin2412m2312_AFB[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Raw_sin2412m2312_AFB[k]->SetTitle(name_h);
    h_MC_Raw_sin2412m2312_AFB[k]->Draw();
    h_MC_Raw_sin2212m2312_AFB[k]->SetLineWidth(2);
    h_MC_Raw_sin2212m2312_AFB[k]->SetLineColor(2);
    h_MC_Raw_sin2212m2312_AFB[k]->SetLineStyle(2);
    h_MC_Raw_sin2212m2312_AFB[k]->Draw("sames");
  }
  r10->SaveAs("sin2thetaW_uncertainty_at_raw_level.C");


  TCanvas *r11 = new TCanvas();
  r11->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r11->cd(k+1);
    gPad->SetLogx();
    h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[k]->SetLineColor(4);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[k]->GetYaxis()->SetRangeUser(-0.04,0.04);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[k]->SetTitle(name_h);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[k]->Draw();
    h_MC_Unfolded_UnDet_AFB_Diff_sin2212m2312[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2212m2312[k]->SetLineColor(2);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2212m2312[k]->SetLineStyle(2);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2212m2312[k]->Draw("sames");
  }
  r11->SaveAs("sin2thetaW_uncertainty_at_bare_lepton_level.C");

  TCanvas *r12 = new TCanvas();
  r12->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r12->cd(k+1);
    gPad->SetLogx();
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[k]->SetLineColor(4);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[k]->GetYaxis()->SetRangeUser(-0.04,0.04);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[k]->SetTitle(name_h);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[k]->Draw();
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2212m2312[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2212m2312[k]->SetLineColor(2);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2212m2312[k]->SetLineStyle(2);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2212m2312[k]->Draw("sames");
  }
  r12->SaveAs("sin2thetaW_uncertainty_at_born_level.C");

  TCanvas *r13 = new TCanvas();
  r13->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r13->cd(k+1);
    gPad->SetLogx();
    h_MC_Raw_Align_Startup_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Startup_m_Ideal_AFB[k]->SetLineColor(1);
    h_MC_Raw_Align_Startup_m_Ideal_AFB[k]->GetYaxis()->SetRangeUser(-0.1,0.1);
    h_MC_Raw_Align_Startup_m_Ideal_AFB[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_MC_Raw_Align_Startup_m_Ideal_AFB[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Raw_Align_Startup_m_Ideal_AFB[k]->SetTitle(name_h);
    h_MC_Raw_Align_Startup_m_Ideal_AFB[k]->Draw();

    h_MC_Raw_Align_Bowing_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Bowing_m_Ideal_AFB[k]->SetLineColor(2);
    h_MC_Raw_Align_Bowing_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Raw_Align_Elliptical_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Elliptical_m_Ideal_AFB[k]->SetLineColor(5);
    h_MC_Raw_Align_Elliptical_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Raw_Align_Radial_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Radial_m_Ideal_AFB[k]->SetLineColor(6);
    h_MC_Raw_Align_Radial_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Raw_Align_Sagitta_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Sagitta_m_Ideal_AFB[k]->SetLineColor(7);
    h_MC_Raw_Align_Sagitta_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Raw_Align_Skew_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Skew_m_Ideal_AFB[k]->SetLineColor(8);
    h_MC_Raw_Align_Skew_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Raw_Align_Telescope_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Telescope_m_Ideal_AFB[k]->SetLineColor(9);
    h_MC_Raw_Align_Telescope_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Raw_Align_CurlV2TF_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_CurlV2TF_m_Ideal_AFB[k]->SetLineColor(13);
    h_MC_Raw_Align_CurlV2TF_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Raw_Align_Twist_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Twist_m_Ideal_AFB[k]->SetLineColor(11);
    h_MC_Raw_Align_Twist_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Raw_Align_Zexpansion_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Zexpansion_m_Ideal_AFB[k]->SetLineColor(12);
    h_MC_Raw_Align_Zexpansion_m_Ideal_AFB[k]->Draw("sames");
  }
  r13->SaveAs("Alignment_uncertainty_at_raw_level.C");

  TCanvas *r14 = new TCanvas();
  r14->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r14->cd(k+1);
    gPad->SetLogx();
    h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[k]->SetLineColor(1);
    h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[k]->GetYaxis()->SetRangeUser(-0.04,0.04);
    h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[k]->SetTitle(name_h);
    h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[k]->Draw();

    h_MC_Unfolded_UnDet_Align_Bowing_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Bowing_m_Ideal_AFB[k]->SetLineColor(2);
    h_MC_Unfolded_UnDet_Align_Bowing_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_UnDet_Align_Elliptical_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Elliptical_m_Ideal_AFB[k]->SetLineColor(5);
    h_MC_Unfolded_UnDet_Align_Elliptical_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_UnDet_Align_Radial_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Radial_m_Ideal_AFB[k]->SetLineColor(6);
    h_MC_Unfolded_UnDet_Align_Radial_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_UnDet_Align_Sagitta_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Sagitta_m_Ideal_AFB[k]->SetLineColor(7);
    h_MC_Unfolded_UnDet_Align_Sagitta_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_UnDet_Align_Skew_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Skew_m_Ideal_AFB[k]->SetLineColor(8);
    h_MC_Unfolded_UnDet_Align_Skew_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_UnDet_Align_Telescope_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Telescope_m_Ideal_AFB[k]->SetLineColor(9);
    h_MC_Unfolded_UnDet_Align_Telescope_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_UnDet_Align_CurlV2TF_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_CurlV2TF_m_Ideal_AFB[k]->SetLineColor(13);
    h_MC_Unfolded_UnDet_Align_CurlV2TF_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_UnDet_Align_Twist_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Twist_m_Ideal_AFB[k]->SetLineColor(11);
    h_MC_Unfolded_UnDet_Align_Twist_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_UnDet_Align_Zexpansion_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Zexpansion_m_Ideal_AFB[k]->SetLineColor(12);
    h_MC_Unfolded_UnDet_Align_Zexpansion_m_Ideal_AFB[k]->Draw("sames");
  }
  r14->SaveAs("Alignment_uncertainty_at_bare_lepton_level.C");

  TCanvas *r15 = new TCanvas();
  r15->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r15->cd(k+1);
    gPad->SetLogx();
    h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[k]->SetLineColor(1);
    h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[k]->GetYaxis()->SetRangeUser(-0.04,0.04);
    h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[k]->SetTitle(name_h);
    h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[k]->Draw();

    h_MC_Unfolded_NoFsr_Align_Bowing_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Bowing_m_Ideal_AFB[k]->SetLineColor(2);
    h_MC_Unfolded_NoFsr_Align_Bowing_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_NoFsr_Align_Elliptical_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Elliptical_m_Ideal_AFB[k]->SetLineColor(5);
    h_MC_Unfolded_NoFsr_Align_Elliptical_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_NoFsr_Align_Radial_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Radial_m_Ideal_AFB[k]->SetLineColor(6);
    h_MC_Unfolded_NoFsr_Align_Radial_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_NoFsr_Align_Sagitta_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Sagitta_m_Ideal_AFB[k]->SetLineColor(7);
    h_MC_Unfolded_NoFsr_Align_Sagitta_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_NoFsr_Align_Skew_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Skew_m_Ideal_AFB[k]->SetLineColor(8);
    h_MC_Unfolded_NoFsr_Align_Skew_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_NoFsr_Align_Telescope_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Telescope_m_Ideal_AFB[k]->SetLineColor(9);
    h_MC_Unfolded_NoFsr_Align_Telescope_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_NoFsr_Align_CurlV2TF_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_CurlV2TF_m_Ideal_AFB[k]->SetLineColor(13);
    h_MC_Unfolded_NoFsr_Align_CurlV2TF_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_NoFsr_Align_Twist_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Twist_m_Ideal_AFB[k]->SetLineColor(11);
    h_MC_Unfolded_NoFsr_Align_Twist_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_NoFsr_Align_Zexpansion_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Zexpansion_m_Ideal_AFB[k]->SetLineColor(12);
    h_MC_Unfolded_NoFsr_Align_Zexpansion_m_Ideal_AFB[k]->Draw("sames");
  }
  r15->SaveAs("Alignment_uncertainty_at_Born_level.C");



 TCanvas *r16 = new TCanvas();
  r16->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r16->cd(k+1);
    gPad->SetLogx();
    h_DeltaXmaxPlus_ct10[k]->SetLineWidth(2);
    h_DeltaXmaxPlus_ct10[k]->SetLineColor(4);
    h_DeltaXmaxPlus_ct10[k]->GetYaxis()->SetRangeUser(0.,0.016);
    h_DeltaXmaxPlus_ct10[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_DeltaXmaxPlus_ct10[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_DeltaXmaxPlus_ct10[k]->SetTitle(name_h);
    h_DeltaXmaxPlus_ct10[k]->Draw();
    h_DeltaXmaxMinus_ct10[k]->SetLineWidth(2);
    h_DeltaXmaxMinus_ct10[k]->SetLineColor(2);
    h_DeltaXmaxMinus_ct10[k]->SetLineStyle(2);
    h_DeltaXmaxMinus_ct10[k]->Draw("sames");
  }
  r16->SaveAs("pdf_ct10_uncertainty_at_raw_level.C");

 TCanvas *r16_1 = new TCanvas();
  r16_1->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r16_1->cd(k+1);
    gPad->SetLogx();
    h_DeltaXmaxPlus_undet_ct10[k]->SetLineWidth(2);
    h_DeltaXmaxPlus_undet_ct10[k]->SetLineColor(4);
    h_DeltaXmaxPlus_undet_ct10[k]->GetYaxis()->SetRangeUser(0.,0.016);
    h_DeltaXmaxPlus_undet_ct10[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_DeltaXmaxPlus_undet_ct10[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_DeltaXmaxPlus_undet_ct10[k]->SetTitle(name_h);
    h_DeltaXmaxPlus_undet_ct10[k]->Draw();
    h_DeltaXmaxMinus_undet_ct10[k]->SetLineWidth(2);
    h_DeltaXmaxMinus_undet_ct10[k]->SetLineColor(2);
    h_DeltaXmaxMinus_undet_ct10[k]->SetLineStyle(2);
    h_DeltaXmaxMinus_undet_ct10[k]->Draw("sames");
  }
  r16_1->SaveAs("pdf_undet_ct10_uncertainty_at_raw_level.C");


 TCanvas *r17 = new TCanvas();
  r17->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r17->cd(k+1);
    gPad->SetLogx();
    h_DeltaXmaxPlus_mstw[k]->SetLineWidth(2);
    h_DeltaXmaxPlus_mstw[k]->SetLineColor(4);
    h_DeltaXmaxPlus_mstw[k]->GetYaxis()->SetRangeUser(0.,0.007);
    h_DeltaXmaxPlus_mstw[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_DeltaXmaxPlus_mstw[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_DeltaXmaxPlus_mstw[k]->SetTitle(name_h);
    h_DeltaXmaxPlus_mstw[k]->Draw();
    h_DeltaXmaxMinus_mstw[k]->SetLineWidth(2);
    h_DeltaXmaxMinus_mstw[k]->SetLineColor(2);
    h_DeltaXmaxMinus_mstw[k]->SetLineStyle(2);
    h_DeltaXmaxMinus_mstw[k]->Draw("sames");
  }
  r17->SaveAs("pdf_mstw_uncertainty_at_raw_level.C");

 TCanvas *r18 = new TCanvas();
  r18->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r18->cd(k+1);
    gPad->SetLogx();
    h_sigma[k]->SetLineWidth(2);
    h_sigma[k]->SetLineColor(4);
    h_sigma[k]->GetYaxis()->SetRangeUser(0.,0.01);
    h_sigma[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_sigma[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_sigma[k]->SetTitle(name_h);
    h_sigma[k]->Draw();
  }
  r18->SaveAs("pdf_nnpdf_uncertainty_at_raw_level.C");


 TCanvas *r19 = new TCanvas();
  r19->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r19->cd(k+1);
    gPad->SetLogx();
    h_Delta_AFB_alphas_PLUS[k]->SetLineWidth(2);
    h_Delta_AFB_alphas_PLUS[k]->SetLineColor(4);
    h_Delta_AFB_alphas_PLUS[k]->GetYaxis()->SetRangeUser(-0.006,0.006);
    h_Delta_AFB_alphas_PLUS[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_Delta_AFB_alphas_PLUS[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_Delta_AFB_alphas_PLUS[k]->SetTitle(name_h);
    h_Delta_AFB_alphas_PLUS[k]->Draw();
    h_Delta_AFB_alphas_MINUS[k]->SetLineWidth(2);
    h_Delta_AFB_alphas_MINUS[k]->SetLineColor(2);
    h_Delta_AFB_alphas_MINUS[k]->SetLineStyle(2);
    h_Delta_AFB_alphas_MINUS[k]->Draw("sames");
  }
  r19->SaveAs("pdf_alpha_s_uncertainty_at_raw_level.C");

TCanvas *r20 = new TCanvas();
  r20->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r20->cd(k+1);
    gPad->SetLogx();
    h_DeltaX_CT10_ALPHAS_PLUS[k]->SetLineWidth(2);
    h_DeltaX_CT10_ALPHAS_PLUS[k]->SetLineColor(4);
    h_DeltaX_CT10_ALPHAS_PLUS[k]->GetYaxis()->SetRangeUser(0.,0.016);
    h_DeltaX_CT10_ALPHAS_PLUS[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_DeltaX_CT10_ALPHAS_PLUS[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_DeltaX_CT10_ALPHAS_PLUS[k]->SetTitle(name_h);
    h_DeltaX_CT10_ALPHAS_PLUS[k]->Draw();
    h_DeltaX_CT10_ALPHAS_MINUS[k]->SetLineWidth(2);
    h_DeltaX_CT10_ALPHAS_MINUS[k]->SetLineColor(2);
    h_DeltaX_CT10_ALPHAS_MINUS[k]->SetLineStyle(2);
    h_DeltaX_CT10_ALPHAS_MINUS[k]->Draw("sames");
  }
  r20->SaveAs("pdf_CT10_plus_alpha_s_uncertainty_at_raw_level.C");

TCanvas *r21 = new TCanvas();
  r21->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r21->cd(k+1);
    gPad->SetLogx();
    h_envelope_sigma[k]->SetLineWidth(2);
    h_envelope_sigma[k]->SetLineColor(4);
    h_envelope_sigma[k]->GetYaxis()->SetRangeUser(0.,0.016);
    h_envelope_sigma[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_envelope_sigma[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_envelope_sigma[k]->SetTitle(name_h);
    h_envelope_sigma[k]->Draw();
  }
  r21->SaveAs("pdf_envelope_uncertainty_at_raw_level.C");

TCanvas *r22 = new TCanvas();
  r22->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r22->cd(k+1);
    gPad->SetLogx();
    h_total_plus[k]->SetLineWidth(2);
    h_total_plus[k]->SetLineColor(4);
    h_total_plus[k]->GetYaxis()->SetRangeUser(0.,0.016);
    h_total_plus[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_total_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_total_plus[k]->SetTitle(name_h);
    h_total_plus[k]->Draw();
    h_total_minus[k]->SetLineWidth(2);
    h_total_minus[k]->SetLineColor(2);
    h_total_minus[k]->SetLineStyle(2);
    h_total_minus[k]->Draw("sames");
  }
  r22->SaveAs("total_systematic_uncertainty_at_raw_level.C");



  for (int k=0;k<nb_Y;k++){
    for (int i=0;i<nb;i++){
      y_plus[k][i] = h_MC_Raw_AFB[k]->GetBinContent(i+1)+total_plus[k][i];
      y_minus[k][i] = h_MC_Raw_AFB[k]->GetBinContent(i+1)+total_minus[k][i];

      y_plus_undet[k][i] = h_MC_UnDet_AFB[k]->GetBinContent(i+1)+total_plus_undet[k][i];
      y_minus_undet[k][i] = h_MC_UnDet_AFB[k]->GetBinContent(i+1)+total_minus_undet[k][i];

      y_plus_nofsr[k][i] = h_MC_NoFsr_AFB[k]->GetBinContent(i+1)+total_plus_nofsr[k][i];
      y_minus_nofsr[k][i] = h_MC_NoFsr_AFB[k]->GetBinContent(i+1)+total_minus_nofsr[k][i];
    }
  }

  int j = nb-1;
  for (int i=0;i<nb;i++){
    band_x1[i] =  (xAxis_AFB[i]+xAxis_AFB[i+1])/2.;
    band_x1[i+nb] =  (xAxis_AFB[j]+xAxis_AFB[j+1])/2.;

    band_y1[i] = total_minus[0][i];
    band_y1[i+nb] = total_plus[0][j];
    band_y2[i] = total_minus[1][i];
    band_y2[i+nb] = total_plus[1][j];
    band_y3[i] = total_minus[2][i];
    band_y3[i+nb] = total_plus[2][j];
    band_y4[i] = total_minus[3][i];
    band_y4[i+nb] = total_plus[3][j];

    band_afb_y1[i] = y_minus[0][i];
    band_afb_y1[i+nb] =  y_plus[0][j];
    band_afb_y2[i] = y_minus[1][i];
    band_afb_y2[i+nb] =  y_plus[1][j];
    band_afb_y3[i] = y_minus[2][i];
    band_afb_y3[i+nb] =  y_plus[2][j];
    band_afb_y4[i] = y_minus[3][i];
    band_afb_y4[i+nb] =  y_plus[3][j];


    band_y1_undet[i] = total_minus_undet[0][i];
    band_y1_undet[i+nb] = total_plus_undet[0][j];
    band_y2_undet[i] = total_minus_undet[1][i];
    band_y2_undet[i+nb] = total_plus_undet[1][j];
    band_y3_undet[i] = total_minus_undet[2][i];
    band_y3_undet[i+nb] = total_plus_undet[2][j];
    band_y4_undet[i] = total_minus_undet[3][i];
    band_y4_undet[i+nb] = total_plus_undet[3][j];

    band_afb_y1_undet[i] = y_minus_undet[0][i];
    band_afb_y1_undet[i+nb] =  y_plus_undet[0][j];
    band_afb_y2_undet[i] = y_minus_undet[1][i];
    band_afb_y2_undet[i+nb] =  y_plus_undet[1][j];
    band_afb_y3_undet[i] = y_minus_undet[2][i];
    band_afb_y3_undet[i+nb] =  y_plus_undet[2][j];
    band_afb_y4_undet[i] = y_minus_undet[3][i];
    band_afb_y4_undet[i+nb] =  y_plus_undet[3][j];


    band_y1_nofsr[i] = total_minus_nofsr[0][i];
    band_y1_nofsr[i+nb] = total_plus_nofsr[0][j];
    band_y2_nofsr[i] = total_minus_nofsr[1][i];
    band_y2_nofsr[i+nb] = total_plus_nofsr[1][j];
    band_y3_nofsr[i] = total_minus_nofsr[2][i];
    band_y3_nofsr[i+nb] = total_plus_nofsr[2][j];
    band_y4_nofsr[i] = total_minus_nofsr[3][i];
    band_y4_nofsr[i+nb] = total_plus_nofsr[3][j];

    band_afb_y1_nofsr[i] = y_minus_nofsr[0][i];
    band_afb_y1_nofsr[i+nb] =  y_plus_nofsr[0][j];
    band_afb_y2_nofsr[i] = y_minus_nofsr[1][i];
    band_afb_y2_nofsr[i+nb] =  y_plus_nofsr[1][j];
    band_afb_y3_nofsr[i] = y_minus_nofsr[2][i];
    band_afb_y3_nofsr[i+nb] =  y_plus_nofsr[2][j];
    band_afb_y4_nofsr[i] = y_minus_nofsr[3][i];
    band_afb_y4_nofsr[i+nb] =  y_plus_nofsr[3][j];

    j--;
  }

  /*
  TGraph *gr_band1 = new TGraph(nb*2,band_x1,band_y1);
  TGraph *gr_band2 = new TGraph(nb*2,band_x1,band_y2);
  TGraph *gr_band3 = new TGraph(nb*2,band_x1,band_y3);
  TGraph *gr_band4 = new TGraph(nb*2,band_x1,band_y4);
  
  TCanvas *r23 = new TCanvas();
  TH2F* frame1 = new TH2F("frame1","|Y|=0.00-1.00",100,30,1000,100,-0.1,0.1);
  frame1->GetXaxis()->SetRangeUser(40,320);
  frame1->GetYaxis()->SetRangeUser(-0.098,0.072);
  frame1->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame1->GetYaxis()->SetTitle("A_{FB}(mod)-A_{FB}");
  frame1->GetYaxis()->CenterTitle();
  frame1->Draw();
  gr_band1->SetMarkerStyle(28);
  gr_band1->SetFillColor(20);
  gr_band1->SetLineColor(20);
  gr_band1->SetMarkerColor(20);
  gr_band1->Draw("F");
  r23->SaveAs("del.C");
  */

  TGraph *gr_afb_band1 = new TGraph(nb*2,band_x1,band_afb_y1);
  TGraph *gr_afb_band2 = new TGraph(nb*2,band_x1,band_afb_y2);
  TGraph *gr_afb_band3 = new TGraph(nb*2,band_x1,band_afb_y3);
  TGraph *gr_afb_band4 = new TGraph(nb*2,band_x1,band_afb_y4);

  float AFB0[nb];
  float AFB1[nb];
  float AFB2[nb];
  float AFB3[nb];
  float AFB_Err0[nb];
  float AFB_Err1[nb];
  float AFB_Err2[nb];
  float AFB_Err3[nb];
  float AFB_x0[nb];
  float AFB_x1[nb];
  float AFB_x2[nb];
  float AFB_x3[nb];
  
  float AFB0_UnDet[nb];
  float AFB1_UnDet[nb];
  float AFB2_UnDet[nb];
  float AFB3_UnDet[nb];
  float AFB_Err0_UnDet[nb];
  float AFB_Err1_UnDet[nb];
  float AFB_Err2_UnDet[nb];
  float AFB_Err3_UnDet[nb];
  float AFB_x0_UnDet[nb];
  float AFB_x1_UnDet[nb];
  float AFB_x2_UnDet[nb];
  float AFB_x3_UnDet[nb];

  float AFB0_NoFsr[nb];
  float AFB1_NoFsr[nb];
  float AFB2_NoFsr[nb];
  float AFB3_NoFsr[nb];
  float AFB_Err0_NoFsr[nb];
  float AFB_Err1_NoFsr[nb];
  float AFB_Err2_NoFsr[nb];
  float AFB_Err3_NoFsr[nb];
  float AFB_x0_NoFsr[nb];
  float AFB_x1_NoFsr[nb];
  float AFB_x2_NoFsr[nb];
  float AFB_x3_NoFsr[nb];

  float AFB0_Parton[nb];
  float AFB1_Parton[nb];
  float AFB2_Parton[nb];
  float AFB3_Parton[nb];
  float AFB_Err0_Parton[nb];
  float AFB_Err1_Parton[nb];
  float AFB_Err2_Parton[nb];
  float AFB_Err3_Parton[nb];
  float AFB_x0_Parton[nb];
  float AFB_x1_Parton[nb];
  float AFB_x2_Parton[nb];
  float AFB_x3_Parton[nb];

  for (int j=0;j<nb_Y;j++){
    for (int i=0;i<nb;i++){
      if (j == 0){ 
	AFB0[i] = h_Raw_AFB[j]->GetBinContent(i+1);
	AFB_Err0[i] = h_Raw_AFB[j]->GetBinError(i+1);
	AFB_x0[i] = hExpectedMass_RAW_M_Y[j][i]->GetMean();

	AFB0_UnDet[i] = h_Unfolded_UnDet_AFB[j]->GetBinContent(i+1);
	AFB_Err0_UnDet[i] = h_Unfolded_UnDet_AFB[j]->GetBinError(i+1);
	AFB_x0_UnDet[i] = hExpectedMass_UnDet_M_Y[j][i]->GetMean();

	AFB0_NoFsr[i] = h_Unfolded_NoFsr_AFB[j]->GetBinContent(i+1);
	AFB_Err0_NoFsr[i] = h_Unfolded_NoFsr_AFB[j]->GetBinError(i+1);
	AFB_x0_NoFsr[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();

	AFB0_Parton[i] = h_Unfolded_NoFsr_AFB[j]->GetBinContent(i+1)*dilution[j][i];
	AFB_Err0_Parton[i] = h_Unfolded_NoFsr_AFB[j]->GetBinError(i+1)*dilution[j][i];
	AFB_x0_Parton[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();
      }
      if (j == 1){ 
	AFB1[i] = h_Raw_AFB[j]->GetBinContent(i+1);
	AFB_Err1[i] = h_Raw_AFB[j]->GetBinError(i+1);
	AFB_x1[i] = hExpectedMass_RAW_M_Y[j][i]->GetMean();

	AFB1_UnDet[i] = h_Unfolded_UnDet_AFB[j]->GetBinContent(i+1);
	AFB_Err1_UnDet[i] = h_Unfolded_UnDet_AFB[j]->GetBinError(i+1);
	AFB_x1_UnDet[i] = hExpectedMass_UnDet_M_Y[j][i]->GetMean();

	AFB1_NoFsr[i] = h_Unfolded_NoFsr_AFB[j]->GetBinContent(i+1);
	AFB_Err1_NoFsr[i] = h_Unfolded_NoFsr_AFB[j]->GetBinError(i+1);
	AFB_x1_NoFsr[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();

	AFB1_Parton[i] = h_Unfolded_NoFsr_AFB[j]->GetBinContent(i+1)*dilution[j][i];
	AFB_Err1_Parton[i] = h_Unfolded_NoFsr_AFB[j]->GetBinError(i+1)*dilution[j][i];
	AFB_x1_Parton[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();
      }
      if (j == 2){ 
	AFB2[i] = h_Raw_AFB[j]->GetBinContent(i+1);
	AFB_Err2[i] = h_Raw_AFB[j]->GetBinError(i+1);
	AFB_x2[i] = hExpectedMass_RAW_M_Y[j][i]->GetMean();

	AFB2_UnDet[i] = h_Unfolded_UnDet_AFB[j]->GetBinContent(i+1);
	AFB_Err2_UnDet[i] = h_Unfolded_UnDet_AFB[j]->GetBinError(i+1);
	AFB_x2_UnDet[i] = hExpectedMass_UnDet_M_Y[j][i]->GetMean();

	AFB2_NoFsr[i] = h_Unfolded_NoFsr_AFB[j]->GetBinContent(i+1);
	AFB_Err2_NoFsr[i] = h_Unfolded_NoFsr_AFB[j]->GetBinError(i+1);
	AFB_x2_NoFsr[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();

	AFB2_Parton[i] = h_Unfolded_NoFsr_AFB[j]->GetBinContent(i+1)*dilution[j][i];
	AFB_Err2_Parton[i] = h_Unfolded_NoFsr_AFB[j]->GetBinError(i+1)*dilution[j][i];
	AFB_x2_Parton[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();
      }
      if (j == 3){ 
	AFB3[i] = h_Raw_AFB[j]->GetBinContent(i+1);
	AFB_Err3[i] = h_Raw_AFB[j]->GetBinError(i+1);
	AFB_x3[i] = hExpectedMass_RAW_M_Y[j][i]->GetMean();

	AFB3_UnDet[i] = h_Unfolded_UnDet_AFB[j]->GetBinContent(i+1);
	AFB_Err3_UnDet[i] = h_Unfolded_UnDet_AFB[j]->GetBinError(i+1);
	AFB_x3_UnDet[i] = hExpectedMass_UnDet_M_Y[j][i]->GetMean();

	AFB3_NoFsr[i] = h_Unfolded_NoFsr_AFB[j]->GetBinContent(i+1);
	AFB_Err3_NoFsr[i] = h_Unfolded_NoFsr_AFB[j]->GetBinError(i+1);
	AFB_x3_NoFsr[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();

	AFB3_Parton[i] = h_Unfolded_NoFsr_AFB[j]->GetBinContent(i+1)*dilution[j][i];
	AFB_Err3_Parton[i] = h_Unfolded_NoFsr_AFB[j]->GetBinError(i+1)*dilution[j][i];
	AFB_x3_Parton[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();
      }
    }
  }

  TGraph *gr[nb_Y];
  gr[0] = new TGraphErrors(nb,AFB_x0,AFB0,0,AFB_Err0);
  gr[1] = new TGraphErrors(nb,AFB_x1,AFB1,0,AFB_Err1);
  gr[2] = new TGraphErrors(nb,AFB_x2,AFB2,0,AFB_Err2);
  gr[3] = new TGraphErrors(nb,AFB_x3,AFB3,0,AFB_Err3);

  TGraph *gr_UnDet[nb_Y];
  gr_UnDet[0] = new TGraphErrors(nb,AFB_x0_UnDet,AFB0_UnDet,0,AFB_Err0_UnDet);
  gr_UnDet[1] = new TGraphErrors(nb,AFB_x1_UnDet,AFB1_UnDet,0,AFB_Err1_UnDet);
  gr_UnDet[2] = new TGraphErrors(nb,AFB_x2_UnDet,AFB2_UnDet,0,AFB_Err2_UnDet);
  gr_UnDet[3] = new TGraphErrors(nb,AFB_x3_UnDet,AFB3_UnDet,0,AFB_Err3_UnDet);

  TGraph *gr_NoFsr[nb_Y];
  gr_NoFsr[0] = new TGraphErrors(nb,AFB_x0_NoFsr,AFB0_NoFsr,0,AFB_Err0_NoFsr);
  gr_NoFsr[1] = new TGraphErrors(nb,AFB_x1_NoFsr,AFB1_NoFsr,0,AFB_Err1_NoFsr);
  gr_NoFsr[2] = new TGraphErrors(nb,AFB_x2_NoFsr,AFB2_NoFsr,0,AFB_Err2_NoFsr);
  gr_NoFsr[3] = new TGraphErrors(nb,AFB_x3_NoFsr,AFB3_NoFsr,0,AFB_Err3_NoFsr);

  TGraph *gr_Parton[nb_Y];
  gr_Parton[0] = new TGraphErrors(nb,AFB_x0_Parton,AFB0_Parton,0,AFB_Err0_Parton);
  gr_Parton[1] = new TGraphErrors(nb,AFB_x1_Parton,AFB1_Parton,0,AFB_Err1_Parton);
  gr_Parton[2] = new TGraphErrors(nb,AFB_x2_Parton,AFB2_Parton,0,AFB_Err2_Parton);
  gr_Parton[3] = new TGraphErrors(nb,AFB_x3_Parton,AFB3_Parton,0,AFB_Err3_Parton);

  TCanvas *r24 = new TCanvas();
  r24->Divide(2,2);
  r24->cd(1);

  TH2F* frame1a = new TH2F("frame1a","|Y|=0.00-1.00",100,30,1000,100,-0.2,0.5);
  frame1a->GetXaxis()->SetRangeUser(40,1500);
  frame1a->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame1a->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame1a->GetYaxis()->SetTitle("A_{FB}");
  frame1a->GetYaxis()->CenterTitle();
  frame1a->Draw();
  gPad->SetLogx();
  gr_afb_band1->SetMarkerStyle(28);
  gr_afb_band1->SetFillColor(4);
  gr_afb_band1->SetLineColor(4);
  gr_afb_band1->SetMarkerColor(4);
  gr_afb_band1->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Raw_AFB[0]->Draw("e1sames");
  gr[0]->SetMarkerStyle(8);
  gr[0]->SetLineWidth(2);
  gr[0]->Draw("P");
  r24->cd(2);

  TH2F* frame2a = new TH2F("frame2a","|Y|=1.00-1.25",100,30,1000,100,-0.2,0.5);
  frame2a->GetXaxis()->SetRangeUser(40,1500);
  frame2a->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame2a->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame2a->GetYaxis()->SetTitle("A_{FB}");
  frame2a->GetYaxis()->CenterTitle();
  frame2a->Draw();
  gPad->SetLogx();
  gr_afb_band2->SetMarkerStyle(28);
  gr_afb_band2->SetFillColor(4);
  gr_afb_band2->SetLineColor(4);
  gr_afb_band2->SetMarkerColor(4);
  gr_afb_band2->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Raw_AFB[1]->Draw("e1sames");
  gr[1]->SetMarkerStyle(8);
  gr[1]->SetLineWidth(2);
  gr[1]->Draw("P");
  r24->cd(3);
  TH2F* frame3a = new TH2F("frame3a","|Y|=1.25-1.50",100,30,1000,100,-0.2,0.5);
  frame3a->GetXaxis()->SetRangeUser(40,1500);
  frame3a->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame3a->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame3a->GetYaxis()->SetTitle("A_{FB}");
  frame3a->GetYaxis()->CenterTitle();
  frame3a->Draw();
  gPad->SetLogx();
  gr_afb_band3->SetMarkerStyle(28);
  gr_afb_band3->SetFillColor(4);
  gr_afb_band3->SetLineColor(4);
  gr_afb_band3->SetMarkerColor(4);
  gr_afb_band3->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Raw_AFB[2]->Draw("e1sames");
  gr[2]->SetMarkerStyle(8);
  gr[2]->SetLineWidth(2);
  gr[2]->Draw("P");
  r24->cd(4);
  TH2F* frame4a = new TH2F("frame4a","|Y|=1.50-2.10",100,30,1000,100,-0.2,0.5);
  frame4a->GetXaxis()->SetRangeUser(40,1500);
  frame4a->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame4a->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame4a->GetYaxis()->SetTitle("A_{FB}");
  frame4a->GetYaxis()->CenterTitle();
  frame4a->Draw();
  gPad->SetLogx();
  gr_afb_band4->SetMarkerStyle(28);
  gr_afb_band4->SetFillColor(4);
  gr_afb_band4->SetLineColor(4);
  gr_afb_band4->SetMarkerColor(4);
  gr_afb_band4->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Raw_AFB[3]->Draw("e1sames");
  gr[3]->SetMarkerStyle(8);
  gr[3]->SetLineWidth(2);
  gr[3]->Draw("P");
  r24->SaveAs("raw_AFB_with_systematics.C");

//undet
  TGraph *gr_afb_band1_undet = new TGraph(nb*2,band_x1,band_afb_y1_undet);
  TGraph *gr_afb_band2_undet = new TGraph(nb*2,band_x1,band_afb_y2_undet);
  TGraph *gr_afb_band3_undet = new TGraph(nb*2,band_x1,band_afb_y3_undet);
  TGraph *gr_afb_band4_undet = new TGraph(nb*2,band_x1,band_afb_y4_undet);

  TCanvas *r25 = new TCanvas();
  r25->Divide(2,2);
  r25->cd(1);

  TH2F* frame1a_undet = new TH2F("frame1a_undet","|Y|=0.00-1.00",100,30,1000,100,-0.2,0.5);
  frame1a_undet->GetXaxis()->SetRangeUser(40,1500);
  frame1a_undet->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame1a_undet->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame1a_undet->GetYaxis()->SetTitle("A_{FB}");
  frame1a_undet->GetYaxis()->CenterTitle();
  frame1a_undet->Draw();
  gPad->SetLogx();
  gr_afb_band1_undet->SetMarkerStyle(28);
  gr_afb_band1_undet->SetFillColor(4);
  gr_afb_band1_undet->SetLineColor(4);
  gr_afb_band1_undet->SetMarkerColor(4);
  gr_afb_band1_undet->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_UnDet_AFB[0]->Draw("e1sames");
  gr_UnDet[0]->SetMarkerStyle(8);
  gr_UnDet[0]->SetLineWidth(2);
  gr_UnDet[0]->Draw("P");
  r25->cd(2);

  TH2F* frame2a_undet = new TH2F("frame2a_undet","|Y|=1.00-1.25",100,30,1000,100,-0.2,0.5);
  frame2a_undet->GetXaxis()->SetRangeUser(40,1500);
  frame2a_undet->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame2a_undet->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame2a_undet->GetYaxis()->SetTitle("A_{FB}");
  frame2a_undet->GetYaxis()->CenterTitle();
  frame2a_undet->Draw();
  gPad->SetLogx();
  gr_afb_band2_undet->SetMarkerStyle(28);
  gr_afb_band2_undet->SetFillColor(4);
  gr_afb_band2_undet->SetLineColor(4);
  gr_afb_band2_undet->SetMarkerColor(4);
  gr_afb_band2_undet->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_UnDet_AFB[1]->Draw("e1sames");
  gr_UnDet[1]->SetMarkerStyle(8);
  gr_UnDet[1]->SetLineWidth(2);
  gr_UnDet[1]->Draw("P");
  r25->cd(3);
  TH2F* frame3a_undet = new TH2F("frame3a_undet","|Y|=1.25-1.50",100,30,1000,100,-0.2,0.5);
  frame3a_undet->GetXaxis()->SetRangeUser(40,1500);
  frame3a_undet->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame3a_undet->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame3a_undet->GetYaxis()->SetTitle("A_{FB}");
  frame3a_undet->GetYaxis()->CenterTitle();
  frame3a_undet->Draw();
  gPad->SetLogx();
  gr_afb_band3_undet->SetMarkerStyle(28);
  gr_afb_band3_undet->SetFillColor(4);
  gr_afb_band3_undet->SetLineColor(4);
  gr_afb_band3_undet->SetMarkerColor(4);
  gr_afb_band3_undet->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_UnDet_AFB[2]->Draw("e1sames");
  gr_UnDet[2]->SetMarkerStyle(8);
  gr_UnDet[2]->SetLineWidth(2);
  gr_UnDet[2]->Draw("P");
  r25->cd(4);
  TH2F* frame4a_undet = new TH2F("frame4a_undet","|Y|=1.50-2.10",100,30,1000,100,-0.2,0.5);
  frame4a_undet->GetXaxis()->SetRangeUser(40,1500);
  frame4a_undet->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame4a_undet->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame4a_undet->GetYaxis()->SetTitle("A_{FB}");
  frame4a_undet->GetYaxis()->CenterTitle();
  frame4a_undet->Draw();
  gPad->SetLogx();
  gr_afb_band4_undet->SetMarkerStyle(28);
  gr_afb_band4_undet->SetFillColor(4);
  gr_afb_band4_undet->SetLineColor(4);
  gr_afb_band4_undet->SetMarkerColor(4);
  gr_afb_band4_undet->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");


  //  h_Unfolded_UnDet_AFB[3]->Draw("e1sames");
  gr_UnDet[3]->SetMarkerStyle(8);
  gr_UnDet[3]->SetLineWidth(2);
  gr_UnDet[3]->Draw("P");
  r25->SaveAs("Bare_Lepton_Level_AFB_with_systematics.C");
//eof undet

//nofsr
  TGraph *gr_afb_band1_nofsr = new TGraph(nb*2,band_x1,band_afb_y1_nofsr);
  TGraph *gr_afb_band2_nofsr = new TGraph(nb*2,band_x1,band_afb_y2_nofsr);
  TGraph *gr_afb_band3_nofsr = new TGraph(nb*2,band_x1,band_afb_y3_nofsr);
  TGraph *gr_afb_band4_nofsr = new TGraph(nb*2,band_x1,band_afb_y4_nofsr);

  TCanvas *r26 = new TCanvas();
  r26->Divide(2,2);
  r26->cd(1);

  TH2F* frame1a_nofsr = new TH2F("frame1a_nofsr","|Y|=0.00-1.00",100,30,1000,100,-0.2,0.5);
  frame1a_nofsr->GetXaxis()->SetRangeUser(40,1500);
  frame1a_nofsr->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame1a_nofsr->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame1a_nofsr->GetYaxis()->SetTitle("A_{FB}");
  frame1a_nofsr->GetYaxis()->CenterTitle();
  frame1a_nofsr->Draw();
  gPad->SetLogx();
  gr_afb_band1_nofsr->SetMarkerStyle(28);
  gr_afb_band1_nofsr->SetFillColor(4);
  gr_afb_band1_nofsr->SetLineColor(4);
  gr_afb_band1_nofsr->SetMarkerColor(4);
  gr_afb_band1_nofsr->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_NoFsr_AFB[0]->Draw("e1sames");
  gr_NoFsr[0]->SetMarkerStyle(8);
  gr_NoFsr[0]->SetLineWidth(2);
  gr_NoFsr[0]->Draw("P");
  r26->cd(2);

  TH2F* frame2a_nofsr = new TH2F("frame2a_nofsr","|Y|=1.00-1.25",100,30,1000,100,-0.2,0.5);
  frame2a_nofsr->GetXaxis()->SetRangeUser(40,1500);
  frame2a_nofsr->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame2a_nofsr->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame2a_nofsr->GetYaxis()->SetTitle("A_{FB}");
  frame2a_nofsr->GetYaxis()->CenterTitle();
  frame2a_nofsr->Draw();
  gPad->SetLogx();
  gr_afb_band2_nofsr->SetMarkerStyle(28);
  gr_afb_band2_nofsr->SetFillColor(4);
  gr_afb_band2_nofsr->SetLineColor(4);
  gr_afb_band2_nofsr->SetMarkerColor(4);
  gr_afb_band2_nofsr->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_NoFsr_AFB[1]->Draw("e1sames");
  gr_NoFsr[1]->SetMarkerStyle(8);
  gr_NoFsr[1]->SetLineWidth(2);
  gr_NoFsr[1]->Draw("P");
  r26->cd(3);
  TH2F* frame3a_nofsr = new TH2F("frame3a_nofsr","|Y|=1.25-1.50",100,30,1000,100,-0.2,0.5);
  frame3a_nofsr->GetXaxis()->SetRangeUser(40,1500);
  frame3a_nofsr->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame3a_nofsr->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame3a_nofsr->GetYaxis()->SetTitle("A_{FB}");
  frame3a_nofsr->GetYaxis()->CenterTitle();
  frame3a_nofsr->Draw();
  gPad->SetLogx();
  gr_afb_band3_nofsr->SetMarkerStyle(28);
  gr_afb_band3_nofsr->SetFillColor(4);
  gr_afb_band3_nofsr->SetLineColor(4);
  gr_afb_band3_nofsr->SetMarkerColor(4);
  gr_afb_band3_nofsr->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_NoFsr_AFB[2]->Draw("e1sames");
  gr_NoFsr[2]->SetMarkerStyle(8);
  gr_NoFsr[2]->SetLineWidth(2);
  gr_NoFsr[2]->Draw("P");
  r26->cd(4);
  TH2F* frame4a_nofsr = new TH2F("frame4a_nofsr","|Y|=1.50-2.10",100,30,1000,100,-0.2,0.5);
  frame4a_nofsr->GetXaxis()->SetRangeUser(40,1500);
  frame4a_nofsr->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame4a_nofsr->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame4a_nofsr->GetYaxis()->SetTitle("A_{FB}");
  frame4a_nofsr->GetYaxis()->CenterTitle();
  frame4a_nofsr->Draw();
  gPad->SetLogx();
  gr_afb_band4_nofsr->SetMarkerStyle(28);
  gr_afb_band4_nofsr->SetFillColor(4);
  gr_afb_band4_nofsr->SetLineColor(4);
  gr_afb_band4_nofsr->SetMarkerColor(4);
  gr_afb_band4_nofsr->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_NoFsr_AFB[3]->Draw("e1sames");
  gr_NoFsr[3]->SetMarkerStyle(8);
  gr_NoFsr[3]->SetLineWidth(2);
  gr_NoFsr[3]->Draw("P");
  r26->SaveAs("Born_Level_AFB_with_systematics.C");
//eof nofsr

  TCanvas *c27 = new TCanvas();
  c27->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c27->cd(k+1);
    gPad->SetLogx();  
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_Ideal_Geo_AFB[k]->SetTitle(name_h);
    h_Ideal_Geo_AFB[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Ideal_Geo_AFB[k]->GetYaxis()->SetTitle("A_{FB}");
    h_Ideal_Geo_AFB[k]->SetMarkerStyle(8);
    h_Ideal_Geo_AFB[k]->SetLineWidth(2);
    h_Ideal_Geo_AFB[k]->Draw("e1");
  }
  c27->SaveAs("IDEAL_afb_raw.C");

  TCanvas *c28 = new TCanvas();
  c28->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c28->cd(k+1);

    h_Ideal_Geo_AFB_FineBin[k]->SetLineWidth(2);
    h_Ideal_Geo_AFB_FineBin[k]->SetLineColor(4);
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_Ideal_Geo_AFB_FineBin[k]->SetTitle(name_h);
    h_Ideal_Geo_AFB_FineBin[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Ideal_Geo_AFB_FineBin[k]->GetYaxis()->SetTitle("A_{FB}");
    h_Ideal_Geo_AFB_FineBin[k]->Draw("e1");
    h_Raw_AFB_FineBin[k]->SetMarkerStyle(8);
    h_Raw_AFB_FineBin[k]->SetLineWidth(2);
    h_Raw_AFB_FineBin[k]->Draw("e1sames");

  }
  c28->SaveAs("afb_raw_FINEBIN.C");

  
  TCanvas *c29 = new TCanvas();
  c29->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c29->cd(k+1);
    gPad->SetLogx();
    h_MC_Raw_alignment_total_plus[k]->SetLineWidth(2);
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Raw_alignment_total_plus[k]->GetYaxis()->SetRangeUser(-0.18,0.18);
    h_MC_Raw_alignment_total_plus[k]->SetTitle(name_h);
    h_MC_Raw_alignment_total_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_MC_Raw_alignment_total_plus[k]->GetYaxis()->SetTitle("#Delta");
    h_MC_Raw_alignment_total_plus[k]->Draw();
    //    h_MC_Raw_alignment_total_minus[k]->SetFillColor(1);
    h_MC_Raw_alignment_total_minus[k]->SetLineWidth(2);
    h_MC_Raw_alignment_total_minus[k]->Draw("sames");

    h_MC_Bare_alignment_total_plus[k]->SetLineWidth(2);
    h_MC_Bare_alignment_total_plus[k]->SetLineColor(2);
    h_MC_Bare_alignment_total_plus[k]->Draw("sames");
    h_MC_Bare_alignment_total_minus[k]->SetLineWidth(2);
    h_MC_Bare_alignment_total_minus[k]->SetLineColor(2);
    h_MC_Bare_alignment_total_minus[k]->Draw("sames");

    h_MC_Born_alignment_total_plus[k]->SetLineWidth(2);
    h_MC_Born_alignment_total_plus[k]->SetLineColor(4);
    h_MC_Born_alignment_total_plus[k]->Draw("sames");
    h_MC_Born_alignment_total_minus[k]->SetLineWidth(2);
    h_MC_Born_alignment_total_minus[k]->SetLineColor(4);
    h_MC_Born_alignment_total_minus[k]->Draw("sames");

  }
  c29->SaveAs("total_misalignment_syst_at_each_stage.C");


  TCanvas *c30 = new TCanvas();
  c30->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c30->cd(k+1);
    gPad->SetLogx();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_Systematics_fsr_raw_plus[k]->GetYaxis()->SetRangeUser(-0.18,0.18);
    h_Systematics_fsr_raw_plus[k]->SetMarkerStyle(20);
    h_Systematics_fsr_raw_plus[k]->SetLineColor(2);
    h_Systematics_fsr_raw_plus[k]->SetMarkerColor(2);
    h_Systematics_fsr_raw_plus[k]->SetLineWidth(2);
    h_Systematics_fsr_raw_plus[k]->SetTitle(name_h);
    h_Systematics_fsr_raw_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Systematics_fsr_raw_plus[k]->GetYaxis()->SetTitle("#Delta");
    h_Systematics_fsr_raw_plus[k]->Draw("e1");
    h_Systematics_fsr_raw_minus[k]->SetLineColor(2);
    h_Systematics_fsr_raw_minus[k]->SetMarkerColor(2);
    h_Systematics_fsr_raw_minus[k]->SetMarkerStyle(20);
    h_Systematics_fsr_raw_minus[k]->SetLineWidth(2);
    h_Systematics_fsr_raw_minus[k]->Draw("e1sames");
    
    h_Systematics_es_raw_plus[k]->SetMarkerStyle(26);
    h_Systematics_es_raw_plus[k]->SetLineColor(kRed+4);
    h_Systematics_es_raw_plus[k]->SetMarkerColor(kRed+4);
    h_Systematics_es_raw_plus[k]->SetLineWidth(2);
    h_Systematics_es_raw_plus[k]->SetTitle(name_h);
    h_Systematics_es_raw_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Systematics_es_raw_plus[k]->GetYaxis()->SetTitle("#Delta");
    h_Systematics_es_raw_plus[k]->Draw("e1sames");
    h_Systematics_es_raw_minus[k]->SetLineColor(kRed+4);
    h_Systematics_es_raw_minus[k]->SetMarkerColor(kRed+4);
    h_Systematics_es_raw_minus[k]->SetMarkerStyle(26);
    h_Systematics_es_raw_minus[k]->SetLineWidth(2);
    h_Systematics_es_raw_minus[k]->Draw("e1sames");


    h_Systematics_bkg_raw_plus[k]->SetLineWidth(2);
    h_Systematics_bkg_raw_plus[k]->SetMarkerStyle(21);
    h_Systematics_bkg_raw_plus[k]->SetLineColor(4);
    h_Systematics_bkg_raw_plus[k]->SetMarkerColor(4);
    h_Systematics_bkg_raw_plus[k]->Draw("e1sames");
    h_Systematics_bkg_raw_minus[k]->SetLineWidth(2);
    h_Systematics_bkg_raw_minus[k]->SetLineColor(4);
    h_Systematics_bkg_raw_minus[k]->SetMarkerColor(4);
    h_Systematics_bkg_raw_minus[k]->SetMarkerStyle(21);
    h_Systematics_bkg_raw_minus[k]->Draw("e1sames");

    h_Systematics_sin_raw_plus[k]->SetLineWidth(2);
    h_Systematics_sin_raw_plus[k]->SetMarkerStyle(22);
    h_Systematics_sin_raw_plus[k]->SetLineColor(kYellow+3);
    h_Systematics_sin_raw_plus[k]->SetMarkerColor(kYellow+3);
    h_Systematics_sin_raw_plus[k]->Draw("e1sames");
    h_Systematics_sin_raw_minus[k]->SetLineWidth(2);
    h_Systematics_sin_raw_minus[k]->SetMarkerStyle(22);
    h_Systematics_sin_raw_minus[k]->SetLineColor(kYellow+3);
    h_Systematics_sin_raw_minus[k]->SetMarkerColor(kYellow+3);
    h_Systematics_sin_raw_minus[k]->Draw("e1sames");

    h_MC_Raw_alignment_total_plus[k]->SetLineWidth(2);
    h_MC_Raw_alignment_total_plus[k]->SetMarkerStyle(23);
    h_MC_Raw_alignment_total_plus[k]->SetLineColor(kGreen+2);
    h_MC_Raw_alignment_total_plus[k]->SetMarkerColor(kGreen+2);
    h_MC_Raw_alignment_total_plus[k]->Draw("e1sames");
    h_MC_Raw_alignment_total_minus[k]->SetLineWidth(2);
    h_MC_Raw_alignment_total_minus[k]->SetMarkerStyle(23);
    h_MC_Raw_alignment_total_minus[k]->SetMarkerColor(kGreen+2);
    h_MC_Raw_alignment_total_minus[k]->SetLineColor(kGreen+2);
    h_MC_Raw_alignment_total_minus[k]->Draw("e1sames");

    h_envelope_sigma_plus[k]->SetMarkerStyle(24);
    h_envelope_sigma_plus[k]->SetLineWidth(2);
    h_envelope_sigma_plus[k]->SetLineColor(6);
    h_envelope_sigma_plus[k]->SetMarkerColor(6);
    h_envelope_sigma_plus[k]->Draw("e1sames");
    h_envelope_sigma_minus[k]->SetMarkerStyle(24);
    h_envelope_sigma_minus[k]->SetLineWidth(2);
    h_envelope_sigma_minus[k]->SetLineColor(6);
    h_envelope_sigma_minus[k]->SetMarkerColor(6);
    h_envelope_sigma_minus[k]->Draw("e1sames");

    h_total_plus[k]->SetLineWidth(2);
    h_total_plus[k]->SetLineColor(1);
    h_total_plus[k]->SetMarkerColor(1);
    h_total_plus[k]->SetMarkerStyle(25);
    h_total_plus[k]->Draw("e1sames");
    h_total_minus[k]->SetLineWidth(2);
    h_total_minus[k]->SetLineColor(1);
    h_total_minus[k]->SetLineStyle(1);
    h_total_minus[k]->SetMarkerColor(1);
    h_total_minus[k]->SetMarkerStyle(25);
    h_total_minus[k]->Draw("e1sames");
  }
  c30->SaveAs("systematic_uncertainties_RAW_on_top_of_each_other.C");


  TCanvas *c31 = new TCanvas();
  c31->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c31->cd(k+1);
    gPad->SetLogx();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_Systematics_fsr_bare_plus[k]->GetYaxis()->SetRangeUser(-0.18,0.18);
    h_Systematics_fsr_bare_plus[k]->SetMarkerStyle(20);
    h_Systematics_fsr_bare_plus[k]->SetLineColor(2);
    h_Systematics_fsr_bare_plus[k]->SetMarkerColor(2);
    h_Systematics_fsr_bare_plus[k]->SetLineWidth(2);
    h_Systematics_fsr_bare_plus[k]->SetTitle(name_h);
    h_Systematics_fsr_bare_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Systematics_fsr_bare_plus[k]->GetYaxis()->SetTitle("#Delta");
    h_Systematics_fsr_bare_plus[k]->Draw("e1");
    h_Systematics_fsr_bare_minus[k]->SetLineColor(2);
    h_Systematics_fsr_bare_minus[k]->SetMarkerColor(2);
    h_Systematics_fsr_bare_minus[k]->SetMarkerStyle(20);
    h_Systematics_fsr_bare_minus[k]->SetLineWidth(2);
    h_Systematics_fsr_bare_minus[k]->Draw("e1sames");


    h_Systematics_es_bare_plus[k]->SetMarkerStyle(26);
    h_Systematics_es_bare_plus[k]->SetLineColor(kRed+4);
    h_Systematics_es_bare_plus[k]->SetMarkerColor(kRed+4);
    h_Systematics_es_bare_plus[k]->SetLineWidth(2);
    h_Systematics_es_bare_plus[k]->SetTitle(name_h);
    h_Systematics_es_bare_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Systematics_es_bare_plus[k]->GetYaxis()->SetTitle("#Delta");
    h_Systematics_es_bare_plus[k]->Draw("e1sames");
    h_Systematics_es_bare_minus[k]->SetLineColor(kRed+4);
    h_Systematics_es_bare_minus[k]->SetMarkerColor(kRed+4);
    h_Systematics_es_bare_minus[k]->SetMarkerStyle(26);
    h_Systematics_es_bare_minus[k]->SetLineWidth(2);
    h_Systematics_es_bare_minus[k]->Draw("e1sames");



    h_Systematics_bkg_bare_plus[k]->SetLineWidth(2);
    h_Systematics_bkg_bare_plus[k]->SetMarkerStyle(21);
    h_Systematics_bkg_bare_plus[k]->SetLineColor(4);
    h_Systematics_bkg_bare_plus[k]->SetMarkerColor(4);
    h_Systematics_bkg_bare_plus[k]->Draw("e1sames");
    h_Systematics_bkg_bare_minus[k]->SetLineWidth(2);
    h_Systematics_bkg_bare_minus[k]->SetLineColor(4);
    h_Systematics_bkg_bare_minus[k]->SetMarkerColor(4);
    h_Systematics_bkg_bare_minus[k]->SetMarkerStyle(21);
    h_Systematics_bkg_bare_minus[k]->Draw("e1sames");

    h_Systematics_sin_bare_plus[k]->SetLineWidth(2);
    h_Systematics_sin_bare_plus[k]->SetMarkerStyle(22);
    h_Systematics_sin_bare_plus[k]->SetLineColor(kYellow+3);
    h_Systematics_sin_bare_plus[k]->SetMarkerColor(kYellow+3);
    h_Systematics_sin_bare_plus[k]->Draw("e1sames");
    h_Systematics_sin_bare_minus[k]->SetLineWidth(2);
    h_Systematics_sin_bare_minus[k]->SetMarkerStyle(22);
    h_Systematics_sin_bare_minus[k]->SetLineColor(kYellow+3);
    h_Systematics_sin_bare_minus[k]->SetMarkerColor(kYellow+3);
    h_Systematics_sin_bare_minus[k]->Draw("e1sames");

    h_MC_Bare_alignment_total_plus[k]->SetLineWidth(2);
    h_MC_Bare_alignment_total_plus[k]->SetMarkerStyle(23);
    h_MC_Bare_alignment_total_plus[k]->SetLineColor(kGreen+2);
    h_MC_Bare_alignment_total_plus[k]->SetMarkerColor(kGreen+2);
    h_MC_Bare_alignment_total_plus[k]->Draw("e1sames");
    h_MC_Bare_alignment_total_minus[k]->SetLineWidth(2);
    h_MC_Bare_alignment_total_minus[k]->SetMarkerStyle(23);
    h_MC_Bare_alignment_total_minus[k]->SetMarkerColor(kGreen+2);
    h_MC_Bare_alignment_total_minus[k]->SetLineColor(kGreen+2);
    h_MC_Bare_alignment_total_minus[k]->Draw("e1sames");

    h_envelope_sigma_plus[k]->SetMarkerStyle(24);
    h_envelope_sigma_plus[k]->SetLineWidth(2);
    h_envelope_sigma_plus[k]->SetLineColor(6);
    h_envelope_sigma_plus[k]->SetMarkerColor(6);
    h_envelope_sigma_plus[k]->Draw("e1sames");
    h_envelope_sigma_minus[k]->SetMarkerStyle(24);
    h_envelope_sigma_minus[k]->SetLineWidth(2);
    h_envelope_sigma_minus[k]->SetLineColor(6);
    h_envelope_sigma_minus[k]->SetMarkerColor(6);
    h_envelope_sigma_minus[k]->Draw("e1sames");

    h_total_plus_undet[k]->SetLineWidth(2);
    h_total_plus_undet[k]->SetLineStyle(1);
    h_total_plus_undet[k]->SetLineColor(1);
    h_total_plus_undet[k]->SetMarkerStyle(25);
    h_total_plus_undet[k]->Draw("sames");
    h_total_minus_undet[k]->SetLineWidth(2);
    h_total_minus_undet[k]->SetLineStyle(1);
    h_total_minus_undet[k]->SetLineColor(1);
    h_total_minus_undet[k]->SetMarkerStyle(25);
    h_total_minus_undet[k]->Draw("sames");
  }
  c31->SaveAs("systematic_uncertainties_BARE_LEPTON_on_top_of_each_other.C");

   TCanvas *c32 = new TCanvas();
  c32->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c32->cd(k+1);
    gPad->SetLogx();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_Systematics_fsr_Born_plus[k]->GetYaxis()->SetRangeUser(-0.18,0.18);
    h_Systematics_fsr_Born_plus[k]->SetMarkerStyle(20);
    h_Systematics_fsr_Born_plus[k]->SetLineColor(2);
    h_Systematics_fsr_Born_plus[k]->SetMarkerColor(2);
    h_Systematics_fsr_Born_plus[k]->SetLineWidth(2);
    h_Systematics_fsr_Born_plus[k]->SetTitle(name_h);
    h_Systematics_fsr_Born_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Systematics_fsr_Born_plus[k]->GetYaxis()->SetTitle("#Delta");
    h_Systematics_fsr_Born_plus[k]->Draw("e1");
    h_Systematics_fsr_Born_minus[k]->SetLineColor(2);
    h_Systematics_fsr_Born_minus[k]->SetMarkerColor(2);
    h_Systematics_fsr_Born_minus[k]->SetMarkerStyle(20);
    h_Systematics_fsr_Born_minus[k]->SetLineWidth(2);
    h_Systematics_fsr_Born_minus[k]->Draw("e1sames");
   
    h_Systematics_es_Born_plus[k]->GetYaxis()->SetRangeUser(-0.18,0.18);
    h_Systematics_es_Born_plus[k]->SetMarkerStyle(20);
    h_Systematics_es_Born_plus[k]->SetLineColor(2);
    h_Systematics_es_Born_plus[k]->SetMarkerColor(2);
    h_Systematics_es_Born_plus[k]->SetLineWidth(2);
    h_Systematics_es_Born_plus[k]->SetTitle(name_h);
    h_Systematics_es_Born_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Systematics_es_Born_plus[k]->GetYaxis()->SetTitle("#Delta");
    h_Systematics_es_Born_plus[k]->Draw("e1sames");
    h_Systematics_es_Born_minus[k]->SetLineColor(2);
    h_Systematics_es_Born_minus[k]->SetMarkerColor(2);
    h_Systematics_es_Born_minus[k]->SetMarkerStyle(20);
    h_Systematics_es_Born_minus[k]->SetLineWidth(2);
    h_Systematics_es_Born_minus[k]->Draw("e1sames");

 
    h_Systematics_bkg_Born_plus[k]->SetLineWidth(2);
    h_Systematics_bkg_Born_plus[k]->SetMarkerStyle(21);
    h_Systematics_bkg_Born_plus[k]->SetLineColor(4);
    h_Systematics_bkg_Born_plus[k]->SetMarkerColor(4);
    h_Systematics_bkg_Born_plus[k]->Draw("e1sames");
    h_Systematics_bkg_Born_minus[k]->SetLineWidth(2);
    h_Systematics_bkg_Born_minus[k]->SetLineColor(4);
    h_Systematics_bkg_Born_minus[k]->SetMarkerColor(4);
    h_Systematics_bkg_Born_minus[k]->SetMarkerStyle(21);
    h_Systematics_bkg_Born_minus[k]->Draw("e1sames");

    h_Systematics_sin_Born_plus[k]->SetLineWidth(2);
    h_Systematics_sin_Born_plus[k]->SetMarkerStyle(22);
    h_Systematics_sin_Born_plus[k]->SetLineColor(kYellow+3);
    h_Systematics_sin_Born_plus[k]->SetMarkerColor(kYellow+3);
    h_Systematics_sin_Born_plus[k]->Draw("e1sames");
    h_Systematics_sin_Born_minus[k]->SetLineWidth(2);
    h_Systematics_sin_Born_minus[k]->SetMarkerStyle(22);
    h_Systematics_sin_Born_minus[k]->SetLineColor(kYellow+3);
    h_Systematics_sin_Born_minus[k]->SetMarkerColor(kYellow+3);
    h_Systematics_sin_Born_minus[k]->Draw("e1sames");

    h_MC_Born_alignment_total_plus[k]->SetLineWidth(2);
    h_MC_Born_alignment_total_plus[k]->SetMarkerStyle(23);
    h_MC_Born_alignment_total_plus[k]->SetLineColor(kGreen+2);
    h_MC_Born_alignment_total_plus[k]->SetMarkerColor(kGreen+2);
    h_MC_Born_alignment_total_plus[k]->Draw("e1sames");
    h_MC_Born_alignment_total_minus[k]->SetLineWidth(2);
    h_MC_Born_alignment_total_minus[k]->SetMarkerStyle(23);
    h_MC_Born_alignment_total_minus[k]->SetMarkerColor(kGreen+2);
    h_MC_Born_alignment_total_minus[k]->SetLineColor(kGreen+2);
    h_MC_Born_alignment_total_minus[k]->Draw("e1sames");

    h_envelope_sigma_plus[k]->SetMarkerStyle(24);
    h_envelope_sigma_plus[k]->SetLineWidth(2);
    h_envelope_sigma_plus[k]->SetLineColor(6);
    h_envelope_sigma_plus[k]->SetMarkerColor(6);
    h_envelope_sigma_plus[k]->Draw("e1sames");
    h_envelope_sigma_minus[k]->SetMarkerStyle(24);
    h_envelope_sigma_minus[k]->SetLineWidth(2);
    h_envelope_sigma_minus[k]->SetLineColor(6);
    h_envelope_sigma_minus[k]->SetMarkerColor(6);
    h_envelope_sigma_minus[k]->Draw("e1sames");

    h_total_plus_nofsr[k]->SetLineWidth(2);
    h_total_plus_nofsr[k]->SetLineStyle(1);
    h_total_plus_nofsr[k]->SetLineColor(1);
    h_total_plus_nofsr[k]->SetMarkerStyle(25);
    h_total_plus_nofsr[k]->Draw("sames");
    h_total_minus_nofsr[k]->SetLineWidth(2);
    h_total_minus_nofsr[k]->SetLineStyle(1);
    h_total_minus_nofsr[k]->SetLineColor(1);
    h_total_minus_nofsr[k]->SetMarkerStyle(25);
    h_total_minus_nofsr[k]->Draw("sames");
  }
  c32->SaveAs("systematic_uncertainties_BORN_on_top_of_each_other.C");


  TCanvas *c33 = new TCanvas();
  c33->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c33->cd(k+1);
    gPad->SetLogx();  
    h_MC_True_AFB[k]->GetYaxis()->SetRangeUser(-1,1);
    h_MC_True_AFB[k]->SetLineWidth(2);
    h_MC_True_AFB[k]->SetLineColor(4);
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_True_AFB[k]->SetTitle(name_h);
    h_MC_True_AFB[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_MC_True_AFB[k]->GetYaxis()->SetTitle("A_{FB}");
    h_MC_True_AFB[k]->Draw();

    gr_Parton[k]->SetMarkerStyle(8);
    gr_Parton[k]->SetLineWidth(2);
    gr_Parton[k]->Draw("p");

  }
  c33->SaveAs("afb_parton.C");


  TCanvas *c34 = new TCanvas();
  c34->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c34->cd(k+1);
    gPad->SetLogx();
    h_MC_Raw_AFB_ES_Diff_Up[k]->SetLineWidth(2);
    h_MC_Raw_AFB_ES_Diff_Up[k]->SetLineColor(4);
    h_MC_Raw_AFB_ES_Diff_Up[k]->GetYaxis()->SetRangeUser(-0.002,0.002);
    h_MC_Raw_AFB_ES_Diff_Up[k]->GetYaxis()->SetTitle("A_{FB}(raw)-A_{FB}(ES Scaled)");
    h_MC_Raw_AFB_ES_Diff_Up[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Raw_AFB_ES_Diff_Up[k]->SetTitle(name_h);
    h_MC_Raw_AFB_ES_Diff_Up[k]->Draw();
    h_MC_Raw_AFB_ES_Diff_Down[k]->SetLineWidth(2);
    h_MC_Raw_AFB_ES_Diff_Down[k]->SetLineColor(2);
    h_MC_Raw_AFB_ES_Diff_Down[k]->Draw("sames");
  }
  c34->SaveAs("es_uncertainty_at_raw.C");

  TCanvas *c35 = new TCanvas();
  c35->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c35->cd(k+1);
    gPad->SetLogx();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_UnDet_AFB_ES_Diff_Up[k]->SetLineWidth(2);
    h_MC_UnDet_AFB_ES_Diff_Up[k]->SetLineColor(4);
    h_MC_UnDet_AFB_ES_Diff_Up[k]->GetYaxis()->SetRangeUser(-0.002,0.002);
    h_MC_UnDet_AFB_ES_Diff_Up[k]->GetYaxis()->SetTitle("A_{FB}(raw)-A_{FB}(ES Scaled)");
    h_MC_UnDet_AFB_ES_Diff_Up[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_UnDet_AFB_ES_Diff_Up[k]->SetTitle(name_h);
    h_MC_UnDet_AFB_ES_Diff_Up[k]->Draw();
    h_MC_UnDet_AFB_ES_Diff_Down[k]->SetLineWidth(2);
    h_MC_UnDet_AFB_ES_Diff_Down[k]->SetLineColor(2);
    h_MC_UnDet_AFB_ES_Diff_Down[k]->Draw("sames");
  }
  c35->SaveAs("es_uncertainty_at_bare_lepton.C");

  TCanvas *c36 = new TCanvas();
  c36->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c36->cd(k+1);
    gPad->SetLogx();
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[k]->SetLineColor(4);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[k]->GetYaxis()->SetRangeUser(-0.002,0.002);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[k]->GetYaxis()->SetTitle("A_{FB}(Born)-A_{FB}(FSR Scaled)");
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[k]->SetTitle(name_h);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[k]->Draw();
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Down[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Down[k]->SetLineColor(2);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Down[k]->Draw("sames");
  }
  c36->SaveAs("es_uncertainty_at_born_level.C");


//eof parton

}//end void

int main(int argc,char **argv){
  tree1r();
}

double AFB(double forward, double backward)
{
  float afb = (forward-backward)/(forward+backward);
  return afb;
}

double RAWAFBERROR(double rawafb, double forward, double backward)
{
  double rawerror = (1-rawafb*rawafb)/(forward+backward);
  rawerror = sqrt(rawerror);
  return rawerror;
}


