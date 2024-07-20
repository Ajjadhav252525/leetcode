class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int>stk ;
        for(auto it:s)
        {
            if(it=="+" || it=="-" || it=="/"||it=="*")
            {
                int one =stk.top();stk.pop() ;
                int two  =stk.top() ;stk.pop() ;
                // cout<<two<< it<<one ;
                if(it=="+")
                {
                    stk.push(one+two) ;
                }
                else if(it=="-")
                {
                    stk.push(two -one);
                }
                else if (it=="*")
                {
                    stk.push(two*one);
                }
                else
                {
                    stk.push(two/one) ;
                }
            }
            else
            {
                bool flag =false;
                int val =0 ;
                if(it[0]=='-')
                {
                    flag = true ;
                    it.erase(it.begin());
                }
                val = stoi(it) ;
                // cout<<val<<" " ;
                stk.push(flag ? -1*val:val) ;
                                // cout<<stk.top()<<" ";

            }
        }
        return stk.top() ;
    }
};