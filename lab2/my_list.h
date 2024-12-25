#ifndef UNTITLED6_MY_LIST_H
#define UNTITLED6_MY_LIST_H


#include <string>

struct list_element {
    int value = 0;
    struct list_element *next = nullptr;
    struct list_element *prev = nullptr;

};

class my_list {
private:
    list_element *first = nullptr;
    int size = 0;

public:
    list_element * element(int);
    void append(int);
    void add(int, int);
    std::string print();
    void del(int);
    ~my_list();
    void clear();
    int get_size() const;
    void swap(int, int);
    void reverse();
    bool operator> (const my_list &list) const;
    bool operator< (const my_list &list) const;
    bool isEmpty() const;
};

#endif //UNTITLED6_MY_LIST_H
