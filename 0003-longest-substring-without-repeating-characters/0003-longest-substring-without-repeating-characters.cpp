class Solution {
public:
    // int lengthOfLongestSubstring(string s) 
    // {
    //     int i=0 ;
    //     for(i=0 ; i<s.size() ; i++)
    //     {
    //         if(s[i]!=' ')
    //         {
    //             break ;
    //         }
    //     }
    //     int n = s.size();
    //     vector<int>v(300 , 0);
    //     int ans = min(n ,1) , l =i ;
    //     for(i=i ;i<n ; i++)
    //     {
    //         v[s[i]]++ ;
    //         while(v[s[i]]>1)
    //         {
    //             v[s[l]]--;
    //             l++;
    //         }
    //         ans = max(ans , i-l+1);
    //     }
    //     return ans ;
    // }
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        if(n==0) return 0;
        int m=0;
        int k=0,j=0;
        for(int i=0;i<n;i++){
            if(mp[s[i]]==0){
                mp[s[i]]++;
                k++;
                // m=max(m,k);
            }
            else{
                m=max(m,k);
                while(j<i && mp[s[i]]>0){
                    mp[s[j]]--;
                    j++;
                    k--;
                }
                k++;
                m=max(m,k);
                mp[s[i]]++;
            }
           
        }
        m=max(m,k);
        return m;
        }
};