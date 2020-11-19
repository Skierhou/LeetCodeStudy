#include "Q_437.h"
#include <iostream>

void Q_437::Execute()
{
    TreeNode *root = new TreeNode(10);
    root->right = new TreeNode(-3);
    root->right->right = new TreeNode(11);

    root->left = new TreeNode(5);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);

    /*TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root->right->right->right->right = new TreeNode(5);*/
    cout << ans_02(root, 8);
}

int Q_437::ans_01(TreeNode* root, int sum)
{
    ans_01_dfs(root,0, sum, true);
	return res;
}

void Q_437::ans_01_dfs(TreeNode* root, int curr, int sum, bool bNormal)
{
    if (root == nullptr) return;

    if (bNormal)
    {
        ans_01_dfs(root->right, 0, sum, true);
        ans_01_dfs(root->left, 0, sum, true);
    }

    curr += root->val;
    if (curr == sum)
        ++res;

    ans_01_dfs(root->left, curr, sum);
    ans_01_dfs(root->right, curr, sum);
}

int Q_437::ans_02(TreeNode* root, int sum)
{
    unordered_map<int, int> m;
    m.insert(pair<int, int>(0, 1));
    return ans_02_loop(root, m, sum, 0);
}

int Q_437::ans_02_loop(TreeNode* node, unordered_map<int, int> prefixSumCount, int target, int currSum)
{
    // 1.递归终止条件
    if (node == nullptr) {
        return 0;
    }
    // 2.本层要做的事情
    int res = 0;
    // 当前路径上的和
    currSum += node->val;

    //---核心代码
    // 看看root到当前节点这条路上是否存在节点前缀和加target为currSum的路径
    // 当前节点->root节点反推，有且仅有一条路径，如果此前有和为currSum-target,而当前的和又为currSum,两者的差就肯定为target了
    // currSum-target相当于找路径的起点，起点的sum+target=currSum，当前点到起点的距离就是target
    res += prefixSumCount[currSum - target];
    // 更新路径上当前节点前缀和的个数
    ++prefixSumCount[currSum];
    //---核心代码

    // 3.进入下一层
    res += ans_02_loop(node->left, prefixSumCount, target, currSum);
    res += ans_02_loop(node->right, prefixSumCount, target, currSum);

    // 4.回到本层，恢复状态，去除当前节点的前缀和数量
    --prefixSumCount[currSum];
    return res;
}
