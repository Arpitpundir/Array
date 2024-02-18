class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int lowerBound = *min_element(nums.begin(), nums.end());
        int upperBound = *max_element(nums.begin(), nums.end());

        vector<int> frequency, result;
        frequency.resize(upperBound-lowerBound+1, 0);
        for(int i=0;i<nums.size();i++){
            frequency[nums[i] - lowerBound]++;
        }

        for(int i = lowerBound;i<=upperBound;i++){
            while(frequency[i-lowerBound]){
                result.push_back(i);
                frequency[i-lowerBound]--;
            }
        }

        return result;
    }
};