#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int vc_len=strs.size();
        int minlen=201;
        char a;
        bool pass=true;
        for(int i=0;i<vc_len;i++)
        {
            minlen=std::min(minlen,(int)strs[i].size());
        }
        for(int j=0;j<minlen;j++)
        {
            for(int i=0;i<vc_len;i++)
            {
                a=strs[0][j];
                pass=true;
                if(a!=strs[i][j])
                {
                    pass=false;
                    break;
                }
            }
            if(pass)
            {
                ans.push_back(a);
            }
            else
            {
                break;
            }
        }
        return ans;
}
};