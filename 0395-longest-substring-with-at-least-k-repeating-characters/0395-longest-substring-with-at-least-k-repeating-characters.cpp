class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstringUtil(s, k, 0, s.length());
    }
    
private:
    int longestSubstringUtil(string s, int k, int start, int end) {
        if (end - start < k) return 0;
        
        int count[26] = {0};
        for (int i = start; i < end; i++) {
            count[s[i] - 'a']++;
        }
        
        for (int i = start; i < end; i++) {
            if (count[s[i] - 'a'] < k) {
                int left = longestSubstringUtil(s, k, start, i);
                int right = longestSubstringUtil(s, k, i + 1, end);
                return max(left, right);
            }
        }
        
        return end - start;
    }
};