//
// Created by Nervana on 5/9/2023.
//

#ifndef MAIN_CPP_AVL_H
#define MAIN_CPP_AVL_H

#endif //MAIN_CPP_AVL_H
#include "Student.h"
#include <utility>

struct AVLNode
{
    Student data;
    AVLNode * left;
    AVLNode * right;
    int height;
    AVLNode()
    {
        left = nullptr;
        right = nullptr;
        height = 1;
    }
    AVLNode(Student stud)
    {
        data = move(stud);
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};


class AVL {
    AVLNode * root;
    int size = 0;

public:
    AVL()
    {
        root = nullptr;
    }


    AVL(Student stud)
    {
        root = new AVLNode(move(stud));
    }


    void rotateToLeft(AVLNode * &r)
    {
        AVLNode * p;
        if(r == NULL)
        {
            cout << "Error in the tree!" << endl;
        }
        else if(r->right == NULL)
        {
            cout << "No right subtree to rotate!" << endl;
        }
        else
        {
            p = r->right;
            r->right = p->left;
            r->height = 1 + max(bFactor(r->left), bFactor(r->right));
            p->left = r;
            p->height = 1 + max(bFactor(p->left), bFactor(p->right));
            r = p;
        }
    }


    void rotateToRight(AVLNode * &r)
    {
        AVLNode * p;
        if(r == NULL)
        {
            cout << "Error in the tree!" << endl;
        }
        else if(r->left == NULL)
        {
            cout << "No left subtree to rotate!" << endl;
        }
        else
        {
            p = r->left;
            r->left = p->right;
            r->height = 1 + max(bFactor(r->left), bFactor(r->right));
            p->right = r;
            p->height = 1 + max(bFactor(p->left), bFactor(p->right));
            r = p;
        }
    }



    int bFactor(AVLNode * n)
    {
        if(n == NULL)
            return 0;
        return n->height;
    }


    int getBalanceFactor(AVLNode * n)
    {
        if(n == NULL)
            return 0;
        return bFactor(n->left) - bFactor(n->right);
    }


    AVLNode * newNode (Student st)
    {
        AVLNode *node = new AVLNode();
        node->data = st;
        node->left = node->right = NULL;
        node->height = 1;
        return (node);
    }

    void insert(Student stud){
        AVLNode * node = NULL;
        insert(root, node, stud);
    }

    void insert(AVLNode * &r, AVLNode *node, Student stud)
    {
        if(r == NULL){
            r = newNode(stud);
            size++;
            return;
        }
        if(stud.getId() < r->data.getId())
            insert(r->left, node, stud);
        else if(stud.getId() > r->data.getId())
            insert(r->right, node, stud);
        else
        {
            cout << "Student with id " << stud.getId() << " already exists." << endl;
            return;
        }


        r->height = 1 + max(bFactor(r->left), bFactor(r->right));

        int balanceFactor = getBalanceFactor(r);
        if(balanceFactor > 1 && stud.getId() < r->left->data.getId())
        {
            rotateToRight(r);
        }

        if(balanceFactor > 1 && stud.getId() > r->left->data.getId())
        {
            rotateToLeft(r->left);
            rotateToRight(r);
        }

        if (balanceFactor < -1)
        {
            if(stud.getId() > r->right->data.getId())
                rotateToLeft(r);
            else if(stud.getId() < r->right->data.getId())
            {
                rotateToRight(r->right);
                rotateToLeft(r);
            }
        }
    }


    AVLNode* minimumNode(AVLNode* nod)
    {
        AVLNode * curr = nod;
        while (curr->left != NULL)
            curr = curr->left;
        return curr;
    }

    void remove(int id){
        AVLNode *node = NULL;
        remove(root, id);
    }

    void remove(AVLNode * &node, int id)
    {
        if(node == NULL){
            cout << "There is no student with id " << id << '\n';
            return;
        }
        if(id < node->data.getId())
        {
            remove(node->left, id);
        }
        else if(id > node->data.getId())
        {
            remove(node->right, id);
        }
        else
        {
            if((node->left == NULL) || (node->right == NULL))
            {
                AVLNode * t;
                t = NULL;
                if(node->left)
                    t = node->left;
                else if(node->right)
                    t = node->right;

                if(t == NULL)
                {
                    t = node;
                    node = NULL;
                    delete t;
                }
                else
                {
                    *node = *t;
                    delete t;
                }
            }
            else
            {
                Student stud = minimumNode(node->right)->data;
                remove(node->right, stud.getId());
                node->data = stud;
                size++;
            }
            size--;
        }
        if(node == NULL)
            return;
        node->height = 1 + max(bFactor(node->left), bFactor(node->right));

        int balanceFactor = getBalanceFactor(node);

        if(balanceFactor > 1 && getBalanceFactor(node->left) < 0)
        {
            rotateToLeft(node->left);
            rotateToRight(node);
        }

        if(balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
            rotateToRight(node);

        if(balanceFactor < -1 && getBalanceFactor(node->right) > 0)
        {
            rotateToRight(node->right);
            rotateToLeft(node);
        }

        if(balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
            rotateToLeft(node);
    }


    void search(int id){
        search(root, id);
    }

    void search(AVLNode* ptr, int id)
    {
        if(ptr == NULL)
        {
            cout << id << " was not found!" << endl;
            return;
        }
        if(ptr->data.getId() == id)
        {
            cout << id << " was found!" << endl;
            ptr->data.printStudent();
        }
        else
        {
            if(id > ptr->data.getId())
            {
                search(ptr->right, id);
            }
            else if(id < ptr->data.getId())
            {
                search(ptr->left, id);
            }
        }
    }


    void LVR(AVLNode*node) const
    {
        if(node == NULL)
            return;
        else
        {
            LVR(node->left);
            node->data.printStudent();
            LVR(node->right);
        }
    }


    void printStudents() const
    {
        if(size == 0)
            cout << "No student left" << endl;
        else
        {
            LVR(root);
        }
    }

};