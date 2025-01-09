#ifndef MINHEAP_H
#define MINHEAP_H

class MinHeap {
    public:
        virtual void insert(int num) = 0;
        virtual int removeMin() = 0;
        virtual void print() = 0;
};

#endif // MINHEAP_H
