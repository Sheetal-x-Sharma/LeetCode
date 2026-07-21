class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<int> left(n, 0);
        int zero=0;
        bool found=false;
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                if(found){
                    zero=0;
                    found=false;
                }                
                zero++;
            }
            else{
                left[i] = zero; 
                found=true;               
            }
        }

        vector<int> right(n, 0);
        zero=0;
        found=false;
         for(int i=n-1; i>=0; i--){
            if(s[i] == '0'){
                if(found){
                    zero=0;
                    found=false;
                }                
                zero++;
            }
            else{
                right[i] = zero; 
                found=true;               
            }
        }

        int ans=0;
        for(int i=0; i<n; i++){
            if(s[i] == '1')
            ans++;
        }

        int ones=ans;

        for(int i=0; i<n; i++){
           // cout<<"l: "<<left[i]<<" r: "<<right[i]<<endl;
            if(left[i] and right[i]){              

                ans = max(ans, ones+left[i]+right[i]);
            }
        }

        return ans;
    }
};