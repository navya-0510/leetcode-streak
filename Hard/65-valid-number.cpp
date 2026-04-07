class Solution {
public:
    bool isNumber(string s) {
        bool numSeen = false;
        bool dotSeen = false;
        bool eSeen = false;
        bool numAfterE = true;  //imp

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                numSeen = true;
                numAfterE = true;
            }
            else if (s[i] == '+' || s[i] == '-') {
                //sign valid only at start OR just after e/E
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (s[i] == '.') {
                //dot not allowed after e or multiple times
                if (dotSeen || eSeen)
                    return false;
                dotSeen = true;
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                //e must appear once and only after a number
                if (eSeen || !numSeen)
                    return false;
                eSeen = true;
                numAfterE = false; //must have digits after e
            }
            else {
                return false;
            }
        }

        return numSeen && numAfterE;
    }
};