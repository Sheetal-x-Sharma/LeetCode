class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        unordered_map<char, int> mp;

        for(int i=0; i<n; i++){
            char ch = text[i];
            if(ch == 'b' or ch == 'a' or ch == 'l' or ch == 'o' or ch == 'n')
            mp[ch]++;
        }

        int ans=1e9;
        for(auto i: mp){
            char ch = i.first;
            if(ch == 'b' or ch == 'a' or ch == 'n')
            ans = min(ans, mp[ch]);
            else if(ch == 'l' or ch == 'o')
            ans = min(ans, mp[ch]/2);
        }

        if(mp.size() < 5)
        return 0;

        return ans;
    }
};