class Solution {
  public:
    vector<vector<int>> result;
    int s = 0;
    vector<int> path;
    void backtracking(vector<int> &candidates, int target, int idx,
                      vector<bool> used) {
        if (s == target) {
            result.push_back(path);
            return;
        }
        if (s > target)
            return;
        for (int i = idx; i < candidates.size(); i++) {
            if (i > 0 && candidates[i - 1] == candidates[i] &&
                used[i - 1] == false) {
                continue;
            }
            s += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, i + 1, used);
            s -= candidates[i];
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<bool> used = {0};
        used.resize(candidates.size());
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, used);
        return result;
    }
};