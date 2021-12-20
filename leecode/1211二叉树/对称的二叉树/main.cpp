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

bool isSymmetric(TreeNode* root) {
	if (root == nullptr) {
		return true;
	}
	queue<TreeNode*> que;
	que.push(root->left);
	que.push(root->right);
	while (!que.empty()) {
		TreeNode* left = que.front();
		que.pop();
		TreeNode* right = que.front();
		que.pop();
		if (!left && !right) {
			continue;
		}
		if (!left || !right || (left->val != right->val)) {
			return false;
		}
		que.push(left->left);
		que.push(right->right);
		que.push(left->right);
		que.push(right->left);
	}
	return true;
}