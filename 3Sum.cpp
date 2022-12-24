class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i-1] == nums[i]) continue;
            int j = i+1, k = n-1;
            while(j<k){
                if((nums[i]+nums[j]+nums[k]) == 0){
                    vector<int> temp{nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    int l = j;
                    while(j<n && nums[j] == nums[l]){
                        j++;
                    }
                    l = k;
                    while(k > j && nums[k] == nums[l]){
                        k--;
                    }
                }
                else if((nums[i]+nums[j]+nums[k]) < 0){
                    j++;
                }else{
                    k--;
                }
                
            }
        }
        return ans;
    }
};