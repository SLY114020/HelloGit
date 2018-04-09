// 计算器二叉树的实现
// 这里的效率有点低
class Solution {
public:
	enum ValueType
	{
		INT,
		OP,
		KuoHao,
	};
	struct Data
	{
		union Value
		{
			const char* string;
			char ch;
			int number;
		};
		Value value;
		ValueType type;
	};
	bool isBlank(char ch){
		if (ch == ' ')
			return true;
		return false;
	}
	bool isKuoHao(char ch){
		if (ch == ')' || ch == '(')
			return true;
		return false;
	}
	bool isNumber(char ch){
		if ('0' <= ch && ch <= '9')
			return true;
		return false;
	}
	bool isOp(char ch){
		switch (ch)
		{
		case '+':case '-':case '*':case '/':
			return true;
			break;
		}
		return false;
	}
	void initSVec(string& s, std::vector<Data>& vec)
	{
		int i = 0;
		while (i < s.size())
		{
			char ch = s[i];
			if (isKuoHao(ch)){
				Data data;
				data.value.ch = s[i];
				data.type = KuoHao;
				vec.push_back(data);
			}
			else if (isNumber(ch)){
				int j = i + 1;
				while (j < s.size())
				{
					if (isNumber(s[j]) == false)
						break;
					j = j + 1;
				}
				std::string n = s.substr(i, j - i);
				i = j - 1;
				int number = atoi(n.c_str());
				Data data;
				data.value.number = number;
				data.type = INT;
				vec.push_back(data);
			}
			else if (isOp(ch)){
				Data data;
				data.value.ch = s[i];
				data.type = OP;
				vec.push_back(data);
			}
			else if (isBlank(ch)){
			}
			i = i + 1;
		}
	}

	struct TreeNode {
		Data data;
		TreeNode *left;
		TreeNode *right;
		TreeNode() : left(NULL), right(NULL) {}
	};
	int isBigOp(char op)
	{
		if (op == '*' || op == '/')
			return 1;
		return 0;
	}
	bool isThan(char op1, char op2)
	{
		return isBigOp(op1) > isBigOp(op2);
	}
	void insert(TreeNode* head, Data& data, TreeNode* parent, TreeNode* root)
	{
		if (head == NULL)
		{
			TreeNode* n = new TreeNode;
			n->data = data;
			if (parent)
				parent->right = n;
			else
				root->left = n;
			return;
		}
		if (data.type == OP)
		{
			if (head->data.type == INT)
			{
				TreeNode* n = new TreeNode;
				n->data = data;
				if (parent)
					parent->right = n;
				else
					root->left = n;
				n->left = head;
				return;
			}
			if (isThan(data.value.ch, head->data.value.ch))
			{
				// 插到低下去
				insert(head->right, data, head, root);
				return;
			}
			TreeNode* n = new TreeNode;
			n->data = data;
			if (parent)
				parent->right = n;
			else
				root->left = n;
			n->left = head;
			return;
		}
		insert(head->right, data, head, root);
	}
	int calculateS(TreeNode* root)
	{
		if (root->left == NULL)
			return root->data.value.number;
		if (root->data.type == OP)
		{
			switch (root->data.value.ch)
			{
			case '+':return calculateS(root->left) + calculateS(root->right);
			case '-':return calculateS(root->left) - calculateS(root->right);
			case '*':return calculateS(root->left) * calculateS(root->right);
			case '/':return calculateS(root->left) / calculateS(root->right);
			}
		}
		return root->left->data.value.number;
	}
	int calculate(string s) {
		std::vector<Data> vec;
		initSVec(s, vec);
		TreeNode* head = new TreeNode;

		for (auto data : vec){
			insert(head->left, data, NULL,head);
		}
		return calculateS(head->left);
	}
};