class Solution2 {
public:
	int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		if (size == 0)
			return 0;
		int b_nums = nums[0];
		int no_again_size = 1;
		for (int i = 1; i < size; ++i)
		{
			if (nums[i] == b_nums)
				continue;
			b_nums = nums[i];
			nums[no_again_size] = b_nums;
			++no_again_size;
		}
		return no_again_size;
	}
};