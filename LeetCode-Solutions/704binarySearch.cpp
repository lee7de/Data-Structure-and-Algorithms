#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // 找到目标值
        if (arr[mid] == target)
            return mid;
            
        // 如果中间值大于目标值，查找左半部分
        if (arr[mid] > target)
            right = mid - 1;
            
        // 如果中间值小于目标值，查找右半部分
        else
            left = mid + 1;
    }
    
    // 未找到目标值
    return -1;
}

// 主函数示例
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 1;
    
    int result = binarySearch(arr, 0, n-1, target);
    
    if (result == -1)
        std::cout << "元素未找到";
    else
        std::cout << "元素位于索引: " << result;
        
    return 0;
}
