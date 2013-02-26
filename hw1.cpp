// 5 layer OSI network model
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

// Function Prototypes
void AppL_SP_Inp(int,string);
void AppL_SP_Out(int,string);
void AppL_SU_Inp(int,string);

void TL_SP_Inp(int,string);
void TL_SP_Out(int,string);
void TL_SU_Inp(int,string);

void NL_SP_Inp(int,string);
void NL_SP_Out(int,string);
void NL_SU_Inp(int,string);

void DLL_SP_Inp(int,string);
void DLL_SP_Out(int,string);
void DLL_SU_Inp(int,string);

void PhyL_SP_Inp(int,string);
void PhyL_SP_Out(int,string);
void PhyL_SU_Inp(int,string);


//Application Layer
void AppL_SP_Inp(int header,string inside){
  if (header=2) {   
    time_t rawtime;
    time (&rawtime);
    inside += "AppL - ";
    inside += ctime (&rawtime);
  }
  else if (header >=4) {
    cout << header << " " << inside;
    return; 
  }

  header+=1;
  cout << header << "  " << inside;
  TL_SP_Inp(header,inside);
  return;
}
void AppL_SP_Out(int header,string inside){
//  header+=1;
  AppL_SP_Inp(header,inside);
  return;
}
void AppL_SU_Inp(int header,string inside){
//  header+=1;
  AppL_SP_Out(header,inside);
  return;
}

//Transport Layer
void TL_SP_Inp(int header,string inside){
//  header+=1;

  NL_SP_Inp(header,inside);
  return;
}
void TL_SP_Out(int header,string inside){
//  header+=1;
  AppL_SU_Inp(header,inside);
  return;
}
void TL_SU_Inp(int header,string inside){
//  header+=1;
  TL_SP_Out(header,inside);
  return;
}

//Network Layer
void NL_SP_Inp(int header,string inside){
//  header+=1;

  DLL_SP_Inp(header,inside);
  return;
}
void NL_SP_Out(int header,string inside){
//  header+=1;
  TL_SU_Inp(header,inside);
  return;
}
void NL_SU_Inp(int header,string inside){
//  header+=1;
  NL_SP_Out(header,inside);
  return;
}

//Data Link Layer
void DLL_SP_Inp(int header,string inside){
//  header+=1;

  PhyL_SP_Inp(header,inside);
  return;
}
void DLL_SP_Out(int header,string inside){
//  header+=1;
  NL_SU_Inp(header,inside);
  return;
}
void DLL_SU_Inp(int header,string inside){
//  header+=1;
  DLL_SP_Out(header,inside);
  return;
}

//Physical Layer
void PhyL_SP_Inp(int header,string inside){
//  header+=1;

  PhyL_SU_Inp(header,inside);
  return;
}
void PhyL_SP_Out(int header,string inside){
//  header+=1;
  DLL_SU_Inp(header,inside);
  return;
}
void PhyL_SU_Inp(int header,string inside){
  header+=1;
  cout << header << "  " << inside;
  PhyL_SP_Out(header,inside);
  return;
}

int main(){

  string input;
  cout << "Please enter a message and press enter to submit, or type QUIT to exit";
  cout << endl;
  getline (cin, input);
//  cout << "WOW " << input;
  AppL_SP_Inp(0,input);
  return 0;
}
