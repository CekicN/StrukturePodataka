#include"BSTree.h"

void main()
{
	BSTree stablo;
	
	stablo.insert(5);
	stablo.insert(2);
	stablo.insert(6);
	stablo.insert(4);
	stablo.insert(3);
	stablo.insert(8);
	stablo.insert(17);
	stablo.insert(9);
	stablo.insert(7);

	stablo.preorder();
	stablo.postorder();
	stablo.inorder();

	stablo.deleteByMerging(8);
	stablo.preorder();
}