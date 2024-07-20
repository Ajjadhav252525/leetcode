class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0 ,j=-1 ;
        int cnt=0 ;
        while(i<nums.size())
        {
            nums[++j]=nums[i];
            bool flag =false ;
            while(i<nums.size()-1 && nums[i]==nums[i+1])
            {
                flag =true ;
                i++;
            }
            if(flag)
            {
                nums[++j]=nums[i];
            }
            i++;
        }
        return j+1;
    }
};