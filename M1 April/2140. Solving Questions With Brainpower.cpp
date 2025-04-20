

// For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
// If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
// If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
// Easy to get (pattern)
// pick or not pick appraoch ):

class Solution {
    private:
        long long helper(int index, int n, vector<vector<int>> & q, vector<long long>&dp){
    
            if(index >= n){
                return 0;
            }

            // memorization [recursive calls]
            if(dp[index] != -1){
                return dp[index];
            }
    
            long long solve_problem = q[index][0] + helper(index+q[index][1] +  1, n, q,dp);
            // next index value
            long long skip_problem = 0 + helper(index+1,n, q, dp);
    
            // maximum points you can earn for the exam.
            return dp[index] = max(solve_problem, skip_problem);
        }
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            int index = 0;
            int n = questions.size();
            vector<long long> dp(n+1,-1);
            return helper(index,n,questions,dp);
        }
};