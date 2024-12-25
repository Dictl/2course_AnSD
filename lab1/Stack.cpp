#include "stack.h"

#include <iostream>


std::ostream& operator<< (std::ostream& os, const Stack& stack) {
    for (const auto& it : stack.items)//проходим по каждому элементу
        std::cout << it << ' ';
    return os;
}//оператор перегрузки вывода

void Stack::push(std::string &value) {
    items.push_front(value);
    size++;
}//добавление элементов в стек

std::string Stack::pop() {
    if (isEmpty()) return "";
    std::string item = items.front();
    items.pop_front();
    size--;
    return item;
}//удаление и возвращение верхнего элемента стека

std::string * Stack::top() {
    if (isEmpty()) return nullptr;
    return &items.front();
}//получение указателя на вершину стека

unsigned Stack::getSize() const {
    return size;
}//передыёт приватное значение size

bool Stack::isEmpty() const {
    return items.empty();
}//проверка на пустоту стека