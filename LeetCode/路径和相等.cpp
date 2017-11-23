class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return false;
		int cur_sum = 0;
		return preScan(root, cur_sum, sum);
	}
	bool preScan(TreeNode* root, int cur_sum, int sum)
	{
		cur_sum = cur_sum + root->val;
		if (root->left == NULL && root->right == NULL)
		{
			if (cur_sum == sum)
				return true;
			return false;
		}
		if (root->left && preScan(root->left, cur_sum, sum)) {
			return true;
		}
		if (root->right && preScan(root->right, cur_sum, sum)) {
			return true;
		}
		return false;
	}
};