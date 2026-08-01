class Solution {
public:

    int solve(int i, int j, vector<int> &nums, auto &dp){

        if(i>j)
        return 0;
        if(dp[i][j] != -1)
        return dp[i][j];

        int take_i = nums[i] + min(solve(i+2, j, nums, dp), solve(i+1, j-1, nums, dp));

        int take_j = nums[j] + min(solve(i+1, j-1, nums, dp), solve(i, j-2, nums, dp));

        return dp[i][j] = max(take_i, take_j);
    }



    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(auto i:nums)
        total += i;

        vector<vector<int>> dp(n, vector<int>(n, -1));
        int score_a = solve(0, n-1, nums, dp);
        int score_b = total - score_a;
        return score_a >= score_b;
    }
};