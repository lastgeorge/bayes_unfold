void test(){
  // Define two beams
  Double_t Ntrue[2]={10,6};
  Double_t PEC[2][2]={{0.6,0.4},    //00   01
		      {0.4,0.6}};   //10   11
  Double_t Nmeasure[2];
  Nmeasure[0] = int(Ntrue[0]*PEC[0][0] + Ntrue[1]*PEC[1][0]-3);
  Nmeasure[1] = int(Ntrue[0]*PEC[0][1] + Ntrue[1]*PEC[1][1]+3);
  
  cout << Nmeasure[0] << " " << Nmeasure[1] << endl;

  // Make a Guess
  //  Double_t Nguess[2]={10,6};
  
  Double_t Nguess[2]={3,3};
  Double_t M[2][2];

  for (Int_t i=0;i!=100;i++){
    M[0][0] = Nguess[0] * PEC[0][0] / (Nguess[0] * PEC[0][0] + Nguess[1]*PEC[1][0]);
    M[0][1] = Nguess[0] * PEC[0][1] / (Nguess[0] * PEC[0][1] + Nguess[1]*PEC[1][1]);
    M[1][0] = Nguess[1] * PEC[1][0] / (Nguess[0] * PEC[0][0] + Nguess[1]*PEC[1][0]);
    M[1][1] = Nguess[1] * PEC[1][1] / (Nguess[0] * PEC[0][1] + Nguess[1]*PEC[1][1]);
    
     // cout << M[0][0] << " " << M[0][1] << endl;
     // cout << M[1][0] << " " << M[1][1] << endl;

    Double_t Ndeduce[2];
    Ndeduce[0] = Nmeasure[0] * M[0][0] + Nmeasure[1] * M[0][1];
    Ndeduce[1] = Nmeasure[0] * M[1][0] + Nmeasure[1] * M[1][1];
    
    cout << "Result: " << i << " " << Ndeduce[0] << " " << Ndeduce[1] << endl;
    cout << Ndeduce[0] * PEC[0][0] + Ndeduce[1]*PEC[1][0] << " " 
	 << Ndeduce[0] * PEC[0][1] + Ndeduce[1]*PEC[1][1] << endl;
      
    
    Nguess[0] = Ndeduce[0];
    Nguess[1] = Ndeduce[1]; 
  }
}
