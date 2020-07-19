//PostOrder Traversal

//Recursive approach
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
    void postorder(TreeNode* root,vector<int>& ans)
    {
            if(root->left)
                    postorder(root->left,ans);
            if(root->right)
                    postorder(root->right,ans);
            ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
            vector<int> ans;
            if(!root)
                    return ans;
            postorder(root,ans);
            return ans;
        
    }
};


//Iterative Approach
//Using two stacks
/*
1. Push 1 to first stack.
      First stack: 1
      Second stack: Empty

2. Pop 1 from first stack and push it to second stack. 
   Push left and right children of 1 to first stack
      First stack: 2, 3
      Second stack: 1

3. Pop 3 from first stack and push it to second stack. 
   Push left and right children of 3 to first stack
      First stack: 2, 6, 7
      Second stack: 1, 3

4. Pop 7 from first stack and push it to second stack.
      First stack: 2, 6
      Second stack: 1, 3, 7

5. Pop 6 from first stack and push it to second stack.
      First stack: 2
      Second stack: 1, 3, 7, 6

6. Pop 2 from first stack and push it to second stack. 
   Push left and right children of 2 to first stack
      First stack: 4, 5
      Second stack: 1, 3, 7, 6, 2

7. Pop 5 from first stack and push it to second stack.
      First stack: 4
      Second stack: 1, 3, 7, 6, 2, 5

8. Pop 4 from first stack and push it to second stack.
      First stack: Empty
      Second stack: 1, 3, 7, 6, 2, 5, 4

The algorithm stops here since there are no more items in the first stack. 
Observe that the contents of second stack are in postorder fashion. Print them.
*/ 

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
    vector<int> postorderTraversal(TreeNode* root) {
            vector<int> ans;
            if(!root)
                    return ans;
            stack<TreeNode *> s1;
            stack<TreeNode *> s2;
            TreeNode *curr = root;
            s1.push(curr);
            while(!s1.empty())
            {
                    curr = s1.top();
                    s1.pop();
                    s2.push(curr);
                    
                    if(curr->left)
                            s1.push(curr->left);
                    if(curr->right)
                            s1.push(curr->right);
            }
            
            while(!s2.empty())
            {
                    TreeNode *temp = s2.top();
                    s2.pop();
                    ans.push_back(temp->val);
            }
            
            return ans;
            
        
    }
};


//using 1 stack
class Solution {
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
            vector<int> ans;
            stack<TreeNode *> s1;
            while(true)
            {
            while(root!=NULL)
            {
                    s1.push(root);
                    s1.push(root);
                    root = root->left;
            }
            
            if(s1.empty())
                    return ans;
            
            if(!s1.empty() && s1.top()==root)
                    root = root->right;
            else
            {
                    int k = root->val;
                    ans.push_back(k);
                    root = NULL;
            }
           }
            return ans;
        
    }
};