class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> mymap;
        char ch ;
        for (auto c : s) {
            mymap[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (mymap[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};