#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<vector<int> > mat){
  int n = mat.size();
  int m = mat[0].size();

  vector<vector<int> > suffSum(n);

  for(int i = 0;i < n;i++){
    suffSum[i].resize(m);
  }

  int max = -1000000;

  suffSum[n-1][m-1] = mat[n-1][m-1];
  for(int i = n-2;i>=0;i--){
    suffSum[n-1][i] = suffSum[n-1][i+1]+mat[n-1][i];
  }
  for(int i = n-1;i >= 0;i--){
    suffSum[i][n-1] = suffSum[i+1][n-1]+mat[i][n-1];
  }

  for(int i = n-2;i >= 0;i--){
    for(int j = n-2;j>=0;j--){
      suffSum[i][j] = suffSum[i+1][j]+suffSum[i][j+1]-suffSum[i+1][j+1]+mat[i][j];
    }
    if(max < suffSum[i][j]){
      max = suffSum[i][j];
    }
  }
  return max;
}

int main(){
  int n, m;
  cin>>n>>m;

  vector<vector<int> > mat(n);

  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      int tmp;
      cin>>temp;
      mat[i].push_back(temp);
    }
  }
  cout<<maxSum(mat)<<endl;
}