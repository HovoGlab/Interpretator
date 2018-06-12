#include <iostream>
#include <sstream>
#include <string>

class SpreadsheetCell
{
    public:
      
      SpreadsheetCell();


       void setValue(double inValue);
       double getValue();

        void setString(std::string inString);
        std::string getString();

    protected:
        
        std::string doubleToString(double inValue);
        double stringToDouble(std::string inString);

       double mValue;
       std::string mString;
};


SpreadsheetCell::SpreadsheetCell()//: mValue(0), mString("")
{
    mValue = 0;
    mString = " ";
}

void SpreadsheetCell::setValue(double inValue)
{
    mValue = inValue;

     mString = doubleToString(mValue);

}

double SpreadsheetCell::getValue()
{
    return (mValue);
}

void SpreadsheetCell::setString(std::string inString)
{
    mString = inString;
    
     mValue = stringToDouble(mString);

}

std::string SpreadsheetCell::getString()
{
    return (mString);
}

std::string SpreadsheetCell::doubleToString(double inValue)
{
    std::stringstream ostr;

     ostr << inValue;
     return (ostr.str());
}
double SpreadsheetCell::stringToDouble(std::string inString)
{
    double temp;

    std::istringstream istr (inString);

     istr >> temp;
     if (istr.fail() || istr.eof()){return (0);}

      return (temp);
 }   


int main(){
    
    SpreadsheetCell practice();

      std::cout << practice.getValue() << std::endl;
      std::cout << practice.getString() << std::endl;
   
}

