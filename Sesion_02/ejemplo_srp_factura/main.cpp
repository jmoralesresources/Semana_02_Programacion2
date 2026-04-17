#include <iostream>
#include <string>
using namespace std;

class CalculadorPrecio {
public:
    double totalConIVA(double subtotal, double iva = 0.13) const {
        return subtotal * (1 + iva);
    }
};

class ImpresorFactura {
public:
    void imprimir(const string& cliente, double total) const {
        cout << "Cliente: " << cliente << ", Total: " << total << endl;
    }
};

int main() {
    CalculadorPrecio calc;
    ImpresorFactura imp;
    double total = calc.totalConIVA(100.0);
    imp.imprimir("Juan", total);
    return 0;
}