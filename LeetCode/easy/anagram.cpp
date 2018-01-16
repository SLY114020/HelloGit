#include <hash_map>
class Solution {
public:
	vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
		std::map<int, int> b_map;
		for (int i = 0; i < B.size(); ++i)
			b_map.insert(std::make_pair(B[i],i));
		std::vector<int> result;
		for (int i = 0; i < A.size(); ++i)
		{
			auto it = b_map.find(A[i]);
			if (it != b_map.end())
				result.push_back(it->second);
		}
		return result;
	}
};