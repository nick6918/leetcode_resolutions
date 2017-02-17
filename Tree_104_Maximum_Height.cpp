/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
pre_order: stack
in_order: back_track, stack;
*/

#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *parent;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x, TreeNode* parent) : val(x), parent(parent), left(NULL), right(NULL) {}
};

#include <stack>
#include <queue>

class Solution {
public:
    int maxDepth_Recursion(TreeNode* root) {
    	//performance rate: 50.46%
    	if (!root) return 0;
    	else if (!root->left && !root->right) return 1;
    	else if (!root->left) return maxDepth(root->right)+1;
    	else if (!root->right) return maxDepth(root->left)+1;
    	else {
    		int left = maxDepth(root->left);
    		int right = maxDepth(root->right);
    		return left >= right ? left+1 : right+1;
    	}
    }
    TreeNode* travleAlongLeft(TreeNode* root, int& level){
    	TreeNode* current = root;
    	while(current->left) {
    		current = current->left;
    		level++;
    	}
    	return current;
    }


    TreeNode* climbBack(TreeNode* current, int& level){
    	//root should not have no children
    	while(current->parent && current->parent->right==current) {

    		current = current->parent;
    		level--;
    	}
    	level--;
    	return current->parent;
    }

    int maxDepth_WithParent(TreeNode* current) {
    	if (!current) return 0;
    	int backtrack = 0;
    	int max_level = 1;
    	int current_level = 1;
    	while(current){
    		if (backtrack == 0){
    			current = travleAlongLeft(current, current_level);
    		}
    		if (current->right) {
    			current = current->right;
    			current_level++;
    			backtrack = 0;
    		}
    		else {
    			backtrack = 1;
    			max_level = (max_level >= current_level ? max_level : current_level);
    			current = climbBack(current, current_level);
    		}
    	}
    	return max_level;
    }

    int maxDepth(TreeNode* root){
    	//50.46
    	if(!root) return 0;
    	queue<TreeNode*> que;
    	que.push(root);
    	int max_level = 1;
    	int count_on_this_level = 1;
    	int count_on_next_level = 0;
    	while(!que.empty()){
    		if(count_on_this_level==0){
    			max_level++;
    			count_on_this_level=count_on_next_level;
    			count_on_next_level=0;
    		}
    		TreeNode* current = que.front();
    		que.pop();
    		count_on_this_level--;
    		if(current->left) {
    			que.push(current->left);
    			count_on_next_level++;
    		}
    		if(current->right) {
    			que.push(current->right);
    			count_on_next_level++;
    		}
    	}
    	return max_level;
    }
};

int main(){
	TreeNode* EmptyTree = NULL;
	TreeNode* OneNodeTree = new TreeNode(1, NULL);
	TreeNode* LeftTree = new TreeNode(1, NULL);
	LeftTree->left = new TreeNode(2, LeftTree);
	LeftTree->left->left = new TreeNode(3, LeftTree->left);
	TreeNode* BigTree = new TreeNode(1, NULL);
	BigTree->left = new TreeNode(2, BigTree);
	BigTree->left->left = new TreeNode(3, BigTree->left);
	BigTree->left->right = new TreeNode(4, BigTree->left);
	BigTree->right = new TreeNode(5, BigTree);
	BigTree->right->right = new TreeNode(6, BigTree->right);
	//				1	
	//		2				5
	//	3		4				6
	Solution Sol = Solution();
	cout<<"Emptytree:  "<<Sol.maxDepth(EmptyTree)<<endl;
	cout<<"OneNodeTree: " <<Sol.maxDepth(OneNodeTree)<<endl;
	cout<<"LeftTree: " <<Sol.maxDepth(LeftTree)<<endl;
	cout<<"BigTree: " <<Sol.maxDepth(BigTree)<<endl;
	//cout<<Sol.traverse(BigTree);
}
