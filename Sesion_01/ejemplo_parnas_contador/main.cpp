#include <iostream>
using namespace std;

class Contador {
    int valor;
    int limite;
public:
    Contador(int lim = 100) : valor(0), limite(lim) {}
    void incrementar() {
        if (valor < limite) valor++;
    }
    int leer() const { return valor; }
    void reiniciar() { valor = 0; }
};

int main() {
    Contador c(10);
    for (int i = 0; i < 5; i++) c.incrementar();
    cout << "Valor: " << c.leer() << endl;
    c.reiniciar();
    cout << "Despues de reiniciar: " << c.leer() << endl;
    return 0;
}