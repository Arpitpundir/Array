#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        int temp;
        cin>>temp;
        a[i] = temp;
    }

    //if we think properly than for generating all subarrays we need to chosse all possible values of i and j 
    // as pair where i is ending point and j is starting point we can do so
    for(int i = 0;i < n;i++){//for ending point 
        for(int j = 0; j <= i;j++){// for chossing starting point
        //now we have got a subarray which starts from i and ends at j
        //for printing the subarray we need another loop
        for(int k = j;k <= i;k++){
            cout<<a[k]<<" ";
        }
        cout<<endl;
        }
    }
}