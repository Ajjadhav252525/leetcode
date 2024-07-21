class Solution {
public:
    int maxOperations(string s) {
        int ans=0 , cnt=0  ,i=0 ; ;
        while(i<s.size()){
            if(s[i]=='1')
            {
                cnt++ ;
            }
            else
            {
                ans+=cnt ;
                while(i+1<s.size() && s[i]==s[i+1])i++ ;
            }
            i++ ;
        }
        return ans ;
    }
};