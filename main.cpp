#include <iostream>
#include "st.h"

int main()
{
	Stree searchTree;

	searchTree.insert(1);
	searchTree.insert(2);
	searchTree.insert(3);
	searchTree.insert(4);
	searchTree.insert(5);

	searchTree.preOrder();
	std::cout << std::endl;
	searchTree.inOrder();
	std::cout << std::endl;
	searchTree.postOrder();

	std::cin.get();
}