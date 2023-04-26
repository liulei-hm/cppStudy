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
	vector<int> B; //小容器每次放完一层 就放入res中，并且B.clear
	int cur_level = 0;
	que.emplace(root);
	while (que.empty() == false)
	{
		//把当前层(都在队列中)的下一层都入队，每次处理一层
		int size = que.size();
		while (size--)
		{
			//出队
			p = que.front();
			que.pop();
			B.push_back(p->val);
			//左节点入队
			if (p->left != NULL)
			{
				que.emplace(p->left);
			}
			//右节点出队
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