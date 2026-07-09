class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int minLength = strs[0].size();
        for(int i = 1; i < strs.size(); i++) {
            minLength = min(minLength, (int)strs[i].size());
        }
        for(int i = 0; i < minLength; i++){
            char ch = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(strs[j][i] != ch) return prefix;
            }
            prefix += ch;
        }
        return prefix;
    }
};