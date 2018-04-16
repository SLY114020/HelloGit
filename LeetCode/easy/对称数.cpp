class Solution {
public:
	int checklr(TreeNode* node)
	{
		if (node->left == NULL && node->right == NULL)
			return 1;
		if (node->left == NULL)
			return 0;
		if (node->right == NULL)
			return 0;
		return 2;
	}
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		int ret = checklr(root);
		if (ret != 2)
		{
			return ret;
		}
		std::vector<TreeNode*>* vec = new std::vector<TreeNode*>;
		std::vector<TreeNode*>* cVec = new std::vector<TreeNode*>;
		vec->push_back(root->left);
		vec->push_back(root->right);
		bool fail = false;
		while (vec->size())
		{
			if (fail)
				break;
			if (vec->size() % 2 != 0)
			{
				fail = true;
				break;
			}
			for (int i = 0; i < vec->size(); ++i)
			{
				int ri = vec->size() - i - 1;
				if ((*vec)[i]->val != (*vec)[ri]->val)
				{
					fail = true;
					break;
				}
				TreeNode* node = (*vec)[i];
				TreeNode* rNode = (*vec)[ri];
				if (node->left && rNode->right)
				{
					cVec->push_back(node->left);
				}
				if (node->right && rNode->left)
				{
					cVec->push_back(node->right);
				}
				if ((node->left && rNode->right == NULL) || (node->right && rNode->left == NULL))
				{
					fail = true;
					break;
				}		
			}
			std::vector<TreeNode*>* tmp = vec;
			vec = cVec;
			cVec = tmp;
			cVec->clear();
		}
		delete vec;
		delete cVec;
		if (fail)
			return false;
		return true;
	}
};