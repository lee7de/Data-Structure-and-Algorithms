// 144. Binary Tree Preorder Traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 方法一：递归法
    // void preorder( TreeNode *root, vector<int> &res ) {
        
    //     if ( root == nullptr ) return;
    //     res.push_back(root->val);
    //     preorder( root->left, res );
    //     preorder( root->right, res );
    // }


    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     preorder( root, res);
    //     return res;
    // }

    // 方法二：迭代法
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if ( root == nullptr ) return res;
        st.push(root);
        while ( !st.empty() ) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back( node->val );
            if ( node->right ) st.push( node->right); // 右边先入栈
            if ( node->left ) st.push( node->left );
        }// while
        return res;
    }
}; 
