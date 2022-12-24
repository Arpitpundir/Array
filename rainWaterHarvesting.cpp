#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findWater(vector<int> elev){
    int savedWater = 0;
    int i = 0;
    int n = elev.size();
    while(i < n){
        int j = i+1;
        int max = 0;
        for(j = i+1;j < n;j++){
            if(elev[j] >= elev[i]){
                max = elev[j];
                break;
            }else if(max < elev[j]){
                max = elev[j];
            }
        }
        for(int k = i+1;k < j;k++){
            if(k != n-1){
                savedWater += min(elev[i], max) - elev[k];
                //cout<<elev[i]<<" "<<max<<" "<<elev[k]<<endl;
            }
        }
        i = j;
    }
    return savedWater;
}
int main(){
    int n;
    cin>>n;
    vector<int> elev;
    for(int i = 0;i < n;i++){
        int temp;
        cin>>temp;
        elev.push_back(temp);
    }
    cout<<findWater(elev);
}