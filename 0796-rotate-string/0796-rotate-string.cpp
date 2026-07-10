class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }
        string temp = s + s;
        return temp.find(goal) != string::npos;
    }
};

// Apporach
// A string s can be rotated to get goal if
// Both strings have the same length.
// goal is a substring of s + s.
// Time complexity O(n).