#include <vector>
#include <stack>
#include<queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> preorder;

        if(root == nullptr) return preorder;

        stack<TreeNode*> sta;

        sta.push(root);

        while(!sta.empty()) {

            root = sta.top();
            sta.pop();

            preorder.push_back(root->val);

            if(root->right != nullptr)
                sta.push(root->right);

            if(root->left != nullptr)
                sta.push(root->left);
        }

        return preorder;
    }
    vector<int> inorderTraversal(TreeNode* root) {
       stack<TreeNode*>st;
       TreeNode*node=root;
       vector<int>ans;
       while(node!=nullptr||!st.empty()){
        while(node!=nullptr){
        st.push(node);
        node=node->left;
        }
       
            node=st.top();
            st.pop();
            ans.push_back(node->val);
            node=node->right;
        }return ans;
       }
        bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL)return true;
        if(p==nullptr||q==NULL)return false;
        return (p->val==q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        
    }
    void Preorder(TreeNode*root,vector<int>&ans){
      if(root==nullptr)return;
      ans.push_back(root->val);
      Preorder(root->left,ans);
      Preorder(root->right,ans);
}










    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        Preorder(root,ans);
        return ans;
        
    }
    void Inorder(TreeNode*root,vector<int>&ans){
        if(root==nullptr)return;
        Inorder(root->left,ans);
        ans.push_back(root->val);
        Inorder(root->right,ans);
    }







    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        Inorder(root,ans);
        return ans;

        
    }
     void postorder(TreeNode*root,vector<int>&ans){
        if(root==nullptr)return;
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
        
       }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorder(root,ans);
        return ans;


        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
       
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
               
                TreeNode*node=q.front();
                q.pop();
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
                level.push_back(node->val);

                
            }
            ans.push_back(level);
        }
        return ans;
        
    }
     vector<int> inOrder(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode*node=root;
        vector<int>inorder;
        while(node!=nullptr||!st.empty()){
            if(node!=NULL){
            st.push(node);
            node=node->left;}
            else{
                if(st.empty())break;
                node=st.top();
                st.pop();
                inorder.push_back(node->val);
                node=node->right;
                
            }
        }return inorder;
        
        
    }
    int maxDepth(TreeNode* root) {
        if (root==nullptr) return 0 ;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
        
    }

};