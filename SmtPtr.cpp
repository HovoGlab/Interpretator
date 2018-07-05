#include <iostream>
using namespace std;

template <typename T>
class SmartPtr
{
 public:
    SmartPtr (T * adress )
    {
        this->pointer = adress;
    }
    ~SmartPtr ()
    {
        delete pointer;
    }
    T& operator*()
    {
        return *pointer;    
    }
    T& operator->()
    {
       return pointer;   
    }

 private:
 T * pointer;
};


int main()
{
    SmartPtr <int> p = new int;
    *p = 7;
    cout << *p << endl;   
}
