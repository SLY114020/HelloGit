struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> v;
		if (root == NULL)
			return v;
		stack<TreeNode*> s;
		s.push(root);
		while (s.empty() == false)
		{
			TreeNode* node = s.top();
			if (node->left == NULL)
			{
				v.push_back(node->val);
				s.pop();
				while (node)
				{
					if (node->right != NULL)
					{
						s.push(node->right);
						break;
					}
					else
					{
						if (s.empty())
							break;
						node = s.top();
						v.push_back(node->val);
						s.pop();
					}
				}
			}
			else
			{
				s.push(node->left);
			}
		}
		return v;
	}
};