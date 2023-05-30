#include"BinaryTree.h"
#include"queue.h"

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}


BTNode* BinaryTreeCreate()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}
// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root != NULL)
	{
		return;
	}
	BinaryTreeDestory((*root)->left);
	BinaryTreeDestory((*root)->right);
	free(*root);
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return BinaryTreeSize(root->left) + 1 + BinaryTreeSize(root->right);
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{	
	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);


}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode* ret = BinaryTreeFind(root->left, x);
	if (ret!= NULL)
	{
		return ret;
	}
	BTNode* ret1 = BinaryTreeFind(root->right, x);
	if (root->right != NULL)
	{
		return ret1;
	}
	return NULL;
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);

}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	
	BinaryTreeInOrder(root->left);
	printf("%d", root->data);
	BinaryTreeInOrder(root->right);
} 
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%d", root->data);
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q,root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d", front->data);
		if (front->left != NULL)
		{
			QueuePush(&q,front->left);
		}

		if (front->right != NULL)
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");
	QueueDestroy(&q);
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
	{
		return 1;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	return BinaryTreeComplete(root->left) * BinaryTreeComplete(root->right);
}