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

int maxDepth(TreeNode* root) {//最大深度
	if (root == nullptr) {
		return 0;
	}
	queue<TreeNode*> que;
	int depth = 0;
	que.push(root);
	while (!que.empty()) {
		int nums = que.size();
		depth++;
		for (int i = 0; i < nums; i++) {
			TreeNode* node = que.front();
			que.pop();
			if (node->left != nullptr) {
				que.push(node->left);
			}
			if (node->right!= nullptr) {
				que.push(node->right);
			}
		}
	}
	return depth;
}
int minDepth(TreeNode* root) {//最小深度
	if (root == nullptr) {
		return 0;
	}
	queue<TreeNode*> que;
	int depth = 0;
	que.push(root);
	while (!que.empty()) {
		int nums = que.size();
		depth++;
		for (int i = 0; i < nums; i++) {
			TreeNode* node = que.front();
			que.pop();
			if (node->left == nullptr && node->right == nullptr) {
				return depth;
			}
			if (node->left != nullptr) {
				que.push(node->left);
			}
			if (node->right != nullptr) {
				que.push(node->right);
			}
		}
	}
	return depth;
}

bool isBalanced(TreeNode* root) {

}
int depth(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}

}