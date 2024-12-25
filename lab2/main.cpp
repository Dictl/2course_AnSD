#include <iostream>
#include <limits>
#include "my_list.h"
#include "timsort.h"

using namespace std;
my_list l_object;
timsort t_object;
int l_value, l_n, l_index, point;

int Input() {
    int userInput;
    while (!(cin >> userInput) || userInput < -2147483648 || userInput > 2147483648 || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ты не ёжик - читать умеешь. Введи число нормальное" << endl;
    }
    cout << "Вы ввели: " << userInput << endl;

    return userInput;
}

bool menu() {
    string m = "1)Сортивка \n2)Удалить элемент \n3)Добавить элемент \n4)Вывод списка \n0)Выход \n";
    cout << m;
    cout << "Выберите пункт" << endl;
    point = Input();
    switch (point) {
        case 1:
            t_object.timSort(l_object);
            cout << l_object.print();
            system("pause");
            break;
        case 2:
            cout << "Введите индекс узла для удаления'" << endl;
            l_index = Input();
            l_object.del(l_index);
            cout << l_object.print();
            system("pause");
            break;
        case 3:
            cout << "Введите индекс узла для добавления'" << endl;
            l_index = Input();
            cout << "Введите значение узла'" << endl;
            l_n = Input();
            l_object.add(l_index, l_n);
            cout << l_object.print();
            system("pause");
            break;
        case 4:
            cout << l_object.print();
            system("pause");
            break;
        case 0:
            return false;
    }
    return true;
}

int main() {
    int size, value;
    cout << "Введите размер списка" << endl;
    size = Input();
    cout << "Введите элементы  списка" << endl;
    l_object.clear();
    for (int i = 0; i < size; i++) {
        value = Input();
        l_object.append(value);
    }
    bool q = true;
    while (q) {
        system("cls");
        q = menu();
    }
}