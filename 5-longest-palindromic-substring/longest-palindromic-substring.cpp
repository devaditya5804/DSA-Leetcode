class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int resLen = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            // check for odd length palindrome
            int l = i, r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if((r-l+1)>resLen){
                    resLen = r-l+1;
                    res = s.substr(l,r-l+1);
                }
                l-=1;
                r+=1;
            }

            // check for even length palindrome
            int l2 = i, r2=i+1;
            while(l2>=0 && r2<n && s[l2]==s[r2]){
                if((r2-l2+1)>resLen){
                    resLen = r2-l2+1;
                    res = s.substr(l2,r2-l2+1);
                }
                l2-=1;
                r2+=1;
            }
        }
        return res;
    }
};