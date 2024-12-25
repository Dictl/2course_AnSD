#include "my_list.h"

my_list::~my_list() {
    clear();
    delete first;
}//деструктор класса my_list

void my_list::clear() {
    while (first) {
        list_element *t = first;
        first= t->next;
        delete t;
    }
    first = nullptr;
    size=0;
}//очистка списка

list_element *my_list::element(int index) {
    list_element *t = first;
    for (int i = 0; i < size; i++) {
        if (index == i) {
            return t;
        }
        t = t->next;
    }
    return nullptr;
}//переход к нужному элементу списка по индексу

void my_list::add(int index, int value) {
    list_element *t = first;
    auto *newEl = new list_element;
    if (index > size) {
        return;
    }
    if (index == size) {
        append(value);
        return;
    }
    switch (size) {
        case 0:
            first = newEl;
            newEl->value = value;
            size++;
            break;
        default:
            t = element(index);
            if (t == nullptr) return;
            if (t->prev == nullptr) {
                first = newEl;
                t->prev = newEl;
                newEl->next = t;
                newEl->value = value;
            } else {
                newEl->prev = t->prev;
                t->prev->next = newEl;
                t->prev = newEl;
                newEl->next = t;
                newEl->value = value;
            }
            size++;
            break;
    }

}//добавление элемента к списку по индексу

void my_list::append(int value) {
    list_element *m = new list_element;
    if (size == 0) {
        first = m;
        first->value = value;

    } else {
        if (size == 1) {
            first->next = m;
            m->prev = first;
            m->value = value;
        } else {
            list_element *k;
            for (list_element *t = first; t->next != nullptr; t = t->next) {
                k = t;
            }
            k = k->next;
            m->prev = k;
            k->next = m;
            m->value = value;
        }
    }
    size++;
}//добавление элемента в конец списка

std::string my_list::print() {
    if (size == 0) {
        return "0";
    }
    if (size == 1) {
        return std::to_string(first->value);
    } else {
        std::string str ;
        list_element *t = first;
        for (int i = 0; i < size; i++) {
            str += std::to_string(t->value);
            str += " ";
            t = t->next;
        }
        return str;
    }
}//вывод списка

void my_list::del(int index) {
    list_element *t = first;
    if (index >= size) {
        return;
    }
    switch (size) {
        case 0:
            break;
        case 1:
            first->next = nullptr;
            first->prev = nullptr;
            size--;
            delete t;
            break;
        default:
            t = element(index);
            if (t == nullptr) return;//неверный ввод
            if (t->next == nullptr) {
                t->prev->next == nullptr;
            } else if (t->prev == nullptr) {
                t->next->prev == nullptr;
            } else {
                t->prev->next = t->next;
                t->next->prev = t->prev;
            };
            delete t;
            size--;
            break;
    }

}//удаление элемента по индексу

