class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		std::map<int, int> em_manager;
		for (int i = 0; i < employees.size(); ++i)
			em_manager.insert(make_pair(employees[i]->id, i));
		std::queue<int> q;
		q.push(id);
		int imp_sum = 0;
		while (q.empty() == true)
		{
			int index  = q.front();
			q.pop();
			auto it = em_manager.find(index);
			Employee* e = employees[it->second];
			imp_sum = imp_sum + e->importance;
			auto it1 = e->subordinates.begin();
			auto it2 = e->subordinates.end();
			for (; it1 != it2; ++it1)
				q.push(*it1);
		}
		return imp_sum;
	}
};