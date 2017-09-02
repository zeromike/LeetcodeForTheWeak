class Solution {
public:
  bool isValidSerialization(string preorder) {
    if (preorder.size() == 0)
      return false;
    int capacity = 1;
    for (int i = 0; i <= preorder.size(); ++i) {
      if (i == preorder.size() || preorder[i] == ',') {
        // Either null or non-null node consumes capacity by 1.
        capacity -= 1;
        if (capacity < 0)
          return false;
        // Non-null node can have 2 children.
        if (preorder[i - 1] != '#')
          capacity += 2;
      }
    }
    return (capacity == 0);
  }
};