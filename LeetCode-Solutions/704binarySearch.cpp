#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // �ҵ�Ŀ��ֵ
        if (arr[mid] == target)
            return mid;
            
        // ����м�ֵ����Ŀ��ֵ��������벿��
        if (arr[mid] > target)
            right = mid - 1;
            
        // ����м�ֵС��Ŀ��ֵ�������Ұ벿��
        else
            left = mid + 1;
    }
    
    // δ�ҵ�Ŀ��ֵ
    return -1;
}

// ������ʾ��
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 1;
    
    int result = binarySearch(arr, 0, n-1, target);
    
    if (result == -1)
        std::cout << "Ԫ��δ�ҵ�";
    else
        std::cout << "Ԫ��λ������: " << result;
        
    return 0;
}
