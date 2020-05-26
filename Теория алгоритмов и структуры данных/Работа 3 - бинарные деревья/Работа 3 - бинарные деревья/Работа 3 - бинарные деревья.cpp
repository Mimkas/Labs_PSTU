#include <iostream>
#include "BinaryTree.h"

int main()
{
    BinaryTree a;
    a.Insert(5);
    a.Insert(1);
    a.Insert(3);
    a.Insert(7);
    a.Insert(9);
    a.Insert(6);
    a.Insert(8);
    a.Insert(4);
    a.Insert(2);
    cout << "initial tree print\n";
    a.Show();
    cout << "\n\n";
    cout << "Max element is" << a.MaxElem() << "\n\n";
    cout << "level straightened binary tree\n";
    a.TreeStruct();
    cout << "\n\n";
    a = a.RestructTree();
    cout << "straightened restructing binary tree\n";
    a.TreeStruct();
    cout << "\n\n";
    cout << "direct tree\n";
    a.Show();
}