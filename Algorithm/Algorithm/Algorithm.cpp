#include "TreeCustom.h"

int main()
{
	Tree tree;
	NodeRef ref = tree.CreateTree();
	tree.PrintTree(ref, 0);

	cout << tree.GetHeight(ref) << "\n";
}