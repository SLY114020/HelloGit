class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		if (image.empty())
			return image;
		int dir[4][2] = {
			{ -1, 0 },	//ио
			{ 1, 0 },	//об
			{ 0, -1 },  //вС
			{ 0, 1 },	//ср
		};
		vector<vector<int>> nImage;
		vector<vector<bool>> bVec;
		for (int i = 0; i < image.size(); ++i)
		{
			vector<int> v1;
			vector<bool> v2;
			for (int j = 0; j < image[i].size(); ++j)
			{
				v1.push_back(image[i][j]);
				v2.push_back(false);
			}
			nImage.push_back(v1);
			bVec.push_back(v2);
		}
		depFloodFill(nImage, sr, sc, newColor, bVec, dir, image[sr][sc]);
		return nImage;
 	}
	
	void depFloodFill(vector<vector<int>>& nImage, int sr, int sc, int newColor, vector<vector<bool>>& bVec, int dir[4][2], int oldColor)
	{
		if (sr < 0 || sr >= nImage.size())
			return;
		if (sc < 0 || sc >= nImage[0].size())
			return;
		if (bVec[sr][sc])
			return;
		bVec[sr][sc] = true;
		if (nImage[sr][sc] != oldColor)
			return;
		nImage[sr][sc] = newColor;

		for (int i = 0; i < 4; ++i)
		{
			depFloodFill(nImage, sr + dir[i][0], sc + dir[i][1], newColor, bVec, dir, oldColor);
		}
	}
};