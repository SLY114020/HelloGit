class Solution {
public:
	// 将1~9 转换成 字符'1'~'9'
	char itoc(int i)
	{
		return i + '0';
	}
	// 将 '1'~'9' 转换成 字符1~9
	int ctoi(char c)
	{
		return c - '0';
	}
	bool isUnknowX(char c)
	{
		if (c == '.')
			return true;
		return false;
	}

	void widthInit(vector<char>& v, std::set<int>& s)
	{
		// 找到这一行所有缺失的
		std::vector<int> all(10, 0);
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i] != '.')
			{
				all[v[i] - '0'] = 1;
			}
		}
		for (int i = 1; i < all.size(); ++i)
		{
			if (all[i])
				continue;
			s.insert(i);
		}
	}
	void heightInit(vector<vector<char>> b, int j, std::set<int>& s)
	{
		// 筛选s
		for (int i = 0; i < b.size(); ++i)
		{
			if (b[i][j] != '.')
			{
				int n = b[i][j] - '0';
				auto it = s.find(n);
				if (it != s.end())
					s.erase(it);
			}
		}
	}
	void nineInit(vector<vector<char>> b, int si, int sj, std::set<int>& s)
	{
		int begin_w = (sj / 3) * 3;
		int end_w = begin_w + 3;
		int begin_h = (si / 3) * 3;
		int end_h = begin_h + 3;
		for (int i = begin_h; i < end_h; ++i)
		{
			for (int j = begin_w; j < end_w; ++j)
			{
				if (b[i][j] != '.')
				{
					auto it = s.find(ctoi(b[i][j]));
					if (it != s.end())
						s.erase(it);
				}
			}
		}
	}
	// 剔除 字符C
	void widthInitDel(vector<vector<std::set<int>>>& v, int si, int sj, char c, vector<vector<char>>& b)
	{
		for (int j = 0; j < sj; ++j)
		{
			if (j == sj)
				continue;
			if (isUnknowX(b[si][j]))
			{
				v[si][j].erase(ctoi(c));
			}
		}
	}
	void hightInitDel(vector<vector<std::set<int>>>& v, int si, int sj, char c, vector<vector<char>>& b)
	{
		for (int i = 0; i < si; ++i)
		{
			if (i == si)
				continue;
			if (isUnknowX(b[i][sj]))
			{
				v[i][sj].erase(ctoi(c));
			}
		}
	}
	void nineInitDel(vector<vector<std::set<int>>>& v, int si, int sj, char c, vector<vector<char>>& b)
	{
		int begin_w = (sj / 3) * 3;
		int end_w = begin_w + 3;
		int begin_h = (si / 3) * 3;
		int end_h = begin_h + 3;

		for (int i = begin_h; i < si; ++i)
		{
			for (int j = begin_w; j < sj; ++j)
			{
				if (i == si && j == sj)
					continue;
				if (isUnknowX(b[i][j]))
				{
					v[i][j].erase(ctoi(c));
				}
			}
		}
	}

	// 剔除 字符C
	void widthDel(vector<vector<std::set<int>>>& v, int si, int sj, char c, vector<vector<char>>& b)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (j == sj)
				continue;
			if (isUnknowX(b[si][j]))
			{
				v[si][j].erase(ctoi(c));
			}
		}
	}
	void hightDel(vector<vector<std::set<int>>>& v, int si, int sj, char c, vector<vector<char>>& b)
	{
		for (int i = 0; i < 9; ++i)
		{
			if (i == si)
				continue;
			if (isUnknowX(b[i][sj]))
			{
				v[i][sj].erase(ctoi(c));
			}
		}
	}
	void nineDel(vector<vector<std::set<int>>>& v, int si, int sj, char c, vector<vector<char>>& b)
	{
		int begin_w = (sj / 3) * 3;
		int end_w = begin_w + 3;
		int begin_h = (si / 3) * 3;
		int end_h = begin_h + 3;

		for (int i = begin_h; i < end_h; ++i)
		{
			for (int j = begin_w; j < end_w; ++j)
			{
				if (i == si && j == sj)
					continue;
				if (isUnknowX(b[i][j]))
				{
					v[i][j].erase(ctoi(c));
				}
			}
		}
	}
	void delAll(vector<vector<std::set<int>>>& v, int si, int sj, char c, vector<vector<char>>& b)
	{
		widthDel(v, si, sj, c, b);
		hightDel(v, si, sj, c, b);
		nineDel(v, si, sj, c, b);
	}


	bool checkWidth(vector<vector<char>>& b, int si, int sj, int check)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (j == sj)
				continue;
			if (!isUnknowX(b[si][j]))
			{
				if (check == ctoi(b[si][j]))
					return false;
			}
		}
		return true;
	}
	bool checkHight(vector<vector<char>>& b, int si, int sj, int check)
	{
		for (int i = 0; i < 9; ++i)
		{
			if (i == si)
				continue;
			if (!isUnknowX(b[i][sj]))
			{
				if (check == ctoi(b[i][sj]))
					return false;
			}
		}
		return true;
	}
	bool checkNine(vector<vector<char>>& b, int si, int sj, int check)
	{
		int begin_w = (sj / 3) * 3;
		int end_w = begin_w + 3;
		int begin_h = (si / 3) * 3;
		int end_h = begin_h + 3;
		for (int i = begin_h; i < end_h; ++i)
		{
			for (int j = begin_w; j < end_w; ++j)
			{
				if (i == si && j == sj)
					continue;
				if (!isUnknowX(b[i][j]))
				{
					if (check == ctoi(b[i][j]))
						return false;
				}
			}
		}
		return true;
	}
	bool checkAll(vector<vector<char>>& b, int si, int sj, int check)
	{
		if (!checkWidth(b, si, sj, check))
		{
			return false;
		}
		if (!checkHight(b, si, sj, check))
		{
			return false;
		}
		if (!checkNine(b, si, sj, check))
		{
			return false;
		}
		return true;
	}

	bool widthScan(vector<vector<char>>& b, int si, int sj, vector<vector<std::set<int>>>& v)
	{
		if (v[si][sj].size() == 1)
			return true;
		auto it = v[si][sj].begin();
		auto it_end = v[si][sj].end();
		for (; it != it_end; ++it)
		{
			bool have_repeated = false;
			// 横向筛选
			for (int j = 0; j < 9; ++j)
			{
				if (j == sj)
					continue;
				if (isUnknowX(b[si][j]))
				{
					auto v_it = v[si][j].find(*it);
					if (v_it != v[si][j].end())
					{
						have_repeated = true;
						break;
					}
				}
			}
			if (!have_repeated)
			{
				int unique_nums = *it;
				v[si][sj].clear();
				v[si][sj].insert(unique_nums);
				return checkWidth(b, si, sj, unique_nums);
			}
		}
		return true;
	}
	bool hightScan(vector<vector<char>>& b, int si, int sj, vector<vector<std::set<int>>>& v)
	{
		if (v[si][sj].size() == 1)
			return true;
		auto it = v[si][sj].begin();
		auto it_end = v[si][sj].end();
		for (; it != it_end; ++it)
		{
			bool have_repeated = false;
			// 纵向筛选
			for (int i = 0; i < 9; ++i)
			{
				if (i == si)
					continue;
				if (isUnknowX(b[i][sj]))
				{
					auto v_it = v[i][sj].find(*it);
					if (v_it != v[i][sj].end())
					{
						have_repeated = true;
						break;
					}
				}
			}
			if (!have_repeated)
			{
				int unique_nums = *it;
				v[si][sj].clear();
				v[si][sj].insert(unique_nums);
				return checkHight(b, si, sj, unique_nums);
			}
		}
		return true;
	}
	bool nineScan(vector<vector<char>>& b, int si, int sj, vector<vector<std::set<int>>>& v)
	{
		if (v[si][sj].size() == 1)
			return true;
		int begin_w = (sj / 3) * 3;
		int end_w = begin_w + 3;
		int begin_h = (si / 3) * 3;
		int end_h = begin_h + 3;
		auto it = v[si][sj].begin();
		auto it_end = v[si][sj].end();
		for (; it != it_end; ++it)
		{
			bool have_repeated = false;
			for (int i = begin_h; i < end_h; ++i)
			{
				for (int j = begin_w; j < end_w; ++j)
				{
					if (i == si && j == sj)
						continue;
					if (isUnknowX(b[i][j]))
					{
						auto v_it = v[i][j].find(*it);
						if (v_it != v[i][j].end())
						{
							have_repeated = true;
							break;
						}
					}
				}
			}
			if (!have_repeated)
			{
				int unique_nums = *it;
				v[si][sj].clear();
				v[si][sj].insert(unique_nums);
				return checkNine(b, si, sj, unique_nums);
			}
		}
		return true;
	}
	bool scanAll(vector<vector<char>>& b, int si, int sj, vector<vector<std::set<int>>>& v)
	{
		if (!widthScan(b, si, sj, v))
		{
			return false;
		}
		if (!hightScan(b, si, sj, v))
		{
			return false;
		}
		if (!nineScan(b, si, sj, v))
		{
			return false;
		}
		return true;
	}

	void solveSudoku(vector<vector<char>>& board) {
		// 记录空缺中的记录
		vector<vector<std::set<int>>> v(9);
		// 所有未知节点初始化
		for (int i = 0; i < v.size(); ++i)
		{
			for (int j = 0; j < v.size(); ++j)
			{
				std::set<int> s;
				widthInit(board[i], s);
				if (isUnknowX(board[i][j]))
				{
					std::set<int> s1(s.begin(), s.end());
					heightInit(board, j, s1);
					nineInit(board, i, j, s1);
					v[i].push_back(s1);
					if (s1.size() == 1)
					{
						auto it = s1.begin();
						board[i][j] = itoc(*it);
						widthInitDel(v, i, j, board[i][j], board);
						hightInitDel(v, i, j, board[i][j], board);
						nineInitDel(v, i, j, board[i][j], board);
						continue;
					}
				}
				else
					v[i].push_back(s);
			}
		}
		bool have_error = true;
		board = loop(board, v, have_error);
	}

	vector<vector<char>> loop(vector<vector<char>> board, vector<vector<std::set<int>>> v, bool& have_error)
	{
		bool change = true;
		bool have_unknow = true;
		have_error = false;
		while (true)
		{
			change = loopScan(board, v, have_unknow, have_error);
			if (!have_unknow)
				break;
			if (have_error)
			{
				break;
			}
			if (!change)
			{
				bool have_find = false;
				for (int i = 0; i < board.size(); ++i)
				{
					if (have_find) break;
					for (int j = 0; j < board.size(); ++j)
					{
						if (have_find) break;
						if (isUnknowX(board[i][j]))
						{
							for (auto it = v[i][j].begin(); it != v[i][j].end(); ++it)
							{
								board[i][j] = itoc(*it);
								bool error = false;
								vector<vector<std::set<int>>> temp_v = v;
								delAll(temp_v, i, j, board[i][j], board);
								vector<vector<char>> tmp = loop(board, temp_v, error);
								if (!error)
								{
									have_find = true;
									board = tmp;
									break;
								}
								board[i][j] = '.';
							}
							// 待选数，竟然没有答案
							if (!have_find)
							{
								have_error = true;
								return board;
							}
						}
					}
				}
			}
		}
		return board;
	}

	bool loopScan(vector<vector<char>>& board, vector<vector<std::set<int>>>& v, bool& have_unknow, bool& have_error)
	{
		bool have_change = false;
		have_unknow = false;
		have_error = false;
		for (int t = 0; t < 5; ++t)
		{
			for (int i = 0; i < board.size(); ++i)
			{
				for (int j = 0; j < board[i].size(); ++j)
				{
					// 记录所有缺失
					if (isUnknowX(board[i][j]))
					{
						if (!scanAll(board, i, j, v))
						{
							have_error = true;
							return true;
						}
						if (v[i][j].size() == 0)
						{
							have_error = true;
							return true;
						}
						if (v[i][j].size() == 1)
						{
							auto it = v[i][j].begin();
							if (!checkAll(board, i, j, *it))
							{
								have_error = true;
								return true;
							}
							board[i][j] = itoc(*it);
							delAll(v, i, j, board[i][j], board);
							have_change = true;
							continue;
						}
						have_unknow = true;
					}
				}
			}
		}
		return have_change;
	}
};