class Solution {
public:
	std::map<int, vector<int>> t;
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		t.clear();
		preOrder(root, 1);
		DWORD size = t.size();
		vector<vector<int>> v(size);
		auto it = t.begin();
		auto it_end = t.end();
		for (; it != it_end; ++it)
		{
			v[size - 1] = it->second;
			size--;
		}
		return v;
	}
	void preOrder(TreeNode* root, DWORD level)
	{
		if (root == NULL)
			return;
		t[level].push_back(root->val);
		preOrder(root->left, level + 1);
		preOrder(root->right, level + 1);
	}
};