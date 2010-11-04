import FWCore.ParameterSet.Config as cms

import RecoJets.JetProducers.JetIDParams_cfi
theJetIDParams = RecoJets.JetProducers.JetIDParams_cfi.JetIDParams.clone()

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.load("JetMETCorrections.Configuration.DefaultJEC_cff")

#
#process.load("RecoJets.Configuration.RecoJPTJets_cff")
#
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
#'/store/data/Run2010A/Mu/RECO/Jun14thReReco_v1/0000/A2CCE8E1-A878-DF11-8F75-00237DA14F86.root'
#'/store/data/Run2010A/Mu/RECO/Jul16thReReco-v1/0049/7E1C8196-2691-DF11-8CE1-002618943925.root'
#'/store/data/Run2010A/Mu/RECO/v4/000/141/961/90CA5CBA-CF9B-DF11-A2D5-000423D9A212.root',
#        '/store/data/Run2010A/Mu/RECO/v4/000/141/961/8464C5BE-CF9B-DF11-8A93-0030487CBD0A.root',
'/store/data/Run2010B/Mu/RECO/PromptReco-v2/000/148/029/F45C8B32-62DA-DF11-B00D-001D09F282F5.root',
# '/store/data/Run2010B/Mu/AOD/PromptReco-v2/000/148/029/FC072AA6-65DA-DF11-B79C-001D09F253C0.root',

    )
)

process.load('Configuration/StandardSequences/MagneticField_38T_cff')
process.load('Configuration/StandardSequences/GeometryIdeal_cff')

process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
#process.GlobalTag.globaltag = 'GR10_P_V6::All' 
#process.GlobalTag.globaltag = 'GR_R_36X_V12B::All'
process.GlobalTag.globaltag = 'GR10_P_V10::All'

process.load("RecoMuon.MuonIsolationProducers.muIsolation_cff")
process.load("Configuration/StandardSequences/RawToDigi_Data_cff")


####################################################################################
process.noscraping = cms.EDFilter("FilterOutScraping",
                                applyfilter = cms.untracked.bool(True),                                 
				debugOn = cms.untracked.bool(True),
                                numtrack = cms.untracked.uint32(10),
                                thresh = cms.untracked.double(0.25)                                 
)

#####PV filter
process.oneGoodVertexFilter = cms.EDFilter("VertexSelector",
   src = cms.InputTag("offlinePrimaryVertices"), 
   cut = cms.string("!isFake && ndof > 4 && abs(z) <= 24 && position.Rho <= 2"),    
   filter = cms.bool(True),   # otherwise it won't filter the events, just produce an empty vertex collection.
)
###################################################################################

process.mu9_HLT = cms.EDFilter("HLTHighLevel",
     TriggerResultsTag = cms.InputTag("TriggerResults","","HLT"),
     HLTPaths = cms.vstring('HLT_Mu9'),   # provide list of HLT paths (or patterns) you want
     eventSetupPathsKey = cms.string(''), # not empty => use read paths from AlCaRecoTriggerBitsRcd via this key
     andOr = cms.bool(True),              # how to deal with multiple triggers: True (OR) accept if ANY is true, False (AND) accept if ALL are true
     throw = cms.bool(True)    # throw exception on unknown path names
 ) 

process.demo = cms.EDAnalyzer("AFB",
			      muonTag    = cms.InputTag("muons"),
#                              CaloJetAlg = cms.string("iterativeCone5CaloJets"),
                              CaloJetAlg = cms.string("ak5CaloJets"),
##
#                              JPTjets = cms.InputTag("JetPlusTrackZSPCorJetAntiKt5"),
#                              JPTAlgL2L3 = cms.string("ak5JPTJetsL2L3"),    
##
                              trigTag = cms.InputTag("TriggerResults::HLT"),
                              triggerSummaryLabel = cms.InputTag("hltTriggerSummaryAOD","","HLT"),
                              hltTag = cms.InputTag("HLT_Mu9","","HLT"),
                              L3FilterName = cms.string("hltSingleMu9L3Filtered9"),
#                              muonTrig = cms.string("HLT_L2Mu9"),
                              JetIDParams = theJetIDParams
)

process.TFileService = cms.Service("TFileService",
#---------------------------------------------------------------------------------------------
fileName = cms.string('newmuons.root')
#---------------------------------------------------------------------------------------------
         
)

#process.p = cms.Path(process.mu9_HLT*process.noscraping*process.oneGoodVertexFilter*process.recoJPTJets*process.ak5JPTJetsL2L3*process.demo)
#process.p = cms.Path(process.mu9_HLT*process.noscraping*process.recoJPTJets*process.ak5JPTJetsL2L3*process.demo)
process.p = cms.Path(process.mu9_HLT*process.demo)

#process.p = cms.Path(process.demo)
