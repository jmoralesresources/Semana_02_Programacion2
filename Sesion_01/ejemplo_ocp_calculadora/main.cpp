#include <iostream>
using namespace std;

class IOperacion {
public:
    virtual double calcular(double a, double b) const = 0;
    virtual ~IOperacion() = default;
};

class Suma : public IOperacion {
public:
    double calcular(double a, double b) const override { return a + b; }
};

class Resta : public IOperacion {
public:
    double calcular(double a, double b) const override { return a - b; }
};

class Calculadora {
    const IOperacion* op;
public:
    void setOperacion(const IOperacion* operacion) { op = operacion; }
    double ejecutar(double a, double b) const {
        return op ? op->calcular(a, b) : 0;
    }
};

int main() {
    Calculadora calc;
    Suma s;
    Resta r;
    calc.setOperacion(&s);
    cout << "10 + 5 = " << calc.ejecutar(10, 5) << endl;
    calc.setOperacion(&r);
    cout << "10 - 5 = " << calc.ejecutar(10, 5) << endl;
    return 0;
}