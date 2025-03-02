class Solution {
    int dp[1001][1001];
// recursion+memoization
    int solve(string& s,string& t,int i,int j){
        if(j>= t.size()) return 1;
        if(i>= s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int notake= solve(s,t,i+1,j);
        int take= 0;
        if(s[i]==t[j]) take= solve(s,t,i+1,j+1);

        return dp[i][j]= take+notake;
    }
// tabulation dp
    int solvetab(string& s,string& t){
        int n=s.size(),m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][m]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                dp[i][j]= dp[i+1][j];
                if(s[i]==t[j]) dp[i][j]+= dp[i+1][j+1];
            }
        } int sm=0;
        for(int i=0;i<=n;i++) sm+= dp[i][0];
        return sm;
    }
public:
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(s,t,0,0);
    }
};