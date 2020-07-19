/**
 * 空间复杂度O(n),这里我问助教动态数组空间复杂度怎么计算，助教告诉我比较复杂一般认为是O(n), 时间复杂度O(n),n取决于strs的大小
 * sort 助教说一般是快速排序，时间复杂度为O(nlogn)，所以整个过程的时间复杂度为O(n2logn) (n平方logn)
 * 用sort将strs[i]的副本t升序排列，然后以t为key,strs[i]为value，即可将Anagrams归类
 **/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vec;
        unordered_map<string, vector<string>> myMap;
        
        for (int i = 0; i < strs.size(); i++) {
            string t = strs[i];
            sort(t.begin(), t.end());
            myMap[t].push_back(strs[i]);
        }
        
        for (auto n : myMap) {
            vec.push_back(n.second);
        }
        return vec;
    }
};