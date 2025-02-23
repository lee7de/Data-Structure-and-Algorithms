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
private:
	int result = INT_MAX;
	TreeNode* pre = NULL;
	void traversal( TreeNode* cur ) {
		if ( cur == NULL ) return;
		// LXR
		traversal( cur->left );
		if ( pre != NULL ) {
			result = min( result, cur->val - pre->val );
		}
		pre = cur;
		traversal( cur->right );
	}
public:
    int getMinimumDifference(TreeNode* root) {
        traversal( root );
        return result;
    }
};
