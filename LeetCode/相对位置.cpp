class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		std::map<int, int> m; 
		int size = nums.size();
		for (int i = 0; i < size; ++i)
			m.insert(std::make_pair(nums[i], i));
		auto it = m.begin();
		auto it_end = m.end();
		std::vector<string> vec(size);
		int count = size;
		for (; it != it_end; ++it)
		{
			switch (count)
			{
			case 1: vec[it->second] = "Gold Medal"; break;
			case 2: vec[it->second] = "Silver Medal"; break;
			case 3: vec[it->second] = "Bronze Medal"; break;
			default: vec[it->second] = to_string(count); break;
			}
			count--;
		}
		return vec;
	}
};