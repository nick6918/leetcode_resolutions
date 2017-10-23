/*
	
	此题极度类似判断树是否平衡， 自顶向下的算法包含了两个重复的计算；
	希望通过子底向上的算法合并之。

	类似题目： 110

*/

#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //bool isValidBST_BruteSolve(TreeNode* root) {
      //  isValidBST(root->left) && isValidBST(root-right) && root->val > MaxNode(root->left) && root->val < MaxNode(root->right);
    //}

    bool isValidBST_helper(TreeNode* root, TreeNode* maxNode, TreeNode* minNode){
    	if(!root) return true;
    	if((maxNode && root->val > maxNode->val) || (minNode && root->val <= minNode->val))
    		return false;
    	return isValidBST_helper(root->left, root, minNode) && isValidBST_helper(root->right, maxNode, root);
    }

    bool isValidBST(TreeNode* root){
    	return isValidBST_helper(root, NULL, NULL);
    }

};


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
	//				1	
	//		2				5
	//	3		4				6
	Solution Sol = Solution();
	cout<<"Emptytree:  "<<Sol.isValidBST(EmptyTree)<<endl;
	cout<<"OneNodeTree: " <<Sol.isValidBST(OneNodeTree)<<endl;
	cout<<"LeftTree: " <<Sol.isValidBST(LeftTree)<<endl;
	cout<<"BigTree: " <<Sol.isValidBST(BigTree)<<endl;
	//cout<<Sol.traverse(BigTree);
}