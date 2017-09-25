//1 全按
//2 奇按
//3 偶按
//4 3k+1 按
// 3k + 1 决定了有多少种按法
class Solution {
public:
	int flipLights(int n, int m) {
		if (m == 0 || n == 0) return 1;
		if (n == 1) return 2;
		if (n == 2) return m == 1 ? 3 : 4;
		if (m == 1) return 4;
		return m == 2 ? 7 : 8;
	}
};