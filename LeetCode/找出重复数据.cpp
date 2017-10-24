class Solution2 {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		std::vector<int> vec;
		for (int i = 0; i < nums.size(); ++i)
		{
			while (nums[i])
			{
				if (nums[i] != i + 1)
				{
					if (nums[nums[i] - 1] == nums[i])
					{
						vec.push_back(nums[i]);
						nums[i] = 0;
						break;
					}
					else
					{
						int tmp = nums[nums[i] - 1];
						nums[nums[i] - 1] = nums[i];
						nums[i] = tmp;
					}
					continue;
				}
				break;
			}
		}
		return vec;
	}
};