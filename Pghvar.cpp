#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <cctype>
using namespace std;

class tokenizer
{
      public:
          void m_getline(string& line);
          void m_checking(string& line);
      private:
          string _token;
          map <string,pair<string,string> > con;
};


void tokenizer::m_getline(string& line)
{
    _token = line.substr(0,line.find(" "));
    if(_token == "pghvar")
    {
        int pos = line.rfind(";");
        string var = line.substr(7,pos-7);
        con.emplace(var,make_pair("",""));
    }
    else {return;}
}
 
void tokenizer::m_checking(string& line)
{
    
    _token = line.substr(0,line.find(" ")); 
    if(_token!="pghvar"&&_token!="print")
    { 
        auto it = con.find(_token);
        if(it!=con.end())
        {
          string optr = line.substr((line.find(" "))+1,1);
          if(optr == "=")
          {
                con[_token].first = line.substr((line.find("="))+2,(line.find(";"))-((line.find("=")+2)));
                if(!isdigit(con[_token].first[0]))
                {
                    con[_token].second = "String";
                }
                else
                {
                    int checktypeInt;   
                    double checktypeDouble;
                    stringstream convert(con[_token].first);
                    convert >> checktypeDouble;
                    checktypeInt = checktypeDouble;
                    if((checktypeDouble - checktypeInt) == 0)
                    {
                        con[_token].second = "Integer";
                        cout <<  con[_token].second; 
                    }
                    else
                    {
                        con[_token].second = "Double";
                        cout <<  con[_token].second; 

                    }    
               } 
          }   
          else {return;}
        }
        else
        {
          cout << "You are not declared this variable" << endl;
          return;
        }
    } 
    else {return;}
    
}

int main(int argc,char * argv [] )
{
    if (argc<2)
    {
      cout << "ERROR"; 
      return -1;
    }
    string s = argv[1];
    if ((s.substr(s.length()-4))!=".pgh")
    { 
      cout<<"ERROR";
      return -1;
    }
    string filename = argv[1];
    fstream fileRead(filename);
    string line;
    tokenizer a;
    while(true)
    {  
       getline(fileRead,line);
       
       if (!fileRead.eof())
       {
             
          a.m_getline(line);
          a.m_checking(line);
       }
       else
       break;    
    }
   
  
   

} 
