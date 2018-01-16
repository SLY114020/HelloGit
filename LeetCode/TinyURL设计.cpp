class Solution2 {
public:
	std::map<string, string> index;
	std::map<string, string> revIndex;

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		auto it = revIndex.find(longUrl);
		if (it != revIndex.end()) return "http://tinyurl.com/" + it->second;

		static std::string randset = "abcdefghijklmnopqrstuvwxyz0123456789";

		char key[7] = "";
		srand(time(NULL));
		do
		{
			for (int i = 0; i < 6; ++i)
			{
				int index = 1 + rand() % (randset.size() + 1);
				key[i] = randset[index - 1];
			}
		} while (index.find(key) != index.end());
		key[6] = '\0';
		string keyStr(key);
		revIndex.insert(make_pair(longUrl, keyStr));
		index.insert(make_pair(keyStr, longUrl));
		return "http://tinyurl.com/" + keyStr;
	}
	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		int pos = shortUrl.find_last_of("/");
		std::string keyStr = shortUrl.substr(pos + 1);
		auto it = index.find(keyStr);
		if (it == index.end())
			return "http://tinyurl.com/404.html";
		return it->second;
	}
};