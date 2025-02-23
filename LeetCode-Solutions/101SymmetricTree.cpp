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
	bool compare( TreeNode* left, TreeNode* right ) {
		// nodes is null
		if ( left == NULL && right != NULL ) return false;
		else if ( left != NULL && right == NULL ) return false;
		else if ( left == NULL && right == NULL ) return true;
		// nodes have val
		// but val not equal
		else if ( left->val != right->val ) return false;
		// val is equal
		bool outside = compare( left->left, right->right );
		bool inside = compare( left->right, right->left );
		bool isSame = outside && inside;
		return isSame; // there code can be simplified, but for learn the Principle, i don't
	} 
    bool isSymmetric(TreeNode* root) {
        if ( root == NULL ) return true;
        return compare( root->left, root->right );
    }
};
