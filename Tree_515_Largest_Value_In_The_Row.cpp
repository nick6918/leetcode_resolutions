#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/* 
    
    Bfs 可解， DFS也可解。

    类似： 104

*/

struct TreeNode {
     int val;
     TreeNode *parent;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> largestValues_BFS(TreeNode* root) {
        if(!root) return vector<int>();
        queue<TreeNode*> stk;
        stk.push(root);
        int count_on_this_level = 1;
        int count_on_next_level = 0;
        vector<int> max_value_array = vector<int>(); 
        int current_max=root->val;
        while(!stk.empty()){
            TreeNode* current = stk.front();
            stk.pop();
            if(count_on_this_level==0){
                count_on_this_level = count_on_next_level;
                count_on_next_level = 0;
                max_value_array.push_back(current_max);
                current_max = current->val;
            }
            else current_max = current->val > current_max ? current->val : current_max;
            if(current->left) {
                stk.push(current->left);
                count_on_next_level++;
            }
            if(current->right) {
                stk.push(current->right);
                count_on_next_level++;
            }
            count_on_this_level--;
        }
        max_value_array.push_back(current_max);
        return max_value_array;
    }

    vector<int> largestValues(TreeNode* node){
        vector<int> max_value_array = vector<int>();
        largestValues_helper(node, max_value_array, 0);
        return max_value_array;
    }

    void largestValues_helper(TreeNode* node, vector<int>& max_array, int level){
        if(!node) return;
        if(max_array.size()>level) max_array[level] = max_array[level] >= node->val ? max_array[level] : node->val;
        else max_array.push_back(node->val);
        largestValues_helper(node->left, max_array, level+1);
        largestValues_helper(node->right, max_array, level+1); 
    }
};

void printVector(vector<int> vec){
    cout<<"[ ";
    for(auto iter = vec.begin(); iter!=vec.end(); iter++){
        cout<<*iter<<", ";
    }
    cout<<" ]"<<endl;
}

int main(){

    TreeNode* EmptyTree = NULL;
    TreeNode* OneNodeTree = new TreeNode(1);
    TreeNode* LeftTree = new TreeNode(1);
    LeftTree->left = new TreeNode(2);
    LeftTree->left->left = new TreeNode(3);
    TreeNode* BigTree = new TreeNode(1);
    BigTree->left = new TreeNode(2);
    BigTree->left->left = new TreeNode(3);
    BigTree->left->right = new TreeNode(4);
    BigTree->right = new TreeNode(5);
    BigTree->right->right = new TreeNode(6);
    //              1   
    //      2               5
    //  3       4               6
    Solution Sol = Solution();
    cout<<"Emptytree:  ";
    printVector(Sol.largestValues(EmptyTree));
    cout<<"OneNodeTree: " ;
    printVector(Sol.largestValues(OneNodeTree));
    cout<<"LeftTree: " ;
    printVector(Sol.largestValues(LeftTree));
    cout<<"BigTree: " ;
    printVector(Sol.largestValues(BigTree));
    //cout<<Sol.traverse(BigTree);
}