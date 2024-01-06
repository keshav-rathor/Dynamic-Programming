/******************************************************************************

    Leetcode: 132. Palindrome Partitioning II

*******************************************************************************/
class Solution {
public:
    // int ans=INT_MAX;
    bool palindrome(string &s, int left, int right){
        while(left<right) if(s[left++]!=s[right--]) return false;
        return true;
    }

    int minCut(string s) {
        // vector<string> temp;
        int n=s.size();
        vector<int> dp(n+1,-1);

        return solver(s,0,dp)-1;
        // return ans;
        
    }
    int solver(string s,int i,vector<int> & dp)
    {
        int n=s.size();
        // if(palindrome(s,i,j)) return 0;
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;
        for(int k=i;k<n;k++)
        {
            if(palindrome(s,i,k))
            {
                int temp=1+(solver(s,k+1,dp));
                ans=min(ans,temp);
            }

        }
        return dp[i]=ans;
        
    }
};