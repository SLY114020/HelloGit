class Solution {
public:
	vector<int> findMode(TreeNode* root) {
		std::map<int, int> m;
		preScan(root, m);
		m[1] = 2;
		m[2] = 1;
		auto it = m.begin();
		auto it_end = m.end();
		int max_num = 0;
		vector<int> vec;
		for (; it != it_end; ++it)
		{
			if (it->second > max_num)
			{
				vec.clear();
				max_num = it->second;
				vec.push_back(it->first);
			}
			else if (it->second == max_num)
				vec.push_back(it->first);
		}
		return vec;
	}
	void preScan(TreeNode* root, std::map<int, int>& m)
	{
		if (!root)
			return;
		m[root->val] = m[root->val] + 1;
		preScan(root->left, m);
		preScan(root->right, m);
	}
};