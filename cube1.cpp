#include <iostream>
#include <string>
#include <sstream>
using namespace std;

   
  
 class cube
 {
  public:
     void _getline();
     cube(const int size = 8);
     void _checkSpace(string & _cont);
     void _filling(string & _cont);
     void _checkSize(const string & _cont);
     void _combination();
     void _divideComb(const string & _arr,int & it);
     void _Checker(int & it);
     void _encrypt();
     void _rotLeft(const int & ND);
     void _rotRight(const int & ND);
     void _rotUp(const int & ND);
     void _rotDown(const int & ND);
  private:
     char** _array2;
     string * _arr;
     string _cont;
     int _cubeNum;
     int _size;
     int tmp1;
     int NumOfBegin;
     string Save;
     
 };
 
 cube::cube(const int sz)
 {
    _size = sz;
     
 }

 void cube::_encrypt()
 {   
    _cont.clear();

    for(int i = 0;i<_cubeNum;i++)
    {
       
      
      Save = _arr[i];
      string tmp;
      int count = 0;
      while(Save[count]!= ':')
      {
          tmp = tmp + Save[count];
          count++;
      }

      NumOfBegin = tmp.size();
      stringstream(tmp) >> tmp1;

      for(int j = NumOfBegin+1;j < Save.size();j+=2)
      {
          if(Save[j] == 'L')
          {
            _rotLeft(tmp1);
          }
          if(Save[j] == 'R')
          {
            _rotRight(tmp1);
          }    
          if(Save[j] == 'U')
          {
            _rotUp(tmp1);    
          }
          if(Save[j] == 'D')
          {
            _rotDown(tmp1);    
          }    
            
      }
      
      _cont += _array2[i];
      
        

    }

    for(int i = 0;i<_cont.size();i++)
    {
        if(_cont[i] == '|')
        {
            _cont[i] = ' ';
        }    
        
    }
    cout << _cont << endl;
   
 }
 
 void cube::_rotLeft(const int & ND)
 {
    char temp;
    temp = _array2[ND][0];
    _array2[ND][0] = _array2[ND][1];
    _array2[ND][1] = _array2[ND][5]; 
    _array2[ND][5] = _array2[ND][4];
    _array2[ND][4] = temp;
    temp = _array2[ND][3];
    _array2[ND][3] = _array2[ND][2];
    _array2[ND][2] = _array2[ND][6];
    _array2[ND][6] = _array2[ND][7];
    _array2[ND][7] = temp;
 }
 

  
 void cube::_rotRight(const int & ND)
 {
    char temp;
    temp = _array2[ND][1];
    _array2[ND][1] = _array2[ND][0];
    _array2[ND][0] = _array2[ND][4]; 
    _array2[ND][4] = _array2[ND][5];
    _array2[ND][5] = temp;
    temp = _array2[ND][2];
    _array2[ND][2] = _array2[ND][3];
    _array2[ND][3] = _array2[ND][7];
    _array2[ND][7] = _array2[ND][6];
    _array2[ND][6] = temp;
 }


   
 void cube::_rotUp(const int & ND)
 {
    char temp;
    temp = _array2[ND][2];
    _array2[ND][2] = _array2[ND][1];
    _array2[ND][1] = _array2[ND][5]; 
    _array2[ND][5] = _array2[ND][6];
    _array2[ND][6] = temp;
    temp = _array2[ND][3];
    _array2[ND][3] = _array2[ND][0];
    _array2[ND][0] = _array2[ND][4];
    _array2[ND][4] = _array2[ND][7];
    _array2[ND][7] = temp;
 }


    
 void cube::_rotDown(const int & ND)
 {
    char temp;
    temp = _array2[ND][0];
    _array2[ND][0] = _array2[ND][3];
    _array2[ND][3] = _array2[ND][7]; 
    _array2[ND][7] = _array2[ND][4];
    _array2[ND][4] = temp;
    temp = _array2[ND][1];
    _array2[ND][1] = _array2[ND][2];
    _array2[ND][2] = _array2[ND][6];
    _array2[ND][6] = _array2[ND][5];
    _array2[ND][5] = temp;
 } 
 
 
 void cube::_Checker(int & it)
 {   
    if(tmp1 >= _cubeNum || tmp1 < 0)
    {
        cout << "Something is wrong, reenter your combination again" << endl;
        cout << "#" << it+1 << ":";
        getline(cin,_arr[it]);
        _divideComb(_arr[it],it);
       
    }
     
    
    
    for(int i = NumOfBegin; i < Save.size(); i+=2)    
    {
        
 
       if(Save[i]!= ':') 
       {
           cout << "Something is wrong, reenter your combination again" << endl;
           cout << "#" << it+1 << ":";
           getline(cin,_arr[it]);
           _divideComb(_arr[it],it);
           
       }
        
       if((Save[i+1] != 'L') && (Save[i+1] != 'R') && (Save[i+1]!='U') && (Save[i+1]!='D'))
       {
           cout << "Something is wrong, reenter your combination again" << endl;
           cout << "#" << it+1 << ":";
           getline(cin,_arr[it]);
           _divideComb(_arr[it],it);
       }
        
    }    
 
 }

 void cube::_divideComb(const string & _arr,int & it)
 {  
    Save = _arr;
    string tmp;
    int count = 0;
    while(_arr[count]!= ':')
    {
        tmp = tmp + _arr[count];
        count++;
    }
    
    NumOfBegin = tmp.size(); 
    stringstream(tmp) >> tmp1;
    _Checker(it);
    
 }

 void cube::_combination()
 {
    _arr = new string[_cubeNum];
    cout << "Please enter the combination this way: for example \"1:L:U:L:D\" " << endl;
    for(int i = 0 ; i < _cubeNum; i++)
    {   
        cout << "#" << i+1 << ":";
        getline(cin,_arr[i]);
        _divideComb(_arr[i],i);
       
    }
    
 }

 void cube::_checkSpace(string & _cont)
 {
   
    int sos = _cont.size()%_size;
    if(sos > 0)
    {
        for(int s = 0;s < _size-sos;s++)
        {
            _cont = _cont + " ";
 
        }    
     
    } 

    for(int i = 0 ; i < _cont.size(); i++)
    {
       if(_cont[i]==' ')
       {
            _cont[i] = '|'; 
       }    
    } 

 }
 
 void cube::_checkSize(const string & _cont)
 {    
    if(_cont.size()<=8)
    {
       _cubeNum = 1;
       return;
    }
    double cubeNum = _cont.size()/8.0;
    _cubeNum = cubeNum;
    if(_cubeNum == cubeNum)
    {  
       return;
    }
    else
    {  
       _cubeNum = _cubeNum+1;
        
    }

 }
 
 void cube::_filling(string & _cont)
 {
    
    _array2 = new char*[_cubeNum];
    for(int i = 0; i < _cubeNum; i++)
    {
        _array2[i] = new char[_size];
    }
        
    for(int i = 0 ; i < _cubeNum; i++)
    {  
        if(i!=0)
        {
            _cont.erase(0,8);
        }    
        for(int j = 0;j < _size;j++)
        {   
                
            if(i!= 0 && i == (_cubeNum-1) && j == (_size - (_size - _cont.size())))
            {
                break;
            }
                
            _array2[i][j] = _cont[j];
               
                    
        }    
    }    

        
 }
     

 

 void cube::_getline()
 {
     getline(cin,_cont);
     _checkSpace(_cont);
     _checkSize(_cont);
     _filling(_cont);
     _combination();
     _encrypt();
  
 }

 
 int main()
 {
     cube Data;     
     cout << "Please Enter the text" << endl;
     Data._getline();
    
 }
