class Solution {
public:
    string longestPalindrome(string &s) {
        if (s.empty()) return s;

        string longest = std::string(1, s[0]);
        int length = s.length();
        int longestLength = 1;

        for (int left=0; left<length; left++) {
            for (int right=length-1; right>=left && right - left + 1 > longestLength; right--) {
                if (isPalindromic(s, left, right)) { // O(N)
                    longestLength = right - left + 1;
                    longest = s.substr(left, longestLength);
                    break;
                }
            }
        }
        return longest;
    }

    bool isPalindromic(string &s, int left, int right) { // O(N)
        for (int i=left; i<=(right+left)/2; i++) {
            if (s[i] != s[right-i+left]) {
                return false;
            }
        }
        return true;
    }
};