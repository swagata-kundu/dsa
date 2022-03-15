#include<stack>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        
        if(root==NULL){
            return result;
        }
        
        
        stack <TreeNode*> stack1,stack2;
        stack <TreeNode*> * st1,*st2;
        st1=&stack1;
        st2=&stack2;
        
        st1->push(root);
        bool isLeftToRight=true;
        
        vector<int> r;
        
        while(!st1->empty()){
            TreeNode* current=st1->top();
            cout<<current->val<<endl;
            r.push_back(current->val);
            st1->pop();
            
            
            if(isLeftToRight){
                if(current->left)
                    st2->push(current->left);
                if (current->right)
                    st2->push(current->right);
            }else{
                if(current->right)
                    st2->push(current->right);
                if(current->left)
                    st2->push(current->left);
            }
            
            if(st1->empty()){
                
                stack <TreeNode*> *tmp;
                result.push_back(r);
                r.clear();
                isLeftToRight=!isLeftToRight;
                
                tmp=st1;
                st1=st2;
                st2=tmp;
            }
        }
        return result;
        
    }
};