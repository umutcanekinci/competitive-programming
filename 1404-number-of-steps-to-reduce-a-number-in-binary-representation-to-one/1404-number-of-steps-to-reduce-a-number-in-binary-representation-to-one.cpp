class Solution {
public:
    int numSteps(string s) {
        int index = 0;
        int size = s.size();
        while (isOne(s, size)) {
            if (isEven(s, size)) {
                divideByTwo(s, size);
            } else {
                size += addOne(s, size);
            }
            index++;
        }
        return index;
    }

    bool isOne(string &s, int size) {
        for (int i=0; i<size-1; i++) {
            if (s[i] == '1') {
                return true;
            }
        }
        return false;
    }

    bool isEven(string &s, int size) {
        return s[size-1] == '0';
    }

    bool addOne(string &s, int size) {
        for(int i=size-1; i>=0; i--) {
            char ch = s[i];
            if (ch == '0') {
                s[i] = '1';
                return 0;
            }
            s[i] = '0';
        }
        s = '1' + s;
        return 1;
    }

    void divideByTwo(string &s, int size) {
        for(int i=size-2; i>=0; i--) {
            s[i+1] = s[i];
        }
        s[0] = '0';
    }
};