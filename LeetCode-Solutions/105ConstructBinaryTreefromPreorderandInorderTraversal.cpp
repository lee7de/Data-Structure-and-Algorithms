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
	 	int rootValue = preorder[ 0 ]; //������preorder.begin()������һ�����󣬷���һ����������ָ�������ĵ�һ��Ԫ��
	 	TreeNode* root = new TreeNode( rootValue );
	 	if ( preorder.size() == 1 ) return root;
	 	
	 	// traversal
	 	int delimiterIndex;
	 	for ( delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++ ) {
	 		if ( inorder[ delimiterIndex ] == rootValue ) break;	
		}//for
		// ����ҿ�����[xx,xx) 
		vector<int> leftInorder( inorder.begin(), inorder.begin() + delimiterIndex );
		vector<int> rightInorder( inorder.begin() + delimiterIndex + 1, inorder.end() );
		// ǰ�������һ��Ԫ���Ƴ��Ƚ��鷳��δ���þ���д��
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
