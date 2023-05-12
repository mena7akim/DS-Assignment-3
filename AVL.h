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
    int bFactor;
    AVLNode()
    {
        left = nullptr;
        right = nullptr;
    }
    AVLNode(Student stud)
    {
        data = move(stud);
        left = nullptr;
        right = nullptr;
    }
};


class AVL {
    AVLNode *root;
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


    AVLNode* rotateToLeft(AVLNode *root)
    {
        AVLNode * p;
        if(root == NULL)
        {
            cout << "Error in the tree!" << endl;
        }
        else if(root->right == NULL)
        {
            cout << "No right subtree to rotate!" << endl;
        }
        else
        {
            p = root->right;
            root->right = p->left;
            p->left = root;
            root = p;
        }
        return (root);
    }


    AVLNode* rotateToRight(AVLNode *root)
    {
        AVLNode * p;
        if(root == NULL)
        {
            cout << "Error in the tree!" << endl;
        }
        else if(root->left == NULL)
        {
            cout << "No left subtree to rotate!" << endl;
        }
        else
        {
            p = root->left;
            root->left = p->right;
            p->right = root;
            root = p;
        }
        return (root);
    }



    int bFactor(AVLNode * n)
    {
        if(n == NULL)
            return 0;
        return n->bFactor;
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
        node->bFactor = 1;
        return (node);
    }




    AVLNode *insert(AVLNode *node, int id)
    {
        if(node == NULL)
            return (newNode(node->data));
        if(id < node->data.getId())
            node->left = insert(node->left, id);
        else if(id > node->data.getId())
            node->right = insert(node->right, id);
        else
        {
            cout << "Student with id " << id << " already exists." << endl;
            return node;
        }


        node->bFactor = 1 + max(bFactor(node->left), bFactor(node->right));

        int balanceFactor = getBalanceFactor(node);
        if(balanceFactor > 1 && id < node->left->data.getId())
        {
            return rotateToRight(node);
        }

        if(balanceFactor > 1 && id > node->left->data.getId())
        {
            node->left = rotateToLeft(node->left);
            return rotateToRight(node);
        }

        if (balanceFactor < -1)
        {
            if(id > node->right->data.getId())
                return rotateToLeft(node);
            else if(id < node->right->data.getId())
            {
                node->right = rotateToRight(node->right);
                return rotateToLeft(node);
            }
        }
        size++;
        return node;
    }


    AVLNode* minimumNode(AVLNode* nod)
    {
        AVLNode * curr = nod;
        while (curr->left != NULL)
            curr = curr->left;
        return curr;
    }


    AVLNode* remove(AVLNode *node, int id)
    {
        if(node == NULL)
            return node;
        if(id < node->data.getId())
        {
            node->left = remove(node->left, id);
        }
        else if(id > node->data.getId())
        {
            node->right = remove(node->right, id);
        }
        else
        {
            if((node->left == NULL) || (node->right == NULL))
            {
                AVLNode* t;
                if(node->left)
                    t = node->left;
                else
                    t = node->right;

                if(t == NULL)
                {
                    t = node;
                    node = NULL;
                }
                else
                {
                    *node = *t;
                    delete t;
                }
            }
            else
            {
                AVLNode* temp = minimumNode(node->right);
                node->data = temp->data;
                node->right = remove(node->right, id);
            }
        }
        if (node == NULL)
            return node;

        node->bFactor = 1 + max(bFactor(node->left), bFactor(node->right));

        int balanceFactor = getBalanceFactor(node);

        if(balanceFactor > 1 && getBalanceFactor(node->left) < 0)
        {
            node->left = rotateToLeft(node->left);
            return rotateToRight(node);
        }

        if(balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
            return rotateToRight(node);

        if(balanceFactor < -1 && getBalanceFactor(node->right) > 0)
        {
            node->right = rotateToRight(node->right);
            return rotateToLeft(node);
        }

        if(balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
            return rotateToLeft(node);

        size--;
        return node;
    }


    void printStudent(Student st)
    {
        cout << "[" <<  st.getId() << ", " << st.getName() << ", " << st.getGpa() << ", " << st.getDepartment() << "]" << endl;
    }


    AVLNode* search(AVLNode* ptr, int id)
    {
        if(ptr == NULL)
        {
            cout << id << " was not found!" << endl;
            return ptr;
        }
        if(ptr->data.getId() == id)
        {
            cout << id << " was found!" << endl;
            printStudent(ptr->data);
        }
        else
        {
            if(id > ptr->data.getId())
            {
                return search(ptr->right, id);
            }
            else if(id < ptr->data.getId())
            {
                return search(ptr->left, id);
            }
        }
    }

    void LVR(AVLNode*node)
    {
        if(node == NULL)
            return;
        else
        {
            LVR(node->left);
            printStudent(node->data);
            LVR(node->right);
        }
    }

    void printStudents()
    {
        if(size == 0)
            cout << "No student left" << endl;
        else
        {
            LVR(root);
        }
    }

};