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
	int getDepth( TreeNode* node ) {
		if ( node == NULL ) return 0;
		int leftDepth = getDepth( node->left );
		int rightDepth = getDepth( node->right );
		if ( node->left == NULL && node->right != NULL ) return 1 + rightDepth;
		if ( node->left != NULL && node->right == NULL ) return 1 + leftDepth;
		int result = 1 + min( leftDepth, rightDepth );
		return result;	
	}
	
    int minDepth(TreeNode* root) {
        return getDepth( root );
    }
};
