class Solution {
public:
    bool isPerfectSquare(int num) {
        int low =1 ,high =num ;
        while(low<=high)
        {
            long long  mid =low+(high-low)/2 ;
            if((long long )(mid*mid)==num)
            {
                return true ;
            }
            else if((long long )(mid * mid )> num)
            {
                high =mid-1 ;
            }
            else
            {
                low  =mid+1 ;
            }
        }
        return false ;
    }
};