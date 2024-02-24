class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nextUniquePosn = 1, currentPosn = 1;
        int n = nums.size();
        while(currentPosn < n){
            if(nums[currentPosn] != nums[currentPosn-1]){
                nums[nextUniquePosn] = nums[currentPosn];
                nextUniquePosn++;
            }
            currentPosn++;
        }
        return nextUniquePosn;
    }
};