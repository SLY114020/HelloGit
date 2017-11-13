class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		int max = 0;
		for (int i = 0; i < nums1.size(); ++i)
		{
			if (nums1[i] > max)
				max = nums1[i];
		}
		std::vector<int> vec;
		if (max == 0)
			return nums1;
		vec.resize(max+1);
		for (int i = 0; i < nums1.size(); ++i)
		{
			vec[nums1[i]] = 1;
		}
		std::vector<int> uni_vec;
		for (int i = 0; i < nums2.size(); ++i)
		{
			if (nums2[i] < vec.size() && vec[nums2[i]])
			{
				uni_vec.push_back(nums2[i]);
			}
		}
		return uni_vec;
	}
};