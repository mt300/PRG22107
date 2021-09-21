#ifndef MATHEUSTOMAZI_P2_H_INCLUDED
#define MATHEUSTOMAZI_P2_H_INCLUDED
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>

#define PI 3.14159265358979323846
//using namespace std;
class Funcao{
    public:
        Funcao(Funcao* f){_f = f;};
        Funcao(){ _f = nullptr; };
        virtual ~Funcao(){};

        virtual double operator()(double x) = 0;
        //virtual double value() = 0;
        //virtual void setValue(double val) = 0;
        static double integrar(Funcao* f, double x1, double x0, double step);
    protected:
        Funcao* _f;

};
double Funcao::integrar(Funcao* f, double x1, double x0, double step){
    double area = 0;
    for (double i=x0; i <= x1; i += step){
        std::cout << "Step[" << i*100 << "]: f(x) = " << (*f)(i) * step << std::endl;
        area += (*f)(i) * step;
    };
    return area;
};

class Constante: public Funcao{
    public:
        Constante(double val){
            _value = val;
        };
        ~Constante(){};

        double operator()(double x){  //Allways return Constante._value uncommitted to x parameter
            return this->_value;
        };
        //getter
        double value(){return _value;};
        //setter
        void setValue(double val){ _value = val;};
    private:
        double _value;
};

class Escalar: public Funcao{
    public:
        //constructors
        Escalar(){
            _value = 0;
            _f = nullptr;
        };
        Escalar(double val){
            _value = val;
            _f = nullptr;
        };
        Escalar(Funcao* f){
            _value = 1;
            _f = f;
        };

        Escalar(Funcao* f, double val){
            _value = val;
            _f = f;
        };
        ~Escalar(){};
        //operator
        double operator()(double x){
            double ret = x;
            if(_f != nullptr) ret = (*_f)(x);
            return this->_value * ret;
        };
        //getter to test
        double value(){return this->_value;};

    private:
        double _value;

};
class Potencial: public Funcao{
    public:
        Potencial(){
            _value = 1;
            _f = nullptr ;
        };
        Potencial(double val){
            _value = val;
            _f = nullptr;
        };
        Potencial(Funcao* f){
            _value = 1;
            _f = f;
        };
        Potencial(Funcao* f, double val){
            _value = val;
            _f = f;
        };
        //getter
        double value(){return _value;};

        //operator
        double operator()(double x){
            double ret = x;
            if(_f != nullptr) ret = (*_f)(x);
            return pow( ret , _value );
        };

    private:
        double _value;
};
class Exponencial: public Funcao{
    public:
        Exponencial(){
            _value = 1;
            _f = nullptr;
        };
        Exponencial(double val){
            _value = val;
            _f = nullptr;
        };
        Exponencial(Funcao* f){
            _value = 1;
            _f = f;
        };
        Exponencial(Funcao* f, double val){
            _value = val;
            _f = f;
        };
        ~Exponencial(){};
    double operator()(double x){
        double ret = x;
        if( _f != nullptr ) ret = (*_f)(x);
        return pow(_value,ret);
    };
    private:
        double _value;
};
class Seno: public Funcao{
    public:
        Seno(){
            _f = nullptr;
        };
        Seno(Funcao* f){
            _f = f;
        };
        ~Seno(){};
        //Operator
        double operator()(double x){
            double ret = x;
            if(_f != nullptr) ret = (*_f)(x);
            return sin(ret);
        };
};
class Coseno: public Funcao{
    public:
        Coseno(){
            _f = nullptr;
        };
        Coseno(Funcao* f){
            _f = f;
        }
        ~Coseno(){};
        double operator()(double x){
            double ret = x;
            if(_f != nullptr) ret = (*_f)(x);
            return cos(ret*PI/180);
        };

};
class FuncaoAgregada: public Funcao{
    public:
        //Constructors
        FuncaoAgregada(){
            _f = nullptr;
            _funcao.push_back(nullptr);
        };
        ~FuncaoAgregada(){};
        //methods
        void agrega(Funcao* f){
            _funcao.push_back(f);
        };
        double operator()(double x){
            double ret = 0;
            for(std::vector<Funcao*>::iterator it = _funcao.begin(); it < _funcao.end(); it++){
                if((*it) != nullptr) ret += (**it)(x);
            }
            return ret;
        };
    private:
        std::vector<Funcao*> _funcao;
};
void teste(){
    FuncaoAgregada f;
    Potencial g(2);
    FuncaoAgregada h;
    h.agrega(new Constante(-1));
    h.agrega(new Escalar(2));
    Seno i(&h);
    Escalar j(&i,5);
    f.agrega(&g);
    f.agrega(&j);
    f.agrega(new Constante(5));
    std::cout << "f(x) = x^2 + 5*sin(2x-1) + 5" << std::endl;
    double integral = f.integrar(&f,5,0,0.01);
    std::cout << "integral de f(x) = " << integral << std::endl;
};
#endif // MATHEUSTOMAZI_P2_H_INCLUDED
