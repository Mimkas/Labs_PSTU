#pragma once
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;
struct Tree
{
	Tree* left;
	Tree* right;
	int num;
	Tree(int n = 0, Tree* l = 0, Tree* r = 0) :num(n), left(l), right(r) {}
};
class BinaryTree
{
	Tree* root;
public:
	BinaryTree()
	{
		root = NULL;
	}
	void Add(Tree*& t, int n)
	{
		if (t==NULL)
		{
			t = new Tree(n);
		}
		else
		{
			if (n < t->num)
			{
				Add(t->left, n);
			}
			else
			{
				Add(t->right, n);
			}
		}
	}
	void Insert(int n)
	{
		Add(root, n);
	}
	void OutTree(Tree* &t)
	{
		if (t != NULL)
		{
			OutTree(t->left);
			cout << t->num << "\n";
			OutTree(t->right);
		}
	}
	void Show()
	{
		OutTree(root);
	}
	int MaxElem()
	{
		int a=0;
		Tree* t = root;
		while (t != NULL)
		{
			if (a < t->num) a = t->num;
			t = t->right;
		}
		return a;
	}
	void TreeStruct()
	{
		Tree* t = root;
		while (t != NULL)
		{
			cout << t->num << "\n";
			t = t->right;
		} // показывает, что дерево перестроено в дерево выводит на экран только одно направление.
		t = root;
		while (t != NULL)
		{
			cout << t->num << "\n";
			t = t->left;
		}
	}
	void StructurizationRight(BinaryTree& bt, Tree*& t)
	{
		if (t != NULL)
		{
			StructurizationRight(bt, t->left);
			if(t->num >= root->num) bt.Insert(t->num);
			StructurizationRight(bt, t->right);
		}
	}
	void StructurizationLeft(BinaryTree& bt, Tree*& t)
	{
		if (t != NULL)
		{
			StructurizationLeft(bt, t->right);
			if (t->num < root->num) bt.Insert(t->num);
			StructurizationLeft(bt, t->left);
		}
	}
	BinaryTree RestructTree()
	{
		int i = 0;
		BinaryTree bt;
		Tree* t = root;
		StructurizationRight(bt, t);
		StructurizationLeft(bt, t);
		return bt;
	}
};