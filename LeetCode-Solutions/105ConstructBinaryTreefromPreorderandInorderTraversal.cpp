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
	TreeNode* traversal ( vector<int>& preorder, vector<int>& inorder ) {
	 	// end condition
		if ( preorder.size() == 0 ) return NULL;
	 	int rootValue = preorder[ 0 ]; //不能用preorder.begin()，这是一个对象，返回一个迭代器，指向向量的第一个元素
	 	TreeNode* root = new TreeNode( rootValue );
	 	if ( preorder.size() == 1 ) return root;
	 	
	 	// traversal
	 	int delimiterIndex;
	 	for ( delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++ ) {
	 		if ( inorder[ delimiterIndex ] == rootValue ) break;	
		}//for
		// 左闭右开区间[xx,xx) 
		vector<int> leftInorder( inorder.begin(), inorder.begin() + delimiterIndex );
		vector<int> rightInorder( inorder.begin() + delimiterIndex + 1, inorder.end() );
		// 前序数组第一个元素移除比较麻烦，未来用精简写法
		preorder.erase( preorder.begin() ); 
		vector<int> leftPreorder( preorder.begin(), preorder.begin() + leftInorder.size() );
		vector<int> rightPreorder( preorder.begin() + leftInorder.size(), preorder.end() );
		
		root->left = traversal( leftPreorder, leftInorder);
		root->right = traversal( rightPreorder, rightInorder );
		return root;
	}

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if ( inorder.size() == 0 || preorder.size() == 0 ) return NULL;
        return traversal( preorder, inorder  );
    }
};
