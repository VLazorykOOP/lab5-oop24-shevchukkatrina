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





































