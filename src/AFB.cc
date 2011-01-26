// -*- C++ -*-
//
// Package:    AFB
// Class:      AFB
// 
/**\class AFB AFB.cc ZJet/AFB/src/AFB.cc

Description: <one line class summary>

Implementation:
<Notes on implementation>
*/
//
// Original Author:  Efe Yazgan
//         Created:  Tue Feb  3 10:08:43 CET 2009
// $Id: AFB.cc,v 1.7 2011/01/14 09:56:12 efe Exp $
//
//
#include <memory>
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/Event.h"

#include "FWCore/Framework/interface/EventSetupRecord.h"

#include "FWCore/Framework/interface/Run.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TProfile.h"
#include <TROOT.h>
#include "TF1.h"
#include "TMath.h"
#include <TSystem.h>
#include "TFile.h"
#include <TCanvas.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <Math/VectorUtil.h>
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include "DataFormats/Candidate/interface/CompositePtrCandidate.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Candidate/interface/CandAssociation.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
//muons
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/RecoCandidate/interface/RecoCandidate.h"
#include "DataFormats/MuonReco/interface/MuonChamberMatch.h"
#include "DataFormats/MuonReco/interface/MuonIsolation.h"
#include "DataFormats/MuonReco/interface/MuonEnergy.h"
#include "DataFormats/MuonReco/interface/MuonTime.h"
#include "DataFormats/MuonReco/interface/MuonQuality.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
#include "DataFormats/RecoCandidate/interface/IsoDeposit.h"
#include "DataFormats/RecoCandidate/interface/IsoDepositFwd.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/Common/interface/ValueMap.h"
//jets
#include "DataFormats/JetReco/interface/CaloJetCollection.h"
#include "DataFormats/JetReco/interface/CaloJet.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "JetMETCorrections/Objects/interface/JetCorrector.h"
//#include "RecoJets/JetAlgorithms/interface/JetIDHelper.h"
#include "RecoJets/JetProducers/interface/JetIDHelper.h"
// MET
#include "DataFormats/METReco/interface/CaloMET.h"
#include "DataFormats/METReco/interface/CaloMETFwd.h"
#include "DataFormats/METReco/interface/MET.h"
#include "DataFormats/METReco/interface/METFwd.h"
#include "DataFormats/METReco/interface/PFMET.h"
#include "DataFormats/METReco/interface/PFMETFwd.h" 
//electron isolation
#include "FWCore/Utilities/interface/InputTag.h"
//#include "SHarper/EgIsolExample/interface/EgIsolExample.h"
#include "DataFormats/BeamSpot/interface/BeamSpot.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include "DataFormats/Candidate/interface/CompositePtrCandidate.h"
//trigger
#include "DataFormats/L1GlobalMuonTrigger/interface/L1MuRegionalCand.h"
#include "DataFormats/L1GlobalMuonTrigger/interface/L1MuGMTReadoutCollection.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutRecord.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GtPsbWord.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/HLTReco/interface/TriggerTypeDefs.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
//jpt
#include "DataFormats/JetReco/interface/JPTJetCollection.h"
#include "DataFormats/JetReco/interface/JPTJet.h"
//pf
#include "DataFormats/JetReco/interface/PFJetCollection.h"
#include "DataFormats/JetReco/interface/PFJet.h"
//vtx
// not sure if all that includes are needed .....
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "RecoVertex/VertexPrimitives/interface/TransientVertex.h" 
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "TTree.h"

//electron
//electron
#include "DataFormats/GsfTrackReco/interface/GsfTrack.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "DataFormats/EgammaReco/interface/ElectronSeed.h"
#include "DataFormats/EgammaReco/interface/ElectronSeedFwd.h"
#include "DataFormats/EgammaReco/interface/BasicCluster.h"
#include "DataFormats/EgammaReco/interface/BasicClusterFwd.h"
#include "DataFormats/PatCandidates/interface/Electron.h"

//HFelectron
#include "DataFormats/EgammaReco/interface/HFEMClusterShape.h"
#include "DataFormats/EgammaReco/interface/HFEMClusterShapeAssociation.h"
#include "RecoEgamma/EgammaHFProducers/plugins/HFRecoEcalCandidateProducer.h"
#include "RecoEgamma/EgammaHFProducers/interface/HFRecoEcalCandidateAlgo.h"
#include "DataFormats/EgammaReco/interface/HFEMClusterShapeFwd.h"
#include "RecoEgamma/EgammaHFProducers/plugins/HFEMClusterProducer.h"
#include "DataFormats/RecoCandidate/interface/RecoEcalCandidate.h"
#include "DataFormats/RecoCandidate/interface/RecoEcalCandidateFwd.h"
#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/EgammaReco/interface/SuperClusterFwd.h"

#include "DataFormats/EgammaReco/interface/BasicCluster.h"
#include "DataFormats/EgammaReco/interface/BasicClusterFwd.h"
#include <map>
#include "DataFormats/Common/interface/AssociationMap.h"


class TH1F;
class TH2F;
class TStyle;
class TTree;

//
// class decleration
//

using namespace edm;
using namespace reco;
using namespace std;
using namespace ROOT::Math::VectorUtil;
using namespace HepMC;


class AFB : public edm::EDAnalyzer {
public:
  explicit AFB(const edm::ParameterSet&);
  ~AFB();

  const edm::ValueMap<double>& getValueMap(const edm::Event& iEvent,edm::InputTag& inputTag);
      
  //void produce(const edm::Handle<SuperClusterCollection>& SuperClusters,
  //				      const HFEMClusterShapeAssociationCollection& AssocShapes,
  //	     RecoEcalCandidateCollection& RecoECand);


private:
  //  virtual void beginJob(const edm::EventSetup&) ;
  virtual void beginJob();	
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  bool IsMuMatchedToHLTMu ( const reco::Muon & , std::vector<reco::Particle> ,double ,double );





  // ----------member data ---------------------------

  float DeltaPhi(float phi1, float phi2);
  float DeltaR(float eta1, float eta2, float phi1, float phi2);
  edm::InputTag muonTag_;
  string CaloJetAlg;
  edm::InputTag  JPTAlg, JPTAlgL2L3;
  edm::InputTag trigTag_, triggerSummaryLabel_, hltTag_, hltTag2_, hltTag3_, hltTag4_, hltTag5_;
  string muonTrig_;
  string L3FilterName_, L3FilterName2_, L3FilterName3_, L3FilterName4_, L3FilterName5_;
  edm::Service<TFileService> fs;
  TTree * myTree;
  int event, run,lumi,bxnumber,realdata;
  int hlt_trigger_fired;
  int sort_index_for_mu_tree;
  float RecMuonPt[50], RecMuonEta[50], RecMuonPhi[50],RecMuonPx[50], RecMuonPy[50], RecMuonPz[50], RecMuonE[50], RecMuonM[50], RecMuonGlobalType[50], RecMuonTrackerType[50], RecMuonStandAloneType[50], RecMuonIsoSumPt[50],RecMuonIsoRelative[50], RecMuonIsoCalComb[50], RecMuonIsoDY[50], RecMuonglmuon_dxy[50], RecMuonglmuon_dz[50], RecMuonglmuon_normalizedChi2[50],RecMuonVx[50],RecMuonVy[50],RecMuonVz[50];
  int RecMuonglmuon_trackerHits[50],RecMuontkmuon_pixelhits[50],RecMuonglmuon_muonHits[50],RecNumberOfUsedStations[50],hltmatchedmuon[50],hltmatched_Dimuon[50];//,hltmatchedmuon2[50];

  float RecElec_Pt[50], RecElec_Px[50], RecElec_Py[50],RecElec_Pz[50],RecElec_eta[50],RecElec_phi[50],RecElec_GsfTrk_d0[50],RecElec_dr03TkSumPt[50],RecElec_dr03EcalRecHitSumEt[50],RecElec_dr03HcalTowerSumEt[50],RecElec_scSigmaIEtaIEta[50],RecElec_deltaPhiSuperClusterTrackAtVtx[50],RecElec_deltaEtaSuperClusterTrackAtVtx[50],RecElec_hadronicOverEm[50],RecElec_gsfTrack_numberOfLostHits[50];
  int recelec_index,RecElec_Charge[50],RecElec_IsEB[50], RecElec_IsEE[50]; 

  //particle information
  int par_index, mom[50], daug[50];
  float ParticlePt[50], ParticleEta[50], ParticlePhi[50], ParticlePx[50], ParticlePy[50], ParticlePz[50], ParticleE[50], ParticleM[50];
  int ParticleId[50], ParticleStatus[50], ParticleMother[50][10], ParticleDaughter[50][10];
  int id_tmp[20];
  // int id_muon[20];
  int RecMuonglmuon_charge[50];
  //reco jets 
  int reco_jet;
  //int jpt_c,cjpt_c
  int pfNjets,pfNtracks;
  float RecJetPt[50], RecJetEta[50], RecJetPhi[50], RecJetPx[50], RecJetPy[50], RecJetPz[50], RecJetE[50];
  float RecCorrJetPt[50];
  float JetEMF[50],JetN90[50],JetFHPD[50],JetFRBX[50];
  float JPTPt[50], JPTEta[50], JPTPhi[50], JPTPx[50], JPTPy[50], JPTPz[50], JPTE[50];
  float cJPTPt[50], cJPTEta[50], cJPTPhi[50], cJPTPx[50], cJPTPy[50], cJPTPz[50], cJPTE[50];
  float PFjetEta[30], PFjetPhi[30],PFjetPt[30],PFCorrjetPt[30],PFjetCEMF[30],PFjetNEMF[30];
  float PFjetTrkVZ[50][30],PFjetTrkPT[50][30];
  float vtxZ[50],vtxZerr[50];
  float vtxY[50],vtxYerr[50];
  float vtxX[50],vtxXerr[50];
  int vtxisValid[50],vtxisFake[50];
  int nVertices,nGoodVertices; 
  int techTrigger[44];
  //met 
  float caloMET, caloSET, pfMET, pfSET;
  float caloMETX, pfMETX;
  float caloMETY, pfMETY;
  float muCorrMET, muCorrSET;



  reco::helper::JetIDHelper *jetID;

};



AFB::AFB(const edm::ParameterSet& iConfig)
{   
  muonTag_ = iConfig.getParameter<edm::InputTag>("muonTag");
  CaloJetAlg = iConfig.getParameter<string>("CaloJetAlg");
//  JPTAlg = iConfig.getParameter<edm::InputTag>("JPTjets");
  trigTag_ = iConfig.getParameter<edm::InputTag>("trigTag");
  jetID = new reco::helper::JetIDHelper(iConfig.getParameter<ParameterSet>("JetIDParams"));
  triggerSummaryLabel_ = iConfig.getParameter<edm::InputTag>("triggerSummaryLabel");
  hltTag_ = iConfig.getParameter<edm::InputTag>("hltTag");
  hltTag2_ = iConfig.getParameter<edm::InputTag>("hltTag2");
  hltTag3_ = iConfig.getParameter<edm::InputTag>("hltTag3");
  hltTag4_ = iConfig.getParameter<edm::InputTag>("hltTag4");
  hltTag5_ = iConfig.getParameter<edm::InputTag>("hltTag5");

  L3FilterName_ = iConfig.getParameter<std::string>("L3FilterName");  
  L3FilterName2_ = iConfig.getParameter<std::string>("L3FilterName2");  
  L3FilterName3_ = iConfig.getParameter<std::string>("L3FilterName3");  
  L3FilterName4_ = iConfig.getParameter<std::string>("L3FilterName4");  
  L3FilterName5_ = iConfig.getParameter<std::string>("L3FilterName5");  

}

AFB::~AFB()
{
}


// ------------ method called to for each event  ------------
void
AFB::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  bool singleTrigFlag1 = false;
  bool singleTrigFlag2 = false;
  bool doubleTrigFlag1 = false;
  bool doubleTrigFlag2 = false;

  Handle<GenParticleCollection> genParticles_h;
  iEvent.getByLabel("genParticles", genParticles_h);
  const GenParticleCollection* genParticles  = genParticles_h.failedToGet () ? 0 : &*genParticles_h;

  Handle<MuonCollection> muons;
  iEvent.getByLabel(muonTag_,muons);

  Handle<CaloJetCollection> caloJets;
  iEvent.getByLabel(CaloJetAlg,caloJets);
  CaloJetCollection::const_iterator c_jet;
  //  const JetCorrector* jCorrector = JetCorrector::getJetCorrector("L2L3JetCorrectorAK5Calo",iSetup);
  const JetCorrector* jCorrector = JetCorrector::getJetCorrector("ak5CaloL2L3",iSetup);
  const JetCorrector* PFjCorrector = JetCorrector::getJetCorrector("ak5PFL2L3",iSetup);

/*
  Handle<JPTJetCollection> jptJets;
  iEvent.getByLabel(JPTAlg,jptJets);
*/
  /*
    Handle<JPTJetCollection> corjptJets;
    iEvent.getByLabel(JPTAlgL2L3,corjptJets);
  */
 
  Handle< edm::View<reco::CaloMET> > caloMEThandle;
  iEvent.getByLabel("met", caloMEThandle); 

  Handle< edm::View<reco::PFMET> > pfMEThandle;
  iEvent.getByLabel("pfMet", pfMEThandle); 

  Handle< edm::View<reco::CaloMET> > muCorrMEThandle;
  iEvent.getByLabel("corMetGlobalMuons", muCorrMEThandle); 

  Handle<PFJetCollection> PFjets;
  iEvent.getByLabel("ak5PFJets","",PFjets);
  PFJetCollection::const_iterator i_jet;
   
  //Electrons
  edm::Handle<reco::GsfElectronCollection> elecs_h;	
  iEvent.getByLabel("gsfElectrons",elecs_h);
  //iEvent.getByLabel("electronCollection_",elecs_h);
  const GsfElectronCollection* elec = elecs_h.failedToGet() ? 0 : &*elecs_h;

  //HF electrons
  edm::Handle<reco::RecoEcalCandidateCollection> hfelecs_h;	
  iEvent.getByLabel("hfRecoEcalCandidate",hfelecs_h);
  const RecoEcalCandidateCollection* hfelec = hfelecs_h.failedToGet() ? 0 : &*hfelecs_h;

  Handle<SuperClusterCollection> SCH_h;
  iEvent.getByLabel("hfEMClusters",SCH_h);
  const SuperClusterCollection* SCH = SCH_h.failedToGet() ? 0 : &*SCH_h; //???
  Handle<HFEMClusterShapeAssociationCollection> ASH_h;
  iEvent.getByLabel("hfEMClusters",ASH_h);
  const HFEMClusterShapeAssociationCollection* ASH = ASH_h.failedToGet() ? 0 : &*ASH_h;//??

  

  Handle<BeamSpot> beamSpotHandle;
  if (!iEvent.getByLabel(InputTag("offlineBeamSpot"), beamSpotHandle)) {
    cout<< ">>> No beam spot found !!!" <<endl;
    return;
  }
  
  Handle<VertexCollection> pvHandle;
  iEvent.getByLabel("offlinePrimaryVertices", pvHandle);  

  nVertices = pvHandle->size(); 

  const VertexCollection vertexColl = *(pvHandle.product());

  nGoodVertices = 0;
  for (VertexCollection::const_iterator vtx = vertexColl.begin(); vtx!= vertexColl.end(); ++vtx){
       if (vtx->isValid() && !vtx->isFake()) ++nGoodVertices;
  }

  //  if (nVertices != nGoodVertices) cout<<"@@@@@@@@@@@@@   ------> "<<nVertices<<"  "<<nGoodVertices<<endl;

  reco::VertexCollection vtxs = *pvHandle;
  for (int iv = 0;iv<nVertices;iv++){
    vtxX[iv] = vtxs[iv].x();
    vtxY[iv] = vtxs[iv].y();
    vtxZ[iv] = vtxs[iv].z();
    vtxXerr[iv] = vtxs[iv].xError();
    vtxYerr[iv] = vtxs[iv].yError();
    vtxZerr[iv] = vtxs[iv].zError();
    vtxisValid[iv] = vtxs[iv].isValid();
    vtxisFake[iv] = vtxs[iv].isFake();
  }

  Handle< L1GlobalTriggerReadoutRecord > gtRecord;
  iEvent.getByLabel( "gtDigis", gtRecord);
  const TechnicalTriggerWord tWord = gtRecord->technicalTriggerWord();

  Handle<TriggerResults> triggerResults;
  if (!iEvent.getByLabel(trigTag_, triggerResults)){
    cout<<" Hoooop"<<endl;
    LogError("") << ">>> TRIGGER collection does not exist !!!";
  };
//  const edm::TriggerNames & triggerNames = iEvent.triggerNames(*triggerResults);
//  int hlt_trigger_fired = 0;
  //  int itrig1 = triggerNames.triggerIndex(muonTrig_);
  //  if (triggerResults->accept(itrig1)) hlt_trigger_fired = 1;


  for (int ee = 0;ee<44;ee++){ 
    techTrigger[ee] = tWord.at(ee);
  }

  event = iEvent.id().event();
  run = iEvent.id().run();
  lumi = iEvent.luminosityBlock();
  bxnumber = iEvent.bunchCrossing();
  realdata = iEvent.isRealData();

  //---------------------For trigger matching-----------------------------------
  
  Handle<trigger::TriggerEvent> triggerObj;
  iEvent.getByLabel(triggerSummaryLabel_,triggerObj); 
  const trigger::TriggerObjectCollection & toc(triggerObj->getObjects());
  size_t nMuHLT =0;
  std::vector<reco::Particle>  HLTMuMatched; 
  //for dimuons
  size_t nDiMuHLT =0;
  std::vector<reco::Particle>  HLTDiMuMatched; 
  //--end of for dimuons
  for ( size_t ia = 0; ia < triggerObj->sizeFilters(); ++ ia) {
    std::string fullname = triggerObj->filterTag(ia).encode();
    //   cout<<"full name:   "<<fullname<<endl;	
    std::string name;
    size_t p = fullname.find_first_of(':');
    if ( p != std::string::npos) {
      name = fullname.substr(0, p);
    }
    else {
      name = fullname;
    }
    if ( &toc !=0 ) {
      const trigger::Keys & k = triggerObj->filterKeys(ia);
      for (trigger::Keys::const_iterator ki = k.begin(); ki !=k.end(); ++ki ) {
	//	if (name == L3FilterName_  ) { 
	if ( (run <= 147195 && name == L3FilterName_) || (run >=147196 && run <148108 && name == L3FilterName2_) || ( run >=148108 && name == L3FilterName3_) ) { 
	  cout<<name << "=?" << L3FilterName_<<"  "<<L3FilterName2_<<"   "<<L3FilterName3_<<endl;
	  HLTMuMatched.push_back(toc[*ki].particle());
	  nMuHLT++;     
	}
	if ( (run < 147196 && name == L3FilterName4_) || (run >= 147196 && name == L3FilterName5_)){
	  cout<<name << "=?" << L3FilterName4_<<"  "<<L3FilterName5_<<endl;
	  HLTDiMuMatched.push_back(toc[*ki].particle());
	  nDiMuHLT++;	  
	}
      }    
    }
  }

  //----------------------------------------------------------------------------


  //--------------------met-------------------------------------------------
  caloMET = (caloMEThandle->front()).et();
  caloSET = (caloMEThandle->front()).sumEt();
  pfMET = (pfMEThandle->front()).et();
  pfSET = (pfMEThandle->front()).sumEt(); 

  caloMETX = (caloMEThandle->front()).px();
  caloMETY = (caloMEThandle->front()).py();

  pfMETX = (pfMEThandle->front()).px();
  pfMETY = (pfMEThandle->front()).py();

  muCorrMET      = (muCorrMEThandle->front()).et();
  muCorrSET      = (muCorrMEThandle->front()).sumEt(); 
  //------------------------------------------------------------------------

  par_index = 0;
  for (int i=0;i<50;i++){
    ParticlePt[i] = -999; 
    ParticleEta[i] = -999; 
    ParticlePhi[i] = -999; 
    ParticlePx[i] = -999; 
    ParticlePy[i] = -999;
    ParticlePz[i] = -999; 
    ParticleE[i] = -999;
    ParticleM[i] = -999;
    ParticleId[i] = -999; 
    ParticleStatus[i] = -999; 
    for (int j=0;j<10;j++){
      ParticleMother[i][j] = -999; 
      ParticleDaughter[i][j] = -999;
    }
  }

  //--------------------particles-------------------------------------------
  
  if (!realdata && genParticles){	
    par_index = 0;
    for (size_t i=0; i<genParticles->size(); ++i){
      //const GenParticle & p = (*genParticles)[i];
      const Candidate & p = (*genParticles)[i];
      int id = p.pdgId();
      int st = p.status();
      if (st!=3) continue;
      ParticlePt[par_index] = p.pt();
      ParticleEta[par_index] = p.eta();
      ParticlePhi[par_index] = p.phi();
      ParticlePx[par_index] = p.px();
      ParticlePy[par_index] = p.py();
      ParticlePz[par_index] = p.pz();
      ParticleE[par_index] =p.energy();
      ParticleM[par_index] =p.mass();
      ParticleId[par_index] = id;
      ParticleStatus[par_index] = st;
      //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

      //cout<<i+1<<"  "<<st<<"  "<<id<<"   "<<endl;
      mom[par_index] = p.numberOfMothers();
      for (uint d=0; d<p.numberOfMothers(); d++) {
        // cout << " mother id: " << p.mother(d)->pdgId() << "   ";
	//         mom = d;
	ParticleMother[par_index][d] = p.mother(d)->pdgId();
      }     
      daug[par_index] = p.numberOfDaughters();
      for (uint d=0; d<p.numberOfDaughters(); d++) {
	if (p.daughter(d)->status() == 3){ 
          //  cout << " daughter id: " << p.daughter(d)->pdgId() << "   ";
	  //            daug = d;
	  ParticleDaughter[par_index][d] = p.daughter(d)->pdgId();
	}
      }
      //     cout<<" "<<endl;
      //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
      ++par_index;
      //    cout<< p.pdgId() << "    "<< p.mass() << ",  "<< p.status() << endl;
      //    cout<<i<<"  "<<st<<"  "<<id<<"   "<<p.eta()<<"    "<<p.mass()<<endl;
    }   
  }

  //------------------------------------------------------------------------

  //--------------------------MUONS---------------------------------------------------------------------------------------------------------------------
   
  int reco_muon = 0;
  float rec_eta_muon[50] = {};
  float rec_phi_muon[50] = {};
  float rec_pt_muon[50] = {};
  float rec_px_muon[50] = {};
  float rec_py_muon[50] = {};
  float rec_pz_muon[50] = {};
  float rec_vx_muon[50] = {};
  float rec_vy_muon[50] = {};
  float rec_vz_muon[50] = {};
  float rec_e_muon[50] = {};
  float rec_m_muon[50] = {};
  int rec_n_used_sta[50] = {};
  float rec_typeGlobal_muon[50] = {};
  float rec_typeTracker_muon[50] = {};
  float rec_typeStandAlone_muon[50] = {};
  float rec_iso_sumpt[50] = {};
  float rec_iso_relative[50] = {};
  float rec_iso_CalComb[50] = {};
  float rec_iso_DY[50] = {};
  float glmuon_dxy[50] = {};
  float glmuon_dz[50] = {};
  float glmuon_normalizedChi2[50] = {};
  int glmuon_trackerHits[50] = {};
  int tkmuon_pixelhits[50] = {};
  int glmuon_muonHits[50] = {};
  int glmuon_charge[50] = {};
  int hlt_tmp[50] = {};
  // int hlt_tmp2[50] = {};
  int hlt_tmp_dimuon[50] = {};
  // int hlt_tmp_dimuon2[50] = {};  
  for (int gg = 0;gg<50;gg++){
    rec_eta_muon[gg] = 0;
    rec_phi_muon[gg] = 0;
    rec_pt_muon[gg] = 0;
    rec_px_muon[gg] = 0;
    rec_py_muon[gg] = 0;
    rec_pz_muon[gg] = 0;
    rec_vx_muon[gg] = 0;
    rec_vy_muon[gg] = 0;
    rec_vz_muon[gg] = 0;
    rec_e_muon[gg] = 0;
    rec_m_muon[gg] = 0;
    rec_n_used_sta[gg] = 0;
    rec_typeGlobal_muon[gg] = 0;
    rec_typeTracker_muon[gg] = 0;
    rec_typeStandAlone_muon[gg] = 0;
    rec_iso_sumpt[gg] = 0;
    rec_iso_relative[gg] = 0;
    rec_iso_CalComb[gg] = 0;
    rec_iso_DY[gg] = 0;
    glmuon_dxy[gg] = 0;
    glmuon_dz[gg] = 0;
    glmuon_normalizedChi2[gg] = 0;
    glmuon_trackerHits[gg] = 0;
    tkmuon_pixelhits[gg] = 0;
    glmuon_muonHits[gg] = 0;
    glmuon_charge[gg] = 0;
    hlt_tmp[gg] = 0;
    //   hlt_tmp2[gg] = 0;    
  }
  MuonCollection::const_iterator muon;
  std::vector<reco::Muon>  highPtGlbMuons; 
  for (unsigned int i=0; i<muons->size(); i++ ){	
    const reco::Muon & mu = muons->at(i);
    //    if (mu.isGlobalMuon()) highPtGlbMuons.push_back(mu);
    if (mu.isGlobalMuon() && mu.isTrackerMuon()){
      highPtGlbMuons.push_back(mu);
      rec_typeGlobal_muon[reco_muon] = mu.isGlobalMuon();
      rec_typeTracker_muon[reco_muon] = mu.isTrackerMuon();
      if (mu.isStandAloneMuon()) rec_typeStandAlone_muon[reco_muon] = mu.isStandAloneMuon();
      reco::TrackRef glmuon = mu.globalTrack();//OK
      reco::TrackRef tkmuon = mu.innerTrack();//OK 
      glmuon_dxy[reco_muon] = glmuon->dxy(beamSpotHandle->position());//OK
      glmuon_dz[reco_muon] = glmuon->dz(beamSpotHandle->position());//probably OK but not used anyway. 
      glmuon_normalizedChi2[reco_muon] = glmuon->normalizedChi2();//OK
      glmuon_trackerHits[reco_muon] = tkmuon->hitPattern().numberOfValidTrackerHits();//OK
      tkmuon_pixelhits[reco_muon] = tkmuon->hitPattern().numberOfValidPixelHits();//OK 
      glmuon_muonHits[reco_muon] = glmuon->hitPattern().numberOfValidMuonHits();//OK
      glmuon_charge[reco_muon] = glmuon->charge();
      rec_eta_muon[reco_muon] = mu.eta();
      rec_phi_muon[reco_muon] = mu.phi();
      rec_pt_muon[reco_muon] = mu.pt();
      rec_px_muon[reco_muon] = mu.px();
      rec_py_muon[reco_muon] = mu.py();
      rec_pz_muon[reco_muon] = mu.pz();
      rec_vx_muon[reco_muon] = mu.vx();
      rec_vy_muon[reco_muon] = mu.vy();
      rec_vz_muon[reco_muon] = mu.vz();
      rec_e_muon[reco_muon] = mu.energy();
      rec_m_muon[reco_muon] = mu.mass();
      rec_n_used_sta[reco_muon] = mu.numberOfMatches();
      //      id_tmp[reco_muon] = muon::isGoodMuon(*muon,muon::GlobalMuonPromptTight);//id
      rec_iso_sumpt[reco_muon] = mu.isolationR03().sumPt;
      rec_iso_relative[reco_muon] = rec_iso_sumpt[reco_muon]/mu.pt();//OK
      rec_iso_CalComb[reco_muon] = mu.isolationR03().emEt + mu.isolationR03().hadEt;
      rec_iso_DY[reco_muon] = (rec_iso_sumpt[reco_muon] + mu.isolationR03().hadEt)/mu.pt();
      /*   
      reco::Muon muon1 = highPtGlbMuons[i];//PROBLEM IS HERE!!!!!!!!!!!!!!!!!!!!!!!
      math::XYZTLorentzVector mu1(muon1.p4());
      singleTrigFlag1 = IsMuMatchedToHLTMu ( muon1,  HLTMuMatched , 0.2, 1.0 );
      hlt_tmp[reco_muon] = int(singleTrigFlag1); 
      */
      ++reco_muon;
    }
  }

  //==============================================================
  unsigned int nHighPtGlbMu = highPtGlbMuons.size();
  if (nHighPtGlbMu > 0){
    /*
    for(unsigned int i =0 ; i < nHighPtGlbMu ; i++) {
      reco::Muon muon1 = highPtGlbMuons[i];
      singleTrigFlag1 = IsMuMatchedToHLTMu ( muon1,  HLTMuMatched , 0.2, 1.0 );
      hlt_tmp[i] = int(singleTrigFlag1); 
    }
    */
    if (nHighPtGlbMu>1 ){
      for(unsigned int i =0 ; i < nHighPtGlbMu ; i++) {
	reco::Muon muon1 = highPtGlbMuons[i];
	for (unsigned int j =i+1; j <nHighPtGlbMu ; ++j ){
	  reco::Muon muon2 = highPtGlbMuons[j];
	  if (muon1.charge() == muon2.charge()) continue; 
	  if (nMuHLT){
	    singleTrigFlag1 = IsMuMatchedToHLTMu ( muon1,  HLTMuMatched , 0.2, 1.0 );
	    singleTrigFlag2 = IsMuMatchedToHLTMu ( muon2,  HLTMuMatched , 0.2, 1.0 );
	    hlt_tmp[i] = int(singleTrigFlag1); 
	    hlt_tmp[j] = int(singleTrigFlag2); 
	    //	    cout<<"SINGLE   i,j    hlt tmp1,2 :    "<< i<<"   "<<j<<"  "<<hlt_tmp[i] <<"   "<< hlt_tmp[j]<<endl;
	  }
	  if (nDiMuHLT){
	    doubleTrigFlag1 = IsMuMatchedToHLTMu ( muon1,  HLTDiMuMatched , 0.2, 1.0 );
	    doubleTrigFlag2 = IsMuMatchedToHLTMu ( muon2,  HLTDiMuMatched , 0.2, 1.0 );
	    hlt_tmp_dimuon[i] = int(doubleTrigFlag1); 
	    hlt_tmp_dimuon[j] = int(doubleTrigFlag2); 	  
	    //	    cout<<"DOUBLE   i,j    hlt tmp dimuon 1,2 :    "<< i<<"   "<<j<<"  "<<hlt_tmp_dimuon1[i] <<"   "<< hlt_tmp_dimuon2[j]<<endl;
	  }
	} 
      }   
    }
    for(unsigned int i =0 ; i < nHighPtGlbMu ; i++){
      if (nMuHLT) cout<<"SINGLE   hlt tmp:    "<< i<<"   "<<hlt_tmp[i] <<endl;
    }
    for(unsigned int i =0 ; i < nHighPtGlbMu ; i++){
      if (nDiMuHLT) cout<<"DOUBLE   hlt tmp:    "<< i<<"   "<<hlt_tmp_dimuon[i] <<endl;
    }
  }
  //==============================================================

  //   cout<<"Number of Muons:    "<<muons->size()<<endl;
  /*
  //----old one---------
  for(muon = muons->begin(); muon != muons->end(); ++muon){
    if (muon->isGlobalMuon())  rec_typeGlobal_muon[reco_muon] = muon->isGlobalMuon();
    if (muon->isTrackerMuon()) rec_typeTracker_muon[reco_muon] = muon->isTrackerMuon();
    if (muon->isStandAloneMuon()) rec_typeStandAlone_muon[reco_muon] = muon->isStandAloneMuon();
    if (muon->isGlobalMuon() && muon->isTrackerMuon()){
      reco::TrackRef glmuon = muon->globalTrack();//OK
      reco::TrackRef tkmuon = muon->innerTrack();//OK 
      glmuon_dxy[reco_muon] = glmuon->dxy(beamSpotHandle->position());//OK
      glmuon_dz[reco_muon] = glmuon->dz(beamSpotHandle->position());//probably OK but not used anyway. 
      glmuon_normalizedChi2[reco_muon] = glmuon->normalizedChi2();//OK
      glmuon_trackerHits[reco_muon] = tkmuon->hitPattern().numberOfValidTrackerHits();//OK
      tkmuon_pixelhits[reco_muon] = tkmuon->hitPattern().numberOfValidPixelHits();//OK 
      glmuon_muonHits[reco_muon] = glmuon->hitPattern().numberOfValidMuonHits();//OK
      glmuon_charge[reco_muon] = glmuon->charge();
      rec_eta_muon[reco_muon] = muon->eta();
      rec_phi_muon[reco_muon] = muon->phi();
      rec_pt_muon[reco_muon] = muon->pt();
      rec_px_muon[reco_muon] = muon->px();
      rec_py_muon[reco_muon] = muon->py();
      rec_pz_muon[reco_muon] = muon->pz();
      rec_e_muon[reco_muon] = muon->energy();
      rec_m_muon[reco_muon] = muon->mass();
      rec_n_used_sta[reco_muon] = muon->numberOfMatches();
      id_tmp[reco_muon] = muon::isGoodMuon(*muon,muon::GlobalMuonPromptTight);//id
      rec_iso_sumpt[reco_muon] = muon->isolationR03().sumPt;
      rec_iso_relative[reco_muon] = rec_iso_sumpt[reco_muon]/muon->pt();//OK
      rec_iso_CalComb[reco_muon] = muon->isolationR03().emEt + muon->isolationR03().hadEt;   
      ++reco_muon;
    }
  }
  */
  //-------------

  for (int mm=0;mm<reco_muon;++mm){
    RecMuonPt[mm] = 0;
    RecMuonEta[mm] = 0; 
    RecMuonPhi[mm] = 0;
    RecMuonPx[mm] = 0;
    RecMuonPy[mm] = 0;
    RecMuonPz[mm] = 0;
    RecMuonVx[mm] = 0;
    RecMuonVy[mm] = 0;
    RecMuonVz[mm] = 0;
    RecMuonE[mm] = 0;
    RecMuonM[mm] = 0;
    RecMuonGlobalType[mm] = 0;
    RecMuonStandAloneType[mm] = 0;
    RecMuonTrackerType[mm] = 0;
    RecMuonIsoSumPt[mm] = 0;
    RecNumberOfUsedStations[mm] = 0;
    RecMuonIsoRelative[mm] = 0;
    RecMuonIsoCalComb[mm] = 0;
    RecMuonIsoDY[mm] = 0;
    RecMuonglmuon_dxy[mm] = 0;
    RecMuonglmuon_dz[mm] = 0;
    RecMuonglmuon_normalizedChi2[mm] = 0;
    RecMuonglmuon_trackerHits[mm] = 0;	
    RecMuontkmuon_pixelhits[mm] = 0;
    RecMuonglmuon_muonHits[mm] = 0;
    RecMuonglmuon_charge[mm] = 0;
    //   id_muon[mm] = 0;
  }

  int sorted_muon_index[10]={};
  int sort_reco_muon = 0;
  sort_index_for_mu_tree = 0;
  TMath::Sort(reco_muon,rec_pt_muon,sorted_muon_index);
  for (int i=0;i<reco_muon;++i){ 
    sort_reco_muon = sorted_muon_index[sort_index_for_mu_tree];
    RecMuonPt[sort_index_for_mu_tree]  = rec_pt_muon[sort_reco_muon];
    RecMuonEta[sort_index_for_mu_tree] = rec_eta_muon[sort_reco_muon];
    RecMuonPhi[sort_index_for_mu_tree] = rec_phi_muon[sort_reco_muon];
    RecMuonPx[sort_index_for_mu_tree]  = rec_px_muon[sort_reco_muon];
    RecMuonPy[sort_index_for_mu_tree]  = rec_py_muon[sort_reco_muon];
    RecMuonPz[sort_index_for_mu_tree]  = rec_pz_muon[sort_reco_muon];
    RecMuonVx[sort_index_for_mu_tree] = rec_vx_muon[sort_reco_muon]; 
    RecMuonVy[sort_index_for_mu_tree] = rec_vy_muon[sort_reco_muon]; 
    RecMuonVz[sort_index_for_mu_tree] = rec_vz_muon[sort_reco_muon]; 
    RecMuonE[sort_index_for_mu_tree]   = rec_e_muon[sort_reco_muon];
    RecMuonM[sort_index_for_mu_tree]   = rec_m_muon[sort_reco_muon]; 
    RecMuonGlobalType[sort_index_for_mu_tree] = rec_typeGlobal_muon[sort_reco_muon]; 
    RecMuonTrackerType[sort_index_for_mu_tree] = rec_typeTracker_muon[sort_reco_muon]; 
    RecMuonStandAloneType[sort_index_for_mu_tree] = rec_typeStandAlone_muon[sort_reco_muon]; 
    RecMuonIsoSumPt[sort_index_for_mu_tree] = rec_iso_sumpt[sort_reco_muon]; 
    RecNumberOfUsedStations[sort_index_for_mu_tree] = rec_n_used_sta[sort_reco_muon];
    RecMuonIsoRelative[sort_index_for_mu_tree] = rec_iso_relative[reco_muon];
    RecMuonIsoCalComb[sort_index_for_mu_tree] = rec_iso_CalComb[sort_reco_muon]; 
    RecMuonIsoDY[sort_index_for_mu_tree] = rec_iso_DY[sort_reco_muon];
    RecMuonglmuon_dxy[sort_index_for_mu_tree] = glmuon_dxy[sort_reco_muon];
    RecMuonglmuon_dz[sort_index_for_mu_tree] = glmuon_dz[sort_reco_muon];
    RecMuonglmuon_normalizedChi2[sort_index_for_mu_tree] = glmuon_normalizedChi2[sort_reco_muon];
    RecMuonglmuon_trackerHits[sort_index_for_mu_tree] = glmuon_trackerHits[sort_reco_muon];
    RecMuontkmuon_pixelhits[sort_index_for_mu_tree] = tkmuon_pixelhits[sort_reco_muon];
    RecMuonglmuon_muonHits[sort_index_for_mu_tree] =  glmuon_muonHits[sort_reco_muon];
    RecMuonglmuon_charge[sort_index_for_mu_tree] = glmuon_charge[sort_reco_muon];
    hltmatchedmuon[sort_index_for_mu_tree] = hlt_tmp[sort_reco_muon];
    hltmatched_Dimuon[sort_index_for_mu_tree] = hlt_tmp_dimuon[sort_reco_muon];
    //    hltmatchedmuon2[sort_index_for_mu_tree] = hlt_tmp2[sort_reco_muon];
    cout<<"INDEX AND MATCHED MUONS IN THE TREE and pt(SINGLE):    "<<sort_index_for_mu_tree<<"   "<<hltmatchedmuon[sort_index_for_mu_tree]<<"   "<<RecMuonPt[sort_index_for_mu_tree]<<endl;
     cout<<"INDEX AND MATCHED MUONS IN THE TREE and pt (DOUBLE):    "<<sort_index_for_mu_tree<<"   "<<hltmatched_Dimuon[sort_index_for_mu_tree]<<"   "<<RecMuonPt[sort_index_for_mu_tree]<<endl;
   
    /*
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"Written pt:    "<<RecMuonPt[sort_index_for_mu_tree]<<endl;
    cout<<"matched ?:     "<<hltmatchedmuon[sort_index_for_mu_tree]<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;    
    */
   //   id_muon[sort_index_for_mu_tree] = id_tmp[sort_reco_muon];
    ++sort_index_for_mu_tree;
  }
   
  //-----------------------END MUONS--------------------------------------------------------------------------------------------------------------------

//--------------------------ELECTRONS-----------------------------------------------------------------------------------------------------------------
  for (int jj = 0; jj<50; ++jj){
    RecElec_Pt[jj] = -99.;
    RecElec_Px[jj] = -99.;
    RecElec_Py[jj] = -99.;
    RecElec_Pz[jj] = -99.;
    RecElec_eta[jj] = -99.;
    RecElec_phi[jj] = -99.;
    RecElec_Charge[jj] = -99.;
    RecElec_GsfTrk_d0[jj] = -99.;
    RecElec_IsEB[jj] = -99.;
    RecElec_IsEE[jj] = -99.;
    RecElec_dr03TkSumPt[jj] = -99.;
    RecElec_dr03EcalRecHitSumEt[jj] = -99.;
    RecElec_dr03HcalTowerSumEt[jj] = -99.;
    RecElec_scSigmaIEtaIEta[jj] = -99.;
    RecElec_deltaPhiSuperClusterTrackAtVtx[jj] = -99.;
    RecElec_deltaEtaSuperClusterTrackAtVtx[jj] = -99.;
    RecElec_hadronicOverEm[jj] = -99.;
    RecElec_gsfTrack_numberOfLostHits[jj] = -99.;

  }
  recelec_index = 0;
  for(GsfElectronCollection::const_iterator el = elec->begin(); el != elec->end();  ++el) {
	RecElec_Pt[recelec_index] = el->pt();
        RecElec_Px[recelec_index] = el->px();
	RecElec_Py[recelec_index] = el->py();
	RecElec_Pz[recelec_index] = el->pz();
	RecElec_eta[recelec_index] = el->eta();
	RecElec_phi[recelec_index] = el->phi();	
	RecElec_Charge[recelec_index] = el->charge();
	RecElec_GsfTrk_d0[recelec_index] = el->gsfTrack()->d0();
	RecElec_IsEB[recelec_index] = el->isEB();
	RecElec_IsEE[recelec_index] = el->isEE();
	RecElec_dr03TkSumPt[recelec_index] = el->dr03TkSumPt();
	RecElec_dr03EcalRecHitSumEt[recelec_index] = el->dr03EcalRecHitSumEt();
	RecElec_dr03HcalTowerSumEt[recelec_index] = el->dr03HcalTowerSumEt();
	RecElec_scSigmaIEtaIEta[recelec_index] = el->scSigmaIEtaIEta();
	RecElec_deltaPhiSuperClusterTrackAtVtx[recelec_index] = el->deltaPhiSuperClusterTrackAtVtx();
	RecElec_deltaEtaSuperClusterTrackAtVtx[recelec_index] = el->deltaEtaSuperClusterTrackAtVtx();
	RecElec_hadronicOverEm[recelec_index] = el->hadronicOverEm();
	RecElec_gsfTrack_numberOfLostHits[recelec_index] = el->gsfTrack()->numberOfLostHits();
        ++recelec_index; 
  }

    for(reco::RecoEcalCandidateCollection::const_iterator hfe = hfelec->begin(); hfe != hfelec->end();  ++hfe){
      //          cout<<hfe->et()<<"  "<<hfe->px()<<"  "<<hfe->py()<<"  "<<hfe->pz()<<"  "<<hfe->energy()<<endl;
    }


//--------------------------END ELECTRONS-----------------------------------------------------------------------------------------------------------------



  //-----------------------RECO JETS--------------------------------------------------------------------------------------------------------------------
  reco_jet = 0;
  for( CaloJetCollection::const_iterator jet = caloJets->begin(); jet != caloJets->end(); ++ jet ) {
    const math::XYZTLorentzVector theJet = jet->p4();
    RecJetPt[reco_jet] = jet->pt();
    RecCorrJetPt[reco_jet] = jCorrector->correction(theJet)*jet->pt();
    RecJetEta[reco_jet] = jet->eta();
    RecJetPhi[reco_jet] = jet->phi();
    RecJetPx[reco_jet] = jet->px();
    RecJetPy[reco_jet] = jet->py();
    RecJetPz[reco_jet] = jet->pz();
    RecJetE[reco_jet] = jet->energy();
    JetEMF[reco_jet] = jet->emEnergyFraction();

    jetID->calculate(iEvent,*jet);
    JetN90[reco_jet] = jetID->n90Hits();
    JetFHPD[reco_jet] = jetID->fHPD();
    JetFRBX[reco_jet] = jetID->fRBX();

    ++reco_jet;
  }

  //-----------------------END RECOJETS-----------------------------------------------------------------------------------------------------------------

  //----------------------JPT JETS-----------------------------------------------------------------------------------------------------------------
/*
  jpt_c = 0;   
  for (int i=0;i<50;i++){
    JPTPt[i] = -9999;
    JPTEta[i] = -9999;
    JPTPhi[i] = -9999;
    JPTPx[i] = -9999;
    JPTPy[i] = -9999;
    JPTPz[i] = -9999;
    JPTE[i] = -9999;
    cJPTPt[i] = -9999;
    cJPTEta[i] = -9999;
    cJPTPhi[i] = -9999;
    cJPTPx[i] = -9999;
    cJPTPy[i] = -9999;
    cJPTPz[i] = -9999;
    cJPTE[i] = -9999;
  }
  for( JPTJetCollection::const_iterator jjet = jptJets->begin(); jjet != jptJets->end(); ++ jjet ) {
    JPTPt[jpt_c] = jjet->pt();
    JPTEta[jpt_c] = jjet->eta();
    JPTPhi[jpt_c] = jjet->phi();
    JPTPx[jpt_c] = jjet->px();
    JPTPy[jpt_c] = jjet->py();
    JPTPz[jpt_c] = jjet->pz();
    JPTE[jpt_c] = jjet->energy();
    ++jpt_c;
  }
*/
  /*
    cjpt_c = 0;
    for( CaloJetCollection::const_iterator cjjet = corjptJets->begin(); cjjet != corjptJets->end(); ++ cjjet ) {//L2L3 corr JPT
    cJPTPt[cjpt_c] = cjjet->pt();
    cJPTEta[cjpt_c] = cjjet->eta();
    cJPTPhi[cjpt_c] = cjjet->phi();
    cJPTPx[cjpt_c] = cjjet->px();
    cJPTPy[cjpt_c] = cjjet->py();
    cJPTPz[cjpt_c] = cjjet->pz();
    cJPTE[cjpt_c] = cjjet->energy();
    ++cjpt_c;
    }
  */


  //----------------------END JPT JETS-----------------------------------------------------------------------------------------------------------------



  int NJets = 20;
  //----------------------------PF jets-------------------------------------------------------------------------------------
  for (int kkk = 0;kkk<50;kkk++){
    for (int jjj = 0;jjj<30;jjj++){
	PFjetTrkVZ[kkk][jjj] = -99;
	PFjetTrkPT[kkk][jjj] = -99;
    }
  }
  pfNjets=0;
  for(i_jet = PFjets->begin(); i_jet != PFjets->end() && pfNjets < NJets; i_jet++){
    const math::XYZTLorentzVector theJet = i_jet->p4();
    PFjetEta[pfNjets]=i_jet->eta();
    PFjetPhi[pfNjets]=i_jet->phi();
    PFjetPt[pfNjets]=i_jet->pt();
    PFCorrjetPt[pfNjets] = PFjCorrector->correction(theJet)*i_jet->pt();
    PFjetCEMF[pfNjets]=i_jet->chargedEmEnergyFraction();
    PFjetNEMF[pfNjets]=i_jet->neutralEmEnergyFraction();
    //         cout<<PFjetEta[pfNjets]<<"  "<<PFjetPt[pfNjets]<<"  "<<PFCorrjetPt[pfNjets]<<endl;
    // ---- This accesses to the vertex Z of the track-base constituents of pfjets
    pfNtracks=0;
    const reco::TrackRefVector &tracks = i_jet->getTrackRefs();
    for (reco::TrackRefVector::const_iterator iTrack = tracks.begin();iTrack != tracks.end(); ++iTrack) {
          PFjetTrkVZ[pfNjets][pfNtracks] = (**iTrack).vz();
          PFjetTrkPT[pfNjets][pfNtracks] = (**iTrack).pt();
          pfNtracks++;
    }
    pfNjets++;
  }
  //-----------------------------end of pf jets--------------------------------------------------------------------------

  // cout<<"clusShape.e9e25()    "<<clusShape.e9e25()<<"  "<<"clusShape.eCOREe9()    "<<clusShape.eCOREe9()<<"  "<<"(clusShape.eSeL()   "<<(clusShape.eSeL()<<endl;

  myTree->Fill();//!!!!!!

}


// ------------ method called once each job just before starting event loop  ------------
//void AFB::beginJob(const edm::EventSetup&)
void AFB::beginJob()
{
  TFileDirectory TestDir = fs->mkdir("test");
  myTree = new TTree("MuonTree","MuonTree");
  myTree->Branch("event", &event, "event/I");
  myTree->Branch("run", &run, "run/I");
  myTree->Branch("lumi", &lumi, "lumi/I");
  myTree->Branch("bxnumber", &bxnumber, "bxnumber/I");
  myTree->Branch("realdata", &realdata, "realdata/I");

  //muon
  myTree->Branch("hlt_trigger_fired",&hlt_trigger_fired,"hlt_trigger_fired/I");
  myTree->Branch("sort_index_for_mu_tree",&sort_index_for_mu_tree,"sort_index_for_mu_tree/I");
  myTree->Branch("RecMuonPt",RecMuonPt,"RecMuonPt[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonEta",RecMuonEta,"RecMuonEta[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonPhi",RecMuonPhi,"RecMuonPhi[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonPx",RecMuonPx,"RecMuonPx[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonPy",RecMuonPy,"RecMuonPy[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonPz",RecMuonPz,"RecMuonPz[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonVx",RecMuonVx,"RecMuonVx[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonVy",RecMuonVy,"RecMuonVy[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonVz",RecMuonVz,"RecMuonVz[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonE",RecMuonE,"RecMuonE[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonM",RecMuonM,"RecMuonM[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonGlobalType",RecMuonGlobalType,"RecMuonGlobalType[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonTrackerType",RecMuonTrackerType,"RecMuonTrackerType[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonStandAloneType",RecMuonStandAloneType,"RecMuonStandAloneType[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonIsoSumPt",RecMuonIsoSumPt,"RecMuonIsoSumPt[sort_index_for_mu_tree]/F");
  myTree->Branch("RecNumberOfUsedStations",RecNumberOfUsedStations,"RecNumberOfUsedStations[sort_index_for_mu_tree]/I");
  myTree->Branch("RecMuonIsoRelative",RecMuonIsoRelative,"RecMuonIsoRelative[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonIsoCalComb",RecMuonIsoCalComb,"RecMuonIsoCalComb[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonIsoDY",RecMuonIsoDY,"RecMuonIsoDY[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonglmuon_dxy",RecMuonglmuon_dxy,"RecMuonglmuon_dxy[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonglmuon_dz",RecMuonglmuon_dz,"RecMuonglmuon_dz[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonglmuon_normalizedChi2",RecMuonglmuon_normalizedChi2,"RecMuonglmuon_normalizedChi2[sort_index_for_mu_tree]/F");
  myTree->Branch("RecMuonglmuon_trackerHits",RecMuonglmuon_trackerHits,"RecMuonglmuon_trackerHits[sort_index_for_mu_tree]/I");
  myTree->Branch("RecMuontkmuon_pixelhits",RecMuontkmuon_pixelhits,"RecMuontkmuon_pixelhits[sort_index_for_mu_tree]/I");
  myTree->Branch("RecMuonglmuon_muonHits",RecMuonglmuon_muonHits,"RecMuonglmuon_muonHits[sort_index_for_mu_tree]/I");
  
  myTree->Branch("RecMuonglmuon_charge",RecMuonglmuon_charge,"RecMuonglmuon_charge[sort_index_for_mu_tree]/I");
  myTree->Branch("hltmatchedmuon",hltmatchedmuon,"hltmatchedmuon[sort_index_for_mu_tree]/I");
  myTree->Branch("hltmatched_Dimuon",hltmatched_Dimuon,"hltmatched_Dimuon[sort_index_for_mu_tree]/I");
  //  myTree->Branch("hltmatchedmuon2",hltmatchedmuon2,"hltmatchedmuon2[sort_index_for_mu_tree]/I");

  myTree->Branch("recelec_index",&recelec_index,"recelec_index/I");
  myTree->Branch("RecElec_Pt",RecElec_Pt,"RecElec_Pt[recelec_index]/F");
  myTree->Branch("RecElec_Px",RecElec_Px,"RecElec_Px[recelec_index]/F");
  myTree->Branch("RecElec_Py",RecElec_Py,"RecElec_Py[recelec_index]/F");
  myTree->Branch("RecElec_Pz",RecElec_Pz,"RecElec_Pz[recelec_index]/F");
  myTree->Branch("RecElec_eta",RecElec_eta,"RecElec_eta[recelec_index]/F");
  myTree->Branch("RecElec_phi",RecElec_phi,"RecElec_phi[recelec_index]/F");
  myTree->Branch("RecElec_Charge",RecElec_Charge,"RecElec_Charge[recelec_index]/I");
  myTree->Branch("RecElec_GsfTrk_d0",RecElec_GsfTrk_d0,"RecElec_GsfTrk_d0[recelec_index]/F");
  myTree->Branch("RecElec_IsEB",RecElec_IsEB,"RecElec_IsEB[recelec_index]/I");
  myTree->Branch("RecElec_IsEE",RecElec_IsEE,"RecElec_IsEE[recelec_index]/I");
  myTree->Branch("RecElec_dr03TkSumPt",RecElec_dr03TkSumPt,"RecElec_dr03TkSumPt[recelec_index]/F");
  myTree->Branch("RecElec_dr03EcalRecHitSumEt",RecElec_dr03EcalRecHitSumEt,"RecElec_dr03EcalRecHitSumEt[recelec_index]/F");
  myTree->Branch("RecElec_dr03HcalTowerSumEt",RecElec_dr03HcalTowerSumEt,"RecElec_dr03HcalTowerSumEt[recelec_index]/F");
  myTree->Branch("RecElec_scSigmaIEtaIEta",RecElec_scSigmaIEtaIEta,"RecElec_scSigmaIEtaIEta[recelec_index]/F");
  myTree->Branch("RecElec_deltaPhiSuperClusterTrackAtVtx",RecElec_deltaPhiSuperClusterTrackAtVtx,"RecElec_deltaPhiSuperClusterTrackAtVtx[recelec_index]/F");
  myTree->Branch("RecElec_deltaEtaSuperClusterTrackAtVtx",RecElec_deltaEtaSuperClusterTrackAtVtx,"RecElec_deltaEtaSuperClusterTrackAtVtx[recelec_index]/F");
  myTree->Branch("RecElec_hadronicOverEm",RecElec_hadronicOverEm,"RecElec_hadronicOverEm[recelec_index]/F");
  myTree->Branch("RecElec_gsfTrack_numberOfLostHits",RecElec_gsfTrack_numberOfLostHits,"RecElec_gsfTrack_numberOfLostHits[recelec_index]/F");



  // myTree->Branch("id_muon",id_muon,"id_muon[sort_index_for_mu_tree]/I");
  myTree->Branch("techTrigger",techTrigger, "techTrigger[44]/I");

  //particles
  
  myTree->Branch("par_index", &par_index, "par_index/I");
  myTree->Branch("ParticlePt", ParticlePt, "ParticlePt[par_index]/F");
  myTree->Branch("ParticleEta", ParticleEta, "ParticleEta[par_index]/F");
  myTree->Branch("ParticlePhi", ParticlePhi, "ParticlePhi[par_index]/F");
  myTree->Branch("ParticlePx", ParticlePx, "ParticlePx[par_index]/F");
  myTree->Branch("ParticlePy", ParticlePy, "ParticlePy[par_index]/F");
  myTree->Branch("ParticlePz", ParticlePz, "ParticlePz[par_index]/F");
  myTree->Branch("ParticleE", ParticleE, "ParticleE[par_index]/F");
  myTree->Branch("ParticleM", ParticleM, "ParticleM[par_index]/F");  
  myTree->Branch("ParticleId", ParticleId, "ParticleId[par_index]/I");
  myTree->Branch("mom", mom, "mom[par_index]/I");
  myTree->Branch("daug", daug, "daug[par_index]/I");
  myTree->Branch("ParticleStatus", ParticleStatus, "ParticleStatus[par_index]/I");
  myTree->Branch("ParticleMother", ParticleMother, "ParticleMother[par_index][5]/I");
  myTree->Branch("ParticleDaughter", ParticleDaughter, "ParticleDaughter[par_index][5]/I");
  
  //recojets
  myTree->Branch("reco_jet",&reco_jet,"reco_jet/I");

  myTree->Branch("RecCorrJetPt",RecCorrJetPt,"RecCorrJetPt[reco_jet]/F");
  myTree->Branch("JetEMF",JetEMF,"JetEMF[reco_jet]/F");
  myTree->Branch("JetN90",JetN90,"JetN90[reco_jet]/F");
  myTree->Branch("JetFHPD",JetFHPD,"JetFHPD[reco_jet]/F");
  myTree->Branch("JetFRBX",JetFRBX,"JetFRBX[reco_jet]/F");

  myTree->Branch("RecJetPt",RecJetPt,"RecJetPt[reco_jet]/F");
  myTree->Branch("RecJetEta",RecJetEta,"RecJetEta[reco_jet]/F");
  myTree->Branch("RecJetPhi",RecJetPhi,"RecJetPhi[reco_jet]/F");
  myTree->Branch("RecJetPx",RecJetPx,"RecJetPx[reco_jet]/F");
  myTree->Branch("RecJetPy",RecJetPy,"RecJetPy[reco_jet]/F");
  myTree->Branch("RecJetPz",RecJetPz,"RecJetPz[reco_jet]/F");
  myTree->Branch("RecJetE",RecJetE,"RecJetE[reco_jet]/F");
  myTree->Branch("caloMET", &caloMET, "caloMET/F");
  myTree->Branch("caloSET", &caloSET, "caloSET/F");
  myTree->Branch("pfMET", &pfMET, "pfMET/F");
  myTree->Branch("pfSET", &pfSET, "pfSET/F"); 
  myTree->Branch("caloMETX", &caloMETX, "caloMETX/F");
  myTree->Branch("pfMETX", &pfMETX, "pfMETX/F");
  myTree->Branch("caloMETY", &caloMETY, "caloMETY/F");
  myTree->Branch("pfMETY", &pfMETY, "pfMETY/F");
  myTree->Branch("muCorrMET", &muCorrMET, "muCorrMET/F");
  myTree->Branch("muCorrSET", &muCorrSET, "muCorrSET/F");	

/*
  myTree->Branch("jpt_c",&jpt_c,"jpt_c/I");
  myTree->Branch("JPTPt",JPTPt,"JPTPt[jpt_c]/F");
  myTree->Branch("JPTEta",JPTEta,"JPTEta[jpt_c]/F");
  myTree->Branch("JPTPhi",JPTPhi,"JPTPhi[jpt_c]/F");
  myTree->Branch("JPTPx",JPTPx,"JPTPx[jpt_c]/F");
  myTree->Branch("JPTPy",JPTPy,"JPTPy[jpt_c]/F");
  myTree->Branch("JPTPz",JPTPz,"JPTPz[jpt_c]/F");
  myTree->Branch("JPTE",JPTE,"JPTE[jpt_c]/F");
*/
  /*
    myTree->Branch("cjpt_c",&cjpt_c,"cjpt_c/I");
    myTree->Branch("cJPTPt",cJPTPt,"cJPTPt[cjpt_c]/F");
    myTree->Branch("cJPTEta",cJPTEta,"cJPTEta[cjpt_c]/F");
    myTree->Branch("cJPTPhi",cJPTPhi,"cJPTPhi[cjpt_c]/F");
    myTree->Branch("cJPTPx",cJPTPx,"cJPTPx[cjpt_c]/F");
    myTree->Branch("cJPTPy",cJPTPy,"cJPTPy[cjpt_c]/F");
    myTree->Branch("cJPTPz",cJPTPz,"cJPTPz[cjpt_c]/F");
    myTree->Branch("cJPTE",cJPTE,"cJPTE[cjpt_c]/F");
  */

  myTree->Branch("pfNjets",&pfNjets,"pfNjets/I");
  myTree->Branch("PFjetEta",PFjetEta,"PFjetEta[pfNjets]/F");
  myTree->Branch("PFjetPhi",PFjetPhi,"PFjetPhi[pfNjets]/F");
  myTree->Branch("PFjetPt",PFjetPt,"PFjetPt[pfNjets]/F");
  myTree->Branch("PFCorrjetPt",PFCorrjetPt,"PFCorrjetPt[pfNjets]/F");
  myTree->Branch("PFjetCEMF",PFjetCEMF,"PFjetCEMF[pfNjets]/F");
  myTree->Branch("PFjetNEMF",PFjetNEMF,"PFjetNEMF[pfNjets]/F");

  myTree->Branch("pfNtracks",&pfNtracks,"pfNtracks/I");
  myTree->Branch("PFjetTrkVZ",PFjetTrkVZ,"PFjetTrkVZ[pfNjets][30]/F");
  myTree->Branch("PFjetTrkPT",PFjetTrkPT,"PFjetTrkPT[pfNjets][30]/F");
	

  myTree->Branch("nVertices",&nVertices,"nVertices/I");
  myTree->Branch("nGoodVertices",&nGoodVertices,"nGoodVertices/I");
  myTree->Branch("vtxX",vtxX,"vtxX[nVertices]/F");
  myTree->Branch("vtxY",vtxY,"vtxY[nVertices]/F");
  myTree->Branch("vtxZ",vtxZ,"vtxZ[nVertices]/F");
  myTree->Branch("vtxXerr",vtxXerr,"vtxXerr[nVertices]/F");
  myTree->Branch("vtxYerr",vtxYerr,"vtxYerr[nVertices]/F");
  myTree->Branch("vtxZerr",vtxZerr,"vtxZerr[nVertices]/F");
  myTree->Branch("vtxisValid",vtxisValid,"vtxisValid[nVertices]/I");
  myTree->Branch("vtxisFake",vtxisFake,"vtxisFake[nVertices]/I");

}

// ------------ method called once each job just after ending the event loop  ------------
void 
AFB::endJob() {
  myTree->Print();//!!!
  //  f->Write();
  //  f->Close();
}




float AFB::DeltaPhi(float phi1, float phi2)
{
  float dphi = phi2 - phi1;
  if (fabs(dphi) > 3.14) dphi = 6.28 - fabs(dphi);
  return dphi;
}

float AFB::DeltaR(float eta1, float eta2, float phi1, float phi2)
{
  float deta = eta2 - eta1;
  float dphi = phi2 - phi1;
  if (fabs(dphi) > 3.14) dphi = 6.28 - fabs(dphi);
  float DELTAR = sqrt(pow(dphi,2)+pow(deta,2))*1.0;
  return DELTAR;
}


bool AFB::IsMuMatchedToHLTMu ( const reco::Muon & mu, std::vector<reco::Particle> HLTMu , double DR, double DPtRel ) {
  size_t dim =  HLTMu.size();
  size_t nPass=0;
  
  // filling the denumerator;
  double muRecoPt= mu.pt();
  //hTrigMuonPtDenS_-> Fill(muRecoPt);         
 
  if (dim==0) return false;
  for (size_t k =0; k< dim; k++ ) {
    if (  (deltaR(HLTMu[k], mu) < DR)   && (fabs(HLTMu[k].pt() - mu.pt())/ HLTMu[k].pt()<DPtRel)){     
      nPass++ ;
      std::cout<< " matching a muon " << std::endl;  
      std::cout  << "muon reco  pt : " << muRecoPt<< std::endl;     
      std::cout  << "muon reco  eta " <<  mu.eta() << std::endl;   
      std::cout << "muon trigger  pt "<< HLTMu[k].pt() << std::endl; 
      std::cout << "muon trigger  eta : "<< HLTMu[k].eta() << std::endl;   
      std::cout  <<"deltaR((HLTMu[k], mu)): "<< deltaR(HLTMu[k], mu) << std::endl;
      std::cout  <<"deltaPtOverPt: "<< fabs(HLTMu[k].pt() - mu.pt())/ HLTMu[k].pt() << std::endl;
    }
  }
  
  return (nPass>0);
}



//define this as a plug-in
DEFINE_FWK_MODULE(AFB);
