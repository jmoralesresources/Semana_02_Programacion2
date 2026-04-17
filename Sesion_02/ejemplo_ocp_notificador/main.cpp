#include <iostream>
#include <string>
using namespace std;

class Notificador {
public:
    virtual void enviar(const string& msg) = 0;
    virtual ~Notificador() = default;
};

class NotificadorConsola : public Notificador {
public:
    void enviar(const string& msg) override {
        cout << "[Consola] " << msg << endl;
    }
};

class NotificadorPrefijo : public Notificador {
    string prefijo;
    Notificador* base;
public:
    NotificadorPrefijo(const string& p, Notificador* b) : prefijo(p), base(b) {}
    void enviar(const string& msg) override {
        base->enviar(prefijo + msg);
    }
};

int main() {
    NotificadorConsola nc;
    NotificadorPrefijo np(">>> ", &nc);
    np.enviar("Hola");
    return 0;
}