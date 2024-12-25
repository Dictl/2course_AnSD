#include "my_DArray.h"

my_DArray::my_DArray() = default;

my_DArray::my_DArray(unsigned int size, int value) {
    capacity = size * 2;
    array = new int[capacity];
    for (unsigned i = 0; i < size; ++i)
        array[i] = value;
}//создание массива

my_DArray::my_DArray(unsigned int size, const int *values) {
    capacity = size * 2;
    array = new int[capacity];
    for (unsigned i = 0; i < size; ++i)
        array[i] = values[i];
}

my_DArray::~my_DArray() {
    delete[] array;
}//деструктор класса my_DArray

void my_DArray::clear(){
    delete array;
    size=0;
    int * array_2 = new int[capacity];
    array=array_2;
}//очистка массива

std::string my_DArray::print() {
    if (size == 0) {
        return "0";
    } else {
        std::string str;
        for (int i = 0; i < size; i++) {
            str += std::to_string(array[i]);
            str += " ";
        }
        return str;
    }
}//вывод массива

void my_DArray::del(int index) {
    if (index >= size) {
        return;
    }
    capacity = size * 2;
    int *array_2 = new int[capacity];
    switch (size) {
        case 0:
            break;
        default:
            int j=0;
            for (int i = 0; i < size-1; i++) {

                if (index == i) {
                    j++;
                }
                    array_2[i] = array[j];
                j++;
            }
            array = array_2;
            size--;
            break;
    }
}//удаление элемента в массиве по индексу

void my_DArray::append(int value) {
    if (size < capacity) {
        array[size] = value;
    } else {
        capacity = size * 2;
        int *array_2 = new int[capacity];
        for (int i = 0; i <= size; i++) {
            array_2[i] = array[i];
        }
        array_2[size] = value;
        array = array_2;

    }
    size++;
}//добавление элемента в конец массива

void my_DArray::add(int index, int value){
    if (index >= size) {
        return;
    }
    size++;
    capacity = size * 2;
    int *array_2 = new int[capacity];
    switch (size) {
        case 0:
            append(value);
            break;
        default:
            int j=0;
            for (int i = 0; i < size; i++) {

                if (index == i) {
                    array_2[i]=value;
                    i++;
                }
                array_2[i] = array[j];
                j++;
            }
            array = array_2;
            break;
    }
}//добавление элемента в массив по индексу