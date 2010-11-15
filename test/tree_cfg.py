import FWCore.ParameterSet.Config as cms

import RecoJets.JetProducers.JetIDParams_cfi
theJetIDParams = RecoJets.JetProducers.JetIDParams_cfi.JetIDParams.clone()

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.load("JetMETCorrections.Configuration.DefaultJEC_cff")

#
#process.load("RecoJets.Configuration.RecoJPTJets_cff")
#
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
#'/store/data/Run2010A/Mu/RECO/Jun14thReReco_v1/0000/A2CCE8E1-A878-DF11-8F75-00237DA14F86.root'
#'/store/data/Run2010A/Mu/RECO/Jul16thReReco-v1/0049/7E1C8196-2691-DF11-8CE1-002618943925.root'
#'/store/data/Run2010A/Mu/RECO/v4/000/141/961/90CA5CBA-CF9B-DF11-A2D5-000423D9A212.root',
#        '/store/data/Run2010A/Mu/RECO/v4/000/141/961/8464C5BE-CF9B-DF11-8A93-0030487CBD0A.root',
'/store/data/Run2010B/Mu/RECO/PromptReco-v2/000/148/029/F45C8B32-62DA-DF11-B00D-001D09F282F5.root',
# '/store/data/Run2010B/Mu/AOD/PromptReco-v2/000/148/029/FC072AA6-65DA-DF11-B79C-001D09F253C0.root',
#        '/store/data/Run2010B/Electron/RECO/PromptReco-v2/000/148/029/F88601B1-6CDA-DF11-BC5C-0030487A3C9A.root',
#'/store/data/Run2010B/Electron/RECO/PromptReco-v2/000/149/711/12D053B9-8DE7-DF11-8390-000423D94E70.root',
#        '/store/data/Run2010B/Electron/RECO/PromptReco-v2/000/149/709/4AB36C1C-92E7-DF11-B15F-001D09F29533.root',
#        '/store/data/Run2010B/Electron/RECO/PromptReco-v2/000/149/510/4CD61E3F-2FE7-DF11-B26A-003048F024F6.root',
#        '/store/data/Run2010B/Electron/RECO/PromptReco-v2/000/149/509/D4648853-1DE7-DF11-9904-0030487CD840.root',
#        '/store/data/Run2010B/Electron/RECO/PromptReco-v2/000/149/461/BA45E47C-B3E6-DF11-ABAE-003048F024DE.root',
#        '/store/data/Run2010B/Electron/RECO/PromptReco-v2/000/149/459/2CBA8799-99E6-DF11-A7CD-0030487C7E18.root',
#        '/store/data/Run2010B/Electron/RECO/PromptReco-v2/000/149/446/1A1521D7-6AE6-DF11-95C8-0030487CD840.root',
#        '/store/data/Run2010B/Electron/RECO/PromptReco-v2/000/149/442/D40D99D9-42E6-DF11-B429-0030487CD77E.root',
#        '/store/data/Run2010B/Electron/RECO/PromptReco-v2/000/149/442/D0C10A9A-51E6-DF11-9821-0030487CD7C6.root',
#        '/store/data/Run2010B/Electron/RECO/PromptReco-v2/000/149/442/A05625F6-52E6-DF11-AD7F-0030487C7828.root',
#        '/store/data/Run2010B/Electron/RECO/PromptReco-v2/000/149/442/9E477415-55E6-DF11-B6C2-0030487CD7CA.root',
#        '/store/data/Run2010B/Electron/RECO/PromptReco-v2/000/149/442/9CFD7152-57E6-DF11-9626-0030487C778E.root',
#        '/store/data/Run2010B/Electron/RECO/PromptReco-v2/000/149/442/8448E1F5-52E6-DF11-8CBD-0030487CAEAC.root',

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

process.mu_HLT = cms.EDFilter("HLTHighLevel",
     TriggerResultsTag = cms.InputTag("TriggerResults","","HLT"),
     HLTPaths = cms.vstring('HLT_Mu9','HLT_Mu11','HLT_Mu15_v1'),   # provide list of HLT paths (or patterns) you want
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
#                              hltTag2 = cms.InputTag("HLT_Mu11","","HLT"),
                              hltTag3 = cms.InputTag("HLT_Mu15_v1","","HLT"),
                              L3FilterName = cms.string("hltSingleMu9L3Filtered9"),
#                              L3FilterName2 = cms.string("hltSingleMu11L3Filtered11"),
                              L3FilterName3 = cms.string("hltSingleMu15L3Filtered15"),
#                              muonTrig = cms.string("HLT_L2Mu9"),
                              JetIDParams = theJetIDParams
)

process.TFileService = cms.Service("TFileService",
#---------------------------------------------------------------------------------------------
fileName = cms.string('newmuons.root')
#---------------------------------------------------------------------------------------------
         
)

#process.p = cms.Path(process.mu_HLT*process.noscraping*process.oneGoodVertexFilter*process.recoJPTJets*process.ak5JPTJetsL2L3*process.demo)
#process.p = cms.Path(process.mu_HLT*process.noscraping*process.recoJPTJets*process.ak5JPTJetsL2L3*process.demo)
process.p = cms.Path(process.mu_HLT*process.demo)

#process.p = cms.Path(process.demo)
