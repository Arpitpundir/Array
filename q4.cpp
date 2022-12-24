#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

void findTriplets(vector<int> a, int target){
    int n = a.size();
    sort(a.begin(), a.end());
    vector<pair<int, pair<int, int> > > res;
    for(int i = 0;i < n;i++){
        if(a[i] > target)
        break;
        else{
            int toFind1 = target - a[i];
            for(int j = i + 1;j < n;j++){
        if(a[j] > toFind1)
        break;
        else{
            int toFind2 = toFind1 - a[j];
            for(int k = j + 1;k < n;k++){
                if(a[k] > toFind2){
                    break;
                }else{
                    if(a[k] == toFind2){
                        pair<int, int> temp1;
                        temp1 = make_pair(a[j], a[k]);
                        pair<int, pair<int, int> > temp2;
                        temp2 = make_pair(a[i], temp1);
                        res.push_back(temp2);
                    }
                }
            }
        }
    }

        }
    }
    for(int i = 0;i < res.size();i++){
        cout<<res[i].first<<", "<<res[i].second.first<<" and "<<res[i].second.second<<endl;
    }
}

int main(){
    int n, target;
    cin>>n;
    vector<int> a;
    for(int i = 0;i < n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    cin>>target;
    findTriplets(a, target);
}