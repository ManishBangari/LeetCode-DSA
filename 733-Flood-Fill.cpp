#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  
  void dfs(vector<vector<int>>& image, int sr, int sc, int originalColor, int color){

    if(image[sr][sc]==originalColor){
      image[sr][sc]=color;
      if(sr>=1)  dfs(image, sr - 1, sc, originalColor, color);
      if(sc>=1)  dfs(image, sr, sc-1, originalColor, color);
      if(sr+1<image.size())  dfs(image, sr+1, sc, originalColor, color);
      if(sc+1<image[0].size())  dfs(image, sr, sc + 1, originalColor, color);
    }

    return;
  }

  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

    int originalColor = image[sr][sc];

    if(originalColor!=color)  dfs(image,sr,sc,originalColor,color);
    return image;
    
  }
};