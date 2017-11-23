class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (root == NULL)
			return root;
		root = preScan(root, L, R);
		return NULL;
	}
	TreeNode* preScan(TreeNode* root, int L, int R)
	{
		if (root == NULL)
			return NULL;
		if (root->val < L) return preScan(root->right, L, R);
		if (root->val > R) return preScan(root->left, L, R);
		if (L <= root->val && root->val <= R)
		{
			root->left = preScan(root->left, L, R);
			root->right = preScan(root->right, L, R);
		}
	}
};