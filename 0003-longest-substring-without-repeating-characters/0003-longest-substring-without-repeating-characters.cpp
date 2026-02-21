class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        string current = "";
        for (int i=0; i<s.length(); i++) {
            for(int j=i; j<s.length(); j++) {
                char ch = s[j];
                if (current.find(ch) == string::npos) {
                    current += ch;
                }
                else {
                    break;
                }
            }
            if (current.size() > max) {
                max = current.size();
            }
            current = "";
        }
        return max;
    }
};