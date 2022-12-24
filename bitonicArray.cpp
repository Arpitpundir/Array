#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int maxLength(vector<long int> a){
    long int n = a.size();
    long int maxLen = 0, lastEle = 1, tempLen = 1, status = 1;
    for(long int i = 1;i < n;i++){
       // cout<<tempLen<<endl;
        if(a[i] == a[i-1]){
            tempLen++;
        }
        else if(a[i] < a[i-1] && status == 1){
            status = -1;
            tempLen++;
        }else if(a[i] < a[i-1] && status == -1){
            tempLen++;
        }else if(a[i] > a[i-1] && status == 1){
            tempLen++;
        }else if(a[i] > a[i-1] && status == -1){
            status = 1;
            if(tempLen > maxLen){
                maxLen = tempLen;
            }
            tempLen = lastEle + 1;
        }

        if(a[i] == a[i-1]){
            lastEle++;
        }else{
            lastEle = 1;
        }

    }
    if(tempLen > maxLen){
        return tempLen;
    }
    return maxLen;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long int n;
        cin>>n;
        vector<long int> a;
        for(long int i = 0;i < n;i++){
            int temp;
            cin>>temp;
            a.push_back(temp);
        }
        cout<<maxLength(a)<<endl;
    }
}
