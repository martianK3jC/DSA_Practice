#ifndef ARRAYHEAP_H
#define ARRAYHEAP_H

#include "minheap.h"
#include <string>

class ArrayMinHeap : public MinHeap {
    int* array;
    int size;
    int capacity;

    int left(int n);
    int right(int n);

    void print_tree(std::string prefix, int n, bool isLeft);

    public:
        ArrayMinHeap();
        void insert(int num) override;
        int removeMin() override;
        void print() override;
};

#endif // ARRAYHEAP_H
