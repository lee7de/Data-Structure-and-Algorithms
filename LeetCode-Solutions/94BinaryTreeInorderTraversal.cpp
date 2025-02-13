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
    // // ����һ���ݹ鷨
    // void inorder( TreeNode* root, vector<int>& res ) {
    //     if ( !root ) return;
    //     inorder( root->left, res );
    //     res.push_back( root->val );
    //     inorder( root->right, res );
    // }

    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     // д�ݹ����ʱ��������дһ�κ����������ݹ������е�OS���ٽ����ĸо�
    //     inorder( root, res );
    //     return res;
    // }

    // ������������
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while ( cur != NULL || !st.empty() ) {
			if ( cur != NULL ) {
				st.push( cur );
				cur = cur->left; //stack: record nodes
			} else {
				cur = st.top();
				st.pop(); // ��Ҫ��д��top���ڴ泬������ 
                //vector: visit nodes
				result.push_back( cur->val ); // push_back can be used in more objects like vector, deque
				cur = cur->right;
			}
		}//while
		return result;
    }

};
