class Solution {
    static bool compare(string &a ,string &b)
    {
        return a+b > b+a ;
    }
public:
    string largestNumber(vector<int>& nums) {
        string ans="" ;
        vector<string>p(nums.size()) ;
        for(int i=0 ;i<nums.size() ; i++)
        {
            p[i] = to_string(nums[i]) ;
        }
        unordered_map<string ,int>mp;
        sort(p.begin() , p.end()  ,compare) ;
        for(auto it:p)
        {
            ans+= it ;
            mp[it]++ ;
        }
        if(mp.size()==1 && p[0]=="0")
        {
            return p[0];
        }
        return ans ;
    }
};