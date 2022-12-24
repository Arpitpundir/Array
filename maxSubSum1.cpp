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

int sum = 0, start, end;
//simplest way of generating maxsum is to compute the sum of all subarrays and then chosse max from them
for(int i = 0;i <n;i++){
    for(int j = i;j < n; j++){
        int tempSum = 0;
        for(int k = i;k <= j;k++){
            tempSum += a[k];
        }
        if(tempSum > sum){
            sum = tempSum;
            start = i;
            end = j;
        }
    }
}
cout<<sum<<" "<<start<<" "<<end;
}