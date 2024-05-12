/*Створити клас Triangle з полями-сторонами. Визначити методи зміни сторін, 
обчислення кутів, обчислення периметра. Створити похідний клас Equilateral 
(рівносторонній), що має поле площі. Визначити метод обчислення площі.
*/

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Triangle {
protected:
    double side1, side2, side3;

public:
    // Конструктор класу Triangle
    Triangle(double side1, double side2, double side3) {
        // Перевіряємо умову існування трикутника
        if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
            this->side1 = side1;
            this->side2 = side2;
            this->side3 = side3;
        }
        else {
            cout << "Triangle not exists" << endl;
            exit(1); // Завершуємо програму з кодом помилки
        }
    }


    // Методи для зміни сторін
    void setSides(double s1, double s2, double s3) {
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }

    // Метод для обчислення периметра
    double perimeter() const {
        return side1 + side2 + side3;
    }


    // Метод для обчислення кутів (використовуючи закон косинусів)
    void calculateAngles(double& angle1, double& angle2, double& angle3) const {
        angle1 = acos((side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3))*180.0/M_PI;
        angle2 = acos((side1 * side1 + side3 * side3 - side2 * side2) / (2 * side1 * side3))*180.0/M_PI;
        angle3 = 180.0 - angle1 - angle2;

    }

};

class Equilateral : public Triangle {
private:
    double area;

public:
    // Конструктор
    Equilateral(double side) : Triangle(side, side, side) {
        // Обчислення площі рівностороннього трикутника
        double s = (side1 + side2 + side3) / 2;
        area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    // Метод для отримання площі
    double getArea() const {
        return area;
    }
};

//завдання2

class Triad {
private:
    int first, second, third;

public:
    Triad(int f, int s, int t) : first(f), second(s), third(t) {}

    void increaseFieldsByOne() {
        first++;
        second++;
        third++;
    }
    int getFirst() const { return first; }
    int getSecond() const { return second; }
    int getThird() const { return third; }


    void display() {
        std::cout << "Triad: (" << first << ", " << second << ", " << third << ")" << std::endl;
    }
};

class Date {
private:
    int year, month, day;
    Triad triad;

public:
    Date(int y, int m, int d) : year(y), month(m), day(d), triad(y, m, d) {}

    void increaseFieldsByOne() {
        triad.increaseFieldsByOne();
        year = triad.getFirst();
        month = triad.getSecond();
        day = triad.getThird();
    }

    void increaseDateByPDays(int p) {
        for (int i = 0; i < p; ++i) {
            triad.increaseFieldsByOne();
        }
        year = triad.getFirst();
        month = triad.getSecond();
        day = triad.getThird();
    }

    void display() {
        std::cout << "Date: " << year << "/" << month << "/" << day << std::endl;
    }
};

//завдання 3

class Triad1 {
protected:
    int a, b, c;
public:
    Triad1(int a, int b, int c) : a(a), b(b), c(c) {}
    //конструктор копіювання
    Triad1(const Triad1& other) : a(other.a), b(other.b), c(other.c) {}
    // Конструктор перенесення
    Triad1(Triad1&& other) noexcept : a(other.a), b(other.b), c(other.c) {}

    void increase() {
        a++;
        b++;
        c++;
    }

    void display() {
        std::cout << a << ", " << b << ", " << c << std::endl;
    }
};

class Date1 : public Triad1 {
public:
    Date1(int year, int month, int day) : Triad1(year, month, day) {}
    //конструктор копіювання
    Date1(const Date1& other) : Triad1(other) {}
    // Конструктор перенесення
    Date1(Date1&& other) noexcept : Triad1(std::move(other)) {}
    void increase() {
        if (b == 12 && c == 31) {
            a++;
            b = 1;
            c = 1;
        }
        else if (c == 31) {
            b++;
            c = 1;
        }
        else {
            c++;
        }
    }

    void increaseBy(int days) {
        for (int i = 0; i < days; ++i) {
            increase();
        }
    }
    void display() {
        std::cout << a << "-" << b << "-" << c << std::endl;
    }

    Date1& operator=(const Date1& other) {
        if (this != &other) {
            a = other.a;
            b = other.b;
            c = other.c;
        }
        return *this;
    }

    Date1& operator=(Date1&& other) noexcept {
        if (this != &other) {
            a = std::move(other.a);
            b = std::move(other.b);
            c = std::move(other.c);
        }
        return *this;
    }

    bool operator==(const Date1& other) {
        return a == other.a && b == other.b && c == other.c;
    }

    bool operator!=(const Date1& other) {
        return !(*this == other);
    }
};

void Task1() {
    // Приклад використання класів
    Triangle triangle(5, 5, 3);

    cout << "Triangle:" << endl;
    cout << "Perimeter: " << triangle.perimeter() << endl;

    double angle11, angle22, angle33;
    triangle.calculateAngles(angle11, angle22, angle33);
    cout << "Angles: " << angle11 << ", " << angle22 << ", " << angle33 << endl;

    Equilateral equilateralTriangle(5.0);

    cout << "Equilateral Triangle:" << endl;
    cout << "Perimeter: " << equilateralTriangle.perimeter() << endl;
    cout << "Area: " << equilateralTriangle.getArea() << endl;

    double angle1, angle2, angle3;
    equilateralTriangle.calculateAngles(angle1, angle2, angle3);
    cout << "Angles: " << angle1 << ", " << angle2 << ", " << angle3 << endl;
}

void Task2() {
    Triad triad(1, 2, 3);
    triad.display();
    triad.increaseFieldsByOne();
    triad.display();

    Date date(2024, 5, 12);
    date.display();
    date.increaseFieldsByOne(); // Increase date by one day
    date.display();
    date.increaseDateByPDays(5); // Increase date by 5 days
    date.display();
}

void Task3() {
    Triad1 triad(1, 2, 3);
    std::cout << "Triad before increase: ";
    triad.display();
    triad.increase();
    std::cout << "Triad after increase: ";
    triad.display();

    Date1 date(2023, 12, 30);
    std::cout << "Date before increase: ";
    date.display();
    date.increase();
    std::cout << "Date after increase: ";
    date.display();
    date.increaseBy(5);
    std::cout << "Date after increasing by 5 days: ";
    date.display();

    Date1 dateCopy = date;
    std::cout << "Copied date: ";
    dateCopy.display();
    Date1 dateTransfer(2024, 1, 1);
    dateTransfer = std::move(date);
    std::cout << "Transferred date: ";
    date.display();
    std::cout << "Original date: ";
    dateTransfer.display();

    std::cout << "Dates are equal: " << (date == dateCopy) << std::endl;
    std::cout << "Dates are not equal: " << (date != dateTransfer) << std::endl;

}

int main() {
    int choice;

    cout << "Choose task(1, 2, 3):\n";
    cin >> choice;

    switch (choice) {
    case 1:
        Task1();
        break;
    case 2:
        Task2();
        break;
    case 3:
        Task3();
        break;
    default:
        cout << "Wrong choice!\n";
        break;
    }

    return 0;
}





































