#include "stack.h"
#include <iostream>


std::ostream& operator<< (std::ostream& os, const Stack& stack) {
    for (my_list it : stack.items)
        std::cout << it.print() << "; ";
    return os;
}//перегрузка вывода

void Stack::push(my_list &my_list) {
    items.push_front(my_list);
    size++;
}//Добавление элементов в стек

my_list Stack::pop() {
    my_list list1;
    if (isEmpty()) return list1;
    my_list list = items.front();
    items.pop_front();
    size--;
    return list;
}//удаление и возвращение значения вершины стека

my_list * Stack::top() {
    if (isEmpty()) return nullptr;
    return &items.front();
}//возвращаем верхний элемент

unsigned Stack::getSize() const {
    return size;
}//передача приватного size

bool Stack::isEmpty() const {
    return items.empty();
}//проверка на пустоту