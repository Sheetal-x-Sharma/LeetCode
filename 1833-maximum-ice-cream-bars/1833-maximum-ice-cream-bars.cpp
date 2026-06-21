class Solution {
public:

    void countSort(auto &costs, int n){

        int maxi = *max_element(costs.begin(), costs.end());

        vector<int> arr(maxi+1, 0);

        for(int i=0; i<n; i++){
            arr[costs[i]]++;
        }

        costs.clear();

        for(int i=0; i<=maxi; i++){
            while(arr[i]){
                costs.push_back(i);
                arr[i]--;
            }
        }
    }









    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int ans=0;

        countSort(costs, n);
       
        for(int i=0; i<costs.size(); i++){
            if(coins>=costs[i]){
                ans++;
                coins -= costs[i];
            }
            else
            return ans;
        }
        return ans;
    }
};