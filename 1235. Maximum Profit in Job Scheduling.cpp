/******************************************************************************

    Leetcode: 1235. Maximum Profit in Job Scheduling

*******************************************************************************/
class Solution {
public:
    vector<vector<int>> job;
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& profit) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            job.push_back({s[i], e[i], profit[i]});
        }

        sort(s.begin(), s.end());
        sort(job.begin(), job.end());

        vector<int> dp(n + 1, -1);
        return solver(s, e, profit, 0, dp);
    }

    int solver(vector<int>& s, vector<int>& e, vector<int>& profit, int i, vector<int>& dp) {
        int n = s.size();
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        int index = lower_bound(s.begin(), s.end(), job[i][1]) - s.begin();
        int taken = job[i][2] + solver(s, e, profit, index, dp);
        int not_taken = solver(s, e, profit, i + 1, dp);

        return dp[i] = max(taken, not_taken);
    }
};

