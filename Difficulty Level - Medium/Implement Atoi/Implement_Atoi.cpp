#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
      int myAtoi(char *s) {
        int n=0;
        bool sign=true;
        while(s[n]!='\0'){n++;}
        string st="";
        int i=0;
        while(s[i]==' '||s[i]=='0'){
            i++;
        }
        if(s[i]=='-'){
            i++;
            sign=false;
        }
        while(i<n){
            if(int(s[i])-int('0')>=0&&int(s[i])-int('0')<=9){
                st+=s[i];
            }
            else{
                break;
            }
            if(stol(st)>INT_MAX && sign==true){
                return INT_MAX;
            }
            if(stol(st)>INT_MAX-1 && sign==false){
                return INT_MIN;
            }
            i++;
        }
        if(st.length()==0){return 0;}
        if(sign==true){
            return stoi(st);
        }
        string f="-"+st;
        return stoi(f);
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends