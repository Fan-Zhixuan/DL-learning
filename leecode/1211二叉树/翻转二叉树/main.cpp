#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root) {
	if (root == nullptr) {
		return root;
	}
	stack<TreeNode*> stk;
	stk.push(root);
	while (!stk.empty())
	{
		TreeNode* node = stk.top();
		stk.pop();
		swap(node->left, node->right);
		if (node->left != nullptr) {
			stk.push(node->left);
		}
		if (node->right != nullptr) {
			stk.push(node->right);
		}
	}
}