#ifndef UNTITLED6_MY_LIST_H
#define UNTITLED6_MY_LIST_H


#include <string>

struct list_element {
    struct list_element *next = nullptr;
    struct list_element *prev = nullptr;
    int value = 0;

};

class my_list {
private:
    list_element *first = nullptr;
    int size = 0;
    list_element * element(int);

public:
    void append(int);
    void add(int, int);
    std::string print();
    void del(int);
    ~my_list();
    void clear();
};

#endif //UNTITLED6_MY_LIST_H
