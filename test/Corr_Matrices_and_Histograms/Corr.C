

{
//========= Macro generated from object: h_RFF_Normalized/
//========= by ROOT version5.22/00d

  TFile *theFile = new TFile("corr_out.root","RECREATE");
  theFile->cd();

  int nb = 11;
   Double_t xAxis1[12] = {40, 50, 60, 76, 86, 91, 96, 106, 120, 150, 200, 600}; 
   Double_t yAxis1[12] = {40, 50, 60, 76, 86, 91, 96, 106, 120, 150, 200, 600}; 

 TH1F *h_AFB_Obs = new TH1F("h_AFB_Obs","h_AFB_Obs",nb,xAxis1 );
  h_AFB_Obs->Sumw2();
  TH1F *h_AFB_Obs_Tmp1 = new TH1F("h_AFB_Obs_Tmp1","h_AFB_Obs_Tmp1",nb,xAxis1 );
  h_AFB_Obs_Tmp1->Sumw2();
  TH1F *h_AFB_Obs_Tmp2 = new TH1F("h_AFB_Obs_Tmp2","h_AFB_Obs_Tmp2",nb,xAxis1 );
  h_AFB_Obs_Tmp2->Sumw2();

  TH1F *h_AFB_Unfolded = new TH1F("h_AFB_Unfolded","h_AFB_Unfolded",nb,xAxis1 );
  h_AFB_Unfolded->Sumw2();
  TH1F *h_AFB_Unfolded_Tmp1 = new TH1F("h_AFB_Unfolded_Tmp1","h_AFB_Unfolded_Tmp1",nb,xAxis1 );
  h_AFB_Unfolded_Tmp1->Sumw2();
  TH1F *h_AFB_Unfolded_Tmp2 = new TH1F("h_AFB_Unfolded_Tmp2","h_AFB_Unfolded_Tmp2",nb,xAxis1 );
  h_AFB_Unfolded_Tmp2->Sumw2();

  TH1F *h_AFB_Unfolded_and_Acceptance_Corrected = new TH1F("h_AFB_Unfolded_and_Acceptance_Corrected"," h_AFB_Unfolded_and_Acceptance_Corrected",nb,xAxis1 );
  h_AFB_Unfolded_and_Acceptance_Corrected->Sumw2();


  TH1F *h_Unfolded_F = new TH1F("h_Unfolded_F", "Unfolded_F", nb,xAxis1 );
   h_Unfolded_F->Sumw2(); 
  TH1F *h_Unfolded_B = new TH1F("h_Unfolded_B", "Unfolded_B", nb,xAxis1 );
   h_Unfolded_B->Sumw2(); 
  TH1F *h_Unfolded_and_AcceptanceCorrected_F = new TH1F("h_Unfolded_and_AcceptanceCorrected_F","h_Unfolded_and_AcceptanceCorrected_F",nb,xAxis1);
  h_Unfolded_and_AcceptanceCorrected_F->Sumw2();
  TH1F *h_Unfolded_and_AcceptanceCorrected_B = new TH1F("h_Unfolded_and_AcceptanceCorrected_B","h_Unfolded_and_AcceptanceCorrected_B",nb,xAxis1);
  h_Unfolded_and_AcceptanceCorrected_B->Sumw2();
  TH1F *h_Unfolded_and_AcceptanceCorrected_Total = new TH1F("h_Unfolded_and_AcceptanceCorrected_Total","h_Unfolded_and_AcceptanceCorrected_Total",nb,xAxis1);
  h_Unfolded_and_AcceptanceCorrected_Total->Sumw2();
 TH1F *h_Unfolded_and_AcceptanceCorrected_Total_Tmp1 = new TH1F("h_Unfolded_and_AcceptanceCorrected_Total_Tmp1","h_Unfolded_and_AcceptanceCorrected_Total_Tmp1",nb,xAxis1);
  h_Unfolded_and_AcceptanceCorrected_Total_Tmp1->Sumw2(); 
  TH1F *h_Unfolded_and_AcceptanceCorrected_Total_Tmp2 = new TH1F("h_Unfolded_and_AcceptanceCorrected_Total_Tmp2","h_Unfolded_and_AcceptanceCorrected_Total_Tmp2",nb,xAxis1);
  h_Unfolded_and_AcceptanceCorrected_Total_Tmp2->Sumw2(); 

  TH2F *h_correlation = new TH2F("h_correlation","h_correlation",nb,xAxis1,nb,xAxis1);

  TH1F *h_full_corrected = new TH1F("h_full_corrected","h_full_corrected",nb,xAxis1);
  h_full_corrected->Sumw2();
  TH1F *h_full_corrected_2nd_method = new TH1F("h_full_corrected_2nd_method","h_full_corrected_2nd_method",nb,xAxis1);
  h_full_corrected->Sumw2();
 
   TH1 *h_RFF_Normalized = new TH2F("h_RFF_Normalized","",nb, xAxis1,nb, yAxis1);
   h_RFF_Normalized->SetBinContent(14,0.9047195);
   h_RFF_Normalized->SetBinContent(15,0.03817734);
   h_RFF_Normalized->SetBinContent(16,0.0006855576);
   h_RFF_Normalized->SetBinContent(17,0.0005652911);
   h_RFF_Normalized->SetBinContent(18,0.000143747);
   h_RFF_Normalized->SetBinContent(19,0.0002980552);
   h_RFF_Normalized->SetBinContent(20,0.0001563966);
   h_RFF_Normalized->SetBinContent(27,0.02582369);
   h_RFF_Normalized->SetBinContent(28,0.8226601);
   h_RFF_Normalized->SetBinContent(29,0.02353748);
   h_RFF_Normalized->SetBinContent(30,0.001884304);
   h_RFF_Normalized->SetBinContent(31,0.001389554);
   h_RFF_Normalized->SetBinContent(32,0.00131641);
   h_RFF_Normalized->SetBinContent(33,0.0006255865);
   h_RFF_Normalized->SetBinContent(34,0.0006793478);
   h_RFF_Normalized->SetBinContent(35,0.001094092);
   h_RFF_Normalized->SetBinContent(41,0.02216749);
   h_RFF_Normalized->SetBinContent(42,0.51851);
   h_RFF_Normalized->SetBinContent(43,0.03382325);
   h_RFF_Normalized->SetBinContent(44,0.01878294);
   h_RFF_Normalized->SetBinContent(45,0.0189265);
   h_RFF_Normalized->SetBinContent(46,0.008758211);
   h_RFF_Normalized->SetBinContent(47,0.005434783);
   h_RFF_Normalized->SetBinContent(48,0.001094092);
   h_RFF_Normalized->SetBinContent(55,0.01759598);
   h_RFF_Normalized->SetBinContent(56,0.4381948);
   h_RFF_Normalized->SetBinContent(57,0.08720652);
   h_RFF_Normalized->SetBinContent(58,0.04957651);
   h_RFF_Normalized->SetBinContent(59,0.01782922);
   h_RFF_Normalized->SetBinContent(60,0.008831521);
   h_RFF_Normalized->SetBinContent(61,0.007658643);
   h_RFF_Normalized->SetBinContent(69,0.04371585);
   h_RFF_Normalized->SetBinContent(70,0.6532822);
   h_RFF_Normalized->SetBinContent(71,0.3417948);
   h_RFF_Normalized->SetBinContent(72,0.02142634);
   h_RFF_Normalized->SetBinContent(73,0.00611413);
   h_RFF_Normalized->SetBinContent(74,0.002188184);
   h_RFF_Normalized->SetBinContent(82,9.421519e-05);
   h_RFF_Normalized->SetBinContent(83,0.1832295);
   h_RFF_Normalized->SetBinContent(84,0.7837113);
   h_RFF_Normalized->SetBinContent(85,0.1523303);
   h_RFF_Normalized->SetBinContent(86,0.01086957);
   h_RFF_Normalized->SetBinContent(87,0.004376368);
   h_RFF_Normalized->SetBinContent(96,0.001461428);
   h_RFF_Normalized->SetBinContent(97,0.03924393);
   h_RFF_Normalized->SetBinContent(98,0.7051924);
   h_RFF_Normalized->SetBinContent(99,0.1494565);
   h_RFF_Normalized->SetBinContent(100,0.01094092);
   h_RFF_Normalized->SetBinContent(101,0.005235602);
   h_RFF_Normalized->SetBinContent(110,2.483793e-05);
   h_RFF_Normalized->SetBinContent(111,0.02377229);
   h_RFF_Normalized->SetBinContent(112,0.8315217);
   h_RFF_Normalized->SetBinContent(113,0.09628009);
   h_RFF_Normalized->SetBinContent(114,0.002617801);
   h_RFF_Normalized->SetBinContent(115,0.01098901);
   h_RFF_Normalized->SetBinContent(125,0.02921196);
   h_RFF_Normalized->SetBinContent(126,0.9146608);
   h_RFF_Normalized->SetBinContent(127,0.08900524);
   h_RFF_Normalized->SetBinContent(139,0.02188184);
   h_RFF_Normalized->SetBinContent(140,0.8900524);
   h_RFF_Normalized->SetBinContent(141,0.1098901);
   h_RFF_Normalized->SetBinContent(153,0.03141361);
   h_RFF_Normalized->SetBinContent(154,0.9285714);

   TH1 *h_RFB_Normalized = new TH2F("h_RFB_Normalized","",nb, xAxis1,nb, yAxis1);
   h_RFB_Normalized->SetBinContent(14,0.002599653);
   h_RFB_Normalized->SetBinContent(15,0.0005652911);
   h_RFB_Normalized->SetBinContent(18,9.850276e-05);
   h_RFB_Normalized->SetBinContent(19,5.065856e-05);
   h_RFB_Normalized->SetBinContent(20,0.0001620483);
   h_RFB_Normalized->SetBinContent(28,0.003957038);
   h_RFB_Normalized->SetBinContent(29,0.001052632);
   h_RFB_Normalized->SetBinContent(30,9.34929e-05);
   h_RFB_Normalized->SetBinContent(31,0.0001477541);
   h_RFB_Normalized->SetBinContent(32,0.0002786221);
   h_RFB_Normalized->SetBinContent(33,0.0003240966);
   h_RFB_Normalized->SetBinContent(34,0.0008291874);
   h_RFB_Normalized->SetBinContent(42,0.001052632);
   h_RFB_Normalized->SetBinContent(43,0.0004674645);
   h_RFB_Normalized->SetBinContent(44,0.00108353);
   h_RFB_Normalized->SetBinContent(45,0.001266464);
   h_RFB_Normalized->SetBinContent(46,0.0009722898);
   h_RFB_Normalized->SetBinContent(48,0.001402525);
   h_RFB_Normalized->SetBinContent(55,0.0002105263);
   h_RFB_Normalized->SetBinContent(56,0.0003739716);
   h_RFB_Normalized->SetBinContent(57,0.001034279);
   h_RFB_Normalized->SetBinContent(58,0.001190476);
   h_RFB_Normalized->SetBinContent(59,0.0008102414);
   h_RFB_Normalized->SetBinContent(60,0.0008291874);
   h_RFB_Normalized->SetBinContent(61,0.002805049);
   h_RFB_Normalized->SetBinContent(69,0.0001869858);
   h_RFB_Normalized->SetBinContent(70,0.001108156);
   h_RFB_Normalized->SetBinContent(71,0.00139311);
   h_RFB_Normalized->SetBinContent(72,0.0004861449);
   h_RFB_Normalized->SetBinContent(83,0.000394011);
   h_RFB_Normalized->SetBinContent(84,0.001570415);
   h_RFB_Normalized->SetBinContent(85,0.001134338);
   h_RFB_Normalized->SetBinContent(97,5.065856e-05);
   h_RFB_Normalized->SetBinContent(98,0.001134338);
   h_RFB_Normalized->SetBinContent(99,0.0008291874);
   h_RFB_Normalized->SetBinContent(100,0.001402525);
   h_RFB_Normalized->SetBinContent(102,0.006060606);
   h_RFB_Normalized->SetBinContent(109,2.462569e-05);
   h_RFB_Normalized->SetBinContent(112,0.0008291874);
   h_RFB_Normalized->SetBinContent(113,0.001402525);
   h_RFB_Normalized->SetBinContent(126,0.005610098);
   h_RFB_Normalized->SetBinContent(127,0.007490637);
   h_RFB_Normalized->SetBinContent(140,0.007490637);
   h_RFB_Normalized->SetBinContent(154,0.006060606);

   TH1 *h_RBF_Normalized = new TH2F("h_RBF_Normalized","",nb, xAxis1,nb, yAxis1);
   h_RBF_Normalized->SetBinContent(14,0.001780944);
   h_RBF_Normalized->SetBinContent(15,0.001847291);
   h_RBF_Normalized->SetBinContent(16,0.0002285192);
   h_RBF_Normalized->SetBinContent(17,9.421519e-05);
   h_RBF_Normalized->SetBinContent(18,0.0001197892);
   h_RBF_Normalized->SetBinContent(19,4.967587e-05);
   h_RBF_Normalized->SetBinContent(24,0.005494506);
   h_RBF_Normalized->SetBinContent(29,0.0006855576);
   h_RBF_Normalized->SetBinContent(30,9.421519e-05);
   h_RBF_Normalized->SetBinContent(31,0.0001197892);
   h_RBF_Normalized->SetBinContent(32,0.0001987035);
   h_RBF_Normalized->SetBinContent(33,0.0001563966);
   h_RBF_Normalized->SetBinContent(34,0.0006793478);
   h_RBF_Normalized->SetBinContent(42,0.0006855576);
   h_RBF_Normalized->SetBinContent(43,0.001224797);
   h_RBF_Normalized->SetBinContent(44,0.000862482);
   h_RBF_Normalized->SetBinContent(45,0.001068031);
   h_RBF_Normalized->SetBinContent(46,0.0006255865);
   h_RBF_Normalized->SetBinContent(47,0.0006793478);
   h_RBF_Normalized->SetBinContent(48,0.001094092);
   h_RBF_Normalized->SetBinContent(56,0.001036367);
   h_RBF_Normalized->SetBinContent(57,0.001006229);
   h_RBF_Normalized->SetBinContent(58,0.001490276);
   h_RBF_Normalized->SetBinContent(59,0.0004691899);
   h_RBF_Normalized->SetBinContent(69,0.0002826456);
   h_RBF_Normalized->SetBinContent(70,0.001389554);
   h_RBF_Normalized->SetBinContent(71,0.0009190035);
   h_RBF_Normalized->SetBinContent(72,0.0001563966);
   h_RBF_Normalized->SetBinContent(83,0.0002635362);
   h_RBF_Normalized->SetBinContent(84,0.001217059);
   h_RBF_Normalized->SetBinContent(85,0.0006255865);
   h_RBF_Normalized->SetBinContent(86,0.0006793478);
   h_RBF_Normalized->SetBinContent(97,4.967587e-05);
   h_RBF_Normalized->SetBinContent(98,0.001251173);
   h_RBF_Normalized->SetBinContent(99,0.0006793478);
   h_RBF_Normalized->SetBinContent(100,0.001094092);
   h_RBF_Normalized->SetBinContent(112,0.002038043);
   h_RBF_Normalized->SetBinContent(113,0.001094092);
   h_RBF_Normalized->SetBinContent(126,0.001094092);
   h_RBF_Normalized->SetBinContent(140,0.005235602);
   h_RBF_Normalized->SetBinContent(154,0.005494506);

   TH1 *h_RBB_Normalized = new TH2F("h_RBB_Normalized","",nb, xAxis1,nb, yAxis1);
   h_RBB_Normalized->SetBinContent(14,0.9003466);
   h_RBB_Normalized->SetBinContent(15,0.04126625);
   h_RBB_Normalized->SetBinContent(16,0.000631579);
   h_RBB_Normalized->SetBinContent(17,9.34929e-05);
   h_RBB_Normalized->SetBinContent(18,0.000320134);
   h_RBB_Normalized->SetBinContent(19,0.0002532928);
   h_RBB_Normalized->SetBinContent(20,0.0001620483);
   h_RBB_Normalized->SetBinContent(27,0.03032929);
   h_RBB_Normalized->SetBinContent(28,0.8253251);
   h_RBB_Normalized->SetBinContent(29,0.02378947);
   h_RBB_Normalized->SetBinContent(30,0.001963351);
   h_RBB_Normalized->SetBinContent(31,0.001206659);
   h_RBB_Normalized->SetBinContent(32,0.00139311);
   h_RBB_Normalized->SetBinContent(33,0.0004861449);
   h_RBB_Normalized->SetBinContent(41,0.02148106);
   h_RBB_Normalized->SetBinContent(42,0.5707368);
   h_RBB_Normalized->SetBinContent(43,0.03599476);
   h_RBB_Normalized->SetBinContent(44,0.01736111);
   h_RBB_Normalized->SetBinContent(45,0.01874367);
   h_RBB_Normalized->SetBinContent(46,0.008750607);
   h_RBB_Normalized->SetBinContent(47,0.004145937);
   h_RBB_Normalized->SetBinContent(48,0.001402525);
   h_RBB_Normalized->SetBinContent(55,0.02210526);
   h_RBB_Normalized->SetBinContent(56,0.4688669);
   h_RBB_Normalized->SetBinContent(57,0.08628841);
   h_RBB_Normalized->SetBinContent(58,0.04711246);
   h_RBB_Normalized->SetBinContent(59,0.01588073);
   h_RBB_Normalized->SetBinContent(60,0.005804312);
   h_RBB_Normalized->SetBinContent(61,0.005610098);
   h_RBB_Normalized->SetBinContent(62,0.003745318);
   h_RBB_Normalized->SetBinContent(69,0.05366492);
   h_RBB_Normalized->SetBinContent(70,0.6661742);
   h_RBB_Normalized->SetBinContent(71,0.3222138);
   h_RBB_Normalized->SetBinContent(72,0.0238211);
   h_RBB_Normalized->SetBinContent(73,0.006633499);
   h_RBB_Normalized->SetBinContent(74,0.001402525);
   h_RBB_Normalized->SetBinContent(82,0.0004674645);
   h_RBB_Normalized->SetBinContent(83,0.1942228);
   h_RBB_Normalized->SetBinContent(84,0.7751266);
   h_RBB_Normalized->SetBinContent(85,0.1432507);
   h_RBB_Normalized->SetBinContent(86,0.009121061);
   h_RBB_Normalized->SetBinContent(87,0.008415148);
   h_RBB_Normalized->SetBinContent(96,0.001748424);
   h_RBB_Normalized->SetBinContent(97,0.04404762);
   h_RBB_Normalized->SetBinContent(98,0.6725004);
   h_RBB_Normalized->SetBinContent(99,0.1575456);
   h_RBB_Normalized->SetBinContent(100,0.01262272);
   h_RBB_Normalized->SetBinContent(110,2.532928e-05);
   h_RBB_Normalized->SetBinContent(111,0.01976989);
   h_RBB_Normalized->SetBinContent(112,0.8441128);
   h_RBB_Normalized->SetBinContent(113,0.08695652);
   h_RBB_Normalized->SetBinContent(125,0.04063018);
   h_RBB_Normalized->SetBinContent(126,0.8737728);
   h_RBB_Normalized->SetBinContent(127,0.1198502);
   h_RBB_Normalized->SetBinContent(128,0.01818182);
   h_RBB_Normalized->SetBinContent(139,0.02103787);
   h_RBB_Normalized->SetBinContent(140,0.9138577);
   h_RBB_Normalized->SetBinContent(141,0.03636364);
   h_RBB_Normalized->SetBinContent(153,0.01498127);
   h_RBB_Normalized->SetBinContent(154,0.969697);



   TH1 *h_AFB_Gen_before_cuts = new TH1F("h_AFB_Gen_before_cuts","h_AFB_Gen_before_cuts",nb, xAxis1);
   h_AFB_Gen_before_cuts->SetBinContent(1,-0.1033912);
   h_AFB_Gen_before_cuts->SetBinContent(2,-0.1708525);
   h_AFB_Gen_before_cuts->SetBinContent(3,-0.2498851);
   h_AFB_Gen_before_cuts->SetBinContent(4,-0.1178094);
   h_AFB_Gen_before_cuts->SetBinContent(5,0.005458405);
   h_AFB_Gen_before_cuts->SetBinContent(6,0.05640414);
   h_AFB_Gen_before_cuts->SetBinContent(7,0.1406382);
   h_AFB_Gen_before_cuts->SetBinContent(8,0.2280311);
   h_AFB_Gen_before_cuts->SetBinContent(9,0.3170856);
   h_AFB_Gen_before_cuts->SetBinContent(10,0.3088235);
   h_AFB_Gen_before_cuts->SetBinContent(11,0.3939394);

/*
   h_AFB_Gen_before_cuts->SetBinError(1,0.005566816);
   h_AFB_Gen_before_cuts->SetBinError(2,0.007882524);
   h_AFB_Gen_before_cuts->SetBinError(3,0.007366061);
   h_AFB_Gen_before_cuts->SetBinError(4,0.005514387);
   h_AFB_Gen_before_cuts->SetBinError(5,0.002143538);
   h_AFB_Gen_before_cuts->SetBinError(6,0.001945601);
   h_AFB_Gen_before_cuts->SetBinError(7,0.005868096);
   h_AFB_Gen_before_cuts->SetBinError(8,0.01209435);
   h_AFB_Gen_before_cuts->SetBinError(9,0.01671516);
   h_AFB_Gen_before_cuts->SetBinError(10,0.0270592);
   h_AFB_Gen_before_cuts->SetBinError(11,0.03988945);
*/


   TH1 *h_AFB_Gen = new TH1F("h_AFB_Gen","h_AFB_Gen",nb, xAxis1);
   h_AFB_Gen->SetBinContent(1,-0.03344982);
   h_AFB_Gen->SetBinContent(2,-0.05634759);
   h_AFB_Gen->SetBinContent(3,-0.07606264);
   h_AFB_Gen->SetBinContent(4,-0.03485021);
   h_AFB_Gen->SetBinContent(5,-0.002592108);
   h_AFB_Gen->SetBinContent(6,0.01868015);
   h_AFB_Gen->SetBinContent(7,0.04094184);
   h_AFB_Gen->SetBinContent(8,0.08356941);
   h_AFB_Gen->SetBinContent(9,0.164967);
   h_AFB_Gen->SetBinContent(10,0.07782672);
   h_AFB_Gen->SetBinContent(11,0.3085106);
   h_AFB_Gen->SetBinError(1,0.02235642);
   h_AFB_Gen->SetBinError(2,0.01845321);
   h_AFB_Gen->SetBinError(3,0.01369331);
   h_AFB_Gen->SetBinError(4,0.009351468);
   h_AFB_Gen->SetBinError(5,0.003547271);
   h_AFB_Gen->SetBinError(6,0.003193767);
   h_AFB_Gen->SetBinError(7,0.009381114);
   h_AFB_Gen->SetBinError(8,0.01888334);
   h_AFB_Gen->SetBinError(9,0.02482348);
   h_AFB_Gen->SetBinError(10,0.03843596);
   h_AFB_Gen->SetBinError(11,0.05396952);



   TH1 *h_acc_corr_F = new TH1F("h_acc_corr_F","h_acc_corr_F",nb, xAxis1);
   h_acc_corr_F->SetBinContent(1,0.06620614);
   h_acc_corr_F->SetBinContent(2,0.2024174);
   h_acc_corr_F->SetBinContent(3,0.3374183);
   h_acc_corr_F->SetBinContent(4,0.3756714);
   h_acc_corr_F->SetBinContent(5,0.3622198);
   h_acc_corr_F->SetBinContent(6,0.3568459);
   h_acc_corr_F->SetBinContent(7,0.3507401);
   h_acc_corr_F->SetBinContent(8,0.3464674);
   h_acc_corr_F->SetBinContent(9,0.3743254);
   h_acc_corr_F->SetBinContent(10,0.3748723);
   h_acc_corr_F->SetBinContent(11,0.486166);
   h_acc_corr_F->SetBinError(1,0.002197259);
   h_acc_corr_F->SetBinError(2,0.00595344);
   h_acc_corr_F->SetBinError(3,0.007838837);
   h_acc_corr_F->SetBinError(4,0.00592788);
   h_acc_corr_F->SetBinError(5,0.002123573);
   h_acc_corr_F->SetBinError(6,0.001859814);
   h_acc_corr_F->SetBinError(7,0.005296193);
   h_acc_corr_F->SetBinError(8,0.01027814);
   h_acc_corr_F->SetBinError(9,0.01408265);
   h_acc_corr_F->SetBinError(10,0.02294465);
   h_acc_corr_F->SetBinError(11,0.03778772);



   TH1 *h_acc_corr_B = new TH1F("h_acc_corr_B","h_acc_corr_B",nb, xAxis1);
   h_acc_corr_B->SetBinContent(1,0.05752237);
   h_acc_corr_B->SetBinContent(2,0.160462);
   h_acc_corr_B->SetBinContent(3,0.2358421);
   h_acc_corr_B->SetBinContent(4,0.3178964);
   h_acc_corr_B->SetBinContent(5,0.3680991);
   h_acc_corr_B->SetBinContent(6,0.3848553);
   h_acc_corr_B->SetBinContent(7,0.4289195);
   h_acc_corr_B->SetBinContent(8,0.4661383);
   h_acc_corr_B->SetBinContent(9,0.5174721);
   h_acc_corr_B->SetBinContent(10,0.6073501);
   h_acc_corr_B->SetBinContent(11,0.5909091);
   h_acc_corr_B->SetBinError(1,0.001838702);
   h_acc_corr_B->SetBinError(2,0.004382106);
   h_acc_corr_B->SetBinError(3,0.004880392);
   h_acc_corr_B->SetBinError(4,0.004741533);
   h_acc_corr_B->SetBinError(5,0.002157095);
   h_acc_corr_B->SetBinError(6,0.002064605);
   h_acc_corr_B->SetBinError(7,0.006940054);
   h_acc_corr_B->SetBinError(8,0.01569044);
   h_acc_corr_B->SetBinError(9,0.02416255);
   h_acc_corr_B->SetBinError(10,0.04345398);
   h_acc_corr_B->SetBinError(11,0.06536898);

 
   TH1 *h_MZobs_F = new TH1F("h_MZobs_F","M(Z)#rightarrow #mu#mu",nb, xAxis1);
//------------------------------MC----------------------------------------------
/*
   h_MZobs_F->SetBinContent(1,2201);
   h_MZobs_F->SetBinContent(2,3195);
   h_MZobs_F->SetBinContent(3,8745);
   h_MZobs_F->SetBinContent(4,21302);
   h_MZobs_F->SetBinContent(5,83522);
   h_MZobs_F->SetBinContent(6,80802);
   h_MZobs_F->SetBinContent(7,12719);
   h_MZobs_F->SetBinContent(8,2947);
   h_MZobs_F->SetBinContent(9,1842);
   h_MZobs_F->SetBinContent(10,736);
   h_MZobs_F->SetBinContent(11,410);
   h_MZobs_F->SetBinError(1,46.9148);
   h_MZobs_F->SetBinError(2,56.5243);
   h_MZobs_F->SetBinError(3,93.5147);
   h_MZobs_F->SetBinError(4,145.952);
   h_MZobs_F->SetBinError(5,289.002);
   h_MZobs_F->SetBinError(6,284.257);
   h_MZobs_F->SetBinError(7,112.779);
   h_MZobs_F->SetBinError(8,54.2863);
   h_MZobs_F->SetBinError(9,42.9185);
   h_MZobs_F->SetBinError(10,27.1293);
   h_MZobs_F->SetBinError(11,20.2485);
*/
//-------------------------------------------------------------------------------
   h_MZobs_F->SetBinContent(1,67);
   h_MZobs_F->SetBinContent(2,103);
   h_MZobs_F->SetBinContent(3,204);
   h_MZobs_F->SetBinContent(4,536);
   h_MZobs_F->SetBinContent(5,2108);
   h_MZobs_F->SetBinContent(6,1952);
   h_MZobs_F->SetBinContent(7,288);
   h_MZobs_F->SetBinContent(8,60);
   h_MZobs_F->SetBinContent(9,57);
   h_MZobs_F->SetBinContent(10,23);
   h_MZobs_F->SetBinContent(11,12);
   h_MZobs_F->SetBinError(1,8.18535);
   h_MZobs_F->SetBinError(2,10.1489);
   h_MZobs_F->SetBinError(3,14.2829);
   h_MZobs_F->SetBinError(4,23.1517);
   h_MZobs_F->SetBinError(5,45.913);
   h_MZobs_F->SetBinError(6,44.1814);
   h_MZobs_F->SetBinError(7,16.9706);
   h_MZobs_F->SetBinError(8,7.74597);
   h_MZobs_F->SetBinError(9,7.54983);
   h_MZobs_F->SetBinError(10,4.79583);
   h_MZobs_F->SetBinError(11,3.4641);


   TH1 *h_MZobs_B = new TH1F("h_MZobs_B","M(Z)#rightarrow #mu#mu",nb, xAxis1);
//------------------------------MC----------------------------------------------
/*
   h_MZobs_B->SetBinContent(1,2300);
   h_MZobs_B->SetBinContent(2,3555);
   h_MZobs_B->SetBinContent(3,9561);
   h_MZobs_B->SetBinContent(4,21476);
   h_MZobs_B->SetBinContent(5,81457);
   h_MZobs_B->SetBinContent(6,79341);
   h_MZobs_B->SetBinContent(7,12199);
   h_MZobs_B->SetBinContent(8,2449);
   h_MZobs_B->SetBinContent(9,1382);
   h_MZobs_B->SetBinContent(10,579);
   h_MZobs_B->SetBinContent(11,291);
   h_MZobs_B->SetBinError(1,47.9583);
   h_MZobs_B->SetBinError(2,59.6238);
   h_MZobs_B->SetBinError(3,97.7804);
   h_MZobs_B->SetBinError(4,146.547);
   h_MZobs_B->SetBinError(5,285.407);
   h_MZobs_B->SetBinError(6,281.675);
   h_MZobs_B->SetBinError(7,110.449);
   h_MZobs_B->SetBinError(8,49.4874);
   h_MZobs_B->SetBinError(9,37.1753);
   h_MZobs_B->SetBinError(10,24.0624);
   h_MZobs_B->SetBinError(11,17.0587);
*/
//-------------------------------------------------------------------------------
   h_MZobs_B->SetBinContent(1,60);
   h_MZobs_B->SetBinContent(2,86);
   h_MZobs_B->SetBinContent(3,245);
   h_MZobs_B->SetBinContent(4,578);
   h_MZobs_B->SetBinContent(5,2112);
   h_MZobs_B->SetBinContent(6,1966);
   h_MZobs_B->SetBinContent(7,290);
   h_MZobs_B->SetBinContent(8,68);
   h_MZobs_B->SetBinContent(9,53);
   h_MZobs_B->SetBinContent(10,15);
   h_MZobs_B->SetBinContent(11,12);
   h_MZobs_B->SetBinError(1,7.74597);
   h_MZobs_B->SetBinError(2,9.27362);
   h_MZobs_B->SetBinError(3,15.6525);
   h_MZobs_B->SetBinError(4,24.0416);
   h_MZobs_B->SetBinError(5,45.9565);
   h_MZobs_B->SetBinError(6,44.3396);
   h_MZobs_B->SetBinError(7,17.0294);
   h_MZobs_B->SetBinError(8,8.24621);
   h_MZobs_B->SetBinError(9,7.28011);
   h_MZobs_B->SetBinError(10,3.87298);
   h_MZobs_B->SetBinError(11,3.4641);



  h_AFB_Obs->Add(h_MZobs_F);
  h_AFB_Obs_Tmp1->Add(h_MZobs_B);
  h_AFB_Obs_Tmp1->Scale(-1);
  h_AFB_Obs->Add(h_AFB_Obs_Tmp1);
  h_AFB_Obs_Tmp2->Add(h_MZobs_F);
  h_AFB_Obs_Tmp2->Add(h_MZobs_B);
  h_AFB_Obs->Divide(h_AFB_Obs_Tmp2);
  float  Delta_AFB_Obs[20] = {};
  for (int i=1;i<=nb;i++){
     Delta_AFB_Obs[i] = (1-pow(h_AFB_Obs->GetBinContent(i),2))/(h_MZobs_F->GetBinContent(i)+h_MZobs_B->GetBinContent(i));
     Delta_AFB_Obs[i] = sqrt(Delta_AFB_Obs[i]);
     h_AFB_Obs->SetBinError(i,Delta_AFB_Obs[i]);	
  }
  h_AFB_Obs->SaveAs("uncorrected_AFB.C");



  float forward[50] = {};
  float backward[50] = {};
  for (int i=1;i<=nb;i++){
    for (int j=1;j<=nb;j++){
      forward[i] += h_RFF_Normalized->GetBinContent(i,j)*h_MZobs_F->GetBinContent(i)+h_RFB_Normalized->GetBinContent(i,j)*h_MZobs_B->GetBinContent(i);
      backward[i] += h_RBB_Normalized->GetBinContent(i,j)*h_MZobs_B->GetBinContent(i)+h_RBF_Normalized->GetBinContent(i,j)*h_MZobs_F->GetBinContent(i);
    }
    h_Unfolded_F->SetBinContent(i,forward[i]);
    h_Unfolded_B->SetBinContent(i,backward[i]);
    cout<<i<<"  "<<forward[i]<<"   "<<	backward[i]<<endl;
  }

  h_AFB_Unfolded->Add(h_Unfolded_F);
  h_AFB_Unfolded_Tmp1->Add(h_Unfolded_B);
  h_AFB_Unfolded_Tmp1->Scale(-1);
  h_AFB_Unfolded->Add(h_AFB_Unfolded_Tmp1);
  h_AFB_Unfolded_Tmp2->Add(h_Unfolded_F);
  h_AFB_Unfolded_Tmp2->Add(h_Unfolded_B);
  h_AFB_Unfolded->Divide(h_AFB_Unfolded_Tmp2);

  float  Delta_AFB_Unfolded[20] = {};
  for (int i=1;i<=nb;i++){
    // Delta_AFB_Unfolded[i] = (1-pow(h_AFB_Unfolded->GetBinContent(i),2))/(h_Unfolded_F->GetBinContent(i)+h_Unfolded_B->GetBinContent(i));
     Delta_AFB_Unfolded[i] = (1-pow(h_AFB_Unfolded->GetBinContent(i),2))/(h_MZobs_F->GetBinContent(i)+h_MZobs_F->GetBinContent(i));

     Delta_AFB_Unfolded[i] = sqrt(Delta_AFB_Unfolded[i]);
     h_AFB_Unfolded->SetBinError(i,Delta_AFB_Unfolded[i]);	
  }

 


  h_Unfolded_and_AcceptanceCorrected_F->Add(h_Unfolded_F);
  h_Unfolded_and_AcceptanceCorrected_F->Divide(h_acc_corr_F);
  h_Unfolded_and_AcceptanceCorrected_B->Add(h_Unfolded_B);
  h_Unfolded_and_AcceptanceCorrected_B->Divide(h_acc_corr_B);

  h_Unfolded_and_AcceptanceCorrected_Total->Add(h_Unfolded_and_AcceptanceCorrected_F);
  h_Unfolded_and_AcceptanceCorrected_Total_Tmp1->Add(h_Unfolded_and_AcceptanceCorrected_B);
  h_Unfolded_and_AcceptanceCorrected_Total_Tmp1->Scale(-1);
  h_Unfolded_and_AcceptanceCorrected_Total->Add(h_Unfolded_and_AcceptanceCorrected_Total_Tmp1);
  h_Unfolded_and_AcceptanceCorrected_Total_Tmp2->Add(h_Unfolded_and_AcceptanceCorrected_F);
  h_Unfolded_and_AcceptanceCorrected_Total_Tmp2->Add(h_Unfolded_and_AcceptanceCorrected_B);  
  h_Unfolded_and_AcceptanceCorrected_Total->Divide(h_Unfolded_and_AcceptanceCorrected_Total_Tmp2);

  float  Delta_AFB_Unfolded_and_Acceptance_Corrected[20] = {};
  for (int i=1;i<=nb;i++){
//     Delta_AFB_Unfolded_and_Acceptance_Corrected[i] = (1-pow(h_Unfolded_and_AcceptanceCorrected_Total->GetBinContent(i),2))/(h_Unfolded_and_AcceptanceCorrected_F->GetBinContent(i)+h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i));
//     Delta_AFB_Unfolded_and_Acceptance_Corrected[i] = sqrt(Delta_AFB_Unfolded_and_Acceptance_Corrected[i]);
//     h_Unfolded_and_AcceptanceCorrected_Total->SetBinError(i,Delta_AFB_Unfolded_and_Acceptance_Corrected[i]);	
     float nnew = h_Unfolded_and_AcceptanceCorrected_F->GetBinContent(i)+h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i);
     float eff_c = h_acc_corr_F->GetBinContent(i)*(1+h_Unfolded_and_AcceptanceCorrected_Total->GetBinContent(i)) +  h_acc_corr_B->GetBinContent(i)*(1-h_Unfolded_and_AcceptanceCorrected_Total->GetBinContent(i));
     eff_c /= 2;
     //Delta_AFB_Unfolded_and_Acceptance_Corrected[i] = h_AFB_Unfolded->GetBinError(i);
     //Delta_AFB_Unfolded_and_Acceptance_Corrected[i] = (1-pow(h_Unfolded_and_AcceptanceCorrected_Total->GetBinContent(i),2))/(h_Unfolded_F->GetBinContent(i)+h_Unfolded_B->GetBinContent(i));
     Delta_AFB_Unfolded_and_Acceptance_Corrected[i] = (1-pow(h_Unfolded_and_AcceptanceCorrected_Total->GetBinContent(i),2))/(h_MZobs_F->GetBinContent(i)+h_MZobs_F->GetBinContent(i))
;
     
     Delta_AFB_Unfolded_and_Acceptance_Corrected[i] = sqrt(Delta_AFB_Unfolded_and_Acceptance_Corrected[i]);
     h_Unfolded_and_AcceptanceCorrected_Total->SetBinError(i,Delta_AFB_Unfolded_and_Acceptance_Corrected[i]);
  }



  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ERROR CALCULATION @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
/*
  float D_AFB_NFobs_1st[50][50],D_AFB_NFobs_2nd[50][50],D_AFB_NBobs_1st[50][50],D_AFB_NBobs_2nd[50][50],D_AFB_NFobs[50][50],D_AFB_NBobs[50][50],DeltaAFB[50];
  float DeltaNFobs[50],DeltaNBobs[50];
  float epsilon[50][50];//error matrix
  float correlation[50][50];//correlation matrix
  for (int i=1;i<=nb;i++){
    DeltaAFB[i] = 0;
    for (int j=1;j<=nb;j++){
      //     cout<<h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i)<<"  "<<h_RFF_Normalized->GetBinContent(i,j)<<"  "<<h_acc_corr_F->GetBinContent(i)<<"   "<<pow(h_Unfolded_and_AcceptanceCorrected_F->GetBinContent(i) + h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i),2)<<endl;
     // cout<<"biiiiiir F"<<endl;
      D_AFB_NFobs_1st[i][j] = 2*h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i)*h_RFF_Normalized->GetBinContent(i,j);
      //cout<<i<<"  "<<j<<"  "<<D_AFB_NFobs_1st[i][j] <<endl;
      D_AFB_NFobs_1st[i][j] /= h_acc_corr_F->GetBinContent(i);
      //cout<<i<<"  "<<j<<"  "<<D_AFB_NFobs_1st[i][j] <<endl;
      D_AFB_NFobs_1st[i][j] /= pow(h_Unfolded_and_AcceptanceCorrected_F->GetBinContent(i) + h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i),2);
      //cout<<i<<"  "<<j<<"  "<<D_AFB_NFobs_1st[i][j] <<endl;
      //cout<<"ikiiiiiii F"<<endl;
      D_AFB_NFobs_2nd[i][j] = -2*h_Unfolded_and_AcceptanceCorrected_F->GetBinContent(i)*h_RBF_Normalized->GetBinContent(i,j);
      //cout<<i<<"  "<<j<<"  "<<D_AFB_NFobs_2nd[i][j] <<endl;
      D_AFB_NFobs_2nd[i][j] /= h_acc_corr_B->GetBinContent(i);
      //cout<<i<<"  "<<j<<"  "<<D_AFB_NFobs_2nd[i][j] <<endl;
      D_AFB_NFobs_2nd[i][j] /= pow(h_Unfolded_and_AcceptanceCorrected_F->GetBinContent(i) + h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i),2);
      //cout<<i<<"  "<<j<<"  "<<D_AFB_NFobs_2nd[i][j] <<endl;
      //cout<<"FFFFFFFFFFFFFFFFFF"<<endl;
      D_AFB_NFobs[i][j] =  D_AFB_NFobs_1st[i][j] +  D_AFB_NFobs_2nd[i][j];
      //cout<<i<<"  "<<j<<"  "<<D_AFB_NFobs[i][j] <<endl;

 
      //cout<<"biiiiiir B"<<endl; 
      D_AFB_NBobs_1st[i][j] = 2*h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i)*h_RFB_Normalized->GetBinContent(i,j);
      //cout<<i<<"  "<<j<<"  "<<D_AFB_NBobs_1st[i][j] <<endl;
      D_AFB_NBobs_1st[i][j] /= h_acc_corr_F->GetBinContent(i);
      //cout<<i<<"  "<<j<<"  "<<D_AFB_NBobs_1st[i][j] <<endl;
      D_AFB_NBobs_1st[i][j] /= pow(h_Unfolded_and_AcceptanceCorrected_F->GetBinContent(i) + h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i),2);
      //cout<<i<<"  "<<j<<"  "<<D_AFB_NBobs_1st[i][j] <<endl;
      //cout<<"ikiiiiiii B"<<endl;
      D_AFB_NBobs_2nd[i][j] = -2*h_Unfolded_and_AcceptanceCorrected_F->GetBinContent(i)*h_RBB_Normalized->GetBinContent(i,j);
      //cout<<i<<"  "<<j<<"  "<<D_AFB_NBobs_2nd[i][j] <<endl;
      D_AFB_NBobs_2nd[i][j] /= h_acc_corr_B->GetBinContent(i);
      //cout<<i<<"  "<<j<<"  "<<D_AFB_NBobs_2nd[i][j] <<endl;
      D_AFB_NBobs_2nd[i][j] /= pow(h_Unfolded_and_AcceptanceCorrected_F->GetBinContent(i) + h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i),2);
      //cout<<i<<"  "<<j<<"  "<<D_AFB_NBobs_2nd[i][j] <<endl;
      //cout<<"BBBBBBBBBBBBBBBBBBBBB"<<endl;
      D_AFB_NBobs[i][j] =  D_AFB_NBobs_1st[i][j] +  D_AFB_NBobs_2nd[i][j];  
      //cout<<i<<"  "<<j<<"  "<<D_AFB_NBobs[i][j] <<endl;
      
      //cout<<"obs error F"<<endl;
      DeltaNFobs[j] = h_MZobs_F->GetBinError(i);
       //cout<<i<<"  "<<j<<"  "<<DeltaNFobs[j] <<endl;
      //cout<<"obs error B"<<endl;
      DeltaNBobs[j] = h_MZobs_B->GetBinError(i);
       //cout<<i<<"  "<<j<<"  "<<DeltaNBobs[j] <<endl;

      DeltaAFB[i] += pow(D_AFB_NFobs[i][j]*DeltaNFobs[j],2)+pow(D_AFB_NBobs[i][j]*DeltaNBobs[j],2);
      //cout<<i<<"  "<<j<<"  "<<DeltaAFB[j] <<endl;

    }
    DeltaAFB[i] = sqrt(DeltaAFB[i]);
      //cout<<"tot error    "<<DeltaAFB[i] <<endl;
    //cout<<i<<"  "<<h_Unfolded_and_AcceptanceCorrected_Total->GetBinError(i)<<"   "<<DeltaAFB[i]<<endl;
    h_Unfolded_and_AcceptanceCorrected_Total->SetBinError(i,DeltaAFB[i]);
  }

 //error and correlation matrix calculation
  for (int i=1;i<=nb;i++){
    for (int j=1;j<=nb;j++){
      for (int k=1;k<=nb;k++){
	epsilon[i][j] += D_AFB_NFobs[i][k]*D_AFB_NFobs[j][k]*pow(DeltaNFobs[k],2) + D_AFB_NBobs[i][k]*D_AFB_NBobs[j][k]*pow(DeltaNBobs[k],2);
      }
    }
  }

 for (int i=1;i<=nb;i++){
    for (int j=1;j<=nb;j++){
        correlation[i][j] = epsilon[i][j]/sqrt(epsilon[i][i]+epsilon[j][j]);
        h_correlation->SetBinContent(i,j,correlation[i][j]);
    }
 }



  for (int i=1;i<=nb;i++) DeltaAFB[i] = 0;

  for (int i=1;i<=nb;i++){
    for (int j=1;j<=nb;j++){
      //     cout<<h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i)<<"  "<<h_RFF_Normalized->GetBinContent(i,j)<<"  "<<h_acc_corr_F->GetBinContent(i)<<"   "<<pow(h_Unfolded_and_AcceptanceCorrected_F->GetBinContent(i) + h_Unfolded_and_AcceptanceCorrected_B->GetBinContent(i),2)<<endl;
      D_AFB_NFobs_1st[i][j] = -2*h_Unfolded_B->GetBinContent(i)*h_RFF_Normalized->GetBinContent(i,j);
      D_AFB_NFobs_1st[i][j] /= pow(h_Unfolded_F->GetBinContent(i) + h_Unfolded_B->GetBinContent(i),2);
      D_AFB_NFobs_2nd[i][j] = 2*h_Unfolded_F->GetBinContent(i)*h_RBF_Normalized->GetBinContent(i,j);
      D_AFB_NFobs_2nd[i][j] /= pow(h_Unfolded_F->GetBinContent(i) + h_Unfolded_B->GetBinContent(i),2);
      D_AFB_NFobs[i][j] =  D_AFB_NFobs_1st[i][j] +  D_AFB_NFobs_2nd[i][j];

      D_AFB_NBobs_1st[i][j] = -2*h_Unfolded_B->GetBinContent(i)*h_RFB_Normalized->GetBinContent(i,j);
      D_AFB_NBobs_1st[i][j] /= pow(h_Unfolded_F->GetBinContent(i) + h_Unfolded_B->GetBinContent(i),2);
      D_AFB_NBobs_2nd[i][j] = 2*h_Unfolded_F->GetBinContent(i)*h_RBB_Normalized->GetBinContent(i,j);
      D_AFB_NBobs_2nd[i][j] /= pow(h_Unfolded_F->GetBinContent(i) + h_Unfolded_B->GetBinContent(i),2);
      D_AFB_NBobs[i][j] =  D_AFB_NBobs_1st[i][j] +  D_AFB_NBobs_2nd[i][j];  
      
      DeltaNFobs[j] = h_MZobs_F->GetBinError(i);
      DeltaNBobs[j] = h_MZobs_B->GetBinError(i);

      DeltaAFB[i] += pow(D_AFB_NFobs[i][j]*DeltaNFobs[j],2)+pow(D_AFB_NBobs[i][j]*DeltaNBobs[j],2);
    }
    DeltaAFB[i] = sqrt(DeltaAFB[i]);
    h_AFB_Unfolded->SetBinError(i,DeltaAFB[i]);
    //cout<<i<<"  "<<h_Unfolded_and_AcceptanceCorrected_Total->GetBinContent(i)<<"   "<<DeltaAFB[i]<<endl;
  }


  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


  for (int i=1;i<=nb;i++){
    for (int j=1;j<=nb;j++){
      //cout<<i<<"   "<<j<<"   "<<correlation[i][j]<<"   "<<h_correlation->GetBinContent(i,j)<<endl;
    }
  }

*/

  float w[20];
/*
w[1] = 0.399208;
w[2] = 0.389287;
w[3] = 0.350551;
w[4] = 0.345697;
w[5] = 0.452617;
w[6] = 0.330791;
w[7] = 0.340245;
w[8] = 0.325154;
w[9] = 0.286405;
w[10] = 0.287679;
w[11] = 0.175178;
*/
///WEIGHTED BY nf+nb

w[1] = 0.395343;
w[2] = 0.384808;
w[3] = 0.349879;
w[4] = 0.34798;
w[5] = 0.453906;
w[6] = 0.334755;
w[7] = 0.344743;
w[8] = 0.329096;
w[9] = 0.290768;
w[10] = 0.298369;
w[11] = 0.196813;

float D[20];
  D[1]=  2.50029;
  D[2]=  2.57543;
  D[3]=  2.24969;
  D[4]=  2.22874;
  D[5]=  6.07954;
  D[6]=  2.39688;
  D[7]=  2.40839;
  D[8] = 2.3572;
  D[9]=  2.05126;
  D[10]=  2.09787;
  D[11] = 1.59958;

//



  TH1 *h_AFB_abs_genlevel = new TH1F("h_AFB_abs_genlevel","",11, xAxis1);
   h_AFB_abs_genlevel->SetBinContent(1,-0.258508);
   h_AFB_abs_genlevel->SetBinContent(2,-0.440019);
   h_AFB_abs_genlevel->SetBinContent(3,-0.562165);
   h_AFB_abs_genlevel->SetBinContent(4,-0.262567);
   h_AFB_abs_genlevel->SetBinContent(5,0.0331846);
   h_AFB_abs_genlevel->SetBinContent(6,0.135194);
   h_AFB_abs_genlevel->SetBinContent(7,0.338712);
   h_AFB_abs_genlevel->SetBinContent(8,0.537516);
   h_AFB_abs_genlevel->SetBinContent(9,0.650424);
   h_AFB_abs_genlevel->SetBinContent(10,0.647872);
   h_AFB_abs_genlevel->SetBinContent(11,0.630137);

   for (int i=1;i<=nb;i++){
    h_full_corrected->SetBinContent(i,h_Unfolded_and_AcceptanceCorrected_Total->GetBinContent(i)*D[i]);
    h_full_corrected->SetBinError(i,h_Unfolded_and_AcceptanceCorrected_Total->GetBinError(i)*D[i]);

/*
     h_full_corrected->SetBinContent(i,h_Unfolded_and_AcceptanceCorrected_Total->GetBinContent(i)/(1-2*w[i]));
     h_full_corrected->SetBinError(i,DeltaAFB[i]/(1-2*w[i]));
*/
   }

  TCanvas *c0 = new TCanvas();
  c0->cd();
  h_AFB_Gen->Draw();
  h_AFB_Unfolded->Draw("e1sames");
  c0->SaveAs("Unfolded.C");

  TCanvas *c1 = new TCanvas();
  c1->cd();
  h_AFB_Gen_before_cuts->GetYaxis()->SetRangeUser(-1,1);
  h_AFB_Gen_before_cuts->Draw();
  h_Unfolded_and_AcceptanceCorrected_Total->SetLineColor(4);
  h_Unfolded_and_AcceptanceCorrected_Total->SetMarkerColor(4);
  h_Unfolded_and_AcceptanceCorrected_Total->Draw("sames");  	    
  c1->SaveAs("Unfolded_and_AcceptanceCorrected_Total.C");

  TCanvas *c2 = new TCanvas();
  c2->cd();
  h_AFB_abs_genlevel->Draw();  
  h_full_corrected->SetMarkerColor(4);
  h_full_corrected->SetLineColor(4);
  h_full_corrected->Draw("e1sames");  	  
  c2->SaveAs("Unfolded_and_Acceptance_and_dilution_Corrected_.C");

  
  

  theFile->Write();
  theFile->Close();


}
