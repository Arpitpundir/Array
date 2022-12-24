#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void transpose(vector<vector<int> >& mat){
    int n = mat[0].size();
    for(int i = 0;i < n; i++){
        for(int j = i+1;j < n;j++){
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > mat(n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            int temp;
            cin>>temp;
            mat[i].push_back(temp);
        }
    }
    transpose(mat);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n/2;j++){
            int temp = mat[i][j];
            mat[i][j] = mat[i][n - j - 1];
            mat[i][n-j-1] = temp;
        }
    }

    for(int i = 0;i < n;i++){
        cout<<endl;
        for(int j = 0;j < n;j++){
            cout<<mat[i][j]<<" ";
        }
    }
}