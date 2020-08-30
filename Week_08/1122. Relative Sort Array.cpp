class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mymap;
        int top = 0;
        
        for (int i : arr1) 
            mymap[i]++;
        for (auto arr : arr2)
            while (mymap[arr]-- > 0)
                arr1[top++] = arr;
        for (auto it : mymap) {
            while (it.second-- > 0)
                arr1[top++] = it.first;
        }
        return arr1;
    }
};