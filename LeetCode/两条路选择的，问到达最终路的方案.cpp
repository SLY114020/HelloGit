class Solution {
public:
	int minSteps(int n) {
		if (n == 1)
			return 0;
		if (n == 2)
			return 2;
		int cur_num = 2;
		int copy_num = 1;
		int deep = 2;
		return find(cur_num, copy_num, deep, n);
	}
	int find(int cur_num, int copy_num, int deep, int n)
	{
		if (cur_num > n)
			return 0;
		if (cur_num == n)
			return deep;
		// ¸´ÖÆÕ³Ìù 
		int val = find(cur_num * 2, cur_num, deep + 2, n);
		if (val) return val;
		// Õ³Ìù
		val = find(cur_num + copy_num, copy_num, deep + 1, n);
		if (val) return val;
		return 0;
	}
};