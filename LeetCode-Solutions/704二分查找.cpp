#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + ((high - low) / 2); // 防止溢出，等同于 (left + right) / 2
            if (nums[mid] == target) return mid;
            else if (target > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }//while 
        return -1;
    }
};

int main() {
    Solution solution;

    // 测试用例 1
    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    int result1 = solution.search(nums1, target1);
    cout << "测试用例 1: " << endl;
    cout << "输入: nums = [-1, 0, 3, 5, 9, 12], target = 9" << endl;
    cout << "输出: " << result1 << endl; // 预期输出: 4
    cout << endl;

//    // 测试用例 2
//    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
//    int target2 = 2;
//    int result2 = solution.search(nums2, target2);
//    cout << "测试用例 2: " << endl;
//    cout << "输入: nums = [-1, 0, 3, 5, 9, 12], target = 2" << endl;
//    cout << "输出: " << result2 << endl; // 预期输出: -1
//    cout << endl;
//
//    // 测试用例 3 (自定义测试用例)
//    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int target3 = 5;
//    int result3 = solution.search(nums3, target3);
//    cout << "测试用例 3: " << endl;
//    cout << "输入: nums = [1, 2, 3, 4, 5, 6, 7, 8, 9], target = 5" << endl;
//    cout << "输出: " << result3 << endl; // 预期输出: 4
//    cout << endl;

    return 0;
}

//int main() {
//    vector<int> nums = {-1, 0, 3, 5, 9, 12};
//    int target = 9;
//
//    int result = search(nums, target);
//
//    if (result != -1) {
//        cout << "目标值 " << target << " 的下标是: " << result << endl;
//    } else {
//        cout << "目标值 " << target << " 不存在于数组中。" << endl;
//    }
//
//    return 0;
//}    
