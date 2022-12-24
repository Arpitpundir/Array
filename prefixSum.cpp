#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > prefixSum(vector<vector<int> > mat){
  int n = mat.size();
  int m = mat[0].size();

  vector<vector<int> > pSum(n);
  for(int i = 0;i < n;i++){
    pSum[i].resize(m);
  }
  pSum[0][0] = mat[0][0];

  for(int i = 1;i < n;i++){
    pSum[i][0] = pSum[i-1][0]+mat[i][0];
  }

  for(int i = 1;i < m;i++){
    pSum[0][i] = pSum[0][i-1]+mat[0][i];
  }

  for(int i = 1;i < n;i++){
    for(int j = 1;j <m;j++){
      pSum[i][j] = pSum[i-1][j]+pSum[i][j-1]-pSum[i-1][j-1]+mat[i][j];
    }
  }
  return pSum;
}

int main(){
  int n, m;
  cin>>n>>m;
  vector<vector<int> > mat(n);
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      int temp;
      cin>>temp;
      mat[i].push_back(temp);
    }
  }

  vector<vector<int> > pSum;
  pSum = prefixSum(mat);

  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      cout<< pSum[i][j]<<" ";
    }
    cout<<endl;
  }
}