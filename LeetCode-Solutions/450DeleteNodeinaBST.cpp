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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if ( root == NULL ) return root;
		if ( root->val == key ) {
			// 两侧空 
			if ( root->left == NULL && root->right == NULL ) {
				delete root;
				return NULL;
			}
			// 单侧空 
			else if ( root->left == NULL ) {
				auto retNode = root->right;
				delete root;
				return retNode;
			} 
			else if ( root->right == NULL ) {
				auto retNode = root->left;
				delete root;
				return retNode;
			}
			// 两侧都不空 
			else {
				TreeNode* cur = root->right;
				while ( cur->left != NULL ) cur = cur->left;
				cur->left = root->left;
				TreeNode* tmp = root;
				root = root->right;
				delete tmp;
				return root;
			}
		} // if root->val == key 
		if ( root->val > key ) root->left = deleteNode( root->left, key );
		if ( root->val < key ) root->right = deleteNode( root->right, key );
		return root;
    }
};
