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
    // 1.�ݹ���ֹ����
    if (node == nullptr) {
        return 0;
    }
    // 2.����Ҫ��������
    int res = 0;
    // ��ǰ·���ϵĺ�
    currSum += node->val;

    //---���Ĵ���
    // ����root����ǰ�ڵ�����·���Ƿ���ڽڵ�ǰ׺�ͼ�targetΪcurrSum��·��
    // ��ǰ�ڵ�->root�ڵ㷴�ƣ����ҽ���һ��·���������ǰ�к�ΪcurrSum-target,����ǰ�ĺ���ΪcurrSum,���ߵĲ�Ϳ϶�Ϊtarget��
    // currSum-target�൱����·������㣬����sum+target=currSum����ǰ�㵽���ľ������target
    res += prefixSumCount[currSum - target];
    // ����·���ϵ�ǰ�ڵ�ǰ׺�͵ĸ���
    ++prefixSumCount[currSum];
    //---���Ĵ���

    // 3.������һ��
    res += ans_02_loop(node->left, prefixSumCount, target, currSum);
    res += ans_02_loop(node->right, prefixSumCount, target, currSum);

    // 4.�ص����㣬�ָ�״̬��ȥ����ǰ�ڵ��ǰ׺������
    --prefixSumCount[currSum];
    return res;
}
