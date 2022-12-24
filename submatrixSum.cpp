#include<bits/stdc++.h>
using namespace std;

long int submatrixSum(vector<vector<int> > mat){
  int m = mat[0].size();
  int n = mat.size();

  vector<vector<int> > sum(n);
  for(int i = 0;i < n;i++){
    sum[i].resize(m);
  }
  for(int i = 0;i < n; i++){
    for(int j = 0;j < m;j++){
      sum[i][j] = (i+1)*(j+1)*(n-i)*(m-j)*(mat[i][j]);
    }
  }
  long int totSum = 0;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      totSum+=sum[i][j];
    }
  }
  return totSum;
}

int main(){
  int n, m;
  cin>>n>>m;
  vector<vector<int> > mat;
  mat.resize(n);

  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      int temp;
      cin>>temp;
      mat[i].push_back(temp);
    }
  }
  cout<<submatrixSum(mat)<<endl;
}