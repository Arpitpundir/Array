#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int cases;
    cin>>cases;
    while(cases--){
    int c1, c2, c3, c4;
    cin>>c1>>c2>>c3>>c4;
    int n, m;
    cin>>n>>m;
    int cost = 0;
    vector<int> rik;
    vector<int> cab;
    for(int i = 0;i < n;i++){
        int temp;
        cin>>temp;
        rik.push_back(temp);
    }
    for(int i = 0;i < m;i++){
        int temp;
        cin>>temp;
        cab.push_back(temp);
    }
    int costCab = 0, costRik = 0;
    int cost1 = 0;
    for(int i = 0;i < n; i++){
        costRik += min(c2, c1*rik[i]);
    }
    for(int i = 0;i < m;i++){
        costCab += min(c2, c1*cab[i]);
    }
    costCab = min(c3, costCab);
    costRik = min(c3, costRik);
    cost = min(c4, (costCab + costRik));
    cout<<cost<<endl;
    }
}