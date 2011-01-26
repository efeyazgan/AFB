#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <map>
#include <sys/types.h>

#include <TFile.h>
#include <TChain.h>
#include <TTree.h>
#include <TROOT.h>
#include <TCanvas.h>
#include <TPostScript.h>
#include <TASImage.h>
#include <TAxis.h>
#include <TArrow.h>
#include <TBox.h>
#include <TWbox.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TF1.h>
#include <TLine.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TLegend.h>
#include <TProfile.h>
#include <TProfile2D.h>
#include <TPaveText.h>
#include <TPaveLabel.h>
#include <TStyle.h>
#include <TApplication.h>
#include <TLatex.h>
#include <TLorentzVector.h>
#include <TKey.h>
#include <TRandom.h>

using namespace std;
TFile* f; TTree* myTree; TFile* h; 


int main()
{

  h = new TFile("ResMs.root","RECREATE");
  h->cd();

  //////////////////////////////////////////////////// Histogram ///////////////////////////////////////////////////////////////////////

  float xAxis_AFB[12] = {40,50,60,76,86,91,96,106,120,150,200,600};
  float xAxis_AFB_TOPLOT[11] = {45,55,68,81,88.5,93.5,101,113,135,175,400};
   
  int nbin=11;
 
  TH1F *h_MZlepton_F = new TH1F("h_MZlepton_F","M(Z)#rightarrow #l#l",nbin,xAxis_AFB );
  TH1F *h_MZlepton_B = new TH1F("h_MZlepton_B","M(Z)#rightarrow #l#l",nbin,xAxis_AFB );

  TH1F *hTrue_F = new TH1F("hTrue_F", "Test Truth F",nbin,xAxis_AFB );
  TH1F *hTrue_B = new TH1F("hTrue_B", "Test Truth B",nbin,xAxis_AFB );

  TH1F *hTrue_F_before_cuts = new TH1F("hTrue_F_before_cuts", "Test Truth F_before_cuts",nbin,xAxis_AFB );
  TH1F *hTrue_B_before_cuts = new TH1F("hTrue_B_before_cuts", "Test Truth B_before_cuts",nbin,xAxis_AFB );

  TH1F *h_Unfolded_F = new TH1F("h_Unfolded_F", "Unfolded_F", nbin,xAxis_AFB );
  TH1F *h_Unfolded_B = new TH1F("h_Unfolded_B", "Unfolded_B", nbin,xAxis_AFB );

  TH1F *h_Unfolded_over_Truth_F = new TH1F("h_Unfolded_over_Truth_F", "", nbin,xAxis_AFB );
  TH1F *h_Unfolded_over_Truth_B = new TH1F("h_Unfolded_over_Truth_B", "", nbin,xAxis_AFB );

  TH1F *h_Unfolded_and_AcceptanceCorrected_F = new TH1F("h_Unfolded_and_AcceptanceCorrected_F","h_Unfolded_and_AcceptanceCorrected_F",nbin,xAxis_AFB);
  TH1F *h_Unfolded_and_AcceptanceCorrected_B = new TH1F("h_Unfolded_and_AcceptanceCorrected_B","h_Unfolded_and_AcceptanceCorrected_B",nbin,xAxis_AFB);

  TH1F *h_acc_corr_F = new TH1F("h_acc_corr_F","h_acc_corr_F",nbin,xAxis_AFB );
  h_acc_corr_F->Sumw2();
  TH1F *h_acc_corr_B = new TH1F("h_acc_corr_B","h_acc_corr_B",nbin,xAxis_AFB );
  h_acc_corr_B->Sumw2();


  TH2F *h_RFF = new TH2F("h_RFF","",nbin, xAxis_AFB, nbin, xAxis_AFB);
  TH2F *h_RFF_Normalized = new TH2F("h_RFF_Normalized","",nbin, xAxis_AFB, nbin, xAxis_AFB);
  h_RFF_Normalized->GetXaxis()->SetTitle("Generated Mass [GeV]");
  h_RFF_Normalized->GetYaxis()->SetTitle("Reconstructed Mass [GeV]");
  TH1F *h_NF_o = new TH1F("h_NF_o","",nbin, xAxis_AFB);

  TH2F *h_RBB = new TH2F("h_RBB","",nbin, xAxis_AFB, nbin, xAxis_AFB);
  TH2F *h_RBB_Normalized = new TH2F("h_RBB_Normalized","",nbin, xAxis_AFB, nbin, xAxis_AFB);
  h_RBB_Normalized->GetXaxis()->SetTitle("Generated Mass [GeV]");
  h_RBB_Normalized->GetYaxis()->SetTitle("Reconstructed Mass [GeV]");
  TH1F *h_NB_o = new TH1F("h_NB_o","",nbin, xAxis_AFB);

  TH2F *h_RFB = new TH2F("h_RFB","",nbin, xAxis_AFB, nbin, xAxis_AFB);
  TH2F *h_RFB_Normalized = new TH2F("h_RFB_Normalized","",nbin, xAxis_AFB, nbin, xAxis_AFB);
  h_RFB_Normalized->GetXaxis()->SetTitle("Generated Mass [GeV]");
  h_RFB_Normalized->GetYaxis()->SetTitle("Reconstructed Mass [GeV]");

  TH2F *h_RBF = new TH2F("h_RBF","",nbin, xAxis_AFB, nbin, xAxis_AFB);
  TH2F *h_RBF_Normalized = new TH2F("h_RBF_Normalized","",nbin, xAxis_AFB, nbin, xAxis_AFB);
  h_RBF_Normalized->GetXaxis()->SetTitle("Generated Mass [GeV]");
  h_RBF_Normalized->GetYaxis()->SetTitle("Reconstructed Mass [GeV]");

  TH1F *h_DeltaAFB = new TH1F("h_DeltaAFB","",nbin, xAxis_AFB);

  TH1F *h_dr1 = new TH1F("h_dr1","gen e- - reco",10000,0,1);
  TH1F *h_dr2 = new TH1F("h_dr2","gen e+ - reco",10000,0,1);

  /////////////////////////////// Input & Output //////////////////////////////////////////

  
  f = new TFile("unfolding.root");
  if ( f->IsZombie() ) exit(1);
   
  myTree = (TTree*)f->Get("tree");
  
  Long64_t nentries = myTree->GetEntries();
  
  int event; int reco; 
  float genPx_[2], genPy_[2], genPz_[2], genE_[2];
  float recoM, recoCS;
  float recoSCeta[2],recoSCphi[2];
 
  myTree->SetBranchAddress("event", &event);
  myTree->SetBranchAddress("genPx",genPx_);
  myTree->SetBranchAddress("genPy",genPy_);
  myTree->SetBranchAddress("genPz",genPz_);
  myTree->SetBranchAddress("genE",genE_);
  
  myTree->SetBranchAddress("recoSCeta",recoSCeta);
  myTree->SetBranchAddress("recoSCphi",recoSCphi);
  
  myTree->SetBranchAddress("recoM",&recoM);
  myTree->SetBranchAddress("recoCS",&recoCS);

  myTree->SetBranchAddress("reco",&reco);


  ////////////////////////////////////////// start /////////////////////////////////////////////////////////////

  
  for( Int_t i=0; i<nentries; ++i){
    
    if(i%100000==0)std::cout<<i<<std::endl;
    
    myTree->GetEntry(i);
    
    float cscos(TLorentzVector mom, TLorentzVector elec1);
    float deltaR(float eta1, float eta2, float phi1, float phi2);

 
    //================================= gen electron =================================================//
    TLorentzVector p4gen[2];
    
    for(Int_t i=0; i<2; i++){ 
      TLorentzVector p4hf(genPx_[i],genPy_[i],genPz_[i],genE_[i]); 
      p4gen[i] = p4hf;
      
    }
    
    TLorentzVector mom= p4gen[0]+p4gen[1];
    TLorentzVector elec1=p4gen[0];
    float gen_costhetaCSreco =0;
    gen_costhetaCSreco = cscos(mom,elec1);  
    float MZ = mom.M();
 
    //================================== gsf electron ===============================================//
    float MZlepton=0;
    float costhetaCSreco__RECO=0;

    if(reco){
      MZlepton = recoM;
      costhetaCSreco__RECO = recoCS;
    }

    //================================ dr matching (gen, sc reco) =========================================//
    
    float minR = 100; 
    float dr1 = 100; 
    float dr2 = 100; 

    if(reco){
      float gen_eta1=0;  float gen_eta2=0;
      float gen_phi1=0;  float gen_phi2=0;
      
      float reco_eta1=0;  float reco_eta2=0;
      float reco_phi1=0;  float reco_phi2=0;	

      gen_eta1 = p4gen[0].Eta();gen_eta2 = p4gen[1].Eta();
      gen_phi1 = p4gen[0].Phi();gen_phi2 = p4gen[1].Phi();
      
      reco_eta1 = recoSCeta[0]; reco_eta2 = recoSCeta[1];
      reco_phi1 = recoSCphi[0]; reco_phi2 = recoSCphi[1];

      if(minR>deltaR(gen_eta1,reco_eta1,gen_phi1,reco_phi1))minR = deltaR(gen_eta1,reco_eta1,gen_phi1,reco_phi1);
      if(minR>deltaR(gen_eta1,reco_eta2,gen_phi1,reco_phi2))minR = deltaR(gen_eta1,reco_eta2,gen_phi1,reco_phi2);
      h_dr1->Fill(minR); dr1 = minR;

      minR = 100;
      if(minR>deltaR(gen_eta2,reco_eta1,gen_phi2,reco_phi1))minR =deltaR(gen_eta2,reco_eta1,gen_phi2,reco_phi1);
      if(minR>deltaR(gen_eta2,reco_eta2,gen_phi2,reco_phi2))minR =deltaR(gen_eta2,reco_eta2,gen_phi2,reco_phi2);
      h_dr2->Fill(minR); dr2 = minR;

    }
    int check_dr=0;
    if(reco && dr1<0.1 && dr2<0.1) check_dr=1;


    //======================================= Response Matrices ==============================================//
    // target events are "select = 1" if it is satisfied the following condition
    //                   1. recoMass 40-600
    //                   2. genMass 40-600, pt>20, |eta|<2.5
    //                   3. mc matching dr < 0.1
    //========================================================================================================//

    int select =0;

    if(reco && check_dr && MZlepton>40 && MZlepton<600 && MZ > 40. && MZ < 600. && fabs(p4gen[0].Eta())<2.5 && p4gen[0].Pt()>20 && fabs(p4gen[1].Eta())<2.5 && p4gen[1].Pt()>20) select=1; 
  
    //if ((event%2==0 || event%2==1) && select){ 
    if (event%2==0 && select){ //half/half

      if (costhetaCSreco__RECO > 0) h_NF_o->Fill(MZlepton);
      if (costhetaCSreco__RECO < 0 ) h_NB_o->Fill(MZlepton);

      //------------------FF-----------------------------------------
      if (gen_costhetaCSreco > 0){
	if (costhetaCSreco__RECO > 0)h_RFF->Fill(MZ, MZlepton);
      }
            
      //------------------BB-----------------------------------------
      if (gen_costhetaCSreco < 0 ){
	if (costhetaCSreco__RECO < 0 )h_RBB->Fill(MZ, MZlepton);
      }
      
      //------------------FB-----------------------------------------
      if (gen_costhetaCSreco > 0){
	if (costhetaCSreco__RECO < 0 )h_RFB->Fill(MZ, MZlepton);
      }
      
      //------------------BF-----------------------------------------
      if (gen_costhetaCSreco < 0){
	if (costhetaCSreco__RECO > 0)h_RBF->Fill(MZ, MZlepton);
      }
    }
    
    //if (event%2==0 || event%2==1){  ///// no cut at all!!!!

    if (event%2==1){ //half/half ////<------Youn is doing , Efe did--------------->if (iev < nevent*r_test){ 
      if (gen_costhetaCSreco > 0) hTrue_F_before_cuts->Fill(MZ);
      if (gen_costhetaCSreco < 0) hTrue_B_before_cuts->Fill(MZ);
      if (select){
	//Efe did-------->if (MZ > 15. && parton_pt[0] > 20. && parton_pt[1] > 20. && fabs(parton_eta[0]) < 2.1 && fabs(parton_eta[1]) < 2.1){
	if (MZ > 40. &&  MZ < 600. && fabs(p4gen[0].Eta())<2.5 && p4gen[0].Pt()>20 && fabs(p4gen[1].Eta())<2.5 && p4gen[1].Pt()>20){  ////youn did
	  if (gen_costhetaCSreco > 0) hTrue_F->Fill(MZ);
	  if (gen_costhetaCSreco < 0) hTrue_B->Fill(MZ);	  
	}
	if (costhetaCSreco__RECO > 0) h_MZlepton_F->Fill(MZlepton);
	if (costhetaCSreco__RECO < 0) h_MZlepton_B->Fill(MZlepton);
      }
    }
  }

  //============================================= after filling response matrics =======================================//

  float forward[50]={};
  float backward[50]={};
  for (int i=1;i<=nbin;i++){
    
    for (int j=1;j<=nbin;j++){// I fixed h_NF_o->GetBinContent(i) to h_NF_o->GetBinContent(j)
      if(h_NF_o->GetBinContent(j))h_RFF_Normalized->SetBinContent(i,j,h_RFF->GetBinContent(i,j)/h_NF_o->GetBinContent(j));
      if(h_NB_o->GetBinContent(j))h_RBB_Normalized->SetBinContent(i,j,h_RBB->GetBinContent(i,j)/h_NB_o->GetBinContent(j));
      if(h_NB_o->GetBinContent(j))h_RFB_Normalized->SetBinContent(i,j,h_RFB->GetBinContent(i,j)/h_NB_o->GetBinContent(j));
      if(h_NF_o->GetBinContent(j))h_RBF_Normalized->SetBinContent(i,j,h_RBF->GetBinContent(i,j)/h_NF_o->GetBinContent(j));
      forward[i] += h_RFF_Normalized->GetBinContent(i,j)*h_MZlepton_F->GetBinContent(j)+h_RFB_Normalized->GetBinContent(i,j)*h_MZlepton_B->GetBinContent(j);
      backward[i] += h_RBB_Normalized->GetBinContent(i,j)*h_MZlepton_B->GetBinContent(j)+h_RBF_Normalized->GetBinContent(i,j)*h_MZlepton_F->GetBinContent(j);
    }
    
    h_Unfolded_F->SetBinContent(i,forward[i]);
    h_Unfolded_B->SetBinContent(i,backward[i]);
    
    h_Unfolded_and_AcceptanceCorrected_F->SetBinContent(i,forward[i]*(hTrue_F_before_cuts->GetBinContent(i)/hTrue_F->GetBinContent(i)));
    h_Unfolded_and_AcceptanceCorrected_B->SetBinContent(i,backward[i]*(hTrue_B_before_cuts->GetBinContent(i)/hTrue_B->GetBinContent(i)));

    h_acc_corr_F->SetBinContent(i,(hTrue_F->GetBinContent(i)/hTrue_F_before_cuts->GetBinContent(i)));
    h_acc_corr_B->SetBinContent(i,(hTrue_B->GetBinContent(i)/hTrue_B_before_cuts->GetBinContent(i)));

  }

  //=========================================== Error Calculation =======================================================//
  
  float D_AFB_NFobs_1st[50][50]={0.},D_AFB_NFobs_2nd[50][50]={0.},D_AFB_NBobs_1st[50][50]={0.},D_AFB_NBobs_2nd[50][50]={0.};
  float D_AFB_NFobs[50][50]={0.},D_AFB_NBobs[50][50]={0.},DeltaAFB[50]={0.};
  float DeltaNFobs[50]={0.},DeltaNBobs[50]={0.}; 
  
  for (int i=1;i<=nbin;i++){
    for (int j=1;j<=nbin;j++){

      D_AFB_NFobs_1st[i][j] = -2*h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i)*h_RFF_Normalized->GetBinContent(i,j);
      D_AFB_NFobs_1st[i][j] /= h_acc_corr_F->GetBinContent(i);
      D_AFB_NFobs_1st[i][j] /= pow(h_Unfolded_and_AcceptanceCorrected_F->GetBinContent(i) + h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i),2);
      D_AFB_NFobs_2nd[i][j] = 2*h_Unfolded_and_AcceptanceCorrected_F->GetBinContent(i)*h_RBF_Normalized->GetBinContent(i,j);
      D_AFB_NFobs_2nd[i][j] /= h_acc_corr_B->GetBinContent(i);
      D_AFB_NFobs_2nd[i][j] /= pow(h_Unfolded_and_AcceptanceCorrected_F->GetBinContent(i) + h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i),2);
      D_AFB_NFobs[i][j] =  D_AFB_NFobs_1st[i][j] +  D_AFB_NFobs_2nd[i][j];

      D_AFB_NBobs_1st[i][j] = -2*h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i)*h_RFB_Normalized->GetBinContent(i,j);
      D_AFB_NBobs_1st[i][j] /= h_acc_corr_F->GetBinContent(i);
      D_AFB_NBobs_1st[i][j] /= pow(h_Unfolded_and_AcceptanceCorrected_F->GetBinContent(i) + h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i),2);
      D_AFB_NBobs_2nd[i][j] = 2*h_Unfolded_and_AcceptanceCorrected_F->GetBinContent(i)*h_RBB_Normalized->GetBinContent(i,j);
      D_AFB_NBobs_2nd[i][j] /= h_acc_corr_B->GetBinContent(i);
      D_AFB_NBobs_2nd[i][j] /= pow(h_Unfolded_and_AcceptanceCorrected_F->GetBinContent(i) + h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i),2);
      D_AFB_NBobs[i][j] =  D_AFB_NBobs_1st[i][j] +  D_AFB_NBobs_2nd[i][j];  
           
      DeltaNFobs[j] = sqrt(h_MZlepton_F->GetBinContent(i));
      DeltaNBobs[j] = sqrt(h_MZlepton_B->GetBinContent(i));
      
      DeltaAFB[i] += pow(D_AFB_NFobs[i][j]*DeltaNFobs[j],2)+pow(D_AFB_NBobs[i][j]*DeltaNBobs[j],2);
    }
    h_DeltaAFB->SetBinContent(i,DeltaAFB[i]);
  } 


  h->Write();
  h->Close();
  
  return 0;
}

float deltaR(float eta1, float eta2, float phi1, float phi2)
{
  
  float deta = fabs(eta2 - eta1);
  float dphi = fabs(phi2 - phi1);
  if(dphi > 3.14159265) { dphi = 2.0 * 3.14159265 - dphi;}
  float dr = sqrt(deta*deta+dphi*dphi);
  return dr;
}  


float cscos(TLorentzVector mom, TLorentzVector elec1)
{

  double CM_ENERGY=7000.0;

  TLorentzVector Pbeam(  0, 0,  CM_ENERGY/2.0, CM_ENERGY/2.0);
  TLorentzVector Ptarget(0, 0, -CM_ENERGY/2.0, CM_ENERGY/2.0);
  
  TLorentzVector newQ(mom);
  TVector3 newboost = newQ.BoostVector();
  
  //  1) tag the beam direction with the dimuon Pz component
  if (newQ.Pz() < 0) {
    TLorentzVector newtmp(Pbeam);
    Pbeam = Ptarget;
    Ptarget = newtmp;
  }
  
  Pbeam.Boost(-newboost);
  Ptarget.Boost(-newboost);
  
  // 2) take the reference line
  TVector3 newbeam   =  Pbeam.Vect();
  TVector3 newtarget = -Ptarget.Vect();
  
  float newmag = newbeam.Mag();
  TVector3 newbeamUnit(newbeam.X()/newmag, newbeam.Y()/newmag, newbeam.Z()/newmag);
  
  newmag = newtarget.Mag();
  TVector3 newtargetUnit(newtarget.X()/newmag, newtarget.Y()/newmag, newtarget.Z()/newmag);
  
  // 3) bisec-direction of beam and target in dimuon rest frame.
  TVector3 newz_axis = newbeamUnit + newtargetUnit;
  
  // 4) boost muon into the rest frame of dimuon system. 
  elec1.Boost(-newboost);
  
  
  return cos(elec1.Vect().Angle(newz_axis));
}


  
