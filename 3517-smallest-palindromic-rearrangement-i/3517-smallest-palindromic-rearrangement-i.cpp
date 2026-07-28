class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        map<char, int> mp;
        for(int i=0; i<n; i++){
            char ch = s[i];
            mp[ch]++;
        }
        string s1="", s2="";
        char odd='X';

        for(auto it:mp){
            int cnt = it.second;
            char ch = it.first;
            if(cnt%2){
                odd = ch;
            }
            int half = cnt/2;
            while(half--){
                s1 += ch;
                s2 += ch;
            }
        }
        if(odd != 'X')
        s1 += odd;

        reverse(s2.begin(), s2.end());
        return s1 + s2;
    }
};