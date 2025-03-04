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
	vector<vector<int>> result;
	vector<int> path;
	void traversal( TreeNode* cur, int count ) {
		if ( !cur->left && !cur->right && count == 0 ) {
			result.push_back( path );
			return;
		}//if
		if ( !cur->left && !cur->right ) return;
		
		if ( cur->left ) {
			path.push_back( cur->left->val );
			count -= cur->left->val;
			traversal( cur->left, count );
			count += cur->left->val;
			path.pop_back();
		}//if
		if ( cur->right ) {
			path.push_back( cur->right->val );
			count -= cur->right->val;
			traversal( cur->right, count );
			count += cur->right->val;
			path.pop_back();
		}//if
	}

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        result.clear();
        path.clear();
        if ( root == NULL ) return result;
        path.push_back( root->val );
        traversal( root, targetSum - root->val );
        return result;
    }
};
