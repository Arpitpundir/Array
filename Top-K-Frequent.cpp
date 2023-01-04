class Solution {
public:
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
        while(l<=r){
          cout<<l<<" "<<r<<endl;
            int pivot = l;
            int firstLargeInd = pivot+1, lastSmallInd = pivot;
            for(int j = pivot+1;j<=r;j++){
                if(elementFrequency[unique[j]] >= elementFrequency[unique[pivot]]){
                    swap(unique[j], unique[firstLargeInd]);
                    firstLargeInd++;
                    lastSmallInd = j;
                }
            }
            swap(unique[pivot], unique[lastSmallInd]);
            if(lastSmallInd == k-1){
                break;
            }else if(lastSmallInd < k-1){
                l = lastSmallInd+1;
            }else{
                r = lastSmallInd-1;
            }
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(unique[i]);
        }
        return ans;
    }
};