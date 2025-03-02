class Solution {
private:
	vector<vector<int>> result;
	vector<int> path;
	void backtrack( int targetSum, int k, int sum, int startIndex ) {
		//sum����������Բ����У�targetSum����0���жϣ�����ѧΪ�˿ɶ��ԣ�����
		if ( path.size() == k ) {
			if ( sum == targetSum ) result.push_back(path);
			return;
		} 
		for ( int i = startIndex; i <= 9; i++ ) {
			sum += i;
			path.push_back(i);
			backtrack( targetSum, k, sum, i + 1 );
			sum -= i;
			path.pop_back();
		}
	} 

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        path.clear();
        backtrack( n, k, 0, 1 );
        return result;
    }
};
