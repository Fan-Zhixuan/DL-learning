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

//最大深度
int maxDepth(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
	int result = max(maxDepth(root->left), maxDepth(root->right)) + 1;
	return result;
}

//对称二叉树
bool isSymmetric(TreeNode* root) {
	return check(root->left, root->right);
}
bool check(TreeNode* rleft, TreeNode* rright) {
	if (!rleft && !rright) {//两个节点均为空节点，是对称的
		return true;
	}
	if (!rleft || !rright) {//两个节点只有一个是空节点，不对称
		return false;
	}
	return (rleft->val == rright->val) && check(rleft->left, rright->right) && check(rleft->right, rright->left);
}

//路径总和
bool hasPathSum(TreeNode* root, int targetSum) {
	if (root == nullptr) {
		return false;
	}
	if (root->left == nullptr && root->right == nullptr) {//判断该节点是否为叶子节点
		return targetSum == root->val;
	}
	return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

int main() {
	return 0;

}