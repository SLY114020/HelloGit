class Solution2 {
public:
	TreeNode* convertBST(TreeNode* root) {
		if (root == NULL)
			return root;
		int big_val = 0;
		preScan(root, big_val);
		return root;
	}
	void preScan(TreeNode* node, int& big_val)
	{
		if (node->right != NULL) preScan(node->right, big_val);
		node->val = node->val + big_val;
		big_val = node->val;
		if (node->left != NULL)	preScan(node->left, big_val);
	}
};