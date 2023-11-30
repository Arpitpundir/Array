/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const numDict = new Map();
    for(let i = 0;i<nums.length; i++){
        const complement = target - nums[i];
        if(numDict.has(complement)){
            return new Array(i, numDict.get(complement));
        }
        numDict.set(nums[i], i);
    }  
 };