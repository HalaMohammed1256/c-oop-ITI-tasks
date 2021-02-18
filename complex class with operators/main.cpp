#include <iostream>

using namespace std;

///mm  //c3=7+c1;


class Complex{
    private:
        int real;
        int img;

    public:
        /// real setter and getter
        void setReal(int real){
            this->real = real;
        }
        int getReal(){
            return this->real;
        }

        /// imaginary setter and getter
        void setImaginary(int img){
            this->img = img;
        }
        int getImaginary(){
            return this->img;
        }

        /// constructors
        Complex(){
            this->real = 0;
            this->img = 0;
        }
        Complex(int number){
            this->real = number;
            this->img = number;
        }
        Complex(int real, int img){
            this->real = real;
            this->img = img;
        }

        /// copy constructor
        Complex(const Complex &old){
            this->real=old.real;
            this->img=old.img;
        }

        /// destructor
        ~Complex(){
        }

        /// equal
        Complex& operator=(const Complex & right)
        {
            real=right.real;
            img=right.img;
            return *this;
        }

        /// prefix
        Complex& operator++()
        {
            real++;
            return *this;
        }

        /// postfix
        Complex operator++(int)
        {
            Complex temp=*this;
            real++;
            return temp;
        }

        /// compare ==
        int operator==(Complex right)
        {
            return real==right.real&&img==right.img;
        }

        /// compare >
        int operator>(Complex right)
        {
            return real>right.real&&img>right.img;
        }

        /// compare <
        int operator<(Complex right)
        {
            return real<right.real&&img<right.img;
        }

        /// compare !=
        int operator!=(Complex right)
        {
            return real!=right.real&&img!=right.img;
        }

        /// compare >=
        int operator>=(Complex right)
        {
            return real>=right.real&&img>=right.img;
        }

        /// compare <=
        int operator<=(Complex right)
        {
            return real<=right.real&&img<=right.img;
        }

        ///casting operator to int
        operator int()
        {
            return real;
        }

        /// add two complex int another complex
        Complex operator+(Complex& right)
        {
            Complex temp;
            temp.real=real+right.real;
            temp.img=img+right.img;
            return temp;
        }

        /// add complex in the same object
        Complex& operator+=(const Complex& right)
        {
            real+=right.real;
            img+=right.img;
            return *this;
        }

        /// and number to the real value and put it in another complex
        Complex operator+(int num)
        {
            Complex temp;
            temp.real=real+num;
            temp.img=img;
            return temp;
        }


        /// print complex
        void printComplex(){
            cout<<real<<"+"<<img<<"i"<<endl;
        }
};


Complex operator+(int num,Complex right)
{
    Complex temp;
    temp.setReal(right.getReal()+num);
    temp.setImaginary(right.getImaginary());
    return temp;
}



int main()
{
    char redo = 'y';
    int compReal1, compImg1, compReal2, compImg2, compReal3, compImg3, result;


    do{
        cout<<"\nPlease enter the first complex real number:  ";
        cin>>compReal1;
        cout<<"Please enter the first complex real number:  ";
        cin>>compImg1;
        Complex comp1(compReal1, compImg1);

        cout<<"\nPlease enter the second complex real number:  ";
        cin>>compReal2;
        cout<<"Please enter the second complex real number:  ";
        cin>>compImg2;
        Complex comp2(compReal2, compImg2);

        cout<<"\nPlease enter the third complex real number:  ";
        cin>>compReal3;
        cout<<"Please enter the third complex real number:  ";
        cin>>compImg3;
        Complex comp3(compReal3, compImg3);


        /// operations & printing

        cout<<"\n\nBefore operation:\n\nfirst complex: \n";
        comp1.printComplex();
        cout<<"\nsecond complex: \n";
        comp2.printComplex();
        cout<<"\nthird complex: \n";
        comp3.printComplex();


        cout<<"\n\nAfter operation:\n";

        ///c3=c1+c2
        comp3 = comp1 + comp2;
        cout<<"\noperation => c3=c1+c2 \nthird complex:\n";
        comp3.printComplex();

        ///c1+=c2
        comp1 += comp2;
        cout<<"\noperation => c1+=c2 \nfirst complex:\n";
        comp1.printComplex();
        cout<<"\nsecond complex: \n";
        comp2.printComplex();

        ///c3=c1++;
        comp3 += comp1;
        cout<<"\noperation => c3=c1++ \nthird complex:\n";
        comp3.printComplex();
        cout<<"\nfirst complex: \n";
        comp1.printComplex();

        ///c3=++c1;
        comp3 =++ comp1;
        cout<<"\noperation => c3=++c1 \nthird complex:\n";
        comp3.printComplex();
        cout<<"\nfirst complex: \n";
        comp1.printComplex();

        ///c3=c1+7;
        comp3 = comp1 + 7;
        cout<<"\noperation => c3=c1+7 \nthird complex:\n";
        comp3.printComplex();
        cout<<"\nfirst complex: \n";
        comp1.printComplex();

        ///c3=7+c1;
        comp3 = 7 + comp1;
        cout<<"\noperation => c3=7+c1 \nthird complex:\n";
        comp3.printComplex();
        cout<<"\nfirst complex: \n";
        comp1.printComplex();

        ///c1>c2
        result = comp1 > comp2;
        cout<<"\noperation => c1>c2 \n";
        if( result == 1){
            cout<<"True\n";
        }else{
            cout<<"False\n";
        }

        ///c1<=c2
        result = comp1 <= comp2;
        cout<<"\noperation => c1<=c2 \n";
        if( result == 1){
            cout<<"True\n";
        }else{
            cout<<"False\n";
        }

        ///int x=c1
        int x = comp1;
        cout<<"\noperation => x=c1 \nx = "<<x;


        cout<<"\n\nDo you want to redo the task? y|n: ";
        cin>>redo;
        cout<<"\n\n";

    }while(redo == 'y' || redo == 'Y');


    return 0;
}
