#include <vector>
#include <stack>
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

};