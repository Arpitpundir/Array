class Solution {
public:
void print(vector<int> arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> elementFrequency;
        int n = nums.size();
        vector<int> unique;
        for(int i=0;i<n;i++){
            if(elementFrequency.count(nums[i]) == 0){
                elementFrequency[nums[i]] = 1;
                unique.push_back(nums[i]);
            }else{
                elementFrequency[nums[i]]++;
            }
        }

        int l = 0, r = unique.size()-1;
        while(l<r){
            int pivot = l;
            int firstSmallInd = pivot+1, lastLargeInd = pivot;
            int j = pivot+1;
            while(j<=r){
                if(elementFrequency[unique[j]] >= elementFrequency[unique[pivot]]){
                    swap(unique[j], unique[firstSmallInd]);
                    lastLargeInd = firstSmallInd;
                    firstSmallInd++;
                }
                j++;
            }
            swap(unique[pivot], unique[lastLargeInd]);
            if(lastLargeInd == k-1){
                break;
            }else if(lastLargeInd < k-1){
                l = lastLargeInd+1;
            }else{
                r = lastLargeInd-1;
            }
            //print(unique);
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(unique[i]);
        }
        return ans;
    }
};