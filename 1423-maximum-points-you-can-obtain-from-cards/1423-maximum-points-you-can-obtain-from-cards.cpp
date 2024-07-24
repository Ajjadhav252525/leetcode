class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
       int i=0,n  =arr.size() ;
       int maxi = 0 ;
        for(int i=0 ;i<k  ;i++)
        {
            maxi+=arr[i] ;
        }
        int sum=maxi ;
        // maxi=0 ;
        for(int i=0 ;i<k ; i++)
        {
            sum += arr[n-i-1] ;
            sum-= arr[k-i-1] ;
            cout<<sum<<" ";
            maxi =max(maxi ,sum) ;
        }
        return maxi ;
    }
};