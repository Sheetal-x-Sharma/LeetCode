class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int p = n/8;
        int r = n%8;

        // 1*8 + 2*8 + 3*8 + .... + p*8 = 8*(p(1+p)/2)
        // + (p+1)*r
        //int sum = 4*p*(p+1)) + (p+1)*r; = (p+1)*(4*p+r);
        return (p+1)*(4*p+r);;
    }
};