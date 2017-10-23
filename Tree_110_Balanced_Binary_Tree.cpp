class Solution {
public:
    int Height(TreeNode* root) {
        if(!root) return 0;
        int left_height = Height(root->left);
        int right_height = Height(root->right);
        return left_height >= right_height ? left_height + 1 : right_height + 1;
    }
    bool isBalanced_Basic(TreeNode* root) {
        if(!root) return true;
        return abs(Height(root->left) - Height(root -> right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int Height_With_Comparison(TreeNode* root){
        if(!root) return 0;
        int left_height = Height_With_Comparison(root->left);
        if (left_height < 0) return -1;
        int right_height = Height_With_Comparison(root->right);
        if (right_height < 0) return -1;

        //在最底层的节点上， 首先开始进行isBalanced的判断。
        if(abs(left_height-right_height)>1) return -1;
        return max(left_height, right_height)+1;
    }

    bool isBalanced(TreeNode* root){
        return Height_With_Comparison(root) >0;
    }
};