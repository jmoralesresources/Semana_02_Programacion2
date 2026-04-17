#include <iostream>
using namespace std;

class Figura {
public:
    virtual double area() const = 0;
    virtual ~Figura() = default;
};

class Rectangulo : public Figura {
protected:
    double ancho, alto;
public:
    Rectangulo(double a, double h) : ancho(a), alto(h) {}
    double area() const override { return ancho * alto; }
};

class Cuadrado : public Rectangulo {
public:
    Cuadrado(double lado) : Rectangulo(lado, lado) {}
};

void imprimirArea(const Figura& f) {
    cout << "Area: " << f.area() << endl;
}

int main() {
    Rectangulo r(3, 4);
    Cuadrado q(5);
    imprimirArea(r);
    imprimirArea(q);
    return 0;
}