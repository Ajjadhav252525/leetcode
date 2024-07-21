class Solution {
    bool ispossible(vector<int>&houses, vector<int>& heaters ,int radius)
    {
         int i=0, j=0; 
         int n = houses.size() ;
         int m  = heaters.size() ;
        while(i<n)
        {
            if(j == m)
            { 
                return false;
            }
            int l = heaters[j] - radius;
            int r = heaters[j] + radius;
            if(houses[i] < l or houses[i] > r)
            {
                j++;
            }
            else
            {
                i++;
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