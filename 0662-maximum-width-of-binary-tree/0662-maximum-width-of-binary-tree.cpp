/*
    # Level order traversal (BFS) use karenge.
    # har node k saath uska index store karenge.
    # root ka index 0 maanenge.
    # agar kisi node ka index 'i' h:
        -> left child = '2i+1'
        -> right child = '2i+2'
    
    # har level k liye:
        -> first node ka index = 'first'
        -> last node ka index = 'last'
        -> Width = 'last-first+1'
    # har level ki width calculate karke maximum update karenge.
    # Traversal complete karne k baad maximum width return karenge.

*/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        if(root==NULL) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            long long size = q.size();
            long long first, last;
            // # to avoid overflow (V.V. IMP.)
            long long nmin = q.front().second;
            for(int i=0 ; i<size ; i++){
                long long curridx = q.front().second - nmin;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first=curridx;
                if(i==size-1) last=curridx;
                if(node->left){
                    q.push({node->left,curridx*2+1});
                }
                if(node->right){
                    q.push({node->right,curridx*2+2});
                }
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};