// 1. left side aur right side , dono se accha sum mila -> l+r+root->val
// 2. only left side ya right side me se kisi ek se hi accha sum mila -> max(l,r)+root->val
// 3. na left se , na right se, accha sum mila -> root->val
// 4. maxSum = max(maxSum,1,2,3)
// 5. return max(2,3) -> kyunki sirf 2 & 3 m hi further exploration possible h
class Solution {
public:
    int maxSum;
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        int neeche_hi_answer_milgaya = l+r+root->val;   //1
        int koi_ek_accha = max(l,r)+root->val;  //2
        int only_root_accha = root->val;    //3
        maxSum = max({maxSum,neeche_hi_answer_milgaya, koi_ek_accha, only_root_accha}); //4
        return max(koi_ek_accha, only_root_accha);  //5
    }
    int maxPathSum(TreeNode* root) {
       maxSum = INT_MIN;
       solve(root);
       return maxSum;
    }
};