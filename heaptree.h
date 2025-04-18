#pragma once

#include "node.h"

class Heaptree
{
private:
    Node* _root{nullptr};

    //mode is 1 for biggest value first, 0 for lowest value first
    int _mode{1};

    /// @brief finds the first node with a nullptr or a shittier value that the one passed
    /// @return the first node smaller (or greater) than the value
    Node* _findPotential(int);

    /// @brief Bubble a value down the tree
    /// @param start where to start bubbling (will include the start in the bubble if v is greater than start->value())
    /// @param v the value to send down
    void bubble(Node* start, int v);
public:
    Heaptree(/* args */);
    ~Heaptree();

    /// @brief remove the top value from the tree
    /// @return the value that was removed
    void pop();

    /// @brief read the first value, but do not delete it
    /// @return the first value
    int read();

    /// @brief insert a value
    void insert(int);

    /// @brief redo the entire tree to make sure everything is in order.
    void heapify();

    /// @brief prints the tree's contents to the console
    void debug();
};