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

void RooUnfoldExample()
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
  int nb_Y = 4;
  int k_reg_cos = 2;
  //int k_iter = 11;
  RooUnfoldResponse* resp[nb][nb_Y];
  RooUnfoldResponse* resp_2[nb][nb_Y];
  RooUnfoldSvd* unfold_fsr[nb][nb_Y];
  RooUnfoldSvd* unfold_dilution[nb][nb_Y];
  TH1D *hMeasCos_M_Y[30][5];
  TH1D *hDataMeasCos_M_Y[30][5];
  TH1D *hNoFsrTruthCos_M_Y[30][5];
  TH1D *hTrueCos_M_Y[30][5];
  TFile input_fsr_file("RootFilesForUnfolding/MUON_MC_Meas_NoFsr.root","read");
  TFile input_dilution_file("RootFilesForUnfolding/MUON_MC_NoFsr_NoDilution.root","read");
  TFile input_resp_file("Response_and_Historgrams.root","read");
  TFile input_data_file("Data_Histograms.root","read");
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


      sprintf(name_h,"meas_%i_%i",i,j);
      input_resp_file.GetObject(name_h,hMeasCos_M_Y[i][j]);

      sprintf(name_h,"DATA_meas_%i_%i",i,j);
      input_data_file.GetObject(name_h,hDataMeasCos_M_Y[i][j]);
    } 
  }
 
  for (int i=0;i<nb;i++){
    for (int j=0;j<nb_Y;j++){
      hNoFsrTruthCos_M_Y[i][j]->Scale(hDataMeasCos_M_Y[i][j]->Integral()*1./hNoFsrTruthCos_M_Y[i][j]->Integral()*1.);
      unfold_fsr[i][j] = new RooUnfoldSvd(resp_2[i][j], hDataMeasCos_M_Y[i][j], k_reg_cos);
    }
  }

  TH1D* hRecoCos[nb][nb_Y];
  TH1D* hRecoCos2[nb][nb_Y];
  const double *cov_a;
  const double *cov_a2;
  double err_F[nb][nb_Y];
  double err_B[nb][nb_Y];
  double err_FB[nb][nb_Y];
  double err_BF[nb][nb_Y];
  double numerator[nb][nb_Y];
  double err_F2[nb][nb_Y];
  double err_B2[nb][nb_Y];
  double err_FB2[nb][nb_Y];
  double err_BF2[nb][nb_Y];
  double numerator2[nb][nb_Y];
  char matrix_name[100];
  for (int i=0;i<nb;i++){
    for (int j=0;j<nb_Y;j++){
      err_F[i][j] = 0;
      err_B[i][j] = 0;
      err_FB[i][j] = 0;
      err_BF[i][j] = 0;      
      err_F2[i][j] = 0;
      err_B2[i][j] = 0;
      err_FB2[i][j] = 0;
      err_BF2[i][j] = 0;
    }
  }  



  for (int i=0;i<nb;i++){
    for (int j=0;j<nb_Y;j++){
      hRecoCos2[i][j] = (TH1D*) unfold_fsr[i][j]->Hreco();
      TMatrixD cov2 = unfold_fsr[i][j]->Ereco();
      cov2.Print();
      cov_a2 = cov2.GetMatrixArray();
      for (int l=0;l<nbcos;l++){
	for (int m=0;m<nbcos;m++){
	  int k = nbcos*l+m;
	  if (l >= ((nbcos/2)) && m >= ((nbcos/2))) err_F2[i][j] += cov_a2[k];
	  if (l >= ((nbcos/2)) && m < ((nbcos/2))) err_FB2[i][j] += cov_a2[k];
	  if (l <  ((nbcos/2)) && m >= ((nbcos/2))) err_BF2[i][j] += cov_a2[k];
	  if (l <  ((nbcos/2)) && m < ((nbcos/2))) err_B2[i][j] += cov_a2[k];      
	}
      }
      numerator2[i][j] = err_F2[i][j] - err_FB2[i][j] - err_BF2[i][j] + err_B2[i][j];
    }
  }

  
  for (int i=0;i<nb;i++){
    for (int j=0;j<nb_Y;j++){
      hTrueCos_M_Y[i][j]->Scale(hRecoCos2[i][j]->Integral()*1./hTrueCos_M_Y[i][j]->Integral()*1.);
      unfold_dilution[i][j] = new RooUnfoldSvd(resp[i][j], hRecoCos2[i][j], k_reg_cos);
    }
  }

  for (int i=0;i<nb;i++){
    for (int j=0;j<nb_Y;j++){
      hRecoCos[i][j] = (TH1D*) unfold_dilution[i][j]->Hreco();
      TMatrixD cov = unfold_dilution[i][j]->Ereco();
      sprintf(matrix_name,"cov_mat1__%i_%i",i,j);
      cov.Print();
      cov.Write(matrix_name);
      cov_a = cov.GetMatrixArray();
      for (int l=0;l<nbcos;l++){
	for (int m=0;m<nbcos;m++){
	  int k = nbcos*l+m;
	  if (l >= ((nbcos/2)) && m >= ((nbcos/2))) err_F[i][j] += cov_a[k];
	  if (l >= ((nbcos/2)) && m < ((nbcos/2)) ) err_FB[i][j] += cov_a[k];
	  if (l <  ((nbcos/2)) && m >= ((nbcos/2)) ) err_BF[i][j] += cov_a[k];
	  if (l <  ((nbcos/2)) && m < ((nbcos/2)) ) err_B[i][j] += cov_a[k];      
	}
      }
      numerator[i][j] = err_F[i][j] - err_FB[i][j] - err_BF[i][j] + err_B[i][j];
    }
  }
  
  

  float scale[nb][nb_Y],scale2[nb][nb_Y];
  TCanvas *c_rap[nb_Y];
  char name_outfile[100];
  for (int j=0;j<nb_Y;j++){
    c_rap[j] = new TCanvas();
    c_rap[j]->Divide(4,3);
    for (int i=0;i<nb;i++){
      c_rap[j]->cd(i+1);
      hRecoCos2[i][j]->SetMarkerStyle(8);
      scale2[i][j] = hNoFsrTruthCos_M_Y[i][j]->Integral()*1./hRecoCos2[i][j]->Integral()*1.;
      scale[i][j] = hDataMeasCos_M_Y[i][j]->Integral()*1./hRecoCos[i][j]->Integral()*1.;//!!!
      hRecoCos2[i][j]->Scale(scale2[i][j]);
      hRecoCos2[i][j]->Draw();
      hRecoCos[i][j]->SetMarkerStyle(8);
      hRecoCos[i][j]->SetMarkerColor(8);
      hRecoCos[i][j]->Scale(scale[i][j]);
      hRecoCos[i][j]->Draw("sames");
      hDataMeasCos_M_Y[i][j]->SetMarkerColor(2);
      hDataMeasCos_M_Y[i][j]->Draw("e1SAMES");//!!!!
      hMeasCos_M_Y[i][j]->Draw("SAMES");//!!!!
      hNoFsrTruthCos_M_Y[i][j]->Draw("SAMES");
      hTrueCos_M_Y[i][j]->SetLineColor(4);
      hTrueCos_M_Y[i][j]->Draw("SAMES"); 
    }
    sprintf(name_outfile,"Data_and_Unfolded_Y%i_%i_costheta.C",j,j+1);
    c_rap[j]->SaveAs(name_outfile);
  }


  
  
  TCanvas *c_AFB2 = new TCanvas();
  c_AFB2->Divide(2,2);
  char name_outhisto2[100];
  TH1D *h_Unfold_Y2[nb_Y]; 
  TH1D *h_Meas_Y2[nb_Y]; 
  TH1D *h_True_Y2[nb_Y]; 
  int bin_min,bin_mid,bin_mid_for_backward,bin_max;
  float NF_unfold, NB_unfold, NF_meas, NB_meas, NF_true, NB_true, afb, afb_unf_error, binw;
  TAxis *axis = hRecoCos2[0][0]->GetXaxis();
  bin_mid = axis->FindBin(0.);
  bin_mid_for_backward = bin_mid - 1;
  cout<<"middle bin = "<<bin_mid<<endl;
  bin_min = axis->FindBin(-1.);
  bin_max = axis->FindBin(1.);
  binw = axis->GetBinWidth(bin_mid);
  //you do not need to worry about bin size because of the ratio
  for (int j=0;j<nb_Y;j++){
    c_AFB2->cd(j+1);
    gPad->SetLogx();
    sprintf(name_outhisto2,"h_Unfold_Y2_%i",j+1);
    h_Unfold_Y2[j] = new TH1D(name_outhisto2,name_outhisto2,nb, xAxis_AFB);
    sprintf(name_outhisto2,"h_Meas_Y2_%i",j+1);
    h_Meas_Y2[j] = new TH1D(name_outhisto2,name_outhisto2,nb, xAxis_AFB);
    sprintf(name_outhisto2,"h_True_Y2_%i",j+1);
    h_True_Y2[j] = new TH1D(name_outhisto2,name_outhisto2,nb, xAxis_AFB);
    for (int i=0;i<nb;i++){
      NF_unfold = hRecoCos2[i][j]->Integral(bin_mid,bin_max);
      NB_unfold = hRecoCos2[i][j]->Integral(bin_min,bin_mid_for_backward);
      afb_unf_error =  numerator2[i][j]/pow((NF_unfold+NB_unfold),2);
      afb_unf_error = sqrt(afb_unf_error);
      cout<<"afb_unf_error "<<i<<"  "<<j<<"  "<<afb_unf_error<<endl;
      afb_unf_error = scale2[i][j]*afb_unf_error;
      h_Unfold_Y2[j]->SetBinContent(i+1,(NF_unfold-NB_unfold)/(NF_unfold+NB_unfold));
      h_Unfold_Y2[j]->SetBinError(i+1,afb_unf_error);
      
      NF_meas = hDataMeasCos_M_Y[i][j]->Integral(bin_mid,bin_max);//!!!!
      NB_meas = hDataMeasCos_M_Y[i][j]->Integral(bin_min,bin_mid_for_backward);//!!!!
      /*
      NF_meas = hNoFsrCos_M_Y[i][j]->Integral(bin_mid,bin_max);
      NB_meas = hNoFsrCos_M_Y[i][j]->Integral(bin_min,bin_mid_for_backward);
      */
      afb = (NF_meas-NB_meas)/(NF_meas+NB_meas);
      h_Meas_Y2[j]->SetBinContent(i+1,afb);
      h_Meas_Y2[j]->SetBinError(i+1,sqrt((1-afb*afb)/(binw*(NF_meas+NB_meas))));
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
  
  c_AFB2->SaveAs("AFB_NoFsr_Level.C");
  

  ///

  TCanvas *c_AFB = new TCanvas();
  c_AFB->Divide(2,2);
  char name_outhisto[100];
  TH1D *h_Unfold_Y[nb_Y]; 
  TH1D *h_Meas_Y[nb_Y]; 
  TH1D *h_True_Y[nb_Y]; 
  for (int j=0;j<nb_Y;j++){
    c_AFB->cd(j+1);
    gPad->SetLogx();
    sprintf(name_outhisto,"h_Unfold_Y%i",j+1);
    h_Unfold_Y[j] = new TH1D(name_outhisto,name_outhisto,nb, xAxis_AFB);
    sprintf(name_outhisto,"h_Meas_Y%i",j+1);
    h_Meas_Y[j] = new TH1D(name_outhisto,name_outhisto,nb, xAxis_AFB);
    sprintf(name_outhisto,"h_True_Y%i",j+1);
    h_True_Y[j] = new TH1D(name_outhisto,name_outhisto,nb, xAxis_AFB);
    for (int i=0;i<nb;i++){
      NF_unfold = hRecoCos[i][j]->Integral(bin_mid,bin_max);
      NB_unfold = hRecoCos[i][j]->Integral(bin_min,bin_mid_for_backward);
      afb_unf_error =  numerator[i][j]/pow((NF_unfold+NB_unfold),2);
      afb_unf_error = sqrt(afb_unf_error);
      cout<<"afb_unf_error "<<i<<"  "<<j<<"  "<<afb_unf_error<<endl;
      afb_unf_error = scale[i][j]*afb_unf_error;
      h_Unfold_Y[j]->SetBinContent(i+1,(NF_unfold-NB_unfold)/(NF_unfold+NB_unfold));
      h_Unfold_Y[j]->SetBinError(i+1,afb_unf_error);
      NF_meas = hRecoCos2[i][j]->Integral(bin_mid,bin_max);//!!!!
      NB_meas = hRecoCos2[i][j]->Integral(bin_min,bin_mid_for_backward);//!!!!
      
      //NF_meas = hNoFsrCos_M_Y[i][j]->Integral(bin_mid,bin_max);
      //NB_meas = hNoFsrCos_M_Y[i][j]->Integral(bin_min,bin_mid_for_backward);
      
      afb = (NF_meas-NB_meas)/(NF_meas+NB_meas);
      h_Meas_Y[j]->SetBinContent(i+1,afb);
      h_Meas_Y[j]->SetBinError(i+1,sqrt((1-afb*afb)/(binw*(NF_meas+NB_meas))));
      NF_true = hTrueCos_M_Y[i][j]->Integral(bin_mid,bin_max);
      NB_true = hTrueCos_M_Y[i][j]->Integral(bin_min,bin_mid_for_backward);
      afb = (NF_true-NB_true)/(NF_true+NB_true);
      h_True_Y[j]->SetBinContent(i+1,afb);
      //h_True_Y[j]->SetBinError(i+1,sqrt((1-afb*afb)/(binw*(NF_true+NB_true))));
    }
    h_Meas_Y[j]->SetLineColor(4);
    h_Meas_Y[j]->SetMarkerStyle(8);
    h_Meas_Y[j]->SetMarkerColor(4);
    //    h_Meas_Y[j]->SetFillColor(4);
    h_Meas_Y[j]->GetYaxis()->SetRangeUser(-1,1);
    h_Meas_Y[j]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Meas_Y[j]->GetYaxis()->SetTitle("A_{FB}");
    h_Meas_Y[j]->Draw("");
    h_True_Y[j]->SetLineColor(2);
    h_True_Y[j]->SetLineWidth(2);
    //    h_True_Y[j]->SetFillColor(2);
    h_True_Y[j]->Draw("sames");
    h_Unfold_Y[j]->SetMarkerStyle(8);
    h_Unfold_Y[j]->Draw("e1sames");    
  }
  
  c_AFB->SaveAs("AFB_NonDiluted_Level.C");
}

#ifndef __CINT__
int main () { RooUnfoldExample(); return 0; }  // Main program when run stand-alone
#endif
