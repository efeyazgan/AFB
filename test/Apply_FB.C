#include "afbbase.h"

using namespace std;

void tree1r()
{

  double AFB(double forward, double backward);
  double RAWAFBERROR(double rawafb, double forward, double backward);

  int nb = 10;
  int nb_sin = 8;
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
  xAxis_AFB[10] = 600;
  xAxis_AFB[11] = 1500;

  //  int nb_Y = 4;
  float Y_bin_limits[nb_Y+1];
  Y_bin_limits[0] = 0.0;
  Y_bin_limits[1] = 1.0;
  Y_bin_limits[2] = 1.25;
  Y_bin_limits[3] = 1.5;
  Y_bin_limits[4] = 2.1;

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
  TH2D *Inv_Response_UnDetector_Forward_PDF_mstw[nb_Y];
  TH2D *Inv_Response_UnDetector_Backward_PDF_mstw[nb_Y];
  TH2D *Inv_Response_NoFsr_Forward_PDF_mstw[nb_Y];
  TH2D *Inv_Response_NoFsr_Backward_PDF_mstw[nb_Y];

  TH1D *hMeasCos_M_Y_Forward_PDF_nnpdf[nb_Y][n_nnpdf];
  TH1D *hMeasCos_M_Y_Backward_PDF_nnpdf[nb_Y][n_nnpdf];
  TH2D *Inv_Response_UnDetector_Forward_PDF_nnpdf[nb_Y];
  TH2D *Inv_Response_UnDetector_Backward_PDF_nnpdf[nb_Y];
  TH2D *Inv_Response_NoFsr_Forward_PDF_nnpdf[nb_Y];
  TH2D *Inv_Response_NoFsr_Backward_PDF_nnpdf[nb_Y];

  TH1D *hMeasCos_M_Y_Forward_PDF_alpha_s[nb_Y][ct10as_index];
  TH1D *hMeasCos_M_Y_Backward_PDF_alpha_s[nb_Y][ct10as_index];
  TH2D *Inv_Response_UnDetector_Forward_PDF_alpha_s[nb_Y];
  TH2D *Inv_Response_UnDetector_Backward_PDF_alpha_s[nb_Y];
  TH2D *Inv_Response_NoFsr_Forward_PDF_alpha_s[nb_Y];
  TH2D *Inv_Response_NoFsr_Backward_PDF_alpha_s[nb_Y];


  float delta_plus = -999.;
  float delta_minus = -999.;
  float afb_p = -999.;
  float afb_m = -999.;
  float afb_0 = -999.;
  float afb_nnpdf = -999.;
  float afb_alphas0 = -999.;
  float afb_alphas5 = -999.;
  float afb_alphas10 = -999.;

  float DeltaXmaxPlus[nb][nb_Y];
  float DeltaXmaxMinus[nb][nb_Y];
  float sigma[nb][nb_Y];


  TFile input_fsr_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated.root","read");
  TFile input_data_file("RootFiles/MUON_DATA_DYbins.root","read");
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
  TFile input_Align_Ideal_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Ideal.root","read");
  TFile input_Align_Startup_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Startup.root","read");
  TFile input_PDF_ct10_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_CT10.root","read");
  TFile input_PDF_mstw_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_MSTW.root","read");
  TFile input_PDF_nnpdf_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_NNPDF.root","read");
  TFile input_PDF_alpha_s_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_ALPHA_S.root","read");


  for (int j=0;j<nb_Y;j++){
    sprintf(name_h,"MC_meas_Forward_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"MC_meas_Backward_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Backward[j]);

    sprintf(name_h,"MC_meas_Forward_FSR_UP_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Forward_FSR_UP[j]);
    sprintf(name_h,"MC_meas_Backward_FSR_UP_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Backward_FSR_UP[j]);
    sprintf(name_h,"MC_meas_Forward_FSR_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Forward_FSR_DOWN[j]);
    sprintf(name_h,"MC_meas_Backward_FSR_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Backward_FSR_DOWN[j]);

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

    sprintf(name_h,"MC_DATA_meas_Forward_%i",j);
    input_data_file.GetObject(name_h,hDataMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"MC_DATA_meas_Backward_%i",j);
    input_data_file.GetObject(name_h,hDataMeasCos_M_Y_Backward[j]);


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
    //   for (int jjj = 0;jjj<nb;jjj++) cout<<j<<"  "<<jjj<<"   "<<Align_Ideal_hMeasCos_M_Y_Forward[j]->GetBinContent(jjj+1)<<endl;
    sprintf(name_h,"Align_Ideal_MC_meas_Backward_%i",j);
    input_Align_Ideal_file.GetObject(name_h,Align_Ideal_hMeasCos_M_Y_Backward[j]);


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

    //eo pdf
  } 




  double Raw_AFB[nb];
  double Raw_error[nb];
  double MC_Raw_AFB[nb];
  double MC_Raw_AFB_FSR_UP[nb];
  double MC_Raw_AFB_FSR_DOWN[nb];
  double MC_Raw_AFB_FSR_Diff_Up[nb];
  double MC_Raw_AFB_FSR_Diff_Down[nb];

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
  double MC_Unfolded_NoFsr_Forward_FSR_Up[nb_Y][nb];
  double MC_Unfolded_NoFsr_Forward_FSR_Down[nb_Y][nb];
  double MC_Unfolded_NoFsr_Backward_FSR_Up[nb_Y][nb];
  double MC_Unfolded_NoFsr_Backward_FSR_Down[nb_Y][nb];
  double MC_Unfolded_NoFsr_AFB_FSR_Up[nb];
  double MC_Unfolded_NoFsr_AFB_FSR_Down[nb];

  double Unfolded_NoFsr_AFB[nb_Y];
  double first_sum_fsr[nb];
  double second_sum_fsr[nb];
  double Unfolded_NoFsr_error[nb];
  double MC_NoFsr_AFB[nb];
  double error_closure_forward[nb];
  double error_closure_backward[nb];
  double error_forward[nb];
  double error_backward[nb];

  for (int k=0;k<nb_Y;k++){
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
      MC_Unfolded_NoFsr_Forward_FSR_Up[k][i] = 0;
      MC_Unfolded_NoFsr_Forward_FSR_Down[k][i] = 0;
      MC_Unfolded_NoFsr_Backward_FSR_Up[k][i] = 0;
      MC_Unfolded_NoFsr_Backward_FSR_Down[k][i] = 0;
      MC_Unfolded_NoFsr_AFB_FSR_Up[i] = 0;
      MC_Unfolded_NoFsr_AFB_FSR_Down[i] = 0;	
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
      MC_Raw_AFB[i] = 0;
      MC_Raw_AFB_FSR_UP[i] = 0;
      MC_Raw_AFB_FSR_DOWN[i] = 0;
      MC_Raw_AFB_FSR_Diff_Up[i] = 0;
      MC_Raw_AFB_FSR_Diff_Down[i] = 0;
      MC_UnDet_AFB[i] = 0;
      MC_UnDet_AFB_FSR_UP[i] = 0;
      MC_UnDet_AFB_FSR_DOWN[i] = 0;
      MC_UnDet_AFB_FSR_Diff_Up[i] = 0;
      MC_UnDet_AFB_FSR_Diff_Down[i] = 0;
      MC_NoFsr_AFB[i] = 0;
      error_closure_forward[i] = 0;
      error_closure_backward[i] = 0;
      error_forward[i] = 0;
      error_backward[i] = 0;	
      //pdf
      DeltaXmaxPlus[i][k] = 0;
      DeltaXmaxMinus[i][k] = 0;
      sigma[i][k] = 0;
      //
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

	MC_Unfolded_NoFsr_Forward_FSR_Up[k][i] += Inv_Response_NoFsr_Forward_FSR_UP[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_FSR_UP[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_Forward_FSR_Down[k][i] += Inv_Response_NoFsr_Forward_FSR_DOWN[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_FSR_DOWN[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_Backward_FSR_Up[k][i] += Inv_Response_NoFsr_Backward_FSR_UP[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_FSR_UP[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_Backward_FSR_Down[k][i] += Inv_Response_NoFsr_Backward_FSR_DOWN[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_FSR_DOWN[k]->GetBinContent(j+1);
      }
      Raw_AFB[i] = AFB(hDataMeasCos_M_Y_Forward[k]->GetBinContent(i+1),hDataMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      Raw_error[i] = RAWAFBERROR(Raw_AFB[i],hDataMeasCos_M_Y_Forward[k]->GetBinContent(i+1),hDataMeasCos_M_Y_Backward[k]->GetBinContent(i+1));

      h_Raw_AFB[k]->SetBinContent(i+1,Raw_AFB[i]);
      h_Raw_AFB[k]->SetBinError(i+1,Raw_error[i]);

      MC_Raw_AFB[i] = AFB(hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      h_MC_Raw_AFB[k]->SetBinContent(i+1,MC_Raw_AFB[i]);
      MC_Raw_AFB_FSR_UP[i] = AFB(hMeasCos_M_Y_Forward_FSR_UP[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward_FSR_UP[k]->GetBinContent(i+1));
      h_MC_Raw_AFB_FSR_UP[k]->SetBinContent(i+1,MC_Raw_AFB_FSR_UP[i]);
      MC_Raw_AFB_FSR_DOWN[i] = AFB(hMeasCos_M_Y_Forward_FSR_DOWN[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward_FSR_DOWN[k]->GetBinContent(i+1));
      h_MC_Raw_AFB_FSR_DOWN[k]->SetBinContent(i+1,MC_Raw_AFB_FSR_DOWN[i]);
      float diff1 = MC_Raw_AFB_FSR_UP[i]-MC_Raw_AFB[i];
      float diff2 = MC_Raw_AFB_FSR_DOWN[i]-MC_Raw_AFB[i];
      //fsr table raw level
      /*
	if (k == 0 && i == 0){ 
	cout<<"FSR SYSTEMATICS (RAW LEVEL)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
	cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff1<<"  &  "<<setprecision(3)<<diff2<<"    \\\\    "<<endl;
      */ //end of fsr table raw level
      MC_Raw_AFB_FSR_Diff_Up[i] = diff1;//TMath::Max(diff1,diff2);
      MC_Raw_AFB_FSR_Diff_Down[i] = diff2;//TMath::Min(diff1,diff2);
      h_MC_Raw_AFB_FSR_Diff_Up[k]->SetBinContent(i+1,MC_Raw_AFB_FSR_Diff_Up[i]);
      h_MC_Raw_AFB_FSR_Diff_Down[k]->SetBinContent(i+1,MC_Raw_AFB_FSR_Diff_Down[i]);

      MC_UnDet_AFB[i] = AFB(hUnDetectorCos_M_Y_Forward[k]->GetBinContent(i+1),hUnDetectorCos_M_Y_Backward[k]->GetBinContent(i+1));
      h_MC_UnDet_AFB[k]->SetBinContent(i+1,MC_UnDet_AFB[i]);

      //fsr systematics bare lepton level
      MC_UnDet_AFB_FSR_UP[i] = AFB(hUnDetectorCos_M_Y_Forward_FSR_UP[k]->GetBinContent(i+1),hUnDetectorCos_M_Y_Backward_FSR_UP[k]->GetBinContent(i+1));
      h_MC_UnDet_AFB_FSR_UP[k]->SetBinContent(i+1,MC_UnDet_AFB_FSR_UP[i]);
      MC_UnDet_AFB_FSR_DOWN[i] = AFB(hUnDetectorCos_M_Y_Forward_FSR_DOWN[k]->GetBinContent(i+1),hUnDetectorCos_M_Y_Backward_FSR_DOWN[k]->GetBinContent(i+1));
      h_MC_UnDet_AFB_FSR_DOWN[k]->SetBinContent(i+1,MC_UnDet_AFB_FSR_DOWN[i]);
      float diff_NoDet1 = MC_UnDet_AFB_FSR_UP[i]-MC_UnDet_AFB[i];
      float diff_NoDet2 = MC_UnDet_AFB_FSR_DOWN[i]-MC_UnDet_AFB[i];
      /* //fsr table bare level
	 if (k == 0 && i == 0){ 
	 cout<<"FSR SYSTEMATICS (BARE LEPTON LEVEL)"<<endl;
	 cout<<"---------------"<<endl;
	 cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
	 cout<<"-------------------------------------------------------------------"<<endl;
	 }
	 cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff1<<"  &  "<<setprecision(3)<<diff2<<"    \\\\    "<<endl;
      */ //end of fsr table bare lepton level
      MC_UnDet_AFB_FSR_Diff_Up[i] = diff_NoDet1;//TMath::Max(diff1,diff2);
      MC_UnDet_AFB_FSR_Diff_Down[i] = diff_NoDet2;//TMath::Min(diff1,diff2);
      h_MC_UnDet_AFB_FSR_Diff_Up[k]->SetBinContent(i+1,MC_UnDet_AFB_FSR_Diff_Up[i]);
      h_MC_UnDet_AFB_FSR_Diff_Down[k]->SetBinContent(i+1,MC_UnDet_AFB_FSR_Diff_Down[i]);
      //

      MC_NoFsr_AFB[i] = AFB(hNoFsrTruthCos_M_Y_Forward[k]->GetBinContent(i+1),hNoFsrTruthCos_M_Y_Backward[k]->GetBinContent(i+1));
      h_MC_NoFsr_AFB[k]->SetBinContent(i+1,MC_NoFsr_AFB[i]);

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
      float diff_undet1 = MC_Unfolded_NoFsr_AFB_FSR_Up[i]-Closure_Unfolded_NoFsr_AFB[i];//-MC_UnDet_AFB[i];
      float diff_undet2 = MC_Unfolded_NoFsr_AFB_FSR_Down[i]-Closure_Unfolded_NoFsr_AFB[i];//-MC_UnDet_AFB[i];
      h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Up[k]->SetBinContent(i+1,diff_undet1);
      h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Down[k]->SetBinContent(i+1,diff_undet2);
      /*fsr systematics born level table
	if (k == 0 && i == 0){ 
	cout<<"FSR SYSTEMATICS (Born Level)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
	cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_undet1<<"  &  "<<setprecision(3)<<diff_undet2<<"    \\\\    "<<endl;
      */ //end of fsr systematics born level table

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
      diff1 = MC_Unfolded_UnDet_sin2412_AFB[i]-MC_Unfolded_UnDet_sin2312_AFB[i];
      diff2 = MC_Unfolded_UnDet_sin2212_AFB[i]-MC_Unfolded_UnDet_sin2312_AFB[i];
      h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[k]->SetBinContent(i+1,diff1);
      h_MC_Unfolded_UnDet_AFB_Diff_sin2212m2312[k]->SetBinContent(i+1,diff2);
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
      diff1 = MC_Unfolded_NoFsr_sin2412_AFB[i]-MC_Unfolded_NoFsr_sin2312_AFB[i];
      diff2 = MC_Unfolded_NoFsr_sin2212_AFB[i]-MC_Unfolded_NoFsr_sin2312_AFB[i];
      h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[k]->SetBinContent(i+1,diff1);
      h_MC_Unfolded_NoFsr_AFB_Diff_sin2212m2312[k]->SetBinContent(i+1,diff2);
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

    }//eo alignment loop


    for (int i=0;i<nb;i++){ //pdf loop
      afb_0 = AFB(hMeasCos_M_Y_Forward_PDF_ct10[k][0]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_ct10[k][0]->GetBinContent(i+1));


      afb_alphas0 = AFB(hMeasCos_M_Y_Forward_PDF_alpha_s[k][0]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_alpha_s[k][0]->GetBinContent(i+1));
      afb_alphas5 = AFB(hMeasCos_M_Y_Forward_PDF_alpha_s[k][5]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_alpha_s[k][5]->GetBinContent(i+1));
      afb_alphas10 = AFB(hMeasCos_M_Y_Forward_PDF_alpha_s[k][10]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_alpha_s[k][10]->GetBinContent(i+1));  
      h_Delta_AFB_alphas_PLUS[k]->SetBinContent(i+1,afb_alphas10-afb_alphas5);
      h_Delta_AFB_alphas_MINUS[k]->SetBinContent(i+1,afb_alphas0-afb_alphas5);


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
	}
	DeltaXmaxPlus[i][k] = sqrt(DeltaXmaxPlus[i][k]);
	DeltaXmaxMinus[i][k] = sqrt(DeltaXmaxMinus[i][k]);
	h_DeltaXmaxPlus_ct10[k]->SetBinContent(i+1,DeltaXmaxPlus[i][k]);
	h_DeltaXmaxMinus_ct10[k]->SetBinContent(i+1,DeltaXmaxMinus[i][k]);
	float DeltaX_CT10_ALPHAS_PLUS = sqrt(pow(DeltaXmaxPlus[i][k],2)+pow(afb_alphas10-afb_alphas5,2));
	float DeltaX_CT10_ALPHAS_MINUS = sqrt(pow(DeltaXmaxMinus[i][k],2)+pow(afb_alphas0-afb_alphas5,2));
	h_DeltaX_CT10_ALPHAS_PLUS[k]->SetBinContent(i+1,DeltaX_CT10_ALPHAS_PLUS);
	h_DeltaX_CT10_ALPHAS_MINUS[k]->SetBinContent(i+1,DeltaX_CT10_ALPHAS_MINUS);
	DeltaXmaxPlus[i][k] = 0;
	DeltaXmaxMinus[i][k] = 0;
	for (int pdfindex=1; pdfindex<n_mstw; pdfindex+=2){
	  afb_p = AFB(hMeasCos_M_Y_Forward_PDF_mstw[k][pdfindex]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_mstw[k][pdfindex]->GetBinContent(i+1));
	  afb_m = AFB(hMeasCos_M_Y_Forward_PDF_mstw[k][pdfindex+1]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_mstw[k][pdfindex+1]->GetBinContent(i+1));
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
    }
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
    h_MC_Raw_AFB[k]->Draw();
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
    h_Unfolded_NoFsr_AFB[k]->SetMarkerStyle(25);
    h_Unfolded_NoFsr_AFB[k]->SetMarkerColor(4);
    h_Unfolded_NoFsr_AFB[k]->SetLineColor(4);
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

 TCanvas *r17 = new TCanvas();
  r17->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r17->cd(k+1);
    gPad->SetLogx();
    h_DeltaXmaxPlus_mstw[k]->SetLineWidth(2);
    h_DeltaXmaxPlus_mstw[k]->SetLineColor(4);
    h_DeltaXmaxPlus_mstw[k]->GetYaxis()->SetRangeUser(0.,0.052);
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
    h_Delta_AFB_alphas_PLUS[k]->GetYaxis()->SetRangeUser(-0.003,0.003);
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


