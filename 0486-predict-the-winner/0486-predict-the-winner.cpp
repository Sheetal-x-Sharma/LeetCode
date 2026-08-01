class Solution {
public:

    int solve(int i, int j, vector<int> &nums){

        if(i>j)
        return 0;

        int take_i = nums[i] + min(solve(i+2, j, nums), solve(i+1, j-1, nums));

        int take_j = nums[j] + min(solve(i+1, j-1, nums), solve(i, j-2, nums));

        return max(take_i, take_j);
    }



    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(auto i:nums)
        total += i;
        
        int score_a = solve(0, n-1, nums);
        int score_b = total - score_a;
        return score_a >= score_b;
    }
};