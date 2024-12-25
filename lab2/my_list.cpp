#include "my_list.h"

my_list::~my_list() {
    clear();
}//деструктор класса my_list

void my_list::clear() {
    while (first) {
        list_element *t = first;
        first= t->next;
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
}//переход кнужному элементу по индексу

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

}//добавление элемента в список по индексу

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

}//удаление элемента списка по индексу

int my_list::get_size() const {
    return size;
}//передача приватого size

void my_list::swap(int index1, int index2) {
    list_element *t1;
    list_element *t2;
    int time_t;
    if(size==0 || size==1 || (index1==index2)) return;
    t1 = element(index1);
    t2 = element(index2);
        time_t=t1->value;
        t1->value=t2->value;
        t2->value=time_t;
}//пермена значений двух элементов списка

void my_list::reverse() {
    list_element *t = element(size-1);
    list_element *current = first;
    list_element *prev = nullptr;
    list_element *next;

    // Swap pointers
    while (current) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    first = t;
}//обратный вывод списка

bool my_list::operator> (const my_list &list) const {
    return size > list.get_size();
}//оператор сравнения

bool my_list::operator< (const my_list &list) const {
    return size < list.get_size();
}//оператор сравнения

bool my_list::isEmpty() const {
    return size == 0;
}//проверка на пустоту
