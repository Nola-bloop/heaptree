#include "node.h"

#include <iostream>

void Node::_refreshChildCount()
{
    this->_children = 0;
    if (this->left() != nullptr)
        this->_children += this->left()->children()+1;
    if (this->right() != nullptr)
        this->_children += this->right()->children()+1;

    if (this->parent() != nullptr)
        this->parent()->_refreshChildCount();
}

Node::Node(int val, Node *parent)
{
    this->_value = val;
    this->_parent = parent;
}

Node::~Node()
{
    delete this->_left;
    delete this->_right;
}



int Node::value()
{
    return this->_value;
}

void Node::value(int v)
{
    this->_value = v;
}



Node* Node::left()
{
    if (this == nullptr) return nullptr;
    return this->_left;
}

void Node::left(Node* n)
{
    //needs to make sure that the child count is accurate
    if (this->_left != nullptr && n != nullptr){
        //if the current value isn't empty and the new value also isn't empty,
        this->_children -= this->_left->_children+1;
    }

    this->_left = n;

    if (n != nullptr){
        //if the new value isn't empty
        this->_children += this->_left->_children+1;
        n->_parent = this;
    }

    this->_refreshChildCount();
}



Node* Node::right()
{
    if (this == nullptr) return nullptr;
    return this->_right;
}

void Node::right(Node* n)
{
    //needs to make sure that the child count is accurate
    if (this->_right != nullptr && n != nullptr){
        //if the current value isn't empty and the new value also isn't empty,
        this->_children -= this->_right->_children+1;
    }

    this->_right = n;

    if (n != nullptr){
        //if the new value isn't empty
        this->_children += this->_right->_children+1;
        n->_parent = this;
    }
    this->_refreshChildCount();
}



Node *Node::parent()
{
    return this->_parent;
}



int Node::children()
{
    return this->_children;
}

void Node::debug(std::string spaces)
{
    std::cout << spaces << this->_value << "(" << this->_children << ")" << "\n";
    if (this->_left != nullptr)
        this->_left->debug(spaces+"  ");
    if (this->_right != nullptr)
        this->_right->debug(spaces+"  ");
}
