#include <TSystem.h>
#include <TH2.h>
#include <TTree.h>
#include <TFile.h>
#include <TSystemFile.h>
#include <TSystemDirectory.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLegend.h>
#include <TPad.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <TAttLine.h>
#include <TLine.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


const int n_bins = 10; 

void prepare_bdt_cut()
{
  
  cout <<"start"<< endl;

  TH1 *DL1r_bin_jet_2_no_cut = new TH1F("", "DL1r Bin 3rd Jet BDT", 5, 1, 6);

  TH1 *DL1r_bin_3rd_jet = new TH1F("", "DL1r Bin 3rd Jet BDT Cut at 0", 5, 1 , 6);
  TH1 *DL1r_templ_BDT_ttl = new TH1F("", "DL1r_templ_BDT_ttl", 5, 1, 6);
  TH1 *DL1r_templ_BDT_ttb = new TH1F("", "DL1r_templ_BDT_ttb", 5, 1, 6);
  //TH1 *DL1r_templ_BDT_ttbb = new TH1F("", "DL1r_templ_BDT_ttl", 5, 1, 6);
  TH1 *DL1r_templ_BDT_ttc = new TH1F("", "DL1r_templ_BDT_ttc", 5, 1, 6);
  
  TH1 *BDT_ttl = new TH1F("", "BDT_ttl", 50, -1, 1);
  TH1 *BDT_ttc = new TH1F("", "BDT_ttc", 50, -1, 1);
  TH1 *BDT_ttb = new TH1F("", "BDT_ttb", 50, -1, 1);

  TH1* DL1r_bin_jet_pt_2 = new TH1F("", "DL1r_bin_jet_pt_2",5 , 1, 6);
  TH1* DL1r_bin_jet_pt_2_no_cut = new TH1F("", "DL1r_bin_jet_pt_2_no_cut",20 , 0, 1200000);
  TH1* DL1r_bin_jet_pt_2_cut = new TH1F("", "DL1r_bin_jet_pt_2_cut",20 , 0, 1200000);

  TH1 *DL1r_templ_BDT_ttl_no_cut = new TH1F("", "DL1r_templ_BDT_ttl_no_cut", 5, 1, 6);
  TH1 *DL1r_templ_BDT_ttb_no_cut = new TH1F("", "DL1r_templ_BDT_ttb_no_cut", 5, 1, 6);
  //TH1 *DL1r_templ_BDT_ttbb = new TH1F("", "DL1r_templ_BDT_ttl", 5, 1, 6);
  TH1 *DL1r_templ_BDT_ttc_no_cut = new TH1F("", "DL1r_templ_BDT_ttc_no_cut", 5, 1, 6);

  TH1 *DL1r_jet_pt_ttl_templ[n_bins];
  TH1 *DL1r_jet_pt_ttb_templ[n_bins];
  TH1 *DL1r_jet_pt_ttc_templ[n_bins];
  for(int i = 0; i<n_bins; i++){
    TString N = to_string(i);
    DL1r_jet_pt_ttl_templ[i] = new TH1F("DL1r_jet_pt_ttl_templ"+N, "DL1r_jet_pt_ttl_templ"+N, 5, 1, 6);
    DL1r_jet_pt_ttb_templ[i] = new TH1F("DL1r_jet_pt_ttb_templ"+N, "DL1r_jet_pt_ttb_templ"+N, 5, 1, 6);
    DL1r_jet_pt_ttc_templ[i] = new TH1F("DL1r_jet_pt_ttc_templ"+N, "DL1r_jet_pt_ttc_templ"+N, 5, 1, 6);}

  TH1 *DL1r_jet_pt_ttl_templ_cut[n_bins];
  TH1 *DL1r_jet_pt_ttb_templ_cut[n_bins];
  TH1 *DL1r_jet_pt_ttc_templ_cut[n_bins];
  for(int i = 0; i<n_bins; i++){
    TString N = to_string(i);
    DL1r_jet_pt_ttl_templ_cut[i] = new TH1F("DL1r_jet_pt_ttl_templ_cut"+N, "DL1r_jet_pt_ttl_templ_cut"+N, 5, 1, 6);
    DL1r_jet_pt_ttb_templ_cut[i] = new TH1F("DL1r_jet_pt_ttb_templ_cut"+N, "DL1r_jet_pt_ttb_templ_cut"+N, 5, 1, 6);
    DL1r_jet_pt_ttc_templ_cut[i] = new TH1F("DL1r_jet_pt_ttc_templ_cut"+N, "DL1r_jet_pt_ttc_templ_cut"+N, 5, 1, 6);}






  cout<<"Open"<<endl;

  TFile *tmva_file = new TFile("TMVA_Bin_3b_85.root");
  TTree *tree = (TTree*)tmva_file->Get("dataset/TestTree");

  // Set all the needed branches
  float jet_tagWeightBin_DL1r_continuous_2; 
  float BDT;
  //vector<int> *topHOF, *jet_isbtagged_DL1r_77, *jet_truthflav;
  float weights;
  float jet_truthflav_2;
  float h_ttl = 0;
  float h_ttc = 0;
  float h_ttb = 0;
  float jet_pt_2;
  float N_event[n_bins];
  int pt_ranges[n_bins+1];

  for(int i=0; i<=n_bins; i++){
    pt_ranges[i] = 100000*i;

    //cout << pt_ranges[i] << endl;}
  }

  //tree->SetBranchAddress("jet_DL1r", &jet_DL1r_tag_weight);
  //tree->SetBranchAddress("jet_isbtagged_DL1r_77", &jet_isbtagged_DL1r_77);
  tree->SetBranchAddress("jet_truthflav_2", &jet_truthflav_2);
  //tree->SetBranchAddress(method_name, &classifier);
  tree->SetBranchAddress("weights", &weights);
  //tree->SetBranchAddress("topHadronOriginFlag", &topHOF);
  tree->SetBranchAddress("jet_pt_2", &jet_pt_2);
  //tree->SetBranchAddress("jet_eta", &jet_eta);
  //tree->SetBranchAddress("jet_phi", &jet_phi);
  tree->SetBranchAddress("BDT", &BDT);
  tree->SetBranchAddress("jet_tagWeightBin_DL1r_continuous_2", &jet_tagWeightBin_DL1r_continuous_2);



  // Loop over events
  Int_t nEntries = tree->GetEntries();
  cout << "\tnumber of entries = " << nEntries << endl;
  
  for (int entry=0; entry<nEntries; entry++) {
    if (entry%1000==0) { cout << "\t" << entry << "\r"; cout.flush(); }
    tree->GetEntry(entry);
    weights = weights*2;
    //cout<<"Here"<<endl;

    // cout << "Before" << endl;

    for(int j = 0; j<n_bins; j++){
      //cout << "working" << endl;
      if((jet_pt_2) >= pt_ranges[j] && ((jet_pt_2) < pt_ranges[j+1])){
	N_event[j] += weights;
	if ((jet_truthflav_2)==0)DL1r_jet_pt_ttl_templ[j]->Fill(jet_tagWeightBin_DL1r_continuous_2, weights);
	if ((jet_truthflav_2)==5)DL1r_jet_pt_ttb_templ[j]->Fill(jet_tagWeightBin_DL1r_continuous_2, weights);
	if ((jet_truthflav_2)==4)DL1r_jet_pt_ttc_templ[j]->Fill(jet_tagWeightBin_DL1r_continuous_2, weights);
        
        
      }
      //cout << N_event[j] << endl;
      //cout << "Here" << endl;
    }
    //cout << "after" << endl;

    for (int j=0; j<n_bins; j++){
      if((jet_pt_2)>= pt_ranges[j] && ((jet_pt_2)<pt_ranges[j+1])){
	if ((BDT)>0){
	  if ((jet_truthflav_2)==0)DL1r_jet_pt_ttl_templ_cut[j]->Fill(jet_tagWeightBin_DL1r_continuous_2, weights);
	  if ((jet_truthflav_2)==5)DL1r_jet_pt_ttb_templ_cut[j]->Fill(jet_tagWeightBin_DL1r_continuous_2, weights);
	  if ((jet_truthflav_2)==4)DL1r_jet_pt_ttc_templ_cut[j]->Fill(jet_tagWeightBin_DL1r_continuous_2, weights);
	}//pt range
      }//BDT 
    }//for



    
    DL1r_bin_jet_2_no_cut->Fill(jet_tagWeightBin_DL1r_continuous_2, weights);

    if ((jet_truthflav_2)==0) DL1r_templ_BDT_ttl_no_cut->Fill(jet_tagWeightBin_DL1r_continuous_2, weights);
    if ((jet_truthflav_2)==4) DL1r_templ_BDT_ttc_no_cut->Fill(jet_tagWeightBin_DL1r_continuous_2, weights);
    if ((jet_truthflav_2)==5) DL1r_templ_BDT_ttb_no_cut->Fill(jet_tagWeightBin_DL1r_continuous_2, weights);
   
    if ((BDT)>0){
      DL1r_bin_3rd_jet->Fill(jet_tagWeightBin_DL1r_continuous_2, weights);
    }

    if ((BDT)>0){
      if ((jet_truthflav_2)==0) DL1r_templ_BDT_ttl->Fill(jet_tagWeightBin_DL1r_continuous_2, weights);
      if ((jet_truthflav_2)==4) DL1r_templ_BDT_ttc->Fill(jet_tagWeightBin_DL1r_continuous_2, weights);
      if ((jet_truthflav_2)==5) DL1r_templ_BDT_ttb->Fill(jet_tagWeightBin_DL1r_continuous_2, weights);
    }

    if ((jet_truthflav_2)==0)BDT_ttl->Fill(BDT, weights);
    if ((jet_truthflav_2)==4)BDT_ttc->Fill(BDT, weights);
    if ((jet_truthflav_2)==5)BDT_ttb->Fill(BDT, weights);


    if ((BDT)<0)continue;
    if((jet_truthflav_2)==0)h_ttl +=weights;
    if((jet_truthflav_2)==4)h_ttc +=weights;
    if((jet_truthflav_2)==5)h_ttb +=weights;


    if ((BDT)>0){
      DL1r_bin_jet_pt_2_cut->Fill(jet_pt_2, weights);}
    
    //if ((jet_truthflav_2)==4)DL1r_bin_jet_pt_2_c->Fill(jet_pt_2, weights);

    
    DL1r_bin_jet_pt_2_no_cut->Fill(jet_pt_2, weights);
    


  }//entries
  cout << h_ttl << endl;
  cout << h_ttc << endl;
  cout << h_ttb << endl;
 
   

  TFile *hist_file = new TFile("TMVA_Bin_3b_85.root","UPDATE");
  
  gDirectory->Delete("DL1r_Bin_3rd_jet;1");

  gDirectory->Delete("DL1r_templ_BDT_ttl;1");
  gDirectory->Delete("DL1r_templ_BDT_ttc;1");
  gDirectory->Delete("DL1r_templ_BDT_ttb;1");
  

  gDirectory->Delete("DL1r_templ_BDT_ttl_no;1");
  gDirectory->Delete("DL1r_templ_BDT_ttc_no;1");
  gDirectory->Delete("DL1r_templ_BDT_ttb_no;1");
  gDirectory->Delete("DL1r_templ_BDT_ttl_no;2");
  gDirectory->Delete("DL1r_templ_BDT_ttc_no;2");
  gDirectory->Delete("DL1r_templ_BDT_ttb_no;2");
  gDirectory->Delete("DL1r_templ_BDT_ttl_no;3");
  gDirectory->Delete("DL1r_templ_BDT_ttc_no;3");
  gDirectory->Delete("DL1r_templ_BDT_ttb_no;3");

  gDirectory->Delete("BDT_ttl;1");
  gDirectory->Delete("BDT_ttc;1");
  gDirectory->Delete("BDT_ttb;1");

  gDirectory->Delete("DL1r_bin_jet_pt_2_no_cut;1");
  gDirectory->Delete("DL1r_bin_jet_pt_2_cut;1");
  gDirectory->Delete("DL1r_Bin_3rd_jet_BDT;1");
  gDirectory->Delete("DL1r_Bin_3rd_jet_BDT_Cut_0;1");

  
  gDirectory->Delete("DL1r_jet_pt_ttl_templ0;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ0;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ0;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ1;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ1;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ1;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ2;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ2;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ2;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ3;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ3;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ3;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ4;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ4;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ4;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ5;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ5;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ5;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ6;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ6;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ6;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ7;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ7;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ7;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ8;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ8;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ8;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ9;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ9;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ9;1");

  gDirectory->Delete("DL1r_jet_pt_ttl_templ_cut0;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ_cut0;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ_cut0;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ_cut1;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ_cut1;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ_cut1;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ_cut2;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ_cut2;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ_cut2;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ_cut3;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ_cut3;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ_cut3;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ_cut4;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ_cut4;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ_cut4;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ_cut5;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ_cut5;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ_cut5;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ_cut6;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ_cut6;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ_cut6;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ_cut7;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ_cut7;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ_cut7;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ_cut8;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ_cut8;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ_cut8;1");
  gDirectory->Delete("DL1r_jet_pt_ttl_templ_cut9;1");
  gDirectory->Delete("DL1r_jet_pt_ttc_templ_cut9;1");
  gDirectory->Delete("DL1r_jet_pt_ttb_templ_cut9;1");


  DL1r_bin_jet_2_no_cut->Write("DL1r_Bin_3rd_jet_BDT");
  DL1r_bin_3rd_jet->Write("DL1r_Bin_3rd_jet_BDT_Cut_0");

  DL1r_templ_BDT_ttl->Write("DL1r_templ_BDT_ttl");
  DL1r_templ_BDT_ttc->Write("DL1r_templ_BDT_ttc");
  DL1r_templ_BDT_ttb->Write("DL1r_templ_BDT_ttb");

  DL1r_templ_BDT_ttl_no_cut->Write("DL1r_templ_BDT_ttl_no");
  DL1r_templ_BDT_ttc_no_cut->Write("DL1r_templ_BDT_ttc_no");
  DL1r_templ_BDT_ttb_no_cut->Write("DL1r_templ_BDT_ttb_no");

  BDT_ttl->Write("BDT_ttl");
  BDT_ttc->Write("BDT_ttc");
  BDT_ttb->Write("BDT_ttb");

  DL1r_bin_jet_pt_2_no_cut->Write("DL1r_bin_jet_pt_2_no_cut");
  DL1r_bin_jet_pt_2_cut->Write("DL1r_bin_jet_pt_2_cut");

  for (int jet_i=0; jet_i<n_bins; jet_i++){

    TString num = to_string(jet_i);
    DL1r_jet_pt_ttl_templ[jet_i]->Write("DL1r_jet_pt_ttl_templ" + num);
    DL1r_jet_pt_ttc_templ[jet_i]->Write("DL1r_jet_pt_ttc_templ" + num);
    DL1r_jet_pt_ttb_templ[jet_i]->Write("DL1r_jet_pt_ttb_templ" + num);
  }


  for (int jet_i=0; jet_i<n_bins; jet_i++){

    TString num = to_string(jet_i);
    DL1r_jet_pt_ttl_templ_cut[jet_i]->Write("DL1r_jet_pt_ttl_templ_cut" + num);
    DL1r_jet_pt_ttc_templ_cut[jet_i]->Write("DL1r_jet_pt_ttc_templ_cut" + num);
    DL1r_jet_pt_ttb_templ_cut[jet_i]->Write("DL1r_jet_pt_ttb_templ_cut" + num);
  }


  hist_file->Close();

}//Main Function




