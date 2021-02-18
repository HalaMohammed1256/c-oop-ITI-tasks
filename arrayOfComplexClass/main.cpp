#include <iostream>

using namespace std;

class Complex{
    private:
        int real;
        int imaginary;

    public:
        /// real setter and getter
        void setReal(int _real){
            real = _real;
        }
        int getReal() const{
            return real;
        }

        /// imaginary setter and getter
        void setImaginary(int _imaginary){
            imaginary = _imaginary;
        }
        int getImaginary()const{
            return imaginary;
        }

        /// constructors
        Complex(){
            real = 0;
            imaginary = 0;
            ///cout<<"Complex default constructor\n";
        }
        Complex(int _real, int _imaginary){
            real = _real;
            imaginary = _imaginary;
            ///cout<<"Complex parametrize constructor\n";
        }
        Complex(int value){
            real = value;
            imaginary = value;
            ///cout<<"Complex parametrize constructor\n";
        }
        Complex(const Complex& old){
            real = old.real;
            imaginary = old.imaginary;
            ///cout<<"Complex copy constructor\n";
        }

        /// destructor
        ~Complex(){
            ///cout<<"Complex destructor\n";
        }



        Complex operator+(const Complex &right){
            Complex returnedComplex;
            returnedComplex.real = real + right.real;
            returnedComplex.imaginary = imaginary + right.imaginary;

            return returnedComplex;
        }

        Complex operator-(const Complex &right){
            Complex returnedComplex;
            returnedComplex.real = real - right.real;
            returnedComplex.imaginary = imaginary - right.imaginary;

            return returnedComplex;
        }

        Complex operator*(const Complex &right){
            Complex returnedComplex;
            returnedComplex.real = real * right.real;
            returnedComplex.imaginary = imaginary * right.imaginary;

            return returnedComplex;
        }

        Complex operator/(const Complex &right){
            Complex returnedComplex;
            returnedComplex.real = real / right.real;
            returnedComplex.imaginary = imaginary / right.imaginary;

            return returnedComplex;
        }


        Complex& operator+=(const Complex &right){
            real += right.real;
            imaginary += right.imaginary;

            return *this;
        }

        Complex operator-=(const Complex &right){
            real -= right.real;
            imaginary -= right.imaginary;

            return *this;
        }

        Complex operator/=(const Complex &right){
            real /= right.real;
            imaginary /= right.imaginary;

            return *this;
        }

        Complex operator*=(const Complex &right){
            real *= right.real;
            imaginary *= right.imaginary;

            return *this;
        }

        int operator>(const Complex &right){
            return real > right.real && imaginary > right.imaginary;
        }

        int operator>=(const Complex &right){
            return real >= right.real && imaginary >= right.imaginary;
        }

        int operator<(const Complex &right){
            return real < right.real && imaginary < right.imaginary;
        }

        int operator<=(const Complex &right){
            return real <= right.real && imaginary <= right.imaginary;
        }

        int operator==(const Complex &right){
            return real == right.real && imaginary == right.imaginary;
        }

        int operator!=(const Complex &right){
            return real != right.real && imaginary != right.imaginary;
        }

        ///c3=c1+7; //c3=7+c1; //int x=c1

        Complex& operator=(const Complex &right){
            real = right.real;
            imaginary = right.imaginary;
            return *this;
        }

        Complex& operator++(){
            real++;
            return *this;
        }

        Complex operator++(int){
            Complex returnedComplex = *this;
            real++;
            return returnedComplex;
        }

        Complex operator+(int value){
            Complex returnedComplex;
            returnedComplex.real = real + value;
            returnedComplex = imaginary;
            return returnedComplex;
        }


        /*/// add complex function
        Complex addComplex(const Complex& right){

            Complex temp;
            temp.setReal(this->real + right.getReal());
            temp.setImaginary(this->imaginary + right.getImaginary());

            return temp;
        }*/

        /// print complex
        void printComplex(){
            cout<<real<<" + "<<imaginary<<"i";
        }

};

/// standalone subtract complex function
Complex subComplex(const Complex& left, const Complex& right){

    Complex temp;
    temp.setReal(left.getReal() - right.getReal());
    temp.setImaginary(left.getImaginary() - right.getImaginary());

    return temp;
}

int main()
{

    char redo = 'y';
    Complex complexAddition, complexSubtraction;
    Complex *complexArr[2];
    int temp, temp1, result;

    do{

        for(int i = 0; i < 2; i++){

            do{
                cout<<"for complex "<<i+1<<":\n"<<"if you want to use the default values press 1,\nand if you want to use the same value press 2, otherwise press 3:  ";
                cin>>result;
            }while(result < 1 || result > 3);

            switch(result){
                case 1:
                    complexArr[i] = new Complex();
                break;
                case 2:
                    cout<<"\nPlease enter complex "<<i+1<<" value: ";
                    cin>>temp;
                    complexArr[i] = new Complex(temp);

                break;

                case 3:
                    cout<<"\nPlease enter complex "<<i+1<<" real: ";
                    cin>>temp;

                    cout<<"\nPlease enter complex "<<i+1<<" imaginary: ";
                    cin>>temp1;

                    complexArr[i] = new Complex(temp,temp1);
                break;
            }

            cout<<endl;
        }

       // complexAddition = complexArr[0]->addComplex(*complexArr[1]);
        //complexSubtraction = subComplex(*complexArr[0], *complexArr[1]);


        cout<<"\n\nfirst complex: ";
        complexArr[0]->printComplex();

        cout<<"\nsecond complex: ";
        complexArr[1]->printComplex();

        cout<<"\ncomplex addition: ";
        complexAddition.printComplex();

        cout<<"\ncomplex subtraction: ";
        complexSubtraction.printComplex();



        cout<<"\n\nDo you want to redo the task? y|n:  ";
        cin>>redo;
        cout<<endl<<endl;

    }while(redo == 'y' || redo == 'Y');



    return 0;
}
