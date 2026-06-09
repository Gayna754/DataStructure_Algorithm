#include <vector>
#include <stack>
#include<queue>
#include <cstdlib>
#include <map>
#include <set>     // multiset is in <set>
#include <queue>
#include <vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
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
    int height(TreeNode*root){
        if(root==nullptr)return 0;
        int left= height(root->left);
        int right=height(root->right);
        return 1+max(left,right);
     }









    bool isBalanced(TreeNode* root) {
        if(root==nullptr)return true;
        int left=height(root->left);
        int right=height(root->right);
        if(abs(left-right)>1) return false;
        return isBalanced(root->left)&&isBalanced(root->right);      
    }
    int dia=0;
      int height(TreeNode*root){
        if(root==nullptr)return 0;
        int left=height(root->left);
        int right=height(root->right);
        dia=max(dia,left+right);// to find max dia of all height and update
        return 1+max(left,right);//to find max height of all 
      }



    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return dia;
        
    }
    int pathsum(TreeNode*root,int&maxi){
            if(root==NULL)return 0;
            int left=max(0,pathsum(root->left,maxi));
            int right=max(0,pathsum(root->right,maxi));
            maxi=max(root->val+left+right,maxi);
            return max(left,right)+root->val;
        }
        int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        pathsum(root,maxi);
        return maxi;

       
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(q==nullptr&&p==nullptr)return true;
        if(q==nullptr|| p==nullptr)return false;
        return(p->val==q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==nullptr)return result;

      queue<TreeNode*>q;
      q.push(root);
      bool flag=true;
      while(!q.empty()){
        int size=q.size();
        vector<int>row(size);
        for(int i=0;i<size;i++){
        TreeNode*root=q.front();
        q.pop();
        int index = flag?i:size-1-i;
        row[index]=root->val;
        if(root->left!=NULL)q.push(root->left);
        if(root->right!=NULL)q.push(root->right);
        }
        
        flag=!flag;
        result.push_back(row);
       
      
        
        
        
      }return result;


        
    }
bool isLeaf(TreeNode* node){
        return (node->left == NULL && node->right == NULL);
    }
  void left(TreeNode*root,vector<int>&res){
     TreeNode*curr=root->left;
     while(curr){
         if(!isLeaf(curr))res.push_back(curr->val);
         if(curr->left)curr=curr->left;
         else curr=curr->right;
     }
  }
   void right(TreeNode*root,vector<int>&res){
       TreeNode*curr=root->right;
        vector<int>temp;
       while(curr){
           if(!isLeaf(curr))temp.push_back(curr->val);
           if(curr->right)curr=curr->right;
           else curr=curr->left;}
           for(int i=temp.size()-1;i>=0;i--){
               res.push_back(temp[i]);
           }
       
   }
   void leaves(TreeNode*root,vector<int>&res){
       if(isLeaf(root)){
           res.push_back(root->val);
           return;
           
           
       }
       if(root->left)leaves(root->left,res);
       if(root->right)leaves(root->right,res);
   }
        vector<int> boundaryTraversal(TreeNode *root) {
        vector<int>res;
        if(root==nullptr)return res;
        if(!isLeaf(root))res.push_back(root->val);
        left(root,res);
        leaves(root,res);
        right(root,res);
        return res;
        
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
         auto p=q.front();
         q.pop();
         TreeNode*node=p.first;
         int x=p.second.first;
         int y=p.second.second;
         nodes[x][y].insert(node->val);
         if(node->left){
            q.push({node->left,{x-1,y+1}});}
         if(node->right){
                q.push({node->right,{x+1,y+1}});
            }
        }
           
            for(auto p:nodes){
                vector<int>col;
                for(auto q:p.second){
                   for(auto s:q.second){
                    col.push_back(s);
                   
                }                
            }
         ans.push_back(col);
        }
        return ans;
        

        
    }
    vector<int> topView(TreeNode *root) {
        
        vector<int> ans;

        if(root == NULL)
            return ans;

        // hd -> node value
        map<int, int> mp;

        // {node, horizontal distance}
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while(!q.empty()) {

            TreeNode* node = q.front().first;
            int hd = q.front().second;
            q.pop();

            // Store only first node seen at this hd
            if(mp.find(hd) == mp.end()) {
                mp[hd] = node->val;
            }

            if(node->left) {
                q.push({node->left, hd - 1});
            }

            if(node->right) {
                q.push({node->right, hd + 1});
            }
        }

        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
     vector<int> topView(TreeNode *root) {
        vector<int>ans;
        if(root==nullptr)return ans;
        map<int,int>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
        TreeNode*node=q.front().first;
        int dist=q.front().second;
        q.pop();
        if(mp.find(dist)==mp.end()){
            mp[dist]=node->val;
        }
        if(node->left){
            q.push({node->left,dist-1});
        }
        if(node->right){
            q.push({node->right,dist+1});
        }
        
        
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
    vector<int> bottomView(TreeNode *root) {
        vector<int>ans;
        if(root==nullptr)return ans;
        map<int,int>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
        auto it=q.front();
        q.pop();
        TreeNode*root=it.first;
        int wdth=it.second;
        mp[wdth]=root->val;
        if(root->left){
            q.push({root->left,wdth-1});}
        if(root->right){
            q.push({root->right,wdth+1});}
        
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        
        return ans;
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr)return ans;
        map<int,int>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode*root=it.first;
            int wdth=it.second;
            mp[wdth]=root->val;
            if(root->left){
                q.push({root->left,wdth+1});
            }
            if(root->right){
                q.push({root->right,wdth+1});
            }
        
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
    bool ismirrot(TreeNode*right,TreeNode*left){
    if(right==NULL&& left==NULL)return true;
    if(right==NULL || left== NULL)return false;

    if(right->val!=left->val)return false;
    return ismirrot(left->left,right->right)&&ismirrot(left->right,right->left);
}
 bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
        return ismirrot(root->left,root->right);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        queue<pair<TreeNode*,string>>q;
        q.push({root,to_string(root->val)});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode*node=it.first;
            string path=it.second;
            if(node->left==NULL&& node->right==NULL){
            result.push_back(path);}
            if(node->left){
                q.push({node->left,path+"->"+to_string(node->left->val)});
            }
            if(node->right){
                q.push({node->right,path+"->"+to_string(node->right->val)});
            }
            }
        
        return result;

        
    }
vector<string>result;
void dfs(TreeNode*node,string path){
           
            if(node==nullptr)return;
            if(node->left==NULL&&node->right==NULL){
                result.push_back(path);

            }
        
         if(node->left){
            dfs(node->left,path+"->"+to_string(node->left->val));
         }
         if(node->right){
            dfs(node->right,path+"->"+to_string(node->right->val));
         }
}
        
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==nullptr)return{};
        dfs(root,to_string(root->val));
        return result;

     
       
    }TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr||root==q||root==p)return root;
        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        TreeNode*right=lowestCommonAncestor(root->right,p,q);
        if(left==NULL)return right;
        else if(right==NULL)return left;
         return root;

    }
    int widthOfBinaryTree(TreeNode* root) {

        if(root == nullptr) return 0;

        long long ans = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root,0});

        while(!q.empty()) {

            int size = q.size();

            long long mini = q.front().second;
            long long first, last;

            for(int i=0;i<size;i++) {

                long long curr = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();

                if(i==0) first = curr;
                if(i==size-1) last = curr;

                if(node->left)
                    q.push({node->left, curr*2+1});

                if(node->right)
                    q.push({node->right, curr*2+2});
            }

            ans = max(ans, last-first+1);
        }

        return (int)ans;
    }
     bool checkTree(TreeNode* root) {
        if(root->left->val+root->right->val==root->val){
            return true;
        }
        else{
            return false;
        }
        
    }
    bool isSumProperty(TreeNode *root) {
        if(root==nullptr)return true;
        if(root->left==NULL&&root->right==NULL)return true;
        int left=0,right=0;
        if(root->left)left=root->left->val;
        if(root->right)right=root->right->val;
        return (root->val==left+right)&&isSumProperty(root->left)&&isSumProperty(root->right);
        
    }
      vector<string> binaryTreePaths(TreeNode* root) {
        if(root==nullptr)return{};
        dfs(root,to_string(root->val));
        return result;

     
       
    }TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr||root==q||root==p)return root;
        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        TreeNode*right=lowestCommonAncestor(root->right,p,q);
        if(left==NULL)return right;
        else if(right==NULL)return left;
         return root;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr||root==q||root==p)return root;
        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        TreeNode*right=lowestCommonAncestor(root->right,p,q);
        if(left==NULL)return right;
        else if(right==NULL)return left;
         return root;}
         TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr||root==q||root==p)return root;
        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        TreeNode*right=lowestCommonAncestor(root->right,p,q);
        if(left==NULL)return right;
        else if(right==NULL)return left;
         return root;

    }
      unordered_map<int, vector<int>> adj;

    void buildGraph(TreeNode* root, TreeNode* parent) {
        if (!root) return;

        if (parent) {
            adj[root->val].push_back(parent->val);
            adj[parent->val].push_back(root->val);
        }

        buildGraph(root->left, root);
        buildGraph(root->right, root);
    }

    int amountOfTime(TreeNode* root, int start) {
        buildGraph(root, nullptr);

        queue<pair<int,int>> q;
        unordered_set<int> vis;

        q.push({start, 0});
        vis.insert(start);

        int ans = 0;

        while (!q.empty()) {
            auto [rrot, time] = q.front();
            q.pop();

            ans = max(ans, time);

            for (auto nxt : adj[rrot]) {
                if (!vis.count(nxt)) {
                    vis.insert(nxt);
                    q.push({nxt, time + 1});
                }
            }
        }

        return ans;
    }
    unordered_map<int, vector<int>> adj;

    void buildGraph(TreeNode* root, TreeNode* parent) {
        if (!root) return;

        if (parent) {
            adj[root->val].push_back(parent->val);
            adj[parent->val].push_back(root->val);
        }

        buildGraph(root->left, root);
        buildGraph(root->right, root);
    }

    int amountOfTime(TreeNode* root, int start) {
        buildGraph(root, nullptr);

        queue<pair<int,int>> q;
        unordered_set<int> vis;

        q.push({start, 0});
        vis.insert(start);

        int ans = 0;

        while (!q.empty()) {
            auto [rrot, time] = q.front();
            q.pop();

            ans = max(ans, time);

            for (auto nxt : adj[rrot]) {
                if (!vis.count(nxt)) {
                    vis.insert(nxt);
                    q.push({nxt, time + 1});
                }
            }
        }

        return ans;
    }
     int countNodes(TreeNode* root) {
        if(root==nullptr)return 0;
        int left=countNodes(root->left);
        int right=countNodes(root->right);
        return 1+ left+right;

        
    }
    TreeNode*PrevNode=NULL;
    
    void flatten(TreeNode* root) {
        if(root==NULL)return;
       flatten(root->right);
       flatten(root->left);
        root->right=PrevNode;
        root->left=nullptr;
        PrevNode=root;
        
    }
    TreeNode*PrevNode=NULL;
    
    void flatten(TreeNode* root) {
        if(root==NULL)return;
       flatten(root->right);
       flatten(root->left);
        root->right=PrevNode;
        root->left=nullptr;
        PrevNode=root;
        
    }
     int findCeil(TreeNode* root, int x) {
        int ceil=-1;
        while(root!=nullptr){
            if(root->val==x){
                ceil=root->val;
                return ceil;
            }
            if(x>root->val){
                root=root->right;
            }
            else{ceil=root->val;
            root=root->left;
        }
       } return ceil;
        
        
    }

    int findFloor(TreeNode* root, int x) {
         int floor=-1;
        while(root!=nullptr){
            if(root->val==x){
                floor=root->val;
                return floor;
            }
            if(x<root->val){
                
                root=root->left;
            }
            else{floor=root->val;
                root=root->right;}
        
    }
        return floor;
}    
TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr)return new TreeNode(val);
         TreeNode*curr=root;  // copy root as in last root is to be returned
         while(true){
            if(curr->val<=val){
                if(curr->right!=NULL)curr=curr->right;// if not null go right
                  else{ curr->right=new TreeNode(val);
                  break;}//when null insert val to right   
                            
              }else{ 
                if(curr->left!=NULL)curr=curr->left;
                 else{curr->left=new TreeNode(val);
                 break;}
                    
            }
            }
         return root;

        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==NULL)return NULL;  
         if(root->val==key)
         return helper(root);
         TreeNode*dummy=root;
         while(root!=NULL){
            if(root->val>key){
                if(root->left!=NULL&&root->left->val==key){
                    root->left= helper(root->left);
                    break;
                }else{root=root->left;}
            
            
         }else{
            if(root->right!=nullptr&&root->right->val==key){
                root->right =helper(root->right);
                break;
            }else{root=root->right;}
         }
           
           }
           return dummy;}
           TreeNode*helper(TreeNode*root){
            if(root->left==NULL){return root->right;}
             if(root->right==NULL){return root->left;}

             TreeNode*leftchild=root->left;
             TreeNode*lastleft=findlastleft(root->right);
             lastleft->left=leftchild;
             return root->right;}

             TreeNode*findlastleft(TreeNode*root){
                if(root->left==nullptr)return root;
                return findlastleft(root->left);
             
           



        
    }
      int count=0;
      int visit(TreeNode*root,int k){
        if(root==nullptr)return -1;
          int left=visit(root->left,k);
            if(left!=-1)return left;
            count ++;
            if(count==k)return root->val;
           int right=  visit(root->right, k);
           if(right != -1)
    return right;
return -1;

      }
        

      



    int kthSmallest(TreeNode* root, int k){
       return visit(root,k);
        
    }
     bool visit(TreeNode*root,long minval,long maxval){
  if (root==nullptr)return true;
   if(root->val>=maxval|| root->val<=minval)return false;
    return visit(root->left,minval,root->val)&& visit(root->right,root->val,maxval);
    }




    bool isValidBST(TreeNode* root) {
        return visit (root,LONG_MIN,LONG_MAX);
        
    }
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val>p->val&& root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }if(root->val<p->val&&root->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
        
    }
};