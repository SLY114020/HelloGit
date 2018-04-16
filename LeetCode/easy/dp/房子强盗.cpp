class Solution {
public:
	int rob(vector<int>& nums) {
		int size = nums.size();
		if (size == 0)
			return 0;
		if (size == 1)
			return nums[0];
		if (size == 2)
			return std::max<int>(nums[0], nums[1]);
		if (size == 3)
			return std::max<int>(nums[0] + nums[2], nums[1]);
		int n3 = nums[0];
		int n2 = nums[1];
		int n1 = std::max<int>(nums[0] + nums[2], nums[1]);
		int maxRob = 0;
		for (int i = 3; i < size; ++i)
		{
			int d = nums[i];
			maxRob = std::max<int>(std::max<int>(n3 + d, n2 + d), n1);
			n3 = n2;
			n2 = n1;
			n1 = maxRob;
		}
		return maxRob;
	}
};