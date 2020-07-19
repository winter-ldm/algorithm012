/**
 * 时间复杂度为O(n),n取决于给定string的大小
 * 用unordered_map<char, int>存储s中的元素，每遇到重复元素，无序map值+1
 * 再遍历t，如果在无序map中找不到该元素即可判断为非Anagram，找到的话该无序map-1，当值为0时把该元素删除
 * 最后如果该无序map中没有元素的话才可判断为Anagram
 **/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> myMap;
        
        if (s.size() != t.size())
            return false;
        
        for (int i = 0; i < s.size(); i++) {
            if (myMap.find(s[i]) != myMap.end())
                myMap[s[i]]++;
            else
                myMap[s[i]] = 1;
        }
        
        for (int i = 0; i < t.size(); i++) {
            if (myMap.find(t[i]) != myMap.end()) {
                if (--myMap[t[i]] == 0)
                    myMap.erase(t[i]);
            }                
            else 
                return false;
        }
        
        if (myMap.size() > 0)
            return false;
        
        return true;
    }
};

/**
 * 最优解
 * s中的元素就将map值+1，t中的就将map值-1，如果s和t中的元素出现次数是一样的，经过这个操作后map中所有值都将是0，
 * 所以再循环取map中的值判断不为0即可得出给定的两个string不为Anagram
 **/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> myMap;
        
        if (s.size() != t.size())
            return false;
        
        for (int i = 0; i < s.size(); i++) {
            myMap[s[i]]++;
            myMap[t[i]]--;
        }
        
        for (auto n : myMap) {
            if (n.second)
                return false;
        }
        return true;
    }
};