class Solution {
public:
    int countSubstrings(string s) {
        int sum = 0;
        
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]; j++) sum++;
            for (int j = 0; i - 1 - j >= 0 && i + j < s.size() && s[i - 1 - j] == s[i + j]; j++) sum++;            
        } 
        return sum;
    }
};