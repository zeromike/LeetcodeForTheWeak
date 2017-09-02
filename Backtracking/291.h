class Solution {
public:
  bool wordPatternMatch(string pattern, string str) {
    bool success = false;
    backtracking(success, pattern, str, 0, 0);
    return success;
  }

private:
  // map and set together record bijection relationship; they are a candidate.
  unordered_map<char, string> m;
  unordered_set<string> used_words;

  void backtracking(bool &success, string &pattern, string &str,
                    int pattern_pos, int str_pos) {
    if (success)
      return;
    // Either pattern or str is fully consumed, we can't move forward.
    if (pattern_pos >= pattern.size() || str_pos >= str.size()) {
      if (pattern_pos == pattern.size() && str_pos == str.size())
        success = true;
      return;
    }
    char c = pattern[pattern_pos];

    // case 1: c->word mapping exists
    if (m.find(c) != m.end()) {
      string expected = m[c];
      int len = expected.size();
      if (str_pos + len > str.size() || str.substr(str_pos, len) != expected)
        return;
      backtracking(success, pattern, str, pattern_pos + 1, str_pos + len);
    }
    // case 2: c->word mapping not exists yet, try all possible words
    else {
      for (int len = 1; str_pos + len <= str.size(); ++len) {
        string word = str.substr(str_pos, len);
        if (used_words.find(word) != used_words.end())
          continue;
        m[c] = word;
        used_words.insert(word);
        backtracking(success, pattern, str, pattern_pos + 1, str_pos + len);
        used_words.erase(word);
        m.erase(c);
      }
    }
  }
};