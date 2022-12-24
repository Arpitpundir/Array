import math
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if(len(nums) == 1):
            return
        i = len(nums) - 1
        l = len(nums)
        left = -1
        right = -1
        while(i > 0):
            if(nums[i-1] < nums[i]):
                left = i-1
                break
            i-=1
        if(left == -1):
            nums.reverse()
            return
        minEle = math.inf
        for i in range(left, l):
            if(nums[left] < nums[i] and nums[i] < minEle):
                right = i
                minEle = nums[i]
        nums[left], nums[right] = nums[right], nums[left]
        nums[left+1:] = sorted(nums[left+1:])
        