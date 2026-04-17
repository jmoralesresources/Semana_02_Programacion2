#include <iostream>
using namespace std;

class IFigura {
public:
    virtual double area() const = 0;
    virtual ~IFigura() = default;
};

class Circulo : public IFigura {
    double r;
public:
    Circulo(double radio) : r(radio) {}
    double area() const override { return 3.14159 * r * r; }
};

double areaTotal(const IFigura* f1, const IFigura* f2) {
    return f1->area() + f2->area();
}

int main() {
    Circulo c(1.0), c2(2.0);
    cout << "Area total: " << areaTotal(&c, &c2) << endl;
    return 0;
}