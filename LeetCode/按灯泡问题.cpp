//1 ȫ��
//2 �水
//3 ż��
//4 3k+1 ��
// 3k + 1 �������ж����ְ���
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