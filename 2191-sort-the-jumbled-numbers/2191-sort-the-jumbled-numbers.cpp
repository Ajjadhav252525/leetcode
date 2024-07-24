class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int>ans ;
        vector<pair<int ,pair<int ,int>>>v ;
        vector<string>data ;
        for (int i=0 ;i<nums.size() ; i++) {
            auto it = nums[i] ;
            string original = to_string(it);
            string mapped;
            for (char c : original) {
                mapped += to_string(mapping[c - '0']);
            }
            v.push_back({ stoi(mapped) ,{i ,it}});
        }
        sort(v.begin() ,v.end());
        for(auto it:v)
        {
            ans.push_back(it.second.second);
        }
        return ans ;
    }
};