/*
    By analysing outputs, I recognize that the
    program makes calculations for same indexes
    multiple times. To fix this,

    Used an memory matrix to check previous queries
    in order to avoid repeating operations.

    In that matrix:
        -1: unchecked
        0 : false
        1 : true
        
    With that method we don't have to check repeating
    letter star patterns like a*a*a*

    Instead of passing strings by value, using pass
    by reference methode was an important boosting
    factor.

    Also some boolean values are simlified by using
    already existed ones.

    These lines added for speed boost:
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

*/

class Solution {
public:
    int SIZE = 30;
    int memory[30][30];
    
    bool isMatch(string s, string p) { 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        memset(memory, -1, sizeof(memory));
        return solve(s, p, 0, 0);
    }

    bool solve(string &s, string &p, int i, int j) {
        if (i >= SIZE || j >= SIZE)
            return false; 
        
        if(memory[i][j] != -1)
            return memory[i][j];

        int sl = s.size(), pl = p.size();
        bool sEmpty = sl == i, pEmpty = pl == j;

        if (pEmpty)
            return memory[i][j] = sEmpty;

        bool isDot  = j < pl && p[j] == '.';
        bool isStar = j+1 < pl && p[j+1] == '*';
        if (sEmpty && !isStar && isDot) {
            return memory[i][j] = false;
        }
        
        bool same = i < sl && s[i] == p[j];
        bool match = (same || isDot);
        bool result;
  
        if (isStar) {
            result = solve(s, p, i, j + 2) || (match && solve(s, p, i + 1, j));
        } else {
            result = match && solve(s, p, i + 1, j + 1);
        }
        return memory[i][j] = result;
    }
};