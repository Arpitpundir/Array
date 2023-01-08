// My solution to the problem: Product of Array Except Self
// O(n) S(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preProduct, sufProduct, ans;
        preProduct.resize(n,0);
        sufProduct.resize(n,0);
        ans.resize(n,0);
        preProduct[0] = 1, sufProduct[n-1] = 1;
        for(int i=1;i<n;i++){
            preProduct[i] = nums[i-1]*preProduct[i-1];
            sufProduct[n-1-i] = nums[n-i]*sufProduct[n-i];
        }
        for(int i=1;i<n-1;i++){
            ans[i] = preProduct[i]*sufProduct[i];
        }
        ans[0] = sufProduct[0];
        ans[n-1] = preProduct[n-1];

        return ans;
    }
};


//Space Complexity: O(1)
class Solution {
    public int[] productExceptSelf(int[] nums) {

        int length = nums.length;
        int[] answer = new int[length];
        answer[0] = 1;
        for (int i = 1; i < length; i++) {
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // R contains the product of all the elements to the right
        // Note: for the element at index 'length - 1', there are no elements to the right,
        // so the R would be 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--) {
            answer[i] = answer[i] * R;
            R *= nums[i];
        }

        return answer;
    }
}