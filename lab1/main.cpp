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
        cout << "�� �� 񦨪 - ���� 㬥���. ����� �᫮ ��ଠ�쭮�" << endl;
    }
    cout << "�� �����: " << userInput << endl;

    return userInput;
}

bool list_menu() {
    string m = "1)������� ᯨ᮪ \n2)������� 㧥� ᯨ᪠ \n3)�������� 㧥� ᯨ᪠ \n4)�뢮� ᯨ᪠ \n5)�������� 㧥� � ����� \n0)��室 \n";
    cout << m;
    cout << "�롥�� �㭪�" << endl;
    point=Input();
    switch (point) {
        case 1:
            cout << "������ ������⢮ ����⮢" << endl;
            l_n=Input();
            cout << "������ ������ �१ enter" << endl;
            l_object.clear();
            for (int i = 0; i < l_n; i++) {
                l_value=Input();
                l_object.append(l_value);
            }
            system("pause");
            break;
        case 2:
            cout << "������ ������ 㧫� ��� 㤠�����'" << endl;
            l_index=Input();
            l_object.del(l_index);
            cout << l_object.print();
            system("pause");
            break;
        case 3:
            cout << "������ ������ 㧫� ��� ����������'" << endl;
            l_index=Input();
            cout << "������ ���祭�� 㧫�'" << endl;
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
            cout << "������ ���祭�� 㧫�" << endl;
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
    string m = "1)������� �������᪨� ���ᨢ \n2)������� ����� \n3)�������� ����� \n4)�뢮� ���ᨢ� \n5)�������� ����� � ����� \n0)��室 \n";
    cout << m;
    cout << "�롥�� �㭪�" << endl;
    point=Input();
    switch (point) {
        case 1:
            arr_object.clear();
            cout << "������ ࠧ��� ���ᨢ�" << endl;
            arr_size=Input();
            cout << "������ ������ �१ �஡��" << endl;
            for (int i = 0; i < arr_size; i++) {
                arr_value=Input();
                arr_object.append(arr_value);
            }
            system("pause");
            break;
        case 2:
            cout<<"������ ������ ��� 㤠����� ����� ���ᨢ�"<<endl;
            arr_index=Input();
            arr_object.del(arr_index);
            cout<<arr_object.print();
            cout<<endl;
            system("pause");
            break;
        case 3:
            cout<<"������ ������ ��� ���������� ����� ���ᨢ�"<<endl;
            arr_index=Input();
            cout<<"������ ���祭�� ����� ���ᨢ�"<<endl;
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
            cout<<"������ ���祭�� ����� ���ᨢ�"<<endl;
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
    string m = "1)������� �⥪ \n2)������� ����� \n3)�뢮� �⥪� \n0)��室 \n";
    cout << m;
    cout << "�롥�� �㭪�" << endl;
    point=Input();
    switch (point) {
        case 1:
            std::cout << "<< ������ ��ப� ��� ��⠫�������:\n>> ";
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            getline (std::cin, input);
            s_object.push(input);
            std::cout << "���������� �⥪: " << s_object << std::endl;
            system("pause");
            break;
        case 2:
            std::cout << s_object.pop() << std::endl;
            std::cout << "���������� �⥪: " << s_object << std::endl;
            system("pause");
            break;
        case 3:
            std::cout << s_object << " (ࠧ��� = " << s_object.getSize() << ")\n";
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
            std::cout << "<< ������ ��ࠦ���� ['0' - ��室]\n>> ";
            std::string expr;
            std::getline(std::cin, expr);

            if (expr == "0")
                break;

            std::vector<std::string> rpn = toRPN(expr);
            double rpnAnswer = evaluate(rpn);

            std::cout << std::setw(64) << std::setfill('-') << ' ' << std::setfill(' ');
            std::cout << "\n ����: " << expr << "\n RPN: ";
            for (auto &token : rpn) std::cout << token << ' ';
            std::cout << "\n�⢥�: " << rpnAnswer << std::endl;
        }
        catch (std::invalid_argument& e) { std::cerr << "�������⨬� ��㬥��. " << e.what() << std::endl; }
        catch (std::runtime_error& e) { std::cerr << "Runtime error. " << e.what() << std::endl; }
        system("pause");
    }

    return 0;
}

bool basic_menu() {
    bool q = true;
    string m = "1)�����吝� ᯨ᮪ \n2)�������᪨� ���ᨢ \n3)�⥪ \n4)������ ���஢�筮� �⠭樨 \n0)��室 \n";
    cout << m;
    cout << "�롥�� �㭪�" << endl;
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