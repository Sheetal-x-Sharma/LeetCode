class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string result="";

        for(int i=0; i<n; i++){
            char ch = s[i];

            if(ch=='*'){
                if(result.size())
                result.pop_back();
            }
            else if(ch=='#'){
                result += result;
            }
            else if(ch=='%'){
                reverse(result.begin(), result.end());
            }
            else
            result.push_back(ch);
        }
        return result;
    }
};