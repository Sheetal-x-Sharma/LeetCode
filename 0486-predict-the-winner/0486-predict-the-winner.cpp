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

    int solveTab(int n, vector<int> &nums){

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                int take_i=nums[i], take_j=nums[j];

                if(j-1>=0)
                take_i = nums[i] + min(dp[i+2][j], dp[i+1][j-1]);
                if(j-2>=0)
                take_j = nums[j] + min(dp[i+1][j-1] , dp[i][j-2]);

                dp[i][j] = max(take_i, take_j);
            }
        }


        return dp[0][n-1];
    }



    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(auto i:nums)
        total += i;

        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // int score_a = solve(0, n-1, nums, dp);

        int score_a = solveTab(n, nums);
        int score_b = total - score_a;
        return score_a >= score_b;
    }
};