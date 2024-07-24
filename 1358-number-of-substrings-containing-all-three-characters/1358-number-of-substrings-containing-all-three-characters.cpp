class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>v(3 , 0);
        int ans = 0 , l = 0 ;
        for(int i=0  ;i<s.size() ; i++)
        {
            v[s[i] - 'a']++ ;
            int mincount =min({v[0] ,v[1], v[2]});
            while(mincount >=1 )
            {
                ans +=s.size()-i ;
                v[s[l]-'a']-- ;
                l++ ;
                mincount =min({v[0] ,v[1], v[2]});
                // ans++ ;
            }
        }
        return ans ;
    }
};