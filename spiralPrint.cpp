#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printSpiral(vector<vector<int> > a){
    int n = a.size();
    int m = a[0].size();
    int firstRow = 0, lastRow = n-1, firstCol = 0, lastCol = m-1;

    for(int i = 0, j = 0;i < (n+1)/2 && j < (m +1)/2;i++, j++){
 //       cout<<"hj"<<endl;
        cout<<a[firstRow][firstCol]<<", ";
        for(int k = firstRow + 1;k <= lastRow; k++){
            cout<<a[k][firstCol]<<", ";
        }
        for(int k = firstCol + 1;k <= lastCol;k++){
            cout<<a[lastRow][k]<<", ";
        }
        if(firstCol != lastCol){
            for(int k = lastRow-1;k >= firstRow;k--){
                cout<<a[k][lastCol]<<", ";
            }
        }
        if(firstRow != lastRow){
            for(int k = lastCol-1;k > firstCol;k--){
                cout<<a[firstRow][k]<<", ";
            }
        }
        firstRow++;
        lastRow--;
        firstCol++;
        lastCol--;
    }
    cout<<"END";
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int> > a;
    a.resize(n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int temp;
            cin>>temp;
            a[i].push_back(temp);
            //cout<<a[i][j]<<endl;
        }
    } 
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
           // cout<<a[i][j]<<endl;
        }
    }
    printSpiral(a);
}