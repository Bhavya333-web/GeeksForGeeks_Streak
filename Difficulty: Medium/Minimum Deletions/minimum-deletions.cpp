class Solution {
  public:
  int dp[1001][1001];
  int solve(int i, int j,string &s){
      if(i>=j)
      return 0;
      if(dp[i][j]!=-1)
      return dp[i][j];
      int ans=INT_MAX;
      if(s[i]==s[j]){
          ans=min(ans,solve(i+1,j-1,s));
      }
      else{
          ans=min(ans,1+solve(i+1,j,s));
          ans=min(ans,1+solve(i,j-1,s));
      }
      return dp[i][j]=ans;
  }
    int minDeletions(string s) {
        memset(dp,-1,sizeof dp);
       return solve(0,s.size()-1,s);
        
    }
};

