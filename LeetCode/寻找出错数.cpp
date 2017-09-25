class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		std::bitset<10001> b;
		std::vector<int> v;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (b[nums[i]] == 1)
				v.push_back(nums[i]);
			else
				b[nums[i]] = 1;
		}
		for (int i = 1; i <= nums.size(); ++i)
		{
			if (b[i] == 0)
				v.push_back(i);
		}
		return v;
	}
};