#include "timsort.h"

int timsort::getMinRun(int n) {
    int mask = 0;
    while (n >= 64) {
        mask |= n & 1;
        n >>= 1;
    }
    return n + mask;
}//нахождение minrun

void timsort::insert(my_list &my_list) {
    for (int i = 1; i < my_list.get_size(); ++i)
        for (int j = i; j > 0 && my_list.element(j-1)->value >my_list.element(j)->value; --j)
            my_list.swap(j, j - 1);
}//сортировка вставками

Stack timsort::getRuns(my_list &my_list) {
    int size = my_list.get_size();
    int minRun = getMinRun(size);
    Stack sorted;

    for (int i = 0; i < size; ++i) {
        class my_list run;
        run.append(my_list.element(i)->value);
        // Сбор готовых runs
        if (my_list.element(i)->value <= my_list.element(i+1)->value) {
            // Восходящий
            while ((i < size - 1) && (my_list.element(i)->value <= my_list.element(i+1)->value))
                run.append(my_list.element(++i)->value);
        }
        //добавление элементов в список, если minrun не достигнут
        while ((i < size - 1) && (run.get_size() < minRun))
            run.append(my_list.element(++i)->value);

        insert(run);
        sorted.push(run);
    }

    return sorted;
}//нахождение run

int timsort::binarySearch(my_list& my_list, int key) {
    int left = 0;
    int right = (int) my_list.get_size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        struct list_element *midNode = my_list.element(mid);
        if (midNode->value == key) return mid;
        else if (midNode->value < key) left = mid + 1;
        else right = mid - 1;
    }

    return my_list.element(right)->value == key ? right : -1;
}//бинарный поиск

my_list timsort::merge(my_list &a, my_list &b) {
    // 7 элементов подряд - это меньше, чем b[i] -> сделать "скачущий галопом"
    const unsigned short N = 7;
    unsigned short consecutive = 0;
    bool isFromA = true;//был ли взят последний элемент из списка


    my_list result;
    struct list_element *aNode = a.element(0);
    struct list_element *bNode = b.element(0);

    while (aNode && bNode) {//пока в обоих списках есть элементы
        if (consecutive == N) {//запуск галопа
            consecutive = 0;
            if (isFromA) {
                int insertWhile = binarySearch(a, bNode->value);
                if (insertWhile < 0) continue;

                for (; aNode && aNode->value <= a.element(insertWhile)->value; aNode = aNode->next)
                    result.append(aNode->value);
                result.append(bNode->value);
                bNode = bNode->next;
            } else {
                int insertWhile = binarySearch(b, aNode->value);
                if (insertWhile < 0) continue;

                for (; bNode && bNode->value <= b.element(insertWhile)->value; bNode = bNode->next)
                    result.append(bNode->value);
                result.append(aNode->value);
                aNode = aNode->next;
            }
        } else {
            if (aNode->value <= bNode->value) {//обычное слияние
                if (isFromA) consecutive++;
                else {
                    consecutive = 1;
                    isFromA = true;
                }
                result.append(aNode->value);
                aNode = aNode->next;
            } else {
                if (!isFromA) consecutive++;
                else {
                    consecutive = 1;
                    isFromA = false;
                }
                result.append(bNode->value);
                bNode = bNode->next;
            }
        }
    }

    for (; aNode; aNode = aNode->next) result.append(aNode->value);
    for (; bNode; bNode = bNode->next) result.append(bNode->value);

    return result;
}//сортировка слиянием

void timsort::timSort(my_list &my_list) {
    if (my_list.get_size() <= 1) return; // Nothing to do

    Stack runs = getRuns(my_list);

    class my_list x = runs.pop();
    class my_list y = runs.pop();
    class my_list z = runs.pop();
    while (!runs.isEmpty()) {
        // X > Y + Z && Y > Z
        if ((x.get_size() > y.get_size() + z.get_size()) && (y > z)) {
            x = merge(y, x);
            y = z;
            z = runs.pop();
        } else {
            if (x < z) {
                x = merge(x, y);
                y = z;
                z = runs.pop();
            } else {
                y = merge(z, y);
                z = runs.pop();
            }
        }
    }

    if (!y.isEmpty()) x = merge(x, y);
    if (!z.isEmpty()) x = merge(x, z);

    my_list = x;
}//сортировка timsort