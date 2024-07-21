class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size() ,ans=0 ;
        sort(nums.begin() ,nums.end());
        for(int i=0 ;i<nums.size(); i++)
        {
            for(int j=i+1 ; j<nums.size() ;j++)
            {
                int ok = nums[i]+nums[j] ;
                int ind = lower_bound(nums.begin()+j ,nums.end() , ok) - nums.begin() ;
                {
                    ans+= max(0 ,ind -j-1 );
                }
            }
        }
        return (ans) ;
    }
};