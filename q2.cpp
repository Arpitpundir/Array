#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void wavePrint(vector<vector<int> > a){
    int n = a.size();
    int m = a[0].size();
    for(int i = 0;i < m;i++){
        if(i%2 == 0){
            for(int j = 0;j < n;j++){
                cout<<a[j][i]<<", ";
            }
        }else{
            for(int j = n-1;j >= 0;j--){
                cout<<a[j][i]<<", ";
            }
        }
    }

}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int> > a(n);
    for(int i = 0;i < n;i++){
        for(int j = 0; j < m;j++){
            int temp;
            cin>>temp;
            a[i].push_back(temp);
        }
    }
    wavePrint(a);
    cout<<"END";
}