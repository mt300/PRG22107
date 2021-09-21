#ifndef COMPLEXNUMBERS_H
#define COMPLEXNUMBERS_H

#include <iostream>
#include <math.h>

using namespace std;


template<typename Type>
class ComplexNumbers
{
    public:
        ComplexNumbers<Type>(Type a, Type b);

        ComplexNumbers<Type>(){};

        virtual ~ComplexNumbers<Type>(){};

        //getters
        Type getReal(){return _real;};
        Type getImag(){return _imag;};
        //setters
        void setReal(Type real){_real = real;};
        void setImag(Type imag){_imag = imag;};
        //Arithmetics operators overloaded
        ComplexNumbers<Type> operator+(const ComplexNumbers &number);
        ComplexNumbers<Type> operator-(const ComplexNumbers &number);
        ComplexNumbers<Type> operator*(const ComplexNumbers &number);
        ComplexNumbers<Type> operator/(const ComplexNumbers &number);
        //IO operators overloaded
        friend ostream& operator<<(ostream &output,const ComplexNumbers &number)
        {
            if(number._imag < 0) output << " " << number._real << " " << number._imag << "i";
            else output << " " << number._real << " +" << number._imag << "i";
            return output;
        };
        friend istream& operator>>(istream &input, ComplexNumbers &number)
        {
            cout << "Input the real parameter of Complex Number:";
            input >> number._real;
            cout << "Now input the imaginary parameter(without i):";
            input >> number._imag;
            return input;
        };

    protected:

    private:

        Type _real;
        Type _imag;
};

template<typename Type>
ComplexNumbers<Type> ComplexNumbers<Type>::operator+(const ComplexNumbers &number)
{
    ComplexNumbers result;
    result._real = this->_real + number._real;
    result._imag = this->_imag + number._imag;
    return result;
}
template<typename Type>
ComplexNumbers<Type> ComplexNumbers<Type>::operator-(const ComplexNumbers &number)
{
    ComplexNumbers result;
    result._real = this->_real - number._real;
    result._imag = this->_imag - number._imag;
    return result;
}
template<typename Type>
ComplexNumbers<Type> ComplexNumbers<Type>::operator*(const ComplexNumbers &number)
{
    ComplexNumbers result;
    result._real = (this->_real * number._real)-(this->_imag * number._imag);
    result._imag = (this->_real * number._imag)+ (this->_imag * number._real);
    return result;
}
template<typename Type>
ComplexNumbers<Type> ComplexNumbers<Type>::operator/(const ComplexNumbers &number)
{
    ComplexNumbers result;
    result._real = ((this->_real * number._real)+(this->_imag * number._imag))/(pow(number._real,2)+pow(number._imag,2));
    result._imag = ((this->_imag * number._real)-(this->_real * number._imag))/(pow(number._real,2)+pow(number._imag,2)) ;
    return result;
}

template<typename Type>
ComplexNumbers<Type>::ComplexNumbers(Type a, Type b)
{
    _real = a;
    _imag = b;
}

#endif // COMPLEXNUMBERS_H
