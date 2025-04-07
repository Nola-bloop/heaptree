#include "heaptree.h"

#include <iostream>
#include <queue>

Node *Heaptree::_findPotential(int v)
{
    Node* it = this->_root;
    if (it == nullptr) return nullptr;

    while (it->value() > v){
        if (it->left() == nullptr)
            break;
        else if (it->right() == nullptr)
            break;

        bool lGreater = it->left()->value() > v; //false
        bool rGreater = it->right()->value() > v; //false


        if (!lGreater && !rGreater) break;
        if (lGreater && rGreater)
        {
            if (it->left()->children() <= it->right()->children())
                it = it->left();
            
            else
                it = it->right();
            
        }
        else if (!lGreater)
            it = it->left();
        else
            it = it->right();
        
        
    }

    return it;
}

void Heaptree::bubble(Node * ptr, int mem)
{
    if (mem > ptr->value()){
        int temp = ptr->value();
        ptr->value(mem);
        mem = temp;
    }
    
    while (ptr != nullptr){
        //if one of the children is empty, fill the blank
        if (ptr->left() == nullptr){
            ptr->left(new Node(mem, ptr));
            break;
        }
        else if (ptr->right() == nullptr){
            ptr->right(new Node(mem, ptr));
            break;
        }

        //find if a side should be favored because of the child count.
        bool childrenFavor = ptr->left()->children() > ptr->right()->children(); //favor left side if they have the same child count.
        //false = left, right = true
        
        //I know by now that both children are not nullptr
        if (!childrenFavor)
            ptr = ptr->left();
        else
            ptr = ptr->right();
        
        int temp = ptr->value();
        ptr->value(mem);
        mem = temp;
    }
}

Heaptree::Heaptree()
{

}

Heaptree::~Heaptree()
{
    delete this->_root;
}

void Heaptree::pop()
{
    Node* ptr = this->_root;
    if (ptr == nullptr) return;

    //yanking the chain
    while (!(ptr->left() == nullptr && ptr->right() == nullptr)){
        //if at least one of them is nullptr...
        if (ptr->left() == nullptr || ptr->right() == nullptr){
            if (ptr->left() != nullptr){
                ptr->value(ptr->left()->value());
                ptr = ptr->left();
            }
            else
            {
                ptr->value(ptr->right()->value());
                ptr = ptr->right();
            }
        }

        //if they both have values
        else{
            //default yanking side to the left
            Node* swap = ptr->left();

            //check for a greater one
            if (ptr->left() < ptr->right())
                swap = ptr->right();

            //if both values are equal, then compare the child count
            if (ptr->left()->children() > ptr->right()->children())
                swap = ptr->right();

            //do the swap and move on
            ptr->value(swap->value());
            ptr = swap;
        }
    }
    delete ptr;
}

int Heaptree::read()
{
    return this->_root->value();
}

void Heaptree::insert(int v)
{
    //if root is empty, set the root
    if (this->_root == nullptr) {
        this->_root = new Node(v);
        return;
    }

    //this is accessed when the value is greater than the root's value to bypass priority checks
    if (v > this->_root->value()) {
        bubble(this->_root, v);
        return;
    }

    //find where to add
    Node* where = this->_findPotential(v);

    //if the potential has an empty child, then add the new node to it
    if (where->left() == nullptr)
        where->left(new Node(v));
    else if (where->right() == nullptr)
        where->right(new Node(v));

    //else, a bubble sort needs to happen.
    else{


        this->bubble(where, v);
    }
}

void Heaptree::heapify()
{
    //to implement
}

void Heaptree::debug()
{
    std::cout << ">---Tree Debug---<" << "\n";
    this->_root->debug();
}
