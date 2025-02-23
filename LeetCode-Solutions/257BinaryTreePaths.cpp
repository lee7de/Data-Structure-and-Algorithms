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
	void traversal( TreeNode* cur, vector<int>& path, vector<string>& result){
		path.push_back( cur->val ); // ���� 
		//	��ֹ����	 
		if ( cur->left == NULL && cur->right == NULL ) {
			// ��������ת��Ϊ�ַ��� 
			string sPath;
			// �ȸ�ǰn-1��Ԫ�ؼӼ�ͷ
			for ( int i = 0; i < path.size() - 1; i++ ) { //
				sPath += to_string( path[i] );
				sPath += "->";
			} //for
			// Ȼ��׷�ӵ�n��			
			sPath += to_string( path[path.size() - 1]);
			result.push_back(sPath);
			return;
		}//if
		if ( cur->left ) {
			traversal( cur->left, path, result );
			path.pop_back();
		}
		if( cur->right ) {
			traversal( cur->right, path, result);
			path.pop_back();
		}
	} 
	
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if ( root == NULL ) return result;
        traversal( root, path, result );
        return result;
    }
};
