#include "afbbase.h"

using namespace std;

void tree1r()
{

  double AFB(double forward, double backward);
  double RAWAFBERROR(double rawafb, double forward, double backward);

  int nb = 10;
  int nb_sin = 7;//nominal 8 but not much stats for > 7
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
  xAxis_AFB[10] = 2000;

  //  int nb_Y = 4;
  float Y_bin_limits[nb_Y+1];
  Y_bin_limits[0] = 0.0;
  Y_bin_limits[1] = 1.0;
  Y_bin_limits[2] = 1.25;
  Y_bin_limits[3] = 1.5;
  Y_bin_limits[4] = 2.4;//!!!!!


  //electron channel results
double data_rawf[10][4]={{919.549, 161.225, 114.686, 213.796},{1587.87, 242.604, 209.152, 380.354},{4252.71, 790.422, 588.089, 1011.48},{14450.3, 3415.45, 2900.96, 4737.51},{114926, 21250.8, 17301.3, 25210.2},{10400.4, 2385.94, 2165.35, 3767.42},{2318.45, 521.076, 427.034, 679.67},{1495.81, 312.803, 302.174, 382.06},{699.99, 132.54, 156.342, 165.151},{463.032, 101.813, 82.2866, 104.663}};

double data_rawb[10][4]={{1025.17, 178.25, 109.946, 258.84},{1632.64, 240.525, 267.173, 447.941},{4462.98, 930.862, 774.94, 1279},{14757.3, 3392.39, 2974.86, 4886.41},{114284, 20193.3, 16382.4, 24302},{9777.02, 2170.33, 1915.11, 3401.42},{2076.66, 412.222, 287.256, 454.46},{1229.5, 193.52, 166.584, 216.275},{565.955, 88.6453, 63.8144, 103.612},{366.71, 55.6842, 29.5223, 50.8832}};

double data_bornf[10][4]={{1027.44, 186.354, 131.092, 237.769},{1720.44, 268.972, 222.142, 425.238},{3715.78, 706.914, 521.235, 776.014},{9100.19, 1915.61, 1370.9, 2186.43},{131932, 25345.5, 20939.2, 31591.9},{8842.55, 1591.68, 1279.28, 1540},{2492.01, 575.263, 437.939, 733.09},{1613.29, 330.636, 324.782, 368.519},{767.174, 141.878, 159.657, 171.12},{510.932, 108.615, 86.8051, 107.235}};

double data_bornb[10][4]={{1160.67, 208.514, 115.657, 284.996},{1765.43, 257.066, 287.074, 469.554},{3924.67, 860.437, 723.842, 1088.61},{9396.52, 1919.8, 1555.14, 2334.73},{130896, 24128.8, 19868.1, 30519.3},{8233.6, 1441.25, 1114.77, 1274.24},{2228.67, 460.748, 281.269, 487.544},{1324.47, 197.199, 178.022, 209.672},{627.741, 97.9225, 62.6883, 106.979},{402.859, 60.6218, 33.4459, 51.2989}};





 /* 
  float data_rawf[10][0]={919.549, 1587.87, 4252.71, 14450.3, 114926, 10400.4, 2318.45, 1495.81, 699.99, 463.032};
  float data_rawb[10][0]={1025.17, 1632.64, 4462.98, 14757.3, 114284, 9777.02, 2076.66, 1229.5, 565.955, 366.71};
  
  float data_rawf[10][1]={161.225, 242.604, 790.422, 3415.45, 21250.8, 2385.94, 521.076, 312.803, 132.54, 101.813};
  float data_rawb[10][1]={178.25, 240.525, 930.862, 3392.39, 20193.3, 2170.33, 412.222, 193.52, 88.6453, 55.6842};
  
  float data_rawf[10][2]={114.686, 209.152, 588.089, 2900.96, 17301.3, 2165.35, 427.034, 302.174, 156.342, 82.2866};
  float data_rawb[10][2]={109.946, 267.173, 774.94, 2974.86, 16382.4, 1915.11, 287.256, 166.584, 63.8144, 29.5223};
  
  float data_rawf[10][3]={213.796, 380.354, 1011.48, 4737.51, 25210.2, 3767.42, 679.67, 382.06, 165.151, 104.663};
  float data_rawb[10][3]={258.84, 447.941, 1279, 4886.41, 24302, 3401.42, 454.46, 216.275, 103.612, 50.8832};
  
  float data_bornf[10][0]={1027.44, 1720.44, 3715.78, 9100.19, 131932, 8842.55, 2492.01, 1613.29, 767.174, 510.932};
  float data_bornb[10][0]={1160.67, 1765.43, 3924.67, 9396.52, 130896, 8233.6, 2228.67, 1324.47, 627.741, 402.859};
  
  float data_bornf[10][1]={186.354, 268.972, 706.914, 1915.61, 25345.5, 1591.68, 575.263, 330.636, 141.878, 108.615};
  float data_bornb[10][1]={208.514, 257.066, 860.437, 1919.8, 24128.8, 1441.25, 460.748, 197.199, 97.9225, 60.6218};
  
  float data_bornf[10][2]={131.092, 222.142, 521.235, 1370.9, 20939.2, 1279.28, 437.939, 324.782, 159.657, 86.8051};
  float data_bornb[10][2]={115.657, 287.074, 723.842, 1555.14, 19868.1, 1114.77, 281.269, 178.022, 62.6883, 33.4459};
  
  float data_bornf[10][3]={237.769, 425.238, 776.014, 2186.43, 31591.9, 1540, 733.09, 368.519, 171.12, 107.235};
  float data_bornb[10][3]={284.996, 469.554, 1088.61, 2334.73, 30519.3, 1274.24, 487.544, 209.672, 106.979, 51.2989};
*/

   TH2F *h_RFF__1 = new TH2F("h_RFF__1","0.00 < |y| < 1.00",nb, xAxis_AFB,nb, xAxis_AFB);
   h_RFF__1->SetBinContent(13,1.259963);
   h_RFF__1->SetBinContent(14,-0.07610608);
   h_RFF__1->SetBinContent(15,0.003242817);
   h_RFF__1->SetBinContent(16,-0.0006141444);
   h_RFF__1->SetBinContent(17,8.16413e-05);
   h_RFF__1->SetBinContent(18,-3.086919e-06);
   h_RFF__1->SetBinContent(19,1.549373e-07);
   h_RFF__1->SetBinContent(20,-1.820496e-07);
   h_RFF__1->SetBinContent(21,1.493466e-09);
   h_RFF__1->SetBinContent(22,-1.385113e-10);
   h_RFF__1->SetBinContent(25,-0.07322412);
   h_RFF__1->SetBinContent(26,1.286929);
   h_RFF__1->SetBinContent(27,-0.06101583);
   h_RFF__1->SetBinContent(28,0.003341648);
   h_RFF__1->SetBinContent(29,-0.0004442302);
   h_RFF__1->SetBinContent(30,1.682645e-05);
   h_RFF__1->SetBinContent(31,-1.098904e-06);
   h_RFF__1->SetBinContent(32,3.542535e-06);
   h_RFF__1->SetBinContent(33,-5.853931e-08);
   h_RFF__1->SetBinContent(34,1.491794e-09);
   h_RFF__1->SetBinContent(37,0.002857433);
   h_RFF__1->SetBinContent(38,-0.0583004);
   h_RFF__1->SetBinContent(39,1.211726);
   h_RFF__1->SetBinContent(40,-0.07067473);
   h_RFF__1->SetBinContent(41,0.009395306);
   h_RFF__1->SetBinContent(42,-0.0003558191);
   h_RFF__1->SetBinContent(43,2.277693e-05);
   h_RFF__1->SetBinContent(44,-7.029042e-05);
   h_RFF__1->SetBinContent(45,1.146564e-06);
   h_RFF__1->SetBinContent(46,-3.02109e-08);
   h_RFF__1->SetBinContent(49,-0.0004350675);
   h_RFF__1->SetBinContent(50,0.00247264);
   h_RFF__1->SetBinContent(51,-0.07742552);
   h_RFF__1->SetBinContent(52,1.312979);
   h_RFF__1->SetBinContent(53,-0.1745396);
   h_RFF__1->SetBinContent(54,0.006594769);
   h_RFF__1->SetBinContent(55,-0.000290797);
   h_RFF__1->SetBinContent(56,-1.416975e-05);
   h_RFF__1->SetBinContent(57,4.775582e-06);
   h_RFF__1->SetBinContent(58,1.794515e-07);
   h_RFF__1->SetBinContent(61,-7.282315e-05);
   h_RFF__1->SetBinContent(62,-0.000348961);
   h_RFF__1->SetBinContent(63,-0.001721905);
   h_RFF__1->SetBinContent(64,-0.08420146);
   h_RFF__1->SetBinContent(65,1.196121);
   h_RFF__1->SetBinContent(66,-0.04733391);
   h_RFF__1->SetBinContent(67,0.001659493);
   h_RFF__1->SetBinContent(68,-0.0001746022);
   h_RFF__1->SetBinContent(69,-2.730942e-05);
   h_RFF__1->SetBinContent(70,-1.299852e-06);
   h_RFF__1->SetBinContent(73,-2.73144e-06);
   h_RFF__1->SetBinContent(74,-0.0001220145);
   h_RFF__1->SetBinContent(75,-0.002349926);
   h_RFF__1->SetBinContent(76,0.01049824);
   h_RFF__1->SetBinContent(77,-0.3003798);
   h_RFF__1->SetBinContent(78,1.410548);
   h_RFF__1->SetBinContent(79,-0.05352123);
   h_RFF__1->SetBinContent(80,0.00196176);
   h_RFF__1->SetBinContent(81,-6.4231e-05);
   h_RFF__1->SetBinContent(82,2.719883e-06);
   h_RFF__1->SetBinContent(85,-0.0002933104);
   h_RFF__1->SetBinContent(86,-9.411919e-05);
   h_RFF__1->SetBinContent(87,-0.0008430168);
   h_RFF__1->SetBinContent(88,-0.003600227);
   h_RFF__1->SetBinContent(89,0.03445591);
   h_RFF__1->SetBinContent(90,-0.2166832);
   h_RFF__1->SetBinContent(91,1.310292);
   h_RFF__1->SetBinContent(92,-0.05029322);
   h_RFF__1->SetBinContent(93,0.0009992775);
   h_RFF__1->SetBinContent(94,-4.815069e-05);
   h_RFF__1->SetBinContent(97,2.657241e-05);
   h_RFF__1->SetBinContent(98,2.509213e-05);
   h_RFF__1->SetBinContent(99,-0.0002084124);
   h_RFF__1->SetBinContent(100,-0.0006040928);
   h_RFF__1->SetBinContent(101,-0.003758443);
   h_RFF__1->SetBinContent(102,0.01411801);
   h_RFF__1->SetBinContent(103,-0.120138);
   h_RFF__1->SetBinContent(104,1.198236);
   h_RFF__1->SetBinContent(105,-0.02367062);
   h_RFF__1->SetBinContent(106,0.0003465779);
   h_RFF__1->SetBinContent(109,-1.246732e-06);
   h_RFF__1->SetBinContent(110,-1.696992e-06);
   h_RFF__1->SetBinContent(111,2.287825e-05);
   h_RFF__1->SetBinContent(112,1.042117e-05);
   h_RFF__1->SetBinContent(113,-0.0001972497);
   h_RFF__1->SetBinContent(114,-0.0005209277);
   h_RFF__1->SetBinContent(115,0.005897305);
   h_RFF__1->SetBinContent(116,-0.09116755);
   h_RFF__1->SetBinContent(117,1.183216);
   h_RFF__1->SetBinContent(118,-0.01717017);
   h_RFF__1->SetBinContent(121,1.340756e-07);
   h_RFF__1->SetBinContent(122,2.04758e-07);
   h_RFF__1->SetBinContent(123,-2.881496e-08);
   h_RFF__1->SetBinContent(124,2.917788e-05);
   h_RFF__1->SetBinContent(125,-0.0003964282);
   h_RFF__1->SetBinContent(126,4.209522e-05);
   h_RFF__1->SetBinContent(127,-0.0005003557);
   h_RFF__1->SetBinContent(128,0.003313686);
   h_RFF__1->SetBinContent(129,-0.05235665);
   h_RFF__1->SetBinContent(130,1.128785);

  TH2F *h_RFF__2 = new TH2F("h_RFF__2","1.00 < |y| < 1.25",nb, xAxis_AFB,nb, xAxis_AFB);
   h_RFF__2->SetBinContent(13,1.331052);
   h_RFF__2->SetBinContent(14,-0.1151729);
   h_RFF__2->SetBinContent(15,0.006289481);
   h_RFF__2->SetBinContent(16,-0.000537578);
   h_RFF__2->SetBinContent(17,9.863857e-05);
   h_RFF__2->SetBinContent(18,-6.81156e-06);
   h_RFF__2->SetBinContent(19,3.680592e-07);
   h_RFF__2->SetBinContent(20,-2.803895e-08);
   h_RFF__2->SetBinContent(21,9.120537e-08);
   h_RFF__2->SetBinContent(22,-2.74334e-09);
   h_RFF__2->SetBinContent(25,-0.1195227);
   h_RFF__2->SetBinContent(26,1.401144);
   h_RFF__2->SetBinContent(27,-0.0968475);
   h_RFF__2->SetBinContent(28,0.008277803);
   h_RFF__2->SetBinContent(29,-0.001518869);
   h_RFF__2->SetBinContent(30,0.0001048866);
   h_RFF__2->SetBinContent(31,-5.667497e-06);
   h_RFF__2->SetBinContent(32,4.31753e-07);
   h_RFF__2->SetBinContent(33,-1.40441e-06);
   h_RFF__2->SetBinContent(34,4.224285e-08);
   h_RFF__2->SetBinContent(37,0.006955232);
   h_RFF__2->SetBinContent(38,-0.08154337);
   h_RFF__2->SetBinContent(39,1.274158);
   h_RFF__2->SetBinContent(40,-0.1089055);
   h_RFF__2->SetBinContent(41,0.01998275);
   h_RFF__2->SetBinContent(42,-0.001379923);
   h_RFF__2->SetBinContent(43,7.456348e-05);
   h_RFF__2->SetBinContent(44,-5.680285e-06);
   h_RFF__2->SetBinContent(45,1.847689e-05);
   h_RFF__2->SetBinContent(46,-5.557609e-07);
   h_RFF__2->SetBinContent(49,-0.0005258947);
   h_RFF__2->SetBinContent(50,0.006274071);
   h_RFF__2->SetBinContent(51,-0.1129445);
   h_RFF__2->SetBinContent(52,1.412137);
   h_RFF__2->SetBinContent(53,-0.2591088);
   h_RFF__2->SetBinContent(54,0.01789295);
   h_RFF__2->SetBinContent(55,-0.0009668368);
   h_RFF__2->SetBinContent(56,7.365414e-05);
   h_RFF__2->SetBinContent(57,-0.0002395829);
   h_RFF__2->SetBinContent(58,7.206345e-06);
   h_RFF__2->SetBinContent(61,-5.778869e-06);
   h_RFF__2->SetBinContent(62,-0.0004698277);
   h_RFF__2->SetBinContent(63,0.005476157);
   h_RFF__2->SetBinContent(64,-0.1361714);
   h_RFF__2->SetBinContent(65,1.276718);
   h_RFF__2->SetBinContent(66,-0.0908113);
   h_RFF__2->SetBinContent(67,0.004902527);
   h_RFF__2->SetBinContent(68,-0.0002805414);
   h_RFF__2->SetBinContent(69,3.117921e-05);
   h_RFF__2->SetBinContent(70,-9.378302e-07);
   h_RFF__2->SetBinContent(73,4.992468e-07);
   h_RFF__2->SetBinContent(74,0.0001619066);
   h_RFF__2->SetBinContent(75,-0.003575535);
   h_RFF__2->SetBinContent(76,0.03128313);
   h_RFF__2->SetBinContent(77,-0.3984227);
   h_RFF__2->SetBinContent(78,1.511597);
   h_RFF__2->SetBinContent(79,-0.08322689);
   h_RFF__2->SetBinContent(80,0.004446459);
   h_RFF__2->SetBinContent(81,-0.0001365916);
   h_RFF__2->SetBinContent(82,4.108499e-06);
   h_RFF__2->SetBinContent(85,-1.847168e-06);
   h_RFF__2->SetBinContent(86,-7.783567e-06);
   h_RFF__2->SetBinContent(87,0.0003663043);
   h_RFF__2->SetBinContent(88,-0.008118588);
   h_RFF__2->SetBinContent(89,0.06991337);
   h_RFF__2->SetBinContent(90,-0.2920816);
   h_RFF__2->SetBinContent(91,1.372521);
   h_RFF__2->SetBinContent(92,-0.07323388);
   h_RFF__2->SetBinContent(93,0.002164429);
   h_RFF__2->SetBinContent(94,-6.510322e-05);
   h_RFF__2->SetBinContent(97,4.843533e-07);
   h_RFF__2->SetBinContent(98,-2.701608e-06);
   h_RFF__2->SetBinContent(99,3.226418e-05);
   h_RFF__2->SetBinContent(100,9.489024e-05);
   h_RFF__2->SetBinContent(101,-0.007068809);
   h_RFF__2->SetBinContent(102,0.02379605);
   h_RFF__2->SetBinContent(103,-0.1383015);
   h_RFF__2->SetBinContent(104,1.20155);
   h_RFF__2->SetBinContent(105,-0.03548944);
   h_RFF__2->SetBinContent(106,0.001067476);
   h_RFF__2->SetBinContent(109,-3.394594e-08);
   h_RFF__2->SetBinContent(110,4.414462e-08);
   h_RFF__2->SetBinContent(111,6.986615e-07);
   h_RFF__2->SetBinContent(112,-2.381879e-05);
   h_RFF__2->SetBinContent(113,0.0008402585);
   h_RFF__2->SetBinContent(114,-0.002888179);
   h_RFF__2->SetBinContent(115,0.007610654);
   h_RFF__2->SetBinContent(116,-0.09354779);
   h_RFF__2->SetBinContent(117,1.192702);
   h_RFF__2->SetBinContent(118,-0.03587493);
   h_RFF__2->SetBinContent(121,1.610639e-09);
   h_RFF__2->SetBinContent(122,-2.094537e-09);
   h_RFF__2->SetBinContent(123,-3.314951e-08);
   h_RFF__2->SetBinContent(124,1.130134e-06);
   h_RFF__2->SetBinContent(125,-3.986789e-05);
   h_RFF__2->SetBinContent(126,0.0001370359);
   h_RFF__2->SetBinContent(127,-0.000361104);
   h_RFF__2->SetBinContent(128,0.004438578);
   h_RFF__2->SetBinContent(129,-0.05659033);
   h_RFF__2->SetBinContent(130,1.110427);

   TH2F *h_RFF__3 = new TH2F("h_RFF__3","1.25 < |y| < 1.50",nb, xAxis_AFB,nb, xAxis_AFB);
   h_RFF__3->SetBinContent(13,1.35624);
   h_RFF__3->SetBinContent(14,-0.1808672);
   h_RFF__3->SetBinContent(15,0.01707698);
   h_RFF__3->SetBinContent(16,-0.00167335);
   h_RFF__3->SetBinContent(17,0.0003488699);
   h_RFF__3->SetBinContent(18,-3.116644e-05);
   h_RFF__3->SetBinContent(19,2.037516e-06);
   h_RFF__3->SetBinContent(20,-1.324247e-07);
   h_RFF__3->SetBinContent(21,3.497224e-09);
   h_RFF__3->SetBinContent(22,-6.556735e-11);
   h_RFF__3->SetBinContent(25,-0.1215395);
   h_RFF__3->SetBinContent(26,1.373317);
   h_RFF__3->SetBinContent(27,-0.1296648);
   h_RFF__3->SetBinContent(28,0.01270568);
   h_RFF__3->SetBinContent(29,-0.002648955);
   h_RFF__3->SetBinContent(30,0.0002366455);
   h_RFF__3->SetBinContent(31,-1.547078e-05);
   h_RFF__3->SetBinContent(32,1.005495e-06);
   h_RFF__3->SetBinContent(33,-2.655428e-08);
   h_RFF__3->SetBinContent(34,4.978503e-10);
   h_RFF__3->SetBinContent(37,0.00889133);
   h_RFF__3->SetBinContent(38,-0.1004683);
   h_RFF__3->SetBinContent(39,1.337915);
   h_RFF__3->SetBinContent(40,-0.1311005);
   h_RFF__3->SetBinContent(41,0.0273326);
   h_RFF__3->SetBinContent(42,-0.002441769);
   h_RFF__3->SetBinContent(43,0.0001596315);
   h_RFF__3->SetBinContent(44,-1.037496e-05);
   h_RFF__3->SetBinContent(45,2.739939e-07);
   h_RFF__3->SetBinContent(46,-5.136946e-09);
   h_RFF__3->SetBinContent(49,-0.0008986458);
   h_RFF__3->SetBinContent(50,0.01017774);
   h_RFF__3->SetBinContent(51,-0.1356678);
   h_RFF__3->SetBinContent(52,1.469708);
   h_RFF__3->SetBinContent(53,-0.3064133);
   h_RFF__3->SetBinContent(54,0.02737356);
   h_RFF__3->SetBinContent(55,-0.001789556);
   h_RFF__3->SetBinContent(56,0.0001163089);
   h_RFF__3->SetBinContent(57,-3.07162e-06);
   h_RFF__3->SetBinContent(58,5.758796e-08);
   h_RFF__3->SetBinContent(61,7.035687e-05);
   h_RFF__3->SetBinContent(62,-0.0008964027);
   h_RFF__3->SetBinContent(63,0.009330035);
   h_RFF__3->SetBinContent(64,-0.1678381);
   h_RFF__3->SetBinContent(65,1.314944);
   h_RFF__3->SetBinContent(66,-0.1174711);
   h_RFF__3->SetBinContent(67,0.007679712);
   h_RFF__3->SetBinContent(68,-0.000499129);
   h_RFF__3->SetBinContent(69,1.318157e-05);
   h_RFF__3->SetBinContent(70,-2.471334e-07);
   h_RFF__3->SetBinContent(73,-1.086484e-05);
   h_RFF__3->SetBinContent(74,0.0001573253);
   h_RFF__3->SetBinContent(75,-0.003869112);
   h_RFF__3->SetBinContent(76,0.04137078);
   h_RFF__3->SetBinContent(77,-0.4480959);
   h_RFF__3->SetBinContent(78,1.5533);
   h_RFF__3->SetBinContent(79,-0.1027804);
   h_RFF__3->SetBinContent(80,0.006469683);
   h_RFF__3->SetBinContent(81,-0.0001708588);
   h_RFF__3->SetBinContent(82,3.20333e-06);
   h_RFF__3->SetBinContent(85,-1.911235e-06);
   h_RFF__3->SetBinContent(86,1.523302e-05);
   h_RFF__3->SetBinContent(87,0.0001975378);
   h_RFF__3->SetBinContent(88,-0.007952415);
   h_RFF__3->SetBinContent(89,0.08249756);
   h_RFF__3->SetBinContent(90,-0.3276763);
   h_RFF__3->SetBinContent(91,1.362459);
   h_RFF__3->SetBinContent(92,-0.08569041);
   h_RFF__3->SetBinContent(93,0.002263011);
   h_RFF__3->SetBinContent(94,-4.242783e-05);
   h_RFF__3->SetBinContent(97,1.645644e-06);
   h_RFF__3->SetBinContent(98,-1.790523e-05);
   h_RFF__3->SetBinContent(99,0.0001973991);
   h_RFF__3->SetBinContent(100,-0.00137117);
   h_RFF__3->SetBinContent(101,-0.00893959);
   h_RFF__3->SetBinContent(102,0.034833);
   h_RFF__3->SetBinContent(103,-0.1685726);
   h_RFF__3->SetBinContent(104,1.221356);
   h_RFF__3->SetBinContent(105,-0.03225498);
   h_RFF__3->SetBinContent(106,0.0006047293);
   h_RFF__3->SetBinContent(109,-1.198541e-07);
   h_RFF__3->SetBinContent(110,1.304058e-06);
   h_RFF__3->SetBinContent(111,-1.43768e-05);
   h_RFF__3->SetBinContent(112,9.986382e-05);
   h_RFF__3->SetBinContent(113,0.0006510803);
   h_RFF__3->SetBinContent(114,-0.002536926);
   h_RFF__3->SetBinContent(115,0.01227733);
   h_RFF__3->SetBinContent(116,-0.08895274);
   h_RFF__3->SetBinContent(117,1.119801);
   h_RFF__3->SetBinContent(118,-0.02099448);
   h_RFF__3->SetBinContent(121,8.43421e-09);
   h_RFF__3->SetBinContent(122,-9.176738e-08);
   h_RFF__3->SetBinContent(123,1.011704e-06);
   h_RFF__3->SetBinContent(124,-7.02748e-06);
   h_RFF__3->SetBinContent(125,-4.581694e-05);
   h_RFF__3->SetBinContent(126,0.0001785251);
   h_RFF__3->SetBinContent(127,-0.0008639634);
   h_RFF__3->SetBinContent(128,0.006259661);
   h_RFF__3->SetBinContent(129,-0.07880113);
   h_RFF__3->SetBinContent(130,1.092765);

   TH2F *h_RFF__4 = new TH2F("h_RFF__4","1.50 < |y| < 2.40",nb, xAxis_AFB,nb, xAxis_AFB);
   h_RFF__4->SetBinContent(13,1.415364);
   h_RFF__4->SetBinContent(14,-0.2182865);
   h_RFF__4->SetBinContent(15,0.0218288);
   h_RFF__4->SetBinContent(16,-0.00264583);
   h_RFF__4->SetBinContent(17,0.000675839);
   h_RFF__4->SetBinContent(18,-8.692259e-05);
   h_RFF__4->SetBinContent(19,7.228843e-06);
   h_RFF__4->SetBinContent(20,-6.207027e-07);
   h_RFF__4->SetBinContent(21,-6.314544e-09);
   h_RFF__4->SetBinContent(22,3.880903e-07);
   h_RFF__4->SetBinContent(25,-0.1587742);
   h_RFF__4->SetBinContent(26,1.45733);
   h_RFF__4->SetBinContent(27,-0.145734);
   h_RFF__4->SetBinContent(28,0.01766416);
   h_RFF__4->SetBinContent(29,-0.004512054);
   h_RFF__4->SetBinContent(30,0.0005803149);
   h_RFF__4->SetBinContent(31,-4.82614e-05);
   h_RFF__4->SetBinContent(32,4.143952e-06);
   h_RFF__4->SetBinContent(33,4.215732e-08);
   h_RFF__4->SetBinContent(34,-2.590979e-06);
   h_RFF__4->SetBinContent(37,0.009315195);
   h_RFF__4->SetBinContent(38,-0.09782705);
   h_RFF__4->SetBinContent(39,1.28098);
   h_RFF__4->SetBinContent(40,-0.1552653);
   h_RFF__4->SetBinContent(41,0.03966029);
   h_RFF__4->SetBinContent(42,-0.005100882);
   h_RFF__4->SetBinContent(43,0.0004242105);
   h_RFF__4->SetBinContent(44,-3.642472e-05);
   h_RFF__4->SetBinContent(45,-3.705566e-07);
   h_RFF__4->SetBinContent(46,2.277432e-05);
   h_RFF__4->SetBinContent(49,-0.0009573585);
   h_RFF__4->SetBinContent(50,0.009623815);
   h_RFF__4->SetBinContent(51,-0.1454387);
   h_RFF__4->SetBinContent(52,1.538832);
   h_RFF__4->SetBinContent(53,-0.3930725);
   h_RFF__4->SetBinContent(54,0.05055476);
   h_RFF__4->SetBinContent(55,-0.004204344);
   h_RFF__4->SetBinContent(56,0.0003610048);
   h_RFF__4->SetBinContent(57,3.672581e-06);
   h_RFF__4->SetBinContent(58,-0.000225716);
   h_RFF__4->SetBinContent(61,2.246757e-05);
   h_RFF__4->SetBinContent(62,-0.001210063);
   h_RFF__4->SetBinContent(63,0.009748023);
   h_RFF__4->SetBinContent(64,-0.20432);
   h_RFF__4->SetBinContent(65,1.398931);
   h_RFF__4->SetBinContent(66,-0.1803359);
   h_RFF__4->SetBinContent(67,0.01494903);
   h_RFF__4->SetBinContent(68,-0.001289187);
   h_RFF__4->SetBinContent(69,4.376935e-05);
   h_RFF__4->SetBinContent(70,2.902637e-05);
   h_RFF__4->SetBinContent(73,5.016744e-05);
   h_RFF__4->SetBinContent(74,-5.477321e-05);
   h_RFF__4->SetBinContent(75,-0.0066437);
   h_RFF__4->SetBinContent(76,0.05476313);
   h_RFF__4->SetBinContent(77,-0.5074641);
   h_RFF__4->SetBinContent(78,1.613954);
   h_RFF__4->SetBinContent(79,-0.1348625);
   h_RFF__4->SetBinContent(80,0.01152697);
   h_RFF__4->SetBinContent(81,-0.0004104059);
   h_RFF__4->SetBinContent(82,7.174056e-07);
   h_RFF__4->SetBinContent(85,-2.241683e-05);
   h_RFF__4->SetBinContent(86,0.0001434356);
   h_RFF__4->SetBinContent(87,-0.0001282694);
   h_RFF__4->SetBinContent(88,-0.01285781);
   h_RFF__4->SetBinContent(89,0.09645112);
   h_RFF__4->SetBinContent(90,-0.355996);
   h_RFF__4->SetBinContent(91,1.393278);
   h_RFF__4->SetBinContent(92,-0.1191507);
   h_RFF__4->SetBinContent(93,0.004248185);
   h_RFF__4->SetBinContent(94,-8.86593e-05);
   h_RFF__4->SetBinContent(97,-5.084879e-06);
   h_RFF__4->SetBinContent(98,6.536195e-05);
   h_RFF__4->SetBinContent(99,-0.001001039);
   h_RFF__4->SetBinContent(100,0.0009383392);
   h_RFF__4->SetBinContent(101,-0.01301172);
   h_RFF__4->SetBinContent(102,0.03579441);
   h_RFF__4->SetBinContent(103,-0.1715142);
   h_RFF__4->SetBinContent(104,1.198271);
   h_RFF__4->SetBinContent(105,-0.04272439);
   h_RFF__4->SetBinContent(106,0.0009104781);
   h_RFF__4->SetBinContent(109,5.189949e-07);
   h_RFF__4->SetBinContent(110,-3.843856e-06);
   h_RFF__4->SetBinContent(111,8.242347e-05);
   h_RFF__4->SetBinContent(112,0.00050504);
   h_RFF__4->SetBinContent(113,-0.002733244);
   h_RFF__4->SetBinContent(114,-0.003082268);
   h_RFF__4->SetBinContent(115,0.01704171);
   h_RFF__4->SetBinContent(116,-0.1317125);
   h_RFF__4->SetBinContent(117,1.169631);
   h_RFF__4->SetBinContent(118,-0.02492927);
   h_RFF__4->SetBinContent(121,2.196171e-08);
   h_RFF__4->SetBinContent(122,-1.3403e-07);
   h_RFF__4->SetBinContent(123,-4.344347e-06);
   h_RFF__4->SetBinContent(124,-4.614912e-06);
   h_RFF__4->SetBinContent(125,-3.07675e-05);
   h_RFF__4->SetBinContent(126,0.001004939);
   h_RFF__4->SetBinContent(127,-0.004238742);
   h_RFF__4->SetBinContent(128,0.008046126);
   h_RFF__4->SetBinContent(129,-0.07819066);
   h_RFF__4->SetBinContent(130,1.064154);

  TH2F *h_RBB__1 = new TH2F("h_RBB__1","0.00 < |y| < 1.00",10, xAxis_AFB,10, xAxis_AFB);
   h_RBB__1->SetBinContent(13,1.260091);
   h_RBB__1->SetBinContent(14,-0.08701061);
   h_RBB__1->SetBinContent(15,0.004519584);
   h_RBB__1->SetBinContent(16,-0.0003043205);
   h_RBB__1->SetBinContent(17,4.15199e-05);
   h_RBB__1->SetBinContent(18,-1.986853e-06);
   h_RBB__1->SetBinContent(19,-1.748086e-07);
   h_RBB__1->SetBinContent(20,9.734714e-09);
   h_RBB__1->SetBinContent(21,9.150209e-09);
   h_RBB__1->SetBinContent(22,-2.164994e-10);
   h_RBB__1->SetBinContent(25,-0.07056166);
   h_RBB__1->SetBinContent(26,1.281044);
   h_RBB__1->SetBinContent(27,-0.06773162);
   h_RBB__1->SetBinContent(28,0.004208848);
   h_RBB__1->SetBinContent(29,-0.0005740458);
   h_RBB__1->SetBinContent(30,2.799621e-05);
   h_RBB__1->SetBinContent(31,2.681361e-06);
   h_RBB__1->SetBinContent(32,-1.445397e-07);
   h_RBB__1->SetBinContent(33,-1.264661e-07);
   h_RBB__1->SetBinContent(34,2.962716e-09);
   h_RBB__1->SetBinContent(37,0.001855743);
   h_RBB__1->SetBinContent(38,-0.05051287);
   h_RBB__1->SetBinContent(39,1.199335);
   h_RBB__1->SetBinContent(40,-0.07450346);
   h_RBB__1->SetBinContent(41,0.01016153);
   h_RBB__1->SetBinContent(42,-0.0004956156);
   h_RBB__1->SetBinContent(43,-4.74834e-05);
   h_RBB__1->SetBinContent(44,2.559299e-06);
   h_RBB__1->SetBinContent(45,2.23865e-06);
   h_RBB__1->SetBinContent(46,-5.244262e-08);
   h_RBB__1->SetBinContent(49,-0.0002408964);
   h_RBB__1->SetBinContent(50,0.002054071);
   h_RBB__1->SetBinContent(51,-0.07742018);
   h_RBB__1->SetBinContent(52,1.316139);
   h_RBB__1->SetBinContent(53,-0.1802656);
   h_RBB__1->SetBinContent(54,0.006664679);
   h_RBB__1->SetBinContent(55,-0.0002266977);
   h_RBB__1->SetBinContent(56,-5.187106e-06);
   h_RBB__1->SetBinContent(57,-3.988693e-05);
   h_RBB__1->SetBinContent(58,1.053861e-06);
   h_RBB__1->SetBinContent(61,-6.178173e-05);
   h_RBB__1->SetBinContent(62,-0.0003512032);
   h_RBB__1->SetBinContent(63,-0.001391326);
   h_RBB__1->SetBinContent(64,-0.08568661);
   h_RBB__1->SetBinContent(65,1.193452);
   h_RBB__1->SetBinContent(66,-0.04573797);
   h_RBB__1->SetBinContent(67,0.001605951);
   h_RBB__1->SetBinContent(68,-0.0001247803);
   h_RBB__1->SetBinContent(69,-2.326796e-05);
   h_RBB__1->SetBinContent(70,-3.259079e-06);
   h_RBB__1->SetBinContent(73,-9.18334e-05);
   h_RBB__1->SetBinContent(74,-0.0002023024);
   h_RBB__1->SetBinContent(75,-0.001707808);
   h_RBB__1->SetBinContent(76,0.01046032);
   h_RBB__1->SetBinContent(77,-0.3025619);
   h_RBB__1->SetBinContent(78,1.412668);
   h_RBB__1->SetBinContent(79,-0.05448783);
   h_RBB__1->SetBinContent(80,0.001945163);
   h_RBB__1->SetBinContent(81,-8.512232e-05);
   h_RBB__1->SetBinContent(82,8.143023e-06);
   h_RBB__1->SetBinContent(85,2.017887e-05);
   h_RBB__1->SetBinContent(86,-2.469139e-05);
   h_RBB__1->SetBinContent(87,-0.001608251);
   h_RBB__1->SetBinContent(88,-0.00438214);
   h_RBB__1->SetBinContent(89,0.03985135);
   h_RBB__1->SetBinContent(90,-0.2231055);
   h_RBB__1->SetBinContent(91,1.3078);
   h_RBB__1->SetBinContent(92,-0.04885862);
   h_RBB__1->SetBinContent(93,0.0005746937);
   h_RBB__1->SetBinContent(94,-0.0001559377);
   h_RBB__1->SetBinContent(97,2.026035e-05);
   h_RBB__1->SetBinContent(98,-0.000379902);
   h_RBB__1->SetBinContent(99,-0.0001457074);
   h_RBB__1->SetBinContent(100,-0.0006226137);
   h_RBB__1->SetBinContent(101,-0.004325808);
   h_RBB__1->SetBinContent(102,0.01381883);
   h_RBB__1->SetBinContent(103,-0.1127904);
   h_RBB__1->SetBinContent(104,1.197449);
   h_RBB__1->SetBinContent(105,-0.02358426);
   h_RBB__1->SetBinContent(106,0.0003189543);
   h_RBB__1->SetBinContent(109,-2.084729e-06);
   h_RBB__1->SetBinContent(110,4.591429e-05);
   h_RBB__1->SetBinContent(111,-0.0003791691);
   h_RBB__1->SetBinContent(112,0.0001334483);
   h_RBB__1->SetBinContent(113,-0.0004429354);
   h_RBB__1->SetBinContent(114,-0.001466264);
   h_RBB__1->SetBinContent(115,0.007552588);
   h_RBB__1->SetBinContent(116,-0.09130311);
   h_RBB__1->SetBinContent(117,1.194939);
   h_RBB__1->SetBinContent(118,-0.01551232);
   h_RBB__1->SetBinContent(121,5.088396e-08);
   h_RBB__1->SetBinContent(122,-1.213854e-06);
   h_RBB__1->SetBinContent(123,1.463735e-05);
   h_RBB__1->SetBinContent(124,-4.204687e-06);
   h_RBB__1->SetBinContent(125,2.293819e-05);
   h_RBB__1->SetBinContent(126,3.639411e-05);
   h_RBB__1->SetBinContent(127,-0.0001289932);
   h_RBB__1->SetBinContent(128,0.001792753);
   h_RBB__1->SetBinContent(129,-0.04545078);
   h_RBB__1->SetBinContent(130,1.123088);

   TH2F *h_RBB__2 = new TH2F("h_RBB__2","1.00 < |y| < 1.25",10, xAxis_AFB,10, xAxis_AFB);
   h_RBB__2->SetBinContent(13,1.336518);
   h_RBB__2->SetBinContent(14,-0.1271008);
   h_RBB__2->SetBinContent(15,0.01047087);
   h_RBB__2->SetBinContent(16,-0.00077769);
   h_RBB__2->SetBinContent(17,0.0001378847);
   h_RBB__2->SetBinContent(18,-9.089591e-06);
   h_RBB__2->SetBinContent(19,-1.184088e-06);
   h_RBB__2->SetBinContent(20,3.9056e-07);
   h_RBB__2->SetBinContent(21,-3.840617e-06);
   h_RBB__2->SetBinContent(22,2.60615e-08);
   h_RBB__2->SetBinContent(25,-0.1376121);
   h_RBB__2->SetBinContent(26,1.444204);
   h_RBB__2->SetBinContent(27,-0.118977);
   h_RBB__2->SetBinContent(28,0.00883663);
   h_RBB__2->SetBinContent(29,-0.001566737);
   h_RBB__2->SetBinContent(30,0.000103282);
   h_RBB__2->SetBinContent(31,1.345439e-05);
   h_RBB__2->SetBinContent(32,-4.437803e-06);
   h_RBB__2->SetBinContent(33,4.363963e-05);
   h_RBB__2->SetBinContent(34,-2.96128e-07);
   h_RBB__2->SetBinContent(37,0.007157029);
   h_RBB__2->SetBinContent(38,-0.08584426);
   h_RBB__2->SetBinContent(39,1.253657);
   h_RBB__2->SetBinContent(40,-0.09311129);
   h_RBB__2->SetBinContent(41,0.01650866);
   h_RBB__2->SetBinContent(42,-0.001088279);
   h_RBB__2->SetBinContent(43,-0.0001417685);
   h_RBB__2->SetBinContent(44,4.676099e-05);
   h_RBB__2->SetBinContent(45,-0.0004598294);
   h_RBB__2->SetBinContent(46,3.120292e-06);
   h_RBB__2->SetBinContent(49,-0.0006441314);
   h_RBB__2->SetBinContent(50,0.007634631);
   h_RBB__2->SetBinContent(51,-0.1198951);
   h_RBB__2->SetBinContent(52,1.415923);
   h_RBB__2->SetBinContent(53,-0.2511886);
   h_RBB__2->SetBinContent(54,0.01725117);
   h_RBB__2->SetBinContent(55,-0.0008718401);
   h_RBB__2->SetBinContent(56,4.796899e-05);
   h_RBB__2->SetBinContent(57,4.444259e-05);
   h_RBB__2->SetBinContent(58,-4.631958e-07);
   h_RBB__2->SetBinContent(61,6.332547e-05);
   h_RBB__2->SetBinContent(62,-0.0007135448);
   h_RBB__2->SetBinContent(63,0.0065476);
   h_RBB__2->SetBinContent(64,-0.1418777);
   h_RBB__2->SetBinContent(65,1.278707);
   h_RBB__2->SetBinContent(66,-0.08885165);
   h_RBB__2->SetBinContent(67,0.004587741);
   h_RBB__2->SetBinContent(68,-0.000271104);
   h_RBB__2->SetBinContent(69,-4.73074e-06);
   h_RBB__2->SetBinContent(70,8.695168e-07);
   h_RBB__2->SetBinContent(73,-2.071357e-05);
   h_RBB__2->SetBinContent(74,0.0002345709);
   h_RBB__2->SetBinContent(75,-0.002101555);
   h_RBB__2->SetBinContent(76,0.03188242);
   h_RBB__2->SetBinContent(77,-0.4078629);
   h_RBB__2->SetBinContent(78,1.522817);
   h_RBB__2->SetBinContent(79,-0.0799314);
   h_RBB__2->SetBinContent(80,0.004110052);
   h_RBB__2->SetBinContent(81,-8.578165e-05);
   h_RBB__2->SetBinContent(82,-1.377398e-05);
   h_RBB__2->SetBinContent(85,-4.980182e-06);
   h_RBB__2->SetBinContent(86,6.244554e-05);
   h_RBB__2->SetBinContent(87,-0.001144605);
   h_RBB__2->SetBinContent(88,-0.007938049);
   h_RBB__2->SetBinContent(89,0.07596582);
   h_RBB__2->SetBinContent(90,-0.3215933);
   h_RBB__2->SetBinContent(91,1.382221);
   h_RBB__2->SetBinContent(92,-0.0708788);
   h_RBB__2->SetBinContent(93,0.001548666);
   h_RBB__2->SetBinContent(94,-7.442967e-06);
   h_RBB__2->SetBinContent(97,-7.135417e-06);
   h_RBB__2->SetBinContent(98,8.533851e-05);
   h_RBB__2->SetBinContent(99,-0.001225296);
   h_RBB__2->SetBinContent(100,0.0008331625);
   h_RBB__2->SetBinContent(101,-0.006899298);
   h_RBB__2->SetBinContent(102,0.02936213);
   h_RBB__2->SetBinContent(103,-0.134908);
   h_RBB__2->SetBinContent(104,1.197622);
   h_RBB__2->SetBinContent(105,-0.0261704);
   h_RBB__2->SetBinContent(106,0.0001767254);
   h_RBB__2->SetBinContent(109,4.649755e-07);
   h_RBB__2->SetBinContent(110,-5.669905e-06);
   h_RBB__2->SetBinContent(111,9.059624e-05);
   h_RBB__2->SetBinContent(112,0.0002797869);
   h_RBB__2->SetBinContent(113,-0.002575386);
   h_RBB__2->SetBinContent(114,-0.002285961);
   h_RBB__2->SetBinContent(115,0.01151655);
   h_RBB__2->SetBinContent(116,-0.1042033);
   h_RBB__2->SetBinContent(117,1.191736);
   h_RBB__2->SetBinContent(118,-0.008060222);
   h_RBB__2->SetBinContent(121,-1.92269e-08);
   h_RBB__2->SetBinContent(122,2.344525e-07);
   h_RBB__2->SetBinContent(123,-3.746186e-06);
   h_RBB__2->SetBinContent(124,-1.156928e-05);
   h_RBB__2->SetBinContent(125,0.0001064931);
   h_RBB__2->SetBinContent(126,9.452528e-05);
   h_RBB__2->SetBinContent(127,-0.0004762135);
   h_RBB__2->SetBinContent(128,0.004308843);
   h_RBB__2->SetBinContent(129,-0.04927868);
   h_RBB__2->SetBinContent(130,1.101144);

   TH2F *h_RBB__3 = new TH2F("h_RBB__3","1.25 < |y| < 1.50",10, xAxis_AFB,10, xAxis_AFB);
   h_RBB__3->SetBinContent(13,1.329555);
   h_RBB__3->SetBinContent(14,-0.1764852);
   h_RBB__3->SetBinContent(15,0.01248956);
   h_RBB__3->SetBinContent(16,-0.001299145);
   h_RBB__3->SetBinContent(17,0.0002471679);
   h_RBB__3->SetBinContent(18,-2.116567e-05);
   h_RBB__3->SetBinContent(19,1.211101e-06);
   h_RBB__3->SetBinContent(20,-6.664664e-08);
   h_RBB__3->SetBinContent(21,2.620187e-09);
   h_RBB__3->SetBinContent(22,-7.716585e-11);
   h_RBB__3->SetBinContent(25,-0.1149259);
   h_RBB__3->SetBinContent(26,1.362823);
   h_RBB__3->SetBinContent(27,-0.09644467);
   h_RBB__3->SetBinContent(28,0.01003203);
   h_RBB__3->SetBinContent(29,-0.001908636);
   h_RBB__3->SetBinContent(30,0.0001634418);
   h_RBB__3->SetBinContent(31,-9.352149e-06);
   h_RBB__3->SetBinContent(32,5.146471e-07);
   h_RBB__3->SetBinContent(33,-2.023315e-08);
   h_RBB__3->SetBinContent(34,5.958766e-10);
   h_RBB__3->SetBinContent(37,0.007286716);
   h_RBB__3->SetBinContent(38,-0.09238167);
   h_RBB__3->SetBinContent(39,1.285677);
   h_RBB__3->SetBinContent(40,-0.1337342);
   h_RBB__3->SetBinContent(41,0.0254435);
   h_RBB__3->SetBinContent(42,-0.002178798);
   h_RBB__3->SetBinContent(43,0.0001246709);
   h_RBB__3->SetBinContent(44,-6.860617e-06);
   h_RBB__3->SetBinContent(45,2.697225e-07);
   h_RBB__3->SetBinContent(46,-7.943465e-09);
   h_RBB__3->SetBinContent(49,-0.001170958);
   h_RBB__3->SetBinContent(50,0.008266457);
   h_RBB__3->SetBinContent(51,-0.1269442);
   h_RBB__3->SetBinContent(52,1.46412);
   h_RBB__3->SetBinContent(53,-0.278555);
   h_RBB__3->SetBinContent(54,0.02385344);
   h_RBB__3->SetBinContent(55,-0.001364895);
   h_RBB__3->SetBinContent(56,7.510991e-05);
   h_RBB__3->SetBinContent(57,-2.952918e-06);
   h_RBB__3->SetBinContent(58,8.696492e-08);
   h_RBB__3->SetBinContent(61,8.438727e-05);
   h_RBB__3->SetBinContent(62,-0.0007177969);
   h_RBB__3->SetBinContent(63,0.008448225);
   h_RBB__3->SetBinContent(64,-0.1698304);
   h_RBB__3->SetBinContent(65,1.314694);
   h_RBB__3->SetBinContent(66,-0.1125809);
   h_RBB__3->SetBinContent(67,0.006441883);
   h_RBB__3->SetBinContent(68,-0.0003544956);
   h_RBB__3->SetBinContent(69,1.393686e-05);
   h_RBB__3->SetBinContent(70,-4.104476e-07);
   h_RBB__3->SetBinContent(73,-3.319173e-05);
   h_RBB__3->SetBinContent(74,0.0003689474);
   h_RBB__3->SetBinContent(75,-0.004735143);
   h_RBB__3->SetBinContent(76,0.04443313);
   h_RBB__3->SetBinContent(77,-0.460743);
   h_RBB__3->SetBinContent(78,1.553001);
   h_RBB__3->SetBinContent(79,-0.08997632);
   h_RBB__3->SetBinContent(80,0.00495138);
   h_RBB__3->SetBinContent(81,-0.0001946616);
   h_RBB__3->SetBinContent(82,5.732883e-06);
   h_RBB__3->SetBinContent(85,6.434858e-06);
   h_RBB__3->SetBinContent(86,-7.164553e-05);
   h_RBB__3->SetBinContent(87,0.0009342326);
   h_RBB__3->SetBinContent(88,-0.008074004);
   h_RBB__3->SetBinContent(89,0.08193827);
   h_RBB__3->SetBinContent(90,-0.3138528);
   h_RBB__3->SetBinContent(91,1.329496);
   h_RBB__3->SetBinContent(92,-0.07316191);
   h_RBB__3->SetBinContent(93,0.002876333);
   h_RBB__3->SetBinContent(94,-8.470947e-05);
   h_RBB__3->SetBinContent(97,-7.298091e-07);
   h_RBB__3->SetBinContent(98,8.128784e-06);
   h_RBB__3->SetBinContent(99,-0.000106384);
   h_RBB__3->SetBinContent(100,0.0009014687);
   h_RBB__3->SetBinContent(101,-0.009098284);
   h_RBB__3->SetBinContent(102,0.03593241);
   h_RBB__3->SetBinContent(103,-0.1853799);
   h_RBB__3->SetBinContent(104,1.210345);
   h_RBB__3->SetBinContent(105,-0.04758425);
   h_RBB__3->SetBinContent(106,0.00140138);
   h_RBB__3->SetBinContent(109,6.378946e-08);
   h_RBB__3->SetBinContent(110,-7.10502e-07);
   h_RBB__3->SetBinContent(111,9.298564e-06);
   h_RBB__3->SetBinContent(112,-7.879349e-05);
   h_RBB__3->SetBinContent(113,0.0007952418);
   h_RBB__3->SetBinContent(114,-0.003140697);
   h_RBB__3->SetBinContent(115,0.01620325);
   h_RBB__3->SetBinContent(116,-0.105791);
   h_RBB__3->SetBinContent(117,1.142127);
   h_RBB__3->SetBinContent(118,-0.03363621);
   h_RBB__3->SetBinContent(121,-5.5663e-09);
   h_RBB__3->SetBinContent(122,6.199875e-08);
   h_RBB__3->SetBinContent(123,-8.113973e-07);
   h_RBB__3->SetBinContent(124,6.875559e-06);
   h_RBB__3->SetBinContent(125,-6.939319e-05);
   h_RBB__3->SetBinContent(126,0.0002740588);
   h_RBB__3->SetBinContent(127,-0.001413904);
   h_RBB__3->SetBinContent(128,0.009231377);
   h_RBB__3->SetBinContent(129,-0.09966255);
   h_RBB__3->SetBinContent(130,1.198373);

   TH2F *h_RBB__4 = new TH2F("h_RBB__4","1.50 < |y| < 2.40",10, xAxis_AFB,10, xAxis_AFB);
   h_RBB__4->SetBinContent(13,1.353911);
   h_RBB__4->SetBinContent(14,-0.255378);
   h_RBB__4->SetBinContent(15,0.02959071);
   h_RBB__4->SetBinContent(16,-0.003325159);
   h_RBB__4->SetBinContent(17,0.0008174658);
   h_RBB__4->SetBinContent(18,-0.0001029993);
   h_RBB__4->SetBinContent(19,8.335898e-06);
   h_RBB__4->SetBinContent(20,-6.793846e-07);
   h_RBB__4->SetBinContent(21,2.4596e-08);
   h_RBB__4->SetBinContent(22,-5.369772e-10);
   h_RBB__4->SetBinContent(25,-0.1386603);
   h_RBB__4->SetBinContent(26,1.446311);
   h_RBB__4->SetBinContent(27,-0.1675844);
   h_RBB__4->SetBinContent(28,0.01883174);
   h_RBB__4->SetBinContent(29,-0.004629645);
   h_RBB__4->SetBinContent(30,0.0005833276);
   h_RBB__4->SetBinContent(31,-4.720963e-05);
   h_RBB__4->SetBinContent(32,3.847635e-06);
   h_RBB__4->SetBinContent(33,-1.392973e-07);
   h_RBB__4->SetBinContent(34,3.041123e-09);
   h_RBB__4->SetBinContent(37,0.009222833);
   h_RBB__4->SetBinContent(38,-0.1045058);
   h_RBB__4->SetBinContent(39,1.304886);
   h_RBB__4->SetBinContent(40,-0.1466322);
   h_RBB__4->SetBinContent(41,0.03604845);
   h_RBB__4->SetBinContent(42,-0.004542044);
   h_RBB__4->SetBinContent(43,0.0003675948);
   h_RBB__4->SetBinContent(44,-2.995937e-05);
   h_RBB__4->SetBinContent(45,1.08463e-06);
   h_RBB__4->SetBinContent(46,-2.367952e-08);
   h_RBB__4->SetBinContent(49,-0.001374931);
   h_RBB__4->SetBinContent(50,0.01199904);
   h_RBB__4->SetBinContent(51,-0.1627694);
   h_RBB__4->SetBinContent(52,1.531242);
   h_RBB__4->SetBinContent(53,-0.3764445);
   h_RBB__4->SetBinContent(54,0.04743138);
   h_RBB__4->SetBinContent(55,-0.003838697);
   h_RBB__4->SetBinContent(56,0.0003128579);
   h_RBB__4->SetBinContent(57,-1.132651e-05);
   h_RBB__4->SetBinContent(58,2.47279e-07);
   h_RBB__4->SetBinContent(61,0.0001009695);
   h_RBB__4->SetBinContent(62,-0.001665235);
   h_RBB__4->SetBinContent(63,0.01242761);
   h_RBB__4->SetBinContent(64,-0.2123974);
   h_RBB__4->SetBinContent(65,1.400428);
   h_RBB__4->SetBinContent(66,-0.1764515);
   h_RBB__4->SetBinContent(67,0.0142805);
   h_RBB__4->SetBinContent(68,-0.001163876);
   h_RBB__4->SetBinContent(69,4.213622e-05);
   h_RBB__4->SetBinContent(70,-9.199134e-07);
   h_RBB__4->SetBinContent(73,-3.89977e-05);
   h_RBB__4->SetBinContent(74,0.0005411739);
   h_RBB__4->SetBinContent(75,-0.005453635);
   h_RBB__4->SetBinContent(76,0.05908541);
   h_RBB__4->SetBinContent(77,-0.5181559);
   h_RBB__4->SetBinContent(78,1.61608);
   h_RBB__4->SetBinContent(79,-0.1313172);
   h_RBB__4->SetBinContent(80,0.01069601);
   h_RBB__4->SetBinContent(81,-0.0003872314);
   h_RBB__4->SetBinContent(82,8.453992e-06);
   h_RBB__4->SetBinContent(85,9.081698e-05);
   h_RBB__4->SetBinContent(86,-0.0009422141);
   h_RBB__4->SetBinContent(87,-0.001392729);
   h_RBB__4->SetBinContent(88,-0.01582581);
   h_RBB__4->SetBinContent(89,0.1032294);
   h_RBB__4->SetBinContent(90,-0.3740381);
   h_RBB__4->SetBinContent(91,1.422598);
   h_RBB__4->SetBinContent(92,-0.1158701);
   h_RBB__4->SetBinContent(93,0.004194887);
   h_RBB__4->SetBinContent(94,-9.158232e-05);
   h_RBB__4->SetBinContent(97,-1.88049e-05);
   h_RBB__4->SetBinContent(98,0.0001972017);
   h_RBB__4->SetBinContent(99,0.0004082319);
   h_RBB__4->SetBinContent(100,0.001249128);
   h_RBB__4->SetBinContent(101,-0.01458239);
   h_RBB__4->SetBinContent(102,0.04378653);
   h_RBB__4->SetBinContent(103,-0.195867);
   h_RBB__4->SetBinContent(104,1.216537);
   h_RBB__4->SetBinContent(105,-0.04404272);
   h_RBB__4->SetBinContent(106,0.0009615358);
   h_RBB__4->SetBinContent(109,0.0001902333);
   h_RBB__4->SetBinContent(110,-0.001966422);
   h_RBB__4->SetBinContent(111,-0.002594908);
   h_RBB__4->SetBinContent(112,0.0002224714);
   h_RBB__4->SetBinContent(113,0.00089731);
   h_RBB__4->SetBinContent(114,-0.002739669);
   h_RBB__4->SetBinContent(115,0.01291402);
   h_RBB__4->SetBinContent(116,-0.1017792);
   h_RBB__4->SetBinContent(117,1.139543);
   h_RBB__4->SetBinContent(118,-0.02487837);
   h_RBB__4->SetBinContent(121,-1.023285e-05);
   h_RBB__4->SetBinContent(122,0.0001057714);
   h_RBB__4->SetBinContent(123,0.000139342);
   h_RBB__4->SetBinContent(124,-1.398495e-05);
   h_RBB__4->SetBinContent(125,-2.525769e-05);
   h_RBB__4->SetBinContent(126,7.828602e-05);
   h_RBB__4->SetBinContent(127,-0.0003857352);
   h_RBB__4->SetBinContent(128,0.003559459);
   h_RBB__4->SetBinContent(129,-0.06140612);
   h_RBB__4->SetBinContent(130,1.055411);

//electron total systematics
   TGraph *graph_ee1p = new TGraph(12);
   graph_ee1p->SetName("Graph");
   graph_ee1p->SetTitle("Graph");
   graph_ee1p->SetFillColor(1);
   graph_ee1p->SetMarkerColor(46);
   graph_ee1p->SetMarkerStyle(28);
   graph_ee1p->SetPoint(0,37.65653,0.02184903);
   graph_ee1p->SetPoint(1,46.22267,0.01130844);
   graph_ee1p->SetPoint(2,55.14681,0.005795063);
   graph_ee1p->SetPoint(3,68.87928,0.0041922);
   graph_ee1p->SetPoint(4,82.57219,0.003137779);
   graph_ee1p->SetPoint(5,91.16829,0.001414742);
   graph_ee1p->SetPoint(6,99.30242,0.002338209);
   graph_ee1p->SetPoint(7,111.5845,0.004852891);
   graph_ee1p->SetPoint(8,131.6597,0.01149089);
   graph_ee1p->SetPoint(9,169.4964,0.03099402);
   graph_ee1p->SetPoint(10,284.1778,0.04299469);

   TGraph *graph_ee1m = new TGraph(12);
   graph_ee1m->SetName("Graph");
   graph_ee1m->SetTitle("Graph");
   graph_ee1m->SetPoint(0,37.65653,-0.00212277);
   graph_ee1m->SetPoint(1,46.22267,-0.01216276);
   graph_ee1m->SetPoint(2,55.14681,-0.003553807);
   graph_ee1m->SetPoint(3,68.87928,-0.00188077);
   graph_ee1m->SetPoint(4,82.57219,-0.00247024);
   graph_ee1m->SetPoint(5,91.16829,-0.0003634635);
   graph_ee1m->SetPoint(6,99.30242,-0.003254301);
   graph_ee1m->SetPoint(7,111.5845,-0.005220941);
   graph_ee1m->SetPoint(8,131.6597,-0.008033601);
   graph_ee1m->SetPoint(9,169.4964,-0.02384241);
   graph_ee1m->SetPoint(10,284.1778,-0.02625386);

   TGraph *graph_ee2p = new TGraph(12);
   graph_ee2p->SetName("Graph");
   graph_ee2p->SetTitle("Graph");
   graph_ee2p->SetPoint(0,37.61235,0.07882547);
   graph_ee2p->SetPoint(1,46.20211,0.01248767);
   graph_ee2p->SetPoint(2,55.15172,0.00627542);
   graph_ee2p->SetPoint(3,68.89547,0.01629258);
   graph_ee2p->SetPoint(4,82.58346,0.009790954);
   graph_ee2p->SetPoint(5,91.16965,0.001881997);
   graph_ee2p->SetPoint(6,99.3086,0.0197535);
   graph_ee2p->SetPoint(7,111.6251,0.009737397);
   graph_ee2p->SetPoint(8,131.6069,0.01389175);
   graph_ee2p->SetPoint(9,168.9787,0.02911937);
   graph_ee2p->SetPoint(10,269.5577,0.03126372);

   TGraph *graph_ee2m = new TGraph(12);
   graph_ee2m->SetName("Graph");
   graph_ee2m->SetTitle("Graph");
   graph_ee2m->SetFillColor(1);
   graph_ee2m->SetMarkerColor(46);
   graph_ee2m->SetMarkerStyle(28);
   graph_ee2m->SetPoint(0,37.61235,-0.06469753);
   graph_ee2m->SetPoint(1,46.20211,-0.01669112);
   graph_ee2m->SetPoint(2,55.15172,-0.01833757);
   graph_ee2m->SetPoint(3,68.89547,-0.01064684);
   graph_ee2m->SetPoint(4,82.58346,-0.006018695);
   graph_ee2m->SetPoint(5,91.16965,-0.001038346);
   graph_ee2m->SetPoint(6,99.3086,-0.01180344);
   graph_ee2m->SetPoint(7,111.6251,-0.009074448);
   graph_ee2m->SetPoint(8,131.6069,-0.01298305);
   graph_ee2m->SetPoint(9,168.9787,-0.01717682);
   graph_ee2m->SetPoint(10,269.5577,-0.02817502);

   TGraph *graph_ee3p = new TGraph(12);
   graph_ee3p->SetName("Graph");
   graph_ee3p->SetTitle("Graph");
   graph_ee3p->SetFillColor(1);
   graph_ee3p->SetMarkerColor(46);
   graph_ee3p->SetMarkerStyle(28);
   graph_ee3p->SetPoint(0,37.68314,0.06532624);
   graph_ee3p->SetPoint(1,46.39925,0.03351267);
   graph_ee3p->SetPoint(2,55.32642,0.02461323);
   graph_ee3p->SetPoint(3,68.95133,0.02675579);
   graph_ee3p->SetPoint(4,82.57803,0.01884848);
   graph_ee3p->SetPoint(5,91.16344,0.001465283);
   graph_ee3p->SetPoint(6,99.30788,0.01817412);
   graph_ee3p->SetPoint(7,111.5838,0.01845624);
   graph_ee3p->SetPoint(8,131.7248,0.02972315);
   graph_ee3p->SetPoint(9,169.6304,0.02623899);
   graph_ee3p->SetPoint(10,267.3923,0.0530885);

   TGraph *graph_ee3m = new TGraph(12);
   graph_ee3m->SetName("Graph");
   graph_ee3m->SetTitle("Graph");
   graph_ee3m->SetPoint(0,37.68314,-0.04037242);
   graph_ee3m->SetPoint(1,46.39925,-0.008561511);
   graph_ee3m->SetPoint(2,55.32642,-0.0322174);
   graph_ee3m->SetPoint(3,68.95133,-0.007216705);
   graph_ee3m->SetPoint(4,82.57803,-0.02079959);
   graph_ee3m->SetPoint(5,91.16344,-0.001798638);
   graph_ee3m->SetPoint(6,99.30788,-0.01285082);
   graph_ee3m->SetPoint(7,111.5838,-0.005387958);
   graph_ee3m->SetPoint(8,131.7248,-0.01665481);
   graph_ee3m->SetPoint(9,169.6304,-0.02603562);
   graph_ee3m->SetPoint(10,267.3923,-0.04740732);



   TGraph *graph_ee4p = new TGraph(12);
   graph_ee4p->SetName("Graph");
   graph_ee4p->SetTitle("Graph");
   graph_ee4p->SetPoint(0,37.73418,0.1128376);
   graph_ee4p->SetPoint(1,46.30013,0.05739409);
   graph_ee4p->SetPoint(2,55.12051,0.01977302);
   graph_ee4p->SetPoint(3,68.83578,0.02224735);
   graph_ee4p->SetPoint(4,82.57095,0.02700118);
   graph_ee4p->SetPoint(5,91.16083,0.001500927);
   graph_ee4p->SetPoint(6,99.29644,0.05070191);
   graph_ee4p->SetPoint(7,111.7024,0.01461224);
   graph_ee4p->SetPoint(8,131.5414,0.0223309);
   graph_ee4p->SetPoint(9,169.7365,0.03394256);
   graph_ee4p->SetPoint(10,260.4229,0.02809115);

   TGraph *graph_ee4m = new TGraph(12);
   graph_ee4m->SetName("Graph");
   graph_ee4m->SetTitle("Graph");
   graph_ee4m->SetPoint(0,37.73418,-0.02553291);
   graph_ee4m->SetPoint(1,46.30013,-0.02100379);
   graph_ee4m->SetPoint(2,55.12051,-0.02755638);
   graph_ee4m->SetPoint(3,68.83578,-0.01917079);
   graph_ee4m->SetPoint(4,82.57095,-0.02971931);
   graph_ee4m->SetPoint(5,91.16083,-0.001253668);
   graph_ee4m->SetPoint(6,99.29644,-0.02366753);
   graph_ee4m->SetPoint(7,111.7024,-0.022714);
   graph_ee4m->SetPoint(8,131.5414,-0.02190383);
   graph_ee4m->SetPoint(9,169.7365,-0.008396404);
   graph_ee4m->SetPoint(10,260.4229,-0.03061301);

//

   double xee1m[nb], xee2m[nb], xee3m[nb], xee4m[nb];
   double xee1p[nb], xee2p[nb], xee3p[nb], xee4p[nb];
   double yee1m[nb], yee2m[nb], yee3m[nb], yee4m[nb];
   double yee1p[nb], yee2p[nb], yee3p[nb], yee4p[nb];

   for (int i=0;i<nb;i++){
     graph_ee1m->GetPoint(i,xee1m[i],yee1m[i]);
     graph_ee2m->GetPoint(i,xee2m[i],yee2m[i]);
     graph_ee3m->GetPoint(i,xee3m[i],yee3m[i]);
     graph_ee4m->GetPoint(i,xee4m[i],yee4m[i]);

     graph_ee1p->GetPoint(i,xee1p[i],yee1p[i]);
     graph_ee2p->GetPoint(i,xee2p[i],yee2p[i]);
     graph_ee3p->GetPoint(i,xee3p[i],yee3p[i]);
     graph_ee4p->GetPoint(i,xee4p[i],yee4p[i]);
   }

  //eof electron channel results


  //BACKGROUNDS //2.1 fb-1

  float qcd_plus_2011A[10][4]={{14.1947,3.80381,2.96883,5.10267},{24.7305,6.62714,5.1724,8.89006},{37.1178,9.94661,7.76321,13.343},{19.5588,4.47731,2.35648,2.59213},{15.0788,3.45178,1.81673,1.9984},{11.7462,2.68889,1.4152,1.55672},{12.5866,2.03419,0.889958,0.762821},{13.9642,2.25684,0.987367,0.846314},{7.9527,1.28528,0.562312,0.481982},{4.63386,0.748906,0.327646,0.28084}};

  float comb_plus_2011A[10][4]={{171.662,37.655,33.7355,54.4926},{319.456,73.0219,67.1609,113.974},{407.06,89.353,79.8504,128.537},{146.784,29.0266,21.8887,25.4481},{261.422,53.8919,42.6497,56.7785},{95.8057,18.031,12.343,12.7409},{122.113,16.0434,9.78513,7.15538},{180.854,22.5459,13.5275,9.57671},{141.315,17.5445,10.664,7.6098},{101.406,12.9598,8.03124,5.74444}};

  float qcd_minus_2011A[10][4]={{15.5985,4.17998,3.26242,5.60729},{25.933,6.94938,5.4239,9.32233},{39.4549,10.5729,8.25201,14.1831},{20.5885,4.71304,2.48055,2.7286},{15.6808,3.58958,1.88925,2.07818},{12.7481,2.91825,1.53592,1.68951},{11.5247,1.86257,0.814876,0.698465},{14.0628,2.27278,0.994342,0.852293},{9.46669,1.52997,0.669362,0.573739},{4.73335,0.764985,0.334681,0.28687}};

  float comb_minus_2011A[10][4]={{178.123,39.0856,34.5673,55.7561},{311.009,71.031,65.6042,111.014},{391.258,86.3479,77.2648,124.743},{167.578,32.2807,23.4135,25.7672},{256.826,52.7509,41.3442,54.8177},{97.4771,18.2736,12.2969,12.4914},{117.826,15.2214,9.20724,6.63345},{179.669,22.7827,13.7211,9.57998},{167.224,20.2574,12.0382,8.22751},{94.3012,11.8094,7.22729,5.14524}};
  //----eof 2.1 fb-1

  float qcd_plus[10][4]={{90,17,24,47},{111,31,25,44},{129,38,25,43},{74,12,11,18},{56,16,8,11},{38,9,5,6},{56,17,3,2},{61,9,7,5},{59,3,6,4},{42,2,2,4}};
  float qcd_minus[10][4];
  float comb_plus[10][4];
  float comb_minus[10][4];
  for (int i=0;i<4;i++){
	for (int j=0;j<10;j++){
		qcd_plus[j][i] = qcd_plus[j][i]/2.;
                qcd_minus[j][i] = qcd_plus[j][i]; 
                comb_plus[j][i] = (4.7/2.1)*(comb_plus_2011A[j][i] - qcd_plus_2011A[j][i]) + qcd_plus[j][i];
                comb_minus[j][i] = (4.7/2.1)*(comb_minus_2011A[j][i] - qcd_minus_2011A[j][i]) + qcd_minus[j][i];
	} 
  } 

  float comb_plus_qcd_up[11][4];
  float comb_minus_qcd_up[11][4];
  float comb_plus_qcd_down[11][4];
  float comb_minus_qcd_down[11][4];

  float qcd_scale = 100.;//100%
  for (int i=0;i<nb;i++){
    for (int j=0;j<nb_Y;j++){
      comb_plus_qcd_up[i][j] = comb_plus[i][j] - qcd_plus[i][j] + (1.+qcd_scale/100.)*qcd_plus[i][j]; 
      comb_minus_qcd_up[i][j] = comb_minus[i][j] - qcd_minus[i][j] + (1.+qcd_scale/100.)*qcd_minus[i][j]; 
      comb_plus_qcd_down[i][j] = comb_plus[i][j] - qcd_plus[i][j] + (1.-qcd_scale/100.)*qcd_plus[i][j]; 
      comb_minus_qcd_down[i][j] = comb_minus[i][j] - qcd_minus[i][j] + (1.-qcd_scale/100.)*qcd_minus[i][j]; 
    }
  }
  //



  int n_ct = 53;
  int n_mstw = 41;
  int n_nnpdf = 101;


  int ct10as_index = 11;//ct10weights 0 to 10 are alphas uncertainties in the ct10as file 

  int nPDF; ///!!!
  //pdf set 0: CT10, 1: nnpdf, 2: MSTW, 3: CT10as
  int pdf_set = 0;
  
  if (pdf_set == 0){ 
	cout<<"PDF SET :  CT10"<<endl;
	nPDF = n_ct;
  }
  if (pdf_set == 1){ 
	cout<<"PDF SET :  NNPDF"<<endl;
        nPDF = n_nnpdf;
  }
  if (pdf_set == 2){ 
	cout<<"PDF SET :  MSTW"<<endl;
        nPDF = n_mstw;
  } 
  if (pdf_set == 3){
    cout<<"PDF SET : CT10 alphas"<<endl;//MSTW in the root file = ct10as
	nPDF = ct10as_index;
  }

  TH1D *hMeasCos_M_Y_Forward_PDF_ct10[nb_Y][n_ct];
  TH1D *hMeasCos_M_Y_Backward_PDF_ct10[nb_Y][n_ct];
  TH2D *Inv_Response_UnDetector_Forward_PDF_ct10[nb_Y];
  TH2D *Inv_Response_UnDetector_Backward_PDF_ct10[nb_Y];
  TH2D *Inv_Response_NoFsr_Forward_PDF_ct10[nb_Y];
  TH2D *Inv_Response_NoFsr_Backward_PDF_ct10[nb_Y];

  TH1D *hMeasCos_M_Y_Forward_PDF_mstw[nb_Y][n_mstw];
  TH1D *hMeasCos_M_Y_Backward_PDF_mstw[nb_Y][n_mstw];


  TH1D *hMeasCos_M_Y_Forward_PDF_nnpdf[nb_Y][n_nnpdf];
  TH1D *hMeasCos_M_Y_Backward_PDF_nnpdf[nb_Y][n_nnpdf];


  TH1D *hMeasCos_M_Y_Forward_PDF_alpha_s[nb_Y][ct10as_index];
  TH1D *hMeasCos_M_Y_Backward_PDF_alpha_s[nb_Y][ct10as_index];



  float delta_plus = -999.;
  float delta_minus = -999.;
  float afb_p = -999.;
  float afb_m = -999.;
  float afb_0 = -999.;
  float afb_0_mstw = -999.;
  float afb_nnpdf = -999.;
  float afb_alphas0 = -999.;
  float afb_alphas5 = -999.;
  float afb_alphas10 = -999.;

  float DeltaXmaxPlus[nb][nb_Y];
  float DeltaXmaxMinus[nb][nb_Y];
  float sigma[nb][nb_Y];

  float delta_plus_undet = -999.;
  float delta_minus_undet = -999.;
  float afb_p_undet = -999.;
  float afb_m_undet = -999.;
  float afb_0_undet = -999.;



  float DeltaXmaxPlus_undet[nb][nb_Y];
  float DeltaXmaxMinus_undet[nb][nb_Y];
  float sigma_undet[nb][nb_Y];


//  TFile input_fsr_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated.root","read");
//  TFile input_fsr_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_plus_highmass.root","read"); 

//  TFile input_fsr_file("RootFiles/MC_Meas_UnDetector_NoFsr_DYbins_Updated_plus_highmass_eff_pu.root","read");
//  TFile input_fsr_file("RootFiles/MC_Meas_UnDetector_NoFsr_DYbins_Updated_plus_highmass_eff_pu_bincentering.root","read");

//====> for eta<2.1  
//TFile input_fsr_file("RootFiles/MC_Meas_UnDetector_NoFsr_DYbins_Updated_plus_highmass_eff_pu_bincentering_new.root","read");
//eof 2.1

//  TFile input_fsr_file("RootFiles/MC_Meas_UnDetector_NoFsr_Y25_eta24.root","read");

//--->  TFile input_fsr_file("RootFiles/MC_Y25_eta24_Weights.root","read"); 


//----> 
TFile input_fsr_file("RootFiles/MC_Y25_eta24_Official_Weights.root","read");

  //TFile input_fsr_file("RootFiles/MC_Y21_eta21_Weights.root","read");
 
//  TFile input_fsr_file("RootFiles/test_with_nonenergyconsevts.root","read");

// TFile input_fsr_file("RootFiles/MC_Y25_eta24_Weights_wo_parton_weight.root","read");
//TFile input_fsr_file("RootFiles/MC_Y25_eta24_Weights_noconst.root","read");

//  TFile input_fsr_file("TEST_MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_plus_highmass.root","read");
//TFile input_fsr_file("TEST_YLAST_1_75_MC_Meas_UnDetector_NoFsr_DYbins_Updated_plus_highmass_eff_pu.root","read");

////  TFile input_data_file("RootFiles/MUON_DATA_DYbins.root","read");
//
 //===> For eta<2.1 TFile input_data_file("RootFiles/Data_output_new_2fb.root","read");
  //TFile input_data_file("RootFiles/Data_output_new_2fb_eta24_Y25.root","read");
  //TFile input_data_file("RootFiles/Data_output_new_2fb_eta24_Y25_w_HLT.root","read");


//===========>>>>>  TFile input_data_file("RootFiles/Data_output_new_2fb_eta24_Y24_w_HLT.root","read");
//   TFile input_data_file("RootFiles/Data_output_new_2fb_eta21_Y21.root","read");
 TFile input_data_file("RootFiles/Data_output_new_5fb_eta24_Y24.root","read");


  //TFile input_data_file("RootFiles/RELVAL_OLD_Data_output_new_2fb.root","read");
  //TFile input_data_file("RootFiles/RELVAL_NEW_Data_output_new_2fb.root","read");
  


  TFile input_sin2312_file("RootFiles/sin2thetaW2312_MUON_MC_Meas_NoFsr.root","read");
  TFile input_sin2412_file("RootFiles/sin2thetaW2412_MUON_MC_Meas_NoFsr.root","read");
  TFile input_sin2212_file("RootFiles/sin2thetaW2212_MUON_MC_Meas_NoFsr.root","read");
  TFile input_Align_Bowing_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Bowing.root","read");
  TFile input_Align_Elliptical_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Elliptical.root","read");
  TFile input_Align_Radial_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Radial.root","read");
  TFile input_Align_Sagitta_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Sagitta.root","read");
  TFile input_Align_Skew_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Skew.root","read");
  TFile input_Align_Telescope_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Telescope.root","read");
  TFile input_Align_CurlV2TF_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_CurlV2TF.root","read");
  TFile input_Align_Twist_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Twist.root","read");
  TFile input_Align_Zexpansion_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Zexpansion.root","read");
  //  TFile input_Align_Ideal_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Ideal.root","read");
  TFile input_Align_Ideal_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Ideal_plus_finebin.root","read");
  TFile input_Align_Startup_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_Startup.root","read");
  //  TFile input_PDF_ct10_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_CT10.root","read");
  TFile input_PDF_ct10_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_CT10_new.root","read");
  //  TFile input_PDF_mstw_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_MSTW.root","read");
  TFile input_PDF_mstw_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_MSTW_new.root","read");
  //  TFile input_PDF_nnpdf_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_NNPDF.root","read");
  TFile input_PDF_nnpdf_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_NNPDF_new.root","read");
  //  TFile input_PDF_alpha_s_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_ALPHA_S.root","read");
  TFile input_PDF_alpha_s_file("RootFiles/MUON_MC_Meas_UnDetector_NoFsr_DYbins_Updated_ALPHA_S_new.root","read");//OK

  for (int j=0;j<nb_Y;j++){
    sprintf(name_h,"MC_meas_Forward_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[j],Y_bin_limits[j+1]);
    hMeasCos_M_Y_Forward[j]->SetTitle(name_h);
    sprintf(name_h,"MC_meas_Backward_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Backward[j]);
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[j],Y_bin_limits[j+1]);
    hMeasCos_M_Y_Backward[j]->SetTitle(name_h);

    sprintf(name_h,"MC_meas_Forward_NoWeight_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Forward_NoWeight[j]);
    sprintf(name_h,"MC_meas_Backward_NoWeight_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Backward_NoWeight[j]);


    sprintf(name_h,"MC_true_Forward_%i",j);
    input_fsr_file.GetObject(name_h,hTrueCos_M_Y_Forward[j]);
    sprintf(name_h,"MC_true_Backward_%i",j);
    input_fsr_file.GetObject(name_h,hTrueCos_M_Y_Backward[j]);

    for (int ii=0;ii<nb;ii++){
      sprintf(name_h,"hExpectedMass_RAW_M_Y_%i_%i",j,ii);
      input_fsr_file.GetObject(name_h,hExpectedMass_RAW_M_Y[j][ii]);
      sprintf(name_h,"hExpectedMass_UnDet_M_Y_%i_%i",j,ii);
      input_fsr_file.GetObject(name_h,hExpectedMass_UnDet_M_Y[j][ii]);
      sprintf(name_h,"hExpectedMass_NoFsr_M_Y_%i_%i",j,ii);
      input_fsr_file.GetObject(name_h,hExpectedMass_NoFsr_M_Y[j][ii]);


    }

    sprintf(name_h,"MC_meas_Forward_FSR_UP_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Forward_FSR_UP[j]);
    sprintf(name_h,"MC_meas_Backward_FSR_UP_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Backward_FSR_UP[j]);
    sprintf(name_h,"MC_meas_Forward_FSR_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Forward_FSR_DOWN[j]);
    sprintf(name_h,"MC_meas_Backward_FSR_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Backward_FSR_DOWN[j]);

//
    sprintf(name_h,"MC_meas_Forward_ES_UP_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Forward_ES_UP[j]);
    sprintf(name_h,"MC_meas_Backward_ES_UP_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Backward_ES_UP[j]);
    sprintf(name_h,"MC_meas_Forward_ES_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Forward_ES_DOWN[j]);
    sprintf(name_h,"MC_meas_Backward_ES_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,hMeasCos_M_Y_Backward_ES_DOWN[j]);
//

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

    sprintf(name_h,"response_nofsr_forwardbackward_%i",j);
    input_fsr_file.GetObject(name_h,Response_NoFsr_ForwardBackward[j]);
    sprintf(name_h,"response_nofsr_backwardforward_%i",j);
    input_fsr_file.GetObject(name_h,Response_NoFsr_BackwardForward[j]);

    sprintf(name_h,"response_nofsr_forward_no_norm_%i",j);
    input_fsr_file.GetObject(name_h,Response_NoFsr_Forward_NO_NORM[j]);
    sprintf(name_h,"response_nofsr_backward_no_norm_%i",j);
    input_fsr_file.GetObject(name_h,Response_NoFsr_Backward_NO_NORM[j]);

    sprintf(name_h,"response_nofsr_forwardbackward_no_norm_%i",j);
    input_fsr_file.GetObject(name_h,Response_NoFsr_ForwardBackward_NO_NORM[j]);
    sprintf(name_h,"response_nofsr_backwardforward_no_norm_%i",j);
    input_fsr_file.GetObject(name_h,Response_NoFsr_BackwardForward_NO_NORM[j]);

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

    sprintf(name_h,"inv_response_undet_forward_FSR_UP_%i",j);
    input_fsr_file.GetObject(name_h,Inv_Response_UnDet_Forward_FSR_UP[j]);
    sprintf(name_h,"inv_response_undet_backward_FSR_UP_%i",j);
    input_fsr_file.GetObject(name_h,Inv_Response_UnDet_Backward_FSR_UP[j]);
    sprintf(name_h,"inv_response_undet_forward_FSR_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,Inv_Response_UnDet_Forward_FSR_DOWN[j]);
    sprintf(name_h,"inv_response_undet_backward_FSR_DOWN_%i",j);
    input_fsr_file.GetObject(name_h,Inv_Response_UnDet_Backward_FSR_DOWN[j]);



    sprintf(name_h,"MC_DATA_meas_Forward_%i",j);
    input_data_file.GetObject(name_h,hDataMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"MC_DATA_meas_Backward_%i",j);
    input_data_file.GetObject(name_h,hDataMeasCos_M_Y_Backward[j]);

    //relval
    sprintf(name_h,"MC_DATA_meas_Forward_FineBin%i",j);
    input_data_file.GetObject(name_h,hDataMeasCos_M_Y_Forward_FineBin[j]);
    sprintf(name_h,"MC_DATA_meas_Backward_FineBin%i",j);
    input_data_file.GetObject(name_h,hDataMeasCos_M_Y_Backward_FineBin[j]);
    //end of relval


    sprintf(name_h,"MC_meas_Forward_bkg_%i",j);
    hMeasCos_M_Y_Forward_bkg[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_meas_Backward_bkg_%i",j);
    hMeasCos_M_Y_Backward_bkg[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"MC_meas_Forward_bkg_UP_%i",j);
    hMeasCos_M_Y_Forward_bkg_UP[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_meas_Backward_bkg_UP_%i",j);
    hMeasCos_M_Y_Backward_bkg_UP[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_meas_Forward_bkg_DOWN_%i",j);
    hMeasCos_M_Y_Forward_bkg_DOWN[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_meas_Backward_bkg_DOWN_%i",j);
    hMeasCos_M_Y_Backward_bkg_DOWN[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    //background subtraction
    float luminosity_scale_factor = 2.1/2.2;
    float luminosity_scale_factor_MC = 17.4/2.2;
    /*
    luminosity_scale_factor = 0;
    cout<<"LUMINOSITY SCALE FACTOR ===== 0!!!!"<<endl;
    cout<<"!!!!!!!!!!!!"<<endl;
    */
    for (int ijk = 0;ijk<nb;ijk++){
      float back_subed_signal_plus = hDataMeasCos_M_Y_Forward[j]->GetBinContent(ijk+1) - luminosity_scale_factor*comb_plus[ijk][j];
      hDataMeasCos_M_Y_Forward[j]->SetBinContent(ijk+1,back_subed_signal_plus);
      float back_subed_signal_minus = hDataMeasCos_M_Y_Backward[j]->GetBinContent(ijk+1) - luminosity_scale_factor*comb_minus[ijk][j];
      hDataMeasCos_M_Y_Backward[j]->SetBinContent(ijk+1,back_subed_signal_minus);


      float back_subed_signal_plus_MC = hMeasCos_M_Y_Forward[j]->GetBinContent(ijk+1) + luminosity_scale_factor_MC*comb_plus[ijk][j];
      float back_subed_signal_minus_MC = hMeasCos_M_Y_Backward[j]->GetBinContent(ijk+1) + luminosity_scale_factor_MC*comb_minus[ijk][j];
      hMeasCos_M_Y_Forward_bkg[j]->SetBinContent(ijk+1,back_subed_signal_plus_MC);
      hMeasCos_M_Y_Backward_bkg[j]->SetBinContent(ijk+1,back_subed_signal_minus_MC);

      back_subed_signal_plus_MC += luminosity_scale_factor_MC*comb_plus[ijk][j];
      back_subed_signal_minus_MC += luminosity_scale_factor_MC*comb_minus[ijk][j];


      float back_subed_signal_plus_UP = back_subed_signal_plus_MC - luminosity_scale_factor_MC*comb_plus_qcd_up[ijk][j];
      hMeasCos_M_Y_Forward_bkg_UP[j]->SetBinContent(ijk+1,back_subed_signal_plus_UP);
      float back_subed_signal_plus_DOWN = back_subed_signal_plus_MC - luminosity_scale_factor_MC*comb_plus_qcd_down[ijk][j];
      hMeasCos_M_Y_Forward_bkg_DOWN[j]->SetBinContent(ijk+1,back_subed_signal_plus_DOWN);
      float back_subed_signal_minus_UP = back_subed_signal_minus_MC - luminosity_scale_factor_MC*comb_minus_qcd_up[ijk][j];
      hMeasCos_M_Y_Backward_bkg_UP[j]->SetBinContent(ijk+1,back_subed_signal_minus_UP);
      float back_subed_signal_minus_DOWN = back_subed_signal_minus_MC - luminosity_scale_factor_MC*comb_minus_qcd_down[ijk][j];
      hMeasCos_M_Y_Backward_bkg_DOWN[j]->SetBinContent(ijk+1,back_subed_signal_minus_DOWN);
    }
    //end of background subtraction


    //sin2thetaW 2312
    sprintf(name_h,"Sin2312_MC_meas_Forward_%i",j);
    input_sin2312_file.GetObject(name_h,h_Sin2312_MeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Sin2312_MC_meas_Backward_%i",j);
    input_sin2312_file.GetObject(name_h,h_Sin2312_MeasCos_M_Y_Backward[j]);

    sprintf(name_h,"SinTrue2312_MC_meas_Forward_%i",j);
    input_sin2312_file.GetObject(name_h,h_SinTrue2312_MeasCos_M_Y_Forward[j]);
    sprintf(name_h,"SinTrue2312_MC_meas_Backward_%i",j);
    input_sin2312_file.GetObject(name_h,h_SinTrue2312_MeasCos_M_Y_Backward[j]);

    sprintf(name_h,"SinTrue2212_MC_meas_Forward_%i",j);
    input_sin2212_file.GetObject(name_h,h_SinTrue2212_MeasCos_M_Y_Forward[j]);
    sprintf(name_h,"SinTrue2212_MC_meas_Backward_%i",j);
    input_sin2212_file.GetObject(name_h,h_SinTrue2212_MeasCos_M_Y_Backward[j]);

    sprintf(name_h,"SinTrue2412_MC_meas_Forward_%i",j);
    input_sin2412_file.GetObject(name_h,h_SinTrue2412_MeasCos_M_Y_Forward[j]);
    sprintf(name_h,"SinTrue2412_MC_meas_Backward_%i",j);
    input_sin2412_file.GetObject(name_h,h_SinTrue2412_MeasCos_M_Y_Backward[j]);


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

    //Align_Bowing
    sprintf(name_h,"Align_Bowing_MC_meas_Forward_%i",j);
    input_Align_Bowing_file.GetObject(name_h,Align_Bowing_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Bowing_MC_meas_Backward_%i",j);
    input_Align_Bowing_file.GetObject(name_h,Align_Bowing_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Bowing_inv_response_undetector_forward_%i",j);
    input_Align_Bowing_file.GetObject(name_h,Align_Bowing_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Bowing_inv_response_undetector_backward_%i",j);
    input_Align_Bowing_file.GetObject(name_h,Align_Bowing_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Bowing_inv_response_nofsr_forward_%i",j);
    input_Align_Bowing_file.GetObject(name_h,Align_Bowing_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Bowing_inv_response_nofsr_backward_%i",j);
    input_Align_Bowing_file.GetObject(name_h,Align_Bowing_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Bowing

 
    //Align_Elliptical
    sprintf(name_h,"Align_Elliptical_MC_meas_Forward_%i",j);
    input_Align_Elliptical_file.GetObject(name_h,Align_Elliptical_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Elliptical_MC_meas_Backward_%i",j);
    input_Align_Elliptical_file.GetObject(name_h,Align_Elliptical_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Elliptical_inv_response_undetector_forward_%i",j);
    input_Align_Elliptical_file.GetObject(name_h,Align_Elliptical_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Elliptical_inv_response_undetector_backward_%i",j);
    input_Align_Elliptical_file.GetObject(name_h,Align_Elliptical_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Elliptical_inv_response_nofsr_forward_%i",j);
    input_Align_Elliptical_file.GetObject(name_h,Align_Elliptical_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Elliptical_inv_response_nofsr_backward_%i",j);
    input_Align_Elliptical_file.GetObject(name_h,Align_Elliptical_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Elliptical

    //Align_Radial
    sprintf(name_h,"Align_Radial_MC_meas_Forward_%i",j);
    input_Align_Radial_file.GetObject(name_h,Align_Radial_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Radial_MC_meas_Backward_%i",j);
    input_Align_Radial_file.GetObject(name_h,Align_Radial_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Radial_inv_response_undetector_forward_%i",j);
    input_Align_Radial_file.GetObject(name_h,Align_Radial_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Radial_inv_response_undetector_backward_%i",j);
    input_Align_Radial_file.GetObject(name_h,Align_Radial_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Radial_inv_response_nofsr_forward_%i",j);
    input_Align_Radial_file.GetObject(name_h,Align_Radial_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Radial_inv_response_nofsr_backward_%i",j);
    input_Align_Radial_file.GetObject(name_h,Align_Radial_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Radial

    //Align_Sagitta
    sprintf(name_h,"Align_Sagitta_MC_meas_Forward_%i",j);
    input_Align_Sagitta_file.GetObject(name_h,Align_Sagitta_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Sagitta_MC_meas_Backward_%i",j);
    input_Align_Sagitta_file.GetObject(name_h,Align_Sagitta_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Sagitta_inv_response_undetector_forward_%i",j);
    input_Align_Sagitta_file.GetObject(name_h,Align_Sagitta_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Sagitta_inv_response_undetector_backward_%i",j);
    input_Align_Sagitta_file.GetObject(name_h,Align_Sagitta_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Sagitta_inv_response_nofsr_forward_%i",j);
    input_Align_Sagitta_file.GetObject(name_h,Align_Sagitta_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Sagitta_inv_response_nofsr_backward_%i",j);
    input_Align_Sagitta_file.GetObject(name_h,Align_Sagitta_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Sagitta

    //Align_Skew
    sprintf(name_h,"Align_Skew_MC_meas_Forward_%i",j);
    input_Align_Skew_file.GetObject(name_h,Align_Skew_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Skew_MC_meas_Backward_%i",j);
    input_Align_Skew_file.GetObject(name_h,Align_Skew_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Skew_inv_response_undetector_forward_%i",j);
    input_Align_Skew_file.GetObject(name_h,Align_Skew_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Skew_inv_response_undetector_backward_%i",j);
    input_Align_Skew_file.GetObject(name_h,Align_Skew_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Skew_inv_response_nofsr_forward_%i",j);
    input_Align_Skew_file.GetObject(name_h,Align_Skew_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Skew_inv_response_nofsr_backward_%i",j);
    input_Align_Skew_file.GetObject(name_h,Align_Skew_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Skew

    //Align_Telescope
    sprintf(name_h,"Align_Telescope_MC_meas_Forward_%i",j);
    input_Align_Telescope_file.GetObject(name_h,Align_Telescope_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Telescope_MC_meas_Backward_%i",j);
    input_Align_Telescope_file.GetObject(name_h,Align_Telescope_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Telescope_inv_response_undetector_forward_%i",j);
    input_Align_Telescope_file.GetObject(name_h,Align_Telescope_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Telescope_inv_response_undetector_backward_%i",j);
    input_Align_Telescope_file.GetObject(name_h,Align_Telescope_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Telescope_inv_response_nofsr_forward_%i",j);
    input_Align_Telescope_file.GetObject(name_h,Align_Telescope_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Telescope_inv_response_nofsr_backward_%i",j);
    input_Align_Telescope_file.GetObject(name_h,Align_Telescope_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Telescope

    //Align_CurlV2TF
    sprintf(name_h,"Align_CurlV2TF_MC_meas_Forward_%i",j);
    input_Align_CurlV2TF_file.GetObject(name_h,Align_CurlV2TF_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_CurlV2TF_MC_meas_Backward_%i",j);
    input_Align_CurlV2TF_file.GetObject(name_h,Align_CurlV2TF_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_CurlV2TF_inv_response_undetector_forward_%i",j);
    input_Align_CurlV2TF_file.GetObject(name_h,Align_CurlV2TF_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_CurlV2TF_inv_response_undetector_backward_%i",j);
    input_Align_CurlV2TF_file.GetObject(name_h,Align_CurlV2TF_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_CurlV2TF_inv_response_nofsr_forward_%i",j);
    input_Align_CurlV2TF_file.GetObject(name_h,Align_CurlV2TF_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_CurlV2TF_inv_response_nofsr_backward_%i",j);
    input_Align_CurlV2TF_file.GetObject(name_h,Align_CurlV2TF_Inv_Response_NoFsr_Backward[j]);
    //eo Align_CurlV2TF

    //Align_Twist
    sprintf(name_h,"Align_Twist_MC_meas_Forward_%i",j);
    input_Align_Twist_file.GetObject(name_h,Align_Twist_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Twist_MC_meas_Backward_%i",j);
    input_Align_Twist_file.GetObject(name_h,Align_Twist_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Twist_inv_response_undetector_forward_%i",j);
    input_Align_Twist_file.GetObject(name_h,Align_Twist_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Twist_inv_response_undetector_backward_%i",j);
    input_Align_Twist_file.GetObject(name_h,Align_Twist_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Twist_inv_response_nofsr_forward_%i",j);
    input_Align_Twist_file.GetObject(name_h,Align_Twist_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Twist_inv_response_nofsr_backward_%i",j);
    input_Align_Twist_file.GetObject(name_h,Align_Twist_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Twist

    //Align_Zexpansion
    sprintf(name_h,"Align_Zexpansion_MC_meas_Forward_%i",j);
    input_Align_Zexpansion_file.GetObject(name_h,Align_Zexpansion_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Zexpansion_MC_meas_Backward_%i",j);
    input_Align_Zexpansion_file.GetObject(name_h,Align_Zexpansion_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Zexpansion_inv_response_undetector_forward_%i",j);
    input_Align_Zexpansion_file.GetObject(name_h,Align_Zexpansion_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Zexpansion_inv_response_undetector_backward_%i",j);
    input_Align_Zexpansion_file.GetObject(name_h,Align_Zexpansion_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Zexpansion_inv_response_nofsr_forward_%i",j);
    input_Align_Zexpansion_file.GetObject(name_h,Align_Zexpansion_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Zexpansion_inv_response_nofsr_backward_%i",j);
    input_Align_Zexpansion_file.GetObject(name_h,Align_Zexpansion_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Zexpansion

    //Align_Ideal
    sprintf(name_h,"Align_Ideal_MC_meas_Forward_%i",j);
    input_Align_Ideal_file.GetObject(name_h,Align_Ideal_hMeasCos_M_Y_Forward[j]);
    sprintf(name_h,"Align_Ideal_MC_meas_Backward_%i",j);
    input_Align_Ideal_file.GetObject(name_h,Align_Ideal_hMeasCos_M_Y_Backward[j]);

    //
    sprintf(name_h,"Align_Ideal_MC_meas_Forward_FineBin_%i",j);
    input_Align_Ideal_file.GetObject(name_h,Align_Ideal_hMeasCos_M_Y_Forward_FineBin[j]);
    sprintf(name_h,"Align_Ideal_MC_meas_Backward_FineBin_%i",j);
    input_Align_Ideal_file.GetObject(name_h,Align_Ideal_hMeasCos_M_Y_Backward_FineBin[j]);
    //

    sprintf(name_h,"Align_Ideal_inv_response_undetector_forward_%i",j);
    input_Align_Ideal_file.GetObject(name_h,Align_Ideal_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Ideal_inv_response_undetector_backward_%i",j);
    input_Align_Ideal_file.GetObject(name_h,Align_Ideal_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Ideal_inv_response_nofsr_forward_%i",j);
    input_Align_Ideal_file.GetObject(name_h,Align_Ideal_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Ideal_inv_response_nofsr_backward_%i",j);
    input_Align_Ideal_file.GetObject(name_h,Align_Ideal_Inv_Response_NoFsr_Backward[j]);
    //eo Align_Ideal

    //Align_Startup
    sprintf(name_h,"Align_Startup_MC_meas_Forward_%i",j);
    input_Align_Startup_file.GetObject(name_h,Align_Startup_hMeasCos_M_Y_Forward[j]);

    sprintf(name_h,"Align_Startup_MC_meas_Backward_%i",j);
    input_Align_Startup_file.GetObject(name_h,Align_Startup_hMeasCos_M_Y_Backward[j]);


    sprintf(name_h,"Align_Startup_inv_response_undetector_forward_%i",j);
    input_Align_Startup_file.GetObject(name_h,Align_Startup_Inv_Response_UnDetector_Forward[j]);
    sprintf(name_h,"Align_Startup_inv_response_undetector_backward_%i",j);
    input_Align_Startup_file.GetObject(name_h,Align_Startup_Inv_Response_UnDetector_Backward[j]);

    sprintf(name_h,"Align_Startup_inv_response_nofsr_forward_%i",j);
    input_Align_Startup_file.GetObject(name_h,Align_Startup_Inv_Response_NoFsr_Forward[j]);
    sprintf(name_h,"Align_Startup_inv_response_nofsr_backward_%i",j);
    input_Align_Startup_file.GetObject(name_h,Align_Startup_Inv_Response_NoFsr_Backward[j]);

    //eo Align_Startup



    sprintf(name_h,"Raw_Forward_%i",j);
    h_Raw_Forward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"Raw_Backward_%i",j);
    h_Raw_Backward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"Raw_AFB_%i",j);
    h_Raw_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"Raw_AFB_FineBin_%i",j);
    h_Raw_AFB_FineBin[j] = new TH1D(name_h,name_h,100, 40, 640);

    sprintf(name_h,"MC_True_AFB_%i",j);
    h_MC_True_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

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



    sprintf(name_h,"MC_Raw_AFB_ES_UP_%i",j);
    h_MC_Raw_AFB_ES_UP[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_ES_DOWN_%i",j);
    h_MC_Raw_AFB_ES_DOWN[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_ES_Diff_Up_%i",j);
    h_MC_Raw_AFB_ES_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_ES_Diff_Down_%i",j);
    h_MC_Raw_AFB_ES_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);



    sprintf(name_h,"MC_Raw_AFB_bkg_%i",j);
    h_MC_Raw_AFB_bkg[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_bkg_UP_%i",j);
    h_MC_Raw_AFB_bkg_UP[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_bkg_DOWN_%i",j);
    h_MC_Raw_AFB_bkg_DOWN[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_bkg_Diff_Up_%i",j);
    h_MC_Raw_AFB_bkg_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_AFB_bkg_Diff_Down_%i",j);
    h_MC_Raw_AFB_bkg_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    //sin2theta systematics
    sprintf(name_h,"MC_Raw_sin2412m2312_AFB_%i",j);
    h_MC_Raw_sin2412m2312_AFB[j] = new TH1D(name_h,name_h,nb_sin, xAxis_AFB);
    sprintf(name_h,"MC_Raw_sin2212m2312_AFB_%i",j);
    h_MC_Raw_sin2212m2312_AFB[j] = new TH1D(name_h,name_h,nb_sin, xAxis_AFB);

    sprintf(name_h,"MC_True_sin2412m2312_AFB_%i",j);
    h_MC_True_sin2412m2312_AFB[j] = new TH1D(name_h,name_h,nb_sin, xAxis_AFB);
    sprintf(name_h,"MC_True_sin2212m2312_AFB_%i",j);
    h_MC_True_sin2212m2312_AFB[j] = new TH1D(name_h,name_h,nb_sin, xAxis_AFB);


    sprintf(name_h,"MC_Unfolded_UnDet_AFB_Diff_sin2412m2312_%i",j);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[j] = new TH1D(name_h,name_h,nb_sin, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_AFB_Diff_sin2212m2312_%i",j);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2212m2312[j] = new TH1D(name_h,name_h,nb_sin, xAxis_AFB);     
    sprintf(name_h,"MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312_%i",j);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[j] = new TH1D(name_h,name_h,nb_sin, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_AFB_Diff_sin2212m2312_%i",j);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2212m2312[j] = new TH1D(name_h,name_h,nb_sin, xAxis_AFB);     
    //end of sin2theta systematics

    //alignment systematics
    //Raw
    sprintf(name_h,"MC_Raw_Align_Bowing_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Bowing_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_Align_Elliptical_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Elliptical_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);    
    sprintf(name_h,"MC_Raw_Align_Radial_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Radial_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);    
    sprintf(name_h,"MC_Raw_Align_Sagitta_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Sagitta_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);    
    sprintf(name_h,"MC_Raw_Align_Skew_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Skew_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);  
    sprintf(name_h,"MC_Raw_Align_Telescope_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Telescope_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_Align_CurlV2Tf_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_CurlV2TF_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_Align_Twist_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Twist_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_Align_Zexpansion_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Zexpansion_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Raw_Align_Startup_m_Ideal_AFB_%i",j);
    h_MC_Raw_Align_Startup_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_MC_Raw_alignment_total_plus_%i",j);
    h_MC_Raw_alignment_total_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_MC_Raw_alignment_total_minus_%i",j);
    h_MC_Raw_alignment_total_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_MC_Bare_alignment_total_plus_%i",j);
    h_MC_Bare_alignment_total_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_MC_Bare_alignment_total_minus_%i",j);
    h_MC_Bare_alignment_total_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_MC_Born_alignment_total_plus_%i",j);
    h_MC_Born_alignment_total_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_MC_Born_alignment_total_minus_%i",j);
    h_MC_Born_alignment_total_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);


    sprintf(name_h,"h_Systematics_fsr_raw_plus_%i",j);
    h_Systematics_fsr_raw_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_fsr_raw_minus_%i",j);
    h_Systematics_fsr_raw_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Systematics_noweight_raw_plus_%i",j);
    h_Systematics_noweight_raw_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_noweight_raw_minus_%i",j);
    h_Systematics_noweight_raw_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);


    sprintf(name_h,"h_Systematics_es_raw_plus_%i",j);
    h_Systematics_es_raw_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_es_raw_minus_%i",j);
    h_Systematics_es_raw_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);


    sprintf(name_h,"h_Systematics_bkg_raw_plus_%i",j);
    h_Systematics_bkg_raw_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_bkg_raw_minus_%i",j);
    h_Systematics_bkg_raw_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Systematics_sin_raw_plus_%i",j);
    h_Systematics_sin_raw_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_sin_raw_minus_%i",j);
    h_Systematics_sin_raw_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    //
    sprintf(name_h,"h_Systematics_fsr_bare_plus_%i",j);
    h_Systematics_fsr_bare_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_fsr_bare_minus_%i",j);
    h_Systematics_fsr_bare_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Systematics_noweight_bare_plus_%i",j);
    h_Systematics_noweight_bare_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_noweight_bare_minus_%i",j);
    h_Systematics_noweight_bare_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Systematics_es_bare_plus_%i",j);
    h_Systematics_es_bare_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_es_bare_minus_%i",j);
    h_Systematics_es_bare_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);


    sprintf(name_h,"h_Systematics_bkg_bare_plus_%i",j);
    h_Systematics_bkg_bare_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_bkg_bare_minus_%i",j);
    h_Systematics_bkg_bare_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Systematics_sin_bare_plus_%i",j);
    h_Systematics_sin_bare_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_sin_bare_minus_%i",j);
    h_Systematics_sin_bare_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    //
    sprintf(name_h,"h_Systematics_fsr_Born_plus_%i",j);
    h_Systematics_fsr_Born_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_fsr_Born_minus_%i",j);
    h_Systematics_fsr_Born_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Systematics_es_Born_plus_%i",j);
    h_Systematics_es_Born_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_es_Born_minus_%i",j);
    h_Systematics_es_Born_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Systematics_noweight_Born_plus_%i",j);
    h_Systematics_noweight_Born_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_noweight_Born_minus_%i",j);
    h_Systematics_noweight_Born_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Systematics_bkg_Born_plus_%i",j);
    h_Systematics_bkg_Born_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_bkg_Born_minus_%i",j);
    h_Systematics_bkg_Born_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Systematics_sin_Born_plus_%i",j);
    h_Systematics_sin_Born_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Systematics_sin_Born_minus_%i",j);
    h_Systematics_sin_Born_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);


    //Unfolded Bare Lepton
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Bowing_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Bowing_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Elliptical_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Elliptical_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Radial_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Radial_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Sagitta_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Sagitta_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Skew_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Skew_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Telescope_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Telescope_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_CurlV2TF_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_CurlV2TF_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Twist_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Twist_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Zexpansion_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Zexpansion_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    //Unfolded Born Level
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Bowing_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Bowing_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Elliptical_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Elliptical_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Radial_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Radial_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Sagitta_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Sagitta_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Skew_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Skew_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Telescope_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Telescope_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_CurlV2TF_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_CurlV2TF_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Twist_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Twist_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Zexpansion_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Zexpansion_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB_%i",j);
    h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    //eo alignment systematics


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

    sprintf(name_h,"MC_UnDet_AFB_ES_UP%i",j);
    h_MC_UnDet_AFB_ES_UP[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_UnDet_AFB_ES_DOWN%i",j);
    h_MC_UnDet_AFB_ES_DOWN[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_UnDet_AFB_ES_Diff_Up%i",j);
    h_MC_UnDet_AFB_ES_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_UnDet_AFB_ES_Diff_Down%i",j);
    h_MC_UnDet_AFB_ES_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);


    sprintf(name_h,"MC_Unfolded_UnDet_AFB_bkg%i",j);
    h_MC_Unfolded_UnDet_AFB_bkg[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_AFB_bkg_UP%i",j);
    h_MC_Unfolded_UnDet_AFB_bkg_UP[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_AFB_bkg_DOWN%i",j);
    h_MC_Unfolded_UnDet_AFB_bkg_DOWN[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_AFB_bkg_Diff_Up%i",j);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"MC_Unfolded_UnDet_AFB_bkg_Diff_Down%i",j);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"Unfolded_NoFsr_Forward_%i",j);
    h_Unfolded_NoFsr_Forward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"Unfolded_NoFsr_Backward_%i",j);
    h_Unfolded_NoFsr_Backward[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"Unfolded_NoFsr_AFB_%i",j);
    h_Unfolded_NoFsr_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Combined_%i",j);
    h_Combined[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

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
    sprintf(name_h,"Closure_Unfolded_NoFsr_AFB_%i",j);
    h_Closure_Unfolded_NoFsr_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Up_%i",j);
    h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Down_%i",j);
    h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up_%i",j);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_MC_Unfolded_NoFsr_AFB_ES_Diff_Down_%i",j);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);


    sprintf(name_h,"h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up_%i",j);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Down_%i",j);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up_%i",j);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_MC_Unfolded_UnDet_AFB_bkg_Diff_Down_%i",j);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Down[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);


    //pdf
    for (int k=0;k<n_ct;k++){
      sprintf(name_h,"MC_meas_Forward_PDF_%i_pdf_%i_set_%i",j,k,0);
      input_PDF_ct10_file.GetObject(name_h,hMeasCos_M_Y_Forward_PDF_ct10[j][k]);
      sprintf(name_h,"MC_meas_Backward_PDF_%i_pdf_%i_set_%i",j,k,0);
      input_PDF_ct10_file.GetObject(name_h,hMeasCos_M_Y_Backward_PDF_ct10[j][k]);
    }
    for (int k=0;k<n_mstw;k++){
      sprintf(name_h,"MC_meas_Forward_PDF_%i_pdf_%i_set_%i",j,k,2);
      input_PDF_mstw_file.GetObject(name_h,hMeasCos_M_Y_Forward_PDF_mstw[j][k]);
      sprintf(name_h,"MC_meas_Backward_PDF_%i_pdf_%i_set_%i",j,k,2);
      input_PDF_mstw_file.GetObject(name_h,hMeasCos_M_Y_Backward_PDF_mstw[j][k]);
    }
    for (int k=0;k<n_nnpdf;k++){
      sprintf(name_h,"MC_meas_Forward_PDF_%i_pdf_%i_set_%i",j,k,1);
      input_PDF_nnpdf_file.GetObject(name_h,hMeasCos_M_Y_Forward_PDF_nnpdf[j][k]);
      sprintf(name_h,"MC_meas_Backward_PDF_%i_pdf_%i_set_%i",j,k,1);
      input_PDF_nnpdf_file.GetObject(name_h,hMeasCos_M_Y_Backward_PDF_nnpdf[j][k]);
    }
    for (int k=0;k<ct10as_index;k++){
      sprintf(name_h,"MC_meas_Forward_PDF_%i_pdf_%i_set_%i",j,k,3);
      input_PDF_alpha_s_file.GetObject(name_h,hMeasCos_M_Y_Forward_PDF_alpha_s[j][k]);
      sprintf(name_h,"MC_meas_Backward_PDF_%i_pdf_%i_set_%i",j,k,3);
      input_PDF_alpha_s_file.GetObject(name_h,hMeasCos_M_Y_Backward_PDF_alpha_s[j][k]);
    }

    sprintf(name_h,"inv_response_undetector_forward_PDF_%i_set_%i",j,pdf_set);
    input_PDF_ct10_file.GetObject(name_h,Inv_Response_UnDetector_Forward_PDF_ct10[j]);
    sprintf(name_h,"inv_response_undetector_backward_PDF_%i_set_%i",j,pdf_set);
    input_PDF_ct10_file.GetObject(name_h,Inv_Response_UnDetector_Backward_PDF_ct10[j]);
    
    sprintf(name_h,"inv_response_nofsr_forward_PDF_%i_set_%i",j,pdf_set);
    input_PDF_ct10_file.GetObject(name_h,Inv_Response_NoFsr_Forward_PDF_ct10[j]);
    sprintf(name_h,"inv_response_nofsr_backward_PDF_%i_set_%i",j,pdf_set);
    input_PDF_ct10_file.GetObject(name_h,Inv_Response_NoFsr_Backward_PDF_ct10[j]);

    sprintf(name_h,"h_DeltaXmaxPlus_ct10_%i",j);
    h_DeltaXmaxPlus_ct10[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_DeltaXmaxMinus_ct10_%i",j);
    h_DeltaXmaxMinus_ct10[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_DeltaXmaxPlus_undet_ct10_%i",j);
    h_DeltaXmaxPlus_undet_ct10[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_DeltaXmaxMinus_undet_ct10_%i",j);
    h_DeltaXmaxMinus_undet_ct10[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_DeltaXmaxPlus_mstw_%i",j);
    h_DeltaXmaxPlus_mstw[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_DeltaXmaxMinus_mstw_%i",j);
    h_DeltaXmaxMinus_mstw[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_sigma_%i",j);
    h_sigma[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Delta_AFB_alphas_PLUS_%i",j);
    h_Delta_AFB_alphas_PLUS[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_Delta_AFB_alphas_MINUS_%i",j);
    h_Delta_AFB_alphas_MINUS[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_DeltaX_CT10_ALPHAS_PLUS_%i",j);
    h_DeltaX_CT10_ALPHAS_PLUS[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_DeltaX_CT10_ALPHAS_MINUS_%i",j);
    h_DeltaX_CT10_ALPHAS_MINUS[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_envelope_sigma_%i",j);
    h_envelope_sigma[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_envelope_sigma_plus%i",j);
    h_envelope_sigma_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_envelope_sigma_minus%i",j);
    h_envelope_sigma_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_total_plus_%i",j);
    h_total_plus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_total_minus_%i",j);
    h_total_minus[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_total_plus_undet%i",j);
    h_total_plus_undet[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_total_minus_undet%i",j);
    h_total_minus_undet[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_total_plus_nofsr%i",j);
    h_total_plus_nofsr[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    sprintf(name_h,"h_total_minus_nofsr%i",j);
    h_total_minus_nofsr[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);

    sprintf(name_h,"h_Ideal_Geo_AFB_%i",j);
    h_Ideal_Geo_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);    

    sprintf(name_h,"h_Ideal_Geo_AFB_FineBin_%i",j);
    h_Ideal_Geo_AFB_FineBin[j] = new TH1D(name_h,name_h,100,40,640);  

    sprintf(name_h,"h_CurlV2TF_AFB_%i",j);
    h_CurlV2TF_AFB[j] = new TH1D(name_h,name_h,nb, xAxis_AFB);
    //eo pdf
  } //eo j nb_Y


//  cout<<"nire"<<endl;

  double MC_True_AFB[nb];


  double Raw_AFB[nb];
  double Raw_error[nb];
  double Raw_AFB_FineBin[nb];
  double Raw_error_FineBin[nb];
  double MC_Raw_AFB[nb];
  double MC_Raw_AFB_FSR_UP[nb];
  double MC_Raw_AFB_FSR_DOWN[nb];
  double MC_Raw_AFB_FSR_Diff_Up[nb];
  double MC_Raw_AFB_FSR_Diff_Down[nb];
  double MC_Raw_AFB_bkg[nb];
  double MC_Raw_AFB_bkg_UP[nb];
  double MC_Raw_AFB_bkg_DOWN[nb];
  double MC_Raw_AFB_bkg_Diff_Up[nb];
  double MC_Raw_AFB_bkg_Diff_Down[nb];

  double MC_Raw_AFB_NoWeight[nb];

  double MC_Raw_AFB_ES_UP[nb];
  double MC_Raw_AFB_ES_DOWN[nb];
  double MC_Raw_AFB_ES_Diff_Up[nb];
  double MC_Raw_AFB_ES_Diff_Down[nb];


  double MC_Raw_sin2312_AFB[nb_sin];
  double MC_Raw_sin2412_AFB[nb_sin];
  double MC_Raw_sin2212_AFB[nb_sin];

  double MC_True_sin2312_AFB[nb_sin];
  double MC_True_sin2412_AFB[nb_sin];
  double MC_True_sin2212_AFB[nb_sin];

  double MC_Unfolded_UnDet_sin2312_AFB[nb_sin];
  double MC_Unfolded_UnDet_sin2412_AFB[nb_sin];
  double MC_Unfolded_UnDet_sin2212_AFB[nb_sin];
  double MC_Unfolded_UnDet_sin2312_Forward[nb_Y][nb_sin];
  double MC_Unfolded_UnDet_sin2312_Backward[nb_Y][nb_sin];
  double MC_Unfolded_UnDet_sin2412_Forward[nb_Y][nb_sin];
  double MC_Unfolded_UnDet_sin2412_Backward[nb_Y][nb_sin];
  double MC_Unfolded_UnDet_sin2212_Forward[nb_Y][nb_sin];
  double MC_Unfolded_UnDet_sin2212_Backward[nb_Y][nb_sin];
  double MC_Unfolded_NoFsr_sin2312_AFB[nb_sin];
  double MC_Unfolded_NoFsr_sin2412_AFB[nb_sin];
  double MC_Unfolded_NoFsr_sin2212_AFB[nb_sin];
  double MC_Unfolded_NoFsr_sin2312_Forward[nb_Y][nb_sin];
  double MC_Unfolded_NoFsr_sin2312_Backward[nb_Y][nb_sin];
  double MC_Unfolded_NoFsr_sin2412_Forward[nb_Y][nb_sin];
  double MC_Unfolded_NoFsr_sin2412_Backward[nb_Y][nb_sin];
  double MC_Unfolded_NoFsr_sin2212_Forward[nb_Y][nb_sin];
  double MC_Unfolded_NoFsr_sin2212_Backward[nb_Y][nb_sin];

  //alignment
  double MC_Raw_Align_Ideal_AFB[nb];   
  double MC_Raw_Align_Ideal_AFB_FineBin[nb];   
  double MC_Raw_Align_Startup_AFB[nb];   
  double MC_Raw_Align_Bowing_AFB[nb];   
  double MC_Raw_Align_Elliptical_AFB[nb];   
  double MC_Raw_Align_Radial_AFB[nb];   
  double MC_Raw_Align_Sagitta_AFB[nb];   
  double MC_Raw_Align_Skew_AFB[nb];   
  double MC_Raw_Align_Telescope_AFB[nb];   
  double MC_Raw_Align_CurlV2TF_AFB[nb];   
  double MC_Raw_Align_Twist_AFB[nb];   
  double MC_Raw_Align_Zexpansion_AFB[nb];   
 
  double MC_UnDet_Align_Ideal_AFB[nb];   
  double MC_UnDet_Align_Startup_AFB[nb];   
  double MC_UnDet_Align_Bowing_AFB[nb];   
  double MC_UnDet_Align_Elliptical_AFB[nb];   
  double MC_UnDet_Align_Radial_AFB[nb];   
  double MC_UnDet_Align_Sagitta_AFB[nb];   
  double MC_UnDet_Align_Skew_AFB[nb];   
  double MC_UnDet_Align_Telescope_AFB[nb];   
  double MC_UnDet_Align_CurlV2TF_AFB[nb];   
  double MC_UnDet_Align_Twist_AFB[nb];   
  double MC_UnDet_Align_Zexpansion_AFB[nb];  

  double MC_UnDet_Align_Ideal_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Startup_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Bowing_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Elliptical_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Radial_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Sagitta_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Skew_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Telescope_Forward[nb_Y][nb];   
  double MC_UnDet_Align_CurlV2TF_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Twist_Forward[nb_Y][nb];   
  double MC_UnDet_Align_Zexpansion_Forward[nb_Y][nb];  

  double MC_UnDet_Align_Ideal_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Startup_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Bowing_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Elliptical_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Radial_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Sagitta_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Skew_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Telescope_Backward[nb_Y][nb];   
  double MC_UnDet_Align_CurlV2TF_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Twist_Backward[nb_Y][nb];   
  double MC_UnDet_Align_Zexpansion_Backward[nb_Y][nb]; 

  double MC_NoFsr_Align_Ideal_AFB[nb];   
  double MC_NoFsr_Align_Startup_AFB[nb];   
  double MC_NoFsr_Align_Bowing_AFB[nb];    
  double MC_NoFsr_Align_Elliptical_AFB[nb];   
  double MC_NoFsr_Align_Radial_AFB[nb];   
  double MC_NoFsr_Align_Sagitta_AFB[nb];   
  double MC_NoFsr_Align_Skew_AFB[nb];   
  double MC_NoFsr_Align_Telescope_AFB[nb];   
  double MC_NoFsr_Align_CurlV2TF_AFB[nb];   
  double MC_NoFsr_Align_Twist_AFB[nb];   
  double MC_NoFsr_Align_Zexpansion_AFB[nb];  

  double MC_NoFsr_Align_Ideal_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Startup_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Bowing_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Elliptical_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Radial_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Sagitta_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Skew_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Telescope_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_CurlV2TF_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Twist_Forward[nb_Y][nb];   
  double MC_NoFsr_Align_Zexpansion_Forward[nb_Y][nb];  

  double MC_NoFsr_Align_Ideal_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Startup_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Bowing_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Elliptical_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Radial_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Sagitta_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Skew_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Telescope_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_CurlV2TF_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Twist_Backward[nb_Y][nb];   
  double MC_NoFsr_Align_Zexpansion_Backward[nb_Y][nb]; 

  //eo alignment


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

  double MC_UnDet_AFB_NoWeight[nb];

  double MC_UnDet_AFB_ES_UP[nb];
  double MC_UnDet_AFB_ES_DOWN[nb];
  double MC_UnDet_AFB_ES_Diff_Up[nb];
  double MC_UnDet_AFB_ES_Diff_Down[nb];

  double MC_UnDet_AFB_bkg[nb];
  double MC_UnDet_AFB_bkg_UP[nb];
  double MC_UnDet_AFB_bkg_DOWN[nb];
  double MC_UnDet_AFB_bkg_Diff_Up[nb];
  double MC_UnDet_AFB_bkg_Diff_Down[nb];
  double closure_first_sum[nb];
  double closure_second_sum[nb];
  double closure_Unfolded_UnDet_error[nb];
  double closure_Unfolded_NoFsr_error[nb];
  double Unfolded_NoFsr_Forward[nb_Y][nb];
  double Unfolded_NoFsr_Backward[nb_Y][nb];
  double Closure_Unfolded_NoFsr_Forward[nb_Y][nb];
  double Closure_Unfolded_NoFsr_Backward[nb_Y][nb];
  double Closure_Unfolded_NoFsr_AFB[nb];
  double Closure_Unfolded_UnDet_Forward[nb_Y][nb];
  double Closure_Unfolded_UnDet_Backward[nb_Y][nb];
  double Closure_Unfolded_UnDet_AFB[nb];

  double MC_Unfolded_UnDet_Forward_FSR_Up[nb_Y][nb];
  double MC_Unfolded_UnDet_Forward_FSR_Down[nb_Y][nb];
  double MC_Unfolded_UnDet_Backward_FSR_Up[nb_Y][nb];
  double MC_Unfolded_UnDet_Backward_FSR_Down[nb_Y][nb];

  double MC_Unfolded_UnDet_Forward_NoWeight[nb_Y][nb];
  double MC_Unfolded_UnDet_Backward_NoWeight[nb_Y][nb];

  double MC_Unfolded_UnDet_Forward_ES_Up[nb_Y][nb];
  double MC_Unfolded_UnDet_Forward_ES_Down[nb_Y][nb];
  double MC_Unfolded_UnDet_Backward_ES_Up[nb_Y][nb];
  double MC_Unfolded_UnDet_Backward_ES_Down[nb_Y][nb];


  double MC_Unfolded_NoFsr_Forward_FSR_Up[nb_Y][nb];
  double MC_Unfolded_NoFsr_Forward_FSR_Down[nb_Y][nb];
  double MC_Unfolded_NoFsr_Backward_FSR_Up[nb_Y][nb];
  double MC_Unfolded_NoFsr_Backward_FSR_Down[nb_Y][nb];
  double MC_Unfolded_NoFsr_AFB_FSR_Up[nb];
  double MC_Unfolded_NoFsr_AFB_FSR_Down[nb];

  double MC_Unfolded_NoFsr_Forward_ES_Up[nb_Y][nb];
  double MC_Unfolded_NoFsr_Forward_ES_Down[nb_Y][nb];
  double MC_Unfolded_NoFsr_Backward_ES_Up[nb_Y][nb];
  double MC_Unfolded_NoFsr_Backward_ES_Down[nb_Y][nb];
  double MC_Unfolded_NoFsr_AFB_ES_Up[nb];
  double MC_Unfolded_NoFsr_AFB_ES_Down[nb];

  double MC_Unfolded_NoFsr_Forward_NoWeight[nb_Y][nb];
  double MC_Unfolded_NoFsr_Backward_NoWeight[nb_Y][nb];

  double MC_Unfolded_NoFsr_AFB_NoWeight[nb];



  double MC_Unfolded_NoFsr_Forward_bkg[nb_Y][nb];
  double MC_Unfolded_NoFsr_Backward_bkg[nb_Y][nb];
  double MC_Unfolded_NoFsr_AFB_bkg[nb];

  double MC_Unfolded_NoFsr_Forward_bkg_Up[nb_Y][nb];
  double MC_Unfolded_NoFsr_Forward_bkg_Down[nb_Y][nb];
  double MC_Unfolded_NoFsr_Backward_bkg_Up[nb_Y][nb];
  double MC_Unfolded_NoFsr_Backward_bkg_Down[nb_Y][nb];
  double MC_Unfolded_NoFsr_AFB_bkg_Up[nb];
  double MC_Unfolded_NoFsr_AFB_bkg_Down[nb];

  double MC_Unfolded_UnDet_Forward_bkg[nb_Y][nb];
  double MC_Unfolded_UnDet_Backward_bkg[nb_Y][nb];

  double MC_Unfolded_UnDet_Forward_bkg_Up[nb_Y][nb];
  double MC_Unfolded_UnDet_Forward_bkg_Down[nb_Y][nb];
  double MC_Unfolded_UnDet_Backward_bkg_Up[nb_Y][nb];
  double MC_Unfolded_UnDet_Backward_bkg_Down[nb_Y][nb];

  double Unfolded_NoFsr_AFB[nb];//[nb_Y];
  double first_sum_fsr[nb];
  double second_sum_fsr[nb];
  double Unfolded_NoFsr_error[nb];
  double MC_NoFsr_AFB[nb];
  double error_closure_forward[nb];
  double error_closure_backward[nb];
  double error_forward[nb];
  double error_backward[nb];

  double combined[nb];
  double first_sum_comb[nb];
  double second_sum_comb[nb];
  double third_sum_comb[nb];
  double fourth_sum_comb[nb]; 
  double Unfolded_NoFsr_COMB_error[nb];

  double total_plus[nb_Y][nb];
  double total_minus[nb_Y][nb];

  double total_plus_comb[nb_Y][nb];
  double total_minus_comb[nb_Y][nb];

  double total_plus_fsr[nb_Y][nb];
  double total_minus_fsr[nb_Y][nb];

  double total_plus_noweight[nb_Y][nb];
  double total_minus_noweight[nb_Y][nb];

  double total_plus_es[nb_Y][nb];
  double total_minus_es[nb_Y][nb];


  double total_plus_bkg[nb_Y][nb];
  double total_minus_bkg[nb_Y][nb];

  double total_plus_sin[nb_Y][nb];
  double total_minus_sin[nb_Y][nb];

  double total_plus_undet[nb_Y][nb];
  double total_minus_undet[nb_Y][nb];

  double total_plus_undet_fsr[nb_Y][nb];
  double total_minus_undet_fsr[nb_Y][nb];

  double total_plus_undet_noweight[nb_Y][nb];
  double total_minus_undet_noweight[nb_Y][nb];


  double total_plus_undet_es[nb_Y][nb];
  double total_minus_undet_es[nb_Y][nb];

  double total_plus_undet_bkg[nb_Y][nb];
  double total_minus_undet_bkg[nb_Y][nb];

  double total_plus_undet_sin[nb_Y][nb];
  double total_minus_undet_sin[nb_Y][nb];

  double total_plus_nofsr[nb_Y][nb];
  double total_minus_nofsr[nb_Y][nb];

  double total_plus_nofsr_fsr[nb_Y][nb];
  double total_minus_nofsr_fsr[nb_Y][nb];

  double total_plus_nofsr_es[nb_Y][nb];
  double total_minus_nofsr_es[nb_Y][nb];

  double total_plus_nofsr_noweight[nb_Y][nb];
  double total_minus_nofsr_noweight[nb_Y][nb];



  double total_plus_nofsr_bkg[nb_Y][nb];
  double total_minus_nofsr_bkg[nb_Y][nb];

  double total_plus_nofsr_sin[nb_Y][nb];
  double total_minus_nofsr_sin[nb_Y][nb];

  double alignment_total_plus[nb_Y][nb];
  double alignment_total_minus[nb_Y][nb];

  double alignment_total_plus_undet[nb_Y][nb];
  double alignment_total_minus_undet[nb_Y][nb];

  double alignment_total_plus_nofsr[nb_Y][nb];
  double alignment_total_minus_nofsr[nb_Y][nb];

  //unfolding pdf
  double MC_Unfolded_UnDet_Forward_PDF_ct10[nb_Y][nb][n_ct];
  double MC_Unfolded_UnDet_Backward_PDF_ct10[nb_Y][nb][n_ct];
  double MC_Unfolded_UnDet_AFB_PDF_ct10[nb][n_ct];
  //

  double dilution[nb_Y][nb];

  for (int k=0;k<nb_Y;k++){

      for (int i=0;i<17;i++){
	//relval finebins
	Raw_AFB_FineBin[i] = 0;
	Raw_error_FineBin[i] = 0;
	MC_Raw_Align_Ideal_AFB_FineBin[i] = 0;

	Raw_AFB_FineBin[i] = AFB(hDataMeasCos_M_Y_Forward_FineBin[k]->GetBinContent(i+1),hDataMeasCos_M_Y_Backward_FineBin[k]->GetBinContent(i+1));
	Raw_error_FineBin[i] = RAWAFBERROR(Raw_AFB_FineBin[i],hDataMeasCos_M_Y_Forward_FineBin[k]->GetBinContent(i+1),hDataMeasCos_M_Y_Backward_FineBin[k]->GetBinContent(i+1));
	
	h_Raw_AFB_FineBin[k]->SetBinContent(i+1,Raw_AFB_FineBin[i]);
	h_Raw_AFB_FineBin[k]->SetBinError(i+1,Raw_error_FineBin[i]);


	MC_Raw_Align_Ideal_AFB_FineBin[i] = AFB(Align_Ideal_hMeasCos_M_Y_Forward_FineBin[k]->GetBinContent(i+1),Align_Ideal_hMeasCos_M_Y_Backward_FineBin[k]->GetBinContent(i+1));
	h_Ideal_Geo_AFB_FineBin[k]->SetBinContent(i+1,MC_Raw_Align_Ideal_AFB_FineBin[i]);
	h_Ideal_Geo_AFB_FineBin[k]->SetBinError(i+1,RAWAFBERROR(MC_Raw_Align_Ideal_AFB_FineBin[i],Align_Ideal_hMeasCos_M_Y_Forward_FineBin[k]->GetBinContent(i+1),Align_Ideal_hMeasCos_M_Y_Backward_FineBin[k]->GetBinContent(i+1)));
	//
      }


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

      MC_Unfolded_UnDet_Forward_FSR_Up[k][i] = 0;
      MC_Unfolded_UnDet_Forward_FSR_Down[k][i] = 0;
      MC_Unfolded_UnDet_Backward_FSR_Up[k][i] = 0;
      MC_Unfolded_UnDet_Backward_FSR_Down[k][i] = 0;

      MC_Unfolded_UnDet_Forward_NoWeight[k][i] = 0;
      MC_Unfolded_UnDet_Backward_NoWeight[k][i] = 0;

      MC_Unfolded_UnDet_Forward_ES_Up[k][i] = 0;
      MC_Unfolded_UnDet_Forward_ES_Down[k][i] = 0;
      MC_Unfolded_UnDet_Backward_ES_Up[k][i] = 0;
      MC_Unfolded_UnDet_Backward_ES_Down[k][i] = 0;


      MC_Unfolded_NoFsr_Forward_FSR_Up[k][i] = 0;
      MC_Unfolded_NoFsr_Forward_FSR_Down[k][i] = 0;
      MC_Unfolded_NoFsr_Backward_FSR_Up[k][i] = 0;
      MC_Unfolded_NoFsr_Backward_FSR_Down[k][i] = 0;
      MC_Unfolded_NoFsr_AFB_FSR_Up[i] = 0;
      MC_Unfolded_NoFsr_AFB_FSR_Down[i] = 0;	

      MC_Unfolded_NoFsr_Forward_ES_Up[k][i] = 0;
      MC_Unfolded_NoFsr_Forward_ES_Down[k][i] = 0;
      MC_Unfolded_NoFsr_Backward_ES_Up[k][i] = 0;
      MC_Unfolded_NoFsr_Backward_ES_Down[k][i] = 0;
      MC_Unfolded_NoFsr_AFB_ES_Up[i] = 0;
      MC_Unfolded_NoFsr_AFB_ES_Down[i] = 0;

      MC_Unfolded_NoFsr_Forward_NoWeight[k][i] = 0;
      MC_Unfolded_NoFsr_Backward_NoWeight[k][i] = 0;
      MC_Unfolded_NoFsr_AFB_NoWeight[i] = 0;

      MC_Unfolded_NoFsr_Forward_bkg[k][i] = 0;
      MC_Unfolded_NoFsr_Backward_bkg[k][i] = 0;
      MC_Unfolded_NoFsr_AFB_bkg[i] = 0;

      MC_Unfolded_NoFsr_Forward_bkg_Up[k][i] = 0;
      MC_Unfolded_NoFsr_Forward_bkg_Down[k][i] = 0;
      MC_Unfolded_NoFsr_Backward_bkg_Up[k][i] = 0;
      MC_Unfolded_NoFsr_Backward_bkg_Down[k][i] = 0;
      MC_Unfolded_NoFsr_AFB_bkg_Up[i] = 0;
      MC_Unfolded_NoFsr_AFB_bkg_Down[i] = 0;	

      Unfolded_NoFsr_AFB[i] = 0;
      combined[i] = 0;

      MC_Unfolded_UnDet_Forward_bkg[k][i] = 0;
      MC_Unfolded_UnDet_Backward_bkg[k][i] = 0;

      MC_Unfolded_UnDet_Forward_bkg_Up[k][i] = 0;
      MC_Unfolded_UnDet_Forward_bkg_Down[k][i] = 0;
      MC_Unfolded_UnDet_Backward_bkg_Up[k][i] = 0;
      MC_Unfolded_UnDet_Backward_bkg_Down[k][i] = 0;

      dilution[k][i] = 0;

      first_sum[i] = 0;
      second_sum[i] = 0;
      Unfolded_UnDet_error[i] = 0;
      closure_first_sum[i] = 0;
      closure_second_sum[i] = 0;
      closure_Unfolded_UnDet_error[i] = 0;
      first_sum_fsr[i] = 0;
      second_sum_fsr[i] = 0;
      Unfolded_NoFsr_error[i] = 0;

      first_sum_comb[i] = 0;
      second_sum_comb[i] = 0;
      third_sum_comb[i] = 0;
      fourth_sum_comb[i] = 0;
      Unfolded_NoFsr_COMB_error[i] = 0;

      Raw_AFB[i] = 0;
      Raw_error[i] = 0;

      MC_True_AFB[i] = 0;


      MC_Raw_AFB[i] = 0;
      MC_Raw_AFB_FSR_UP[i] = 0;
      MC_Raw_AFB_FSR_DOWN[i] = 0;
      MC_Raw_AFB_FSR_Diff_Up[i] = 0;
      MC_Raw_AFB_FSR_Diff_Down[i] = 0;

      MC_Raw_AFB_NoWeight[i] = 0;

      MC_Raw_AFB_ES_UP[i] = 0;
      MC_Raw_AFB_ES_DOWN[i] = 0;
      MC_Raw_AFB_ES_Diff_Up[i] = 0;
      MC_Raw_AFB_ES_Diff_Down[i] = 0;

      MC_Raw_AFB_bkg[i] = 0;
      MC_Raw_AFB_bkg_UP[i] = 0;
      MC_Raw_AFB_bkg_DOWN[i] = 0;
      MC_Raw_AFB_bkg_Diff_Up[i] = 0;
      MC_Raw_AFB_bkg_Diff_Down[i] = 0;
      MC_UnDet_AFB[i] = 0;
      MC_UnDet_AFB_FSR_UP[i] = 0;
      MC_UnDet_AFB_FSR_DOWN[i] = 0;
      MC_UnDet_AFB_FSR_Diff_Up[i] = 0;
      MC_UnDet_AFB_FSR_Diff_Down[i] = 0;

      MC_UnDet_AFB_NoWeight[i] = 0;

      MC_UnDet_AFB_ES_UP[i] = 0;
      MC_UnDet_AFB_ES_DOWN[i] = 0;
      MC_UnDet_AFB_ES_Diff_Up[i] = 0;
      MC_UnDet_AFB_ES_Diff_Down[i] = 0;


      MC_UnDet_AFB_bkg[i] = 0;
      MC_UnDet_AFB_bkg_UP[i] = 0;
      MC_UnDet_AFB_bkg_DOWN[i] = 0;
      MC_UnDet_AFB_bkg_Diff_Up[i] = 0;
      MC_UnDet_AFB_bkg_Diff_Down[i] = 0;      
      MC_NoFsr_AFB[i] = 0;
      error_closure_forward[i] = 0;
      error_closure_backward[i] = 0;
      error_forward[i] = 0;
      error_backward[i] = 0;	
      //pdf
      DeltaXmaxPlus[i][k] = 0;
      DeltaXmaxMinus[i][k] = 0;
      sigma[i][k] = 0;

      DeltaXmaxPlus_undet[i][k] = 0;
      DeltaXmaxMinus_undet[i][k] = 0;
      sigma_undet[i][k] = 0;

      for (int pdfindex = 0; pdfindex<n_ct;pdfindex++){
	MC_Unfolded_UnDet_Forward_PDF_ct10[k][i][pdfindex] = 0;
	MC_Unfolded_UnDet_Backward_PDF_ct10[k][i][pdfindex] = 0;
	MC_Unfolded_UnDet_AFB_PDF_ct10[i][pdfindex] = 0;
      }
      //



      total_plus[k][i] = 0;
      total_minus[k][i] = 0;

      total_plus_comb[k][i] = 0;
      total_minus_comb[k][i] = 0;

      total_plus_fsr[k][i] = 0;
      total_minus_fsr[k][i] = 0;

      total_plus_noweight[k][i] = 0;
      total_minus_noweight[k][i] = 0;

      total_plus_es[k][i] = 0;
      total_minus_es[k][i] = 0;

      total_plus_bkg[k][i] = 0;
      total_minus_bkg[k][i] = 0;

      total_plus_sin[k][i] = 0;
      total_minus_sin[k][i] = 0;

      total_plus_undet[k][i] = 0;
      total_minus_undet[k][i] = 0;

      total_plus_undet_fsr[k][i] = 0;
      total_minus_undet_fsr[k][i] = 0;

      total_plus_undet_noweight[k][i] = 0;
      total_minus_undet_noweight[k][i] = 0;


      total_plus_undet_es[k][i] = 0;
      total_minus_undet_es[k][i] = 0;


      total_plus_undet_bkg[k][i] = 0;
      total_minus_undet_bkg[k][i] = 0;

      total_plus_undet_sin[k][i] = 0;
      total_minus_undet_sin[k][i] = 0;

      total_plus_nofsr[k][i] = 0;
      total_minus_nofsr[k][i] = 0;

      total_plus_nofsr_fsr[k][i] = 0;
      total_minus_nofsr_fsr[k][i] = 0;

      total_plus_nofsr_es[k][i] = 0;
      total_minus_nofsr_es[k][i] = 0;

      total_plus_nofsr_noweight[k][i] = 0;
      total_minus_nofsr_noweight[k][i] = 0;

      total_plus_nofsr_bkg[k][i] = 0;
      total_minus_nofsr_bkg[k][i] = 0;

      total_plus_nofsr_sin[k][i] = 0;
      total_minus_nofsr_sin[k][i] = 0;

      alignment_total_plus[k][i] = 0;
      alignment_total_minus[k][i] = 0;
      alignment_total_plus_undet[k][i] = 0;
      alignment_total_minus_undet[k][i] = 0;
      alignment_total_plus_nofsr[k][i] = 0;
      alignment_total_minus_nofsr[k][i] = 0;

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
	//
	MC_Unfolded_UnDet_Forward_NoWeight[k][i] += Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_NoWeight[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_Backward_NoWeight[k][i] += Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_NoWeight[k]->GetBinContent(j+1);
	//
	/////
	MC_Unfolded_UnDet_Forward_FSR_Up[k][i] += Inv_Response_UnDet_Forward_FSR_UP[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_FSR_UP[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_Forward_FSR_Down[k][i] += Inv_Response_UnDet_Forward_FSR_DOWN[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_FSR_DOWN[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_Backward_FSR_Up[k][i] += Inv_Response_UnDet_Backward_FSR_UP[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_FSR_UP[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_Backward_FSR_Down[k][i] += Inv_Response_UnDet_Backward_FSR_DOWN[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_FSR_DOWN[k]->GetBinContent(j+1);

        MC_Unfolded_UnDet_Forward_ES_Up[k][i] += Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_ES_UP[k]->GetBinContent(j+1);
        MC_Unfolded_UnDet_Forward_ES_Down[k][i] += Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_ES_DOWN[k]->GetBinContent(j+1);
        MC_Unfolded_UnDet_Backward_ES_Up[k][i] += Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_ES_UP[k]->GetBinContent(j+1);
        MC_Unfolded_UnDet_Backward_ES_Down[k][i] += Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_ES_DOWN[k]->GetBinContent(j+1);
	/////
	MC_Unfolded_NoFsr_Forward_FSR_Up[k][i] += Inv_Response_NoFsr_Forward_FSR_UP[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_FSR_UP[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_Forward_FSR_Down[k][i] += Inv_Response_NoFsr_Forward_FSR_DOWN[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_FSR_DOWN[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_Backward_FSR_Up[k][i] += Inv_Response_NoFsr_Backward_FSR_UP[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_FSR_UP[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_Backward_FSR_Down[k][i] += Inv_Response_NoFsr_Backward_FSR_DOWN[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_FSR_DOWN[k]->GetBinContent(j+1);

        MC_Unfolded_NoFsr_Forward_ES_Up[k][i] += Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_ES_UP[k]->GetBinContent(j+1);
        MC_Unfolded_NoFsr_Forward_ES_Down[k][i] += Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_ES_DOWN[k]->GetBinContent(j+1);
        MC_Unfolded_NoFsr_Backward_ES_Up[k][i] += Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_ES_UP[k]->GetBinContent(j+1);
        MC_Unfolded_NoFsr_Backward_ES_Down[k][i] += Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_ES_DOWN[k]->GetBinContent(j+1);

        MC_Unfolded_NoFsr_Forward_NoWeight[k][i] += Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_NoWeight[k]->GetBinContent(j+1);
        MC_Unfolded_NoFsr_Backward_NoWeight[k][i] += Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_NoWeight[k]->GetBinContent(j+1);


	MC_Unfolded_UnDet_Forward_bkg[k][i] += Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_bkg[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_Backward_bkg[k][i] += Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_bkg[k]->GetBinContent(j+1);

	MC_Unfolded_NoFsr_Forward_bkg[k][i] += Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_bkg[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_Backward_bkg[k][i] += Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_bkg[k]->GetBinContent(j+1);


	MC_Unfolded_UnDet_Forward_bkg_Up[k][i] += Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_bkg_UP[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_Forward_bkg_Down[k][i] += Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_bkg_DOWN[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_Backward_bkg_Up[k][i] += Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_bkg_UP[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_Backward_bkg_Down[k][i] += Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_bkg_DOWN[k]->GetBinContent(j+1);

	MC_Unfolded_NoFsr_Forward_bkg_Up[k][i] += Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_bkg_UP[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_Forward_bkg_Down[k][i] += Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_bkg_DOWN[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_Backward_bkg_Up[k][i] += Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_bkg_UP[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_Backward_bkg_Down[k][i] += Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_bkg_DOWN[k]->GetBinContent(j+1);

      }
      Raw_AFB[i] = AFB(hDataMeasCos_M_Y_Forward[k]->GetBinContent(i+1),hDataMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      Raw_error[i] = RAWAFBERROR(Raw_AFB[i],hDataMeasCos_M_Y_Forward[k]->GetBinContent(i+1),hDataMeasCos_M_Y_Backward[k]->GetBinContent(i+1));

      h_Raw_AFB[k]->SetBinContent(i+1,Raw_AFB[i]);
      h_Raw_AFB[k]->SetBinError(i+1,Raw_error[i]);

     
 
      MC_Raw_AFB[i] = AFB(hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      h_MC_Raw_AFB[k]->SetBinContent(i+1,MC_Raw_AFB[i]);

      h_MC_Raw_AFB[k]->SetBinError(i+1,RAWAFBERROR(MC_Raw_AFB[i],hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward[k]->GetBinContent(i+1)));

      //
      MC_Raw_AFB_NoWeight[i] = AFB(hMeasCos_M_Y_Forward_NoWeight[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward_NoWeight[k]->GetBinContent(i+1));
      float diff1 = MC_Raw_AFB_NoWeight[i]-MC_Raw_AFB[i];
      if (i == nb-1){
	if (fabs(diff1) > fabs(MC_Raw_AFB_NoWeight[i-1]-MC_Raw_AFB[i-1])) diff1 = MC_Raw_AFB_NoWeight[i-1]-MC_Raw_AFB[i-1];
      }
      if (diff1 >0. ? total_plus[k][i] += diff1*diff1 : total_minus[k][i] += diff1*diff1);
      if (diff1 >0. ? total_plus_noweight[k][i] += diff1*diff1 : total_minus_noweight[k][i] += diff1*diff1);
      if (total_plus_noweight[k][i] != 0){
	h_Systematics_noweight_raw_plus[k]->SetBinContent(i+1,sqrt(total_plus_noweight[k][i]));
	h_Systematics_noweight_raw_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_noweight[k][i] != 0){
	h_Systematics_noweight_raw_minus[k]->SetBinContent(i+1,-sqrt(total_minus_noweight[k][i]));
	h_Systematics_noweight_raw_minus[k]->SetBinError(i+1,0.000000001);
      }
      //


      diff1 = 0;
      MC_Raw_AFB_FSR_UP[i] = AFB(hMeasCos_M_Y_Forward_FSR_UP[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward_FSR_UP[k]->GetBinContent(i+1));
      h_MC_Raw_AFB_FSR_UP[k]->SetBinContent(i+1,MC_Raw_AFB_FSR_UP[i]);
      MC_Raw_AFB_FSR_DOWN[i] = AFB(hMeasCos_M_Y_Forward_FSR_DOWN[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward_FSR_DOWN[k]->GetBinContent(i+1));
      h_MC_Raw_AFB_FSR_DOWN[k]->SetBinContent(i+1,MC_Raw_AFB_FSR_DOWN[i]);
      diff1 = MC_Raw_AFB_FSR_UP[i]-MC_Raw_AFB[i];
      float diff2 = MC_Raw_AFB_FSR_DOWN[i]-MC_Raw_AFB[i];
      if (diff1 >0. ? total_plus[k][i] += diff1*diff1 : total_minus[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus[k][i] += diff2*diff2 : total_minus[k][i] += diff2*diff2);

      if (diff1 >0. ? total_plus_fsr[k][i] += diff1*diff1 : total_minus_fsr[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus_fsr[k][i] += diff2*diff2 : total_minus_fsr[k][i] += diff2*diff2);      
      if (total_plus_fsr[k][i] != 0){
	h_Systematics_fsr_raw_plus[k]->SetBinContent(i+1,sqrt(total_plus_fsr[k][i]));
	h_Systematics_fsr_raw_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_fsr[k][i] != 0){
	h_Systematics_fsr_raw_minus[k]->SetBinContent(i+1,-sqrt(total_minus_fsr[k][i]));
	h_Systematics_fsr_raw_minus[k]->SetBinError(i+1,0.000000001);
      }

      MC_Raw_AFB_FSR_Diff_Up[i] = diff1;//TMath::Max(diff1,diff2);
      MC_Raw_AFB_FSR_Diff_Down[i] = diff2;//TMath::Min(diff1,diff2);
      h_MC_Raw_AFB_FSR_Diff_Up[k]->SetBinContent(i+1,MC_Raw_AFB_FSR_Diff_Up[i]);
      h_MC_Raw_AFB_FSR_Diff_Down[k]->SetBinContent(i+1,MC_Raw_AFB_FSR_Diff_Down[i]);


      diff1 = 0;
      diff2 = 0;		
      MC_Raw_AFB_ES_UP[i] = AFB(hMeasCos_M_Y_Forward_ES_UP[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward_ES_UP[k]->GetBinContent(i+1));
      h_MC_Raw_AFB_ES_UP[k]->SetBinContent(i+1,MC_Raw_AFB_ES_UP[i]);
      MC_Raw_AFB_ES_DOWN[i] = AFB(hMeasCos_M_Y_Forward_ES_DOWN[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward_ES_DOWN[k]->GetBinContent(i+1));
      h_MC_Raw_AFB_ES_DOWN[k]->SetBinContent(i+1,MC_Raw_AFB_ES_DOWN[i]);
      diff1 = MC_Raw_AFB_ES_UP[i]-MC_Raw_AFB[i];
      diff2 = MC_Raw_AFB_ES_DOWN[i]-MC_Raw_AFB[i];
/*
      if (i == nb-1 && fabs(diff1) > fabs(MC_Raw_AFB_ES_UP[i-1]-MC_Raw_AFB[i-1])) diff1 = MC_Raw_AFB_ES_UP[i-1]-MC_Raw_AFB[i-1];
      if (i == nb-1 && fabs(diff2) > fabs(MC_Raw_AFB_ES_DOWN[i-1]-MC_Raw_AFB[i-1])) diff1 = MC_Raw_AFB_ES_DOWN[i-1]-MC_Raw_AFB[i-1];
*/
      //cout<<k<<"  "<<i<<"   diff1   "<<diff1<<endl;
      //cout<<k<<"  "<<i<<"   diff2   "<<diff2<<endl;
      if (diff1 >0. ? total_plus[k][i] += diff1*diff1 : total_minus[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus[k][i] += diff2*diff2 : total_minus[k][i] += diff2*diff2);

      if (diff1 >0. ? total_plus_es[k][i] += diff1*diff1 : total_minus_es[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus_es[k][i] += diff2*diff2 : total_minus_es[k][i] += diff2*diff2);
      //cout<<total_plus_es[k][i]<<endl;
      //cout<<total_minus_es[k][i]<<endl;
      if (total_plus_es[k][i] != 0){
        h_Systematics_es_raw_plus[k]->SetBinContent(i+1,sqrt(total_plus_es[k][i]));
        h_Systematics_es_raw_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_es[k][i] != 0){
        h_Systematics_es_raw_minus[k]->SetBinContent(i+1,-sqrt(total_minus_es[k][i]));
        h_Systematics_es_raw_minus[k]->SetBinError(i+1,0.000000001);      
      }

      MC_Raw_AFB_ES_Diff_Up[i] = diff1;//TMath::Max(diff1,diff2);
      MC_Raw_AFB_ES_Diff_Down[i] = diff2;//TMath::Min(diff1,diff2);
      h_MC_Raw_AFB_ES_Diff_Up[k]->SetBinContent(i+1,MC_Raw_AFB_ES_Diff_Up[i]);
      h_MC_Raw_AFB_ES_Diff_Down[k]->SetBinContent(i+1,MC_Raw_AFB_ES_Diff_Down[i]);
     
      
      //fsr table raw level
      /*
	if (k == 0 && i == 0){ 
	cout<<"FSR SYSTEMATICS (RAW LEVEL)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
	cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff1<<"  &  "<<setprecision(3)<<diff2<<"    \\\\    "<<endl;
      */
       //end of fsr table raw level
/*
      MC_Raw_AFB_FSR_Diff_Up[i] = diff1;//TMath::Max(diff1,diff2);
      MC_Raw_AFB_FSR_Diff_Down[i] = diff2;//TMath::Min(diff1,diff2);
      h_MC_Raw_AFB_FSR_Diff_Up[k]->SetBinContent(i+1,MC_Raw_AFB_FSR_Diff_Up[i]);
      h_MC_Raw_AFB_FSR_Diff_Down[k]->SetBinContent(i+1,MC_Raw_AFB_FSR_Diff_Down[i]);
*/


      MC_Raw_AFB_bkg[i] = AFB(hMeasCos_M_Y_Forward_bkg[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward_bkg[k]->GetBinContent(i+1));

      MC_Raw_AFB_bkg_UP[i] = AFB(hMeasCos_M_Y_Forward_bkg_UP[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward_bkg_UP[k]->GetBinContent(i+1));
      h_MC_Raw_AFB_bkg_UP[k]->SetBinContent(i+1,MC_Raw_AFB_bkg_UP[i]);
      MC_Raw_AFB_bkg_DOWN[i] = AFB(hMeasCos_M_Y_Forward_bkg_DOWN[k]->GetBinContent(i+1),hMeasCos_M_Y_Backward_bkg_DOWN[k]->GetBinContent(i+1));
      h_MC_Raw_AFB_bkg_DOWN[k]->SetBinContent(i+1,MC_Raw_AFB_bkg_DOWN[i]);
      diff1 = 0;
      diff2 = 0;
      diff1 = MC_Raw_AFB_bkg_UP[i]-MC_Raw_AFB_bkg[i];
      diff2 = MC_Raw_AFB_bkg_DOWN[i]-MC_Raw_AFB_bkg[i];
      if (diff1 >0. ? total_plus[k][i] += diff1*diff1 : total_minus[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus[k][i] += diff2*diff2 : total_minus[k][i] += diff2*diff2);

      if (diff1 >0. ? total_plus_bkg[k][i] += diff1*diff1 : total_minus_bkg[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus_bkg[k][i] += diff2*diff2 : total_minus_bkg[k][i] += diff2*diff2);
      if (total_plus_bkg[k][i] != 0){
	h_Systematics_bkg_raw_plus[k]->SetBinContent(i+1,sqrt(total_plus_bkg[k][i]));
	h_Systematics_bkg_raw_plus[k]->SetBinError(i+1,0.000000001); 
      }
      if (total_minus_bkg[k][i] != 0){
	h_Systematics_bkg_raw_minus[k]->SetBinContent(i+1,-sqrt(total_minus_bkg[k][i]));  
	h_Systematics_bkg_raw_minus[k]->SetBinError(i+1,0.000000001); 
      }
      //bkg systematics table raw level
      /*
	if (k == 0 && i == 0){ 
	cout<<"bkg SYSTEMATICS (RAW LEVEL)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    bkg Up - Nominal           bkg Down - Nominal"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
	cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff1<<"  &  "<<setprecision(3)<<diff2<<"    \\\\    "<<endl;
      */
       //end of bkg table raw level
      MC_Raw_AFB_bkg_Diff_Up[i] = diff1;//TMath::Max(diff1,diff2);
      MC_Raw_AFB_bkg_Diff_Down[i] = diff2;//TMath::Min(diff1,diff2);
      h_MC_Raw_AFB_bkg_Diff_Up[k]->SetBinContent(i+1,MC_Raw_AFB_bkg_Diff_Up[i]);
      h_MC_Raw_AFB_bkg_Diff_Down[k]->SetBinContent(i+1,MC_Raw_AFB_bkg_Diff_Down[i]);


      MC_UnDet_AFB[i] = AFB(hUnDetectorCos_M_Y_Forward[k]->GetBinContent(i+1),hUnDetectorCos_M_Y_Backward[k]->GetBinContent(i+1));
      h_MC_UnDet_AFB[k]->SetBinContent(i+1,MC_UnDet_AFB[i]);

      //fsr systematics bare lepton level
      /*
      MC_UnDet_AFB_FSR_UP[i] = AFB(hUnDetectorCos_M_Y_Forward_FSR_UP[k]->GetBinContent(i+1),hUnDetectorCos_M_Y_Backward_FSR_UP[k]->GetBinContent(i+1));
      MC_UnDet_AFB_FSR_DOWN[i] = AFB(hUnDetectorCos_M_Y_Forward_FSR_DOWN[k]->GetBinContent(i+1),hUnDetectorCos_M_Y_Backward_FSR_DOWN[k]->GetBinContent(i+1));
      */
      MC_UnDet_AFB_FSR_UP[i] = AFB(MC_Unfolded_UnDet_Forward_FSR_Up[k][i],MC_Unfolded_UnDet_Backward_FSR_Up[k][i]);
      MC_UnDet_AFB_FSR_DOWN[i] = AFB(MC_Unfolded_UnDet_Forward_FSR_Down[k][i],MC_Unfolded_UnDet_Backward_FSR_Down[k][i]);
      h_MC_UnDet_AFB_FSR_UP[k]->SetBinContent(i+1,MC_UnDet_AFB_FSR_UP[i]);
      h_MC_UnDet_AFB_FSR_DOWN[k]->SetBinContent(i+1,MC_UnDet_AFB_FSR_DOWN[i]);
      double diff_NoDet1 = MC_UnDet_AFB_FSR_UP[i]-MC_UnDet_AFB[i];
      double diff_NoDet2 = MC_UnDet_AFB_FSR_DOWN[i]-MC_UnDet_AFB[i];
      //
      if (i == nb-1){
	if (fabs(diff_NoDet1) > fabs(MC_UnDet_AFB_FSR_UP[i-1]-MC_UnDet_AFB[i-1])) diff_NoDet1 = MC_UnDet_AFB_FSR_UP[i-1]-MC_UnDet_AFB[i-1];
	if (fabs(diff_NoDet2) > fabs(MC_UnDet_AFB_FSR_DOWN[i-1]-MC_UnDet_AFB[i-1])) diff_NoDet2 = MC_UnDet_AFB_FSR_DOWN[i-1]-MC_UnDet_AFB[i-1];
      }
      //
      if (diff_NoDet1 >0. ? total_plus_undet[k][i] += diff_NoDet1*diff_NoDet1 : total_minus_undet[k][i] += diff_NoDet1*diff_NoDet1);
      if (diff_NoDet2 >0. ? total_plus_undet[k][i] += diff_NoDet2*diff_NoDet2 : total_minus_undet[k][i] += diff_NoDet2*diff_NoDet2);

      if (diff_NoDet1 >0. ? total_plus_undet_fsr[k][i] += diff_NoDet1*diff_NoDet1 : total_minus_undet_fsr[k][i] += diff_NoDet1*diff_NoDet1);
      if (diff_NoDet2 >0. ? total_plus_undet_fsr[k][i] += diff_NoDet2*diff_NoDet2 : total_minus_undet_fsr[k][i] += diff_NoDet2*diff_NoDet2);

      if (total_plus_undet_fsr[k][i] != 0){
	h_Systematics_fsr_bare_plus[k]->SetBinContent(i+1,sqrt(total_plus_undet_fsr[k][i]));
	h_Systematics_fsr_bare_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_undet_fsr[k][i] != 0){
	h_Systematics_fsr_bare_minus[k]->SetBinContent(i+1,-sqrt(total_minus_undet_fsr[k][i]));
	h_Systematics_fsr_bare_minus[k]->SetBinError(i+1,0.000000001);
      }
       //fsr table bare level
      /*
	 if (k == 0 && i == 0){ 
	 cout<<"FSR SYSTEMATICS (BARE LEPTON LEVEL)"<<endl;
	 cout<<"---------------"<<endl;
	 cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
	 cout<<"-------------------------------------------------------------------"<<endl;
	 }
	 cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_NoDet1<<"  &  "<<setprecision(3)<<diff_NoDet2<<"    \\\\    "<<endl;
       //end of fsr table bare lepton level
       */
      MC_UnDet_AFB_FSR_Diff_Up[i] = diff_NoDet1;//TMath::Max(diff1,diff2);
      MC_UnDet_AFB_FSR_Diff_Down[i] = diff_NoDet2;//TMath::Min(diff1,diff2);
      h_MC_UnDet_AFB_FSR_Diff_Up[k]->SetBinContent(i+1,MC_UnDet_AFB_FSR_Diff_Up[i]);
      h_MC_UnDet_AFB_FSR_Diff_Down[k]->SetBinContent(i+1,MC_UnDet_AFB_FSR_Diff_Down[i]);
      //


     //
      diff_NoDet1 = 0;
      diff_NoDet2 = 0;

      MC_UnDet_AFB_NoWeight[i] = AFB(MC_Unfolded_UnDet_Forward_NoWeight[k][i],MC_Unfolded_UnDet_Backward_NoWeight[k][i]);
      diff_NoDet1 = MC_UnDet_AFB_NoWeight[i]-MC_UnDet_AFB[i];
      if (i == nb-1){
	if (fabs(diff_NoDet1) > fabs(MC_UnDet_AFB_NoWeight[i-1]-MC_UnDet_AFB[i-1])) diff_NoDet1 = MC_UnDet_AFB_NoWeight[i-1]-MC_UnDet_AFB[i-1];
      }
      if (diff1 >0. ? total_plus_undet[k][i] += diff_NoDet1*diff_NoDet1 : total_minus_undet[k][i] += diff_NoDet1*diff_NoDet1);
      if (diff1 >0. ? total_plus_undet_noweight[k][i] += diff_NoDet1*diff_NoDet1 : total_minus_undet_noweight[k][i] += diff_NoDet1*diff_NoDet1);
      if (total_plus_undet_noweight[k][i] != 0){
	h_Systematics_noweight_bare_plus[k]->SetBinContent(i+1,sqrt(total_plus_undet_noweight[k][i]));
	h_Systematics_noweight_bare_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_undet_noweight[k][i] != 0){
	h_Systematics_noweight_bare_minus[k]->SetBinContent(i+1,-sqrt(total_minus_undet_noweight[k][i]));
	h_Systematics_noweight_bare_minus[k]->SetBinError(i+1,0.000000001);
      }
      //


//es syst at bare lepton
      diff_NoDet1 = 0;
      diff_NoDet2 = 0;

      MC_UnDet_AFB_ES_UP[i] = AFB(MC_Unfolded_UnDet_Forward_ES_Up[k][i],MC_Unfolded_UnDet_Backward_ES_Up[k][i]);
      MC_UnDet_AFB_ES_DOWN[i] = AFB(MC_Unfolded_UnDet_Forward_ES_Down[k][i],MC_Unfolded_UnDet_Backward_ES_Down[k][i]);
      h_MC_UnDet_AFB_ES_UP[k]->SetBinContent(i+1,MC_UnDet_AFB_ES_UP[i]);
      h_MC_UnDet_AFB_ES_DOWN[k]->SetBinContent(i+1,MC_UnDet_AFB_ES_DOWN[i]);
      diff_NoDet1 = MC_UnDet_AFB_ES_UP[i]-MC_UnDet_AFB[i];
      diff_NoDet2 = MC_UnDet_AFB_ES_DOWN[i]-MC_UnDet_AFB[i];
      //
      if (i == nb-1){
	if (fabs(diff_NoDet1) > fabs(MC_UnDet_AFB_ES_UP[i-1]-MC_UnDet_AFB[i-1])) diff_NoDet1 = MC_UnDet_AFB_ES_UP[i-1]-MC_UnDet_AFB[i-1];
	if (fabs(diff_NoDet2) > fabs(MC_UnDet_AFB_ES_DOWN[i-1]-MC_UnDet_AFB[i-1])) diff_NoDet2 = MC_UnDet_AFB_ES_DOWN[i-1]-MC_UnDet_AFB[i-1];
      }
      //
      if (diff_NoDet1 >0. ? total_plus_undet[k][i] += diff_NoDet1*diff_NoDet1 : total_minus_undet[k][i] += diff_NoDet1*diff_NoDet1);
      if (diff_NoDet2 >0. ? total_plus_undet[k][i] += diff_NoDet2*diff_NoDet2 : total_minus_undet[k][i] += diff_NoDet2*diff_NoDet2);
      if (diff_NoDet1 >0. ? total_plus_undet_es[k][i] += diff_NoDet1*diff_NoDet1 : total_minus_undet_es[k][i] += diff_NoDet1*diff_NoDet1);
      if (diff_NoDet2 >0. ? total_plus_undet_es[k][i] += diff_NoDet2*diff_NoDet2 : total_minus_undet_es[k][i] += diff_NoDet2*diff_NoDet2);

      if (total_plus_undet_es[k][i] != 0){
        h_Systematics_es_bare_plus[k]->SetBinContent(i+1,sqrt(total_plus_undet_es[k][i]));
        h_Systematics_es_bare_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_undet_es[k][i] != 0){
        h_Systematics_es_bare_minus[k]->SetBinContent(i+1,-sqrt(total_minus_undet_es[k][i]));
        h_Systematics_es_bare_minus[k]->SetBinError(i+1,0.000000001);
      }
       //fsr table bare level
      /*
         if (k == 0 && i == 0){ 
         cout<<"FSR SYSTEMATICS (BARE LEPTON LEVEL)"<<endl;
         cout<<"---------------"<<endl;
         cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
         cout<<"-------------------------------------------------------------------"<<endl;
         }
         cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_NoDet1<<"  &  "<<setprecision(3)<<diff_NoDet2<<"    \\\\    "<<endl;
       //end of fsr table bare lepton level
       */
      MC_UnDet_AFB_ES_Diff_Up[i] = diff_NoDet1;//TMath::Max(diff1,diff2);
      MC_UnDet_AFB_ES_Diff_Down[i] = diff_NoDet2;//TMath::Min(diff1,diff2);
      h_MC_UnDet_AFB_ES_Diff_Up[k]->SetBinContent(i+1,MC_UnDet_AFB_ES_Diff_Up[i]);
      h_MC_UnDet_AFB_ES_Diff_Down[k]->SetBinContent(i+1,MC_UnDet_AFB_ES_Diff_Down[i]);

//

      //bkg systematics bare lepton level
      MC_UnDet_AFB_bkg[i] = AFB(MC_Unfolded_UnDet_Forward_bkg[k][i],MC_Unfolded_UnDet_Backward_bkg[k][i]);
      h_MC_Unfolded_UnDet_AFB_bkg[k]->SetBinContent(i+1,MC_UnDet_AFB_bkg[i]);

      MC_UnDet_AFB_bkg_UP[i] = AFB(MC_Unfolded_UnDet_Forward_bkg_Up[k][i],MC_Unfolded_UnDet_Backward_bkg_Up[k][i]);
      h_MC_Unfolded_UnDet_AFB_bkg_UP[k]->SetBinContent(i+1,MC_UnDet_AFB_bkg_UP[i]);
      MC_UnDet_AFB_bkg_DOWN[i] = AFB(MC_Unfolded_UnDet_Forward_bkg_Down[k][i],MC_Unfolded_UnDet_Backward_bkg_Down[k][i]);
      h_MC_Unfolded_UnDet_AFB_bkg_DOWN[k]->SetBinContent(i+1,MC_UnDet_AFB_bkg_DOWN[i]);
      diff_NoDet1 = 0;
      diff_NoDet2 = 0;
      diff_NoDet1 = MC_UnDet_AFB_bkg_UP[i]-MC_UnDet_AFB_bkg[i];//MC_UnDet_AFB[i];
      diff_NoDet2 = MC_UnDet_AFB_bkg_DOWN[i]-MC_UnDet_AFB_bkg[i];//MC_UnDet_AFB[i];
      if (diff_NoDet1 >0. ? total_plus_undet[k][i] += diff_NoDet1*diff_NoDet1 : total_minus_undet[k][i] += diff_NoDet1*diff_NoDet1);
      if (diff_NoDet2 >0. ? total_plus_undet[k][i] += diff_NoDet2*diff_NoDet2 : total_minus_undet[k][i] += diff_NoDet2*diff_NoDet2);
      if (diff_NoDet1 >0. ? total_plus_undet_bkg[k][i] += diff_NoDet1*diff_NoDet1 : total_minus_undet_bkg[k][i] += diff_NoDet1*diff_NoDet1);
      if (diff_NoDet2 >0. ? total_plus_undet_bkg[k][i] += diff_NoDet2*diff_NoDet2 : total_minus_undet_bkg[k][i] += diff_NoDet2*diff_NoDet2);
      if (total_plus_undet_bkg[k][i] != 0){
	h_Systematics_bkg_bare_plus[k]->SetBinError(i+1,0.00000001);
	h_Systematics_bkg_bare_plus[k]->SetBinContent(i+1,sqrt(total_plus_undet_bkg[k][i]));
      }
      if (total_minus_undet_bkg[k][i] != 0){
	h_Systematics_bkg_bare_minus[k]->SetBinContent(i+1,-sqrt(total_minus_undet_bkg[k][i]));   
	h_Systematics_bkg_bare_minus[k]->SetBinError(i+1,0.00000001);
      }
      //bkg table bare level
      /*
      if (k == 0 && i == 0){ 
	cout<<"bkg SYSTEMATICS (BARE LEPTON LEVEL)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    bkg Up - Nominal           bkg Down - Nominal"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
      }
      cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_NoDet1<<"  &  "<<setprecision(3)<<diff_NoDet2<<"    \\\\    "<<endl;
      */
      //end of bkg table bare lepton level

      MC_UnDet_AFB_bkg_Diff_Up[i] = diff_NoDet1;//TMath::Max(diff1,diff2);
      MC_UnDet_AFB_bkg_Diff_Down[i] = diff_NoDet2;//TMath::Min(diff1,diff2);
      h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[k]->SetBinContent(i+1,MC_UnDet_AFB_bkg_Diff_Up[i]);
      h_MC_Unfolded_UnDet_AFB_bkg_Diff_Down[k]->SetBinContent(i+1,MC_UnDet_AFB_bkg_Diff_Down[i]);
      //

      MC_NoFsr_AFB[i] = AFB(hNoFsrTruthCos_M_Y_Forward[k]->GetBinContent(i+1),hNoFsrTruthCos_M_Y_Backward[k]->GetBinContent(i+1));
      h_MC_NoFsr_AFB[k]->SetBinContent(i+1,MC_NoFsr_AFB[i]);
      h_MC_NoFsr_AFB[k]->SetBinError(i+1,RAWAFBERROR(MC_NoFsr_AFB[i],hNoFsrTruthCos_M_Y_Forward[k]->GetBinContent(i+1),hNoFsrTruthCos_M_Y_Backward[k]->GetBinContent(i+1)));
      //
      MC_True_AFB[i] = AFB(hTrueCos_M_Y_Forward[k]->GetBinContent(i+1),hTrueCos_M_Y_Backward[k]->GetBinContent(i+1));
      h_MC_True_AFB[k]->SetBinContent(i+1,MC_True_AFB[i]);
      dilution[k][i] = MC_True_AFB[i]/MC_NoFsr_AFB[i];
      //cout<<k<<"  "<<i<<"   "<<MC_True_AFB[i]<<"   "<<MC_NoFsr_AFB[i]<<"   "<<dilution[k][i]<<endl;
     //


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


      //combined measurement
      combined[i] = AFB(Unfolded_NoFsr_Forward[k][i]+data_bornf[i][k],Unfolded_NoFsr_Backward[k][i]+data_bornb[i][k]);
      cout<<i<<"  "<<k<<"  "<<Unfolded_NoFsr_Forward[k][i]<<"  "<<data_bornf[i][k]<<"   "<<Unfolded_NoFsr_Backward[k][i]<<"  "<<data_bornb[i][k]<<endl;
      cout<<combined[i]<<endl;
      h_Combined[k]->SetBinContent(i+1,combined[i]);
        for (int j=0;j<nb;j++){
          first_sum_comb[i] += pow(Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1),2)*sqrt(pow(hMeasCos_M_Y_Forward[k]->GetBinContent(j+1),2)+pow(data_rawf[j][k],2));
          second_sum_comb[i] += pow(Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1),2)*sqrt(pow(hMeasCos_M_Y_Backward[k]->GetBinContent(j+1),2)+pow(data_rawb[j][k],2));
      }
      first_sum_comb[i] *= 4*pow(Unfolded_NoFsr_Forward[k][i]+data_bornf[i][k],2)/pow(Unfolded_NoFsr_Forward[k][i]+Unfolded_NoFsr_Backward[k][i]+data_bornf[i][k]+data_bornb[i][k],4);
      second_sum_comb[i] *= 4*pow(Unfolded_NoFsr_Backward[k][i]+data_bornb[i][k],2)/pow(Unfolded_NoFsr_Forward[k][i]+Unfolded_NoFsr_Backward[k][i]+data_bornf[i][k]+data_bornb[i][k],4);
      Unfolded_NoFsr_COMB_error[i] = sqrt(first_sum_comb[i]+second_sum_comb[i]);    
      h_Combined[k]->SetBinError(i+1,Unfolded_NoFsr_COMB_error[i]); 

/*
      if (k == 0){
	for (int j=0;j<nb;j++){
	  first_sum_comb[i] += pow(Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1),2)*hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	  second_sum_comb[i] += pow(Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1),2)*hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
          third_sum_comb[i] += pow(h_RFF__1->GetBinContent(j+1,i+1),2)*data_rawf[j][k];
          fourth_sum_comb[i] += pow(h_RBB__1->GetBinContent(j+1,i+1),2)*data_rawb[j][k];
	}
      }
      if (k == 1){
	for (int j=0;j<nb;j++){
          first_sum_comb[i] += pow(Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1),2)*hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);          second_sum_comb[i] += pow(Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1),2)*hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
          third_sum_comb[i] += pow(h_RFF__2->GetBinContent(j+1,i+1),2)*data_rawf[j][k];
          fourth_sum_comb[i] += pow(h_RBB__2->GetBinContent(j+1,i+1),2)*data_rawb[j][k];
	}
      }
      if (k == 2){
	for (int j=0;j<nb;j++){
          first_sum_comb[i] += pow(Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1),2)*hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);          second_sum_comb[i] += pow(Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1),2)*hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
          third_sum_comb[i] += pow(h_RFF__3->GetBinContent(j+1,i+1),2)*data_rawf[j][k];
          fourth_sum_comb[i] += pow(h_RBB__3->GetBinContent(j+1,i+1),2)*data_rawb[j][k];
	}
      }
      if (k == 3){
	for (int j=0;j<nb;j++){
          first_sum_comb[i] += pow(Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1),2)*hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);          second_sum_comb[i] += pow(Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1),2)*hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
          third_sum_comb[i] += pow(h_RFF__4->GetBinContent(j+1,i+1),2)*data_rawf[j][k];
          fourth_sum_comb[i] += pow(h_RBB__4->GetBinContent(j+1,i+1),2)*data_rawb[j][k];
	}
      }
      first_sum_comb[i] *= 4*pow(Unfolded_NoFsr_Forward[k][i],2)/pow(Unfolded_NoFsr_Forward[k][i]+Unfolded_NoFsr_Backward[k][i],4);
      second_sum_comb[i] *= 4*pow(Unfolded_NoFsr_Backward[k][i],2)/pow(Unfolded_NoFsr_Forward[k][i]+Unfolded_NoFsr_Backward[k][i],4);
      third_sum_comb[i] *= 4*pow(data_bornf[i][k],2)/pow(data_bornf[i][k]+data_bornb[i][k],4);
      fourth_sum_comb[i] *= 4*pow(data_bornb[i][k],2)/pow(data_bornf[i][k]+data_bornb[i][k],4);
      Unfolded_NoFsr_COMB_error[i] = sqrt(first_sum_comb[i]+second_sum_comb[i]+third_sum_comb[i]+fourth_sum_comb[i]);    
      h_Combined[k]->SetBinError(i+1,Unfolded_NoFsr_COMB_error[i]); 
*/
      //


      for (int j=0;j<nb;j++){
	error_closure_forward[i] += pow(Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1),2)*hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	error_closure_backward[i] += pow(Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1),2)*hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
      }
      error_closure_forward[i] = sqrt(error_closure_forward[i]);
      error_closure_backward[i] = sqrt(error_closure_backward[i]);

      h_Closure_Unfolded_NoFsr_Forward[k]->SetBinContent(i+1,Closure_Unfolded_NoFsr_Forward[k][i]);
      h_Closure_Unfolded_NoFsr_Forward[k]->SetBinError(i+1,error_closure_forward[i]);

      h_Closure_Unfolded_NoFsr_Backward[k]->SetBinContent(i+1,Closure_Unfolded_NoFsr_Backward[k][i]);
      h_Closure_Unfolded_NoFsr_Backward[k]->SetBinError(i+1,error_closure_backward[i]);	

      for (int j=0;j<nb;j++){
	closure_first_sum[i] += pow(Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1),2)*hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	closure_second_sum[i] += pow(Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1),2)*hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
      }
      closure_first_sum[i] *= 4*pow(Closure_Unfolded_NoFsr_Forward[k][i],2)/pow(Closure_Unfolded_NoFsr_Forward[k][i]+Closure_Unfolded_NoFsr_Backward[k][i],4);
      closure_second_sum[i] *= 4*pow(Closure_Unfolded_NoFsr_Backward[k][i],2)/pow(Closure_Unfolded_NoFsr_Forward[k][i]+Closure_Unfolded_NoFsr_Backward[k][i],4);
      closure_Unfolded_NoFsr_error[i] = sqrt(closure_first_sum[i]+closure_second_sum[i]);

      h_Closure_Unfolded_NoFsr_AFB[k]->SetBinContent(i+1,Closure_Unfolded_NoFsr_AFB[i]);
      h_Closure_Unfolded_NoFsr_AFB[k]->SetBinError(i+1,closure_Unfolded_NoFsr_error[i]);

   

      MC_Unfolded_NoFsr_AFB_FSR_Up[i] = AFB(MC_Unfolded_NoFsr_Forward_FSR_Up[k][i],MC_Unfolded_NoFsr_Backward_FSR_Up[k][i]);
      MC_Unfolded_NoFsr_AFB_FSR_Down[i] = AFB(MC_Unfolded_NoFsr_Forward_FSR_Down[k][i],MC_Unfolded_NoFsr_Backward_FSR_Down[k][i]);
      float diff_undet1 = MC_Unfolded_NoFsr_AFB_FSR_Up[i]-MC_NoFsr_AFB[i];//Closure_Unfolded_NoFsr_AFB[i];//-MC_UnDet_AFB[i];
      float diff_undet2 = MC_Unfolded_NoFsr_AFB_FSR_Down[i]-MC_NoFsr_AFB[i];//Closure_Unfolded_NoFsr_AFB[i];//-MC_UnDet_AFB[i];
      h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Up[k]->SetBinContent(i+1,diff_undet1);
      h_MC_Unfolded_NoFsr_AFB_FSR_Diff_Down[k]->SetBinContent(i+1,diff_undet2);
      //
      if (i == nb-1){
	if (fabs(diff_undet1) > fabs(MC_Unfolded_NoFsr_AFB_FSR_Up[i-1]-MC_NoFsr_AFB[i-1])) diff_undet1 = MC_Unfolded_NoFsr_AFB_FSR_Up[i-1]-MC_UnDet_AFB[i-1];
	if (fabs(diff_undet2) > fabs(MC_Unfolded_NoFsr_AFB_FSR_Down[i-1]-MC_NoFsr_AFB[i-1])) diff_undet2 = MC_Unfolded_NoFsr_AFB_FSR_Down[i-1]-MC_UnDet_AFB[i-1];
      }
      //
      if (diff_undet1 >0. ? total_plus_nofsr[k][i] += diff_undet1*diff_undet1 : total_minus_nofsr[k][i] += diff_undet1*diff_undet1);
      if (diff_undet2 >0. ? total_plus_nofsr[k][i] += diff_undet2*diff_undet2 : total_minus_nofsr[k][i] += diff_undet2*diff_undet2);

      if (diff_undet1 >0. ? total_plus_nofsr_fsr[k][i] += diff_undet1*diff_undet1 : total_minus_nofsr_fsr[k][i] += diff_undet1*diff_undet1);
      if (diff_undet2 >0. ? total_plus_nofsr_fsr[k][i] += diff_undet2*diff_undet2 : total_minus_nofsr_fsr[k][i] += diff_undet2*diff_undet2);
      if (total_plus_nofsr_fsr[k][i] != 0){
	h_Systematics_fsr_Born_plus[k]->SetBinContent(i+1,sqrt(total_plus_nofsr_fsr[k][i]));
	h_Systematics_fsr_Born_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_nofsr_fsr[k][i] != 0){
	h_Systematics_fsr_Born_minus[k]->SetBinContent(i+1,-sqrt(total_minus_nofsr_fsr[k][i]));
	h_Systematics_fsr_Born_minus[k]->SetBinError(i+1,0.000000001);
      }
    //fsr systematics born level table
      /*
	if (k == 0 && i == 0){ 
	cout<<"FSR SYSTEMATICS (Born Level)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
	cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_undet1<<"  &  "<<setprecision(3)<<diff_undet2<<"    \\\\    "<<endl;
      */
       //end of fsr systematics born level table


     //
      diff_undet1 = 0;
      diff_undet2 = 0;

      MC_Unfolded_NoFsr_AFB_NoWeight[i] = AFB(MC_Unfolded_NoFsr_Forward_NoWeight[k][i],MC_Unfolded_NoFsr_Backward_NoWeight[k][i]);
      diff_undet1 = MC_Unfolded_NoFsr_AFB_NoWeight[i]-MC_NoFsr_AFB[i];
      if (i == nb-1){
	if (fabs(diff_undet1) > fabs(MC_Unfolded_NoFsr_AFB_NoWeight[i-1]-MC_NoFsr_AFB[i-1])) diff_undet1 = MC_Unfolded_NoFsr_AFB_NoWeight[i-1]-MC_NoFsr_AFB[i-1];
      }
      if (diff1 >0. ? total_plus_nofsr[k][i] += diff_undet1*diff_undet1 : total_minus_nofsr[k][i] += diff_undet1*diff_undet1);
      if (diff1 >0. ? total_plus_nofsr_noweight[k][i] += diff_undet1*diff_undet1 : total_minus_nofsr_noweight[k][i] += diff_undet1*diff_undet1);
      if (total_plus_nofsr_noweight[k][i] != 0){
	h_Systematics_noweight_Born_plus[k]->SetBinContent(i+1,sqrt(total_plus_nofsr_noweight[k][i]));
	h_Systematics_noweight_Born_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_nofsr_noweight[k][i] != 0){
	h_Systematics_noweight_Born_minus[k]->SetBinContent(i+1,-sqrt(total_minus_nofsr_noweight[k][i]));
	h_Systematics_noweight_Born_minus[k]->SetBinError(i+1,0.000000001);
      }
      //


//es
      diff_undet1 = 0;
      diff_undet2 = 0;
      MC_Unfolded_NoFsr_AFB_ES_Up[i] = AFB(MC_Unfolded_NoFsr_Forward_ES_Up[k][i],MC_Unfolded_NoFsr_Backward_ES_Up[k][i]);
      MC_Unfolded_NoFsr_AFB_ES_Down[i] = AFB(MC_Unfolded_NoFsr_Forward_ES_Down[k][i],MC_Unfolded_NoFsr_Backward_ES_Down[k][i]);
      diff_undet1 = MC_Unfolded_NoFsr_AFB_ES_Up[i]-MC_NoFsr_AFB[i];//Closure_Unfolded_NoFsr_AFB[i];//-MC_UnDet_AFB[i];
      diff_undet2 = MC_Unfolded_NoFsr_AFB_ES_Down[i]-MC_NoFsr_AFB[i];//Closure_Unfolded_NoFsr_AFB[i];//-MC_UnDet_AFB[i];
      h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[k]->SetBinContent(i+1,diff_undet1);
      h_MC_Unfolded_NoFsr_AFB_ES_Diff_Down[k]->SetBinContent(i+1,diff_undet2);
      //
      if (i == nb-1){
	if (fabs(diff_undet1) > fabs(MC_Unfolded_NoFsr_AFB_ES_Up[i-1]-MC_NoFsr_AFB[i-1])) diff_undet1 = MC_Unfolded_NoFsr_AFB_ES_Up[i-1]-MC_UnDet_AFB[i-1];
	if (fabs(diff_undet2) > fabs(MC_Unfolded_NoFsr_AFB_ES_Down[i-1]-MC_NoFsr_AFB[i-1])) diff_undet2 = MC_Unfolded_NoFsr_AFB_ES_Down[i-1]-MC_UnDet_AFB[i-1];
      }
      //
      if (diff_undet1 >0. ? total_plus_nofsr[k][i] += diff_undet1*diff_undet1 : total_minus_nofsr[k][i] += diff_undet1*diff_undet1);
      if (diff_undet2 >0. ? total_plus_nofsr[k][i] += diff_undet2*diff_undet2 : total_minus_nofsr[k][i] += diff_undet2*diff_undet2);

      if (diff_undet1 >0. ? total_plus_nofsr_es[k][i] += diff_undet1*diff_undet1 : total_minus_nofsr_es[k][i] += diff_undet1*diff_undet1);
      if (diff_undet2 >0. ? total_plus_nofsr_es[k][i] += diff_undet2*diff_undet2 : total_minus_nofsr_es[k][i] += diff_undet2*diff_undet2);
      if (total_plus_nofsr_es[k][i] != 0){
        h_Systematics_es_Born_plus[k]->SetBinContent(i+1,sqrt(total_plus_nofsr_es[k][i]));
        h_Systematics_es_Born_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_nofsr_es[k][i] != 0){
        h_Systematics_es_Born_minus[k]->SetBinContent(i+1,-sqrt(total_minus_nofsr_es[k][i]));
        h_Systematics_es_Born_minus[k]->SetBinError(i+1,0.000000001);
      }
//


      MC_Unfolded_NoFsr_AFB_bkg[i] = AFB(MC_Unfolded_NoFsr_Forward_bkg[k][i],MC_Unfolded_NoFsr_Backward_bkg[k][i]);

      MC_Unfolded_NoFsr_AFB_bkg_Up[i] = AFB(MC_Unfolded_NoFsr_Forward_bkg_Up[k][i],MC_Unfolded_NoFsr_Backward_bkg_Up[k][i]);
      MC_Unfolded_NoFsr_AFB_bkg_Down[i] = AFB(MC_Unfolded_NoFsr_Forward_bkg_Down[k][i],MC_Unfolded_NoFsr_Backward_bkg_Down[k][i]);
      diff_undet1 = 0;
      diff_undet2 = 0;
      diff_undet1 = MC_Unfolded_NoFsr_AFB_bkg_Up[i]-MC_Unfolded_NoFsr_AFB_bkg[i];
      diff_undet2 = MC_Unfolded_NoFsr_AFB_bkg_Down[i]-MC_Unfolded_NoFsr_AFB_bkg[i];
      h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[k]->SetBinContent(i+1,diff_undet1);
      h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Down[k]->SetBinContent(i+1,diff_undet2);
      if (diff_undet1 >0. ? total_plus_nofsr[k][i] += diff_undet1*diff_undet1 : total_minus_nofsr[k][i] += diff_undet1*diff_undet1);
      if (diff_undet2 >0. ? total_plus_nofsr[k][i] += diff_undet2*diff_undet2 : total_minus_nofsr[k][i] += diff_undet2*diff_undet2);

      if (diff_undet1 >0. ? total_plus_nofsr_bkg[k][i] += diff_undet1*diff_undet1 : total_minus_nofsr_bkg[k][i] += diff_undet1*diff_undet1);
      if (diff_undet2 >0. ? total_plus_nofsr_bkg[k][i] += diff_undet2*diff_undet2 : total_minus_nofsr_bkg[k][i] += diff_undet2*diff_undet2);
      if (total_plus_nofsr_bkg[k][i] != 0){
	h_Systematics_bkg_Born_plus[k]->SetBinContent(i+1,sqrt(total_plus_nofsr_bkg[k][i]));
	h_Systematics_bkg_Born_plus[k]->SetBinError(i+1,0.00000000001);
      }
      if (total_minus_nofsr_bkg[k][i] != 0){
	h_Systematics_bkg_Born_minus[k]->SetBinContent(i+1,-sqrt(total_minus_nofsr_bkg[k][i]));
	h_Systematics_bkg_Born_minus[k]->SetBinError(i+1,0.00000000001);
      }
      //bkg systematics born level table
      /*
      if (k == 0 && i == 0){ 
	cout<<"Bkg SYSTEMATICS (Born Level)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    bkg Up - Nominal           bkg Down - Nominal"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
      }
      cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_undet1<<"  &  "<<setprecision(3)<<diff_undet2<<"    \\\\    "<<endl;
      */
      //end of fsr systematics born level table
      
    } 

    cout<<"sin2theta!"<<endl;
 
    for (int i=3;i<7;i++){//nb_sin
      MC_Raw_sin2312_AFB[i] = 0;
      MC_Raw_sin2412_AFB[i] = 0;
      MC_Raw_sin2212_AFB[i] = 0;

      MC_True_sin2312_AFB[i] = 0;
      MC_True_sin2412_AFB[i] = 0;
      MC_True_sin2212_AFB[i] = 0;


      MC_Unfolded_UnDet_sin2312_Forward[k][i] = 0;
      MC_Unfolded_UnDet_sin2312_Backward[k][i] = 0;
      MC_Unfolded_UnDet_sin2412_Forward[k][i] = 0;
      MC_Unfolded_UnDet_sin2412_Backward[k][i] = 0;
      MC_Unfolded_UnDet_sin2212_Forward[k][i] = 0;
      MC_Unfolded_UnDet_sin2212_Backward[k][i] = 0;
      MC_Unfolded_UnDet_sin2312_AFB[i] = 0;
      MC_Unfolded_UnDet_sin2412_AFB[i] = 0;
      MC_Unfolded_UnDet_sin2212_AFB[i] = 0;
      MC_Unfolded_NoFsr_sin2312_Forward[k][i] = 0;
      MC_Unfolded_NoFsr_sin2312_Backward[k][i] = 0;
      MC_Unfolded_NoFsr_sin2412_Forward[k][i] = 0;
      MC_Unfolded_NoFsr_sin2412_Backward[k][i] = 0;
      MC_Unfolded_NoFsr_sin2212_Forward[k][i] = 0;
      MC_Unfolded_NoFsr_sin2212_Backward[k][i] = 0;
      MC_Unfolded_NoFsr_sin2312_AFB[i] = 0;
      MC_Unfolded_NoFsr_sin2412_AFB[i] = 0;
      MC_Unfolded_NoFsr_sin2212_AFB[i] = 0;
      MC_Raw_sin2312_AFB[i] = AFB(h_Sin2312_MeasCos_M_Y_Forward[k]->GetBinContent(i+1),h_Sin2312_MeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_sin2412_AFB[i] = AFB(h_Sin2412_MeasCos_M_Y_Forward[k]->GetBinContent(i+1),h_Sin2412_MeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_sin2212_AFB[i] = AFB(h_Sin2212_MeasCos_M_Y_Forward[k]->GetBinContent(i+1),h_Sin2212_MeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      float diff1 = MC_Raw_sin2412_AFB[i]-MC_Raw_sin2312_AFB[i];
      float diff2 = MC_Raw_sin2212_AFB[i]-MC_Raw_sin2312_AFB[i];
      h_MC_Raw_sin2412m2312_AFB[k]->SetBinContent(i+1,diff1);
      h_MC_Raw_sin2212m2312_AFB[k]->SetBinContent(i+1,diff2);
      /* We do not include sin2thetaW in the systamtic uncertainty
      if (diff1 >0. ? total_plus[k][i] += diff1*diff1 : total_minus[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus[k][i] += diff2*diff2 : total_minus[k][i] += diff2*diff2);
      */
      if (diff1 >0. ? total_plus_sin[k][i] += diff1*diff1 : total_minus_sin[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus_sin[k][i] += diff2*diff2 : total_minus_sin[k][i] += diff2*diff2);
      if (total_plus_sin[k][i] != 0){
	h_Systematics_sin_raw_plus[k]->SetBinContent(i+1,sqrt(total_plus_sin[k][i]));
	h_Systematics_sin_raw_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_sin[k][i] != 0){
	h_Systematics_sin_raw_minus[k]->SetBinContent(i+1,-sqrt(total_minus_sin[k][i]));
	h_Systematics_sin_raw_minus[k]->SetBinError(i+1,0.000000001);
      }

     cout<<"sin2theta   "<<i<<endl;

      MC_True_sin2312_AFB[i] = AFB(h_SinTrue2312_MeasCos_M_Y_Forward[k]->GetBinContent(i+1),h_SinTrue2312_MeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_True_sin2412_AFB[i] = AFB(h_SinTrue2412_MeasCos_M_Y_Forward[k]->GetBinContent(i+1),h_SinTrue2412_MeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_True_sin2212_AFB[i] = AFB(h_SinTrue2212_MeasCos_M_Y_Forward[k]->GetBinContent(i+1),h_SinTrue2212_MeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      float err2312 = RAWAFBERROR(MC_True_sin2312_AFB[i],h_SinTrue2312_MeasCos_M_Y_Forward[k]->GetBinContent(i+1),h_SinTrue2312_MeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      float err2212 = RAWAFBERROR(MC_True_sin2212_AFB[i],h_SinTrue2212_MeasCos_M_Y_Forward[k]->GetBinContent(i+1),h_SinTrue2212_MeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      float err2412 = RAWAFBERROR(MC_True_sin2412_AFB[i],h_SinTrue2412_MeasCos_M_Y_Forward[k]->GetBinContent(i+1),h_SinTrue2412_MeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      float diff1_m = MC_True_sin2412_AFB[i]-MC_True_sin2312_AFB[i];
      float diff2_m = MC_True_sin2212_AFB[i]-MC_True_sin2312_AFB[i];
      float diff1_m_err = sqrt(err2312*err2312+err2412*err2412);
      float diff2_m_err = sqrt(err2312*err2312+err2212*err2412);
      h_MC_True_sin2412m2312_AFB[k]->SetBinContent(i+1,diff1_m);
      h_MC_True_sin2212m2312_AFB[k]->SetBinContent(i+1,diff2_m);
      h_MC_True_sin2412m2312_AFB[k]->SetBinError(i+1,diff1_m_err);
      h_MC_True_sin2212m2312_AFB[k]->SetBinError(i+1,diff2_m_err);


     cout<<"sin2theta   2   "<<i<<endl;


      /*
      //sin2thetaW systematics raw level table
      if (k == 0 && i == 0){ 
      cout<<"sin2thetaW SYSTEMATICS (Raw Level)"<<endl;
      cout<<"---------------"<<endl;
      cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
      cout<<"-------------------------------------------------------------------"<<endl;
      }
      cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff1<<"  &  "<<setprecision(3)<<diff2<<"    \\\\    "<<endl;
      //end of sin2theta systematics raw level table
      */
      for (int j=0;j<nb;j++){
	MC_Unfolded_UnDet_sin2312_Forward[k][i] += Inv_Response_Sin2312_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*h_Sin2312_MeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_sin2312_Backward[k][i] += Inv_Response_Sin2312_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*h_Sin2312_MeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_sin2412_Forward[k][i] += Inv_Response_Sin2412_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*h_Sin2412_MeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_sin2412_Backward[k][i] += Inv_Response_Sin2412_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*h_Sin2412_MeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_sin2212_Forward[k][i] += Inv_Response_Sin2212_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*h_Sin2212_MeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_Unfolded_UnDet_sin2212_Backward[k][i] += Inv_Response_Sin2212_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*h_Sin2212_MeasCos_M_Y_Backward[k]->GetBinContent(j+1);

	MC_Unfolded_NoFsr_sin2312_Forward[k][i] += Inv_Response_Sin2312_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*h_Sin2312_MeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_sin2312_Backward[k][i] += Inv_Response_Sin2312_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*h_Sin2312_MeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_sin2412_Forward[k][i] += Inv_Response_Sin2412_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*h_Sin2412_MeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_sin2412_Backward[k][i] += Inv_Response_Sin2412_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*h_Sin2412_MeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_sin2212_Forward[k][i] += Inv_Response_Sin2212_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*h_Sin2212_MeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_Unfolded_NoFsr_sin2212_Backward[k][i] += Inv_Response_Sin2212_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*h_Sin2212_MeasCos_M_Y_Backward[k]->GetBinContent(j+1);
      }
      MC_Unfolded_UnDet_sin2312_AFB[i] = AFB(MC_Unfolded_UnDet_sin2312_Forward[k][i],MC_Unfolded_UnDet_sin2312_Backward[k][i]);
      MC_Unfolded_UnDet_sin2412_AFB[i] = AFB(MC_Unfolded_UnDet_sin2412_Forward[k][i],MC_Unfolded_UnDet_sin2412_Backward[k][i]);
      MC_Unfolded_UnDet_sin2212_AFB[i] = AFB(MC_Unfolded_UnDet_sin2212_Forward[k][i],MC_Unfolded_UnDet_sin2212_Backward[k][i]);
      diff1 = 0;
      diff2 = 0;
      diff1 = MC_Unfolded_UnDet_sin2412_AFB[i]-MC_Unfolded_UnDet_sin2312_AFB[i];
      diff2 = MC_Unfolded_UnDet_sin2212_AFB[i]-MC_Unfolded_UnDet_sin2312_AFB[i];
      h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[k]->SetBinContent(i+1,diff1);
      h_MC_Unfolded_UnDet_AFB_Diff_sin2212m2312[k]->SetBinContent(i+1,diff2);
      /* We do not include sin2thetaW in the systamtic uncertainty
      if (diff1 >0. ? total_plus_undet[k][i] += diff1*diff1 : total_minus_undet[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus_undet[k][i] += diff2*diff2 : total_minus_undet[k][i] += diff2*diff2);
      */
      if (diff1 >0. ? total_plus_undet_sin[k][i] += diff1*diff1 : total_minus_undet_sin[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus_undet_sin[k][i] += diff2*diff2 : total_minus_undet_sin[k][i] += diff2*diff2);
      if (total_plus_undet_sin[k][i] != 0){
	h_Systematics_sin_bare_plus[k]->SetBinContent(i+1,sqrt(total_plus_undet_sin[k][i]));
	h_Systematics_sin_bare_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_undet_sin[k][i] != 0){
	h_Systematics_sin_bare_minus[k]->SetBinContent(i+1,-sqrt(total_minus_undet_sin[k][i]));
	h_Systematics_sin_bare_minus[k]->SetBinError(i+1,0.000000001);
      }
      //sin2thetaW systematics bare lepton level table
      /*
	if (k == 0 && i == 0){ 
	cout<<"sin2thetaW SYSTEMATICS (Bare Lepton Level)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
	cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff1<<"  &  "<<setprecision(3)<<diff2<<"    \\\\    "<<endl;
      */
      //end of sin2theta systematics bare lepton level table

      MC_Unfolded_NoFsr_sin2312_AFB[i] = AFB(MC_Unfolded_NoFsr_sin2312_Forward[k][i],MC_Unfolded_NoFsr_sin2312_Backward[k][i]);
      MC_Unfolded_NoFsr_sin2412_AFB[i] = AFB(MC_Unfolded_NoFsr_sin2412_Forward[k][i],MC_Unfolded_NoFsr_sin2412_Backward[k][i]);
      MC_Unfolded_NoFsr_sin2212_AFB[i] = AFB(MC_Unfolded_NoFsr_sin2212_Forward[k][i],MC_Unfolded_NoFsr_sin2212_Backward[k][i]);
      diff1 = 0;
      diff2 = 0;
      diff1 = MC_Unfolded_NoFsr_sin2412_AFB[i]-MC_Unfolded_NoFsr_sin2312_AFB[i];
      diff2 = MC_Unfolded_NoFsr_sin2212_AFB[i]-MC_Unfolded_NoFsr_sin2312_AFB[i];
      h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[k]->SetBinContent(i+1,diff1);
      h_MC_Unfolded_NoFsr_AFB_Diff_sin2212m2312[k]->SetBinContent(i+1,diff2);
      /* We do not include sin2thetaW in the systamtic uncertainty
      if (diff1 >0. ? total_plus_nofsr[k][i] += diff1*diff1 : total_minus_nofsr[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus_nofsr[k][i] += diff2*diff2 : total_minus_nofsr[k][i] += diff2*diff2);
      */
      if (diff1 >0. ? total_plus_nofsr_sin[k][i] += diff1*diff1 : total_minus_nofsr_sin[k][i] += diff1*diff1);
      if (diff2 >0. ? total_plus_nofsr_sin[k][i] += diff2*diff2 : total_minus_nofsr_sin[k][i] += diff2*diff2);
      if (total_plus_nofsr_sin[k][i] != 0){
	h_Systematics_sin_Born_plus[k]->SetBinContent(i+1,sqrt(total_plus_nofsr_sin[k][i]));
	h_Systematics_sin_Born_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (total_minus_nofsr_sin[k][i] != 0){
	h_Systematics_sin_Born_minus[k]->SetBinContent(i+1,-sqrt(total_minus_nofsr_sin[k][i]));
	h_Systematics_sin_Born_minus[k]->SetBinError(i+1,0.000000001);
      }
      //sin2thetaW systematics born lepton level table
      /*
      if (k == 0 && i == 0){ 
	cout<<"sin2thetaW SYSTEMATICS (Born Level)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    FSR Up - Nominal           FSR Down - Nominal"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
      }
      cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff1<<"  &  "<<setprecision(3)<<diff2<<"    \\\\    "<<endl;
      //end of sin2theta systematics born lepton level table
      */
    }
    for (int i=0;i<nb;i++){//alignment loop
      MC_Raw_Align_Ideal_AFB[i] = 0;  
      MC_Raw_Align_Startup_AFB[i] = 0;   
      MC_Raw_Align_Bowing_AFB[i] = 0;   
      MC_Raw_Align_Elliptical_AFB[i] = 0;   
      MC_Raw_Align_Radial_AFB[i] = 0;   
      MC_Raw_Align_Sagitta_AFB[i] = 0;   
      MC_Raw_Align_Skew_AFB[i] = 0;   
      MC_Raw_Align_Telescope_AFB[i] = 0;   
      MC_Raw_Align_CurlV2TF_AFB[i] = 0;   
      MC_Raw_Align_Twist_AFB[i] = 0;   
      MC_Raw_Align_Zexpansion_AFB[i] = 0;   
 
      MC_UnDet_Align_Ideal_AFB[i] = 0;   
      MC_UnDet_Align_Startup_AFB[i] = 0;   
      MC_UnDet_Align_Bowing_AFB[i] = 0;   
      MC_UnDet_Align_Elliptical_AFB[i] = 0;   
      MC_UnDet_Align_Radial_AFB[i] = 0;   
      MC_UnDet_Align_Sagitta_AFB[i] = 0;   
      MC_UnDet_Align_Skew_AFB[i] = 0;   
      MC_UnDet_Align_Telescope_AFB[i] = 0;   
      MC_UnDet_Align_CurlV2TF_AFB[i] = 0;   
      MC_UnDet_Align_Twist_AFB[i] = 0;   
      MC_UnDet_Align_Zexpansion_AFB[i] = 0;  

      MC_UnDet_Align_Ideal_Forward[k][i] = 0;   
      MC_UnDet_Align_Startup_Forward[k][i] = 0;   
      MC_UnDet_Align_Bowing_Forward[k][i] = 0;   
      MC_UnDet_Align_Elliptical_Forward[k][i] = 0;   
      MC_UnDet_Align_Radial_Forward[k][i] = 0;   
      MC_UnDet_Align_Sagitta_Forward[k][i] = 0;   
      MC_UnDet_Align_Skew_Forward[k][i] = 0;   
      MC_UnDet_Align_Telescope_Forward[k][i] = 0;   
      MC_UnDet_Align_CurlV2TF_Forward[k][i] = 0;   
      MC_UnDet_Align_Twist_Forward[k][i] = 0;   
      MC_UnDet_Align_Zexpansion_Forward[k][i] = 0;  

      MC_UnDet_Align_Ideal_Backward[k][i] = 0;   
      MC_UnDet_Align_Startup_Backward[k][i] = 0;   
      MC_UnDet_Align_Bowing_Backward[k][i] = 0;   
      MC_UnDet_Align_Elliptical_Backward[k][i] = 0;   
      MC_UnDet_Align_Radial_Backward[k][i] = 0;   
      MC_UnDet_Align_Sagitta_Backward[k][i] = 0;   
      MC_UnDet_Align_Skew_Backward[k][i] = 0;   
      MC_UnDet_Align_Telescope_Backward[k][i] = 0;   
      MC_UnDet_Align_CurlV2TF_Backward[k][i] = 0;   
      MC_UnDet_Align_Twist_Backward[k][i] = 0;   
      MC_UnDet_Align_Zexpansion_Backward[k][i] = 0; 

      MC_NoFsr_Align_Ideal_AFB[i] = 0;   
      MC_NoFsr_Align_Startup_AFB[i] = 0;   
      MC_NoFsr_Align_Bowing_AFB[i] = 0;   
      MC_NoFsr_Align_Elliptical_AFB[i] = 0;   
      MC_NoFsr_Align_Radial_AFB[i] = 0;   
      MC_NoFsr_Align_Sagitta_AFB[i] = 0;   
      MC_NoFsr_Align_Skew_AFB[i] = 0;   
      MC_NoFsr_Align_Telescope_AFB[i] = 0;   
      MC_NoFsr_Align_CurlV2TF_AFB[i] = 0;   
      MC_NoFsr_Align_Twist_AFB[i] = 0;   
      MC_NoFsr_Align_Zexpansion_AFB[i] = 0;  

      MC_NoFsr_Align_Ideal_Forward[k][i] = 0;   
      MC_NoFsr_Align_Startup_Forward[k][i] = 0;   
      MC_NoFsr_Align_Bowing_Forward[k][i] = 0;   
      MC_NoFsr_Align_Elliptical_Forward[k][i] = 0;   
      MC_NoFsr_Align_Radial_Forward[k][i] = 0;   
      MC_NoFsr_Align_Sagitta_Forward[k][i] = 0;   
      MC_NoFsr_Align_Skew_Forward[k][i] = 0;   
      MC_NoFsr_Align_Telescope_Forward[k][i] = 0;   
      MC_NoFsr_Align_CurlV2TF_Forward[k][i] = 0;   
      MC_NoFsr_Align_Twist_Forward[k][i] = 0;   
      MC_NoFsr_Align_Zexpansion_Forward[k][i] = 0;  

      MC_NoFsr_Align_Ideal_Backward[k][i] = 0;   
      MC_NoFsr_Align_Startup_Backward[k][i] = 0;   
      MC_NoFsr_Align_Bowing_Backward[k][i] = 0;   
      MC_NoFsr_Align_Elliptical_Backward[k][i] = 0;   
      MC_NoFsr_Align_Radial_Backward[k][i] = 0;   
      MC_NoFsr_Align_Sagitta_Backward[k][i] = 0;   
      MC_NoFsr_Align_Skew_Backward[k][i] = 0;   
      MC_NoFsr_Align_Telescope_Backward[k][i] = 0;   
      MC_NoFsr_Align_CurlV2TF_Backward[k][i] = 0;   
      MC_NoFsr_Align_Twist_Backward[k][i] = 0;   
      MC_NoFsr_Align_Zexpansion_Backward[k][i] = 0; 




      MC_Raw_Align_Ideal_AFB[i] = AFB(Align_Ideal_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Ideal_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      h_Ideal_Geo_AFB[k]->SetBinContent(i+1,MC_Raw_Align_Ideal_AFB[i]);
      h_Ideal_Geo_AFB[k]->SetBinError(i+1,RAWAFBERROR(MC_Raw_Align_Ideal_AFB[i],Align_Ideal_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Ideal_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1)));

     

      MC_Raw_Align_Startup_AFB[i] = AFB(Align_Startup_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Startup_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_Bowing_AFB[i] = AFB(Align_Bowing_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Bowing_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_Elliptical_AFB[i] = AFB(Align_Elliptical_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Elliptical_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_Radial_AFB[i] = AFB(Align_Radial_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Radial_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_Sagitta_AFB[i] = AFB(Align_Sagitta_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Sagitta_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_Skew_AFB[i] = AFB(Align_Skew_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Skew_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_Telescope_AFB[i] = AFB(Align_Telescope_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Telescope_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_CurlV2TF_AFB[i] = AFB(Align_CurlV2TF_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_CurlV2TF_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_Twist_AFB[i] = AFB(Align_Twist_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Twist_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));
      MC_Raw_Align_Zexpansion_AFB[i] = AFB(Align_Zexpansion_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_Zexpansion_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1));

//

      h_CurlV2TF_AFB[k]->SetBinContent(i+1,MC_Raw_Align_CurlV2TF_AFB[i]);
      h_CurlV2TF_AFB[k]->SetBinError(i+1,RAWAFBERROR(MC_Raw_Align_CurlV2TF_AFB[i],Align_CurlV2TF_hMeasCos_M_Y_Forward[k]->GetBinContent(i+1),Align_CurlV2TF_hMeasCos_M_Y_Backward[k]->GetBinContent(i+1)));

//  
      float diff_Startup = MC_Raw_Align_Startup_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_Bowing = MC_Raw_Align_Bowing_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_Elliptical = MC_Raw_Align_Elliptical_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_Radial = MC_Raw_Align_Radial_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_Sagitta = MC_Raw_Align_Sagitta_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_Skew = MC_Raw_Align_Skew_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_Telescope = MC_Raw_Align_Telescope_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_CurlV2TF = MC_Raw_Align_CurlV2TF_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_Twist = MC_Raw_Align_Twist_AFB[i] - MC_Raw_Align_Ideal_AFB[i];
      float diff_Zexpansion = MC_Raw_Align_Zexpansion_AFB[i] - MC_Raw_Align_Ideal_AFB[i];


      h_MC_Raw_Align_Startup_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Bowing);
      h_MC_Raw_Align_Bowing_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Bowing);
      h_MC_Raw_Align_Elliptical_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Elliptical);
      h_MC_Raw_Align_Radial_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Radial);
      h_MC_Raw_Align_Sagitta_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Sagitta);
      h_MC_Raw_Align_Skew_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Skew);
      h_MC_Raw_Align_Telescope_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Telescope);
      h_MC_Raw_Align_CurlV2TF_m_Ideal_AFB[k]->SetBinContent(i+1,diff_CurlV2TF);
      h_MC_Raw_Align_Twist_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Twist);
      h_MC_Raw_Align_Zexpansion_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Zexpansion);

//
      float max_alignment = 0;
      float min_alignment = 9999;
      if (diff_Startup > 0. && diff_Startup > max_alignment) max_alignment = diff_Startup;
      if (diff_Startup < 0. && diff_Startup < min_alignment) min_alignment = diff_Startup;
      if (diff_Bowing > 0. && diff_Bowing > max_alignment) max_alignment = diff_Bowing;
      if (diff_Bowing < 0. && diff_Bowing < min_alignment) min_alignment = diff_Bowing;
      if (diff_Elliptical > 0. && diff_Elliptical > max_alignment) max_alignment = diff_Elliptical;
      if (diff_Elliptical < 0. && diff_Elliptical < min_alignment) min_alignment = diff_Elliptical;
      if (diff_Radial > 0. && diff_Radial > max_alignment) max_alignment = diff_Radial;
      if (diff_Radial < 0. && diff_Radial < min_alignment) min_alignment = diff_Radial;
      if (diff_Sagitta > 0. && diff_Sagitta > max_alignment) max_alignment = diff_Sagitta;
      if (diff_Sagitta < 0. && diff_Sagitta < min_alignment) min_alignment = diff_Sagitta;
      if (diff_Skew > 0. && diff_Skew > max_alignment) max_alignment = diff_Skew;
      if (diff_Skew < 0. && diff_Skew < min_alignment) min_alignment = diff_Skew;
      if (diff_Telescope > 0. && diff_Telescope > max_alignment) max_alignment = diff_Telescope;
      if (diff_Telescope < 0. && diff_Telescope < min_alignment) min_alignment = diff_Telescope;
      if (diff_CurlV2TF > 0. && diff_CurlV2TF > max_alignment) max_alignment = diff_CurlV2TF;
      if (diff_CurlV2TF < 0. && diff_CurlV2TF < min_alignment) min_alignment = diff_CurlV2TF;
      if (diff_Twist > 0. && diff_Twist > max_alignment) max_alignment = diff_Twist;
      if (diff_Twist < 0. && diff_Twist < min_alignment) min_alignment = diff_Twist;
      if (diff_Zexpansion > 0. && diff_Zexpansion > max_alignment) max_alignment = diff_Zexpansion;
      if (diff_Zexpansion < 0. && diff_Zexpansion < min_alignment) min_alignment = diff_Zexpansion;
      
//
/*///this was the previous version
      if (diff_Startup >0. ? total_plus[k][i] += diff_Startup*diff_Startup : total_minus[k][i] += diff_Startup*diff_Startup);
      if (diff_Bowing >0. ? total_plus[k][i] += diff_Bowing*diff_Bowing : total_minus[k][i] += diff_Bowing*diff_Bowing);
      if (diff_Elliptical >0. ? total_plus[k][i] += diff_Elliptical*diff_Elliptical : total_minus[k][i] += diff_Elliptical*diff_Elliptical);
      if (diff_Radial >0. ? total_plus[k][i] += diff_Radial*diff_Radial : total_minus[k][i] += diff_Radial*diff_Radial);
      if (diff_Sagitta >0. ? total_plus[k][i] += diff_Sagitta*diff_Sagitta : total_minus[k][i] += diff_Sagitta*diff_Startup);
      if (diff_Skew >0. ? total_plus[k][i] += diff_Skew*diff_Skew : total_minus[k][i] += diff_Skew*diff_Skew);
      if (diff_Telescope >0. ? total_plus[k][i] += diff_Telescope*diff_Telescope : total_minus[k][i] += diff_Telescope*diff_Telescope);
      if (diff_CurlV2TF >0. ? total_plus[k][i] += diff_CurlV2TF*diff_CurlV2TF : total_minus[k][i] += diff_CurlV2TF*diff_CurlV2TF);
      if (diff_Twist >0. ? total_plus[k][i] += diff_Twist*diff_Twist : total_minus[k][i] += diff_Twist*diff_Twist);
      if (diff_Zexpansion >0. ? total_plus[k][i] += diff_Zexpansion*diff_Zexpansion : total_minus[k][i] += diff_Zexpansion*diff_Zexpansion);
*/
     //---> max alignment uncertainties added to total systematics
     if (min_alignment != 9999) total_minus[k][i] += min_alignment*min_alignment;
     total_plus[k][i] += max_alignment*max_alignment;
     //---------------------------------------------------------------------------

/*///this was the previous version
      if (diff_Startup >0. ? alignment_total_plus[k][i] += diff_Startup*diff_Startup : alignment_total_minus[k][i] += diff_Startup*diff_Startup);
      if (diff_Bowing >0. ? alignment_total_plus[k][i] += diff_Bowing*diff_Bowing : alignment_total_minus[k][i] += diff_Bowing*diff_Bowing);
      if (diff_Elliptical >0. ? alignment_total_plus[k][i] += diff_Elliptical*diff_Elliptical : alignment_total_minus[k][i] += diff_Elliptical*diff_Elliptical);
      if (diff_Radial >0. ? alignment_total_plus[k][i] += diff_Radial*diff_Radial : alignment_total_minus[k][i] += diff_Radial*diff_Radial);
      if (diff_Sagitta >0. ? alignment_total_plus[k][i] += diff_Sagitta*diff_Sagitta : alignment_total_minus[k][i] += diff_Sagitta*diff_Sagitta);
      if (diff_Skew >0. ? alignment_total_plus[k][i] += diff_Skew*diff_Skew : alignment_total_minus[k][i] += diff_Skew*diff_Skew);
      if (diff_Telescope >0. ? alignment_total_plus[k][i] += diff_Telescope*diff_Telescope : alignment_total_minus[k][i] += diff_Telescope*diff_Telescope);
      if (diff_CurlV2TF >0. ? alignment_total_plus[k][i] += diff_CurlV2TF*diff_CurlV2TF : alignment_total_minus[k][i] += diff_CurlV2TF*diff_CurlV2TF);
      if (diff_Twist >0. ? alignment_total_plus[k][i] += diff_Twist*diff_Twist : alignment_total_minus[k][i] += diff_Twist*diff_Twist);
      if (diff_Zexpansion >0. ? alignment_total_plus[k][i] += diff_Zexpansion*diff_Zexpansion : alignment_total_minus[k][i] += diff_Zexpansion*diff_Zexpansion);
*///
//
      //---> max alignment uncertainties added to alignment systematics
      alignment_total_plus[k][i] += max_alignment*max_alignment;
      if (min_alignment != 9999) alignment_total_minus[k][i] += min_alignment*min_alignment;
      //---------------------------------------------------------------------------

      alignment_total_plus[k][i] = sqrt(alignment_total_plus[k][i]);
      alignment_total_minus[k][i] = -sqrt(alignment_total_minus[k][i]);
      if (alignment_total_plus[k][i] != 0){
	h_MC_Raw_alignment_total_plus[k]->SetBinContent(i+1,alignment_total_plus[k][i]);
	h_MC_Raw_alignment_total_plus[k]->SetBinError(i+1,0.000000001);
      }	
      if (alignment_total_minus[k][i] != 0){
	h_MC_Raw_alignment_total_minus[k]->SetBinContent(i+1,alignment_total_minus[k][i]);
	h_MC_Raw_alignment_total_minus[k]->SetBinError(i+1,0.000000001);
      }
      /*
      if (k == 0 && i == 0){ 
	cout<<"Misalignment (Raw Level)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    Mis  - Nominal   "<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Startup<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Bowing<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Elliptical<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Radial<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Sagitta<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Skew<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Telescope<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_CurlV2TF<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Twist<<"    \\\\    "<<endl;
//      cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Zexpansion<<"    \\\\    "<<endl;
      */

      for (int j=0;j<nb;j++){
	MC_UnDet_Align_Ideal_Forward[k][i] += Align_Ideal_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Ideal_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Ideal_Backward[k][i] += Align_Ideal_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Ideal_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Startup_Forward[k][i] += Align_Startup_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Startup_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Startup_Backward[k][i] += Align_Startup_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Startup_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Bowing_Forward[k][i] += Align_Bowing_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Bowing_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Bowing_Backward[k][i] += Align_Bowing_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Bowing_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Elliptical_Forward[k][i] += Align_Elliptical_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Elliptical_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Elliptical_Backward[k][i] += Align_Elliptical_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Elliptical_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Radial_Forward[k][i] += Align_Radial_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Radial_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Radial_Backward[k][i] += Align_Radial_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Radial_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);    
	MC_UnDet_Align_Sagitta_Forward[k][i] += Align_Sagitta_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Sagitta_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Sagitta_Backward[k][i] += Align_Sagitta_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Sagitta_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Skew_Forward[k][i] += Align_Skew_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Skew_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Skew_Backward[k][i] += Align_Skew_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Skew_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Telescope_Forward[k][i] += Align_Telescope_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Telescope_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Telescope_Backward[k][i] += Align_Telescope_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Telescope_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_CurlV2TF_Forward[k][i] += Align_CurlV2TF_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_CurlV2TF_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_CurlV2TF_Backward[k][i] += Align_CurlV2TF_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_CurlV2TF_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Twist_Forward[k][i] += Align_Twist_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Twist_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Twist_Backward[k][i] += Align_Twist_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Twist_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Zexpansion_Forward[k][i] += Align_Zexpansion_Inv_Response_UnDetector_Forward[k]->GetBinContent(j+1,i+1)*Align_Zexpansion_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_UnDet_Align_Zexpansion_Backward[k][i] += Align_Zexpansion_Inv_Response_UnDetector_Backward[k]->GetBinContent(j+1,i+1)*Align_Zexpansion_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
       
	MC_NoFsr_Align_Ideal_Forward[k][i] += Align_Ideal_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Ideal_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Ideal_Backward[k][i] += Align_Ideal_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Ideal_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Startup_Forward[k][i] += Align_Startup_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Startup_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Startup_Backward[k][i] += Align_Startup_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Startup_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Bowing_Forward[k][i] += Align_Bowing_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Bowing_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Bowing_Backward[k][i] += Align_Bowing_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Bowing_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Elliptical_Forward[k][i] += Align_Elliptical_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Elliptical_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Elliptical_Backward[k][i] += Align_Elliptical_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Elliptical_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Radial_Forward[k][i] += Align_Radial_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Radial_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Radial_Backward[k][i] += Align_Radial_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Radial_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Sagitta_Forward[k][i] += Align_Sagitta_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Sagitta_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Sagitta_Backward[k][i] += Align_Sagitta_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Sagitta_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Skew_Forward[k][i] += Align_Skew_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Skew_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Skew_Backward[k][i] += Align_Skew_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Skew_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Telescope_Forward[k][i] += Align_Telescope_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Telescope_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Telescope_Backward[k][i] += Align_Telescope_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Telescope_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_CurlV2TF_Forward[k][i] += Align_CurlV2TF_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_CurlV2TF_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_CurlV2TF_Backward[k][i] += Align_CurlV2TF_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_CurlV2TF_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Twist_Forward[k][i] += Align_Twist_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Twist_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Twist_Backward[k][i] += Align_Twist_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Twist_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Zexpansion_Forward[k][i] += Align_Zexpansion_Inv_Response_NoFsr_Forward[k]->GetBinContent(j+1,i+1)*Align_Zexpansion_hMeasCos_M_Y_Forward[k]->GetBinContent(j+1);
	MC_NoFsr_Align_Zexpansion_Backward[k][i] += Align_Zexpansion_Inv_Response_NoFsr_Backward[k]->GetBinContent(j+1,i+1)*Align_Zexpansion_hMeasCos_M_Y_Backward[k]->GetBinContent(j+1);
		
      }
      MC_UnDet_Align_Ideal_AFB[i] = AFB(MC_UnDet_Align_Ideal_Forward[k][i],MC_UnDet_Align_Ideal_Backward[k][i]);
      MC_UnDet_Align_Startup_AFB[i] = AFB(MC_UnDet_Align_Startup_Forward[k][i],MC_UnDet_Align_Startup_Backward[k][i]);
      MC_UnDet_Align_Bowing_AFB[i] = AFB(MC_UnDet_Align_Bowing_Forward[k][i],MC_UnDet_Align_Bowing_Backward[k][i]);
      MC_UnDet_Align_Elliptical_AFB[i] = AFB(MC_UnDet_Align_Elliptical_Forward[k][i],MC_UnDet_Align_Elliptical_Backward[k][i]);
      MC_UnDet_Align_Radial_AFB[i] = AFB(MC_UnDet_Align_Radial_Forward[k][i],MC_UnDet_Align_Radial_Backward[k][i]);
      MC_UnDet_Align_Sagitta_AFB[i] = AFB(MC_UnDet_Align_Sagitta_Forward[k][i],MC_UnDet_Align_Sagitta_Backward[k][i]);
      MC_UnDet_Align_Skew_AFB[i] = AFB(MC_UnDet_Align_Skew_Forward[k][i],MC_UnDet_Align_Skew_Backward[k][i]);
      MC_UnDet_Align_Telescope_AFB[i] = AFB(MC_UnDet_Align_Telescope_Forward[k][i],MC_UnDet_Align_Telescope_Backward[k][i]);
      MC_UnDet_Align_CurlV2TF_AFB[i] = AFB(MC_UnDet_Align_CurlV2TF_Forward[k][i],MC_UnDet_Align_CurlV2TF_Backward[k][i]);
      MC_UnDet_Align_Twist_AFB[i] = AFB(MC_UnDet_Align_Twist_Forward[k][i],MC_UnDet_Align_Twist_Backward[k][i]);
      MC_UnDet_Align_Zexpansion_AFB[i] = AFB(MC_UnDet_Align_Zexpansion_Forward[k][i],MC_UnDet_Align_Zexpansion_Backward[k][i]);

      diff_Startup = 0;
      diff_Bowing = 0;
      diff_Elliptical = 0;
      diff_Radial = 0;
      diff_Sagitta = 0;
      diff_Skew = 0;
      diff_Telescope = 0;
      diff_CurlV2TF = 0;
      diff_Twist = 0;
      diff_Zexpansion = 0;
      diff_Startup = MC_UnDet_Align_Startup_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_Bowing = MC_UnDet_Align_Bowing_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_Elliptical = MC_UnDet_Align_Elliptical_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_Radial = MC_UnDet_Align_Radial_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_Sagitta = MC_UnDet_Align_Sagitta_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_Skew = MC_UnDet_Align_Skew_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_Telescope = MC_UnDet_Align_Telescope_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_CurlV2TF = MC_UnDet_Align_CurlV2TF_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_Twist = MC_UnDet_Align_Twist_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];
      diff_Zexpansion = MC_UnDet_Align_Zexpansion_AFB[i] - MC_UnDet_Align_Ideal_AFB[i];

      h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Bowing);
      h_MC_Unfolded_UnDet_Align_Bowing_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Bowing);
      h_MC_Unfolded_UnDet_Align_Elliptical_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Elliptical);
      h_MC_Unfolded_UnDet_Align_Radial_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Radial);
      h_MC_Unfolded_UnDet_Align_Sagitta_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Sagitta);
      h_MC_Unfolded_UnDet_Align_Skew_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Skew);
      h_MC_Unfolded_UnDet_Align_Telescope_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Telescope);
      h_MC_Unfolded_UnDet_Align_CurlV2TF_m_Ideal_AFB[k]->SetBinContent(i+1,diff_CurlV2TF);
      h_MC_Unfolded_UnDet_Align_Twist_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Twist);
      h_MC_Unfolded_UnDet_Align_Zexpansion_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Zexpansion);

      if (diff_Startup >0. ? total_plus_undet[k][i] += diff_Startup*diff_Startup : total_minus_undet[k][i] += diff_Startup*diff_Startup);
      if (diff_Bowing >0. ? total_plus_undet[k][i] += diff_Bowing*diff_Bowing : total_minus_undet[k][i] += diff_Bowing*diff_Bowing);
      if (diff_Elliptical >0. ? total_plus_undet[k][i] += diff_Elliptical*diff_Elliptical : total_minus_undet[k][i] += diff_Elliptical*diff_Elliptical);
      if (diff_Radial >0. ? total_plus_undet[k][i] += diff_Radial*diff_Radial : total_minus_undet[k][i] += diff_Radial*diff_Radial);
      if (diff_Sagitta >0. ? total_plus_undet[k][i] += diff_Sagitta*diff_Sagitta : total_minus_undet[k][i] += diff_Sagitta*diff_Sagitta);
      if (diff_Skew >0. ? total_plus_undet[k][i] += diff_Skew*diff_Skew : total_minus_undet[k][i] += diff_Skew*diff_Skew);
      if (diff_Telescope >0. ? total_plus_undet[k][i] += diff_Telescope*diff_Telescope : total_minus_undet[k][i] += diff_Telescope*diff_Telescope);
      if (diff_CurlV2TF >0. ? total_plus_undet[k][i] += diff_CurlV2TF*diff_CurlV2TF : total_minus_undet[k][i] += diff_CurlV2TF*diff_CurlV2TF);
      if (diff_Twist >0. ? total_plus_undet[k][i] += diff_Twist*diff_Twist : total_minus_undet[k][i] += diff_Twist*diff_Twist);
      if (diff_Zexpansion >0. ? total_plus_undet[k][i] += diff_Zexpansion*diff_Zexpansion : total_minus_undet[k][i] += diff_Zexpansion*diff_Zexpansion);


      if (diff_Startup >0. ? alignment_total_plus_undet[k][i] += diff_Startup*diff_Startup : alignment_total_minus_undet[k][i] += diff_Startup*diff_Startup);
      if (diff_Bowing >0. ? alignment_total_plus_undet[k][i] += diff_Bowing*diff_Bowing : alignment_total_minus_undet[k][i] += diff_Bowing*diff_Bowing);
      if (diff_Elliptical >0. ? alignment_total_plus_undet[k][i] += diff_Elliptical*diff_Elliptical : alignment_total_minus_undet[k][i] += diff_Elliptical*diff_Elliptical);
      if (diff_Radial >0. ? alignment_total_plus_undet[k][i] += diff_Radial*diff_Radial : alignment_total_minus_undet[k][i] += diff_Radial*diff_Radial);
      if (diff_Sagitta >0. ? alignment_total_plus_undet[k][i] += diff_Sagitta*diff_Sagitta : alignment_total_minus_undet[k][i] += diff_Sagitta*diff_Sagitta);
      if (diff_Skew >0. ? alignment_total_plus_undet[k][i] += diff_Skew*diff_Skew : alignment_total_minus_undet[k][i] += diff_Skew*diff_Skew);
      if (diff_Telescope >0. ? alignment_total_plus_undet[k][i] += diff_Telescope*diff_Telescope : alignment_total_minus_undet[k][i] += diff_Telescope*diff_Telescope);
      if (diff_CurlV2TF >0. ? alignment_total_plus_undet[k][i] += diff_CurlV2TF*diff_CurlV2TF : alignment_total_minus_undet[k][i] += diff_CurlV2TF*diff_CurlV2TF);
      if (diff_Twist >0. ? alignment_total_plus_undet[k][i] += diff_Twist*diff_Twist : alignment_total_minus_undet[k][i] += diff_Twist*diff_Twist);
      if (diff_Zexpansion >0. ? alignment_total_plus_undet[k][i] += diff_Zexpansion*diff_Zexpansion : alignment_total_minus_undet[k][i] += diff_Zexpansion*diff_Zexpansion);

      alignment_total_plus_undet[k][i] = sqrt(alignment_total_plus_undet[k][i]);
      alignment_total_minus_undet[k][i] = -sqrt(alignment_total_minus_undet[k][i]);
      if (alignment_total_plus_undet[k][i] != 0){
	h_MC_Bare_alignment_total_plus[k]->SetBinContent(i+1,alignment_total_plus_undet[k][i]);
	h_MC_Bare_alignment_total_plus[k]->SetBinError(i+1,0.00000001);
      }
      if (alignment_total_minus_undet[k][i] != 0){
	h_MC_Bare_alignment_total_minus[k]->SetBinContent(i+1,alignment_total_minus_undet[k][i]);
	h_MC_Bare_alignment_total_minus[k]->SetBinError(i+1,0.00000001);
      }

      /*
      if (k == 0 && i == 0){ 
	cout<<"Misalignment (Bare lepton Level)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    Mis  - Nominal   "<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Startup<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Bowing<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Elliptical<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Radial<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Sagitta<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Skew<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Telescope<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_CurlV2TF<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Twist<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Zexpansion<<"    \\\\    "<<endl;
      */


      MC_NoFsr_Align_Ideal_AFB[i] = AFB(MC_NoFsr_Align_Ideal_Forward[k][i],MC_NoFsr_Align_Ideal_Backward[k][i]);
      MC_NoFsr_Align_Startup_AFB[i] = AFB(MC_NoFsr_Align_Startup_Forward[k][i],MC_NoFsr_Align_Startup_Backward[k][i]);
      MC_NoFsr_Align_Bowing_AFB[i] = AFB(MC_NoFsr_Align_Bowing_Forward[k][i],MC_NoFsr_Align_Bowing_Backward[k][i]);
      MC_NoFsr_Align_Elliptical_AFB[i] = AFB(MC_NoFsr_Align_Elliptical_Forward[k][i],MC_NoFsr_Align_Elliptical_Backward[k][i]);
      MC_NoFsr_Align_Radial_AFB[i] = AFB(MC_NoFsr_Align_Radial_Forward[k][i],MC_NoFsr_Align_Radial_Backward[k][i]);
      MC_NoFsr_Align_Sagitta_AFB[i] = AFB(MC_NoFsr_Align_Sagitta_Forward[k][i],MC_NoFsr_Align_Sagitta_Backward[k][i]);
      MC_NoFsr_Align_Skew_AFB[i] = AFB(MC_NoFsr_Align_Skew_Forward[k][i],MC_NoFsr_Align_Skew_Backward[k][i]);
      MC_NoFsr_Align_Telescope_AFB[i] = AFB(MC_NoFsr_Align_Telescope_Forward[k][i],MC_NoFsr_Align_Telescope_Backward[k][i]);
      MC_NoFsr_Align_CurlV2TF_AFB[i] = AFB(MC_NoFsr_Align_CurlV2TF_Forward[k][i],MC_NoFsr_Align_CurlV2TF_Backward[k][i]);
      MC_NoFsr_Align_Twist_AFB[i] = AFB(MC_NoFsr_Align_Twist_Forward[k][i],MC_NoFsr_Align_Twist_Backward[k][i]);
      MC_NoFsr_Align_Zexpansion_AFB[i] = AFB(MC_NoFsr_Align_Zexpansion_Forward[k][i],MC_NoFsr_Align_Zexpansion_Backward[k][i]);

      diff_Startup = 0;
      diff_Bowing = 0;
      diff_Elliptical = 0;
      diff_Radial = 0;
      diff_Sagitta = 0;
      diff_Skew = 0;
      diff_Telescope = 0;
      diff_CurlV2TF = 0;
      diff_Twist = 0;
      diff_Zexpansion = 0;
      diff_Startup = MC_NoFsr_Align_Startup_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_Bowing = MC_NoFsr_Align_Bowing_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_Elliptical = MC_NoFsr_Align_Elliptical_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_Radial = MC_NoFsr_Align_Radial_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_Sagitta = MC_NoFsr_Align_Sagitta_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_Skew = MC_NoFsr_Align_Skew_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_Telescope = MC_NoFsr_Align_Telescope_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_CurlV2TF = MC_NoFsr_Align_CurlV2TF_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_Twist = MC_NoFsr_Align_Twist_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];
      diff_Zexpansion = MC_NoFsr_Align_Zexpansion_AFB[i] - MC_NoFsr_Align_Ideal_AFB[i];

      h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Bowing);
      h_MC_Unfolded_NoFsr_Align_Bowing_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Bowing);
      h_MC_Unfolded_NoFsr_Align_Elliptical_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Elliptical);
      h_MC_Unfolded_NoFsr_Align_Radial_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Radial);
      h_MC_Unfolded_NoFsr_Align_Sagitta_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Sagitta);
      h_MC_Unfolded_NoFsr_Align_Skew_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Skew);
      h_MC_Unfolded_NoFsr_Align_Telescope_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Telescope);
      h_MC_Unfolded_NoFsr_Align_CurlV2TF_m_Ideal_AFB[k]->SetBinContent(i+1,diff_CurlV2TF);
      h_MC_Unfolded_NoFsr_Align_Twist_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Twist);
      h_MC_Unfolded_NoFsr_Align_Zexpansion_m_Ideal_AFB[k]->SetBinContent(i+1,diff_Zexpansion);


///////this is the new one
      float max_alignment_nofsr = 0;
      float min_alignment_nofsr = 9999;
      if (diff_Startup > 0. && diff_Startup > max_alignment_nofsr) max_alignment_nofsr = diff_Startup;
      if (diff_Startup < 0. && diff_Startup < min_alignment_nofsr) min_alignment_nofsr = diff_Startup;
      if (diff_Bowing > 0. && diff_Bowing > max_alignment_nofsr) max_alignment_nofsr = diff_Bowing;
      if (diff_Bowing < 0. && diff_Bowing < min_alignment_nofsr) min_alignment_nofsr = diff_Bowing;
      if (diff_Elliptical > 0. && diff_Elliptical > max_alignment_nofsr) max_alignment_nofsr = diff_Elliptical;
      if (diff_Elliptical < 0. && diff_Elliptical < min_alignment_nofsr) min_alignment_nofsr = diff_Elliptical;
      if (diff_Radial > 0. && diff_Radial > max_alignment_nofsr) max_alignment_nofsr = diff_Radial;
      if (diff_Radial < 0. && diff_Radial < min_alignment_nofsr) min_alignment_nofsr = diff_Radial;
      if (diff_Sagitta > 0. && diff_Sagitta > max_alignment_nofsr) max_alignment_nofsr = diff_Sagitta;
      if (diff_Sagitta < 0. && diff_Sagitta < min_alignment_nofsr) min_alignment_nofsr = diff_Sagitta;
      if (diff_Skew > 0. && diff_Skew > max_alignment_nofsr) max_alignment_nofsr = diff_Skew;
      if (diff_Skew < 0. && diff_Skew < min_alignment_nofsr) min_alignment_nofsr = diff_Skew;
      if (diff_Telescope > 0. && diff_Telescope > max_alignment_nofsr) max_alignment_nofsr = diff_Telescope;
      if (diff_Telescope < 0. && diff_Telescope < min_alignment_nofsr) min_alignment_nofsr = diff_Telescope;
      if (diff_CurlV2TF > 0. && diff_CurlV2TF > max_alignment_nofsr) max_alignment_nofsr = diff_CurlV2TF;
      if (diff_CurlV2TF < 0. && diff_CurlV2TF < min_alignment_nofsr) min_alignment_nofsr = diff_CurlV2TF;
      if (diff_Twist > 0. && diff_Twist > max_alignment_nofsr) max_alignment_nofsr = diff_Twist;
      if (diff_Twist < 0. && diff_Twist < min_alignment_nofsr) min_alignment_nofsr = diff_Twist;
      if (diff_Zexpansion > 0. && diff_Zexpansion > max_alignment_nofsr) max_alignment_nofsr = diff_Zexpansion;
      if (diff_Zexpansion < 0. && diff_Zexpansion < min_alignment_nofsr) min_alignment_nofsr = diff_Zexpansion;

     //---> max alignment uncertainties added to total systematics
     if (min_alignment_nofsr != 9999) total_minus_nofsr[k][i] += min_alignment_nofsr*min_alignment_nofsr;
     total_plus_nofsr[k][i] += max_alignment_nofsr*max_alignment_nofsr;
     //---------------------------------------------------------------------------

      //---> max alignment uncertainties added to alignment systematics
      alignment_total_plus_nofsr[k][i] += max_alignment_nofsr*max_alignment_nofsr;
      if (min_alignment_nofsr != 9999) alignment_total_minus_nofsr[k][i] += min_alignment_nofsr*min_alignment_nofsr;
      //---------------------------------------------------------------------------

///////////////////////////

//these were for the previous version
/* 
      if (diff_Startup >0. ? total_plus_nofsr[k][i] += diff_Startup*diff_Startup : total_minus_nofsr[k][i] += diff_Startup*diff_Startup);
      if (diff_Bowing >0. ? total_plus_nofsr[k][i] += diff_Bowing*diff_Bowing : total_minus_nofsr[k][i] += diff_Bowing*diff_Bowing);
      if (diff_Elliptical >0. ? total_plus_nofsr[k][i] += diff_Elliptical*diff_Elliptical : total_minus_nofsr[k][i] += diff_Elliptical*diff_Elliptical);
      if (diff_Radial >0. ? total_plus_nofsr[k][i] += diff_Radial*diff_Radial : total_minus_nofsr[k][i] += diff_Radial*diff_Radial);
      if (diff_Sagitta >0. ? total_plus_nofsr[k][i] += diff_Sagitta*diff_Sagitta : total_minus_nofsr[k][i] += diff_Sagitta*diff_Sagitta);
      if (diff_Skew >0. ? total_plus_nofsr[k][i] += diff_Skew*diff_Skew : total_minus_nofsr[k][i] += diff_Skew*diff_Skew);
      if (diff_Telescope >0. ? total_plus_nofsr[k][i] += diff_Telescope*diff_Telescope : total_minus_nofsr[k][i] += diff_Telescope*diff_Telescope);
      if (diff_CurlV2TF >0. ? total_plus_nofsr[k][i] += diff_CurlV2TF*diff_CurlV2TF : total_minus_nofsr[k][i] += diff_CurlV2TF*diff_CurlV2TF);
      if (diff_Twist >0. ? total_plus_nofsr[k][i] += diff_Twist*diff_Twist : total_minus_nofsr[k][i] += diff_Twist*diff_Twist);
      if (diff_Zexpansion >0. ? total_plus_nofsr[k][i] += diff_Zexpansion*diff_Zexpansion : total_minus_nofsr[k][i] += diff_Zexpansion*diff_Zexpansion);

      if (diff_Startup >0. ? alignment_total_plus_nofsr[k][i] += diff_Startup*diff_Startup : alignment_total_minus_nofsr[k][i] += diff_Startup*diff_Startup);
      if (diff_Bowing >0. ? alignment_total_plus_nofsr[k][i] += diff_Bowing*diff_Bowing : alignment_total_minus_nofsr[k][i] += diff_Bowing*diff_Bowing);
      if (diff_Elliptical >0. ? alignment_total_plus_nofsr[k][i] += diff_Elliptical*diff_Elliptical : alignment_total_minus_nofsr[k][i] += diff_Elliptical*diff_Elliptical);
      if (diff_Radial >0. ? alignment_total_plus_nofsr[k][i] += diff_Radial*diff_Radial : alignment_total_minus_nofsr[k][i] += diff_Radial*diff_Radial);
      if (diff_Sagitta >0. ? alignment_total_plus_nofsr[k][i] += diff_Sagitta*diff_Sagitta : alignment_total_minus_nofsr[k][i] += diff_Sagitta*diff_Sagitta);
      if (diff_Skew >0. ? alignment_total_plus_nofsr[k][i] += diff_Skew*diff_Skew : alignment_total_minus_nofsr[k][i] += diff_Skew*diff_Skew);
      if (diff_Telescope >0. ? alignment_total_plus_nofsr[k][i] += diff_Telescope*diff_Telescope : alignment_total_minus_nofsr[k][i] += diff_Telescope*diff_Telescope);
      if (diff_CurlV2TF >0. ? alignment_total_plus_nofsr[k][i] += diff_CurlV2TF*diff_CurlV2TF : alignment_total_minus_nofsr[k][i] += diff_CurlV2TF*diff_CurlV2TF);
      if (diff_Twist >0. ? alignment_total_plus_nofsr[k][i] += diff_Twist*diff_Twist : alignment_total_minus_nofsr[k][i] += diff_Twist*diff_Twist);
      if (diff_Zexpansion >0. ? alignment_total_plus_nofsr[k][i] += diff_Zexpansion*diff_Zexpansion : alignment_total_minus_nofsr[k][i] += diff_Zexpansion*diff_Zexpansion);
*/
      //cout<<diff_Startup<<" "<<diff_Bowing<<" "<<diff_Elliptical<<" "<<diff_Radial<<" "<<diff_Sagitta<<" "<<diff_Skew<<" "<<diff_Telescope<<" "<<diff_CurlV2TF<<" "<<diff_Twist<<" "<<diff_Zexpansion <<endl;


      alignment_total_plus_nofsr[k][i] = sqrt(alignment_total_plus_nofsr[k][i]);
      alignment_total_minus_nofsr[k][i] = -sqrt(alignment_total_minus_nofsr[k][i]);
      if (alignment_total_plus_nofsr[k][i]){
	h_MC_Born_alignment_total_plus[k]->SetBinContent(i+1,alignment_total_plus_nofsr[k][i]);
	h_MC_Born_alignment_total_plus[k]->SetBinError(i+1,0.000000001);
      }
      if (alignment_total_minus_nofsr[k][i]){
	h_MC_Born_alignment_total_minus[k]->SetBinContent(i+1,alignment_total_minus_nofsr[k][i]);
	h_MC_Born_alignment_total_minus[k]->SetBinError(i+1,0.000000001);
      }

      /*     
      if (k == 0 && i == 0){ 
	cout<<"Misalignment (Born lepton Level)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)    Mis  - Nominal   "<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Startup<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Bowing<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Elliptical<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Radial<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Sagitta<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Skew<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Telescope<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_CurlV2TF<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Twist<<"    \\\\    "<<endl;
      //cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_Zexpansion<<"    \\\\    "<<endl;
      */

    }//eo alignment loop


      for (int i=0;i<nb;i++){
	if (k == 0) total_minus_comb[k][i] = -1.*sqrt(total_minus_nofsr[k][i] + yee1m[i]*yee1m[i]);
	if (k == 1) total_minus_comb[k][i] = -1.*sqrt(total_minus_nofsr[k][i] + yee2m[i]*yee2m[i]);
	if (k == 2) total_minus_comb[k][i] = -1.*sqrt(total_minus_nofsr[k][i] + yee3m[i]*yee3m[i]);
	if (k == 3) total_minus_comb[k][i] = -1.*sqrt(total_minus_nofsr[k][i] + yee4m[i]*yee4m[i]);

	if (k == 0) total_plus_comb[k][i] = sqrt(total_plus_nofsr[k][i] + yee1p[i]*yee1p[i]);
	if (k == 1) total_plus_comb[k][i] = sqrt(total_plus_nofsr[k][i] + yee2p[i]*yee2p[i]);
	if (k == 2) total_plus_comb[k][i] = sqrt(total_plus_nofsr[k][i] + yee3p[i]*yee3p[i]);
	if (k == 3) total_plus_comb[k][i] = sqrt(total_plus_nofsr[k][i] + yee4p[i]*yee4p[i]);
      }
    

    for (int i=0;i<nb;i++){ //pdf loop
      afb_0 = AFB(hMeasCos_M_Y_Forward_PDF_ct10[k][0]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_ct10[k][0]->GetBinContent(i+1));
      afb_0_mstw = AFB(hMeasCos_M_Y_Forward_PDF_mstw[k][0]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_mstw[k][0]->GetBinContent(i+1));


      afb_alphas0 = AFB(hMeasCos_M_Y_Forward_PDF_alpha_s[k][0]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_alpha_s[k][0]->GetBinContent(i+1));
      afb_alphas5 = AFB(hMeasCos_M_Y_Forward_PDF_alpha_s[k][5]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_alpha_s[k][5]->GetBinContent(i+1));
      afb_alphas10 = AFB(hMeasCos_M_Y_Forward_PDF_alpha_s[k][10]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_alpha_s[k][10]->GetBinContent(i+1));  
      h_Delta_AFB_alphas_PLUS[k]->SetBinContent(i+1,afb_alphas10-afb_alphas5);
      h_Delta_AFB_alphas_MINUS[k]->SetBinContent(i+1,afb_alphas0-afb_alphas5);

      for (int pdfindex = 0; pdfindex<n_ct; pdfindex++){
	for (int j=0;j<nb;j++){
	  MC_Unfolded_UnDet_Forward_PDF_ct10[k][i][pdfindex] += Inv_Response_UnDetector_Forward_PDF_ct10[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Forward_PDF_ct10[k][pdfindex]->GetBinContent(j+1);
	  MC_Unfolded_UnDet_Backward_PDF_ct10[k][i][pdfindex] += Inv_Response_UnDetector_Backward_PDF_ct10[k]->GetBinContent(j+1,i+1)*hMeasCos_M_Y_Backward_PDF_ct10[k][pdfindex]->GetBinContent(j+1);
	}
	MC_Unfolded_UnDet_AFB_PDF_ct10[i][pdfindex] = AFB(MC_Unfolded_UnDet_Forward_PDF_ct10[k][i][pdfindex],MC_Unfolded_UnDet_Backward_PDF_ct10[k][i][pdfindex]);	
      }

      afb_0_undet = MC_Unfolded_UnDet_AFB_PDF_ct10[i][0];

	for (int pdfindex=1; pdfindex<n_ct; pdfindex+=2){
	  afb_p = AFB(hMeasCos_M_Y_Forward_PDF_ct10[k][pdfindex]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_ct10[k][pdfindex]->GetBinContent(i+1));
	  afb_m = AFB(hMeasCos_M_Y_Forward_PDF_ct10[k][pdfindex+1]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_ct10[k][pdfindex+1]->GetBinContent(i+1));
	  delta_plus = afb_p - afb_0;
	  delta_minus = afb_m - afb_0;
	  arrayformax_p[0] = delta_plus;
	  arrayformax_p[1] = delta_minus;
	  arrayformax_p[2] = 0;	  
	  arrayformax_m[0] = -delta_plus;
	  arrayformax_m[1] = -delta_minus;
	  arrayformax_m[2] = 0;
	  DeltaXmaxPlus[i][k] += pow(TMath::MaxElement(3,arrayformax_p),2);
	  DeltaXmaxMinus[i][k] += pow(TMath::MaxElement(3,arrayformax_m),2);

	  afb_p_undet = MC_Unfolded_UnDet_AFB_PDF_ct10[i][pdfindex];
	  afb_m_undet = MC_Unfolded_UnDet_AFB_PDF_ct10[i][pdfindex+1];
	  delta_plus_undet = afb_p_undet - afb_0_undet;
	  delta_minus_undet = afb_m_undet - afb_0_undet;
	  arrayformax_p_undet[0] = delta_plus_undet;
	  arrayformax_p_undet[1] = delta_minus_undet;
	  arrayformax_p_undet[2] = 0;	  
	  arrayformax_m_undet[0] = -delta_plus_undet;
	  arrayformax_m_undet[1] = -delta_minus_undet;
	  arrayformax_m_undet[2] = 0;
	  DeltaXmaxPlus_undet[i][k] += pow(TMath::MaxElement(3,arrayformax_p_undet),2);
	  DeltaXmaxMinus_undet[i][k] += pow(TMath::MaxElement(3,arrayformax_m_undet),2);
	}
	DeltaXmaxPlus[i][k] = sqrt(DeltaXmaxPlus[i][k]);
	DeltaXmaxMinus[i][k] = sqrt(DeltaXmaxMinus[i][k]);
	h_DeltaXmaxPlus_ct10[k]->SetBinContent(i+1,DeltaXmaxPlus[i][k]);
	h_DeltaXmaxMinus_ct10[k]->SetBinContent(i+1,DeltaXmaxMinus[i][k]);
	float DeltaX_CT10_ALPHAS_PLUS = sqrt(pow(DeltaXmaxPlus[i][k],2)+pow(afb_alphas10-afb_alphas5,2));
	float DeltaX_CT10_ALPHAS_MINUS = sqrt(pow(DeltaXmaxMinus[i][k],2)+pow(afb_alphas0-afb_alphas5,2));
	h_DeltaX_CT10_ALPHAS_PLUS[k]->SetBinContent(i+1,DeltaX_CT10_ALPHAS_PLUS);
	h_DeltaX_CT10_ALPHAS_MINUS[k]->SetBinContent(i+1,DeltaX_CT10_ALPHAS_MINUS);

	DeltaXmaxPlus_undet[i][k] = sqrt(DeltaXmaxPlus_undet[i][k]);
	DeltaXmaxMinus_undet[i][k] = sqrt(DeltaXmaxMinus_undet[i][k]);
	h_DeltaXmaxPlus_undet_ct10[k]->SetBinContent(i+1,DeltaXmaxPlus_undet[i][k]);
	h_DeltaXmaxMinus_undet_ct10[k]->SetBinContent(i+1,DeltaXmaxMinus_undet[i][k]);
	//	float DeltaX_CT10_ALPHAS_PLUS = sqrt(pow(DeltaXmaxPlus[i][k],2)+pow(afb_alphas10-afb_alphas5,2));
	//	float DeltaX_CT10_ALPHAS_MINUS = sqrt(pow(DeltaXmaxMinus[i][k],2)+pow(afb_alphas0-afb_alphas5,2));
	//	h_DeltaX_CT10_ALPHAS_PLUS[k]->SetBinContent(i+1,DeltaX_CT10_ALPHAS_PLUS);
	//	h_DeltaX_CT10_ALPHAS_MINUS[k]->SetBinContent(i+1,DeltaX_CT10_ALPHAS_MINUS);

	DeltaXmaxPlus[i][k] = 0;
	DeltaXmaxMinus[i][k] = 0;
	for (int pdfindex=1; pdfindex<n_mstw; pdfindex+=2){
	  afb_p = AFB(hMeasCos_M_Y_Forward_PDF_mstw[k][pdfindex]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_mstw[k][pdfindex]->GetBinContent(i+1));
	  afb_m = AFB(hMeasCos_M_Y_Forward_PDF_mstw[k][pdfindex+1]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_mstw[k][pdfindex+1]->GetBinContent(i+1));
	  delta_plus = afb_p - afb_0_mstw;
	  delta_minus = afb_m - afb_0_mstw;
	  //cout<<afb_0_mstw<<endl;
	  arrayformax_p[0] = delta_plus;
	  arrayformax_p[1] = delta_minus;
	  arrayformax_p[2] = 0;	  
	  arrayformax_m[0] = -delta_plus;
	  arrayformax_m[1] = -delta_minus;
	  arrayformax_m[2] = 0;
	  DeltaXmaxPlus[i][k] += pow(TMath::MaxElement(3,arrayformax_p),2);
	  DeltaXmaxMinus[i][k] += pow(TMath::MaxElement(3,arrayformax_m),2);
	}
	DeltaXmaxPlus[i][k] = sqrt(DeltaXmaxPlus[i][k]);
	DeltaXmaxMinus[i][k] = sqrt(DeltaXmaxMinus[i][k]);
	h_DeltaXmaxPlus_mstw[k]->SetBinContent(i+1,DeltaXmaxPlus[i][k]);
	h_DeltaXmaxMinus_mstw[k]->SetBinContent(i+1,DeltaXmaxMinus[i][k]);


	float average_afb = 0;
	for (int pdfindex=1;pdfindex<n_nnpdf;pdfindex++){
	  afb_nnpdf = AFB(hMeasCos_M_Y_Forward_PDF_nnpdf[k][pdfindex]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_nnpdf[k][pdfindex]->GetBinContent(i+1));
	  average_afb += afb_nnpdf;
	}
	average_afb = average_afb/((n_nnpdf-1)*1.);
	for (int pdfindex=1;pdfindex<n_nnpdf;pdfindex++){
	  afb_nnpdf = AFB(hMeasCos_M_Y_Forward_PDF_nnpdf[k][pdfindex]->GetBinContent(i+1),hMeasCos_M_Y_Backward_PDF_nnpdf[k][pdfindex]->GetBinContent(i+1));
	  sigma[i][k] += pow(afb_nnpdf - average_afb,2);
	}
	sigma[i][k] = sigma[i][k]/(n_nnpdf*1.-2.);
	sigma[i][k] = sqrt(sigma[i][k]);
	h_sigma[k]->SetBinContent(i+1,sigma[i][k]);

	float envelope_p = TMath::Max(afb_0+DeltaX_CT10_ALPHAS_PLUS,average_afb+sigma[i][k]);
	float envelope_m = TMath::Max(afb_0-DeltaX_CT10_ALPHAS_MINUS,average_afb-sigma[i][k]);
	float envelope_pp = TMath::Max(envelope_p,afb_0_mstw+DeltaXmaxPlus[i][k]);
	float envelope_mm = TMath::Max(envelope_m,afb_0_mstw-DeltaXmaxMinus[i][k]);

	float envelope_mean = (envelope_pp + envelope_mm)/2.;
	float diff_env = envelope_pp-envelope_mean;
	h_envelope_sigma[k]->SetBinContent(i+1,diff_env);
	h_envelope_sigma_plus[k]->SetBinContent(i+1,diff_env);
	h_envelope_sigma_minus[k]->SetBinContent(i+1,-diff_env);
	h_envelope_sigma_plus[k]->SetBinError(i+1,0.0000001);
	h_envelope_sigma_minus[k]->SetBinError(i+1,0.0000001);

	total_plus[k][i] += diff_env*diff_env; 
	total_plus[k][i] = sqrt(total_plus[k][i]);
	total_minus[k][i] += diff_env*diff_env;
	total_minus[k][i] = -1.*sqrt(total_minus[k][i]);
	h_total_plus[k]->SetBinContent(i+1,total_plus[k][i]);
	h_total_minus[k]->SetBinContent(i+1,total_minus[k][i]);	
	h_total_plus[k]->SetBinError(i+1,0.000000001);
	h_total_minus[k]->SetBinError(i+1,0.000000001);

	total_plus_undet[k][i] += diff_env*diff_env; 
	total_plus_undet[k][i] = sqrt(total_plus_undet[k][i]);
	total_minus_undet[k][i] += diff_env*diff_env;
	total_minus_undet[k][i] = -1.*sqrt(total_minus_undet[k][i]);	
	h_total_plus_undet[k]->SetBinContent(i+1,total_plus_undet[k][i]);
	h_total_minus_undet[k]->SetBinContent(i+1,total_minus_undet[k][i]);	
	h_total_plus_undet[k]->SetBinError(i+1,0.00000000001);
	h_total_minus_undet[k]->SetBinError(i+1,0.00000000001);
	

	total_plus_nofsr[k][i] += diff_env*diff_env; 
	total_plus_nofsr[k][i] = sqrt(total_plus_nofsr[k][i]);
	total_minus_nofsr[k][i] += diff_env*diff_env;
	total_minus_nofsr[k][i] = -1.*sqrt(total_minus_nofsr[k][i]);	
	h_total_plus_nofsr[k]->SetBinContent(i+1,total_plus_nofsr[k][i]);
	h_total_minus_nofsr[k]->SetBinContent(i+1,total_minus_nofsr[k][i]);
	h_total_plus_nofsr[k]->SetBinError(i+1,0.00000001);
	h_total_minus_nofsr[k]->SetBinError(i+1,0.00000001);

	/*
      if (k == 0 && i == 0){ 
	cout<<"PDF (Raw Level)"<<endl;
	cout<<"---------------"<<endl;
	cout<<"|Y|     Mass (GeV)     Envelope   "<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	}
      cout<<Y_bin_limits[k]<<"-"<<Y_bin_limits[k+1]<<" &  "<<xAxis_AFB[i]<<"-"<<xAxis_AFB[i+1]<<"  &  "<<setprecision(3)<<diff_env<<"    \\\\    "<<endl;
	*/
    }//eof pdf loop
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
    h_MC_Raw_AFB[k]->Draw("e1");
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
    h_MC_NoFsr_AFB[k]->Draw("");
    h_Raw_AFB[k]->SetMarkerStyle(8);
    h_Raw_AFB[k]->SetLineWidth(2);
    h_Raw_AFB[k]->Draw("e1sames");
    h_Unfolded_NoFsr_AFB[k]->SetMarkerStyle(20);
    h_Unfolded_NoFsr_AFB[k]->SetMarkerColor(1);
    h_Unfolded_NoFsr_AFB[k]->SetLineColor(1);
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
    hMeasCos_M_Y_Forward[k]->Scale(h_Closure_Unfolded_NoFsr_Forward[k]->Integral()*1./hMeasCos_M_Y_Forward[k]->Integral()*1.);
    hMeasCos_M_Y_Forward[k]->SetMarkerColor(1);
    hMeasCos_M_Y_Forward[k]->SetLineColor(1);
    hMeasCos_M_Y_Forward[k]->SetLineWidth(2);
    hMeasCos_M_Y_Forward[k]->GetXaxis()->SetTitle("Forward M(#mu^{+}#mu^{-}) [GeV]");
    hMeasCos_M_Y_Forward[k]->Draw();
    
    hNoFsrTruthCos_M_Y_Forward[k]->SetLineColor(4);
    hNoFsrTruthCos_M_Y_Forward[k]->Scale(h_Closure_Unfolded_NoFsr_Forward[k]->Integral()*1./hNoFsrTruthCos_M_Y_Forward[k]->Integral()*1.);
    hNoFsrTruthCos_M_Y_Forward[k]->Draw("sames");
    h_Closure_Unfolded_NoFsr_Forward[k]->SetMarkerStyle(25);
    h_Closure_Unfolded_NoFsr_Forward[k]->SetMarkerColor(2);
    h_Closure_Unfolded_NoFsr_Forward[k]->SetLineColor(2);
    h_Closure_Unfolded_NoFsr_Forward[k]->SetLineWidth(2);
    h_Closure_Unfolded_NoFsr_Forward[k]->Draw("e1sames");
  }
  c0_1->SaveAs("forward_MC_test.C");


  TCanvas *c0_2 = new TCanvas();
  c0_2->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c0_2->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    hMeasCos_M_Y_Backward[k]->Scale(h_Closure_Unfolded_NoFsr_Backward[k]->Integral()*1./hMeasCos_M_Y_Backward[k]->Integral()*1.);
    hMeasCos_M_Y_Backward[k]->SetMarkerColor(1);
    hMeasCos_M_Y_Backward[k]->SetLineColor(1);
    hMeasCos_M_Y_Backward[k]->SetLineWidth(2);
    hMeasCos_M_Y_Backward[k]->GetXaxis()->SetTitle("Backward M(#mu^{+}#mu^{-}) [GeV]");
    hMeasCos_M_Y_Backward[k]->Draw();
    
    hNoFsrTruthCos_M_Y_Backward[k]->SetLineColor(4);
    hNoFsrTruthCos_M_Y_Backward[k]->Scale(h_Closure_Unfolded_NoFsr_Backward[k]->Integral()*1./hNoFsrTruthCos_M_Y_Backward[k]->Integral()*1.);
    hNoFsrTruthCos_M_Y_Backward[k]->Draw("sames");
    h_Closure_Unfolded_NoFsr_Backward[k]->SetMarkerStyle(25);
    h_Closure_Unfolded_NoFsr_Backward[k]->SetMarkerColor(2);
    h_Closure_Unfolded_NoFsr_Backward[k]->SetLineColor(2);
    h_Closure_Unfolded_NoFsr_Backward[k]->SetLineWidth(2);
    h_Closure_Unfolded_NoFsr_Backward[k]->Draw("e1sames");
  }
  c0_2->SaveAs("backward_MC_test.C");


  TCanvas *c0_3 = new TCanvas();
  c0_3->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c0_3->cd(k+1);
    gPad->SetLogx();
    h_MC_Raw_AFB[k]->GetYaxis()->SetRangeUser(-0.2,0.4);
    h_MC_Raw_AFB[k]->SetLineWidth(2);
    h_MC_Raw_AFB[k]->SetLineColor(1);
    h_MC_Raw_AFB[k]->Draw();
    h_MC_NoFsr_AFB[k]->SetLineColor(4);
    h_MC_NoFsr_AFB[k]->SetLineWidth(2);
    h_MC_NoFsr_AFB[k]->SetLineStyle(2);
    h_MC_NoFsr_AFB[k]->Draw("sames");
    h_Closure_Unfolded_NoFsr_AFB[k]->SetLineColor(2);
    h_Closure_Unfolded_NoFsr_AFB[k]->SetMarkerColor(2);
    h_Closure_Unfolded_NoFsr_AFB[k]->SetMarkerStyle(25);
    h_Closure_Unfolded_NoFsr_AFB[k]->Draw("e1sames");
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
    Response_NoFsr_ForwardBackward_NO_NORM[k]->SetTitle(name_h);
    Response_NoFsr_ForwardBackward_NO_NORM[k]->GetXaxis()->SetTitle("Forward Gen M(#mu^{+}#mu^{-}) (Born level) [GeV]");
    Response_NoFsr_ForwardBackward_NO_NORM[k]->GetYaxis()->SetTitle("Backward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Response_NoFsr_ForwardBackward_NO_NORM[k]->Draw("colz");
  }
  r4->SaveAs("response_nofsr_forwardbackward_no_norm.C");

  TCanvas *r5 = new TCanvas();
  r5->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r5->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    gPad->SetLogz();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    Response_NoFsr_BackwardForward_NO_NORM[k]->SetTitle(name_h);
    Response_NoFsr_BackwardForward_NO_NORM[k]->GetXaxis()->SetTitle("Backward Gen M(#mu^{+}#mu^{-}) (Born level) [GeV]");
    Response_NoFsr_BackwardForward_NO_NORM[k]->GetYaxis()->SetTitle("Forward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Response_NoFsr_BackwardForward_NO_NORM[k]->Draw("colz");
  }
  r5->SaveAs("response_nofsr_backwardforward_no_norm.C");

  TCanvas *r4_1 = new TCanvas();
  r4_1->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r4_1->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    gPad->SetLogz();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    Response_NoFsr_Forward_NO_NORM[k]->SetTitle(name_h);
    Response_NoFsr_Forward_NO_NORM[k]->GetXaxis()->SetTitle("Forward Gen M(#mu^{+}#mu^{-}) (Born level) [GeV]");
    Response_NoFsr_Forward_NO_NORM[k]->GetYaxis()->SetTitle("Forward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Response_NoFsr_Forward_NO_NORM[k]->Draw("colz");
  }
  r4_1->SaveAs("response_nofsr_forward_no_norm.C");

  TCanvas *r5_1 = new TCanvas();
  r5_1->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r5_1->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    gPad->SetLogz();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    Response_NoFsr_Backward_NO_NORM[k]->SetTitle(name_h);
    Response_NoFsr_Backward_NO_NORM[k]->GetXaxis()->SetTitle("Backward Gen M(#mu^{+}#mu^{-}) (Born level) [GeV]");
    Response_NoFsr_Backward_NO_NORM[k]->GetYaxis()->SetTitle("Backward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Response_NoFsr_Backward_NO_NORM[k]->Draw("colz");
  }
  r5_1->SaveAs("response_nofsr_backward_no_norm.C");

  TCanvas *r6 = new TCanvas();
  r6->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r6->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    gPad->SetLogz();
    sprintf(name_h,"R(FB)/R(FF).   |Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    Response_NoFsr_ForwardBackward_NO_NORM[k]->SetTitle(name_h);
    Response_NoFsr_ForwardBackward_NO_NORM[k]->Divide(Response_NoFsr_Forward_NO_NORM[k]);
    Response_NoFsr_ForwardBackward_NO_NORM[k]->GetXaxis()->SetTitle("Forward Gen M(#mu^{+}#mu^{-}) (Born level) [GeV]");
    Response_NoFsr_ForwardBackward_NO_NORM[k]->GetYaxis()->SetTitle("Backward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Response_NoFsr_ForwardBackward_NO_NORM[k]->Draw("colz");
  }
  r6->SaveAs("response_nofsr_forwardbackward_divide_forward.C");

  TCanvas *r7 = new TCanvas();
  r7->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r7->cd(k+1);
    gPad->SetLogx();
    gPad->SetLogy();
    gPad->SetLogz();
    sprintf(name_h,"R(BF)/R(BB).    |Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    Response_NoFsr_BackwardForward_NO_NORM[k]->SetTitle(name_h);
    Response_NoFsr_BackwardForward_NO_NORM[k]->Divide(Response_NoFsr_Backward_NO_NORM[k]);
    Response_NoFsr_BackwardForward_NO_NORM[k]->GetXaxis()->SetTitle("Backward Gen M(#mu^{+}#mu^{-}) (Born lepton) [GeV]");
    Response_NoFsr_BackwardForward_NO_NORM[k]->GetYaxis()->SetTitle("Forward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Response_NoFsr_BackwardForward_NO_NORM[k]->Draw("colz");
  }
  r7->SaveAs("response_nofsr_backwardforward_divide_backward.C");


  //fsr uncertainty plots
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
  //end of fsr uncertainty plots


  //bkg uncertainty plots
  TCanvas *r8_bkg = new TCanvas();
  r8_bkg->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r8_bkg->cd(k+1);
    gPad->SetLogx();
    h_MC_Raw_AFB_bkg_Diff_Up[k]->SetLineWidth(2);
    h_MC_Raw_AFB_bkg_Diff_Up[k]->SetLineColor(4);
    h_MC_Raw_AFB_bkg_Diff_Up[k]->GetYaxis()->SetRangeUser(-0.0015,0.0015);
    h_MC_Raw_AFB_bkg_Diff_Up[k]->GetYaxis()->SetTitle("A_{FB}(raw)-A_{FB}(bkg Scaled)");
    h_MC_Raw_AFB_bkg_Diff_Up[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Raw_AFB_bkg_Diff_Up[k]->SetTitle(name_h);
    h_MC_Raw_AFB_bkg_Diff_Up[k]->Draw();
    h_MC_Raw_AFB_bkg_Diff_Down[k]->SetLineWidth(2);
    h_MC_Raw_AFB_bkg_Diff_Down[k]->SetLineColor(2);
    h_MC_Raw_AFB_bkg_Diff_Down[k]->Draw("sames");
  }
  r8_bkg->SaveAs("bkg_uncertainty_at_raw.C");

  TCanvas *r8_bkg_1 = new TCanvas();
  r8_bkg_1->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r8_bkg_1->cd(k+1);
    gPad->SetLogx();
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[k]->SetLineColor(4);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[k]->GetYaxis()->SetRangeUser(-0.0015,0.0015);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[k]->GetYaxis()->SetTitle("A_{FB}(Bare)-A_{FB}(bkg Scaled)");
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[k]->SetTitle(name_h);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Up[k]->Draw();
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Down[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Down[k]->SetLineColor(2);
    h_MC_Unfolded_UnDet_AFB_bkg_Diff_Down[k]->Draw("sames");
  }
  r8_bkg_1->SaveAs("bkg_uncertainty_at_bare_lepton.C");

  TCanvas *r9_bkg = new TCanvas();
  r9_bkg->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r9_bkg->cd(k+1);
    gPad->SetLogx();
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[k]->SetLineColor(4);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[k]->GetYaxis()->SetRangeUser(-0.0015,0.0015);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[k]->GetYaxis()->SetTitle("A_{FB}(Born)-A_{FB}(bkg Scaled)");
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[k]->SetTitle(name_h);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Up[k]->Draw();
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Down[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Down[k]->SetLineColor(2);
    h_MC_Unfolded_NoFsr_AFB_bkg_Diff_Down[k]->Draw("sames");
  }
  r9_bkg->SaveAs("bkg_uncertainty_at_born_level.C");
  //end of bkg uncertainty plots


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

  TCanvas *r10_m = new TCanvas();
  r10_m->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r10_m->cd(k+1);
    h_MC_True_sin2412m2312_AFB[k]->SetLineWidth(2);
    h_MC_True_sin2412m2312_AFB[k]->SetLineColor(4);
    h_MC_True_sin2412m2312_AFB[k]->GetYaxis()->SetRangeUser(-0.1,0.1);
    h_MC_True_sin2412m2312_AFB[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_MC_True_sin2412m2312_AFB[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_True_sin2412m2312_AFB[k]->SetTitle(name_h);
    h_MC_True_sin2412m2312_AFB[k]->Draw("e1");
    h_MC_True_sin2212m2312_AFB[k]->SetLineWidth(2);
    h_MC_True_sin2212m2312_AFB[k]->SetLineColor(2);
    h_MC_True_sin2212m2312_AFB[k]->SetLineStyle(2);
    h_MC_True_sin2212m2312_AFB[k]->Draw("e1sames");
  }
  r10_m->SaveAs("sin2thetaW_uncertainty_at_the_parton_level.C");


  TCanvas *r11 = new TCanvas();
  r11->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r11->cd(k+1);
    gPad->SetLogx();
    h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[k]->SetLineColor(4);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[k]->GetYaxis()->SetRangeUser(-0.04,0.04);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[k]->SetTitle(name_h);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2412m2312[k]->Draw();
    h_MC_Unfolded_UnDet_AFB_Diff_sin2212m2312[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2212m2312[k]->SetLineColor(2);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2212m2312[k]->SetLineStyle(2);
    h_MC_Unfolded_UnDet_AFB_Diff_sin2212m2312[k]->Draw("sames");
  }
  r11->SaveAs("sin2thetaW_uncertainty_at_bare_lepton_level.C");

  TCanvas *r12 = new TCanvas();
  r12->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r12->cd(k+1);
    gPad->SetLogx();
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[k]->SetLineColor(4);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[k]->GetYaxis()->SetRangeUser(-0.04,0.04);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[k]->SetTitle(name_h);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2412m2312[k]->Draw();
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2212m2312[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2212m2312[k]->SetLineColor(2);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2212m2312[k]->SetLineStyle(2);
    h_MC_Unfolded_NoFsr_AFB_Diff_sin2212m2312[k]->Draw("sames");
  }
  r12->SaveAs("sin2thetaW_uncertainty_at_born_level.C");

  TCanvas *r13 = new TCanvas();
  r13->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r13->cd(k+1);
    gPad->SetLogx();
    h_MC_Raw_Align_Startup_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Startup_m_Ideal_AFB[k]->SetLineColor(1);
    h_MC_Raw_Align_Startup_m_Ideal_AFB[k]->GetYaxis()->SetRangeUser(-0.1,0.1);
    h_MC_Raw_Align_Startup_m_Ideal_AFB[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_MC_Raw_Align_Startup_m_Ideal_AFB[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Raw_Align_Startup_m_Ideal_AFB[k]->SetTitle(name_h);
    h_MC_Raw_Align_Startup_m_Ideal_AFB[k]->Draw();

    h_MC_Raw_Align_Bowing_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Bowing_m_Ideal_AFB[k]->SetLineColor(2);
    h_MC_Raw_Align_Bowing_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Raw_Align_Elliptical_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Elliptical_m_Ideal_AFB[k]->SetLineColor(5);
    h_MC_Raw_Align_Elliptical_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Raw_Align_Radial_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Radial_m_Ideal_AFB[k]->SetLineColor(6);
    h_MC_Raw_Align_Radial_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Raw_Align_Sagitta_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Sagitta_m_Ideal_AFB[k]->SetLineColor(7);
    h_MC_Raw_Align_Sagitta_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Raw_Align_Skew_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Skew_m_Ideal_AFB[k]->SetLineColor(8);
    h_MC_Raw_Align_Skew_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Raw_Align_Telescope_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Telescope_m_Ideal_AFB[k]->SetLineColor(9);
    h_MC_Raw_Align_Telescope_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Raw_Align_CurlV2TF_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_CurlV2TF_m_Ideal_AFB[k]->SetLineColor(13);
    h_MC_Raw_Align_CurlV2TF_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Raw_Align_Twist_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Twist_m_Ideal_AFB[k]->SetLineColor(11);
    h_MC_Raw_Align_Twist_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Raw_Align_Zexpansion_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Raw_Align_Zexpansion_m_Ideal_AFB[k]->SetLineColor(12);
    h_MC_Raw_Align_Zexpansion_m_Ideal_AFB[k]->Draw("sames");
  }
  r13->SaveAs("Alignment_uncertainty_at_raw_level.C");

  TCanvas *r14 = new TCanvas();
  r14->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r14->cd(k+1);
    gPad->SetLogx();
    h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[k]->SetLineColor(1);
    h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[k]->GetYaxis()->SetRangeUser(-0.04,0.04);
    h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[k]->SetTitle(name_h);
    h_MC_Unfolded_UnDet_Align_Startup_m_Ideal_AFB[k]->Draw();

    h_MC_Unfolded_UnDet_Align_Bowing_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Bowing_m_Ideal_AFB[k]->SetLineColor(2);
    h_MC_Unfolded_UnDet_Align_Bowing_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_UnDet_Align_Elliptical_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Elliptical_m_Ideal_AFB[k]->SetLineColor(5);
    h_MC_Unfolded_UnDet_Align_Elliptical_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_UnDet_Align_Radial_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Radial_m_Ideal_AFB[k]->SetLineColor(6);
    h_MC_Unfolded_UnDet_Align_Radial_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_UnDet_Align_Sagitta_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Sagitta_m_Ideal_AFB[k]->SetLineColor(7);
    h_MC_Unfolded_UnDet_Align_Sagitta_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_UnDet_Align_Skew_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Skew_m_Ideal_AFB[k]->SetLineColor(8);
    h_MC_Unfolded_UnDet_Align_Skew_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_UnDet_Align_Telescope_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Telescope_m_Ideal_AFB[k]->SetLineColor(9);
    h_MC_Unfolded_UnDet_Align_Telescope_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_UnDet_Align_CurlV2TF_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_CurlV2TF_m_Ideal_AFB[k]->SetLineColor(13);
    h_MC_Unfolded_UnDet_Align_CurlV2TF_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_UnDet_Align_Twist_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Twist_m_Ideal_AFB[k]->SetLineColor(11);
    h_MC_Unfolded_UnDet_Align_Twist_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_UnDet_Align_Zexpansion_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_UnDet_Align_Zexpansion_m_Ideal_AFB[k]->SetLineColor(12);
    h_MC_Unfolded_UnDet_Align_Zexpansion_m_Ideal_AFB[k]->Draw("sames");
  }
  r14->SaveAs("Alignment_uncertainty_at_bare_lepton_level.C");

  TCanvas *r15 = new TCanvas();
  r15->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r15->cd(k+1);
    gPad->SetLogx();
    h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[k]->SetLineColor(1);
    h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[k]->GetYaxis()->SetRangeUser(-0.04,0.04);
    h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[k]->SetTitle(name_h);
    h_MC_Unfolded_NoFsr_Align_Startup_m_Ideal_AFB[k]->Draw();

    h_MC_Unfolded_NoFsr_Align_Bowing_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Bowing_m_Ideal_AFB[k]->SetLineColor(2);
    h_MC_Unfolded_NoFsr_Align_Bowing_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_NoFsr_Align_Elliptical_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Elliptical_m_Ideal_AFB[k]->SetLineColor(5);
    h_MC_Unfolded_NoFsr_Align_Elliptical_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_NoFsr_Align_Radial_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Radial_m_Ideal_AFB[k]->SetLineColor(6);
    h_MC_Unfolded_NoFsr_Align_Radial_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_NoFsr_Align_Sagitta_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Sagitta_m_Ideal_AFB[k]->SetLineColor(7);
    h_MC_Unfolded_NoFsr_Align_Sagitta_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_NoFsr_Align_Skew_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Skew_m_Ideal_AFB[k]->SetLineColor(8);
    h_MC_Unfolded_NoFsr_Align_Skew_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_NoFsr_Align_Telescope_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Telescope_m_Ideal_AFB[k]->SetLineColor(9);
    h_MC_Unfolded_NoFsr_Align_Telescope_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_NoFsr_Align_CurlV2TF_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_CurlV2TF_m_Ideal_AFB[k]->SetLineColor(13);
    h_MC_Unfolded_NoFsr_Align_CurlV2TF_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_NoFsr_Align_Twist_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Twist_m_Ideal_AFB[k]->SetLineColor(11);
    h_MC_Unfolded_NoFsr_Align_Twist_m_Ideal_AFB[k]->Draw("sames");

    h_MC_Unfolded_NoFsr_Align_Zexpansion_m_Ideal_AFB[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_Align_Zexpansion_m_Ideal_AFB[k]->SetLineColor(12);
    h_MC_Unfolded_NoFsr_Align_Zexpansion_m_Ideal_AFB[k]->Draw("sames");
  }
  r15->SaveAs("Alignment_uncertainty_at_Born_level.C");



 TCanvas *r16 = new TCanvas();
  r16->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r16->cd(k+1);
    gPad->SetLogx();
    h_DeltaXmaxPlus_ct10[k]->SetLineWidth(2);
    h_DeltaXmaxPlus_ct10[k]->SetLineColor(4);
    h_DeltaXmaxPlus_ct10[k]->GetYaxis()->SetRangeUser(0.,0.016);
    h_DeltaXmaxPlus_ct10[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_DeltaXmaxPlus_ct10[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_DeltaXmaxPlus_ct10[k]->SetTitle(name_h);
    h_DeltaXmaxPlus_ct10[k]->Draw();
    h_DeltaXmaxMinus_ct10[k]->SetLineWidth(2);
    h_DeltaXmaxMinus_ct10[k]->SetLineColor(2);
    h_DeltaXmaxMinus_ct10[k]->SetLineStyle(2);
    h_DeltaXmaxMinus_ct10[k]->Draw("sames");
  }
  r16->SaveAs("pdf_ct10_uncertainty_at_raw_level.C");

 TCanvas *r16_1 = new TCanvas();
  r16_1->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r16_1->cd(k+1);
    gPad->SetLogx();
    h_DeltaXmaxPlus_undet_ct10[k]->SetLineWidth(2);
    h_DeltaXmaxPlus_undet_ct10[k]->SetLineColor(4);
    h_DeltaXmaxPlus_undet_ct10[k]->GetYaxis()->SetRangeUser(0.,0.016);
    h_DeltaXmaxPlus_undet_ct10[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_DeltaXmaxPlus_undet_ct10[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_DeltaXmaxPlus_undet_ct10[k]->SetTitle(name_h);
    h_DeltaXmaxPlus_undet_ct10[k]->Draw();
    h_DeltaXmaxMinus_undet_ct10[k]->SetLineWidth(2);
    h_DeltaXmaxMinus_undet_ct10[k]->SetLineColor(2);
    h_DeltaXmaxMinus_undet_ct10[k]->SetLineStyle(2);
    h_DeltaXmaxMinus_undet_ct10[k]->Draw("sames");
  }
  r16_1->SaveAs("pdf_undet_ct10_uncertainty_at_raw_level.C");


 TCanvas *r17 = new TCanvas();
  r17->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r17->cd(k+1);
    gPad->SetLogx();
    h_DeltaXmaxPlus_mstw[k]->SetLineWidth(2);
    h_DeltaXmaxPlus_mstw[k]->SetLineColor(4);
    h_DeltaXmaxPlus_mstw[k]->GetYaxis()->SetRangeUser(0.,0.007);
    h_DeltaXmaxPlus_mstw[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_DeltaXmaxPlus_mstw[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_DeltaXmaxPlus_mstw[k]->SetTitle(name_h);
    h_DeltaXmaxPlus_mstw[k]->Draw();
    h_DeltaXmaxMinus_mstw[k]->SetLineWidth(2);
    h_DeltaXmaxMinus_mstw[k]->SetLineColor(2);
    h_DeltaXmaxMinus_mstw[k]->SetLineStyle(2);
    h_DeltaXmaxMinus_mstw[k]->Draw("sames");
  }
  r17->SaveAs("pdf_mstw_uncertainty_at_raw_level.C");

 TCanvas *r18 = new TCanvas();
  r18->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r18->cd(k+1);
    gPad->SetLogx();
    h_sigma[k]->SetLineWidth(2);
    h_sigma[k]->SetLineColor(4);
    h_sigma[k]->GetYaxis()->SetRangeUser(0.,0.01);
    h_sigma[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_sigma[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_sigma[k]->SetTitle(name_h);
    h_sigma[k]->Draw();
  }
  r18->SaveAs("pdf_nnpdf_uncertainty_at_raw_level.C");


 TCanvas *r19 = new TCanvas();
  r19->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r19->cd(k+1);
    gPad->SetLogx();
    h_Delta_AFB_alphas_PLUS[k]->SetLineWidth(2);
    h_Delta_AFB_alphas_PLUS[k]->SetLineColor(4);
    h_Delta_AFB_alphas_PLUS[k]->GetYaxis()->SetRangeUser(-0.006,0.006);
    h_Delta_AFB_alphas_PLUS[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_Delta_AFB_alphas_PLUS[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_Delta_AFB_alphas_PLUS[k]->SetTitle(name_h);
    h_Delta_AFB_alphas_PLUS[k]->Draw();
    h_Delta_AFB_alphas_MINUS[k]->SetLineWidth(2);
    h_Delta_AFB_alphas_MINUS[k]->SetLineColor(2);
    h_Delta_AFB_alphas_MINUS[k]->SetLineStyle(2);
    h_Delta_AFB_alphas_MINUS[k]->Draw("sames");
  }
  r19->SaveAs("pdf_alpha_s_uncertainty_at_raw_level.C");

TCanvas *r20 = new TCanvas();
  r20->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r20->cd(k+1);
    gPad->SetLogx();
    h_DeltaX_CT10_ALPHAS_PLUS[k]->SetLineWidth(2);
    h_DeltaX_CT10_ALPHAS_PLUS[k]->SetLineColor(4);
    h_DeltaX_CT10_ALPHAS_PLUS[k]->GetYaxis()->SetRangeUser(0.,0.016);
    h_DeltaX_CT10_ALPHAS_PLUS[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_DeltaX_CT10_ALPHAS_PLUS[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_DeltaX_CT10_ALPHAS_PLUS[k]->SetTitle(name_h);
    h_DeltaX_CT10_ALPHAS_PLUS[k]->Draw();
    h_DeltaX_CT10_ALPHAS_MINUS[k]->SetLineWidth(2);
    h_DeltaX_CT10_ALPHAS_MINUS[k]->SetLineColor(2);
    h_DeltaX_CT10_ALPHAS_MINUS[k]->SetLineStyle(2);
    h_DeltaX_CT10_ALPHAS_MINUS[k]->Draw("sames");
  }
  r20->SaveAs("pdf_CT10_plus_alpha_s_uncertainty_at_raw_level.C");

TCanvas *r21 = new TCanvas();
  r21->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r21->cd(k+1);
    gPad->SetLogx();
    h_envelope_sigma[k]->SetLineWidth(2);
    h_envelope_sigma[k]->SetLineColor(4);
    h_envelope_sigma[k]->GetYaxis()->SetRangeUser(0.,0.016);
    h_envelope_sigma[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_envelope_sigma[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_envelope_sigma[k]->SetTitle(name_h);
    h_envelope_sigma[k]->Draw();
  }
  r21->SaveAs("pdf_envelope_uncertainty_at_raw_level.C");

TCanvas *r22 = new TCanvas();
  r22->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    r22->cd(k+1);
    gPad->SetLogx();
    h_total_plus[k]->SetLineWidth(2);
    h_total_plus[k]->SetLineColor(4);
    h_total_plus[k]->GetYaxis()->SetRangeUser(0.,0.016);
    h_total_plus[k]->GetYaxis()->SetTitle("#DeltaA_{FB}");
    h_total_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_total_plus[k]->SetTitle(name_h);
    h_total_plus[k]->Draw();
    h_total_minus[k]->SetLineWidth(2);
    h_total_minus[k]->SetLineColor(2);
    h_total_minus[k]->SetLineStyle(2);
    h_total_minus[k]->Draw("sames");
  }
  r22->SaveAs("total_systematic_uncertainty_at_raw_level.C");





  /*
  TGraph *gr_band1 = new TGraph(nb*2,band_x1,band_y1);
  TGraph *gr_band2 = new TGraph(nb*2,band_x1,band_y2);
  TGraph *gr_band3 = new TGraph(nb*2,band_x1,band_y3);
  TGraph *gr_band4 = new TGraph(nb*2,band_x1,band_y4);
  
  TCanvas *r23 = new TCanvas();
  TH2F* frame1 = new TH2F("frame1","|Y|=0.00-1.00",100,30,1000,100,-0.1,0.1);
  frame1->GetXaxis()->SetRangeUser(40,320);
  frame1->GetYaxis()->SetRangeUser(-0.098,0.072);
  frame1->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame1->GetYaxis()->SetTitle("A_{FB}(mod)-A_{FB}");
  frame1->GetYaxis()->CenterTitle();
  frame1->Draw();
  gr_band1->SetMarkerStyle(28);
  gr_band1->SetFillColor(20);
  gr_band1->SetLineColor(20);
  gr_band1->SetMarkerColor(20);
  gr_band1->Draw("F");
  r23->SaveAs("del.C");
  */


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
  
  float AFB0_UnDet[nb];
  float AFB1_UnDet[nb];
  float AFB2_UnDet[nb];
  float AFB3_UnDet[nb];
  float AFB_Err0_UnDet[nb];
  float AFB_Err1_UnDet[nb];
  float AFB_Err2_UnDet[nb];
  float AFB_Err3_UnDet[nb];
  float AFB_x0_UnDet[nb];
  float AFB_x1_UnDet[nb];
  float AFB_x2_UnDet[nb];
  float AFB_x3_UnDet[nb];

  float AFB0_NoFsr[nb];
  float AFB1_NoFsr[nb];
  float AFB2_NoFsr[nb];
  float AFB3_NoFsr[nb];
  float AFB_Err0_NoFsr[nb];
  float AFB_Err1_NoFsr[nb];
  float AFB_Err2_NoFsr[nb];
  float AFB_Err3_NoFsr[nb];
  float AFB_x0_NoFsr[nb];
  float AFB_x1_NoFsr[nb];
  float AFB_x2_NoFsr[nb];
  float AFB_x3_NoFsr[nb];

  float AFB0_Comb[nb];
  float AFB1_Comb[nb];
  float AFB2_Comb[nb];
  float AFB3_Comb[nb];
  float AFB_Err0_Comb[nb];
  float AFB_Err1_Comb[nb];
  float AFB_Err2_Comb[nb];
  float AFB_Err3_Comb[nb];
  float AFB_x0_Comb[nb];
  float AFB_x1_Comb[nb];
  float AFB_x2_Comb[nb];
  float AFB_x3_Comb[nb];


  float AFB0_Parton[nb];
  float AFB1_Parton[nb];
  float AFB2_Parton[nb];
  float AFB3_Parton[nb];
  float AFB_Err0_Parton[nb];
  float AFB_Err1_Parton[nb];
  float AFB_Err2_Parton[nb];
  float AFB_Err3_Parton[nb];
  float AFB_x0_Parton[nb];
  float AFB_x1_Parton[nb];
  float AFB_x2_Parton[nb];
  float AFB_x3_Parton[nb];

  for (int j=0;j<nb_Y;j++){
    for (int i=0;i<nb;i++){
      if (j == 0){ 
	AFB0[i] = h_Raw_AFB[j]->GetBinContent(i+1);
	AFB_Err0[i] = h_Raw_AFB[j]->GetBinError(i+1);
	AFB_x0[i] = hExpectedMass_RAW_M_Y[j][i]->GetMean();

	AFB0_UnDet[i] = h_Unfolded_UnDet_AFB[j]->GetBinContent(i+1);
	AFB_Err0_UnDet[i] = h_Unfolded_UnDet_AFB[j]->GetBinError(i+1);
	AFB_x0_UnDet[i] = hExpectedMass_UnDet_M_Y[j][i]->GetMean();

	AFB0_NoFsr[i] = h_Unfolded_NoFsr_AFB[j]->GetBinContent(i+1);
	AFB_Err0_NoFsr[i] = h_Unfolded_NoFsr_AFB[j]->GetBinError(i+1);
	AFB_x0_NoFsr[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();

	AFB0_Comb[i] = h_Combined[j]->GetBinContent(i+1);
	AFB_Err0_Comb[i] = h_Combined[j]->GetBinError(i+1);
	AFB_x0_Comb[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();

	AFB0_Parton[i] = h_Unfolded_NoFsr_AFB[j]->GetBinContent(i+1)*dilution[j][i];
	AFB_Err0_Parton[i] = h_Unfolded_NoFsr_AFB[j]->GetBinError(i+1)*dilution[j][i];
	AFB_x0_Parton[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();
      }
      if (j == 1){ 
	AFB1[i] = h_Raw_AFB[j]->GetBinContent(i+1);
	AFB_Err1[i] = h_Raw_AFB[j]->GetBinError(i+1);
	AFB_x1[i] = hExpectedMass_RAW_M_Y[j][i]->GetMean();

	AFB1_UnDet[i] = h_Unfolded_UnDet_AFB[j]->GetBinContent(i+1);
	AFB_Err1_UnDet[i] = h_Unfolded_UnDet_AFB[j]->GetBinError(i+1);
	AFB_x1_UnDet[i] = hExpectedMass_UnDet_M_Y[j][i]->GetMean();

	AFB1_NoFsr[i] = h_Unfolded_NoFsr_AFB[j]->GetBinContent(i+1);
	AFB_Err1_NoFsr[i] = h_Unfolded_NoFsr_AFB[j]->GetBinError(i+1);
	AFB_x1_NoFsr[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();

	AFB1_Comb[i] = h_Combined[j]->GetBinContent(i+1);
	AFB_Err1_Comb[i] = h_Combined[j]->GetBinError(i+1);
	AFB_x1_Comb[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();

	AFB1_Parton[i] = h_Unfolded_NoFsr_AFB[j]->GetBinContent(i+1)*dilution[j][i];
	AFB_Err1_Parton[i] = h_Unfolded_NoFsr_AFB[j]->GetBinError(i+1)*dilution[j][i];
	AFB_x1_Parton[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();
      }
      if (j == 2){ 
	AFB2[i] = h_Raw_AFB[j]->GetBinContent(i+1);
	AFB_Err2[i] = h_Raw_AFB[j]->GetBinError(i+1);
	AFB_x2[i] = hExpectedMass_RAW_M_Y[j][i]->GetMean();

	AFB2_UnDet[i] = h_Unfolded_UnDet_AFB[j]->GetBinContent(i+1);
	AFB_Err2_UnDet[i] = h_Unfolded_UnDet_AFB[j]->GetBinError(i+1);
	AFB_x2_UnDet[i] = hExpectedMass_UnDet_M_Y[j][i]->GetMean();

	AFB2_NoFsr[i] = h_Unfolded_NoFsr_AFB[j]->GetBinContent(i+1);
	AFB_Err2_NoFsr[i] = h_Unfolded_NoFsr_AFB[j]->GetBinError(i+1);
	AFB_x2_NoFsr[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();

	AFB2_Comb[i] = h_Combined[j]->GetBinContent(i+1);
	AFB_Err2_Comb[i] = h_Combined[j]->GetBinError(i+1);
	AFB_x2_Comb[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();

	AFB2_Parton[i] = h_Unfolded_NoFsr_AFB[j]->GetBinContent(i+1)*dilution[j][i];
	AFB_Err2_Parton[i] = h_Unfolded_NoFsr_AFB[j]->GetBinError(i+1)*dilution[j][i];
	AFB_x2_Parton[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();
      }
      if (j == 3){ 
	AFB3[i] = h_Raw_AFB[j]->GetBinContent(i+1);
	AFB_Err3[i] = h_Raw_AFB[j]->GetBinError(i+1);
	AFB_x3[i] = hExpectedMass_RAW_M_Y[j][i]->GetMean();

	AFB3_UnDet[i] = h_Unfolded_UnDet_AFB[j]->GetBinContent(i+1);
	AFB_Err3_UnDet[i] = h_Unfolded_UnDet_AFB[j]->GetBinError(i+1);
	AFB_x3_UnDet[i] = hExpectedMass_UnDet_M_Y[j][i]->GetMean();

	AFB3_NoFsr[i] = h_Unfolded_NoFsr_AFB[j]->GetBinContent(i+1);
	AFB_Err3_NoFsr[i] = h_Unfolded_NoFsr_AFB[j]->GetBinError(i+1);
	AFB_x3_NoFsr[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();

	AFB3_Comb[i] = h_Combined[j]->GetBinContent(i+1);
	AFB_Err3_Comb[i] = h_Combined[j]->GetBinError(i+1);
	AFB_x3_Comb[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();

	AFB3_Parton[i] = h_Unfolded_NoFsr_AFB[j]->GetBinContent(i+1)*dilution[j][i];
	AFB_Err3_Parton[i] = h_Unfolded_NoFsr_AFB[j]->GetBinError(i+1)*dilution[j][i];
	AFB_x3_Parton[i] = hExpectedMass_NoFsr_M_Y[j][i]->GetMean();
      }
    }
  }


  for (int k=0;k<nb_Y;k++){
    for (int i=0;i<nb;i++){
      y_plus[k][i] = h_MC_Raw_AFB[k]->GetBinContent(i+1)+total_plus[k][i];
      y_minus[k][i] = h_MC_Raw_AFB[k]->GetBinContent(i+1)+total_minus[k][i];

      y_plus_undet[k][i] = h_MC_UnDet_AFB[k]->GetBinContent(i+1)+total_plus_undet[k][i];
      y_minus_undet[k][i] = h_MC_UnDet_AFB[k]->GetBinContent(i+1)+total_minus_undet[k][i];

      y_plus_nofsr[k][i] = h_MC_NoFsr_AFB[k]->GetBinContent(i+1)+total_plus_nofsr[k][i];
      y_minus_nofsr[k][i] = h_MC_NoFsr_AFB[k]->GetBinContent(i+1)+total_minus_nofsr[k][i];
      if (k==1){ 
	cout<<"raw   "<<k<<"   "<<i<<"   "<<h_MC_Raw_AFB[k]->GetBinContent(i+1)<<"   "<<total_plus[k][i]<<"   "<<total_minus[k][i]<<endl;
	cout<<"born   "<<k<<"   "<<i<<"   "<<h_MC_NoFsr_AFB[k]->GetBinContent(i+1)<<"   "<<total_plus_nofsr[k][i]<<"   "<<total_minus_nofsr[k][i]<<endl;
      }

      y_plus_comb[k][i] = h_MC_NoFsr_AFB[k]->GetBinContent(i+1)+total_plus_comb[k][i];
      y_minus_comb[k][i] = h_MC_NoFsr_AFB[k]->GetBinContent(i+1)+total_minus_comb[k][i];    
    }
  }

  int j = nb-1;
  for (int i=0;i<nb;i++){
    band_x1[i] =  AFB_x0[i];
    band_x1[i+nb] =  AFB_x0[j];
    band_x2[i] =  AFB_x1[i];
    band_x2[i+nb] =  AFB_x1[j];
    band_x3[i] =  AFB_x2[i];
    band_x3[i+nb] =  AFB_x2[j];
    band_x4[i] =  AFB_x3[i];//(xAxis_AFB[i]+xAxis_AFB[i+1])/2.;
    band_x4[i+nb] =  AFB_x3[j];//(xAxis_AFB[j]+xAxis_AFB[j+1])/2.;

    band_x1_UnDet[i] =  AFB_x0_UnDet[i];
    band_x1_UnDet[i+nb] =  AFB_x0_UnDet[j];
    band_x2_UnDet[i] =  AFB_x1_UnDet[i];
    band_x2_UnDet[i+nb] =  AFB_x1_UnDet[j];
    band_x3_UnDet[i] =  AFB_x2_UnDet[i];
    band_x3_UnDet[i+nb] =  AFB_x2_UnDet[j];
    band_x4_UnDet[i] =  AFB_x3_UnDet[i];//(xAxis_AFB[i]+xAxis_AFB[i+1])/2.;
    band_x4_UnDet[i+nb] =  AFB_x3_UnDet[j];//(xAxis_AFB[j]+xAxis_AFB[j+1])/2.;

    band_x1_NoFsr[i] =  AFB_x0_NoFsr[i];
    band_x1_NoFsr[i+nb] =  AFB_x0_NoFsr[j];
    band_x2_NoFsr[i] =  AFB_x1_NoFsr[i];
    band_x2_NoFsr[i+nb] =  AFB_x1_NoFsr[j];
    band_x3_NoFsr[i] =  AFB_x2_NoFsr[i];
    band_x3_NoFsr[i+nb] =  AFB_x2_NoFsr[j];
    band_x4_NoFsr[i] =  AFB_x3_NoFsr[i];//(xAxis_AFB[i]+xAxis_AFB[i+1])/2.;
    band_x4_NoFsr[i+nb] =  AFB_x3_NoFsr[j];//(xAxis_AFB[j]+xAxis_AFB[j+1])/2.;




    band_y1[i] = total_minus[0][i];
    band_y1[i+nb] = total_plus[0][j];
    band_y2[i] = total_minus[1][i];
    band_y2[i+nb] = total_plus[1][j];
    band_y3[i] = total_minus[2][i];
    band_y3[i+nb] = total_plus[2][j];
    band_y4[i] = total_minus[3][i];
    band_y4[i+nb] = total_plus[3][j];

    band_afb_y1[i] = y_minus[0][i];
    band_afb_y1[i+nb] =  y_plus[0][j];
    band_afb_y2[i] = y_minus[1][i];
    band_afb_y2[i+nb] =  y_plus[1][j];
    band_afb_y3[i] = y_minus[2][i];
    band_afb_y3[i+nb] =  y_plus[2][j];
    band_afb_y4[i] = y_minus[3][i];
    band_afb_y4[i+nb] =  y_plus[3][j];


    band_y1_undet[i] = total_minus_undet[0][i];
    band_y1_undet[i+nb] = total_plus_undet[0][j];
    band_y2_undet[i] = total_minus_undet[1][i];
    band_y2_undet[i+nb] = total_plus_undet[1][j];
    band_y3_undet[i] = total_minus_undet[2][i];
    band_y3_undet[i+nb] = total_plus_undet[2][j];
    band_y4_undet[i] = total_minus_undet[3][i];
    band_y4_undet[i+nb] = total_plus_undet[3][j];

    band_afb_y1_undet[i] = y_minus_undet[0][i];
    band_afb_y1_undet[i+nb] =  y_plus_undet[0][j];
    band_afb_y2_undet[i] = y_minus_undet[1][i];
    band_afb_y2_undet[i+nb] =  y_plus_undet[1][j];
    band_afb_y3_undet[i] = y_minus_undet[2][i];
    band_afb_y3_undet[i+nb] =  y_plus_undet[2][j];
    band_afb_y4_undet[i] = y_minus_undet[3][i];
    band_afb_y4_undet[i+nb] =  y_plus_undet[3][j];



    band_afb_y1_nofsr[i] = y_minus_nofsr[0][i];
    band_afb_y1_nofsr[i+nb] =  y_plus_nofsr[0][j];
    band_afb_y2_nofsr[i] = y_minus_nofsr[1][i];
    band_afb_y2_nofsr[i+nb] =  y_plus_nofsr[1][j];
    band_afb_y3_nofsr[i] = y_minus_nofsr[2][i];
    band_afb_y3_nofsr[i+nb] =  y_plus_nofsr[2][j];
    band_afb_y4_nofsr[i] = y_minus_nofsr[3][i];
    band_afb_y4_nofsr[i+nb] =  y_plus_nofsr[3][j];

    cout<<"raw   "<<i<<"  "<<band_afb_y2[i]<<"   "<<i+nb<<"  "<<band_afb_y2[i+nb]<<endl;
    cout<<"born   "<<i<<"  "<<band_afb_y2_nofsr[i]<<"   "<<i+nb<<"  "<<band_afb_y2_nofsr[i+nb]<<endl;


    band_afb_y1_comb[i] = y_minus_comb[0][i];
    band_afb_y1_comb[i+nb] =  y_plus_comb[0][j];
    band_afb_y2_comb[i] = y_minus_comb[1][i];
    band_afb_y2_comb[i+nb] =  y_plus_comb[1][j];
    band_afb_y3_comb[i] = y_minus_comb[2][i];
    band_afb_y3_comb[i+nb] =  y_plus_comb[2][j];
    band_afb_y4_comb[i] = y_minus_comb[3][i];
    band_afb_y4_comb[i+nb] =  y_plus_comb[3][j];


    j--;
  }

  TGraph *gr_afb_band1 = new TGraph(nb*2,band_x1,band_afb_y1);
  TGraph *gr_afb_band2 = new TGraph(nb*2,band_x2,band_afb_y2);
  TGraph *gr_afb_band3 = new TGraph(nb*2,band_x3,band_afb_y3);
  TGraph *gr_afb_band4 = new TGraph(nb*2,band_x4,band_afb_y4);


  TGraph *gr[nb_Y];
  gr[0] = new TGraphErrors(nb,AFB_x0,AFB0,0,AFB_Err0);
  gr[1] = new TGraphErrors(nb,AFB_x1,AFB1,0,AFB_Err1);
  gr[2] = new TGraphErrors(nb,AFB_x2,AFB2,0,AFB_Err2);
  gr[3] = new TGraphErrors(nb,AFB_x3,AFB3,0,AFB_Err3);

  TGraph *gr_UnDet[nb_Y];
  gr_UnDet[0] = new TGraphErrors(nb,AFB_x0_UnDet,AFB0_UnDet,0,AFB_Err0_UnDet);
  gr_UnDet[1] = new TGraphErrors(nb,AFB_x1_UnDet,AFB1_UnDet,0,AFB_Err1_UnDet);
  gr_UnDet[2] = new TGraphErrors(nb,AFB_x2_UnDet,AFB2_UnDet,0,AFB_Err2_UnDet);
  gr_UnDet[3] = new TGraphErrors(nb,AFB_x3_UnDet,AFB3_UnDet,0,AFB_Err3_UnDet);

  TGraph *gr_NoFsr[nb_Y];
  gr_NoFsr[0] = new TGraphErrors(nb,AFB_x0_NoFsr,AFB0_NoFsr,0,AFB_Err0_NoFsr);
  gr_NoFsr[1] = new TGraphErrors(nb,AFB_x1_NoFsr,AFB1_NoFsr,0,AFB_Err1_NoFsr);
  gr_NoFsr[2] = new TGraphErrors(nb,AFB_x2_NoFsr,AFB2_NoFsr,0,AFB_Err2_NoFsr);
  gr_NoFsr[3] = new TGraphErrors(nb,AFB_x3_NoFsr,AFB3_NoFsr,0,AFB_Err3_NoFsr);

  TGraph *gr_Comb[nb_Y];
  gr_Comb[0] = new TGraphErrors(nb,AFB_x0_Comb,AFB0_Comb,0,AFB_Err0_Comb);
  gr_Comb[1] = new TGraphErrors(nb,AFB_x1_Comb,AFB1_Comb,0,AFB_Err1_Comb);
  gr_Comb[2] = new TGraphErrors(nb,AFB_x2_Comb,AFB2_Comb,0,AFB_Err2_Comb);
  gr_Comb[3] = new TGraphErrors(nb,AFB_x3_Comb,AFB3_Comb,0,AFB_Err3_Comb);

  TGraph *gr_Parton[nb_Y];
  gr_Parton[0] = new TGraphErrors(nb,AFB_x0_Parton,AFB0_Parton,0,AFB_Err0_Parton);
  gr_Parton[1] = new TGraphErrors(nb,AFB_x1_Parton,AFB1_Parton,0,AFB_Err1_Parton);
  gr_Parton[2] = new TGraphErrors(nb,AFB_x2_Parton,AFB2_Parton,0,AFB_Err2_Parton);
  gr_Parton[3] = new TGraphErrors(nb,AFB_x3_Parton,AFB3_Parton,0,AFB_Err3_Parton);

  TCanvas *r24 = new TCanvas();
  r24->Divide(2,2);
  r24->cd(1);

  TH2F* frame1a = new TH2F("frame1a","|Y|=0.00-1.00",100,30,400,100,-0.2,0.5);
  frame1a->GetXaxis()->SetRangeUser(40,1500);
  frame1a->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame1a->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame1a->GetYaxis()->SetTitle("A_{FB}");
  frame1a->GetYaxis()->CenterTitle();
  frame1a->Draw();
  gPad->SetLogx();
  gr_afb_band1->SetMarkerStyle(28);
  gr_afb_band1->SetFillColor(4);
  gr_afb_band1->SetLineColor(4);
  gr_afb_band1->SetMarkerColor(4);
  gr_afb_band1->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Raw_AFB[0]->Draw("e1sames");
  gr[0]->SetMarkerStyle(8);
  gr[0]->SetLineWidth(2);
  gr[0]->Draw("P");
  r24->cd(2);

  TH2F* frame2a = new TH2F("frame2a","|Y|=1.00-1.25",100,30,400,100,-0.2,0.5);
  frame2a->GetXaxis()->SetRangeUser(40,1500);
  frame2a->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame2a->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame2a->GetYaxis()->SetTitle("A_{FB}");
  frame2a->GetYaxis()->CenterTitle();
  frame2a->Draw();
  gPad->SetLogx();
  gr_afb_band2->SetMarkerStyle(28);
  gr_afb_band2->SetFillColor(4);
  gr_afb_band2->SetLineColor(4);
  gr_afb_band2->SetMarkerColor(4);
  gr_afb_band2->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Raw_AFB[1]->Draw("e1sames");
  gr[1]->SetMarkerStyle(8);
  gr[1]->SetLineWidth(2);
  gr[1]->Draw("P");
  r24->cd(3);
  TH2F* frame3a = new TH2F("frame3a","|Y|=1.25-1.50",100,30,400,100,-0.2,0.5);
  frame3a->GetXaxis()->SetRangeUser(40,1500);
  frame3a->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame3a->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame3a->GetYaxis()->SetTitle("A_{FB}");
  frame3a->GetYaxis()->CenterTitle();
  frame3a->Draw();
  gPad->SetLogx();
  gr_afb_band3->SetMarkerStyle(28);
  gr_afb_band3->SetFillColor(4);
  gr_afb_band3->SetLineColor(4);
  gr_afb_band3->SetMarkerColor(4);
  gr_afb_band3->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Raw_AFB[2]->Draw("e1sames");
  gr[2]->SetMarkerStyle(8);
  gr[2]->SetLineWidth(2);
  gr[2]->Draw("P");
  r24->cd(4);
  TH2F* frame4a = new TH2F("frame4a","|Y|=1.50-2.40",100,30,400,100,-0.2,0.5);
  frame4a->GetXaxis()->SetRangeUser(40,1500);
  frame4a->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame4a->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame4a->GetYaxis()->SetTitle("A_{FB}");
  frame4a->GetYaxis()->CenterTitle();
  frame4a->Draw();
  gPad->SetLogx();
  gr_afb_band4->SetMarkerStyle(28);
  gr_afb_band4->SetFillColor(4);
  gr_afb_band4->SetLineColor(4);
  gr_afb_band4->SetMarkerColor(4);
  gr_afb_band4->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Raw_AFB[3]->Draw("e1sames");
  gr[3]->SetMarkerStyle(8);
  gr[3]->SetLineWidth(2);
  gr[3]->Draw("P");
  r24->SaveAs("raw_AFB_with_systematics.C");

//undet
  TGraph *gr_afb_band1_undet = new TGraph(nb*2,band_x1_UnDet,band_afb_y1_undet);
  TGraph *gr_afb_band2_undet = new TGraph(nb*2,band_x2_UnDet,band_afb_y2_undet);
  TGraph *gr_afb_band3_undet = new TGraph(nb*2,band_x3_UnDet,band_afb_y3_undet);
  TGraph *gr_afb_band4_undet = new TGraph(nb*2,band_x4_UnDet,band_afb_y4_undet);

  TCanvas *r25 = new TCanvas();
  r25->Divide(2,2);
  r25->cd(1);

  TH2F* frame1a_undet = new TH2F("frame1a_undet","|Y|=0.00-1.00",100,30,400,100,-0.2,0.5);
  frame1a_undet->GetXaxis()->SetRangeUser(40,1500);
  frame1a_undet->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame1a_undet->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame1a_undet->GetYaxis()->SetTitle("A_{FB}");
  frame1a_undet->GetYaxis()->CenterTitle();
  frame1a_undet->Draw();
  gPad->SetLogx();
  gr_afb_band1_undet->SetMarkerStyle(28);
  gr_afb_band1_undet->SetFillColor(4);
  gr_afb_band1_undet->SetLineColor(4);
  gr_afb_band1_undet->SetMarkerColor(4);
  gr_afb_band1_undet->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_UnDet_AFB[0]->Draw("e1sames");
  gr_UnDet[0]->SetMarkerStyle(8);
  gr_UnDet[0]->SetLineWidth(2);
  gr_UnDet[0]->Draw("P");
  r25->cd(2);

  TH2F* frame2a_undet = new TH2F("frame2a_undet","|Y|=1.00-1.25",100,30,400,100,-0.2,0.5);
  frame2a_undet->GetXaxis()->SetRangeUser(40,1500);
  frame2a_undet->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame2a_undet->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame2a_undet->GetYaxis()->SetTitle("A_{FB}");
  frame2a_undet->GetYaxis()->CenterTitle();
  frame2a_undet->Draw();
  gPad->SetLogx();
  gr_afb_band2_undet->SetMarkerStyle(28);
  gr_afb_band2_undet->SetFillColor(4);
  gr_afb_band2_undet->SetLineColor(4);
  gr_afb_band2_undet->SetMarkerColor(4);
  gr_afb_band2_undet->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_UnDet_AFB[1]->Draw("e1sames");
  gr_UnDet[1]->SetMarkerStyle(8);
  gr_UnDet[1]->SetLineWidth(2);
  gr_UnDet[1]->Draw("P");
  r25->cd(3);
  TH2F* frame3a_undet = new TH2F("frame3a_undet","|Y|=1.25-1.50",100,30,400,100,-0.2,0.5);
  frame3a_undet->GetXaxis()->SetRangeUser(40,1500);
  frame3a_undet->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame3a_undet->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame3a_undet->GetYaxis()->SetTitle("A_{FB}");
  frame3a_undet->GetYaxis()->CenterTitle();
  frame3a_undet->Draw();
  gPad->SetLogx();
  gr_afb_band3_undet->SetMarkerStyle(28);
  gr_afb_band3_undet->SetFillColor(4);
  gr_afb_band3_undet->SetLineColor(4);
  gr_afb_band3_undet->SetMarkerColor(4);
  gr_afb_band3_undet->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_UnDet_AFB[2]->Draw("e1sames");
  gr_UnDet[2]->SetMarkerStyle(8);
  gr_UnDet[2]->SetLineWidth(2);
  gr_UnDet[2]->Draw("P");
  r25->cd(4);
  TH2F* frame4a_undet = new TH2F("frame4a_undet","|Y|=1.50-2.10",100,30,400,100,-0.2,0.5);
  frame4a_undet->GetXaxis()->SetRangeUser(40,1500);
  frame4a_undet->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame4a_undet->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame4a_undet->GetYaxis()->SetTitle("A_{FB}");
  frame4a_undet->GetYaxis()->CenterTitle();
  frame4a_undet->Draw();
  gPad->SetLogx();
  gr_afb_band4_undet->SetMarkerStyle(28);
  gr_afb_band4_undet->SetFillColor(4);
  gr_afb_band4_undet->SetLineColor(4);
  gr_afb_band4_undet->SetMarkerColor(4);
  gr_afb_band4_undet->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");


  //  h_Unfolded_UnDet_AFB[3]->Draw("e1sames");
  gr_UnDet[3]->SetMarkerStyle(8);
  gr_UnDet[3]->SetLineWidth(2);
  gr_UnDet[3]->Draw("P");
  r25->SaveAs("Bare_Lepton_Level_AFB_with_systematics.C");
//eof undet

//nofsr
  TGraph *gr_afb_band1_nofsr = new TGraph(nb*2,band_x1_NoFsr,band_afb_y1_nofsr);
  TGraph *gr_afb_band2_nofsr = new TGraph(nb*2,band_x2_NoFsr,band_afb_y2_nofsr);
  TGraph *gr_afb_band3_nofsr = new TGraph(nb*2,band_x3_NoFsr,band_afb_y3_nofsr);
  TGraph *gr_afb_band4_nofsr = new TGraph(nb*2,band_x4_NoFsr,band_afb_y4_nofsr);

  TCanvas *r26 = new TCanvas();
  r26->Divide(2,2);
  r26->cd(1);

  TH2F* frame1a_nofsr = new TH2F("frame1a_nofsr","|Y|=0-1",100,30,400,100,-0.2,0.5);
  frame1a_nofsr->GetXaxis()->SetRangeUser(40,1500);
  frame1a_nofsr->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame1a_nofsr->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame1a_nofsr->GetYaxis()->SetTitle("A_{FB}");
  frame1a_nofsr->GetYaxis()->CenterTitle();
  frame1a_nofsr->Draw();
  gPad->SetLogx();
  gr_afb_band1_nofsr->SetMarkerStyle(28);
  gr_afb_band1_nofsr->SetFillColor(4);
  gr_afb_band1_nofsr->SetLineColor(4);
  gr_afb_band1_nofsr->SetMarkerColor(4);
  gr_afb_band1_nofsr->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_NoFsr_AFB[0]->Draw("e1sames");
  gr_NoFsr[0]->SetMarkerStyle(8);
  gr_NoFsr[0]->SetLineWidth(2);
  gr_NoFsr[0]->Draw("P");
  r26->cd(2);

  TH2F* frame2a_nofsr = new TH2F("frame2a_nofsr","|Y|=1-1.25",100,30,400,100,-0.2,0.5);
  frame2a_nofsr->GetXaxis()->SetRangeUser(40,1500);
  frame2a_nofsr->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame2a_nofsr->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame2a_nofsr->GetYaxis()->SetTitle("A_{FB}");
  frame2a_nofsr->GetYaxis()->CenterTitle();
  frame2a_nofsr->Draw();
  gPad->SetLogx();
  gr_afb_band2_nofsr->SetMarkerStyle(28);
  gr_afb_band2_nofsr->SetFillColor(4);
  gr_afb_band2_nofsr->SetLineColor(4);
  gr_afb_band2_nofsr->SetMarkerColor(4);
  gr_afb_band2_nofsr->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_NoFsr_AFB[1]->Draw("e1sames");
  gr_NoFsr[1]->SetMarkerStyle(8);
  gr_NoFsr[1]->SetLineWidth(2);
  gr_NoFsr[1]->Draw("P");
  r26->cd(3);
  TH2F* frame3a_nofsr = new TH2F("frame3a_nofsr","|Y|=1.25-1.5",100,30,400,100,-0.2,0.5);
  frame3a_nofsr->GetXaxis()->SetRangeUser(40,1500);
  frame3a_nofsr->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame3a_nofsr->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame3a_nofsr->GetYaxis()->SetTitle("A_{FB}");
  frame3a_nofsr->GetYaxis()->CenterTitle();
  frame3a_nofsr->Draw();
  gPad->SetLogx();
  gr_afb_band3_nofsr->SetMarkerStyle(28);
  gr_afb_band3_nofsr->SetFillColor(4);
  gr_afb_band3_nofsr->SetLineColor(4);
  gr_afb_band3_nofsr->SetMarkerColor(4);
  gr_afb_band3_nofsr->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_NoFsr_AFB[2]->Draw("e1sames");
  gr_NoFsr[2]->SetMarkerStyle(8);
  gr_NoFsr[2]->SetLineWidth(2);
  gr_NoFsr[2]->Draw("P");
  r26->cd(4);
  TH2F* frame4a_nofsr = new TH2F("frame4a_nofsr","|Y|=1.5-2.4",100,30,400,100,-0.2,0.5);
  frame4a_nofsr->GetXaxis()->SetRangeUser(40,1500);
  frame4a_nofsr->GetYaxis()->SetRangeUser(-0.2,0.5);
  frame4a_nofsr->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame4a_nofsr->GetYaxis()->SetTitle("A_{FB}");
  frame4a_nofsr->GetYaxis()->CenterTitle();
  frame4a_nofsr->Draw();
  gPad->SetLogx();
  gr_afb_band4_nofsr->SetMarkerStyle(28);
  gr_afb_band4_nofsr->SetFillColor(4);
  gr_afb_band4_nofsr->SetLineColor(4);
  gr_afb_band4_nofsr->SetMarkerColor(4);
  gr_afb_band4_nofsr->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_NoFsr_AFB[3]->Draw("e1sames");
  gr_NoFsr[3]->SetMarkerStyle(8);
  gr_NoFsr[3]->SetLineWidth(2);
  gr_NoFsr[3]->Draw("P");
  r26->SaveAs("Born_Level_AFB_with_systematics.C");
//eof nofsr

//comb
  TGraph *gr_afb_band1_comb = new TGraph(nb*2,band_x1_NoFsr,band_afb_y1_comb);
  TGraph *gr_afb_band2_comb = new TGraph(nb*2,band_x2_NoFsr,band_afb_y2_comb);
  TGraph *gr_afb_band3_comb = new TGraph(nb*2,band_x3_NoFsr,band_afb_y3_comb);
  TGraph *gr_afb_band4_comb = new TGraph(nb*2,band_x4_NoFsr,band_afb_y4_comb);

  TCanvas *r26c = new TCanvas();
  r26c->Divide(2,2);
  r26c->cd(1);

  TH2F* frame1a_comb = new TH2F("frame1a_comb","|Y|=0.00-1.00",100,30,400,100,-0.4,0.6);
  frame1a_comb->GetXaxis()->SetRangeUser(40,1500);
  frame1a_comb->GetYaxis()->SetRangeUser(-0.4,0.6);
  frame1a_comb->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame1a_comb->GetYaxis()->SetTitle("A_{FB}");
  frame1a_comb->GetYaxis()->CenterTitle();
  frame1a_comb->Draw();
  gPad->SetLogx();
  gr_afb_band1_comb->SetMarkerStyle(28);
  gr_afb_band1_comb->SetFillColor(2);
  gr_afb_band1_comb->SetLineColor(2);
  gr_afb_band1_comb->SetMarkerColor(4);
  gr_afb_band1_comb->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_Comb_AFB[0]->Draw("e1sames");
  gr_Comb[0]->SetMarkerStyle(8);
  gr_Comb[0]->SetLineWidth(2);
  gr_Comb[0]->Draw("P");
  TLatex *tex = new TLatex(42,0.50,"CMS Preliminary");
  tex->SetLineWidth(1);
  tex->Draw();
  tex = new TLatex(42,0.40,"2.2 fb^{-1} at #sqrt{s} = 7 TeV");
  tex->SetLineWidth(1);
  tex->Draw();


  r26c->cd(2);

  TH2F* frame2a_comb = new TH2F("frame2a_comb","|Y|=1.00-1.25",100,30,400,100,-0.4,0.6);
  frame2a_comb->GetXaxis()->SetRangeUser(40,1500);
  frame2a_comb->GetYaxis()->SetRangeUser(-0.4,0.6);
  frame2a_comb->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame2a_comb->GetYaxis()->SetTitle("A_{FB}");
  frame2a_comb->GetYaxis()->CenterTitle();
  frame2a_comb->Draw();
  gPad->SetLogx();
  gr_afb_band2_comb->SetMarkerStyle(28);
  gr_afb_band2_comb->SetFillColor(2);
  gr_afb_band2_comb->SetLineColor(2);
  gr_afb_band2_comb->SetMarkerColor(4);
  gr_afb_band2_comb->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_Comb_AFB[1]->Draw("e1sames");
  gr_Comb[1]->SetMarkerStyle(8);
  gr_Comb[1]->SetLineWidth(2);
  gr_Comb[1]->Draw("P");

  tex = new TLatex(42,0.50,"CMS Preliminary");
  tex->SetLineWidth(1);
  tex->Draw();
  tex = new TLatex(42,0.40,"2.2 fb^{-1} at #sqrt{s} = 7 TeV");
  tex->SetLineWidth(1);
  tex->Draw();

  r26c->cd(3);
  TH2F* frame3a_comb = new TH2F("frame3a_comb","|Y|=1.25-1.50",100,30,400,100,-0.4,0.6);
  frame3a_comb->GetXaxis()->SetRangeUser(40,1500);
  frame3a_comb->GetYaxis()->SetRangeUser(-0.4,0.6);
  frame3a_comb->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame3a_comb->GetYaxis()->SetTitle("A_{FB}");
  frame3a_comb->GetYaxis()->CenterTitle();
  frame3a_comb->Draw();
  gPad->SetLogx();
  gr_afb_band3_comb->SetMarkerStyle(28);
  gr_afb_band3_comb->SetFillColor(2);
  gr_afb_band3_comb->SetLineColor(2);
  gr_afb_band3_comb->SetMarkerColor(4);
  gr_afb_band3_comb->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_Comb_AFB[2]->Draw("e1sames");
  gr_Comb[2]->SetMarkerStyle(8);
  gr_Comb[2]->SetLineWidth(2);
  gr_Comb[2]->Draw("P");

  tex = new TLatex(42,0.50,"CMS Preliminary");
  tex->SetLineWidth(1);
  tex->Draw();
  tex = new TLatex(42,0.40,"2.2 fb^{-1} at #sqrt{s} = 7 TeV");
  tex->SetLineWidth(1);
  tex->Draw();

  r26c->cd(4);
  TH2F* frame4a_comb = new TH2F("frame4a_comb","|Y|=1.50-2.10",100,30,400,100,-0.4,0.6);
  frame4a_comb->GetXaxis()->SetRangeUser(40,1500);
  frame4a_comb->GetYaxis()->SetRangeUser(-0.4,0.6);
  frame4a_comb->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
  frame4a_comb->GetYaxis()->SetTitle("A_{FB}");
  frame4a_comb->GetYaxis()->CenterTitle();
  frame4a_comb->Draw();
  gPad->SetLogx();
  gr_afb_band4_comb->SetMarkerStyle(28);
  gr_afb_band4_comb->SetFillColor(2);
  gr_afb_band4_comb->SetLineColor(2);
  gr_afb_band4_comb->SetMarkerColor(4);
  gr_afb_band4_comb->Draw("F");
  //  h_MC_Raw_AFB[0]->SetMarkerStyle(20);
  //  h_MC_Raw_AFB[0]->Draw("sames");

  //  h_Unfolded_NoFsr_AFB[3]->Draw("e1sames");
  gr_Comb[3]->SetMarkerStyle(8);
  gr_Comb[3]->SetLineWidth(2);
  gr_Comb[3]->Draw("P");
  tex = new TLatex(42,0.50,"CMS Preliminary");
  tex->SetLineWidth(1);
  tex->Draw();
  tex = new TLatex(42,0.40,"2.2 fb^{-1} at #sqrt{s} = 7 TeV");
  tex->SetLineWidth(1);
  tex->Draw();

  r26c->SaveAs("Born_Level_Comb_AFB_with_mu_systematics.C");
//eof comb



  TCanvas *c27 = new TCanvas();
  c27->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c27->cd(k+1);
    gPad->SetLogx();  
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_Ideal_Geo_AFB[k]->SetTitle(name_h);
    h_Ideal_Geo_AFB[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Ideal_Geo_AFB[k]->GetYaxis()->SetTitle("A_{FB}");
    h_Ideal_Geo_AFB[k]->SetMarkerStyle(8);
    h_Ideal_Geo_AFB[k]->SetLineWidth(2);
    h_Ideal_Geo_AFB[k]->Draw("e1");

    h_CurlV2TF_AFB[k]->SetLineColor(4);
    h_CurlV2TF_AFB[k]->SetMarkerColor(4);
    h_CurlV2TF_AFB[k]->Draw("e1sames");

  }
  c27->SaveAs("IDEAL_and_CURL_afb_raw.C");

  TCanvas *c28 = new TCanvas();
  c28->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c28->cd(k+1);

    h_Ideal_Geo_AFB_FineBin[k]->SetLineWidth(2);
    h_Ideal_Geo_AFB_FineBin[k]->SetLineColor(4);
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_Ideal_Geo_AFB_FineBin[k]->SetTitle(name_h);
    h_Ideal_Geo_AFB_FineBin[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Ideal_Geo_AFB_FineBin[k]->GetYaxis()->SetTitle("A_{FB}");
    h_Ideal_Geo_AFB_FineBin[k]->Draw("e1");
    h_Raw_AFB_FineBin[k]->SetMarkerStyle(8);
    h_Raw_AFB_FineBin[k]->SetLineWidth(2);
    h_Raw_AFB_FineBin[k]->Draw("e1sames");

  }
  c28->SaveAs("afb_raw_FINEBIN.C");

  
  TCanvas *c29 = new TCanvas();
  c29->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c29->cd(k+1);
    gPad->SetLogx();
    h_MC_Raw_alignment_total_plus[k]->SetLineWidth(2);
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Raw_alignment_total_plus[k]->GetYaxis()->SetRangeUser(-0.18,0.18);
    h_MC_Raw_alignment_total_plus[k]->SetTitle(name_h);
    h_MC_Raw_alignment_total_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_MC_Raw_alignment_total_plus[k]->GetYaxis()->SetTitle("#Delta");
    h_MC_Raw_alignment_total_plus[k]->Draw();
    //    h_MC_Raw_alignment_total_minus[k]->SetFillColor(1);
    h_MC_Raw_alignment_total_minus[k]->SetLineWidth(2);
    h_MC_Raw_alignment_total_minus[k]->Draw("sames");

    h_MC_Bare_alignment_total_plus[k]->SetLineWidth(2);
    h_MC_Bare_alignment_total_plus[k]->SetLineColor(2);
    h_MC_Bare_alignment_total_plus[k]->Draw("sames");
    h_MC_Bare_alignment_total_minus[k]->SetLineWidth(2);
    h_MC_Bare_alignment_total_minus[k]->SetLineColor(2);
    h_MC_Bare_alignment_total_minus[k]->Draw("sames");

    h_MC_Born_alignment_total_plus[k]->SetLineWidth(2);
    h_MC_Born_alignment_total_plus[k]->SetLineColor(4);
    h_MC_Born_alignment_total_plus[k]->Draw("sames");
    h_MC_Born_alignment_total_minus[k]->SetLineWidth(2);
    h_MC_Born_alignment_total_minus[k]->SetLineColor(4);
    h_MC_Born_alignment_total_minus[k]->Draw("sames");

  }
  c29->SaveAs("total_misalignment_syst_at_each_stage.C");


  TCanvas *c30 = new TCanvas();
  c30->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c30->cd(k+1);
    gPad->SetLogx();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_Systematics_fsr_raw_plus[k]->GetYaxis()->SetRangeUser(-0.18,0.18);
    h_Systematics_fsr_raw_plus[k]->SetMarkerStyle(20);
    h_Systematics_fsr_raw_plus[k]->SetLineColor(2);
    h_Systematics_fsr_raw_plus[k]->SetMarkerColor(2);
    h_Systematics_fsr_raw_plus[k]->SetLineWidth(2);
    h_Systematics_fsr_raw_plus[k]->SetTitle(name_h);
    h_Systematics_fsr_raw_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Systematics_fsr_raw_plus[k]->GetYaxis()->SetTitle("#Delta");
    h_Systematics_fsr_raw_plus[k]->Draw("e1");
    h_Systematics_fsr_raw_minus[k]->SetLineColor(2);
    h_Systematics_fsr_raw_minus[k]->SetMarkerColor(2);
    h_Systematics_fsr_raw_minus[k]->SetMarkerStyle(20);
    h_Systematics_fsr_raw_minus[k]->SetLineWidth(2);
    h_Systematics_fsr_raw_minus[k]->Draw("e1sames");
    
    h_Systematics_es_raw_plus[k]->SetMarkerStyle(26);
    h_Systematics_es_raw_plus[k]->SetLineColor(kRed+4);
    h_Systematics_es_raw_plus[k]->SetMarkerColor(kRed+4);
    h_Systematics_es_raw_plus[k]->SetLineWidth(2);
    h_Systematics_es_raw_plus[k]->SetTitle(name_h);
    h_Systematics_es_raw_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Systematics_es_raw_plus[k]->GetYaxis()->SetTitle("#Delta");
    h_Systematics_es_raw_plus[k]->Draw("e1sames");
    h_Systematics_es_raw_minus[k]->SetLineColor(kRed+4);
    h_Systematics_es_raw_minus[k]->SetMarkerColor(kRed+4);
    h_Systematics_es_raw_minus[k]->SetMarkerStyle(26);
    h_Systematics_es_raw_minus[k]->SetLineWidth(2);
    h_Systematics_es_raw_minus[k]->Draw("e1sames");

    h_Systematics_noweight_raw_plus[k]->SetMarkerStyle(27);
    h_Systematics_noweight_raw_plus[k]->SetLineColor(kRed-6);
    h_Systematics_noweight_raw_plus[k]->SetMarkerColor(kRed-6);
    h_Systematics_noweight_raw_plus[k]->SetLineWidth(2);
    h_Systematics_noweight_raw_plus[k]->SetTitle(name_h);
    h_Systematics_noweight_raw_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Systematics_noweight_raw_plus[k]->GetYaxis()->SetTitle("#Delta");
    h_Systematics_noweight_raw_plus[k]->Draw("e1sames");
    h_Systematics_noweight_raw_minus[k]->SetLineColor(kRed-6);
    h_Systematics_noweight_raw_minus[k]->SetMarkerColor(kRed-6);
    h_Systematics_noweight_raw_minus[k]->SetMarkerStyle(27);
    h_Systematics_noweight_raw_minus[k]->SetLineWidth(2);
    h_Systematics_noweight_raw_minus[k]->Draw("e1sames");

    h_Systematics_bkg_raw_plus[k]->SetLineWidth(2);
    h_Systematics_bkg_raw_plus[k]->SetMarkerStyle(21);
    h_Systematics_bkg_raw_plus[k]->SetLineColor(4);
    h_Systematics_bkg_raw_plus[k]->SetMarkerColor(4);
    h_Systematics_bkg_raw_plus[k]->Draw("e1sames");
    h_Systematics_bkg_raw_minus[k]->SetLineWidth(2);
    h_Systematics_bkg_raw_minus[k]->SetLineColor(4);
    h_Systematics_bkg_raw_minus[k]->SetMarkerColor(4);
    h_Systematics_bkg_raw_minus[k]->SetMarkerStyle(21);
    h_Systematics_bkg_raw_minus[k]->Draw("e1sames");
    /*
    h_Systematics_sin_raw_plus[k]->SetLineWidth(2);
    h_Systematics_sin_raw_plus[k]->SetMarkerStyle(22);
    h_Systematics_sin_raw_plus[k]->SetLineColor(kYellow+3);
    h_Systematics_sin_raw_plus[k]->SetMarkerColor(kYellow+3);
    h_Systematics_sin_raw_plus[k]->Draw("e1sames");
    h_Systematics_sin_raw_minus[k]->SetLineWidth(2);
    h_Systematics_sin_raw_minus[k]->SetMarkerStyle(22);
    h_Systematics_sin_raw_minus[k]->SetLineColor(kYellow+3);
    h_Systematics_sin_raw_minus[k]->SetMarkerColor(kYellow+3);
    h_Systematics_sin_raw_minus[k]->Draw("e1sames");
    */
    h_MC_Raw_alignment_total_plus[k]->SetLineWidth(2);
    h_MC_Raw_alignment_total_plus[k]->SetMarkerStyle(23);
    h_MC_Raw_alignment_total_plus[k]->SetLineColor(kGreen+2);
    h_MC_Raw_alignment_total_plus[k]->SetMarkerColor(kGreen+2);
    h_MC_Raw_alignment_total_plus[k]->Draw("e1sames");
    h_MC_Raw_alignment_total_minus[k]->SetLineWidth(2);
    h_MC_Raw_alignment_total_minus[k]->SetMarkerStyle(23);
    h_MC_Raw_alignment_total_minus[k]->SetMarkerColor(kGreen+2);
    h_MC_Raw_alignment_total_minus[k]->SetLineColor(kGreen+2);
    h_MC_Raw_alignment_total_minus[k]->Draw("e1sames");

    h_envelope_sigma_plus[k]->SetMarkerStyle(24);
    h_envelope_sigma_plus[k]->SetLineWidth(2);
    h_envelope_sigma_plus[k]->SetLineColor(6);
    h_envelope_sigma_plus[k]->SetMarkerColor(6);
    h_envelope_sigma_plus[k]->Draw("e1sames");
    h_envelope_sigma_minus[k]->SetMarkerStyle(24);
    h_envelope_sigma_minus[k]->SetLineWidth(2);
    h_envelope_sigma_minus[k]->SetLineColor(6);
    h_envelope_sigma_minus[k]->SetMarkerColor(6);
    h_envelope_sigma_minus[k]->Draw("e1sames");

    h_total_plus[k]->SetLineWidth(2);
    h_total_plus[k]->SetLineColor(1);
    h_total_plus[k]->SetMarkerColor(1);
    h_total_plus[k]->SetMarkerStyle(25);
    h_total_plus[k]->Draw("e1sames");
    h_total_minus[k]->SetLineWidth(2);
    h_total_minus[k]->SetLineColor(1);
    h_total_minus[k]->SetLineStyle(1);
    h_total_minus[k]->SetMarkerColor(1);
    h_total_minus[k]->SetMarkerStyle(25);
    h_total_minus[k]->Draw("e1sames");
  }
  c30->SaveAs("systematic_uncertainties_RAW_on_top_of_each_other.C");


  TCanvas *c31 = new TCanvas();
  c31->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c31->cd(k+1);
    gPad->SetLogx();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_Systematics_fsr_bare_plus[k]->GetYaxis()->SetRangeUser(-0.18,0.18);
    h_Systematics_fsr_bare_plus[k]->SetMarkerStyle(20);
    h_Systematics_fsr_bare_plus[k]->SetLineColor(2);
    h_Systematics_fsr_bare_plus[k]->SetMarkerColor(2);
    h_Systematics_fsr_bare_plus[k]->SetLineWidth(2);
    h_Systematics_fsr_bare_plus[k]->SetTitle(name_h);
    h_Systematics_fsr_bare_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Systematics_fsr_bare_plus[k]->GetYaxis()->SetTitle("#Delta");
    h_Systematics_fsr_bare_plus[k]->Draw("e1");
    h_Systematics_fsr_bare_minus[k]->SetLineColor(2);
    h_Systematics_fsr_bare_minus[k]->SetMarkerColor(2);
    h_Systematics_fsr_bare_minus[k]->SetMarkerStyle(20);
    h_Systematics_fsr_bare_minus[k]->SetLineWidth(2);
    h_Systematics_fsr_bare_minus[k]->Draw("e1sames");


    h_Systematics_es_bare_plus[k]->SetMarkerStyle(26);
    h_Systematics_es_bare_plus[k]->SetLineColor(kRed+4);
    h_Systematics_es_bare_plus[k]->SetMarkerColor(kRed+4);
    h_Systematics_es_bare_plus[k]->SetLineWidth(2);
    h_Systematics_es_bare_plus[k]->SetTitle(name_h);
    h_Systematics_es_bare_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Systematics_es_bare_plus[k]->GetYaxis()->SetTitle("#Delta");
    h_Systematics_es_bare_plus[k]->Draw("e1sames");
    h_Systematics_es_bare_minus[k]->SetLineColor(kRed+4);
    h_Systematics_es_bare_minus[k]->SetMarkerColor(kRed+4);
    h_Systematics_es_bare_minus[k]->SetMarkerStyle(26);
    h_Systematics_es_bare_minus[k]->SetLineWidth(2);
    h_Systematics_es_bare_minus[k]->Draw("e1sames");

    h_Systematics_noweight_bare_plus[k]->SetMarkerStyle(27);
    h_Systematics_noweight_bare_plus[k]->SetLineColor(kRed-6);
    h_Systematics_noweight_bare_plus[k]->SetMarkerColor(kRed-6);
    h_Systematics_noweight_bare_plus[k]->SetLineWidth(2);
    h_Systematics_noweight_bare_plus[k]->SetTitle(name_h);
    h_Systematics_noweight_bare_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Systematics_noweight_bare_plus[k]->GetYaxis()->SetTitle("#Delta");
    h_Systematics_noweight_bare_plus[k]->Draw("e1sames");
    h_Systematics_noweight_bare_minus[k]->SetLineColor(kRed-6);
    h_Systematics_noweight_bare_minus[k]->SetMarkerColor(kRed-6);
    h_Systematics_noweight_bare_minus[k]->SetMarkerStyle(27);
    h_Systematics_noweight_bare_minus[k]->SetLineWidth(2);
    h_Systematics_noweight_bare_minus[k]->Draw("e1sames");

    h_Systematics_bkg_bare_plus[k]->SetLineWidth(2);
    h_Systematics_bkg_bare_plus[k]->SetMarkerStyle(21);
    h_Systematics_bkg_bare_plus[k]->SetLineColor(4);
    h_Systematics_bkg_bare_plus[k]->SetMarkerColor(4);
    h_Systematics_bkg_bare_plus[k]->Draw("e1sames");
    h_Systematics_bkg_bare_minus[k]->SetLineWidth(2);
    h_Systematics_bkg_bare_minus[k]->SetLineColor(4);
    h_Systematics_bkg_bare_minus[k]->SetMarkerColor(4);
    h_Systematics_bkg_bare_minus[k]->SetMarkerStyle(21);
    h_Systematics_bkg_bare_minus[k]->Draw("e1sames");
    /*
    h_Systematics_sin_bare_plus[k]->SetLineWidth(2);
    h_Systematics_sin_bare_plus[k]->SetMarkerStyle(22);
    h_Systematics_sin_bare_plus[k]->SetLineColor(kYellow+3);
    h_Systematics_sin_bare_plus[k]->SetMarkerColor(kYellow+3);
    h_Systematics_sin_bare_plus[k]->Draw("e1sames");
    h_Systematics_sin_bare_minus[k]->SetLineWidth(2);
    h_Systematics_sin_bare_minus[k]->SetMarkerStyle(22);
    h_Systematics_sin_bare_minus[k]->SetLineColor(kYellow+3);
    h_Systematics_sin_bare_minus[k]->SetMarkerColor(kYellow+3);
    h_Systematics_sin_bare_minus[k]->Draw("e1sames");
    */
    h_MC_Bare_alignment_total_plus[k]->SetLineWidth(2);
    h_MC_Bare_alignment_total_plus[k]->SetMarkerStyle(23);
    h_MC_Bare_alignment_total_plus[k]->SetLineColor(kGreen+2);
    h_MC_Bare_alignment_total_plus[k]->SetMarkerColor(kGreen+2);
    h_MC_Bare_alignment_total_plus[k]->Draw("e1sames");
    h_MC_Bare_alignment_total_minus[k]->SetLineWidth(2);
    h_MC_Bare_alignment_total_minus[k]->SetMarkerStyle(23);
    h_MC_Bare_alignment_total_minus[k]->SetMarkerColor(kGreen+2);
    h_MC_Bare_alignment_total_minus[k]->SetLineColor(kGreen+2);
    h_MC_Bare_alignment_total_minus[k]->Draw("e1sames");

    h_envelope_sigma_plus[k]->SetMarkerStyle(24);
    h_envelope_sigma_plus[k]->SetLineWidth(2);
    h_envelope_sigma_plus[k]->SetLineColor(6);
    h_envelope_sigma_plus[k]->SetMarkerColor(6);
    h_envelope_sigma_plus[k]->Draw("e1sames");
    h_envelope_sigma_minus[k]->SetMarkerStyle(24);
    h_envelope_sigma_minus[k]->SetLineWidth(2);
    h_envelope_sigma_minus[k]->SetLineColor(6);
    h_envelope_sigma_minus[k]->SetMarkerColor(6);
    h_envelope_sigma_minus[k]->Draw("e1sames");

    h_total_plus_undet[k]->SetLineWidth(2);
    h_total_plus_undet[k]->SetLineStyle(1);
    h_total_plus_undet[k]->SetLineColor(1);
    h_total_plus_undet[k]->SetMarkerStyle(25);
    h_total_plus_undet[k]->Draw("sames");
    h_total_minus_undet[k]->SetLineWidth(2);
    h_total_minus_undet[k]->SetLineStyle(1);
    h_total_minus_undet[k]->SetLineColor(1);
    h_total_minus_undet[k]->SetMarkerStyle(25);
    h_total_minus_undet[k]->Draw("sames");
  }
  c31->SaveAs("systematic_uncertainties_BARE_LEPTON_on_top_of_each_other.C");

   TCanvas *c32 = new TCanvas();
  c32->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c32->cd(k+1);
    gPad->SetLogx();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_Systematics_fsr_Born_plus[k]->GetYaxis()->SetRangeUser(-0.18,0.18);
    h_Systematics_fsr_Born_plus[k]->SetMarkerStyle(20);
    h_Systematics_fsr_Born_plus[k]->SetLineColor(2);
    h_Systematics_fsr_Born_plus[k]->SetMarkerColor(2);
    h_Systematics_fsr_Born_plus[k]->SetLineWidth(2);
    h_Systematics_fsr_Born_plus[k]->SetTitle(name_h);
    h_Systematics_fsr_Born_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Systematics_fsr_Born_plus[k]->GetYaxis()->SetTitle("#Delta");
    h_Systematics_fsr_Born_plus[k]->Draw("e1");
    h_Systematics_fsr_Born_minus[k]->SetLineColor(2);
    h_Systematics_fsr_Born_minus[k]->SetMarkerColor(2);
    h_Systematics_fsr_Born_minus[k]->SetMarkerStyle(20);
    h_Systematics_fsr_Born_minus[k]->SetLineWidth(2);
    h_Systematics_fsr_Born_minus[k]->Draw("e1sames");
   
    h_Systematics_es_Born_plus[k]->GetYaxis()->SetRangeUser(-0.18,0.18);
    h_Systematics_es_Born_plus[k]->SetMarkerStyle(26);
    h_Systematics_es_Born_plus[k]->SetLineColor(kRed+4);
    h_Systematics_es_Born_plus[k]->SetMarkerColor(kRed+4);
    h_Systematics_es_Born_plus[k]->SetLineWidth(2);
    h_Systematics_es_Born_plus[k]->SetTitle(name_h);
    h_Systematics_es_Born_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Systematics_es_Born_plus[k]->GetYaxis()->SetTitle("#Delta");
    h_Systematics_es_Born_plus[k]->Draw("e1sames");
    h_Systematics_es_Born_minus[k]->SetLineColor(kRed+4);
    h_Systematics_es_Born_minus[k]->SetMarkerColor(kRed+4);
    h_Systematics_es_Born_minus[k]->SetMarkerStyle(26);
    h_Systematics_es_Born_minus[k]->SetLineWidth(2);
    h_Systematics_es_Born_minus[k]->Draw("e1sames");

    h_Systematics_noweight_Born_plus[k]->GetYaxis()->SetRangeUser(-0.18,0.18);
    h_Systematics_noweight_Born_plus[k]->SetMarkerStyle(27);
    h_Systematics_noweight_Born_plus[k]->SetLineColor(kRed-6);
    h_Systematics_noweight_Born_plus[k]->SetMarkerColor(kRed-6);
    h_Systematics_noweight_Born_plus[k]->SetLineWidth(2);
    h_Systematics_noweight_Born_plus[k]->SetTitle(name_h);
    h_Systematics_noweight_Born_plus[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_Systematics_noweight_Born_plus[k]->GetYaxis()->SetTitle("#Delta");
    h_Systematics_noweight_Born_plus[k]->Draw("e1sames");
    h_Systematics_noweight_Born_minus[k]->SetLineColor(kRed-6);
    h_Systematics_noweight_Born_minus[k]->SetMarkerColor(kRed-6);
    h_Systematics_noweight_Born_minus[k]->SetMarkerStyle(27);
    h_Systematics_noweight_Born_minus[k]->SetLineWidth(2);
    h_Systematics_noweight_Born_minus[k]->Draw("e1sames");
 
    h_Systematics_bkg_Born_plus[k]->SetLineWidth(2);
    h_Systematics_bkg_Born_plus[k]->SetMarkerStyle(21);
    h_Systematics_bkg_Born_plus[k]->SetLineColor(4);
    h_Systematics_bkg_Born_plus[k]->SetMarkerColor(4);
    h_Systematics_bkg_Born_plus[k]->Draw("e1sames");
    h_Systematics_bkg_Born_minus[k]->SetLineWidth(2);
    h_Systematics_bkg_Born_minus[k]->SetLineColor(4);
    h_Systematics_bkg_Born_minus[k]->SetMarkerColor(4);
    h_Systematics_bkg_Born_minus[k]->SetMarkerStyle(21);
    h_Systematics_bkg_Born_minus[k]->Draw("e1sames");
    /*
    h_Systematics_sin_Born_plus[k]->SetLineWidth(2);
    h_Systematics_sin_Born_plus[k]->SetMarkerStyle(22);
    h_Systematics_sin_Born_plus[k]->SetLineColor(kYellow+3);
    h_Systematics_sin_Born_plus[k]->SetMarkerColor(kYellow+3);
    h_Systematics_sin_Born_plus[k]->Draw("e1sames");
    h_Systematics_sin_Born_minus[k]->SetLineWidth(2);
    h_Systematics_sin_Born_minus[k]->SetMarkerStyle(22);
    h_Systematics_sin_Born_minus[k]->SetLineColor(kYellow+3);
    h_Systematics_sin_Born_minus[k]->SetMarkerColor(kYellow+3);
    h_Systematics_sin_Born_minus[k]->Draw("e1sames");
    */
    h_MC_Born_alignment_total_plus[k]->SetLineWidth(2);
    h_MC_Born_alignment_total_plus[k]->SetMarkerStyle(23);
    h_MC_Born_alignment_total_plus[k]->SetLineColor(kGreen+2);
    h_MC_Born_alignment_total_plus[k]->SetMarkerColor(kGreen+2);
    h_MC_Born_alignment_total_plus[k]->Draw("e1sames");
    h_MC_Born_alignment_total_minus[k]->SetLineWidth(2);
    h_MC_Born_alignment_total_minus[k]->SetMarkerStyle(23);
    h_MC_Born_alignment_total_minus[k]->SetMarkerColor(kGreen+2);
    h_MC_Born_alignment_total_minus[k]->SetLineColor(kGreen+2);
    h_MC_Born_alignment_total_minus[k]->Draw("e1sames");

    h_envelope_sigma_plus[k]->SetMarkerStyle(24);
    h_envelope_sigma_plus[k]->SetLineWidth(2);
    h_envelope_sigma_plus[k]->SetLineColor(6);
    h_envelope_sigma_plus[k]->SetMarkerColor(6);
    h_envelope_sigma_plus[k]->Draw("e1sames");
    h_envelope_sigma_minus[k]->SetMarkerStyle(24);
    h_envelope_sigma_minus[k]->SetLineWidth(2);
    h_envelope_sigma_minus[k]->SetLineColor(6);
    h_envelope_sigma_minus[k]->SetMarkerColor(6);
    h_envelope_sigma_minus[k]->Draw("e1sames");

    h_total_plus_nofsr[k]->SetLineWidth(2);
    h_total_plus_nofsr[k]->SetLineStyle(1);
    h_total_plus_nofsr[k]->SetLineColor(1);
    h_total_plus_nofsr[k]->SetMarkerStyle(25);
    h_total_plus_nofsr[k]->Draw("sames");
    h_total_minus_nofsr[k]->SetLineWidth(2);
    h_total_minus_nofsr[k]->SetLineStyle(1);
    h_total_minus_nofsr[k]->SetLineColor(1);
    h_total_minus_nofsr[k]->SetMarkerStyle(25);
    h_total_minus_nofsr[k]->Draw("sames");
  }
  c32->SaveAs("systematic_uncertainties_BORN_on_top_of_each_other.C");


  TCanvas *c33 = new TCanvas();
  c33->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c33->cd(k+1);
    gPad->SetLogx();  
    h_MC_True_AFB[k]->GetYaxis()->SetRangeUser(-1,1);
    h_MC_True_AFB[k]->SetLineWidth(2);
    h_MC_True_AFB[k]->SetLineColor(4);
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_True_AFB[k]->SetTitle(name_h);
    h_MC_True_AFB[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    h_MC_True_AFB[k]->GetYaxis()->SetTitle("A_{FB}");
    h_MC_True_AFB[k]->Draw();

    gr_Parton[k]->SetMarkerStyle(8);
    gr_Parton[k]->SetLineWidth(2);
    gr_Parton[k]->Draw("p");

  }
  c33->SaveAs("afb_parton.C");


  TCanvas *c34 = new TCanvas();
  c34->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c34->cd(k+1);
    gPad->SetLogx();
    h_MC_Raw_AFB_ES_Diff_Up[k]->SetLineWidth(2);
    h_MC_Raw_AFB_ES_Diff_Up[k]->SetLineColor(4);
    h_MC_Raw_AFB_ES_Diff_Up[k]->GetYaxis()->SetRangeUser(-0.002,0.002);
    h_MC_Raw_AFB_ES_Diff_Up[k]->GetYaxis()->SetTitle("A_{FB}(raw)-A_{FB}(ES Scaled)");
    h_MC_Raw_AFB_ES_Diff_Up[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Raw_AFB_ES_Diff_Up[k]->SetTitle(name_h);
    h_MC_Raw_AFB_ES_Diff_Up[k]->Draw();
    h_MC_Raw_AFB_ES_Diff_Down[k]->SetLineWidth(2);
    h_MC_Raw_AFB_ES_Diff_Down[k]->SetLineColor(2);
    h_MC_Raw_AFB_ES_Diff_Down[k]->Draw("sames");
  }
  c34->SaveAs("es_uncertainty_at_raw.C");

  TCanvas *c35 = new TCanvas();
  c35->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c35->cd(k+1);
    gPad->SetLogx();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_UnDet_AFB_ES_Diff_Up[k]->SetLineWidth(2);
    h_MC_UnDet_AFB_ES_Diff_Up[k]->SetLineColor(4);
    h_MC_UnDet_AFB_ES_Diff_Up[k]->GetYaxis()->SetRangeUser(-0.002,0.002);
    h_MC_UnDet_AFB_ES_Diff_Up[k]->GetYaxis()->SetTitle("A_{FB}(raw)-A_{FB}(ES Scaled)");
    h_MC_UnDet_AFB_ES_Diff_Up[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_UnDet_AFB_ES_Diff_Up[k]->SetTitle(name_h);
    h_MC_UnDet_AFB_ES_Diff_Up[k]->Draw();
    h_MC_UnDet_AFB_ES_Diff_Down[k]->SetLineWidth(2);
    h_MC_UnDet_AFB_ES_Diff_Down[k]->SetLineColor(2);
    h_MC_UnDet_AFB_ES_Diff_Down[k]->Draw("sames");
  }
  c35->SaveAs("es_uncertainty_at_bare_lepton.C");

  TCanvas *c36 = new TCanvas();
  c36->Divide(2,2);
  for (int k=0;k<nb_Y;k++){
    c36->cd(k+1);
    gPad->SetLogx();
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[k]->SetLineColor(4);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[k]->GetYaxis()->SetRangeUser(-0.002,0.002);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[k]->GetYaxis()->SetTitle("A_{FB}(Born)-A_{FB}(FSR Scaled)");
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[k]->GetXaxis()->SetTitle("M(#mu^{+}#mu^{-}) [GeV]");
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[k],Y_bin_limits[k+1]);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[k]->SetTitle(name_h);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Up[k]->Draw();
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Down[k]->SetLineWidth(2);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Down[k]->SetLineColor(2);
    h_MC_Unfolded_NoFsr_AFB_ES_Diff_Down[k]->Draw("sames");
  }
  c36->SaveAs("es_uncertainty_at_born_level.C");

  TCanvas *c37 = new TCanvas();
  c37->Divide(2,2);
  c37->cd(1);
  h_RFF__1->Draw("colz");
  c37->cd(2);
  h_RFF__2->Draw("colz");
  c37->cd(3);
  h_RFF__3->Draw("colz");
  c37->cd(4);
  h_RFF__4->Draw("colz");
  c37->SaveAs("rff_inv_ee.C");

  TCanvas *c38 = new TCanvas();
  c38->Divide(2,2);
  c38->cd(1);
  gPad->SetLogy();
  gPad->SetLogx();
  h_RBB__1->GetXaxis()->SetTitle("Backward Reco M(e^{+}e^{-}) [GeV]");
  h_RBB__1->GetYaxis()->SetTitle("Backward Gen M(e^{+}e^{-}) [GeV]");
  h_RBB__1->Draw("colz");
  c38->cd(2);
  gPad->SetLogy();
  gPad->SetLogx();
  h_RBB__2->GetXaxis()->SetTitle("Backward Reco M(e^{+}e^{-}) [GeV]");
  h_RBB__2->GetYaxis()->SetTitle("Backward Gen M(e^{+}e^{-}) [GeV]");  
  h_RBB__2->Draw("colz");
  c38->cd(3);
  gPad->SetLogy();
  gPad->SetLogx();
  h_RBB__3->GetXaxis()->SetTitle("Backward Reco M(e^{+}e^{-}) [GeV]");
  h_RBB__3->GetYaxis()->SetTitle("Backward Gen M(e^{+}e^{-}) [GeV]");
  h_RBB__3->Draw("colz");
  c38->cd(4);
  gPad->SetLogy();
  gPad->SetLogx();
  h_RBB__4->GetXaxis()->SetTitle("Backward Reco M(e^{+}e^{-}) [GeV]");
  h_RBB__4->GetYaxis()->SetTitle("Backward Gen M(e^{+}e^{-}) [GeV]");
  h_RBB__4->Draw("colz");
  c38->SaveAs("rbb_inv_ee.C");


  TCanvas *c39 = new TCanvas();
  c39->Divide(2,2);
  for (int j=0;j<nb_Y;j++){
    c39->cd(j+1);
    gPad->SetLogx();
    gPad->SetLogy();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[j],Y_bin_limits[j+1]);
    Inv_Response_NoFsr_Forward[j]->SetTitle(name_h);
    Inv_Response_NoFsr_Forward[j]->GetXaxis()->SetTitle("Forward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Inv_Response_NoFsr_Forward[j]->GetYaxis()->SetTitle("Forward Gen M(#mu^{+}#mu^{-}) [GeV]");
    Inv_Response_NoFsr_Forward[j]->Draw("colz");
  }
  c39->SaveAs("rff_inv_mumu.C");

  TCanvas *c40 = new TCanvas();
  c40->Divide(2,2);
  for (int j=0;j<nb_Y;j++){
    c40->cd(j+1);
    gPad->SetLogx();
    gPad->SetLogy();
    sprintf(name_h,"|Y|=%.2f-%.2f",Y_bin_limits[j],Y_bin_limits[j+1]);
    Inv_Response_NoFsr_Backward[j]->SetTitle(name_h);
    Inv_Response_NoFsr_Backward[j]->GetXaxis()->SetTitle("Backward Reco M(#mu^{+}#mu^{-}) [GeV]");
    Inv_Response_NoFsr_Backward[j]->GetYaxis()->SetTitle("Backward Gen M(#mu^{+}#mu^{-}) [GeV]");
    Inv_Response_NoFsr_Backward[j]->Draw("colz");
  }
  c40->SaveAs("rbb_inv_mumu.C");

//eof parton

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


