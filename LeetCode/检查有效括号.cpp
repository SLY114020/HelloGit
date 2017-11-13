class Solution3 {
public:
	char getR(char c)
	{
		switch (c)
		{
		case '[':return ']';
		case '{':return '}';
		case '(':return ')';
		case ')':return '(';
		case '}':return '{';
		case ']':return '[';
		}
	}
	bool isValid(string s) {
		std::stack<char> st;
		for (int i = 0; i < s.size(); ++i)
		{
			if (st.size() == 0)
				st.push(getR(s[i]));
			else{
				char top = st.top();
				if (top != s[i])
					st.push(getR(s[i]));
				else st.pop();
			}
		}
		if (st.size())
			return false;
		return true;
	}
};