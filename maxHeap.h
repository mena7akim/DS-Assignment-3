#ifndef CMAKE_TESTAPP_MAXHEAP_H
#define CMAKE_TESTAPP_MAXHEAP_H

#include "Student.h"

class maxHeap {
    int sz = 0;
    int capacity = 1;
    Student * a = new Student[1];
public:
    maxHeap(){

    }

    void heapify(int low, int high){
        Student temp = a[low];
        int largeIndex = 2 * low + 1;
        while(largeIndex <= high){
            if(largeIndex < high && a[largeIndex] < a[largeIndex + 1])
                largeIndex++;
            if(temp > a[largeIndex])
                break;
            else{
                a[low] = a[largeIndex];

                low = largeIndex;
                largeIndex = 2 * low + 1;
            }
        }
        a[low] = temp;
    }

    void push(Student element){
        if(sz == capacity){
            capacity *= 2;
            Student * temp = new Student[capacity];
            for(int i = 0; i < sz; i++)
                temp[i] = a[i];
            delete[] a;
            a = temp;
            temp = nullptr;
        }

        a[sz] = element;
        int i = sz;
        while(i && a[i] > a[(i - 1) / 2]){
            swap(a[i], a[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
        sz++;
    }

    void pop(){
        a[0] = a[sz - 1];
        sz--;
        heapify(0, sz - 1);
    }

    Student top(){ return a[0]; }
    int size(){ return sz; }
    bool empty(){ return !sz; }
};

#endif



