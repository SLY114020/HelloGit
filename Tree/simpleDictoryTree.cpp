#include <iostream>
#include <string.h>
using namespace std;
const int branchNum = 26;
struct TreeNode
{
	bool isStr;
	TreeNode* next[branchNum];
};
void Insert(TreeNode* node, const char* word)
{
	TreeNode* location = node;
	while (*word != '\0')
	{
		if (location->next[*word - 'a'] == NULL)
		{
			TreeNode* n_n = new TreeNode;
			n_n->isStr = false;
			memset(n_n->next, NULL, sizeof(n_n->next));

			location->next[*word - 'a'] = n_n;
		}
		location = location->next[*word - 'a'];
		++word;
	}
	location->isStr = true;
}
bool Search(TreeNode* node, const char* word)
{
	TreeNode* location = node;
	while (*word != '\0')
	{
		if (location->next[*word - 'a'] == NULL)
			return false;
		location = location->next[*word - 'a'];
		++word;
	}
	return location && location->isStr;
}
void Delete(TreeNode* node)
{
}
int main()
{
	TreeNode* root = new TreeNode;
	root->isStr = false;
	memset(root->next, NULL, sizeof(root->next));
	Insert(root, "a");
	Insert(root, "b");
	Insert(root, "ab");
	Insert(root, "abcd");
	if (Search(root, "abc"))
	{
		cout <<"ÕÒµ½ab" << endl;
	}
	return 0;
}