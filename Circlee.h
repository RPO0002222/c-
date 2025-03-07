#include <iostream>

using namespace std;

class Circle {
private:
    double radius; 

public:
    // �����������
    Circle(double r) : radius(r) {}
    //���������� 
    ~Circle() {}

    // ����������  ==
    bool operator==(const Circle& other) const {
        return radius == other.radius;
    }

    // ����������  >
    bool operator>(const Circle& other) const {
        return radius > other.radius;
    }

    // ����������  +=
    Circle& operator+=(double value) {
        radius += value;
        return *this;
    }

    // ����������  -=
    Circle& operator-=(double value) {
        radius -= value;
        return *this;
    }

    // ����� ����������
    friend ostream& operator<<(ostream& os, const Circle& c) {
        os << "���������� � ��������: " << c.radius;
        return os;
    }
};

int main() {
    Circle c1(5.0);
    Circle c2(5.0);
    Circle c3(10.0);

    // �������� �� ���������
    cout << "c1 � c2 " << (c1 == c2 ? "�����" : "�� �����") << endl;
    // �������� >
    cout << "c3 > c1: " << (c3 > c1 ? "��" : "���") << endl;

    // ��������� �������
    c1 += 3.0;
    c2 -= 2.0;
    cout << c1 << endl;
    cout << c2 << endl;

    return 0;
}
