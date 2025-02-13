#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + ((high - low) / 2); // ��ֹ�������ͬ�� (left + right) / 2
            if (nums[mid] == target) return mid;
            else if (target > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }//while 
        return -1;
    }
};

int main() {
    Solution solution;

    // �������� 1
    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    int result1 = solution.search(nums1, target1);
    cout << "�������� 1: " << endl;
    cout << "����: nums = [-1, 0, 3, 5, 9, 12], target = 9" << endl;
    cout << "���: " << result1 << endl; // Ԥ�����: 4
    cout << endl;

//    // �������� 2
//    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
//    int target2 = 2;
//    int result2 = solution.search(nums2, target2);
//    cout << "�������� 2: " << endl;
//    cout << "����: nums = [-1, 0, 3, 5, 9, 12], target = 2" << endl;
//    cout << "���: " << result2 << endl; // Ԥ�����: -1
//    cout << endl;
//
//    // �������� 3 (�Զ����������)
//    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int target3 = 5;
//    int result3 = solution.search(nums3, target3);
//    cout << "�������� 3: " << endl;
//    cout << "����: nums = [1, 2, 3, 4, 5, 6, 7, 8, 9], target = 5" << endl;
//    cout << "���: " << result3 << endl; // Ԥ�����: 4
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
//        cout << "Ŀ��ֵ " << target << " ���±���: " << result << endl;
//    } else {
//        cout << "Ŀ��ֵ " << target << " �������������С�" << endl;
//    }
//
//    return 0;
//}    
