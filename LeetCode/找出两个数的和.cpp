class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		std::map<int, int> rel_nums;
		std::vector<int> v;
		for (int i = 0; i < nums.size(); ++i)
		{
			int rel = target - nums[i];
			auto it = rel_nums.find(rel);
			if (it != rel_nums.end())
			{
				v.push_back(it->second);
				v.push_back(i);
				break;
			}
			rel_nums.insert(make_pair(nums[i], i));
		}
		return v;
	}
};