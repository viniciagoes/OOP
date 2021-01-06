#include <iostream>
#include <cmath>    //biblioteca para o valor de PI

using namespace std;

class Figura{
   virtual double calcArea()=0;         //metodo virtual para que todas as classes tenham que sobreescrever
};

class Retangulo : public Figura{        //definicao da classe Retangulo, herança de Figura
protected:                              //protegidos para acesso somente por Retangulo e classes derivadas
    double ladoA;
    double ladoB;
public:
    Retangulo(double A, double B){      //contrutor da classe
        ladoA=A;
        ladoB=B;
    }
    double calcArea(){                  //calculo da area
        double x= ladoA * ladoB;
        return x;
    };
};

class Circulo : public Figura{          //definir classe circulo
    double raio;                        //atributos do circulo
public:
    Circulo(double r){                  //construtor do Circulo
        raio=r;
    }
    double calcArea(){                  //calculo da area
        double x;
        x = (raio * raio) * M_PI;       //uso da cmath
        return x;
    }
};

class Quadrado : public Retangulo{      //definicao da classe Quadrado, herda de Retangulo e, consequentemente, Figura
public:
    Quadrado(double L) : Retangulo(L,L){    //construtor do Quadrado
    }
    Quadrado operator*(Quadrado Q){         //sobrecarga do operador de multiplicacao *
        double Lado = this->ladoA * Q.ladoB;
        Quadrado q(Lado);
        return q;
    }
};

int main() {
    Retangulo R(2,3);
    Quadrado Q(7);
    Circulo C(2);
    cout << "Area R: " << R.calcArea() << endl;
    cout << "Area Q: " << Q.calcArea() << endl;
    cout << "Area C: " << C.calcArea() << endl;
    Quadrado Q2 = Q*Q;
    cout << "Area Q2: " << Q2.calcArea() << endl;
    return 0;
}