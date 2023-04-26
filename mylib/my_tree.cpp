#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	
}TreeNode;

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> res;
	if (root == NULL) return res;
	queue<TreeNode*> que;
	TreeNode *p = NULL;
	vector<int> B; //С����ÿ�η���һ�� �ͷ���res�У�����B.clear
	int cur_level = 0;
	que.emplace(root);
	while (que.empty() == false)
	{
		//�ѵ�ǰ��(���ڶ�����)����һ�㶼��ӣ�ÿ�δ���һ��
		int size = que.size();
		while (size--)
		{
			//����
			p = que.front();
			que.pop();
			B.push_back(p->val);
			//��ڵ����
			if (p->left != NULL)
			{
				que.emplace(p->left);
			}
			//�ҽڵ����
			if (p->right != NULL)
			{
				que.emplace(p->right);
			}
		}
		res.push_back(B);
		B.clear();
		cur_level++;
	}
	//cout <<"cur_level =" << cur_level << endl;
	return res;
}