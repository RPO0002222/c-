#include <iostream>

using namespace std;

class Circle {
private:
    double radius; 

public:
    // конструктор
    Circle(double r) : radius(r) {}
    //диструкотр 
    ~Circle() {}

    // перегрузка  ==
    bool operator==(const Circle& other) const {
        return radius == other.radius;
    }

    // перегрузка  >
    bool operator>(const Circle& other) const {
        return radius > other.radius;
    }

    // перегрузка  +=
    Circle& operator+=(double value) {
        radius += value;
        return *this;
    }

    // перегрузка  -=
    Circle& operator-=(double value) {
        radius -= value;
        return *this;
    }

    // вывод информации
    friend ostream& operator<<(ostream& os, const Circle& c) {
        os << "Окружность с радиусом: " << c.radius;
        return os;
    }
};

int main() {
    Circle c1(5.0);
    Circle c2(5.0);
    Circle c3(10.0);

    // проверка на равенство
    cout << "c1 и c2 " << (c1 == c2 ? "равны" : "не равны") << endl;
    // проверка >
    cout << "c3 > c1: " << (c3 > c1 ? "да" : "нет") << endl;

    // изменение радиуса
    c1 += 3.0;
    c2 -= 2.0;
    cout << c1 << endl;
    cout << c2 << endl;

    return 0;
}
