#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<cctype>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::strlen;

bool conver(ifstream& is,ofstream& os);

int main(int argc,char**argv)
{
 cout<<"This program is converting html to normal text."<<endl;
 if (argc!=2)
 {
  cout<<"Usage:"<<argv[0]<<" [filename]"<<endl;
  exit(1);
 }
 ifstream fin(argv[1]);
 char*newname=new char[strlen(argv[1])+6];
 strcpy(newname,argv[1]);
 if (strstr(newname,".html"))
   strcpy(strstr(newname,".html"),"_text.html");
 else
   strcat(newname,"_text");
  
 ofstream fout(newname);
 
 if (!(fin.is_open()))
 {
  cout<<"Unable to open source_file \""<<argv[1]<<"\",program terminated."<<endl;
  exit(1);
 }
 if (!(fout.is_open()))
 {
  cout<<"Unable to open target_file \""<<argv[1]<<"_text\",program terminated."<<endl;
  exit(1);
 }
 cout<<newname<<endl; 
 
 if (conver(fin,fout))
  cout<<"Succeeding converting."<<endl;
 else
  cout<<"Unkonwn error occured."<<endl; 

 delete []newname;
 fin.close();
 fout.close();

 cout<<"Done"<<endl;
return 0;
}

bool conver(ifstream& is,ofstream& os)
{
  int ch;
  bool elements_status=0;
  ch=is.get();
  while (ch!=EOF )
  {
   if (ch=='<')
    elements_status=1;
   if (!elements_status)
    os<<(char)ch;
   if (ch=='>')
    elements_status=0;
   ch=(is.get());
  }
  if (is.eof()==1)
    return true;
  else 
    return false;
  
}
