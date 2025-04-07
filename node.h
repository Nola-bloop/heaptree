#pragma once

#include <string>

class Node
{
private:
    Node* _left{nullptr};
    Node* _right{nullptr};
    Node* _parent{nullptr};
    int _value{0};
    int _children{0};

    void _refreshChildCount();
public:
    Node(int val, Node* parent = nullptr);
    ~Node();

    int value();    //get
    void value(int);//set

    Node*  left();      //get
    void left(Node*);   //set
    
    Node*  right();     //get
    void right(Node*);  //set

    Node* parent();     //get
    void parent(Node*); //set

    /// @brief get child count
    int children();

    /// @brief print the node and it's contents
    /// @param spaces indent
    void debug(std::string spaces = "");
};
