class Solution {
public:

    int solve(int i, int j, auto &nums){

        if(i>j)
        return 0;

        int op1 = nums[i] - solve(i+1, j, nums);
        int op2 = nums[j] - solve(i, j-1, nums);


        return max(op1, op2);
    }



    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int diff = solve(0, n-1, nums);
        return diff>=0?true:false;
    }
};