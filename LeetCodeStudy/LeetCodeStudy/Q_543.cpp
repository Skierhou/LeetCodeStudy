#include "Q_543.h"
#include <iostream>
#include <algorithm>
using namespace std;

//ans = 1开始是因为，一条路径的长度=节点数-1，求路径长度相当于求经过一个节点数最大值-1
//计算节点深度：max(l,r)+1，计算当前节点最大路径数：l+r+1
int Q_543::ans_01(TreeNode* root)
{
    ans = 1;
    depth(root);
    return ans - 1;
}

int Q_543::depth(TreeNode* root)
{
    if (root == nullptr) return 0;
    int l = depth(root->left);
    int r = depth(root->right);
    ans = max(ans, l + r + 1);
    return 1 + max(l, r);
}

void Q_543::Execute()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << ans_01(root);
}
