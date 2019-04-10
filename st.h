#ifndef _searchtree_
#define _searchtree_
#include <iostream>

struct Node
{
	int value;
	Node *left, *right;

	Node(int, Node *, Node *);
};

Node::Node(int v, Node *l = nullptr, Node *r = nullptr)
{
	value = v;
	left = l;
	right = r;
}

class Stree
{
	public:
		Stree();
		void insert(int);
		void preOrder();
		void inOrder();
		void postOrder();

	private:
		Node *root;

		void insert(int, Node *);
		void preOrder(Node *);
		void inOrder(Node *);
		void postOrder(Node *);
};

Stree::Stree()
{
	root = nullptr;
}

void Stree::insert(int key)
{
	if (root != nullptr)
		insert(key, root);
	else
		root = new Node(key);
}

void Stree::insert(int key, Node *leaf)
{
	if (key < leaf->value)
	{
		if (leaf->left != nullptr)
			insert(key, leaf->left);
		else
			leaf->left = new Node(key);
	}
	else
	{
		if (leaf->right != nullptr)
			insert(key, leaf->right);
		else
			leaf->right = new Node(key);
	}
}

void Stree::preOrder()
{
	if (root != nullptr)
		preOrder(root);
	else
		std::cout << "Nothing to print. Tree is empty." << std::endl;
}

void Stree::preOrder(Node *leaf)
{
	if (leaf->left != nullptr)
		preOrder(leaf->left);
	std::cout << leaf->value << " ";
	if (leaf->right != nullptr)
		preOrder(leaf->right);
}

void Stree::inOrder()
{
	if (root != nullptr)
		inOrder(root);
	else
		std::cout << "Nothing to print. Tree is empty." << std::endl;
}

void Stree::inOrder(Node *leaf)
{
	std::cout << leaf->value << " ";
	if (leaf->left != nullptr)
		inOrder(leaf->left);
	if (leaf->right != nullptr)
		inOrder(leaf->right);
}

void Stree::postOrder()
{
	if (root != nullptr)
		postOrder(root);
	else
		std::cout << "Nothing to print. Tree is empty." << std::endl;
}

void Stree::postOrder(Node *leaf)
{
	if (leaf->left != nullptr)
		postOrder(leaf->left);
	if (leaf->right != nullptr)
		postOrder(leaf->right);
	std::cout << leaf->value << " ";
}


#endif