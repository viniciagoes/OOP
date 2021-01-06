#include <iostream>
#include <cmath>

using namespace std;

class Ponto{
    double X, Y;                        //X e Y
    public:                             //Metodos Publicos
    Ponto(double x, double y){          //Construtor
        X=x;
        Y=y;
    }
    double getX(){                      //getter para X
        return X;
    }
    double getY(){                                      //getter para Y
        return Y;
    }
    double distanciaParaPonto(Ponto P){                 //distancia para P
        double distancia = sqrt(((X-P.getX())*(X-P.getX()))+((Y-P.getY())*(Y-P.getY())));
        return distancia;
    }
};

class Reta{
    double A, B, C;                     //variáveis da reta Ax+By+C=0
    public:                             //métodos publicos
    Reta(Ponto p1, Ponto p2){           //construtor da reta, fazendo as operações necessárias em A,B e C
        A=(p1.getY())-(p2.getY());
        B=(p2.getX())-(p1.getX());
        C=((p1.getX())*(p2.getY()))-((p2.getX())*(p1.getY()));
    }
    double getA(){                      //getters
        return A;
    }
    double getB(){
        return B;
    }
    double getC(){
        return C;
    }
    double distanciaParaPonto(Ponto P){                     //distância da reta para o ponto, fazendo as operações necessárias
        double numerador=(A*P.getX())+(B*P.getY())+C;
        double denominador = sqrt((A*A)+(B*B));
        numerador = abs(numerador);
        double distancia = numerador/denominador;
        return distancia;
    }
};

int main() {
    int x1, y1, x2, y2, x3, y3;         //declaração das coordenadas dos pontos
    cout << "Ponto A>";                 //fase de scan das coordenadas
    cin >> x1 >> y1;
    Ponto P1(x1,y1);

    cout << "Ponto B>";
    cin >> x2 >> y2;
    Ponto P2(x2,y2);

    cout << "Ponto C>";
    cin >> x3 >> y3;
    Ponto P3(x3,y3);

    cout << "Distancia AB = " << P1.distanciaParaPonto(P2) << endl;                                 //Distância entre pontos A e B
    Reta R(P1,P2);                                                                                  //Declaração da reta
    cout << "R: " << R.getA() << "x + " << R.getB() << "y + " << R.getC() << " = 0" << endl;        //Imprimir a reta
    cout << "Distancia RC = " << R.distanciaParaPonto(P3);                                          //Distância da reta ao ponto
    return 0;
}