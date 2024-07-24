class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int cnt=0;
        int low=0;
        int res=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==0) cnt++;
            while(cnt>k)
            {
                if(a[low]==0)cnt--;
                low++;
            }
            res=max(res,i-low+1);
        }
        return res;
        
    }
};