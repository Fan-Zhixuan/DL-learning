#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class TraversalTree {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		//iterin(root, res);//递归
		//loopin(root, res);//循环
		return res;
	}
	void iterin(TreeNode* root, vector<int>& res) {
		if (root == nullptr) {
			return;
		}
		iterin(root->left, res);
		res.push_back(root->val);
		iterin(root->right, res);
	}
	void loopin(TreeNode* root, vector<int>& res) {
		if (root == nullptr) {
			return;
		}
		stack<TreeNode*> stk;
		TreeNode* node = root;
		while (!stk.empty() || node != nullptr) {
			while (node != nullptr) {
				stk.push(node);
				node = node->left;
			}
			node = stk.top();
			res.emplace_back(node->val);//emplace_back是push_back的新版本，效果更优
			stk.pop();
			node = node->right;
		}
		
	}
};

int main()
{
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	node1->left = node2;
	cout << node1->left << endl;


}