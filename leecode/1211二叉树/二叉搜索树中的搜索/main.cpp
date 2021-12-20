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


TreeNode* searchBST(TreeNode* root, int val) {
	if (root == nullptr) {
		return nullptr;
	}
	stack<TreeNode*> stk;
	stk.push(root);
	while (!stk.empty()) {
		TreeNode* node = stk.top();
		stk.pop();
		if (node->val == val) {
			return node;
		}
		if (node->val > val ) {
			if (node->left != nullptr) {
				stk.push(node->left);
			}
		}
		else {
			if (node->right != nullptr) {
				stk.push(node->right);
			}
		}
	}
	return nullptr;
}