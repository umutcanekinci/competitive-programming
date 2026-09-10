#include <algorithm>

class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        if (strs.empty()) return "";

        int minLen = strs[0].length();
        for(const auto& str : strs) {
            minLen = std::min<int>(minLen, str.length());
        }

        string prefix = "";
        for (int i=0; i<minLen; i++) {
            for (const auto& str : strs) {
                if (strs[0][i] != str[i]) {
                    return prefix;
                }
            }

            prefix += strs[0][i];
        }
        return prefix;
    }

    
    string longestCommonPrefixModular(const vector<string>& strs) {
        if (strs.empty()) return "";

        int minLen = minLength(strs);
        string prefix = "";
        for (int i=0; i<minLen && checkLetter(strs, i); i++) {
            prefix += strs[0][i];
        }
        return prefix;
    }

    int minLength(const vector<string>& strs) {
        if (strs.empty()) return 0;

        int minLen = strs[0].length();
        for(const auto& str : strs) {
            minLen = std::min<int>(minLen, str.length());
        }
        return minLen;
    }

    bool checkLetter(const vector<string>& strs, int i=0) {
        for (const auto& str : strs) {
            if (strs[0][i] != str[i]) {
                return false;
            }
        }
        return true;
    }
};