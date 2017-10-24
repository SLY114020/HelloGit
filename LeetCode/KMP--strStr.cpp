class Solution2 {
public:
	void createNext(const string& needle, int* next)
	{
		int size = needle.size();
		int k = -1;
		int i = 0;
		next[0] = -1;
		for (; i < size; )
		{
			if (k == -1 || needle[k] == needle[i])
			{
				i++;
				k++;
				next[i] = k;
			}
			else
				k = next[k] ;
		}
	}
	int strStr(string haystack, string needle) {
		//构建next数组
		int* next = NULL;
		int n_size = needle.size();
		if (n_size == 0)
			return 0;
		next = new int[n_size + 1];
		createNext(needle, next);
		int h_size = haystack.size();
		int i, j;
		i = 0;
		j = 0;
		while (i < h_size)
		{
			if (j == -1 || haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
			{
				j = next[j];       //消除了指针i的回溯 
			}
			if (j == n_size)
				return i - n_size;
		}
		return -1;
	}
};