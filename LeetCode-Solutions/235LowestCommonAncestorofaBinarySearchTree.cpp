/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
	TreeNode* traversal( TreeNode* cur, TreeNode* p, TreeNode* q ) {
		if ( cur == NULL ) return cur;
		if ( cur->val > p->val && cur->val > q->val ){
			TreeNode* left = traversal( cur->left, p, q );
			if ( left != NULL ) return left;
		} // if
		if ( cur->val < p->val && cur->val < q->val ) {
			TreeNode* right = traversal( cur->right, p, q );
			if ( right != NULL ) return right;
		} // if
		return cur;
	}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		return traversal( root, p, q );   
    }
};
