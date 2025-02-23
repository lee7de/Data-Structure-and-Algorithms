///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
// */
//class Solution {
//private:
//	TreeNode* traversal( vector<int>& nums, int left, int right ) {
//		if ( left > right ) return nullptr;
//		int mid = left + ( ( right - left ) / 2 );
//		TreeNode* root = new TreeNode( nums[mid] );
//		root->left = traversal( nums, left, mid - 1 );
//		root->right = traversal( nums, mid + 1, right );
//		return root;
//	}
//public:
//    TreeNode* sortedArrayToBST(vector<int>& nums) {
//        TreeNode* root = traversal( nums, 0, nums.size() - 1 );
//        return root;
//    }
//};


#include <iostream>
#include <vector>
using namespace std;

// ����������ڵ�
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // �ݹ鹹��ƽ�����������
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr; // �ݹ���ֹ����

        // �����м�����
        int mid = left + (right - left) / 2;

        // �������ڵ�
        TreeNode* root = new TreeNode(nums[mid]);

        // �ݹ鹹����������������
        root->left = traversal(nums, left, mid - 1);
        root->right = traversal(nums, mid + 1, right);

        return root;
    }

public:
    // ����������ת��Ϊƽ�����������
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversal(nums, 0, nums.size() - 1);
    }
};

// ������������ӡ����������������� 
// �߼���Щ���⣬�ɲο���д 
void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "null ";
        return;
    }
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

// ��������
int main() {
    Solution solution;
    vector<int> nums = {-10, -3, 0, 5, 9};

    // ����������ת��Ϊƽ�����������
    TreeNode* root = solution.sortedArrayToBST(nums);

    // ��ӡ�����������������
    cout << "�����";
    printTree(root);
    cout << endl;

    return 0;
}
