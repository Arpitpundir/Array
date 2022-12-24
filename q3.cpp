#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

void findPairs(vector<int> a, int target){
    int n = a.size();
    sort(a.begin(), a.end());
    vector<pair<int, int> > res;
    for(int i = 0;i < n;i++){
        if(a[i] > target)
        break;
        else{
            int toFind = target - a[i];
            for(int j = i + 1;j < n;j++){
                if(a[j] > toFind){
                    break;
                }else{
                    if(a[j] == toFind){
                        pair<int, int> temp;
                        temp = make_pair(a[i], a[j]);
                        res.push_back(temp);
                    }
                }
            }
        }
    }
    for(int i = 0;i < res.size();i++){
        cout<<res[i].first<<" and "<<res[i].second<<endl;
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
    findPairs(a, target);
}