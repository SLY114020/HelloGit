class Solution2 {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		std::map<int, int> n_m;
		for (int i = 0; i < nums.size(); ++i){
			n_m[nums[i]] = i;
		}
		std::vector<int> vec;
		for (int i = 0; i < findNums.size(); ++i)
		{
			bool have_find = false;
			auto it = n_m.find(findNums[i]);
			int j = 0;
			if (it == n_m.end())
				j = nums.size();
			else
				j = it->second + 1;
			for (; j < nums.size(); ++j)
			{
				if (findNums[i] < nums[j])
				{
					vec.push_back(nums[j]);
					have_find = true;
					break;
				}
			}
			if (!have_find)
				vec.push_back(-1);
		}
		return vec;
	}
};