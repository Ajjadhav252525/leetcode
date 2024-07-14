class Solution {
    bool ok(vector<long long >nums , int mid)
    {
        if(nums[0]>mid)return false ;
        for(int i=0 ;i<nums.size(); i++)
        {
            if(i==0)
            {
                nums[i+1] -= mid-nums[0] ;
            }
            else if(nums[i]>mid)
            {
                    return false ;
            }
            else if(i!=nums.size()-1)
            {
                nums[i+1] = (long long)((long long)nums[i+1] - (long long )(mid - nums[i])) ;
            }
        }
        return true ;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int low = 0 , high = *max_element(nums.begin() ,nums.end()) ;
        int ans=high ;
        vector<long long >num(nums.size()) ;
        for(int i=0 ;i<nums.size() ; i++)
        {
            num[i]= (long long )nums[i] ;
        }
        while(low<=high)
        {
            int mid =low+(high-low)/2 ;
            if(ok(num , mid))
            {
                ans =mid ;
                high = mid-1 ;
            }
            else
            {
                low  =mid+1 ;
            }
        }
        return ans ;
    }
};