class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {

		std::vector<std::vector<int>> vec;
		if (root == NULL)
			return vec;
		TreeNode* NIL = new TreeNode(0);
		std::deque<TreeNode*> queue;
		queue.push_back(root);
		queue.push_back(NIL);
		int cur_size = 0;
		std::vector<int> sub_vec;
		vec.push_back(sub_vec);
		while (queue.empty() == false)
		{
			TreeNode* node = queue.front();
			if (node == NIL)
			{
				// 这里只有一个空元素，则退出
				if (queue.size() == 1)
					break;
				cur_size++;
				vec.push_back(sub_vec);
				queue.push_back(node);
			}
			else
				vec[cur_size].push_back(node->val);
			if (node->left)
				queue.push_back(node->left);
			if (node->right)
				queue.push_back(node->right);
			queue.pop_front();
		}
		return vec;
	}
};