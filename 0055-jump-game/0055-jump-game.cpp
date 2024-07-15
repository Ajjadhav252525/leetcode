class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>v ;
        if(nums.size()<=1)return true ;
        for(int i=0  ;i<nums.size()-1 ;i++)
        {
            if(nums[i]==0)
            {
                v.push_back(i) ;
            }
        }
        if(v.size()==0)return  true  ;
        for(int i=0 ;i<v.size() ;i++)
        {
            int ind = v[i] ;
            int k=0 ;
            bool flag =false ;
            while(ind -k >=0)
            {
                if(nums[ind-k] > k)
                {
                    flag =true ;
                    break ;
                }
                k++ ;
            }
            if(!flag)
            {
                return false ;
            }
        }
        return true ;
    }
};