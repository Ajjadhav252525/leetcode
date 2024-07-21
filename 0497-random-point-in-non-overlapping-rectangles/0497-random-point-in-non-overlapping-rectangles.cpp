class Solution {
public:
    vector<vector<int>>rects;
    int x,y,i;
    Solution(vector<vector<int>>& rect) {
        rects=rect;
        x=rects[0][0]-1;
        y=rects[0][1];
        i=0;
    }
    
    vector<int> pick() {
        if(x!=rects[i][2]){
            ++x;
        }else if(x==rects[i][2] && y!=rects[i][3]){
            x=rects[i][0];
            ++y;
        }else if(x==rects[i][2] && y==rects[i][3]){
            i = (i < rects.size() - 1) ? i + 1 : 0;
            x=rects[i][0];
            y=rects[i][1];
        }

        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */