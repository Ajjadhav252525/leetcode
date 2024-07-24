class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(256 ,0) ;
        if(s==t)return s ;
        bool flag =false ;
        for(auto it:t)
        {
            mp[it]++ ;
        }
        int i=0, j=0 ,ans =INT_MAX;
        int cnt=0 ,start =-1;
        int m = t.size() ;
        int n =s.size(); 
        if(m>n)return "";
        while(i<n)
        {
            if(mp[s[i]]>0)
            {
                cnt++ ;
                mp[s[i]]-- ;
            }
            else
            {
                mp[s[i]]-- ;
            }
                while(j<=i &&cnt==m)
                {
                    flag  =true ;
                    if(i-j+1 < ans)
                    {
                        ans = i-j+1 ;
                        start =j ;
                    }
                    mp[s[j]]++ ;
                    if(mp[s[j]] >=1)cnt-- ;
                    j++ ;
                }
            i++ ;
        }
        if(flag==false)
        {
            return "";
        }
        return s.substr(start ,ans) ;
    }
};