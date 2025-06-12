public class Solution {
    public int MaxAdjacentDistance(int[] nums) {
        var maxDiff = 0;

        for (int i = 1; i < nums.Length; i++)
            maxDiff = Math.Max(Math.Abs(nums[i] - nums[i - 1]), maxDiff);
        
        return Math.Max(maxDiff, Math.Abs(nums[^1] - nums[0]));   
    }
}