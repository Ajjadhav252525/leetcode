class Solution {
    bool ispossible(vector<int>&houses, vector<int>& heaters ,int radius)
    {
         int i=0, j=0; 
         int n = houses.size() ;
         int m  = heaters.size() ;
        while(i<n){
            if(j == m){ 
                return false;//coz we have no heater left to cover rest of the houses, so this cant be answer
            }
            
            int l = heaters[j] - radius; //get the left range
            int r = heaters[j] + radius; //get the right range
            if(houses[i] < l or houses[i] > r){
                j++; //if current house is not in the range, check with next heater
            }
            else{
                i++; //if current heater can cover the current house then check for the next house
            }
        }
        return true; 
    }
public:
    int findRadius(vector<int>& g, vector<int>& h) {
        sort(g.begin() ,g.end());
        sort(h.begin() ,h.end());
        int low =0 , high = max(h[h.size()-1] , g[g.size()-1]) ;
        int ans=high ;
        while(low <=high)
        {
            int mid  = low+(high -low)/2 ;
            if(ispossible(g ,h , mid)) 
            {
                ans  =mid;
                high  =mid-1 ;
            }
            else
            {
                low  =mid+1 ;
            }
        }
        return ans ;
    }
};