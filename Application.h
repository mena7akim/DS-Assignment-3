#ifndef CMAKE_TESTAPP_APPLICATION_H
#define CMAKE_TESTAPP_APPLICATION_H

#include "maxHeap.h"
#include "minHeap.h"

class Application {
    maxHeap MaxHeap;
    minHeap MinHeap;

public:
    Application() {
        freopen("students.txt", "r", stdin);
        int StudentsNumber;
        cin >> StudentsNumber;
        while(StudentsNumber--){
            Student stud;
            cin >> stud;
            MaxHeap.push(stud);
            MinHeap.push(stud);
        }
    }

    void run() const {
        while(true){
            int option;
            cout << "Choose Data Structure:\n"
                           "\t1. BST\n"
                           "\t2. AVL\n"
                           "\t3. Min Heap\n"
                           "\t4. Max Heap\n"
                           "\t5. Exit Program\n";
            cin >> option;
            switch (option) {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    exit(0);
            }
        }
    }
};


#endif
