class Solution {
public:
  int largestBSTSubtree(TreeNode *root) {
    int max_size = 0;
    checkAndCountSubtree(max_size, root);
    return max_size;
  }

private:
  bool checkAndCountSubtree(int &max_size, TreeNode *root) {
    if (root == NULL)
      return true;
    int left_size = 0, right_size = 0;
    bool left = checkAndCountSubtree(left_size, root->left);
    bool right = checkAndCountSubtree(right_size, root->right);

    // Largest BST from left or right child
    max_size = max(max_size, max(left_size, right_size));

    // How to judge a BST? left child, right child, root's value
    if (left && right) {
      if (root->left != NULL && findLargestValue(root->left) >= root->val)
        return false;
      if (root->right != NULL && findSmallestValue(root->right) <= root->val)
        return false;
      // tree with current node as root is still a BST
      max_size = max(max_size, left_size + 1 + right_size);
      return true;
    }
    return false;
  }

  int findLargestValue(TreeNode *root) {
    while (root->right != NULL)
      root = root->right;
    return root->val;
  }

  int findSmallestValue(TreeNode *root) {
    while (root->left != NULL)
      root = root->left;
    return root->val;
  }
};