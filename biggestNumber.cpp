#include<bits/stdc++.h>
using namespace std;
bool compare(string s1, string s2){
    string s1s2 = s1+s2;
    string s2s1 = s2+s1;
    return s1s2 < s2s1;
}
string biggestNo(vector<string>& a){
    sort(a.begin(), a.end(),compare);

    string res = "";
    for(int i = a.size()-1;i >= 0;i--){
        res += a[i];
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> a;
        for(int i = 0;i < n;i++){
            string temp;
            cin>>temp;
            a.push_back(temp);
        }
        cout<<biggestNo(a)<<endl;
    }
}