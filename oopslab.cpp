#include<iostream>
using namespace std;
class ComplexNumber
{
private:
    double real,imaginary;
public:
    ComplexNumber(double r,double i)
    {
        real=r;
        imaginary=i;
    }
    void operations(ComplexNumber a,ComplexNumber b)
    {
        cout<<"Sum= "<<a.real+b.real<<"+"<<a.imaginary+b.imaginary<<"i"<<endl;
        cout<<"Difference= "<<a.real-b.real<<"+"<<a.imaginary-b.imaginary<<"i"<<endl;
    }
};
int main()
{
    double i1,r1,i2,r2;
    cout<<"enter real and imaginary part of a complex number: "<<endl;
    cin>>r1>>i1;
    cout<<"enter the real and imaginary part of 2nd complex number: "<<endl;
    cin>>r2>>i2;
    ComplexNumber a(i1,r1),b(i2,r2);
    a.operations(a,b);
}

