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

//������
int maxDepth(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
	int result = max(maxDepth(root->left), maxDepth(root->right)) + 1;
	return result;
}

//�Գƶ�����
bool isSymmetric(TreeNode* root) {
	return check(root->left, root->right);
}
bool check(TreeNode* rleft, TreeNode* rright) {
	if (!rleft && !rright) {//�����ڵ��Ϊ�սڵ㣬�ǶԳƵ�
		return true;
	}
	if (!rleft || !rright) {//�����ڵ�ֻ��һ���ǿսڵ㣬���Գ�
		return false;
	}
	return (rleft->val == rright->val) && check(rleft->left, rright->right) && check(rleft->right, rright->left);
}

//·���ܺ�
bool hasPathSum(TreeNode* root, int targetSum) {
	if (root == nullptr) {
		return false;
	}
	if (root->left == nullptr && root->right == nullptr) {//�жϸýڵ��Ƿ�ΪҶ�ӽڵ�
		return targetSum == root->val;
	}
	return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

int main() {
	return 0;

}