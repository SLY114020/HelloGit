class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		int max_deep = 1;
		int cur_deep = 1;
		preScan(root, cur_deep, max_deep);
		return max_deep;
	}
	void preScan(TreeNode* root, int cur_deep, int& max_deep)
	{
		if (cur_deep > max_deep)
			max_deep = cur_deep;
		if (root->left) preScan(root->left, cur_deep + 1, max_deep);
		if (root->right) preScan(root->right, cur_deep+ 1, max_deep);
	}
};