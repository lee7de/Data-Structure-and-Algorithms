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
	TreeNode* traversal( vector<int>& inorder, vector<int>& postorder ) {
		// 首先考虑二叉树为空和只有根结点的情况（剪枝，终止） 
		if ( postorder.size() == 0 ) return NULL;
		int rootValue = postorder[ postorder.size() - 1 ]; //后序遍历最后一个结点为根结点 
		TreeNode* root = new TreeNode( rootValue );
		if ( postorder.size() == 1 ) return root;
		
		//然后结合案例假想一颗经典二叉树，写主干逻辑 
		int delimiterIndex;
		for ( delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++ ) {
			if ( inorder[delimiterIndex] == rootValue ) break;
		}
		// 用两个数组切割中序数组，牺牲代码效率，提高可读性、降低首次实现难度 
		vector<int> leftInorder( inorder.begin(), inorder.begin() + delimiterIndex );
		vector<int> rightInorder( inorder.begin() + delimiterIndex +1, inorder.end() );
		postorder.resize( postorder.size() - 1 );
		// 进而切割后序数组
		vector<int> leftPostorder( postorder.begin(), postorder.begin() + leftInorder.size() );
		vector<int> rightPostorder( postorder.begin() + leftInorder.size(), postorder.end() );
		root->left = traversal( leftInorder, leftPostorder );
		root->right = traversal( rightInorder, rightPostorder );
		return root;
	}

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if ( inorder.size() == 0 || postorder.size() == 0 ) return NULL;
		return traversal( inorder, postorder );        
    }
};
