class Solution {
private:
	vector<vector<int>> result;
	vector<int> path;
	void backtrack( vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used ) {
		if ( sum == target ) {
			result.push_back(path);
			return;
		}
		for ( int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++ ) {
			if ( i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false ) continue;
			sum += candidates[i];
			path.push_back(candidates[i]);
			used[i] = true; // 同一枝 
			backtrack( candidates, target, sum, i + 1, used );
			used[i] = false; // 同一层
			sum -= candidates[i];
			path.pop_back();
		}
	}

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used( candidates.size(), false );
        path.clear();
        result.clear();
        sort( candidates.begin(), candidates.end() );
        backtrack( candidates, target, 0, 0, used );
        return result;
    }
};
