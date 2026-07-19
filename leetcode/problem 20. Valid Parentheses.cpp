#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack <char> str;
        int len=s.size();
        for(int i=0;i<len;i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                str.push(s[i]);
            }
            else
            {
                if(str.empty()==true)
                {
                    return false;
                }
                if((str.top()=='('&&s[i]==')')||(str.top()=='{'&&s[i]=='}')||(str.top()=='['&&s[i]==']'))
                {
                    str.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(str.empty()==true)
        {
            return true;
        }
        return false;
    }
};