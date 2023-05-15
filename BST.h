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
        root = new BSTNode(stud);
        size = 1;
    }

    void insert(Student stud) {
        BSTNode * next, * preNext;
        next = root;
        int pos = -1;
        while(next != nullptr){
            if(next->data.getId() < stud.getId()){
                preNext = next;
                next = next->right;
                pos = 2;
            }
            else if(next->data.getId() > stud.getId()){
                preNext = next;
                next = next->left;
                pos = 1;
            }
            else{
                cout << "can't add the same id twice";
                return;
            }
        }
        if(pos == -1)
            root = new BSTNode(stud);
        else{
            auto * newNode = new BSTNode(stud);
            if(pos == 1)
                preNext->left = newNode;
            else
                preNext->right = newNode;
        }
        size++;
    }

    void remove(int id) {
        if(size == 0){
            cout << "Tree is empty.\n";
        }
        else if(size == 1 && root->data.getId() == id){
            BSTNode * temp;
            temp = root;
            root = nullptr;
            delete temp;
            size--;
        }
        else{
            int pos = -1;
            BSTNode * node, * pre;
            pre = nullptr;
            node = root;
            while(node != nullptr){
                if(node->data.getId() < id){
                    pre = node;
                    node = node->right;
                    pos = 2;
                }
                else if(node->data.getId() > id){
                    pre = node;
                    node = node->left;
                    pos = 1;
                }
                else{
                    if(node->right == nullptr && node->left == nullptr){
                        BSTNode * temp;
                        temp = node;
                        node = nullptr;
                        delete temp;
                    }
                    else if(node->right == nullptr || node->left == nullptr){
                        if(node == root){
                            BSTNode * temp;
                            temp = node;
                            root = node->right == nullptr ? node->left : node->right;
                            node = nullptr;
                            delete temp;
                        }
                        else{
                            BSTNode * temp;
                            temp = node;
                            if(pos == 1)
                                pre->left = node->right == nullptr ? node->left : node->right;
                            else
                                pre->right = node->right == nullptr ? node->left : node->right;
                            node = nullptr;
                            delete temp;
                        }
                    }
                    else{
                        BSTNode * predecessor;
                        predecessor = node->left;
                        while(predecessor->right != nullptr){
                            predecessor = predecessor->right;
                        }
                        Student tempStudent = predecessor->data;
                        remove(predecessor->data.getId());
                        node->data = tempStudent;
                    }
                    size--;
                }
            }
        }
    }

    void search(int id) {
        search(root, id);
    }

    void search(BSTNode * root, int id) {
        if(root == NULL){
            cout << "There is no student with this id\n";
            return;
        }

        if(root->data.getId() < id){
            search(root->right, id);
        }
        else if(root->data.getId() > id){
            search(root->left, id);
        }
        else{
            cout << "Student is found.\n";
            root->data.printStudent();
            return;
        }
    }

    void dfs(BSTNode * r) const {
        if(r == nullptr)
            return;
        else{
            dfs(r->left);
            r->data.printStudent();
            dfs(r->right);
        }
    }

    void printStudents() const {
        if(size == 0)
            cout << "No Students left\n";
        else{
            dfs(root);
        }
    }
};


#endif
