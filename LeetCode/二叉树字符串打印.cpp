class Solution {
public:
	string tree2str(TreeNode* t) {
		if (t == NULL)
			return "";
		std::string str = to_string(t->val);
		FirstSort(t, str);
		return str;
	}
	void FirstSort(TreeNode* t, std::string& str)
	{
		if (t->left == NULL && t->right == NULL)
			return;
		if (t->left != NULL)
		{
			str.append("("+ to_string(t->left->val));
			FirstSort(t->left, str);
			str.append(")");
		}
		else
		{
			str.append("()");
		}
		if (t->right != NULL)
		{
			str.append("(" + to_string(t->right->val));
			FirstSort(t->right, str);
			str.append(")");
		}
	}
};