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
  void flatten(TreeNode* root) {
    if (root == nullptr)
      return;

    flatten(root->left);
    flatten(root->right);

    TreeNode* const left = root->left;    // flattened left
    TreeNode* const right = root->right;  // flattened right

    root->left = nullptr;
    root->right = left;

    // Connect the original right subtree to the end of the new right subtree.
    TreeNode* rightmost = root;
    while (rightmost->right != nullptr)
      rightmost = rightmost->right;
    rightmost->right = right;
  }
};