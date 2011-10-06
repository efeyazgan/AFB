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




  TFile input_fsr_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated.root","read");
  TFile input_data_file("RootFiles/MUON_DATA_DYbins.root","read");
  TFile input_sin2312_file("RootFiles/sin2thetaW2312_MUON_MC_Meas_NoFsr.root","read");
  TFile input_sin2412_file("RootFiles/sin2thetaW2412_MUON_MC_Meas_NoFsr.root","read");
  TFile input_sin2212_file("RootFiles/sin2thetaW2212_MUON_MC_Meas_NoFsr.root","read");

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
      //end of sin2theta systematics

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
	MC_Raw_sin2312_AFB[i] = AFB(h_Sin2312_MeasCos_M_Y_Forward[k]->GetBinContent(i+1),h_Sin2312_MeasCos_M_Y_Backward[k]->GetBinContent(i+1));
	MC_Raw_sin2412_AFB[i] = AFB(h_Sin2412_MeasCos_M_Y_Forward[k]->GetBinContent(i+1),h_Sin2412_MeasCos_M_Y_Backward[k]->GetBinContent(i+1));
	MC_Raw_sin2212_AFB[i] = AFB(h_Sin2212_MeasCos_M_Y_Forward[k]->GetBinContent(i+1),h_Sin2212_MeasCos_M_Y_Backward[k]->GetBinContent(i+1));
	float diff1 = MC_Raw_sin2412_AFB[i]-MC_Raw_sin2312_AFB[i];
	float diff2 = MC_Raw_sin2212_AFB[i]-MC_Raw_sin2312_AFB[i];
        h_MC_Raw_sin2412m2312_AFB[k]->SetBinContent(i+1,diff1);
        h_MC_Raw_sin2212m2312_AFB[k]->SetBinContent(i+1,diff2);
	//sin2thetaW systematics raw level table
	if (k == 0 && i == 0){ 
	  cout<<"sin2thetaW SYSTEMATICS (Raw Level)"<<endl;
	  cout<<"---------------"<<endl;
	  cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
	  cout<<"-------------------------------------------------------------------"<<endl;
	}
	cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff1<<"  &  "<<setprecision(3)<<diff2<<"    \\\\    "<<endl;
	//end of sin2theta systematics raw level table
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


