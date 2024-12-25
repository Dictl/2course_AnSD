#include <iostream>
#include "my_list.h"
#include "my_DArray.h"
#include <string>
#include <limits>
#include "Stack.h"
#include <vector>
#include <iomanip>
#include "sort_algoritm.h"

using namespace std;
my_list l_object;
int l_value, l_n, l_index, point;
my_DArray arr_object;
int arr_value, arr_size, arr_index;
Stack s_object;

int Input() {
    int userInput;
    while (!(cin >> userInput) || userInput < -2147483648 || userInput > 2147483648 || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ты не ёжик - читать умеешь. ВВеди число нормальное" << endl;
    }
    cout << "Вы ввели: " << userInput << endl;

    return userInput;
}

bool list_menu() {
    string m = "1)Создать список \n2)Удалить узел списка \n3)Добавить узел списка \n4)Вывод списка \n5)Добавить узел в конец \n0)Выход \n";
    cout << m;
    cout << "Выберите пункт" << endl;
    point=Input();
    switch (point) {
        case 1:
            cout << "Введите количество элементов" << endl;
            l_n=Input();
            cout << "Введите элементы через enter" << endl;
            l_object.clear();
            for (int i = 0; i < l_n; i++) {
                l_value=Input();
                l_object.append(l_value);
            }
            system("pause");
            break;
        case 2:
            cout << "Введите индекс узла для удаления'" << endl;
            l_index=Input();
            l_object.del(l_index);
            cout << l_object.print();
            system("pause");
            break;
        case 3:
            cout << "Введите индекс узла для добавления'" << endl;
            l_index=Input();
            cout << "Введите значение узла'" << endl;
            l_n=Input();
            l_object.add(l_index, l_n);
            cout << l_object.print();
            system("pause");
            break;
        case 4:
            cout << l_object.print();
            system("pause");
            break;
        case 5:
            cout << "Введите значение узла" << endl;
            l_value=Input();
            l_object.append(l_value);
            system("pause");
            break;
        case 0:
            l_object.~my_list();
            return false;
    }
    return true;
}

bool array_menu() {
    string m = "1)Создать динамический массив \n2)Удалить элемент \n3)Добавить элемент \n4)Вывод массива \n5)Добавить элемент в конец \n0)Выход \n";
    cout << m;
    cout << "Выберите пункт" << endl;
    point=Input();
    switch (point) {
        case 1:
            arr_object.clear();
            cout << "Введите размер массива" << endl;
            arr_size=Input();
            cout << "Введите элементы через пробел" << endl;
            for (int i = 0; i < arr_size; i++) {
                arr_value=Input();
                arr_object.append(arr_value);
            }
            system("pause");
            break;
        case 2:
            cout<<"Введите индекс для удаления элемента массива"<<endl;
            arr_index=Input();
            arr_object.del(arr_index);
            cout<<arr_object.print();
            cout<<endl;
            system("pause");
            break;
        case 3:
            cout<<"Введите индекс для добавления элемента массива"<<endl;
            arr_index=Input();
            cout<<"Введите значение элемента массива"<<endl;
            arr_value=Input();
            arr_object.add(arr_index, arr_value);
            system("pause");
            break;
        case 4:
            cout<<arr_object.print();
            cout<<endl;
            system("pause");
            break;
        case 5:
            cout<<"Введите значение элемента массива"<<endl;
            arr_value=Input();
            arr_object.append(arr_value);
            cout<<arr_object.print();
            cout<<endl;
            system("pause");
            break;
        case 0:
            arr_object.~my_DArray();
            return false;
    }
    return true;

}

bool stack_menu(){
    std::string input;
    string m = "1)Создать стек \n2)Удалить элемент \n3)Вывод стека \n0)Выход \n";
    cout << m;
    cout << "Выберите пункт" << endl;
    point=Input();
    switch (point) {
        case 1:
            std::cout << "<< Введите строку для отталкивания:\n>> ";
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            getline (std::cin, input);
            s_object.push(input);
            std::cout << "Обновленный стек: " << s_object << std::endl;
            system("pause");
            break;
        case 2:
            std::cout << s_object.pop() << std::endl;
            std::cout << "Обновленный стек: " << s_object << std::endl;
            system("pause");
            break;
        case 3:
            std::cout << s_object << " (размер = " << s_object.getSize() << ")\n";
            system("pause");
            break;
        case 0:
            return false;
    }
    return true;
}

int executeRPN() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true) {
        try {
            system("cls");
            std::cout << "<< Введите выражение ['0' - выход]\n>> ";
            std::string expr;
            std::getline(std::cin, expr);

            if (expr == "0")
                break;

            std::vector<std::string> rpn = toRPN(expr);
            double rpnAnswer = evaluate(rpn);

            std::cout << std::setw(64) << std::setfill('-') << ' ' << std::setfill(' ');
            std::cout << "\n Ввод: " << expr << "\n RPN: ";
            for (auto &token : rpn) std::cout << token << ' ';
            std::cout << "\nОтвет: " << rpnAnswer << std::endl;
        }
        catch (std::invalid_argument& e) { std::cerr << "Недопустимый аргумент. " << e.what() << std::endl; }
        catch (std::runtime_error& e) { std::cerr << "Runtime error. " << e.what() << std::endl; }
        system("pause");
    }

    return 0;
}

bool basic_menu() {
    bool q = true;
    string m = "1)Двухсвязный список \n2)Динамический массив \n3)Стек \n4)Алгоритм сортировочноый станции \n0)Выход \n";
    cout << m;
    cout << "Выберите пункт" << endl;
    point=Input();
    switch (point) {
        case 1 :
            while (q) {
                system("cls");
                q = list_menu();
            }
            break;
        case 2:
            while (q) {
                system("cls");
                q = array_menu();
            }
            break;
        case 3:
            while (q) {
                system("cls");
                q = stack_menu();
            }
            break;
        case 4:
            system("cls");
            executeRPN();
            system("pause");
            break;
        case 0:
            return false;

    }
    return true;
};

int main() {
    bool q = true;
    while (q) {
        system("cls");
        q = basic_menu();
    }
}