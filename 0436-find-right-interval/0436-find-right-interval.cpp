class Solution {
public:
    
    int binarySearch(vector<pair<int,int>>&inv, int end)
    {
        int lo = 0, hi=inv.size()-1;
        int ans=-1;
        while(lo<=hi)
        {
            int mid = lo+(hi-lo)/2;
            if(inv[mid].first >= end){
                ans = inv[mid].second; // index
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) 
    {
        int n=intervals.size();
         if(intervals.size()==1)
        {
            if(intervals[0][0]==intervals[0][1])
            {
                return {0} ;
            }
            else
            {
                return {-1} ;
            }
        }
        vector<pair<int, int>>inv;
        
        for(int i=0;i<intervals.size();i++){
            inv.push_back({intervals[i][0], i});
        }
        
        sort(inv.begin(), inv.end()); // sort on the basis of start
        vector<int>ans(n,-1);
        
        int i=0;
        for(auto &x : intervals)
        {
            int end = x[1];
            int idx  = binarySearch(inv, end);
            ans[i++] = idx; 
        }
        return ans;
    }
};