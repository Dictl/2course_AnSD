#ifndef UN6_LAB2_TIMSORT_H
#define UN6_LAB2_TIMSORT_H
#include "my_list.h"
#include "Stack.h"


class timsort {
public:
    int getMinRun(int);
    void insert(my_list&);
    Stack getRuns(my_list&);
    my_list merge(my_list&, my_list&);
    int binarySearch(my_list&, int);
    void timSort(my_list&);
};


#endif //UN6_LAB2_TIMSORT_H
