class Solution {
public:
    bool checkOnesSegment(string s) {
        return iterative(s, s.size());
        // return recursive(s, 0, s.size(), false, false);
    }

    bool recursive(string &s, int index, int length, bool isOne, bool isFinished) {
        char ch = s[index];

        if (isOne && ch == '0') {
            if (isFinished) {
                return false;
            }
            isFinished = true;
        }
        if (ch == '1' && isFinished) {
            return false;
        }
        if (index < length-1) {
            return recursive(s, index+1, length, (ch == '1'), isFinished);
        }
        return true;
    
    
    }

    bool iterative(string &s, int l) {
        bool found = false;
        bool before = false;
        bool current;
        for(int i=0; i<l; i++) {
            char ch = s[i];
            current = ch == '1';
            if (current) {
                if (found) {
                    return false;
                }
                
            } else {
                if (before) {
                    found = true;
                }
            }
            before = current;
        }
        return true;
    }
};