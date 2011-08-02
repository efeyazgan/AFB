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
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH1F.h"
#include "TF1.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TPaveText.h"
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

void RooUnfoldApply_Background_Systematics()
{
#ifdef __CINT__
  gSystem->Load("libRooUnfold");
#endif


  char name_h[100];
  int nb = 12;
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
  //  xAxis_AFB[13] = 1500;


  int nb_Y = 4;
  float Y_bin_limits[nb_Y+1];
  Y_bin_limits[0] = 0.0;
  Y_bin_limits[1] = 1.0;
  Y_bin_limits[2] = 1.25;
  Y_bin_limits[3] = 1.5;
  Y_bin_limits[4] = 2.1;
  int k_reg_cos = 2;
  //int k_iter = 11;

//backgrounds
  float qcd[13][4]={{2.84851,  0.614851,  1.38006,  4.76473},{4.57041,  0.986523,  2.21429,  7.64497},{4.9959,  1.07837,  2.42044,  8.35669},{5.25603,  1.65994,  1.48038,  4.12885},{4.58785,  1.44892,  1.29218,  3.60396},{1.78681,  0.564305,  0.50326,  1.40362},{0.20599,  0.0650551,  0.0580177,  0.161815},{3.13809,  0.99106,  0.883851,  2.46511},{3.17069,  1.00135,  0.893032,  2.49072},{10.4333,  1.13866,  0.943375,  0.785145},{10.4114,  1.13627,  0.941396,  0.783498},{11.3714,  1.24104,  1.0282,  0.85574},{0.1511,  0.0164906,  0.0136624,  0.0113708}};

  float tautau[13][4]={{41.0477,  7.48138,  5.19241,  12.4894},{108.846,  19.8383,  13.7686,  33.1181},{98.5837,  17.9679,  12.4705,  29.9957},{40.1073,  8.15741,  5.77816,  12.1681},{8.95654,  1.82167,  1.29035,  2.71732},{1.8589,  0.378082,  0.267808,  0.563973},{0.619635,  0.126027,  0.0892694,  0.187991},{1.63358,  0.332254,  0.235347,  0.495612},{1.68991,  0.343711,  0.243462,  0.512702},{1.81336,  0.278979,  0.185986,  0.511461},{1.20891,  0.185986,  0.123991,  0.340974},{0.604454,  0.0929929,  0.0619953,  0.170487},{0,  0,  0,  0}};

  float toptop[13][4]={{23.3468,  2.94543,  1.4294,  1.68929},{30.8124,  3.88728,  1.88647,  2.22947},{38.0065,  4.79488,  2.32693,  2.75},{38.4182,  4.9419,  3.24947,  2.97868},{36.8285,  4.7374,  3.11501,  2.85542},{23.4483,  3.01626,  1.9833,  1.81802},{8.08106,  1.0395,  0.683509,  0.626549},{37.0934,  4.77149,  3.13742,  2.87596},{50.2086,  6.45855,  4.24672,  3.89282},{84.3968,  9.25432,  5.27887,  4.69233},{75.6228,  8.29223,  4.73008,  4.20451},{61.2782,  6.71931,  3.83284,  3.40697},{0.139269,  0.0152711,  0.00871101,  0.00774312}};

  float ww[13][4]={{2.71557,  0.609795,  0.442231,  0.81018},{4.06,  0.911693,  0.661171,  1.21129},{5.02158,  1.12762,  0.817764,  1.49817},{5.84644,  1.13444,  0.927066,  1.42022},{4.37895,  0.849686,  0.694367,  1.06374},{2.64336,  0.512915,  0.419156,  0.642128},{1.46749,  0.28475,  0.232699,  0.356484},{4.82108,  0.935476,  0.764475,  1.17114},{6.02047,  1.1682,  0.954661,  1.4625},{9.8916,  1.68975,  1.30846,  1.51144},{8.75244,  1.49515,  1.15777,  1.33738},{8.29884,  1.41766,  1.09777,  1.26807},{0.118555,  0.0202523,  0.0156824,  0.0181153}};

  float wz[13][4]={{0.376619,  0.0722494,  0.0502159,  0.116316},{0.643677,  0.123481,  0.0858235,  0.198795},{1.0357,  0.198686,  0.138094,  0.31987},{2.35717,  0.42838,  0.331457,  0.555819},{14.6977,  2.6711,  2.06675,  3.46572},{35.6771,  6.48378,  5.01679,  8.41263},{8.2474,  1.49884,  1.15972,  1.94473},{5.34627,  0.971605,  0.751774,  1.26065},{1.09151,  0.198367,  0.153485,  0.257378},{1.03398,  0.196411,  0.152388,  0.15013},{0.803787,  0.152684,  0.118462,  0.116707},{0.715106,  0.135839,  0.105392,  0.103831},{0.00943412,  0.00179207,  0.0013904,  0.0013698}};

  float zz[13][4]={{0.319472,  0.0611165,  0.0427815,  0.0922303},{0.427891,  0.0818574,  0.0573002,  0.12353},{0.594132,  0.11366,  0.079562,  0.171523},{1.47901,  0.275612,  0.210206,  0.356539},{11.1008,  2.06861,  1.57771,  2.67602},{28.7501,  5.35754,  4.08613,  6.93066},{6.87258,  1.2807,  0.976772,  1.65674},{4.68156,  0.872403,  0.665371,  1.12856},{1.13862,  0.21218,  0.161827,  0.274482},{0.918286,  0.156087,  0.133559,  0.180224},{0.550971,  0.0936523,  0.0801354,  0.108135},{0.509301,  0.0865693,  0.0740748,  0.0999563},{0.01852,  0.00314798,  0.00269363,  0.00363478}};

  float wjet[13][4]={{0.566786,  0.171435,  0.136448,  0.374359},{0.751607,  0.227338,  0.180943,  0.496432},{0.880985,  0.266471,  0.212089,  0.581885},{1.14012,  0.256359,  0.246239,  0.543076},{0.941841,  0.211775,  0.203415,  0.448628},{0.453217,  0.101907,  0.0978841,  0.215881},{0.226608,  0.0509533,  0.048942,  0.107941},{0.906436,  0.203814,  0.195769,  0.431764},{0.920597,  0.206998,  0.198827,  0.438509},{1.84464,  0.282055,  0.242567,  0.468211},{1.38568,  0.211878,  0.182215,  0.351718},{1.14738,  0.17544,  0.150879,  0.291231},{0.0617821,  0.0094468,  0.00812425,  0.0156817}};

  float comb[13][4]={{71.2215,  11.9563,  8.67355,  20.3366},{150.112,  26.0564,  18.8547,  45.0226},{149.118,  25.5476,  18.4654,  43.6739},{94.6042,  16.854,  12.223,  22.1513},{81.4921,  13.8092,  10.2398,  16.8308},{94.6178,  16.4148,  12.3743,  19.9869},{25.7208,  4.34583,  3.24893,  5.04225},{57.6204,  9.0781,  6.634,  9.8288},{64.2404,  9.58936,  6.85201,  9.32911},{110.332,  12.9962,  8.2452,  8.29895},{98.7361,  11.5679,  7.33405,  7.24293},{83.9247,  9.86884,  6.35115,  6.19629},{0.49866,  0.0664008,  0.0502641,  0.0579155}};

  float r_low[8]={0.0337818, 0.0891583, 0.160669, 0.207597, 0.217322, 0.165633, 0.0953228, 0.0305172};
  float r_zregion[8]={0.0739075, 0.118206, 0.14857, 0.155686, 0.154337, 0.14043, 0.130704, 0.0781602};
  float r_high[8]={0.168619, 0.135261, 0.0945135, 0.105693, 0.101162, 0.107239, 0.128129, 0.159383};

  float backg_lumi_scale = 1.;






//eobackgrounds



  RooUnfoldResponse* resp[nb][nb_Y];
  RooUnfoldResponse* resp_2[nb][nb_Y];
  RooUnfoldSvd* unfold_fsr[nb][nb_Y];
  RooUnfoldSvd* unfold_dilution[nb][nb_Y];
  RooUnfoldSvd* unfold_fsr_bkg_UP[nb][nb_Y];
  RooUnfoldSvd* unfold_fsr_bkg_DOWN[nb][nb_Y];
  RooUnfoldSvd* unfold_dilution_bkg_UP[nb][nb_Y];
  RooUnfoldSvd* unfold_dilution_bkg_DOWN[nb][nb_Y];


  TH1D *hMeasCos_M_Y[30][5];

  TH1D *hDataMeasCos_M_Y[30][5];
  TH1D *hDataMeasCos_M_Y_central[30][5];
  TH1D *hDataMeasCos_M_Y_bkg_UP[30][5];
  TH1D *hDataMeasCos_M_Y_bkg_DOWN[30][5];

  TH1D *hNoFsrTruthCos_M_Y[30][5];
  TH1D *hTrueCos_M_Y[30][5];
  TH1D *hTrueCos_MASS_M_Y[30][5];
  TH1D *hDataMeasCos_MASS_M_Y[30][5];

  TH1D *AFB1_err_M_Y[30][5];
  TH1D *AFB2_err_M_Y[30][5];
  TF1 *fitfunc[30][5];
  TF1 *fitfunc_bkg_UP[30][5];
  TF1 *fitfunc_bkg_DOWN[30][5];

  TH1D *AFB[nb_Y];

  
  TFile input_fsr_file("RootFilesForUnfolding/Electron_MCpowheg_Meas_NoFsr_eta25_res_fixedJul27.root","read");
  TFile input_dilution_file("RootFilesForUnfolding/MUON_MC_NoFsr_NoDilution.root","read");
  TFile input_data_file("RootFilesForUnfolding/ZeeData_Data_ESoutput_1010pb.root","read");
  for (int i=0;i<nb;i++){

    for (int j=0;j<nb_Y;j++){
      sprintf(name_h,"response_%i_%i",i,j);
      input_dilution_file.GetObject(name_h,resp[i][j]);
      sprintf(name_h,"truth_non_diluted_%i_%i",i,j);
      input_dilution_file.GetObject(name_h,hTrueCos_M_Y[i][j]);

      sprintf(name_h,"response2_%i_%i",i,j);
      input_fsr_file.GetObject(name_h,resp_2[i][j]);
      sprintf(name_h,"truth_no_fsr_%i_%i",i,j);
      input_fsr_file.GetObject(name_h,hNoFsrTruthCos_M_Y[i][j]);


      //sprintf(name_h,"meas_%i_%i",i,j);
      //      input_resp_file.GetObject(name_h,hMeasCos_M_Y[i][j]);
      sprintf(name_h,"MC_meas_%i_%i",i,j);
      input_fsr_file.GetObject(name_h,hMeasCos_M_Y[i][j]);

      sprintf(name_h,"DATA_meas_%i_%i",i,j);
      input_data_file.GetObject(name_h,hDataMeasCos_M_Y[i][j]);

      sprintf(name_h,"DATA_meas_central_%i_%i",i,j);
      hDataMeasCos_M_Y_central[i][j] = new TH1D(name_h,name_h,nbcos,-1.,1.);

      sprintf(name_h,"DATA_meas_Bkg_UP_%i_%i",i,j);
      hDataMeasCos_M_Y_bkg_UP[i][j] = new TH1D(name_h,name_h,nbcos,-1.,1.);

      sprintf(name_h,"DATA_meas_Bkg_DOWN_%i_%i",i,j);
      hDataMeasCos_M_Y_bkg_DOWN[i][j] = new TH1D(name_h,name_h,nbcos,-1.,1.);      

      sprintf(name_h,"TrueMass_%i_%i",i,j);
      input_dilution_file.GetObject(name_h,hTrueCos_MASS_M_Y[i][j]);

      sprintf(name_h,"MeasuredMass_%i_%i",i,j);
      input_data_file.GetObject(name_h,hDataMeasCos_MASS_M_Y[i][j]);

      sprintf(name_h,"AFB1_err_M_Y_%i_%i",i,j);
      AFB1_err_M_Y[i][j] = new TH1D(name_h,name_h,nbcos,-1.,1.);
      sprintf(name_h,"AFB2_err_M_Y_%i_%i",i,j);
      AFB2_err_M_Y[i][j] = new TH1D(name_h,name_h,nbcos,-1.,1.);

      sprintf(name_h,"Fit_%i_%i",i,j);
      fitfunc[i][j] = new TF1(name_h,"[0]*((3./8.)*(1+x*x)+[1]*x)");
      sprintf(name_h,"Fit_bkg_UP_%i_%i",i,j);
      fitfunc_bkg_UP[i][j] = new TF1(name_h,"[0]*((3./8.)*(1+x*x)+[1]*x)");
      sprintf(name_h,"Fit_bkg_DOWN_%i_%i",i,j);
      fitfunc_bkg_DOWN[i][j] = new TF1(name_h,"[0]*((3./8.)*(1+x*x)+[1]*x)");

    } 
  }

  float bkg_scale_up = 2.;
  float bkg_scale_down = 0.;

  for (int i=0;i<nb;i++){
    for (int j=0;j<nb_Y;j++){
      for (int k=0;k<nbcos;k++){
	if (i < 3){ 
	  float central_value = hDataMeasCos_M_Y[i][j]->GetBinContent(k+1);
	  hDataMeasCos_M_Y_central[i][j]->SetBinContent(k+1,central_value - comb[i][j]*r_low[i]*backg_lumi_scale);
	  hDataMeasCos_M_Y_bkg_UP[i][j]->SetBinContent(k+1,central_value - bkg_scale_up*comb[i][j]*r_low[i]*backg_lumi_scale);  
	  hDataMeasCos_M_Y_bkg_DOWN[i][j]->SetBinContent(k+1,central_value - bkg_scale_down*comb[i][j]*r_low[i]*backg_lumi_scale);  
	}
	if (i >= 3 && i < 9){ 
	  float central_value = hDataMeasCos_M_Y[i][j]->GetBinContent(k+1);
	  hDataMeasCos_M_Y_central[i][j]->SetBinContent(k+1,central_value - comb[i][j]*r_zregion[i]*backg_lumi_scale);
	  hDataMeasCos_M_Y_bkg_UP[i][j]->SetBinContent(k+1,central_value - bkg_scale_up*comb[i][j]*r_zregion[i]*backg_lumi_scale);  
	  hDataMeasCos_M_Y_bkg_DOWN[i][j]->SetBinContent(k+1,central_value - bkg_scale_down*comb[i][j]*r_zregion[i]*backg_lumi_scale);  
	}
	if (i >= 9){
	  float central_value = hDataMeasCos_M_Y[i][j]->GetBinContent(k+1);
	  hDataMeasCos_M_Y_central[i][j]->SetBinContent(k+1,central_value - comb[i][j]*r_high[i]*backg_lumi_scale);
	  hDataMeasCos_M_Y_bkg_UP[i][j]->SetBinContent(k+1,central_value - bkg_scale_up*comb[i][j]*r_high[i]*backg_lumi_scale);  
	  hDataMeasCos_M_Y_bkg_DOWN[i][j]->SetBinContent(k+1,central_value - bkg_scale_down*comb[i][j]*r_high[i]*backg_lumi_scale);  	  
	}
      }
    }
  }

  for (int i=0;i<nb;i++){
    for (int j=0;j<nb_Y;j++){
      hNoFsrTruthCos_M_Y[i][j]->Scale(hDataMeasCos_M_Y[i][j]->Integral()*1./hNoFsrTruthCos_M_Y[i][j]->Integral()*1.);
      unfold_fsr[i][j] = new RooUnfoldSvd(resp_2[i][j], hDataMeasCos_M_Y_central[i][j], k_reg_cos);
      unfold_fsr_bkg_UP[i][j] = new RooUnfoldSvd(resp_2[i][j], hDataMeasCos_M_Y_bkg_UP[i][j], k_reg_cos);     
      unfold_fsr_bkg_DOWN[i][j] = new RooUnfoldSvd(resp_2[i][j], hDataMeasCos_M_Y_bkg_DOWN[i][j], k_reg_cos);
    }
  }

  TH1D* hRecoCos[nb][nb_Y];
  TH1D* hRecoCos2[nb][nb_Y];
  const double *cov_a;
  const double *cov_a2;

  TH1D* hRecoCos_bkg_DOWN[nb][nb_Y];
  TH1D* hRecoCos2_bkg_DOWN[nb][nb_Y];
  const double *cov_a_bkg_DOWN;
  const double *cov_a2_bkg_DOWN;

  TH1D* hRecoCos_bkg_UP[nb][nb_Y];
  TH1D* hRecoCos2_bkg_UP[nb][nb_Y];
  const double *cov_a_bkg_UP;
  const double *cov_a2_bkg_UP;

  char name_outhisto2[100];
  TH1D *h_Unfold_Y2[nb_Y]; 
  TH1D *h_Meas_Y2[nb_Y]; 
  TH1D *h_True_Y2[nb_Y]; 
  TH1D *h_mc[nb_Y];
  int bin_min,bin_mid,bin_mid_for_backward,bin_max;
  float NF_unfold, NB_unfold, NF_meas, NB_meas, NF_true, NB_true, afb, binw, afb_mc, NF_mc, NB_mc;
  TAxis *axis = hDataMeasCos_M_Y[0][0]->GetXaxis();
  bin_mid = axis->FindBin(0.);
  bin_mid_for_backward = bin_mid - 1;
  //cout<<"middle bin = "<<bin_mid<<endl;
  bin_min = axis->FindBin(-1.);
  bin_max = axis->FindBin(1.) - 1;
  binw = axis->GetBinWidth(bin_mid);
  //you do not need to worry about bin size because of the ratio

  double err2[nbcos];
  double error2[nb][nb_Y];
  double err[nbcos];
  double error[nb][nb_Y];

  double err2_bkg_DOWN[nbcos];
  double error2_bkg_DOWN[nb][nb_Y];
  double err_bkg_DOWN[nbcos];
  double error_bkg_DOWN[nb][nb_Y];

  double err2_bkg_UP[nbcos];
  double error2_bkg_UP[nb][nb_Y];
  double err_bkg_UP[nbcos];
  double error_bkg_UP[nb][nb_Y];

  char matrix_name[100];
  for (int i=0;i<nb;i++){
    err2[i] = 0;
    err[i] = 0;
    err2_bkg_UP[i] = 0;
    err_bkg_UP[i] = 0;
    err2_bkg_DOWN[i] = 0;
    err_bkg_DOWN[i] = 0;
    for (int j=0;j<nb_Y;j++){
      error2[i][j] = 0;
      error[i][j] = 0;
      error2_bkg_UP[i][j] = 0;
      error_bkg_UP[i][j] = 0;
      error2_bkg_DOWN[i][j] = 0;
      error_bkg_DOWN[i][j] = 0;
    }
  }  



  for (int i=0;i<nb;i++){
    for (int j=0;j<nb_Y;j++){
      hRecoCos2[i][j] = (TH1D*) unfold_fsr[i][j]->Hreco(); 
      hRecoCos2_bkg_UP[i][j] = (TH1D*) unfold_fsr_bkg_UP[i][j]->Hreco();
      hRecoCos2_bkg_DOWN[i][j] = (TH1D*) unfold_fsr_bkg_DOWN[i][j]->Hreco();

      cout<<hRecoCos2[i][j]->GetBinContent(1)<<"   "<<hRecoCos2_bkg_UP[i][j]->GetBinContent(1)<<"   "<<hRecoCos2_bkg_DOWN[i][j]->GetBinContent(1)<<"   "<<endl;


      TMatrixD cov2 = unfold_fsr[i][j]->Ereco();
      TMatrixD cov2_bkg_UP = unfold_fsr_bkg_UP[i][j]->Ereco();
      TMatrixD cov2_bkg_DOWN = unfold_fsr_bkg_DOWN[i][j]->Ereco();

      //cov2.Print();
      cov_a2 = cov2.GetMatrixArray();
      cov_a2_bkg_UP = cov2_bkg_UP.GetMatrixArray();
      cov_a2_bkg_DOWN = cov2_bkg_DOWN.GetMatrixArray();
      for (int l=0;l<nbcos;l++){
	err2[l] = 0;
	err2_bkg_UP[l] = 0;
	err2_bkg_DOWN[l] = 0;
	for (int m=0;m<nbcos;m++){
	  int k = nbcos*l+m;    
	  err2[l] += cov_a2[k]; 
	  error2[i][j] += cov_a2[k];  
	  err2_bkg_UP[l] += cov_a2_bkg_UP[k]; 
	  error2_bkg_UP[i][j] += cov_a2_bkg_UP[k];  
	  err2_bkg_DOWN[l] += cov_a2_bkg_DOWN[k]; 
	  error2_bkg_DOWN[i][j] += cov_a2_bkg_DOWN[k];  
	}
	//hRecoCos2[i][j]->SetBinError(l+1,sqrt(err2[l]));//!!!!!!!
	//	hRecoCos2_bkg_UP[i][j]->SetBinError(l+1,sqrt(err2_bkg_UP[l]));
	//	hRecoCos2_bkg_DOWN[i][j]->SetBinError(l+1,sqrt(err2_bkg_DOWN[l]));
      }
      error2[i][j] = sqrt(error2[i][j])*sqrt(2*(pow(hRecoCos2[i][j]->Integral(bin_min,bin_mid_for_backward),2)+pow(hRecoCos2[i][j]->Integral(bin_mid,bin_max),2)))/(pow(hRecoCos2[i][j]->Integral(),2));
      error2_bkg_UP[i][j] = sqrt(error2_bkg_UP[i][j])*sqrt(2*(pow(hRecoCos2_bkg_UP[i][j]->Integral(bin_min,bin_mid_for_backward),2)+pow(hRecoCos2_bkg_UP[i][j]->Integral(bin_mid,bin_max),2)))/(pow(hRecoCos2_bkg_UP[i][j]->Integral(),2));
      error2_bkg_DOWN[i][j] = sqrt(error2_bkg_DOWN[i][j])*sqrt(2*(pow(hRecoCos2_bkg_DOWN[i][j]->Integral(bin_min,bin_mid_for_backward),2)+pow(hRecoCos2_bkg_DOWN[i][j]->Integral(bin_mid,bin_max),2)))/(pow(hRecoCos2_bkg_DOWN[i][j]->Integral(),2));
      
    }
  }


  for (int i=0;i<nb;i++){
    for (int j=0;j<nb_Y;j++){
      hTrueCos_M_Y[i][j]->Scale(hRecoCos2[i][j]->Integral()*1./hTrueCos_M_Y[i][j]->Integral()*1.);
      unfold_dilution[i][j] = new RooUnfoldSvd(resp[i][j], hRecoCos2[i][j], k_reg_cos);
      unfold_dilution_bkg_UP[i][j] = new RooUnfoldSvd(resp[i][j], hRecoCos2_bkg_UP[i][j], k_reg_cos);
      unfold_dilution_bkg_DOWN[i][j] = new RooUnfoldSvd(resp[i][j], hRecoCos2_bkg_DOWN[i][j], k_reg_cos);
    }
  }



 


  for (int i=0;i<nb;i++){
    for (int j=0;j<nb_Y;j++){
      hRecoCos[i][j] = (TH1D*) unfold_dilution[i][j]->Hreco();
      hRecoCos_bkg_UP[i][j] = (TH1D*) unfold_dilution_bkg_UP[i][j]->Hreco();
      hRecoCos_bkg_DOWN[i][j] = (TH1D*) unfold_dilution_bkg_DOWN[i][j]->Hreco();

      cout<<hRecoCos[i][j]->GetBinContent(1)<<"   "<<hRecoCos_bkg_UP[i][j]->GetBinContent(1)<<"   "<<hRecoCos_bkg_DOWN[i][j]->GetBinContent(1)<<"   "<<endl;

      TMatrixD cov = unfold_dilution[i][j]->Ereco();
      TMatrixD cov_bkg_UP = unfold_dilution_bkg_UP[i][j]->Ereco();
      TMatrixD cov_bkg_DOWN = unfold_dilution_bkg_DOWN[i][j]->Ereco();

      sprintf(matrix_name,"cov_mat1__%i_%i",i,j);
      //cov.Print();
      //cov.Write(matrix_name);
      cov_a = cov.GetMatrixArray();
      cov_a_bkg_UP = cov_bkg_UP.GetMatrixArray();
      cov_a_bkg_DOWN = cov_bkg_DOWN.GetMatrixArray();

      for (int l=0;l<nbcos;l++){
	err[l] = 0;
	err_bkg_UP[l] = 0;	
	err_bkg_DOWN[l] = 0;		
	for (int m=0;m<nbcos;m++){
	  int k = nbcos*l+m;    
     	  err[l] += cov_a[k];  
	  error[i][j] += cov_a[k];
     	  err_bkg_UP[l] += cov_a_bkg_UP[k];  
	  error_bkg_UP[i][j] += cov_a_bkg_UP[k];
     	  err_bkg_DOWN[l] += cov_a_bkg_DOWN[k];  
	  error_bkg_DOWN[i][j] += cov_a_bkg_DOWN[k];
	}
	//hRecoCos[i][j]->SetBinError(l+1,sqrt(err2[l]));//!!!!!!
	//	hRecoCos_bkg_UP[i][j]->SetBinError(l+1,sqrt(err2_bkg_UP[l]));
	//	hRecoCos_bkg_DOWN[i][j]->SetBinError(l+1,sqrt(err2_bkg_DOWN[l]));
      }
      error[i][j] = sqrt(error[i][j])*sqrt(2*(pow(hRecoCos[i][j]->Integral(bin_min,bin_mid_for_backward),2)+pow(hRecoCos[i][j]->Integral(bin_mid,bin_max),2)))/(pow(hRecoCos[i][j]->Integral(),2));
      error[i][j] = sqrt(error[i][j]*error[i][j]+error2[i][j]*error2[i][j]);
      error_bkg_UP[i][j] = sqrt(error_bkg_UP[i][j])*sqrt(2*(pow(hRecoCos_bkg_UP[i][j]->Integral(bin_min,bin_mid_for_backward),2)+pow(hRecoCos_bkg_UP[i][j]->Integral(bin_mid,bin_max),2)))/(pow(hRecoCos_bkg_UP[i][j]->Integral(),2));
      error_bkg_UP[i][j] = sqrt(error_bkg_UP[i][j]*error_bkg_UP[i][j]+error2_bkg_UP[i][j]*error2_bkg_UP[i][j]);
      error_bkg_DOWN[i][j] = sqrt(error_bkg_DOWN[i][j])*sqrt(2*(pow(hRecoCos_bkg_DOWN[i][j]->Integral(bin_min,bin_mid_for_backward),2)+pow(hRecoCos_bkg_DOWN[i][j]->Integral(bin_mid,bin_max),2)))/(pow(hRecoCos_bkg_DOWN[i][j]->Integral(),2));
      error_bkg_DOWN[i][j] = sqrt(error_bkg_DOWN[i][j]*error_bkg_DOWN[i][j]+error2_bkg_DOWN[i][j]*error2_bkg_DOWN[i][j]);    
    }
  }


  float scale[nb][nb_Y],scale2[nb][nb_Y];
  float scale_bkg_UP[nb][nb_Y],scale2_bkg_UP[nb][nb_Y];
  float scale_bkg_DOWN[nb][nb_Y],scale2_bkg_DOWN[nb][nb_Y];

  TCanvas *c_rap[nb_Y];
  char name_outfile[100];
  for (int j=0;j<nb_Y;j++){
    c_rap[j] = new TCanvas();
    c_rap[j]->Divide(4,3);
    for (int i=0;i<nb;i++){
      c_rap[j]->cd(i+1);
      hRecoCos2[i][j]->SetMarkerStyle(8);
      scale2[i][j] = hNoFsrTruthCos_M_Y[i][j]->Integral()*1./hRecoCos2[i][j]->Integral()*1.;

      scale[i][j] = hDataMeasCos_M_Y_central[i][j]->Integral()*1./hRecoCos[i][j]->Integral()*1.;//!!!
      scale_bkg_UP[i][j] = hDataMeasCos_M_Y_bkg_UP[i][j]->Integral()*1./hRecoCos_bkg_UP[i][j]->Integral()*1.;//!!!
      scale_bkg_DOWN[i][j] = hDataMeasCos_M_Y_bkg_DOWN[i][j]->Integral()*1./hRecoCos_bkg_DOWN[i][j]->Integral()*1.;//!!!

      cout<<"SCALES:   "<<scale[i][j]<<"   "<<scale_bkg_UP[i][j]<<"   "<<scale_bkg_DOWN[i][j]<<endl;


      hRecoCos2[i][j]->Scale(scale2[i][j]);
      hRecoCos2[i][j]->Draw();
      hRecoCos[i][j]->SetMarkerStyle(8);
      hRecoCos[i][j]->SetMarkerColor(8);

      hRecoCos[i][j]->Scale(scale[i][j]);
      hRecoCos[i][j]->Fit(fitfunc[i][j],"MQ","",-1.,-1.);

      hRecoCos_bkg_UP[i][j]->Scale(scale_bkg_UP[i][j]);
      hRecoCos_bkg_UP[i][j]->Fit(fitfunc_bkg_UP[i][j],"MQ","",-1.,-1.);

      hRecoCos_bkg_DOWN[i][j]->Scale(scale_bkg_DOWN[i][j]);
      hRecoCos_bkg_DOWN[i][j]->Fit(fitfunc_bkg_DOWN[i][j],"MQ","",-1.,-1.);


      cout<<"unfolded and scaled values:    "<<hRecoCos[i][j]->GetBinContent(1)<<"   "<<hRecoCos_bkg_UP[i][j]->GetBinContent(1)<<"   "<<hRecoCos_bkg_UP[i][j]->GetBinContent(1)<<endl;


      cout<<"Fits:   "<<fitfunc[i][j]->GetParameter(1)<<"   "<<fitfunc_bkg_UP[i][j]->GetParameter(1)<<"   "<<fitfunc_bkg_DOWN[i][j]->GetParameter(1)<<"   "<<endl;




      hRecoCos[i][j]->Draw("sames");
      hDataMeasCos_M_Y[i][j]->SetMarkerColor(2);
      hDataMeasCos_M_Y[i][j]->Draw("e1SAMES");//!!!!
      //     hMeasCos_M_Y[i][j]->Draw("SAMES");//!!!!
      hNoFsrTruthCos_M_Y[i][j]->Draw("SAMES");
      hTrueCos_M_Y[i][j]->SetLineColor(4);
      hTrueCos_M_Y[i][j]->Draw("SAMES"); 
    }
    //    sprintf(name_outfile,"Data_and_Unfolded_Y%i_%i_costheta.C",j,j+1);
    //    c_rap[j]->SaveAs(name_outfile);
  }


  
  TCanvas *c_AFB2 = new TCanvas();
  c_AFB2->Divide(2,2);

  for (int j=0;j<nb_Y;j++){
    c_AFB2->cd(j+1);
    gPad->SetLogx();
    sprintf(name_outhisto2,"h_Unfold_Y2_%i",j+1);
    h_Unfold_Y2[j] = new TH1D(name_outhisto2,name_outhisto2,nb, xAxis_AFB);
    sprintf(name_outhisto2,"h_Meas_Y2_%i",j+1);
    h_Meas_Y2[j] = new TH1D(name_outhisto2,name_outhisto2,nb, xAxis_AFB);
    sprintf(name_outhisto2,"h_True_Y2_%i",j+1);
    h_True_Y2[j] = new TH1D(name_outhisto2,name_outhisto2,nb, xAxis_AFB);

    sprintf(name_outhisto2,"h_mc_%i",j+1);
    h_mc[j] = new TH1D(name_outhisto2,name_outhisto2,nb, xAxis_AFB);

    for (int i=0;i<nb;i++){
      /*
      for (int l=0;l<nbcos;l++){
	AFB1_err_M_Y[i][j]->SetBinContent(l+1,hRecoCos2[i][j]->GetBinError(l+1)/hMeasCos_M_Y[i][j]->GetBinError(l+1));
      }
      */
      NF_unfold = hRecoCos2[i][j]->Integral(bin_mid,bin_max);
      NB_unfold = hRecoCos2[i][j]->Integral(bin_min,bin_mid_for_backward);
      
      NF_meas = hDataMeasCos_M_Y[i][j]->Integral(bin_mid,bin_max);//!!!!
      NB_meas = hDataMeasCos_M_Y[i][j]->Integral(bin_min,bin_mid_for_backward);//!!!!
      afb = (NF_meas-NB_meas)/(NF_meas+NB_meas);
      h_Meas_Y2[j]->SetBinContent(i+1,afb);
      h_Meas_Y2[j]->SetBinError(i+1,sqrt((1-afb*afb)/(binw*(NF_meas+NB_meas))));

      NF_mc = hMeasCos_M_Y[i][j]->Integral(bin_mid,bin_max);
      NB_mc = hMeasCos_M_Y[i][j]->Integral(bin_min,bin_mid_for_backward);
      afb_mc = (NF_mc-NB_mc)/(NF_mc+NB_mc);
      h_mc[j]->SetBinContent(i+1,afb_mc);

      h_Unfold_Y2[j]->SetBinContent(i+1,(NF_unfold-NB_unfold)/(NF_unfold+NB_unfold));
      h_Unfold_Y2[j]->SetBinError(i+1,error2[i][j]);

      NF_true = hNoFsrTruthCos_M_Y[i][j]->Integral(bin_mid,bin_max);
      NB_true = hNoFsrTruthCos_M_Y[i][j]->Integral(bin_min,bin_mid_for_backward);
      afb = (NF_true-NB_true)/(NF_true+NB_true);
      h_True_Y2[j]->SetBinContent(i+1,afb);
      //h_True_Y2[j]->SetBinError(i+1,sqrt((1-afb*afb)/(binw*(NF_true+NB_true))));
    }
    h_Meas_Y2[j]->SetLineColor(4);
    h_Meas_Y2[j]->SetMarkerStyle(8);
    h_Meas_Y2[j]->SetMarkerColor(4);
    //    h_Meas_Y[j]->SetFillColor(4);
    h_Meas_Y2[j]->GetYaxis()->SetRangeUser(-1,1);
    h_Meas_Y2[j]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Meas_Y2[j]->GetYaxis()->SetTitle("A_{FB}");
    h_Meas_Y2[j]->Draw("");
    h_True_Y2[j]->SetLineColor(2);
    h_True_Y2[j]->SetLineWidth(2);
    //    h_True_Y[j]->SetFillColor(2);
    h_True_Y2[j]->Draw("sames");
    h_Unfold_Y2[j]->SetMarkerStyle(8);
    h_Unfold_Y2[j]->Draw("e1sames");    
  }
  
  //  c_AFB2->SaveAs("AFB_NoFsr_Level.C");
  

  ///

  TCanvas *c_AFB = new TCanvas();
  c_AFB->Divide(2,2);
  char name_outhisto[100];
  char name_title[100];
  TH1D *h_Unfold_Y[nb_Y]; 
  TH1D *h_Meas_Y[nb_Y]; 
  TH1D *h_True_Y[nb_Y]; 
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

  float d_AFB0[nb];
  float d_AFB1[nb];
  float d_AFB2[nb];
  float d_AFB3[nb];
  float d_AFB_Err0[nb];
  float d_AFB_Err1[nb];
  float d_AFB_Err2[nb];
  float d_AFB_Err3[nb];
  float d_AFB_x0[nb];
  float d_AFB_x1[nb];
  float d_AFB_x2[nb];
  float d_AFB_x3[nb];


  float AFB0_bkg_UP[nb];
  float AFB1_bkg_UP[nb];
  float AFB2_bkg_UP[nb];
  float AFB3_bkg_UP[nb];
  float AFB_Err0_bkg_UP[nb];
  float AFB_Err1_bkg_UP[nb];
  float AFB_Err2_bkg_UP[nb];
  float AFB_Err3_bkg_UP[nb];

  float AFB0_bkg_DOWN[nb];
  float AFB1_bkg_DOWN[nb];
  float AFB2_bkg_DOWN[nb];
  float AFB3_bkg_DOWN[nb];
  float AFB_Err0_bkg_DOWN[nb];
  float AFB_Err1_bkg_DOWN[nb];
  float AFB_Err2_bkg_DOWN[nb];
  float AFB_Err3_bkg_DOWN[nb];

  for (int j=0;j<nb_Y;j++){
    for (int i=0;i<nb;i++){
      if (j == 0){ 
	AFB0[i] = fitfunc[i][j]->GetParameter(1);
	AFB_Err0[i] = error[i][j];
	AFB_x0[i] = hTrueCos_MASS_M_Y[i][j]->GetMean();
	
	d_AFB0[i] = h_Meas_Y2[j]->GetBinContent(i+1);
	d_AFB_Err0[i] = h_Meas_Y2[j]->GetBinError(i+1);
	d_AFB_x0[i] = hDataMeasCos_MASS_M_Y[i][j]->GetMean();

	AFB0_bkg_UP[i] = fitfunc_bkg_UP[i][j]->GetParameter(1);
	AFB_Err0_bkg_UP[i] = error_bkg_UP[i][j];
	AFB0_bkg_DOWN[i] = fitfunc_bkg_DOWN[i][j]->GetParameter(1);
	AFB_Err0_bkg_DOWN[i] = error_bkg_DOWN[i][j];

	AFB0_bkg_UP[i] = AFB0_bkg_UP[i] - AFB0[i];
	AFB0_bkg_DOWN[i] = AFB0_bkg_DOWN[i] - AFB0[i];

	cout<<Y_bin_limits[j]<<" - "<<Y_bin_limits[j+1]<<" & "<<xAxis_AFB[i]<<" - "<<xAxis_AFB[i+1]<<" & "<<AFB0_bkg_UP[i]<<" & "<<AFB0_bkg_DOWN[i]<<" \\\\ "<<endl;

      }
      if (j == 1){ 
	AFB1[i] = fitfunc[i][j]->GetParameter(1);
	AFB_Err1[i] = error[i][j];
	AFB_x1[i] = hTrueCos_MASS_M_Y[i][j]->GetMean();

	d_AFB1[i] = h_Meas_Y2[j]->GetBinContent(i+1);
	d_AFB_Err1[i] = h_Meas_Y2[j]->GetBinError(i+1);
	d_AFB_x1[i] = hDataMeasCos_MASS_M_Y[i][j]->GetMean();

	AFB1_bkg_UP[i] = fitfunc_bkg_UP[i][j]->GetParameter(1);
	AFB_Err1_bkg_UP[i] = error_bkg_UP[i][j];
	AFB1_bkg_DOWN[i] = fitfunc_bkg_DOWN[i][j]->GetParameter(1);
	AFB_Err1_bkg_DOWN[i] = error_bkg_DOWN[i][j];


	AFB1_bkg_UP[i] = AFB1_bkg_UP[i] - AFB1[i];
	AFB1_bkg_DOWN[i] = AFB1_bkg_DOWN[i] - AFB1[i];

	cout<<Y_bin_limits[j]<<" - "<<Y_bin_limits[j+1]<<" & "<<xAxis_AFB[i]<<" - "<<xAxis_AFB[i+1]<<" & "<<AFB1_bkg_UP[i]<<" & "<<AFB1_bkg_DOWN[i]<<" \\\\ "<<endl;


      }
      if (j == 2){ 
	AFB2[i] = fitfunc[i][j]->GetParameter(1);
	AFB_Err2[i] = error[i][j];
	AFB_x2[i] = hTrueCos_MASS_M_Y[i][j]->GetMean();

	d_AFB2[i] = h_Meas_Y2[j]->GetBinContent(i+1);
	d_AFB_Err2[i] = h_Meas_Y2[j]->GetBinError(i+1);
	d_AFB_x2[i] = hDataMeasCos_MASS_M_Y[i][j]->GetMean();

	AFB2_bkg_UP[i] = fitfunc_bkg_UP[i][j]->GetParameter(1);
	AFB_Err2_bkg_UP[i] = error_bkg_UP[i][j];
	AFB2_bkg_DOWN[i] = fitfunc_bkg_DOWN[i][j]->GetParameter(1);
	AFB_Err2_bkg_DOWN[i] = error_bkg_DOWN[i][j];

	AFB2_bkg_UP[i] = AFB2_bkg_UP[i] - AFB2[i];
	AFB2_bkg_DOWN[i] = AFB2_bkg_DOWN[i] - AFB2[i];

	cout<<Y_bin_limits[j]<<" - "<<Y_bin_limits[j+1]<<" & "<<xAxis_AFB[i]<<" - "<<xAxis_AFB[i+1]<<" & "<<AFB2_bkg_UP[i]<<" & "<<AFB2_bkg_DOWN[i]<<" \\\\ "<<endl;

      }
      if (j == 3){ 
	AFB3[i] = fitfunc[i][j]->GetParameter(1);
	AFB_Err3[i] = error[i][j];
	AFB_x3[i] = hTrueCos_MASS_M_Y[i][j]->GetMean();

	d_AFB3[i] = h_Meas_Y2[j]->GetBinContent(i+1);
	d_AFB_Err3[i] = h_Meas_Y2[j]->GetBinError(i+1);
	d_AFB_x3[i] = hDataMeasCos_MASS_M_Y[i][j]->GetMean();

	AFB3_bkg_UP[i] = fitfunc_bkg_UP[i][j]->GetParameter(1);
	AFB_Err3_bkg_UP[i] = error_bkg_UP[i][j];
	AFB3_bkg_DOWN[i] = fitfunc_bkg_DOWN[i][j]->GetParameter(1);
	AFB_Err3_bkg_DOWN[i] = error_bkg_DOWN[i][j];

	AFB3_bkg_UP[i] = AFB3_bkg_UP[i] - AFB3[i];
	AFB3_bkg_DOWN[i] = AFB3_bkg_DOWN[i] - AFB3[i];

	cout<<Y_bin_limits[j]<<" - "<<Y_bin_limits[j+1]<<" & "<<xAxis_AFB[i]<<" - "<<xAxis_AFB[i+1]<<" & "<<AFB3_bkg_UP[i]<<" & "<<AFB3_bkg_DOWN[i]<<" \\\\ "<<endl;

      }
    }
  }

  TGraph *gr_bkg_UP[nb_Y];
  gr_bkg_UP[0] = new TGraph(nb,AFB_x0,AFB0_bkg_UP);
  gr_bkg_UP[1] = new TGraph(nb,AFB_x1,AFB1_bkg_UP);
  gr_bkg_UP[2] = new TGraph(nb,AFB_x2,AFB2_bkg_UP);
  gr_bkg_UP[3] = new TGraph(nb,AFB_x3,AFB3_bkg_UP);

  TGraph *gr_bkg_DOWN[nb_Y];
  gr_bkg_DOWN[0] = new TGraph(nb,AFB_x0,AFB0_bkg_DOWN);
  gr_bkg_DOWN[1] = new TGraph(nb,AFB_x1,AFB1_bkg_DOWN);
  gr_bkg_DOWN[2] = new TGraph(nb,AFB_x2,AFB2_bkg_DOWN);
  gr_bkg_DOWN[3] = new TGraph(nb,AFB_x3,AFB3_bkg_DOWN);

  TGraph *d_gr[nb_Y];
  d_gr[0] = new TGraphErrors(nb,d_AFB_x0,d_AFB0,0,d_AFB_Err0);
  d_gr[1] = new TGraphErrors(nb,d_AFB_x1,d_AFB1,0,d_AFB_Err1);
  d_gr[2] = new TGraphErrors(nb,d_AFB_x2,d_AFB2,0,d_AFB_Err2);
  d_gr[3] = new TGraphErrors(nb,d_AFB_x3,d_AFB3,0,d_AFB_Err3);

  for (int j=0;j<nb_Y;j++){
    c_AFB->cd(j+1);
    gPad->SetLogx();
    sprintf(name_outhisto,"h_Unfold_Y%i",j+1);
    h_Unfold_Y[j] = new TH1D(name_outhisto,name_outhisto,nb, xAxis_AFB);
    sprintf(name_outhisto,"h_Meas_Y%i",j+1);
    sprintf(name_title,"|Y|=%.2f-%.2f",Y_bin_limits[j],Y_bin_limits[j+1]);
    h_Meas_Y[j] = new TH1D(name_outhisto,name_title,nb, xAxis_AFB);
    sprintf(name_outhisto,"h_True_Y%i",j+1);
    h_True_Y[j] = new TH1D(name_outhisto,name_title,nb, xAxis_AFB);
    sprintf(name_h,"AFB_%i",j);
    AFB[j] = new TH1D(name_outhisto,name_title,nb,xAxis_AFB);

    for (int i=0;i<nb;i++){

      
      AFB[j]->SetBinContent(i+1,fitfunc[i][j]->GetParameter(1));
      AFB[j]->SetBinError(i+1,error[i][j]);
      
 

      NF_unfold = hRecoCos[i][j]->Integral(bin_mid,bin_max);
      NB_unfold = hRecoCos[i][j]->Integral(bin_min,bin_mid_for_backward);

      NF_meas = hRecoCos2[i][j]->Integral(bin_mid,bin_max);//!!!!
      NB_meas = hRecoCos2[i][j]->Integral(bin_min,bin_mid_for_backward);//!!!!
      
      //NF_meas = hNoFsrCos_M_Y[i][j]->Integral(bin_mid,bin_max);
      //NB_meas = hNoFsrCos_M_Y[i][j]->Integral(bin_min,bin_mid_for_backward);
      
      afb = (NF_meas-NB_meas)/(NF_meas+NB_meas);
      h_Meas_Y[j]->SetBinContent(i+1,afb);
      h_Meas_Y[j]->SetBinError(i+1,sqrt((1-afb*afb)/(binw*(NF_meas+NB_meas))));//burdaki error da degismeli. 


      //cout<<"afb_unf_error "<<i<<"  "<<j<<"  "<<afb_unf_error<<endl;
      //afb_unf_error = scale[i][j]*afb_unf_error;//!!!!
      h_Unfold_Y[j]->SetBinContent(i+1,(NF_unfold-NB_unfold)/(NF_unfold+NB_unfold));
      h_Unfold_Y[j]->SetBinError(i+1,error[i][j]);


      NF_true = hTrueCos_M_Y[i][j]->Integral(bin_mid,bin_max);
      NB_true = hTrueCos_M_Y[i][j]->Integral(bin_min,bin_mid_for_backward);
      afb = (NF_true-NB_true)/(NF_true+NB_true);
      h_True_Y[j]->SetBinContent(i+1,afb);
      //h_True_Y[j]->SetBinError(i+1,sqrt((1-afb*afb)/(binw*(NF_true+NB_true))));
    }



    
    h_True_Y[j]->SetLineColor(2);
    h_True_Y[j]->SetLineWidth(2);
    h_True_Y[j]->GetYaxis()->SetRangeUser(-1,1);
    h_True_Y[j]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_True_Y[j]->GetYaxis()->SetTitle("A_{FB}");
    h_True_Y[j]->GetYaxis()->SetTitleOffset(1.0);
    //    h_True_Y[j]->SetFillColor(2);
    //    h_True_Y[j]->Draw("");

   	

    //h_Meas_Y[j]->Draw("");
    
    h_mc[j]->SetLineWidth(2);
    h_mc[j]->SetLineStyle(2);
    //    h_mc[j]->Draw("sames");

    
    d_gr[j]->SetMarkerStyle(22);
    d_gr[j]->SetLineColor(4);
    d_gr[j]->SetLineWidth(2);
    d_gr[j]->SetMarkerColor(4);
    //    d_gr[j]->Draw("Psames");



    //h_Unfold_Y[j]->SetMarkerStyle(8);
    //h_Unfold_Y[j]->Draw("e1sames");    
    
    /*
    AFB[j]->SetLineWidth(2);
    AFB[j]->SetMarkerStyle(4);

    AFB[j]->Draw("e1sames");
    */
     
    gr_bkg_UP[j]->GetYaxis()->SetRangeUser(-0.2,0.15);
    
    gr_bkg_UP[j]->SetLineWidth(2);
    gr_bkg_UP[j]->SetMarkerStyle(8);
    gr_bkg_UP[j]->Draw("APL");

    gr_bkg_DOWN[j]->SetLineWidth(2);
    gr_bkg_DOWN[j]->SetLineStyle(2);
    gr_bkg_DOWN[j]->SetLineColor(4);
    gr_bkg_DOWN[j]->SetMarkerColor(4);
    gr_bkg_DOWN[j]->SetMarkerStyle(26);
    gr_bkg_DOWN[j]->Draw("PLsames");   

  }
  
  c_AFB->SaveAs("AFB_NonDiluted_Level_bkg_UP_DOWN.C");
}

#ifndef __CINT__
int main () { RooUnfoldApply_Background_Systematics(); return 0; }  // Main program when run stand-alone
#endif
