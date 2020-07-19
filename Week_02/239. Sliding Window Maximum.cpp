/**
 * 此解法时间复杂度为O(n3longn),LeetCode提交超时
 * 
 **/
 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int iSize = nums.size();
        vector<int> myVec;
        int j = 0;
        
        for (int i = 0; i < iSize - k + 1; i++) {
            priority_queue<int> myQueue;
            
            myQueue.push(nums[i]);
            for (j = i + 1; j < i + k; j++) {
                myQueue.push(nums[j]);
            }
            myVec.push_back(myQueue.top());
        }
        return myVec;
    }
};

/**
 * 最优解
 * 时间复杂度O(n)
 * 将双端队列deque作为滑动窗口，当队列满了就从前出，
 * 当队尾元素比后加的元素小时队列里的元素要一次出队保队列头的元素是最大值
 **/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
		vector<int> vec;
		int iSize = nums.size();

		for (int i = 0; i < iSize; i++) {
			if (dq.empty() == false && dq.front() == i - k) {
				dq.pop_front();
			}
			while (dq.empty() == false && nums[dq.back()] < nums[i]) {
				dq.pop_back();
			}
			dq.push_back(i);
			if (i >= k - 1) {
				vec.push_back(nums[dq.front()]);
			}
		}
		return vec;
    }
};