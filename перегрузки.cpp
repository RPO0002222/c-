#include <iostream>
using namespace std;

class IntegerSet {
private:
    int* elements; // динамический массив 
    size_t size;   // текущий размер множества
    size_t capacity; // вместимость массива

    // метод для увеличения размера массива
    void resize(size_t newCapacity) {
        int* newElements = new int[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
    }

public:
    // конструктор по умолчанию
    IntegerSet() : elements(nullptr), size(0), capacity(0) {}

    // конструктор с параметрами
    IntegerSet(const int* arr, size_t n) : size(0), capacity(n) {
        elements = new int[capacity];
        for (size_t i = 0; i < n; ++i) {
            add(arr[i]); // добавляем элементы, исключая дублекаты
        }
    }

    // конструктор копирования
    IntegerSet(const IntegerSet& other) : size(other.size), capacity(other.capacity) {
        elements = new int[capacity];
        for (size_t i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }

    // деструктор
    ~IntegerSet() {
        delete[] elements;
    }

    // проверка принадлежности элемента множеству
    bool contains(int value) const {
        for (size_t i = 0; i < size; ++i) {
            if (elements[i] == value) {
                return true;
            }
        }
        return false;
    }

    // добавление элемента в множество
    void add(int value) {
        if (!contains(value)) {
            if (size >= capacity) {
                resize(capacity == 0 ? 1 : capacity * 2); // увеличиваем размер
            }
            elements[size++] = value;
        }
    }

    // перегрузка добавления
    IntegerSet& operator+=(int value) {
        add(value);
        return *this;
    }

    // перегрузка объединения двух множеств
    IntegerSet operator+(const IntegerSet& other) const {
        IntegerSet result;
        for (size_t i = 0; i < size; ++i) {
            result.add(elements[i]);
        }
        for (size_t i = 0; i < other.size; ++i) {
            result.add(other.elements[i]);
        }
        return result;
    }

    // перегрузка объединения с присваиванием
    IntegerSet& operator+=(const IntegerSet& other) {
        for (size_t i = 0; i < other.size; ++i) {
            add(other.elements[i]);
        }
        return *this;
    }

    // перегрузка элемента
    void remove(int value) {
        for (size_t i = 0; i < size; ++i) {
            if (elements[i] == value) {
                elements[i] = elements[size - 1]; 
                --size;
                return;
            }
        }
    }

    // перегрузка удаления
    IntegerSet& operator-=(int value) {
        remove(value);
        return *this;
    }

    // перегрузка разности множеств
    IntegerSet operator-(const IntegerSet& other) const {
        IntegerSet result;
        for (size_t i = 0; i < size; ++i) {
            if (!other.contains(elements[i])) {
                result.add(elements[i]);
            }
        }
        return result;
    }

    // перегрузка пересечения множеств
    IntegerSet operator*(const IntegerSet& other) const {
        IntegerSet result;

        for (size_t i = 0; i < size; ++i) {
            if (other.contains(elements[i])) {
                result.add(elements[i]);
            }
        }
        return result;
    }

    // перегрузка присваивания
    IntegerSet& operator=(const IntegerSet& other) {
        if (this != &other) {
            delete[] elements; 
            size = other.size;
            capacity = other.capacity;
            elements = new int[capacity];
            for (size_t i = 0; i < size; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    // перегрузка сравнения множеств
    bool operator==(const IntegerSet& other) const {
        if (size != other.size) return false;
        for (size_t i = 0; i < size; ++i) {
            if (!other.contains(elements[i])) {
                return false;
            }
        }
        return true;
    }

    // перегрузка вывода
    friend ostream& operator<<(ostream& os, const IntegerSet& s) {
        os << "{ ";
        for (size_t i = 0; i < s.size; ++i) {
            os << s.elements[i] << (i < s.size - 1 ? ", " : "");
        }
        os << " }";
        return os;
    }

    // перегрузка ввода
    friend istream& operator>>(istream& is, IntegerSet& s) {
        int value;
        while (is >> value) {
            s.add(value);
        }
        return is;
    }
};

int main() 
{
    setlocale(LC_ALL, "Russian");

    IntegerSet set1;
    set1 += 1;
    set1 += 2;
    set1 += 3;
    cout << "Множество 1: " << set1 << endl;

    IntegerSet set2;
    set2 += 2;
    set2 += 3;
    set2 += 4;
    cout << "Множество 2: " << set2 << endl;

    IntegerSet unionSet = set1 + set2;
    cout << "Объединение множеств: " << unionSet << endl;

    IntegerSet intersectionSet = set1 * set2;
    cout << "Пересечение множеств: " << intersectionSet << endl;

    IntegerSet differenceSet = set1 - set2;
    cout << "Разность множеств (set1 - set2): " << differenceSet << endl;

    set1 -= 3;
    cout << "Множество 1 после удаления 3: " << set1 << endl;

    cout << "Текущие элементы множества 2: ";
    cin >> set2; 
    cout << "Обновленное множество 2: " << set2 << endl;

    return 0;
}
