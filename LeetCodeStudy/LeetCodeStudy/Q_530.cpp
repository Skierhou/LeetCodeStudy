#include "Q_530.h"
#include <algorithm>
#include <iostream>

void Q_530::Execute()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);

    cout << ans_01(root);
}

int Q_530::ans_01(TreeNode* root)
{
	int res = INT_MAX;
	int pre = -1;
	ans_01_dfs(root, res, pre);
	return res;
}

void Q_530::ans_01_dfs(TreeNode* root, int& res, int& pre)
{
    if (root == nullptr) return;

    ans_01_dfs(root->left, res, pre);
    if (pre == -1)
        pre = root->val;
    else
    {
        res = min(res, abs(root->val - pre));
        pre = root->val;
    }
    ans_01_dfs(root->right, res, pre);
}
