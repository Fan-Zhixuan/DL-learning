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
int getMinimumDifference(TreeNode* root) {
	stack<TreeNode*> stk;
	TreeNode* cur = root;
	TreeNode* pre = nullptr;
	int result=INT_MAX;
	while (cur != nullptr || !stk.empty()) {
		if (cur != nullptr) {
			stk.push(cur);
			cur = cur->left;
		}
		else {
			cur = stk.top(); stk.pop();
			if (pre != nullptr ) {
				result = min(result, cur->val - pre->val);
			}
			pre = cur;
			cur = cur->right;
		}
	}
	return result;
}