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
            if(largeIndex < high && a[largeIndex].getGpa() < a[largeIndex + 1].getGpa())
                largeIndex++;
            if(temp.getGpa() > a[largeIndex].getGpa())
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
        while(i && a[i].getGpa() > a[(i - 1) / 2].getGpa()){
            swap(a[i], a[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
        sz++;
    }

    void HeapSort(){
        Student * temp = new Student[sz];

        for(int i = 0; i < sz; i++) {
            temp[i] = a[i];
        }

        for(int i = sz - 1; i > 0; i--){
            swap(a[0], a[i]);
            heapify(0, i - 1);
        }
        for(int i = sz - 1; i >= 0; i--){
            a[i].printStudent();
        }

        for(int i = 0; i < sz; i++){
            a[i] = temp[i];
        }

        delete[] temp;
    }

    void printStudents(){
        if(sz){
            HeapSort();
        }
        else{
            cout << "There is no students\n";
        }
    }

    Student top(){ return a[0]; }
    int size(){ return sz; }
    bool empty(){ return !sz; }
};

#endif



