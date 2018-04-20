class NumArray {
public:
	NumArray(vector<int> nums) :n(1, 0) {
		for (int i = 0; i < nums.size(); i++)
		{
			n.push_back(n[i] + nums[i]);
		}
	}

	int sumRange(int i, int j) {
		return n[j + 1] - n[i];
	}
private:
	vector<int> n;
};