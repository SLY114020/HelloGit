class Solution2{
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		std::sort(houses.begin(), houses.end());
		std::sort(heaters.begin(), heaters.end());
		houses.erase(unique(houses.begin(), houses.end()), houses.end());
		heaters.erase(unique(heaters.begin(), heaters.end()), heaters.end());
		int cur_r = 0;
		int j = 0;
		for (int i = 0; i < houses.size(); ++i)
		{
			int min_heater = 0;
			if (j == heaters.size())
				j = heaters.size() - 1;
			for (; j < heaters.size(); ++j)
			{
				int need_r = abs(houses[i] - heaters[j]);
				if (need_r <= cur_r)
				{
					min_heater = need_r;
					break;
				}
				if (min_heater == 0 || need_r < min_heater)
				{
					min_heater = need_r;
				}
				else
				{
					if (j > 0) j--;
					break;
				}
			}
			if (min_heater > cur_r)
				cur_r = min_heater;
		}
		return cur_r;
	}
};