/*
@Copyright:LintCode
@Author:   jasonlin
@Problem:  http://www.lintcode.com/problem/construct-binary-tree-from-preorder-and-inorder-traversal
@Language: C++
@Datetime: 15-09-10 19:44
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
 

class Solution {
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        //if (preorder==NULL||inorder==NULL) return NULL;
        if (preorder.size()==0||inorder.size()==0) return NULL;
        if (preorder.size()!=inorder.size()) return NULL;
        return buildTreeHelper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
private:
    TreeNode *buildTreeHelper(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie) {
        if (ps>pe||is>ie) return NULL;
        int rVal = preorder[ps];
        TreeNode *newTree = new TreeNode(rVal);
        int rIdx = findRootIdx(inorder,is,ie,rVal);
        newTree->left = buildTreeHelper(preorder,ps+1,ps+rIdx-is,inorder,is,rIdx-1);
        newTree->right = buildTreeHelper(preorder,ps+rIdx-is+1,pe,inorder,rIdx+1,ie);
        return newTree;
    }
    int findRootIdx(vector<int> &inorder, int start, int end, int find) {
        for (int i=start; i<=end; i++) {
            if (inorder[i]==find) return i;
        }
        return -1;
    }

};
