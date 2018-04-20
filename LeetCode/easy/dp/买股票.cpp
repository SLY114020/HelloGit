class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int max = 0;
		int cur_max_prices = prices[prices.size() - 1];
		for (int i = prices.size() - 2; i >= 0; i--)
		{
			int diff = cur_max_prices - prices[i];
			if (diff > max)
			{
				max = diff;
			}
			else if (diff < 0)
			{
				cur_max_prices = prices[i];
			}
		}
		return max;
	}
};