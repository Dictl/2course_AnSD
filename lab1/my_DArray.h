#ifndef UNTITLED6_MY_DARRAY_H
#define UNTITLED6_MY_DARRAY_H
#include <string>


class my_DArray {
private:
    unsigned int  size = 0;
    unsigned int capacity = 10;
    int * array = new int[capacity];
public:
    my_DArray();
    explicit my_DArray(unsigned int size, int value = 0);
    explicit my_DArray(unsigned int, const int*);
    ~my_DArray();
    std::string print();
    void del(int);
    void add(int, int);
    void append(int);
    void clear();
};


#endif //UNTITLED6_MY_DARRAY_H
