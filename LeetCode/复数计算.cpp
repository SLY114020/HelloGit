class Solution2 {
public:
	bool isNumber(char c){
		if ('0' <= c && c <= '9')
			return true;
		return false;
	}
	bool isOperator(char c){
		if (c == '+' || c == '-')
			return true;
		return false;
	}
	void parseString(const string& str,int& num, int& numv)
	{
		int size = str.size();
		int index = 0;
		int before_op = 1;
		while (index < size)
		{
			if (isOperator(str[index]))
			{
				if (str[index] == '+')
					before_op = 1;
				else
					before_op = -1;
				index++;
				continue;
			}
			if (isNumber(str[index]))
			{
				int begin = index;
				int end = index;
				while (isNumber(str[index]))
				{
					end = index;
					if (index + 1 >= size)
						break;
					index++;
				}
				std::string sub_str = str.substr(begin, end - begin + 1);
				int n = atoi(sub_str.c_str()) * before_op;
				if (str[index] == 'i')
					numv = numv + n;
				else
					num = num + n;
				continue;
			}
			index++;
		}
	}
	string complexNumberMultiply(string a, string b) {
		int numa = 0;
		int numva = 0;
		int numb = 0;
		int numvb = 0;
		parseString(a, numa, numva);
		parseString(b, numb, numvb);
		int final_num = numa * numb + (-1)* numva* numvb;
		int final_numv = numa * numvb + numb * numva;
		char temp[10];
		sprintf(temp,"%d+%di",final_num, final_numv);
		return temp;
	}
};