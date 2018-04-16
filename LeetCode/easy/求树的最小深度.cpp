class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		std::vector<TreeNode*>* vec = new std::vector<TreeNode*>;
		std::vector<TreeNode*>* cVec = new std::vector<TreeNode*>;
		vec->push_back(root);
		int minDep = 1;
		bool fail = false;
		while (vec->size())
		{
			for (int i = 0; i < vec->size(); ++i)
			{
				TreeNode* node = vec->at(i);
				if (node->left == NULL && node->right == NULL)
				{
					fail = true;
					break;
				}
				if (node->left)
					cVec->push_back(node->left);
				if (node->right)
					cVec->push_back(node->right);
			}
			std::vector<TreeNode*>* tmp = vec;
			vec = cVec;
			cVec = tmp;
			cVec->clear();
			if (fail)
				break;
			minDep++;
		}
		delete vec;
		delete cVec;
		return minDep;
	}

};