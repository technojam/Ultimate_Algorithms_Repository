/* a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        if (strs.size() == 0) return res;
        if (strs[0].size() == 0) return res;
        if (strs.size() == 1) return strs[0];
        int j=0;
        bool flag=false;
        while (true) {
            for (int i=1;i<strs.size();i++) {
                if (j >= strs[0].size() || j >= strs[i].size() || strs[0][j] != strs[i][j]) {
                    flag=true;
                    break;
                }         
            }
            if (flag) break;
            j++;
        }

        for (int i=0;i<j;i++) res +=strs[0][i];
        return res; 
    }
};
