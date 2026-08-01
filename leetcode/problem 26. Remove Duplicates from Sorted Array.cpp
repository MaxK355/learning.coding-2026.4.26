#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        int cnt=1;
        for(int i=1;i<=len-1;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[cnt]=nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};