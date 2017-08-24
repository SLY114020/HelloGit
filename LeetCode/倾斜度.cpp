struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int getMinimumDifference(TreeNode* root) {

	}
	int val;
	int findTilt(TreeNode* root) {
		val = 0;
		if (root == NULL)
			return 0;
		int l_v = left(root->left);
		int r_v = right(root->right);
		int add_v = l_v > r_v ? l_v - r_v : r_v - l_v;
		return val + add_v;
	}
	int left(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int l_v = left(root->left);
		int r_v = right(root->right);
		int add_v = l_v > r_v ? l_v - r_v : r_v - l_v;
		val = val + add_v;
		return root->val + l_v + r_v;
	}
	int right(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int l_v = left(root->left);
		int r_v = right(root->right);
		int add_v = l_v > r_v ? l_v - r_v : r_v - l_v;
		val = val + add_v;
		return root->val + l_v + r_v;
	}
};