#include"BinaryTree.h"
#include"queue.h"

int main()
{
	BTNode *root= BinaryTreeCreate();
	
	printf("%d\n", BinaryTreeLeafSize(root));
	printf("%d\n", BinaryTreeSize(root));
	printf("%d\n", BinaryTreeLevelKSize(root,2));
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreeLevelOrder(root);
	int x=BinaryTreeComplete(root);
	printf("%d", x);
	BinaryTreeDestory(root);
	return 0;
}