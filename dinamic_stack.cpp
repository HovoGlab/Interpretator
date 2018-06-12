#include <iostream>
using namespace std;

class stack
{
 private:
  int * _arr;
  int _top;
  int _size;
 public:
  void push(const int value);
  int  pop();
  stack(const int sz = 10);
  ~stack();
};


stack::stack(const int sz)
{ 
  if ( sz < 1){return;}
  this->_size = sz;
  this->_arr = new int[this->_size];
  this->_top = -1;
}

void stack::push(const int value)
{
  if(this->_top == (this->_size-1))
  {
   int*p=new int[2*this->_size];
   for (int i=0; i < this->_size; i++)
   {
    p[i] = this->_arr[i];
   } 
   delete [] this->_arr;
   this->_arr = p;
   this->_size = (2 * this->_size);
  }
  this->_arr[++this->_top] = value;
}

int stack::pop()
{
  if(this->_top==-1)    
  {
   cout<<"stack is empty";
   return 0;
  } 
  return this->_arr[this->_top--];
}

stack::~stack()
{
  delete [] _arr;
  _arr=nullptr;
}


int main(){
  stack a;
  a.push(4);
  cout<<a.pop();

}
