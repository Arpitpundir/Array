#include <bits/stdc++.h>
using namespace std;

int sumQuery(int bottomRightRow, int bottomRightCol, int upperLeftRow, int upperLeftCol, vector<vector<int> > pSum)
{
  return pSum[bottomRightRow][bottomRightCol] - pSum[bottomRightRow][upperLeftCol - 1] - pSum[upperLeftRow - 1][bottomRightCol] + pSum[upperLeftRow - 1][upperLeftCol - 1];
}

vector<vector<int>> prefixSum(vector<vector<int>> mat)
{
  int n = mat.size();
  int m = mat[0].size();

  vector<vector<int> > pSum(n+1);
  for (int i = 0; i < n+1; i++)
  {
    pSum[i].resize(m+1);
  }
  pSum[1][1] = mat[1][1];
  pSum[0][0] = 0;
  pSum[0][1] = 0;
  pSum[1][0] = 0;
  for (int i = 1; i < n+1; i++)
  {
    pSum[i][0] = 0;
    pSum[i][1] = pSum[i - 1][1] + mat[i-1][0];
  }

  for (int i = 1; i < m+1; i++)
  {
    pSum[0][i] = 0;
    pSum[1][i] = pSum[1][i - 1] + mat[0][i-1];
  }

  for (int i = 2; i < n+1; i++)
  {
    for (int j = 2; j < m+1; j++)
    {
      pSum[i][j] = pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1] + mat[i-1][j-1];
    }
  }
  return pSum;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int temp;
      cin >> temp;
      mat[i].push_back(temp);
    }
  }

  vector<vector<int>> pSum;
  pSum = prefixSum(mat);
  for(int i = 0;i < n+1;i++){
    for(int j = 0;j < m+1;j++){
      cout<<pSum[i][j]<<" ";
    }
    cout<<endl;
  }
  int x1, y1, x2, y2;
  cin>>x1>>y1>>x2>>y2;

  cout<<sumQuery(x2, y2, x1, y1, pSum)<<endl;
}