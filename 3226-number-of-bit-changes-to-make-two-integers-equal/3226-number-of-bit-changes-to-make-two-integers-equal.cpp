class Solution {
public:
    int minChanges(int n, int k) {
        string num1=bitset<32>(n).to_string();
        string num2=bitset<32>(k).to_string();
        int cnt=0;
        for(int i=0;i<32;i++)
        {
            if(num1[i]=='0'&&num2[i]=='1')
            {
                return -1;
            }
            if(num1[i]!=num2[i])
            {
                cnt++;
            }
        }
        return cnt;
       
       
       
    }
};
