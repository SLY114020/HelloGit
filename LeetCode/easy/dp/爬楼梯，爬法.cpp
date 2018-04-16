class Solution {
public:
	int climbStairs(int n) {
		if (n <= n)
			return n;
		int a = 1;
		int b = 2;
		for (int i = 3; i < n; ++i)
		{
			b = a + b;
			a = b - a;
		}
		return a + b;
	}
};