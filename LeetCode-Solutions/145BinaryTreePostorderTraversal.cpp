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
	//    // 方法一：递归法
	//    void postorder( TreeNode *root, vector<int> &res ){
	//        if ( root == nullptr ) return;
	//        postorder( root->left, res );
	//        postorder( root->right, res );
	//        res.push_back( root->val );
	//    }
	//
	//    vector<int> postorderTraversal(TreeNode* root) {
	//        vector<int> res;
	//        postorder( root, res );
	//        return res;
	//    }
    // 方法二：迭代法
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }//while
        reverse(result.begin(), result.end());
        return result;
    }
}; 












