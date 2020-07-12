/*
1.nums1有足够空间存储这两个有序数组，所以不用额外开辟空间，空间复杂度为O(1)
2.两个数组的元素数量都为已知，所以可以直接从两数组的末位往前比较，大的数据就存入到nums的最末空位置
3.因为数据存入nums1且为有序数组，所以只要将nums2的数据处理完即可，时间复杂度为O(n)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int sum = m + n - 1, m1 = m - 1, n1 = n - 1;
        while (n1 >= 0) {
            nums1[sum--] = (m1 >= 0 && nums1[m1] > nums2[n1]) ? nums1[m1--] : nums2[n1--];
        }
    }
};