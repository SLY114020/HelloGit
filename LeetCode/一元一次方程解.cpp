class Solution {
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

	string solveEquation(string equation) {
		enum ValueType { INT = 0, OP =1, X = 2};
		enum OPType { NIL = 0, ADD = 1, SUB = 2};
		#define unknowX  'x'

		int left_c_num = 0;
		int right_c_num = 0;

		bool have_equal = false;

		int before_op = NIL;
		int before_Type = INT;
		int before_value = 1;
		// 
		int left_num_sum = 0;
		int right_num_sum = 0;
		int i = 0;
		int size = equation.size();
		while (i < size )
		{
			if (equation[i] == ' ')
			{
				++i;
				continue;
			}
			if (equation[i] == '=')
			{
				have_equal = true;
				before_op = NIL;
				before_Type = INT;
				before_value = 1;
				++i;
				continue;
			}
			if (isOperator(equation[i]))
			{
				if ((i + 1) < size)
				{
					if (isOperator(equation[i + 1]))
						return "No solution";
				}
				if (equation[i] == '+')
					before_op = ADD;
				else
					before_op = SUB;
				before_Type = OP;
				++i;
				continue;
			}
			//left
			if (equation[i] == unknowX){
				// 还是个未知数，则这个是一个二元方程，
				if (before_Type == X)
					return "No solution";
				if (before_Type == OP)
				{
					if (before_op == ADD || before_op == NIL)
					{
						if (have_equal == false)
							left_c_num++;
						else
							right_c_num++;
					}
					else
					{
						if (have_equal == false)
							left_c_num--;
						else
							right_c_num--;
					}
				}
				if (before_Type == INT)
				{
					if (before_op == ADD || before_op == NIL)
					{
						if (have_equal == false)
							left_c_num = left_c_num + before_value;
						else
							right_c_num = right_c_num + before_value;
					}
					else
					{
						if (have_equal == false)
							left_c_num = left_c_num - before_value;
						else
							right_c_num = right_c_num - before_value;
					}
				}
				// 重置数据
				before_op = NIL;
				before_Type = X;
				before_value = unknowX;
				++i;
				continue;
			}
			if (isNumber(equation[i]))
			{
				if (before_Type == X)
					return "No solution";
				int begin = i;
				int end = i;
				while (isNumber(equation[i]))
				{
					end = i;
					if (i + 1 >= size)
						break;
					i++;
				}
				std::string str = equation.substr(begin, end - begin + 1);
				int num = atoi(str.c_str());
				if (equation[i] == unknowX)
				{
					before_Type = ValueType::INT;
					before_value = num;
					continue;
				}
				else
				{
					if (before_op == OPType::NIL || before_op == OPType::ADD)
					{
						if (have_equal == false)
							left_num_sum = left_num_sum + num;
						else
							right_num_sum = right_num_sum + num;
					}
					else
					{
						if (have_equal == false)
							left_num_sum = left_num_sum - num;
						else
							right_num_sum = right_num_sum - num;
					}
					before_op = OPType::NIL;
					before_Type = ValueType::INT;
					before_value = num;
				}
				if (i + 1 >= size)
					break;
				continue;
			}
			return "No solution";
		}
		cout << left_c_num<< "  "<<right_c_num << endl;
		cout << left_num_sum << "  " << right_num_sum << endl;
		int xs = left_c_num - right_c_num;
		int sum = right_num_sum - left_num_sum;
		if (xs == 0)
		{
			if (sum == 0)
				return "Infinite solution";
			else
				return "No solution";
		}
		else
		{
			char temp[127] = {0};
			sprintf_s( temp, sizeof(temp), "x=%d", sum/xs);
			return temp;
		}
		return "No solution";
	}
};