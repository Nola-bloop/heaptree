const char endl[] = "\n";

#include "heaptree.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    Heaptree tree;

    tree.insert(13);
    tree.insert(10);
    tree.insert(8);
    tree.insert(4);
    tree.insert(12);
    tree.insert(25);
    tree.insert(78);
    tree.insert(16);
    tree.insert(18);
    tree.insert(42);
    tree.insert(23);
    tree.insert(42);
    tree.debug();
    tree.pop();
    tree.debug();
    return 0;
}