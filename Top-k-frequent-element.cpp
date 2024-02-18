class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        int n = nums.size();

        for(int i=0;i<n;i++){
            frequency[nums[i]]++;
        }

        vector<int> unique;

        for(auto curr:frequency){
            unique.push_back(curr.first);
        }

        int lowerBound = 0, upperBound = unique.size()-1;
        while(lowerBound < upperBound){
            int pivot = unique[lowerBound], availableSlot = lowerBound;
            /**
             * move pivot to end so that its position remain fixed during sorting 
            */
            swap(unique[lowerBound], unique[upperBound]);

            for(int i=lowerBound;i<=upperBound;i++){
                if(frequency[pivot] < frequency[unique[i]]){
                    swap(unique[availableSlot], unique[i]);
                    availableSlot++;
                }
            }
            swap(unique[availableSlot], unique[upperBound]);
            if(availableSlot >= k){
                upperBound = availableSlot; 
            } else {
                lowerBound = availableSlot+1;
            }
        }

        vector<int> result;
        for(int i=0;i<k;i++){
            result.push_back(unique[i]);
        }
        return result;
    }
};