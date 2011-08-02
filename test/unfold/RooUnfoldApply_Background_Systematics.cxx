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

  float qcd[13][4]={{16.4216,4.05207,2.77247,2.34594},{26.9621,6.65299,4.55205,3.85173},{26.5097,6.54136,4.47567,3.7871},{23.0641,5.67731,2.12899,1.41933},{15.8125,3.8923,1.45961,0.973075},{7.10051,1.74782,0.655431,0.436954},{3.17257,0.780939,0.292852,0.195235},{12.4385,3.06178,1.14817,0.765445},{10.0213,2.46678,0.925041,0.616694},{15.0571,0,0.579119,0.579119},{8.05228,0,0.309703,0.309703},{4.45166,0,0.171218,0.171218},{0.130931,0,0.00503582,0.00503582}};

  float tautau[13][4]={{103.876,25.1362,22.4155,27.9751},{228.152,55.2086,49.2331,61.4439},{171.045,41.3897,36.9099,46.0643},{73.8442,16.0914,14.2545,13.1524},{14.0598,3.06379,2.71404,2.50419},{1.92271,0.418979,0.371151,0.342453},{0.660933,0.144024,0.127583,0.117718},{3.36475,0.733214,0.649514,0.599293},{2.10297,0.458259,0.405946,0.374558},{2.18571,0.227678,0.364285,0.182143},{1.69216,0.176267,0.282027,0.141014},{0.705068,0.0734446,0.117511,0.0587557},{0,0,0,0}};

  float toptop[13][4]={{38.2361,4.67005,3.989,3.01608},{50.5058,6.16865,5.26906,3.98392},{57.6394,7.03993,6.01328,4.54662},{52.662,5.25799,5.58661,2.79331},{44.0823,4.40135,4.67643,2.33822},{30.7688,3.07208,3.26409,1.63204},{10.6508,1.06341,1.12988,0.564938},{47.0408,4.69674,4.99029,2.49514},{53.5496,5.34661,5.68077,2.84038},{86.2121,9.66435,7.05651,3.22145},{71.6922,8.03667,5.86804,2.67889},{51.1223,5.73079,4.18439,1.91026},{0.302499,0.03391,0.0247597,0.0113033}};

  float ww[13][4]={{5.84007,1.35411,1.30305,1.26711},{8.30349,1.92529,1.85269,1.8016},{10.0363,2.32707,2.23932,2.17757},{10.902,2.20348,1.70164,1.62858},{8.62191,1.74263,1.34575,1.28796},{4.64336,0.9385,0.724758,0.693639},{2.33207,0.47135,0.364,0.348371},{8.544,1.72688,1.33359,1.27633},{9.35425,1.89065,1.46006,1.39736},{15.8081,2.15901,1.59069,1.1768},{13.1097,1.79048,1.31917,0.975927},{11.0024,1.50267,1.10711,0.81905},{0.155215,0.0211988,0.0156185,0.0115547}};

  float wz[13][4]={{1.17269,0.249245,0.216125,0.226791},{1.90447,0.40478,0.350992,0.368313},{3.00032,0.637694,0.552955,0.580244},{6.21211,1.27837,1.00929,1.06885},{23.1674,4.76756,3.76404,3.98616},{68.879,14.1744,11.1909,11.8512},{10.9567,2.25474,1.78014,1.88519},{7.06016,1.45289,1.14707,1.21476},{2.06818,0.425605,0.33602,0.355849},{2.46756,0.290086,0.206854,0.130967},{1.82052,0.21402,0.152613,0.0966251},{1.55846,0.183212,0.130645,0.082716},{0.0185531,0.0021811,0.0015553,0.000984714}};

  float zz[13][4]={{0.848943,0.199223,0.165931,0.170423},{1.20682,0.283207,0.235881,0.242266},{1.84297,0.432493,0.36022,0.369971},{4.01273,0.837597,0.692345,0.719818},{17.445,3.64138,3.00991,3.12935},{55.8711,11.6622,9.63984,10.0224},{9.16219,1.91247,1.58082,1.64354},{6.12134,1.27774,1.05616,1.09807},{1.85281,0.386745,0.319678,0.332363},{1.74343,0.273718,0.212117,0.197589},{1.00509,0.157799,0.122286,0.11391},{0.868227,0.136312,0.105634,0.0983991},{0.0235363,0.0036952,0.00286358,0.00266745}};

  float wjet[13][4]={{2.77898,1.38949,0.277898,0.555795},{2.77898,1.38949,0.277898,0.555795},{3.53688,1.76844,0.353688,0.707375},{3.28424,1.05096,0.656849,0.919588},{1.76844,0.5659,0.353688,0.495163},{1.5158,0.485057,0.303161,0.424425},{0.252634,0.0808429,0.0505268,0.0707375},{2.27371,0.727586,0.454741,0.636638},{2.27371,0.727586,0.454741,0.636638},{3.69477,0.284213,0.568427,0},{1.10843,0.085264,0.170528,0},{1.10843,0.085264,0.170528,0},{0,0,0,0}};
  
  float comb[13][4]={{169.174,37.0504,31.14,35.5572},{319.814,72.033,61.7717,72.2475},{273.611,60.1367,50.905,58.2332},{173.981,32.3971,26.0302,21.7019},{124.957,22.0749,17.3235,14.7141},{170.701,32.499,26.1493,25.4031},{37.1879,6.70778,5.3258,4.82573},{86.8433,13.6768,10.7795,8.08568},{81.2228,11.7022,9.58226,6.55384},{127.169,12.8991,10.578,5.48807},{98.4804,10.4605,8.22437,4.31607},{70.8165,7.71169,5.98704,3.1404},{0.630734,0.0609851,0.0498329,0.031546}};


  // for low mass <70 GeV. Apply this ratio to each cs bin (8 bins)
  float r_low[8]={0.0371685,0.0864997,0.167557,0.202718,0.204737,0.1687,0.091154,0.0414658};
  // for mass (70-120) GeV. Apply this ratio to each cs bin (8 bins)
  float r_zregion[8]={0.0841875,0.130379,0.133009,0.154781,0.15606,0.126065,0.127694,0.0878249};
  // for high mass >120 GeV. Apply this ratio to each cs bin (8 bins)
  float r_high[8]={0.138623,0.155147,0.115194,0.103376,0.102691,0.115563,0.136031,0.133374};

  float backg_lumi_scale = 1.13/1.091;


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

  

  TFile input_fsr_file("RootFilesForUnfolding/MUON_MC_Meas_NoFsr.root","read");
  TFile input_dilution_file("RootFilesForUnfolding/MUON_MC_NoFsr_NoDilution.root","read");
  //TFile input_resp_file("Response_and_Historgrams.root","read");
  //TFile input_resp_file("RootFilesForUnfolding/Data_Histograms.root","read");
  TFile input_data_file("RootFilesForUnfolding/Data_output_NEW.root","read");
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
     
    gr_bkg_UP[j]->GetYaxis()->SetRangeUser(-0.1,0.25);
    
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
