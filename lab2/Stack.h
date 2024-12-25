#ifndef PRACTICE01_STACK_H
#define PRACTICE01_STACK_H

#include <forward_list>
#include <iostream>
#include "my_list.h"

class Stack {
private:
    std::forward_list<my_list> items;
    int size = 0;
public:
    // Operators
    friend std::ostream& operator<< (std::ostream&, const Stack&);

    // Methods
    void push(my_list&);
    my_list pop();
    my_list * top();
    [[nodiscard]] unsigned getSize() const;
    [[nodiscard]] bool isEmpty() const;
};


#endif //PRACTICE01_STACK_H
