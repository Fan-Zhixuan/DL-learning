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

class PreorderTraversalTree {//ǰ�����
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		//iterpreorder(root, res);//�ݹ�
		//looppreorder(root, res);//ѭ��
		return res;
	}
	void iterpre(TreeNode* root, vector<int>& res) {
		if (root == nullptr) {
			return;
		}
		res.push_back(root->val);
		iterpre(root->left, res);
		iterpre(root->right, res);
	}
	void looppre(TreeNode* root, vector<int>& res) {
		if (root == nullptr) {
			return;
		}
		stack<TreeNode*> stk;
		TreeNode* node = root;
		while (!stk.empty() || node != nullptr) {
			while (node != nullptr) {
				res.emplace_back(node->val);//emplace_back��push_back���°汾��Ч������
				stk.push(node);
				node = node->left;
			}
			node = stk.top();
			stk.pop();
			node = node->right;
		}

	}
};


class InorderTraversalTree {//�������
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		//iterin(root, res);//�ݹ�
		//loopin(root, res);//ѭ��
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
			res.emplace_back(node->val);//emplace_back��push_back���°汾��Ч������
			stk.pop();
			node = node->right;
		}

	}
};


class PostorderTraversalTree {//�������
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		//iterpost(root, res);//�ݹ�
		//looppost(root, res);//ѭ��
		return res;
	}
	void iterpost(TreeNode* root, vector<int>& res) {
		if (root == nullptr) {
			return;
		}
		iterpost(root->left, res);
		iterpost(root->right, res);
		res.push_back(root->val);
	}
	void looppost(TreeNode* root, vector<int>& res) {
		if (root == nullptr) {
			return;
		}
		stack<TreeNode*> stk;
		TreeNode* node = root;
		TreeNode* prev = nullptr;
		while (!stk.empty() || node != nullptr) {
			while (node != nullptr) {
				stk.push(node);
				node = node->left;
			}
			node = stk.top();
			stk.pop();
			if (node->right == nullptr || node->right==prev) {//����ҽڵ�Ϊ�ջ����ҽڵ��Ѿ����������򽫵�ǰ�ڵ��¼���������ظ��ڵ�
				res.emplace_back(node->val);
				prev = node;
				node = nullptr;
			}
			else {
				stk.emplace(node);
				node = node->right;
			}
			
		}

	}
};

class LevelorderTraversalTree {
public:
	vector<int> Levelorder(TreeNode* root) {//����һά����
		vector<int> res;
		if (root == nullptr) {
			return res;
		}
		queue <TreeNode*> q;
		TreeNode* node = root;
		q.push(node);
		while (!q.empty()) {
			node = q.front();
			q.pop();
			res.emplace_back(node->val);
			while (node->left != nullptr || node->right != nullptr) {
				q.push(node->left);
				q.push(node->right);
			}
		}
		return res;
	}
	vector<vector<int>> levelOrder(TreeNode* root) {//���ض�ά����
		vector <vector <int>> ret;
		if (!root) {
			return ret;
		}

		queue <TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int currentLevelSize = q.size();
			ret.push_back(vector <int>());
			for (int i = 1; i <= currentLevelSize; ++i) {
				auto node = q.front(); q.pop();
				ret.back().push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
		}
	}

	return ret;
}
};



int main()
{
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	node1->left = node2;
	cout << node1->left << endl;


}