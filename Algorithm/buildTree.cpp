//
// Created by liulei on 2023/3/15.
//

#include "all.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class TreeBuilder_preoderAndInoder {

public:
    //前序 中左右 3 9 20 15 7
    //中序 左中右 9 3 15 20 7
    //前序遍历的第一个节点为根节点3，在中序遍历中，根节点3右边为右子树(1个节点)，左边为左子树(3个节点)
    unordered_map<int, int> map_in;

    TreeNode *build(vector<int> &pre, vector<int> &in, int preL, int preR, int inL, int inR) {
        if (preL > preR) return NULL;
        int root_val = pre[preL];    //前序的左节点一定是根节点
        int in_index = map_in[root_val];  //找到中序中根节点位置，确定左子树大小，分治
        int size_leftSubtree = in_index - inL;

        TreeNode *root = new TreeNode(root_val);
        root->left = build(pre, in, preL + 1, preL + size_leftSubtree, inL, in_index - 1);
        root->right = build(pre, in, preL + 1 + size_leftSubtree, preR, in_index + 1, inR);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            map_in[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

int main()
{
    vector<int> v;
    v.
    return 0;
}
