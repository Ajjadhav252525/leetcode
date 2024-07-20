class Solution {
public:
    int hIndex(vector<int>& c) {
        int ans =0,low = 0, n = c.size(), high =1000;
        for(int i=0 ; i<n ; i++)
        {
            if(c[i] >= n-i)
            {
                ans =max(ans ,n-i);
            }
        }
        return ans ;
    }
};