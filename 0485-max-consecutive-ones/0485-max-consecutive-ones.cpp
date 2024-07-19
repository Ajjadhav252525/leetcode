class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0 ;
        int max=0 ;
        int n = nums.size();
        for(int i=0 ; i<n ; i++)
        {
            if(nums[i]==0)
            {
                if( max <=c) {max = c;} 
                c=0 ;
            }
            else if(nums[i]==1)
            {
                c++ ;
            }
        }
        return max>c ? max : c ;
    }
};