#include<iostream>

using namespace std;

int N;
int preorder[30];
int inorder[30];
int postorder[30];


void Travel(int left,int right,int pleft,int pright)
{
	static int index = 0;
	if (left > right)
		return;


	int root = postorder[pright];
	preorder[index++] = root;
	for (int i = left; i <= right; i++)
	{
		if (inorder[i] == root)
		{
			Travel(left, i - 1,pleft,i-left - 1+pleft);
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
