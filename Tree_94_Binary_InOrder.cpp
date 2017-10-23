class Solution {
public:

    vector<int> inorderTraversal_with_Stack(TreeNode* root) {
        vector<int> res = vector<int>();
        if (!root) return res;
        stack<TreeNode*> stk;
        TreeNode* current = root;
        while(current || !stk.empty()){
        // right node
            if(current){
                while(current -> left){
                    stk.push(current);
                    current = current -> left;
                }
            }
        //backtrack
            else {
                current = stk.top();
                stk.pop();
            }
            res.push_back(current->val);
            current = current -> right;
        } 
        return res;
    }
};