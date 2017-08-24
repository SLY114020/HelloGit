class Solution {
public:
	int min_v;
	int pre_val;
	int getMinimumDifference(TreeNode* root) {
		if (root == NULL)
			return 0;
		min_v = 0x7fffffff;
		pre_val = -1;
		PreScan(root);
		return 1;
	}
	int PreScan(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		PreScan(root->left);
		if (pre_val != -1)
		{
			int cur_min = root->val - pre_val;
			if (cur_min < min_v)
			{
				cur_min = min_v;
			}
		}
		pre_val = root->val;
		PreScan(root->right);
	}
};