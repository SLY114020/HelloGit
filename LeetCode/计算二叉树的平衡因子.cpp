class Solution {
public:
	bool is_balance;
	bool isBalanced(TreeNode* root) {
		is_balance = true;
		preScan(root); 
		return is_balance;
	}
	int preScan(TreeNode* node)
	{
		int ldeep = 0;
		int rdeep = 0;
		if (node->left != NULL)
		{
			ldeep = preScan(node->left) + 1;
		}
		if (node->right != NULL)
		{
			rdeep = preScan(node->right) + 1;
		}
		if (abs(ldeep - rdeep) >= 2)
		{
			is_balance = false;
			return 100;
		}
		return ldeep > rdeep ? ldeep : rdeep;
	}
};