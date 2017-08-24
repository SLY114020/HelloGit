class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		typedef std::map<int, int>::iterator Iter;
		typedef std::map<int, std::set<int>>::iterator Iter2;
		typedef std::set<int>::iterator IterSet;
		std::map<int, int> du;
		std::map<int, std::set<int>> rel;
		for (int i = 0; i < prerequisites.size(); ++i)
		{
			std::set<int>& s = rel[prerequisites[i].first + 1];
			s.insert(prerequisites[i].second + 1);
			Iter it = du.find(prerequisites[i].second + 1);
			if (it == du.end())
			{
				du.insert(std::make_pair(prerequisites[i].second + 1, 1));
			}
			else
			{
				it->second = it->second + 1;
			}
			it = du.find(du[prerequisites[i].first + 1]);
			if (it == du.end())
			{
				du.insert(std::make_pair(prerequisites[i].first + 1, 0));
			}
		}
		std::deque<int> queue;
		Iter it = du.begin();
		Iter it_end = du.end();
		for (; it != it_end; ++it)
		{
			if (it->second == 0)
			{
				queue.push_back(it->first);
			}
		}
		int n = 0;
		while (queue.empty() == false)
		{
			++n;
			auto it = rel.find(queue.at(0));
			if (it != rel.end())
			{
				std::set<int>& s = it->second;
				IterSet s_it = s.begin();
				IterSet s_end = s.end();
				for (; s_it != s_end; ++s_it)
				{
					du[*s_it] = du[*s_it] - 1;
					if (du[*s_it] == 0)
						queue.push_back(*s_it);
				}
			}
			queue.pop_front();
		}
		if (n != du.size())
			return false;
		return true;
	}
};