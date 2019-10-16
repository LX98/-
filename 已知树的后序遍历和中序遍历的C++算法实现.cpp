#include<iostream>

using namespace std;

int N;
int preorder[30];	// 先序遍历数组
int inorder[30];	// 中序遍历数组
int postorder[30];	// 后序遍历数组


void Travel(int left,int right,int pleft,int pright)	// 这里分别是一棵树在中序、后序遍历数组中的范围
{
	static int index = 0;
	if (left > right) // left==right时，说明这棵树只有一个节点
		return;


	int root = postorder[pright];	// 从后序遍历数组中找到这个树的根
	preorder[index++] = root;		// 因为是先序遍历，访问这棵树时，先把根记录下来
	for (int i = left; i <= right; i++)
	{
		if (inorder[i] == root)		// 从中序遍历数组中定位树的根，然后根的左右分别是它的左右子树
		{
			Travel(left, i - 1,pleft,i-left - 1+pleft);// 左子树   i - 1 - left，左子树的长度
			Travel(i + 1, right, i - left + pleft,pright-1);
			break;
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> postorder[i];

	for (int i = 0; i < N; i++)
		cin >> inorder[i];

	Travel(0, N - 1,0,N-1);

	for (int i = 0; i < N; i++)
		cout << preorder[i] << ' ';

}
