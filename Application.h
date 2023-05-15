#ifndef CMAKE_TESTAPP_APPLICATION_H
#define CMAKE_TESTAPP_APPLICATION_H
#include <iostream>
#include <fstream>
#include "maxHeap.h"
#include "minHeap.h"
#include "BST.h"
#include "AVL.h"


using namespace std;
class Application {
    maxHeap MaxHeap;
    minHeap MinHeap;
    BST bst;
    AVL avl;
public:
    Application() {
        ifstream myFile("C:\\Users\\over-\\CLionProjects\\DS-Assignment-3\\cmake-build-debug\\students.txt");
        int cnt = 0;
        string line;
        Student stud;
        while(getline(myFile, line)){
            if(!cnt){
                cnt++;
                continue;
            }
            switch (cnt % 4) {
                case 0:
                    stud.setDepartment(line);
                    MaxHeap.push(stud);
                    MinHeap.push(stud);
                    bst.insert(stud);
                    avl.insert(stud);
                    break;
                case 1:
                    stud.setId(stoi(line));
                    break;
                case 2:
                    stud.setName(line);
                    break;
                case 3:
                    stud.setGpa(stof(line));
                    break;
            }
            cnt++;
        }
        myFile.close();
    }

    void run() {
        while (true) {
            int option;
            Student st;
            cout << "Choose Data Structure:\n"
                    "\t1. BST\n"
                    "\t2. AVL\n"
                    "\t3. Min Heap\n"
                    "\t4. Max Heap\n"
                    "\t5. Exit Program\n";
            cin >> option;

            switch (option) {
                case 1:
                    while (option != 5) {
                        cout << "Choose one of the following options:\n"
                                "\t1. Add student\n"
                                "\t2. Remove student\n"
                                "\t3. Search student\n"
                                "\t4. Print All (sorted by id)\n"
                                "\t5. Return to main menu\n";
                        cin >> option;
                        int id;
                        switch (option) {
                            case 1:
                                cin >> st;
                                bst.insert(st);
                                break;
                            case 2:
                                cout << "Enter the id of the student you want to remove\n";
                                cin >> id;
                                bst.remove(id);
                                break;
                            case 3:
                                cout << "Enter the id of the student you want to search about\n";
                                cin >> id;
                                bst.search(id);
                                break;
                            case 4:
                                bst.printStudents();
                                break;
                            case 5:
                                break;
                        }
                    }
                    break;
                case 2:

                    while (option != 5) {
                        cout << "Choose one of the following options:\n"
                                "\t1. Add student\n"
                                "\t2. Remove student\n"
                                "\t3. Search student\n"
                                "\t4. Print All (sorted by id)\n"
                                "\t5. Return to main menu\n";
                        cin >> option;
                        int id;
                        switch (option) {
                            case 1:
                                cin >> st;
                                avl.insert(st);
                                break;
                            case 2:
                                cout << "Enter the id of the student you want to remove\n";
                                cin >> id;
                                avl.remove(id);
                                break;
                            case 3:
                                cout << "Enter the id of the student you want to search about\n";
                                cin >> id;
                                avl.search(id);
                                break;
                            case 4:
                                avl.printStudents();
                                break;
                            case 5:
                                break;
                        }
                    }
                    break;
                case 3:
                    option = 0;
                    while (option != 3) {
                        cout << "Choose one of the following options:\n"
                                "\t1. Add student\n"
                                "\t2. Print All (sorted by gpa)\n"
                                "\t3. Back to menu\n";
                        cin >> option;
                        switch (option) {
                            case 1:
                                cin >> st;
                                MinHeap.push(st);
                                break;
                            case 2:
                                MinHeap.printStudents();
                                break;
                            case 3:
                                break;
                        }
                    }
                    break;
                case 4:
                    while (option != 3) {
                        cout << "Choose one of the following options:\n"
                                "\t1. Add student\n"
                                "\t2. Print All (sorted by gpa)\n"
                                "\t3. Back to menu\n";
                        cin >> option;
                        switch (option) {
                            case 1:
                                cin >> st;
                                MaxHeap.push(st);
                                break;
                            case 2:
                                MaxHeap.printStudents();
                                break;
                            case 3:
                                break;
                        }
                    }
                case 5:
                    exit(0);
            }
        }
    }
};


#endif
