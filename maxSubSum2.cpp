#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a;
    for(int i = 0;i < n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    //in this method we will be using cumulative array
    //generating cumulative array
    vector<int> cs;
    int sum = 0;
    for(int i = 0;i < n;i++){
        sum += a[i];
        cs.push_back(sum);
    } 

    for(int i = 0;i < n;i++){
        for(int j = 0;j <= i; j++){
            int tempSum = cs[i] - cs[j] + a[j];
        }
    }
}
