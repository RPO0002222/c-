#include <iostream>
using namespace std;

class Student {
private:
    int fullName;
    int birthDate;
    int phone;
    int city;
    int country;
    int university;
    int universityCity;
    int universityCountry;
    int groupNumber;

public:
    //метод ввода
    void inputData() {
        cout << "Введите ФИО: ";
        getline(cin, fullName);
        
        cout << "Введите дату рождения: ";
        getline(cin, birthDate);
        
        cout << "Введите контактный телефон: ";
        getline(cin, phone);
        
        cout << "Введите город проживания: ";
        getline(cin, city);
        
        cout << "Введите страну проживания: ";
        getline(cin, country);
        
        cout << "Введите название учебного заведения: ";
        getline(cin, university);
        
        cout << "Введите город учебного заведения: ";
        getline(cin, universityCity);
        
        cout << "Введите страну учебного заведения: ";
        getline(cin, universityCountry);
        
        cout << "Введите номер группы: ";
        getline(cin, groupNumber);
    }

    //метод вывод 
    void displayData() const {
        cout << "\nДанные студента:\n";
        cout << "ФИО: " << fullName << endl;
        cout << "Дата рождения: " << birthDate << endl;
        cout << "Телефон: " << phone << endl;
        cout << "Город: " << city << endl;
        cout << "Страна: " << country << endl;
        cout << "Учебное заведение: " << university << endl;
        cout << "Город учебного заведения: " << universityCity << endl;
        cout << "Страна учебного заведения: " << universityCountry << endl;
        cout << "Номер группы: " << groupNumber << endl;
    }

    // Аксессоры (геттеры и сеттеры)
    
    int getFullName() const { return fullName; }
    void setFullName(const int &name) { fullName = name; }

    int getBirthDate() const { return birthDate; }
    void setBirthDate(const int &date) { birthDate = date; }

    int getPhone() const { return phone; }
    void setPhone(const int &phone) { this->phone = phone; }

    int getCity() const { return city; }
    void setCity(const int &city) { this->city = city; }

    int getCountry() const { return country; }
    void setCountry(const int &country) { this->country = country; }
    
    int getUniversity() const { return university; }
    void setUniversity(const int &university) { this->university = university; }
   
    int getUniversityCity() const { return universityCity; }
    void setUniversityCity(const int &city) { universityCity = city; }
   
    int getUniversityCountry() const { return universityCountry; }
    void setUniversityCountry(const int &country) { universityCountry = country; }
    
    int getGroupNumber() const { return groupNumber; }
    void setGroupNumber(const int &number) { groupNumber = number; }

};

int main() 
{
    setlocale(LC_ALL, "Russian");
    Student student;
    student.inputData();    
    student.displayData();  
    return 0;
}
