class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		std::vector<int> f;
		f.resize(cost.size(), 0);
		// ³õÊ¼»¯×´Ì¬
		f[0] = cost[0];
		f[1] = cost[1];
		int size = cost.size();
		for (int i = 2; i < size; ++i)
		{
			f[i] = std::min<int>(f[i-1], f[i - 2]) + cost[i];
		}
		return std::min<int>(f[size - 1], f[size-2]);
	}
};