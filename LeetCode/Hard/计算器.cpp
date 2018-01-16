// 这里的内存泄漏没有处理
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
		if ('+' == ch || ch == '-')
			return true;
		return false;
	}
	void initSVec(string& s, std::vector<Data*>& vec)
	{
		int i = 0;
		while (i < s.size())
		{
			char ch = s[i];
			if (isKuoHao(ch)){
				Data* data = new Data;
				data->value.ch = s[i];
				data->type = KuoHao;
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
				Data* data = new Data;
				data->value.number = number;
				data->type = INT;
				vec.push_back(data);
			}
			else if (isOp(ch)){
				Data* data = new Data;
				data->value.ch = s[i];
				data->type = OP;
				vec.push_back(data);
			}
			else if(isBlank(ch)){
			}
			i = i + 1;
		}
	}
	bool csPush(std::stack<Data*>& c_s, Data* data){
		switch (data->type)
		{
		case INT:
			{
				if (c_s.empty()){
					c_s.push(data);
					return true;
				}
				Data* data1 = c_s.top();
				if (data1->type == OP)
				{
					c_s.pop();
					Data* number2 = c_s.top();
					switch (data1->value.ch)
					{
					case '+':
						number2->value.number += data->value.number;
						break;
					case '-':
						number2->value.number -= data->value.number;
						break;
					default:
						return false;
						break;
					}
					return true;
				}
				c_s.push(data);
			}
			break;
		case OP:
			c_s.push(data);
			break;
		case KuoHao:
			if (data->value.ch == ')'){
				Data* number = c_s.top();
				if (number->type != INT)
					return false;
				c_s.pop();
				Data* KH = c_s.top();
				if (KH->value.ch != '(')
					return false;
				c_s.pop();
				return csPush(c_s, number);
			}
			else{
				c_s.push(data);
			}
			break;
		}
		return true;
	}
	int calculate(string s) {
		std::stack<Data*> c_s;
		std::vector<Data*> vec;
		// 数据识别
		initSVec(s, vec);
		// 计算
		for (auto data : vec){
			if (csPush(c_s, data) == false)
				return 0;
		}
		Data* data = c_s.top();
		c_s.pop();
		if (!c_s.empty())
			return 0;
		return data->value.number;
	}
};