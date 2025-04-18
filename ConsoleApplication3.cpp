#include <iostream>
#include <cmath>
#include <limits> // Для numeric_limits
#include <clocale>

using namespace std;

// Функция для вычисления длины отрезка по полярным координатам
double distancePolar(double r1, double angle1, double r2, double angle2) {
    // Разница углов в радианах
    double angleDiff = angle1 - angle2;

    // Расстояние
    double distance = sqrt(r1 * r1 + r2 * r2 - 2 * r1 * r2 * cos(angleDiff));

    return distance;
}

// Функция для безопасного ввода вещественного числа
double getValidDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cout << "Ошибка: некорректный ввод. Пожалуйста, введите число." << endl;
            cin.clear(); // Очищаем поток ошибок
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем остаток строки
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем остаток строки
            return value;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    double r1, angle1, r2, angle2, dist;

    // Ввод данных с проверкой
    cout << "----------------" << endl;
    cout << "Задание первое" << endl;
    r1 = getValidDouble("Введите r1: ");
    angle1 = getValidDouble("Введите angle1 (в радианах): ");
    r2 = getValidDouble("Введите r2: ");
    angle2 = getValidDouble("Введите angle2 (в радианах): ");

    // Вычисление расстояния
    dist = distancePolar(r1, angle1, r2, angle2);

    // Вывод результата
    cout << "Расстояние между точками: " << dist << endl;
    cout << "----------------";

    return 0;
}