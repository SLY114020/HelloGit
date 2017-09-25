class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		if (k <= 0)
			return 0;
		if (root == NULL)
			return 0;
		int deep = 1;
		int val = left(root, deep, k);
		if (val)
			return val;
		return 0;
	}
	int left(TreeNode* root, int& deep, int k)
	{
		if (root == NULL)
			return 0;
		int val = left(root->left, deep, k);
		if (val)
			return val;
		if (deep == k)
			return root->val;
		++deep;
		val = left(root->right, deep, k);
		if (val)
			return val;
	}
};