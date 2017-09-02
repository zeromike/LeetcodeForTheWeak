class Solution {
public:
  vector<vector<string>> wordSquares(vector<string> &words) {
    vector<vector<string>> result;
    vector<string> candidate;
    if (words.size() == 0 || words[0].size() == 0)
      return result;
    backtracking(result, words, candidate);
    return result;
  }

private:
  void backtracking(vector<vector<string>> &result, vector<string> &words,
                    vector<string> &candidate) {
    int N = words[0].size();

    // 1. candidate is already completed
    if (candidate.size() == N) {
      result.push_back(candidate);
      return;
    }

    // 2. make one step forward
    for (const string &word : words) {
      if (!check(candidate, word))
        continue;
      candidate.push_back(word);
      backtracking(result, words, candidate);
      candidate.pop_back();
    }
  }

  bool check(const vector<string> &candidate, const string &word) {
    int pos = candidate.size();
    for (int i = 0; i < candidate.size(); ++i) {
      if (candidate[i][pos] != word[i])
        return false;
    }
    return true;
  }
};