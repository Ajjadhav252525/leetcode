class Solution {
public:
    int findNthDigit(int n) {
        if(n<=9) return n;
        long long size = 1, count = 9;
        while(n > size*count){
            n -= size*count;
            size++;
            count = count*10;
        }
        n--;
        int num = pow(10,size-1) + n/size;
        return to_string(num)[n%size]-'0';
    }
};