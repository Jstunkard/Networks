//Application Layer
int AppL_SP_Inp(int header,string inside){
  header+=1;
  cout << header << "  " << inside;
  TL_SP_Inp(header,inside);
  return 1;
}
int AppL_SP_Out(int header,string inside){
  return 1;
}
int AppL_SU_Inp(int header,string inside){
  return 1;
}

//Transport Layer
int TL_SP_Inp(int header,string inside){
  header+=1;

  NL_SP_Inp(header,inside);
  return 1;
}
int TL_SP_Out(int header,string inside){
  return 1;
}
int TL_SU_Inp(int header,string inside){
  return 1;
}

//Network Layer
int NL_SP_Inp(int header,string inside){
  header+=1;

  DLL_SP_Inp(header,inside);
  return 1;
}
int NL_SP_Out(int header,string inside){
  return 1;
}
int NL_SU_Inp(int header,string inside){
  return 1;
}

//Data Link Layer
int DLL_SP_Inp(int header,string inside){
  header+=1;

  PhyL_SP_Inp(header,inside);
  return 1;
}
int DLL_SP_Out(int header,string inside){
  return 1;
}
int DLL_SU_Inp(int header,string inside){
  return 1;
}

//Physical Layer
int PhyL_SP_Inp(int header,string inside){
  header+=1;

  PhyL_SU_Inp(header,inside);
  return 1;
}
int PhyL_SP_Out(int header,string inside){
  return 1;
}
int PhyL_SU_Inp(int header,string inside){
  cout << header << "  " << inside;
  return 1;
}

