#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

    //in kadanes algo what we do id we keep on adding no continously and updating our current sum and largest sum
    //var now if current sum becomes -ve at any moment than current sum becomes 0 i.e we are staring taking element 
    //from beginning again because if we include previous element than our sum is onl going to reduce since total sum 
    //including last element is negative , we check every time whenever we go on a new element that whether our current
    //sum is bigger than total sum
    vector<int> a;
    int n;
    cin>>n;
    int currSum = 0, larSum = 0;
    for(int i = 0;i < n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    for(int i = 0;i < n;i++){
        currSum += a[i];
        if(currSum <= 0){
            currSum = 0;
        }
        if(currSum > larSum){
            larSum = currSum;
        }
    }
    cout<<larSum<<endl;
}