#ifndef AFBBASE_H
#define AFBBASE_H

#include "TH1D.h"
#include "TRandom.h"
#include "TH1.h"
#include "TGraph.h"
#include "TGraphErrors.h"
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
#include "TStyle.h"
#include "TMatrixD.h"

char name_h[100];
const int nb_Y = 4;


TH1D *hDataMeasCos_M_Y_Forward[nb_Y];
TH1D *hDataMeasCos_M_Y_Backward[nb_Y];

TH1D *hMeasCos_M_Y_Forward[nb_Y];
TH1D *hMeasCos_M_Y_Backward[nb_Y];

TH1D *hMeasCos_M_Y_Forward_FSR_UP[5];
TH1D *hMeasCos_M_Y_Backward_FSR_UP[5];

TH1D *hMeasCos_M_Y_Forward_FSR_DOWN[5];
TH1D *hMeasCos_M_Y_Backward_FSR_DOWN[5];

TH1D *hUnDetectorCos_M_Y_Forward[nb_Y];
TH1D *hUnDetectorCos_M_Y_Backward[nb_Y];

TH1D *hUnDetectorCos_M_Y_Forward_FSR_UP[5];
TH1D *hUnDetectorCos_M_Y_Backward_FSR_UP[5];

TH1D *hUnDetectorCos_M_Y_Forward_FSR_DOWN[5];
TH1D *hUnDetectorCos_M_Y_Backward_FSR_DOWN[5];

TH1D *hNoFsrTruthCos_M_Y_Forward[nb_Y];
TH1D *hNoFsrTruthCos_M_Y_Backward[nb_Y];

TH2D *Response_UnDetector_Forward[nb_Y];
TH2D *Response_UnDetector_Backward[nb_Y];

TH2D *Response_UnDetector_ForwardBackward[nb_Y];
TH2D *Response_UnDetector_BackwardForward[nb_Y];

TH2D *Response_UnDetector_Forward_NO_NORM[5];
TH2D *Response_UnDetector_Backward_NO_NORM[5];

TH2D *Response_UnDetector_ForwardBackward_NO_NORM[5];
TH2D *Response_UnDetector_BackwardForward_NO_NORM[5];

TH2D *Response_NoFsr_Forward[nb_Y];
TH2D *Response_NoFsr_Backward[nb_Y];

TH2D *Response_NoFsr_Forward_FSR_UP[5];
TH2D *Response_NoFsr_Backward_FSR_UP[5];

TH2D *Response_NoFsr_Forward_FSR_DOWN[5];
TH2D *Response_NoFsr_Backward_FSR_DOWN[5];

TH2D *Inv_Response_UnDetector_Forward[nb_Y];
TH2D *Inv_Response_UnDetector_Backward[nb_Y];

TH2D *Inv_Response_NoFsr_Forward[nb_Y];
TH2D *Inv_Response_NoFsr_Backward[nb_Y];

TH2D *Inv_Response_NoFsr_Forward_FSR_UP[5];
TH2D *Inv_Response_NoFsr_Backward_FSR_UP[5];

TH2D *Inv_Response_NoFsr_Forward_FSR_DOWN[5];
TH2D *Inv_Response_NoFsr_Backward_FSR_DOWN[5];


TH1D *h_Raw_Forward[nb_Y];
TH1D *h_Raw_Backward[nb_Y];
TH1D *h_Raw_AFB[nb_Y];
TH1D *h_MC_Raw_AFB_FSR_UP[nb_Y];
TH1D *h_MC_Raw_AFB_FSR_DOWN[nb_Y];
TH1D *h_MC_Raw_AFB_FSR_Diff_Up[nb_Y];
TH1D *h_MC_Raw_AFB_FSR_Diff_Down[nb_Y];


TH1D *h_MC_Raw_AFB[nb_Y];
TH1D *h_MC_Raw_sin2412m2312_AFB[nb_Y];
TH1D *h_MC_Raw_sin2212m2312_AFB[nb_Y];
TH1D *h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[nb_Y];
TH1D *h_MC_Unfolded_UnDet_AFB_Diff_sin2212m2312[nb_Y];
TH1D *h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[nb_Y];
TH1D *h_MC_Unfolded_NoFsr_AFB_Diff_sin2212m2312[nb_Y];


TH1D *h_Unfolded_UnDet_Forward[nb_Y];
TH1D *h_Unfolded_UnDet_Backward[nb_Y];
TH1D *h_Unfolded_UnDet_AFB[nb_Y];

TH1D *h_Closure_Unfolded_UnDet_Forward[nb_Y];
TH1D *h_Closure_Unfolded_UnDet_Backward[nb_Y];
TH1D *h_Closure_Unfolded_UnDet_AFB[nb_Y];


TH1D *h_MC_UnDet_AFB[nb_Y];
TH1D *h_MC_UnDet_AFB_FSR_UP[nb_Y];	
TH1D *h_MC_UnDet_AFB_FSR_DOWN[nb_Y];
TH1D *h_MC_UnDet_AFB_FSR_Diff_Up[nb_Y];
TH1D *h_MC_UnDet_AFB_FSR_Diff_Down[nb_Y];

TH1D *h_Unfolded_NoFsr_Forward[nb_Y];
TH1D *h_Unfolded_NoFsr_Backward[nb_Y];
TH1D *h_Unfolded_NoFsr_AFB[nb_Y];

TH1D *h_Closure_Unfolded_NoFsr_Forward[nb_Y];
TH1D *h_Closure_Unfolded_NoFsr_Backward[nb_Y];

TH1D *h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Up[nb_Y];
TH1D *h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Down[nb_Y];

TH1D *h_MC_NoFsr_AFB[nb_Y];	

TH1D *hMeasCos_M_Y[30][nb_Y];
TH1D *hDataMeasCos_M_Y[nb_Y];
TH1D *hDataMeasCos_M_Y_central[30][nb_Y];
TH1D *hNoFsrTruthCos_M_Y[30][nb_Y];
TH1D *hTrueCos_M_Y[30][nb_Y];
TH1D *hTrueCos_MASS_M_Y[30][nb_Y];
TH1D *hDataMeasCos_MASS_M_Y[30][nb_Y];

TH1D *AFB1_err_M_Y[30][nb_Y];
TH1D *AFB2_err_M_Y[30][nb_Y];

// alignment
TH1D *Align_Bowing_hMeasCos_M_Y_Forward[nb_Y];
TH1D *Align_Curl_hMeasCos_M_Y_Forward[nb_Y];
TH1D *Align_Curl200mu_hMeasCos_M_Y_Forward[nb_Y];
TH1D *Align_Elliptical_hMeasCos_M_Y_Forward[nb_Y];
TH1D *Align_Radial_hMeasCos_M_Y_Forward[nb_Y];
TH1D *Align_Sagitta_hMeasCos_M_Y_Forward[nb_Y];
TH1D *Align_Skew_hMeasCos_M_Y_Forward[nb_Y];
TH1D *Align_Telescope_hMeasCos_M_Y_Forward[nb_Y];
TH1D *Align_CurlV2TF_hMeasCos_M_Y_Forward[nb_Y];
TH1D *Align_Twist_hMeasCos_M_Y_Forward[nb_Y];
TH1D *Align_Zexpansion_hMeasCos_M_Y_Forward[nb_Y];
TH1D *Align_Ideal_hMeasCos_M_Y_Forward[nb_Y];
TH1D *Align_Startup_hMeasCos_M_Y_Forward[nb_Y];


TH1D *Align_Bowing_hMeasCos_M_Y_Backward[nb_Y];
TH1D *Align_Curl_hMeasCos_M_Y_Backward[nb_Y];
TH1D *Align_Curl200mu_hMeasCos_M_Y_Backward[nb_Y];
TH1D *Align_Elliptical_hMeasCos_M_Y_Backward[nb_Y];
TH1D *Align_Radial_hMeasCos_M_Y_Backward[nb_Y];
TH1D *Align_Sagitta_hMeasCos_M_Y_Backward[nb_Y];
TH1D *Align_Skew_hMeasCos_M_Y_Backward[nb_Y];
TH1D *Align_Telescope_hMeasCos_M_Y_Backward[nb_Y];
TH1D *Align_CurlV2TF_hMeasCos_M_Y_Backward[nb_Y];
TH1D *Align_Twist_hMeasCos_M_Y_Backward[nb_Y];
TH1D *Align_Zexpansion_hMeasCos_M_Y_Backward[nb_Y];
TH1D *Align_Ideal_hMeasCos_M_Y_Backward[nb_Y];
TH1D *Align_Startup_hMeasCos_M_Y_Backward[nb_Y];


TH2D *Align_Bowing_Inv_Response_UnDetector_Forward[nb_Y];
TH2D *Align_Curl_Inv_Response_UnDetector_Forward[nb_Y];
TH2D *Align_Curl200mu_Inv_Response_UnDetector_Forward[nb_Y];
TH2D *Align_Elliptical_Inv_Response_UnDetector_Forward[nb_Y];
TH2D *Align_Radial_Inv_Response_UnDetector_Forward[nb_Y];
TH2D *Align_Sagitta_Inv_Response_UnDetector_Forward[nb_Y];
TH2D *Align_Skew_Inv_Response_UnDetector_Forward[nb_Y];
TH2D *Align_Telescope_Inv_Response_UnDetector_Forward[nb_Y];
TH2D *Align_CurlV2TF_Inv_Response_UnDetector_Forward[nb_Y];
TH2D *Align_Twist_Inv_Response_UnDetector_Forward[nb_Y];
TH2D *Align_Zexpansion_Inv_Response_UnDetector_Forward[nb_Y];
TH2D *Align_Ideal_Inv_Response_UnDetector_Forward[nb_Y];
TH2D *Align_Startup_Inv_Response_UnDetector_Forward[nb_Y];


TH2D *Align_Bowing_Inv_Response_UnDetector_Backward[nb_Y];
TH2D *Align_Curl_Inv_Response_UnDetector_Backward[nb_Y];
TH2D *Align_Curl200mu_Inv_Response_UnDetector_Backward[nb_Y];
TH2D *Align_Elliptical_Inv_Response_UnDetector_Backward[nb_Y];
TH2D *Align_Radial_Inv_Response_UnDetector_Backward[nb_Y];
TH2D *Align_Sagitta_Inv_Response_UnDetector_Backward[nb_Y];
TH2D *Align_Skew_Inv_Response_UnDetector_Backward[nb_Y];
TH2D *Align_Telescope_Inv_Response_UnDetector_Backward[nb_Y];
TH2D *Align_CurlV2TF_Inv_Response_UnDetector_Backward[nb_Y];
TH2D *Align_Twist_Inv_Response_UnDetector_Backward[nb_Y];
TH2D *Align_Zexpansion_Inv_Response_UnDetector_Backward[nb_Y];
TH2D *Align_Ideal_Inv_Response_UnDetector_Backward[nb_Y];
TH2D *Align_Startup_Inv_Response_UnDetector_Backward[nb_Y];


TH2D *Align_Bowing_Inv_Response_NoFsr_Forward[nb_Y];
TH2D *Align_Curl_Inv_Response_NoFsr_Forward[nb_Y];
TH2D *Align_Curl200mu_Inv_Response_NoFsr_Forward[nb_Y];
TH2D *Align_Elliptical_Inv_Response_NoFsr_Forward[nb_Y];
TH2D *Align_Radial_Inv_Response_NoFsr_Forward[nb_Y];
TH2D *Align_Sagitta_Inv_Response_NoFsr_Forward[nb_Y];
TH2D *Align_Skew_Inv_Response_NoFsr_Forward[nb_Y];
TH2D *Align_Telescope_Inv_Response_NoFsr_Forward[nb_Y];
TH2D *Align_CurlV2TF_Inv_Response_NoFsr_Forward[nb_Y];
TH2D *Align_Twist_Inv_Response_NoFsr_Forward[nb_Y];
TH2D *Align_Zexpansion_Inv_Response_NoFsr_Forward[nb_Y];
TH2D *Align_Ideal_Inv_Response_NoFsr_Forward[nb_Y];
TH2D *Align_Startup_Inv_Response_NoFsr_Forward[nb_Y];


TH2D *Align_Bowing_Inv_Response_NoFsr_Backward[nb_Y];
TH2D *Align_Curl_Inv_Response_NoFsr_Backward[nb_Y];
TH2D *Align_Curl200mu_Inv_Response_NoFsr_Backward[nb_Y];
TH2D *Align_Elliptical_Inv_Response_NoFsr_Backward[nb_Y];
TH2D *Align_Radial_Inv_Response_NoFsr_Backward[nb_Y];
TH2D *Align_Sagitta_Inv_Response_NoFsr_Backward[nb_Y];
TH2D *Align_Skew_Inv_Response_NoFsr_Backward[nb_Y];
TH2D *Align_Telescope_Inv_Response_NoFsr_Backward[nb_Y];
TH2D *Align_CurlV2TF_Inv_Response_NoFsr_Backward[nb_Y];
TH2D *Align_Twist_Inv_Response_NoFsr_Backward[nb_Y];
TH2D *Align_Zexpansion_Inv_Response_NoFsr_Backward[nb_Y];
TH2D *Align_Ideal_Inv_Response_NoFsr_Backward[nb_Y];
TH2D *Align_Startup_Inv_Response_NoFsr_Backward[nb_Y];

TH1D *h_MC_Raw_Align_Bowing_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Raw_Align_Curl_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Raw_Align_Curl200mu_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Raw_Align_Elliptical_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Raw_Align_Radial_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Raw_Align_Sagitta_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Raw_Align_Skew_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Raw_Align_Telescope_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Raw_Align_CurlV2TF_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Raw_Align_Twist_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Raw_Align_Zexpansion_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Raw_Align_Startup_m_Ideal_AFB[nb_Y];

TH1D *h_MC_Unfolded_UnDet_Align_Bowing_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_UnDet_Align_Curl_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_UnDet_Align_Curl200mu_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_UnDet_Align_Elliptical_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_UnDet_Align_Radial_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_UnDet_Align_Sagitta_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_UnDet_Align_Skew_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_UnDet_Align_Telescope_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_UnDet_Align_CurlV2TF_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_UnDet_Align_Twist_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_UnDet_Align_Zexpansion_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[nb_Y];

TH1D *h_MC_Unfolded_NoFsr_Align_Bowing_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_NoFsr_Align_Curl_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_NoFsr_Align_Curl200mu_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_NoFsr_Align_Elliptical_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_NoFsr_Align_Radial_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_NoFsr_Align_Sagitta_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_NoFsr_Align_Skew_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_NoFsr_Align_Telescope_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_NoFsr_Align_CurlV2TF_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_NoFsr_Align_Twist_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_NoFsr_Align_Zexpansion_m_Ideal_AFB[nb_Y];
TH1D *h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[nb_Y];

//


   Int_t           p1id;
   Int_t           p2id;
   Double_t        p1_px;
   Double_t        p1_py;
   Double_t        p1_pz;
   Double_t        p1_E;
   Double_t        p2_px;
   Double_t        p2_py;
   Double_t        p2_pz;
   Double_t        p2_E;
   Double_t        Mll_gen;
   Double_t        costheta_gen;
   Double_t        phi_gen;
   Double_t        costheta_true;
   Double_t        phi_true;
   Double_t        yZ_gen;
   Double_t        zpT_gen;
   Double_t        l_px_gen;
   Double_t        l_py_gen;
   Double_t        l_pz_gen;
   Double_t        l_E_gen;
   Double_t        lbar_px_gen;
   Double_t        lbar_py_gen;
   Double_t        lbar_pz_gen;
   Double_t        lbar_E_gen;
   Double_t        l_eta_gen;
   Double_t        l_pt_gen;
   Double_t        lbar_eta_gen;
   Double_t        lbar_pt_gen;
   Double_t        Mll_genfsr;
   Double_t        costheta_genfsr;
   Double_t        phi_genfsr;
   Double_t        yZ_genfsr;
   Double_t        zpT_genfsr;
   Double_t        l_px_genfsr;
   Double_t        l_py_genfsr;
   Double_t        l_pz_genfsr;
   Double_t        l_E_genfsr;
   Double_t        lbar_px_genfsr;
   Double_t        lbar_py_genfsr;
   Double_t        lbar_pz_genfsr;
   Double_t        lbar_E_genfsr;
   Double_t        l_eta_genfsr;
   Double_t        l_pt_genfsr;
   Double_t        lbar_eta_genfsr;
   Double_t        lbar_pt_genfsr;
   Double_t        Mll_reco;
   Double_t        costheta_reco;
   Double_t        phi_reco;
   Double_t        yZ_reco;
   Double_t        zpT_reco;
   Double_t        l_px_reco;
   Double_t        l_py_reco;
   Double_t        l_pz_reco;
   Double_t        l_E_reco;
   Double_t        lbar_px_reco;
   Double_t        lbar_py_reco;
   Double_t        lbar_pz_reco;
   Double_t        lbar_E_reco;
   Double_t        l_eta_reco;
   Double_t        l_pt_reco;
   Double_t        lbar_eta_reco;
   Double_t        lbar_pt_reco;

TH1D *h_Sin_MeasCos_M_Y_Forward[nb_Y];
TH1D *h_Sin_MeasCos_M_Y_Backward[nb_Y];
TH2D *Response_Sin_UnDetector_Forward[nb_Y];
TH2D *Response_Sin_UnDetector_Backward[nb_Y];
TH2D *Response_Sin_NoFsr_Forward[nb_Y];
TH2D *Response_Sin_NoFsr_Backward[nb_Y];
TH2D *Inv_Response_Sin_UnDetector_Forward[nb_Y];
TH2D *Inv_Response_Sin_UnDetector_Backward[nb_Y];
TH2D *Inv_Response_Sin_NoFsr_Forward[nb_Y];
TH2D *Inv_Response_Sin_NoFsr_Backward[nb_Y];

TH1D *h_Sin2312_MeasCos_M_Y_Forward[nb_Y];
TH1D *h_Sin2312_MeasCos_M_Y_Backward[nb_Y];
TH2D *Response_Sin2312_UnDetector_Forward[nb_Y];
TH2D *Response_Sin2312_UnDetector_Backward[nb_Y];
TH2D *Response_Sin2312_NoFsr_Forward[nb_Y];
TH2D *Response_Sin2312_NoFsr_Backward[nb_Y];
TH2D *Inv_Response_Sin2312_UnDetector_Forward[nb_Y];
TH2D *Inv_Response_Sin2312_UnDetector_Backward[nb_Y];
TH2D *Inv_Response_Sin2312_NoFsr_Forward[nb_Y];
TH2D *Inv_Response_Sin2312_NoFsr_Backward[nb_Y];

TH1D *h_Sin2412_MeasCos_M_Y_Forward[nb_Y];
TH1D *h_Sin2412_MeasCos_M_Y_Backward[nb_Y];
TH2D *Response_Sin2412_UnDetector_Forward[nb_Y];
TH2D *Response_Sin2412_UnDetector_Backward[nb_Y];
TH2D *Response_Sin2412_NoFsr_Forward[nb_Y];
TH2D *Response_Sin2412_NoFsr_Backward[nb_Y];
TH2D *Inv_Response_Sin2412_UnDetector_Forward[nb_Y];
TH2D *Inv_Response_Sin2412_UnDetector_Backward[nb_Y];
TH2D *Inv_Response_Sin2412_NoFsr_Forward[nb_Y];
TH2D *Inv_Response_Sin2412_NoFsr_Backward[nb_Y];

TH1D *h_Sin2212_MeasCos_M_Y_Forward[nb_Y];
TH1D *h_Sin2212_MeasCos_M_Y_Backward[nb_Y];
TH2D *Response_Sin2212_UnDetector_Forward[nb_Y];
TH2D *Response_Sin2212_UnDetector_Backward[nb_Y];
TH2D *Response_Sin2212_NoFsr_Forward[nb_Y];
TH2D *Response_Sin2212_NoFsr_Backward[nb_Y];
TH2D *Inv_Response_Sin2212_UnDetector_Forward[nb_Y];
TH2D *Inv_Response_Sin2212_UnDetector_Backward[nb_Y];
TH2D *Inv_Response_Sin2212_NoFsr_Forward[nb_Y];
TH2D *Inv_Response_Sin2212_NoFsr_Backward[nb_Y];

#endif
