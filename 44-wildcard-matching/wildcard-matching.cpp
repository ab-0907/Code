class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        // bool t[n+1][m+1];
        bool c[m+1];bool prev[m+1];
        prev[0] = true;
          for(int j=1;j<m+1;j++){
            c[j]=false;
            bool flag=true;
             for(int i=1;i<j+1;i++){
                if(p[i-1]!='*'){ flag =false; break;}
             }
             prev[j]=flag;
        }
         prev[0] = true;
         c[0]=false;
        for (int i = 1; i < n + 1; i++) {
                
            for (int j = 1; j < m + 1; j++) {

                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    c[j] = prev[j - 1];
                } else if (p[j - 1] == '*') {
                    c[j] = prev[j] || c[j - 1];
                } else {
                    c[j] = false;
                }
            }
            memcpy(prev , c,(m+1)*sizeof(bool));
        }
        return prev[m];
    }
};