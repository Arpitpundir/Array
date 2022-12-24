#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int kadanes(vector<int> a){
    int currSum = 0;
    int maxSum = 0;
    for(int i = 0;i < a.size();i++){
        currSum += a[i];
        if(currSum < 0){
            currSum = 0;
        }
        if(currSum > maxSum){
            maxSum = currSum;
        }
    }
    return maxSum;
}

int maxCircularSum(vector<int>& a){//first we are going to calculate legit max sum
//sincs the given array is an circular array therfore now we are going to find cumulative sum
//and the greatest -ve sum this can be found out by inverting the signs of the element and than
//applying kadanes algorithm  cumulativeSum + maxInvertedSum will give the max sum that can when we are considering 
//no wrapping
//and then we can reurn the max of these
    int sum1 = kadanes(a);
    int cumSum = 0;
    for(int i = 0;i < a.size();i++){
        cumSum += a[i];
        a[i] = -a[i];
    }
    int invertSum = kadanes(a);
    int sum2 = cumSum + invertSum;
    return max(sum1, sum2);
}

int main(){
    int n;
    cin>>n;
    vector<int> a;
    for(int i = 0;i < n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    cout<<maxCircularSum(a)<<endl;
}
