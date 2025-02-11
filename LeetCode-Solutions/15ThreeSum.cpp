// ��ѡC++11ѡ�-std=c++11����C98�ᱨ�� 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > threeSum(vector<int>& nums) {
    vector< vector<int> > result; // �洢���
    int n = nums.size();
    if (n < 3) return result; // ������鳤��С��3��ֱ�ӷ��ؿս��

    sort(nums.begin(), nums.end()); // ����

    for (int i = 0; i < n - 2; ++i) {
        // �����ظ��� nums[i]
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum < 0) {
                left++; // ��̫С����ָ������
            } else if (sum > 0) {
                right--; // ��̫����ָ������
            } else {
                // �ҵ�һ����Ч����Ԫ��
                result.push_back( {nums[i], nums[left], nums[right]} );
                // �����ظ��� nums[left] �� nums[right]
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

    // ������
    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
