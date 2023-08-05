class Solution {
  public:
    int s = 0;
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &candidates, int target, int idx) {
        if (s == target) {
            result.push_back(path);
            return;
        }
        if (idx == candidates.size() || s > target)
            return;
        for (int i = idx; i < candidates.size(); i++) {
            s += candidates[i];
            path.push_back(candidates[i]);
            if (candidates[i] + s > target)
                backtracking(candidates, target, i + 1);
            else
                backtracking(candidates, target, i);
            s -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        backtracking(candidates, target, 0);
        return result;
    }
};