#include<iostream>
using namespace std;
int ma(long long int a[], int n){
	long long int max = -1000000000;
	for(int i = 0;i < n;i++){
		if(max < a[i]){
			max = a[i];
		}
	}
	return max;
}
int main() {
	int n;
	cin>>n;
	long long int a[n];
	long long int max = -1000000000;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
    int res = ma(a, n);
    cout<<res;
	return 0;
}