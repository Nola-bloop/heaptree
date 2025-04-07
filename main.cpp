const char endl[] = "\n";

#include "heaptree.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    Heaptree tree;

    tree.insert(13);
    tree.debug();
    tree.insert(10);
    tree.debug();
    tree.insert(8);
    tree.debug();
    tree.insert(4);
    tree.debug();
    tree.insert(12);
    tree.debug();
    tree.insert(25);
    tree.debug();
    tree.insert(78);
    tree.debug();
    tree.insert(16); //problem
    tree.debug();
    tree.insert(18);
    tree.debug();
    tree.insert(42);
    tree.debug();
    tree.insert(23);
    tree.debug();
    tree.insert(42);
    tree.debug();
    return 0;
}