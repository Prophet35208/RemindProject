#include <string>
#include <iostream>
#include "Reminder.h"

using namespace std;

void displayOptions() {
    cout << "1. Ввести новую дату\n";
    cout << "2. Показать ближайший день рождения\n";
    cout << "3. Вывести список всех дней рождения\n";
    cout << "4. Выйти из приложения\n";
    cout << "Выберите вариант: ";
}

int main()
{
    setlocale(LC_ALL, "Rus");

    Reminder rem;

    cout << "\t\tНапоминалка о днях рождения\n";
    int f = 1;
    int choice;
    string name;
    string date;
    string clear;
    while (f) {
        displayOptions();
        cin >> choice;
        cout << endl;
        getline(cin, clear);
        switch (choice)
        {
        case 1:
            cout << "Введите ФИО: ";
            getline(cin, name);
            cout << "Введите дату в формате dd.mm.yyyy: ";
            getline(cin, date);
            rem.addNewDate(name, date);
            cout << endl;
            break;
        case 2:
            cout << rem.getNearestDateMessage();
            cout << endl;
            cout << endl;
            break;
        case 3:
            //todo
            break;
        case 4:
            f = 0;
            break;
        default:
            break;
        }
    }

}

