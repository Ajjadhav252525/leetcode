class Solution {
public:
    int hIndex(vector<int>& c) {
        int ans =0,low = 0, n = c.size(), high =c.size()-1;
        while(low<=high)
        {
            int mid =low+(high -low)/2 ;
            if(c[mid] >= n-mid )
            {
                ans = max(ans, n-mid);
                            high =mid-1 ;

            }
            else
            {    low = mid+1 ;
            }
        }
        return ans ;
    }
};