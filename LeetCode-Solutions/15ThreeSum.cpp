// 勾选C++11选项（-std=c++11），C98会报错 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > threeSum(vector<int>& nums) {
    vector< vector<int> > result; // 存储结果
    int n = nums.size();
    if (n < 3) return result; // 如果数组长度小于3，直接返回空结果

    sort(nums.begin(), nums.end()); // 排序

    for (int i = 0; i < n - 2; ++i) {
        // 跳过重复的 nums[i]
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum < 0) {
                left++; // 和太小，左指针右移
            } else if (sum > 0) {
                right--; // 和太大，右指针左移
            } else {
                // 找到一个有效的三元组
                result.push_back( {nums[i], nums[left], nums[right]} );
                // 跳过重复的 nums[left] 和 nums[right]
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);

    // 输出结果
    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
