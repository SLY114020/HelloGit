class SkipList
{
private:
	struct Node
	{
		Node(int val)
		{
			this->val = val;
			this->next.clear();
			this->next.push_back(NULL);
		}
		int val;
		std::vector<Node*> next;
	};
public:
	SkipList()
	{
		header = new Node(0);
	}
	void insert(int val)
	{
		Node* new_node = new Node(val);
		insertNode(new_node, 0);
	}
	bool search(int val)
	{
		int deep = header->next.size() - 1;
		return search(header, val,deep , NULL);
	}
private:
	bool search(Node* begin_node, int val, int deep, Node* end_node)
	{
		if (deep == -1)
			return false;
		if (begin_node == NULL)
			return false;
		if (begin_node == end_node)
			return false;
		Node* pre_node = begin_node;
		if (begin_node == header)
			begin_node = header->next[deep];
		Node* cur_node = begin_node;
		while (cur_node)
		{
			if (cur_node->val == val)
				return true;
			if (cur_node->val > val)
				return search(pre_node, val, deep - 1, cur_node);
			if (cur_node == end_node)
				return false;
			pre_node = cur_node;
			cur_node = cur_node->next[deep];
		}
		return false;
	}
	void insertNode(Node* n_node, int deep)
	{
		if (header->next.size() < deep + 1)
		{
			header->next.push_back(n_node);
			return;
		}
		Node* base_head = header;
		Node* before = base_head;
		while(base_head != NULL)
		{
			if (base_head->next[deep] == NULL)
			{
				Node* new_node = n_node;
				base_head->next[deep] = new_node;
				break;
			}
			if (n_node->val < base_head->val)
			{
				Node* new_node = n_node;
				before->next[deep] = new_node;
				new_node->next[deep] = base_head;
				break;
			}
			before = base_head;
			base_head = base_head->next[deep];
		}
		Node* cur_node = n_node;
		int r = 1 + rand() % 100;
		if (r < 50)
			return;
		n_node->next.push_back(NULL);
		insertNode(cur_node, deep + 1);
	}
	Node* header;
};