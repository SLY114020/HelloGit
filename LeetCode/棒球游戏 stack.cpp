class Solution2 {
public:
	std::stack<int> st;
	void pushInteger(int n)
	{
		st.push(n);
	}
	void pushAdd()
	{
		int top = st.top();
		st.pop();
		int sum = top + st.top();
		st.push(top);
		st.push(sum);
	}
	void pushD()
	{
		st.push(2 * st.top());
	}
	void popC()
	{
		st.pop();
	}
	int calPoints(vector<string>& ops) {
		for (int i = 0; i < ops.size(); ++i)
		{
			char tmp = ops[i][0];
			if (tmp == '-' || ('0' <= tmp && tmp <= '9'))
				this->pushInteger(atoi(ops[i].c_str()));
			else if ('+' == tmp)
				this->pushAdd();
			else if ('D' == tmp)
				this->pushD();
			else
				this->popC();

		}
		int sum = 0;
		while (!st.empty())
		{
			sum = sum + st.top();
			st.pop();
		}
		return sum;
	}
};