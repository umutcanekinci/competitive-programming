class Solution {
public:
    bool checkOnesSegment(string s) {
        return solution(s, 0, s.size(), false, false);
    }

    bool solution(string &s, int index, int length, bool isOne, bool isFinished) {
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
            return solution(s, index+1, length, (ch == '1'), isFinished);
        }
        return true;
    }
};