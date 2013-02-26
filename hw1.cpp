// 5 layer OSI network model
// Program By: Jason Stunkard
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

void test(int,string);

//Test output
void test(int header,string data){
  cout << header << " " << data;
}

//Application Layer
void AppL_SP_Inp(int header,string data){
//  cout << header;
  if (header==2) { 
    // I used the time_t function to create the time stamp.
    time_t rawtime;
    time (&rawtime);
    string temp = data; // Used to store the data temporaraly while the time stamp is generated.
    data = "AppL - ";  // Adds the first part of the time stamp showing the layer it was applied at.
    data += ctime (&rawtime); // Adds the time to the stamp
    data.erase (data.end()-1); // This removes the \n character that ctime places at the end of the string.
    data +=": ";
    data += temp; // Moves to origional data to the end of the timestamp.
  }
  else if (header >=4) {
//    test(header,data);
    cout << data;
    return; 
  }
//  else{
//    test(header,data);
//  }

//  if (header == 0){
  header+=1; // Incraments the header here at the Appl_SP_Inp and at the PhyL_SU_Inp
             //   to ensure the header is the correct path number for the entire time
             //   travelled up and down the layers.
//  test(header,data);
  TL_SP_Inp(header,data);
//  }
  return;
}
void AppL_SP_Out(int header,string data){
//  header+=1;
  AppL_SP_Inp(header,data);
  return;
}
void AppL_SU_Inp(int header,string data){
//  header+=1;
  AppL_SP_Out(header,data);
  return;
}

//Transport Layer
void TL_SP_Inp(int header,string data){
//  header+=1;
  NL_SP_Inp(header,data);
  return;
}
void TL_SP_Out(int header,string data){
//  header+=1;
  AppL_SU_Inp(header,data);
  return;
}
void TL_SU_Inp(int header,string data){
//  header+=1;
  TL_SP_Out(header,data);
  return;
}

//Network Layer
void NL_SP_Inp(int header,string data){
//  header+=1;
  DLL_SP_Inp(header,data);
  return;
}
void NL_SP_Out(int header,string data){
//  header+=1;
  TL_SU_Inp(header,data);
  return;
}
void NL_SU_Inp(int header,string data){
//  header+=1;
  NL_SP_Out(header,data);
  return;
}

//Data Link Layer
void DLL_SP_Inp(int header,string data){
//  header+=1;
  PhyL_SP_Inp(header,data);
  return;
}
void DLL_SP_Out(int header,string data){
//  header+=1;
  NL_SU_Inp(header,data);
  return;
}
void DLL_SU_Inp(int header,string data){
//  header+=1;
  DLL_SP_Out(header,data);
  return;
}

//Physical Layer
void PhyL_SP_Inp(int header,string data){
//  header+=1;
  PhyL_SU_Inp(header,data);
  return;
}
void PhyL_SP_Out(int header,string data){
//  header+=1;
  DLL_SU_Inp(header,data);
  return;
}
void PhyL_SU_Inp(int header,string data){
  header+=1;
//  cout << header << "  " << data;
  PhyL_SP_Out(header,data);
  return;
}

int main(){

  string input;
  cout << "Please enter a message and press enter to submit, or type QUIT to exit";
  cout << endl;
  getline (cin, input);
  if (input=="QUIT" || input=="Quit" || input=="quit" || input=="Q" || input=="q") {
    cout << "Now exiting";
    return 0;
  }
  AppL_SP_Inp(0,input);
  return 0;
}
