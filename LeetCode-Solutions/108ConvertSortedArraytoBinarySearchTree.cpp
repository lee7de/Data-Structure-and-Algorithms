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

// 定义二叉树节点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // 递归构建平衡二叉搜索树
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr; // 递归终止条件

        // 计算中间索引
        int mid = left + (right - left) / 2;

        // 创建根节点
        TreeNode* root = new TreeNode(nums[mid]);

        // 递归构建左子树和右子树
        root->left = traversal(nums, left, mid - 1);
        root->right = traversal(nums, mid + 1, right);

        return root;
    }

public:
    // 将有序数组转换为平衡二叉搜索树
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversal(nums, 0, nums.size() - 1);
    }
};

// 辅助函数：打印二叉树（中序遍历） 
// 逻辑有些问题，可参考重写 
void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "null ";
        return;
    }
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

// 测试用例
int main() {
    Solution solution;
    vector<int> nums = {-10, -3, 0, 5, 9};

    // 将有序数组转换为平衡二叉搜索树
    TreeNode* root = solution.sortedArrayToBST(nums);

    // 打印二叉树（中序遍历）
    cout << "输出：";
    printTree(root);
    cout << endl;

    return 0;
}
