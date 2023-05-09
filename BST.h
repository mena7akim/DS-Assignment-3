#ifndef CMAKE_TESTAPP_BST_H
#define CMAKE_TESTAPP_BST_H

#include <utility>

#include "Student.h"

struct BSTNode {
    Student data;
    BSTNode * left;
    BSTNode * right;
    BSTNode() {
        left = right = nullptr;
    }
    BSTNode(Student stud) {
        data = std::move(stud);
        left = right = nullptr;
    }
};

class BST{
    BSTNode * root;
    int size = 0;
public:
    BST() {
        root = nullptr;
    }
    BST(Student stud) {
        root = new BSTNode(std::move(stud));
    }


};


#endif
