
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int sz = s.length();
        int i = 0;
        for(int j=0;j<sz;j++)
        {
            if(s[j]!=' ')
            {
                if(i) s[i++]=' ';
                int right = j;
                while(right<sz&&s[right]!=' ') s[i++]=s[right++];
                reverse(s.begin()+i-(right-j),s.begin()+i);
                j=right;
            }
        }
        s.erase(s.begin()+i,s.end());
        return s;
    }
};