class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = 0, mid = 0;
        
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i].size() != 0 && matrix[i][0] <= target && matrix[i][matrix[i].size() - 1] >= target) {
                left = 0;
                right = matrix[i].size() - 1;
                
                while (left <= right) {
                    mid = left + (right - left) / 2;
                    if (matrix[i][mid] == target) {
                        return true;
                    }
                    else if (matrix[i][mid] > target) {
                        right = mid - 1;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                break;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size() - 1, mid = 0;
        
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        while (low <= high) {
            mid = low + (high - low) / 2;
            
            if (matrix[mid][0] <= target && matrix[mid][matrix[mid].size() - 1] >= target) {
                //处理二层二分查找
                return find(matrix[mid], target);
            }
            else if (matrix[mid][0] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
                  
    bool find(vector<int> &vec, int target) {
        int low = 0, high = vec.size() - 1, mid = 0;
        
        while (low <= high) {
            mid = low + (high - low) / 2;
            
            if (vec[mid] == target) {
                return true;
            }
            else if (vec[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
};