/**
 * 看别人说时间复杂度是O(nlogn), 应该是for循环嵌套了一个时间复杂度为logn的优先队列插入吧
 * 用无序map存储数据，数据作key，出现次数做value，优先队列进行排序第一个总是最大的，当优先队列中的元素超过map-k个时依次取出最大值后弹出循环往复即可
 **/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> vec;
        unordered_map<int, int> mymap;
        priority_queue<pair<int, int>> pq;
        
        for (int num : nums) {
            mymap[num]++;
        }
        for (auto it = mymap.begin(); it != mymap.end(); it++) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > mymap.size() - k) {
                vec.push_back(pq.top().second);
                pq.pop();
            }
        }
        return vec;
    }
};