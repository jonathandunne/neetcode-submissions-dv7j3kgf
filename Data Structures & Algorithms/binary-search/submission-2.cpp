class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = right / 2;

        if (nums[left] == target) {
            return left;
        }
        else if (nums[mid] == target) {
            return mid;
        }
        else if (nums[right] == target) {
            return right;
        }

        
        while (left < mid && mid < right) {
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid;
                mid = (right + left) / 2;
            }
            else if (nums[mid] > target) {
                right = mid;
                mid = (right + left) / 2;
            }
        }


        return -1;
    }
};
