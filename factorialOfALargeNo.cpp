#include<bits/stdc++.h>
using namespace std;

void mult(vector<int> &res, int num){
    int l = res.size();
    int carry = 0;
    for(int i = 0;i < l;i++){
        int product = res[i]* num + carry;
        res[i] = product%10;
        carry = product/10;
    }
    while(carry){
        int newDigit = carry%10;
        carry = carry/10;
        res.push_back(newDigit);
    }
}

void factorial(vector<int> &res, int n){
    res.push_back(1);
    for(int i = 2;i <= n;i++){
        mult(res, i);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> res;
    factorial(res, n);
    for(int i = res.size()-1; i>= 0;i--){
        cout<<res[i];
    }
}