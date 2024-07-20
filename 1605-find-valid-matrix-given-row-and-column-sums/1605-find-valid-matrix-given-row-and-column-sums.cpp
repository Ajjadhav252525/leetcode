class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) {
        vector<vector<int>>res(r.size() , vector<int>(c.size() , 0));
        for(int i=0 ;i<r.size()-1  ;i++)
        {
            int ok =r[i];
            for(int j=0 ;j<c.size() ;j++)
            {
                res[i][j] =min(ok , c[j]) ;
                c[j]-=res[i][j] ;
                ok-=res[i][j];
            }
        }
        for(int i=0 ;i <c.size() ; i++)
        {
            res[r.size()-1][i] =c[i] ;
        }
        return res ;
    }
};