#include <iostream>
using namespace std;

//解法一 --- 递归
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<int, int> index;
public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorderLeft, int preorderRight, int inorderLeft, int inorderRight) {
        if (preorderLeft > preorderRight) {
            return nullptr;
        }

        int preorderRoot = preorderLeft;
        int inorderRoot = index[preorder[preorderRoot]];

        TreeNode * root = new TreeNode(preorder[preorderRoot]);

        int sizeLeftSubtree = inorderRoot - inorderLeft;

        root->left = myBuildTree(preorder, inorder, preorderLeft + 1, preorderLeft + sizeLeftSubtree, inorderLeft, inorderRoot - 1);
        root->right = myBuildTree(preorder, inorder, preorderLeft + sizeLeftSubtree + 1, preorderRight, inorderRoot + 1, inorderRight);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, inorder.size() - 1, 0, inorder.size() - 1);
    }
};

int main() {

    cout << "从前序与中序遍历构造二叉树" << endl;

    return 0;
}