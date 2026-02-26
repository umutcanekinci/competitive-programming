class Solution {
public:
    int numSteps(string s) {
        int index = 0;
        while (isOne(s)) {
            if (isEven(s)) {
                divideByTwo(s);
            } else {
                addOne(s);
            }
            index++;
        }
        return index;
    }

    bool isOne(string &s) {
        return s.substr(0, s.size()-1).contains('1');
    }

    bool isEven(string &s) {
        return s[s.size()-1] == '0';
    }

    void addOne(string &s) {
        int size = s.size();
        for(int i=size-1; i>=0; i--) {
            char ch = s[i];
            if (ch == '0') {
                s[i] = '1';
                return;
            }
            s[i] = '0';
            
        }
        s = '1' + s;
    }

    void divideByTwo(string &s) {
        int l = s.size();
        int starting = l-2;
        for(int i=starting; i>=0; i--) {
            s[i+1] = s[i];
        }
        s[0] = '0';
    }
};