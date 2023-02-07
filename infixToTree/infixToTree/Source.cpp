#include"BS.h"
#include"BSnode.h"
int main()
{
	BS a;
	char t[] = {"((5+3)*5-8/4)"};
	BSnode* z = a.infixToTree(t);

	a.postorder(z);
	return 0;
}