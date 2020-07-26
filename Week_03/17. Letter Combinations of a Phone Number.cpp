class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> mymap;
        vector<string> vec;
        
        if (digits.size() == 0) {
            return {};
        }
        
        mymap[2] = "abc";
        mymap[3] = "def";
        mymap[4] = "hgi";
        mymap[5] = "jkl";
        mymap[6] = "mno";
        mymap[7] = "pqrs";
        mymap[8] = "tuv";
        mymap[9] = "wxyz";
        
        recursion("", 0, digits, mymap, vec);
        return vec;
    }
    
    void recursion(string s, int level, string digits, unordered_map<int, string> mymap, vector<string> &vec) {
        if (s.size() == digits.size()) {
            vec.push_back(s);
            return ;
        }
        
        string mystr = mymap[digits[level] - '0'];
        for (int i = 0; i < mystr.size(); i++) {
            recursion(s + mystr[i], level + 1, digits, mymap, vec);
        }
    }
};