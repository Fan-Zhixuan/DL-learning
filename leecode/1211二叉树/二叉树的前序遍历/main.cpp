#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
  };
class TraversalTree {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		//iterpreorder(root, res);//递归
		//looppreorder(root, res);//循环
		return res;
	}
	void iterpreorder(TreeNode* root, vector<int>& res) {
		if (root == nullptr) {
			return;
		}
		res.push_back(root->val);
		iterpreorder(root->left, res);
		iterpreorder(root->right, res);
	}
	void looppreorder(TreeNode* root, vector<int>& res) {
		if (root == nullptr) {
			return;
		}
		stack<TreeNode*> stk;
		TreeNode* node = root;
		while (!stk.empty() || node != nullptr) {
			while (node != nullptr) {
				res.emplace_back(node->val);//emplace_back是push_back的新版本，效果更优
				stk.push(node);
				node = node->left;
			}
			node = stk.top();
			stk.pop();
			node = node->right;
		}

	}
};

int main()
{
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	node1->left = node2;
	cout << node1->left << endl;


}