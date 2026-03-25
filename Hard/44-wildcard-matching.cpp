class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0; //pointer for string s
        int j = 0; //pointer for pattern p
        
        int star = -1;   //last position of '*' in pattern
        int match = 0;   //position in s where '*' started matching
        
        while (i < s.size()) {
            
            //characters match OR pattern has '?'
            //'?' can match any single character
            if (j < p.size() && (p[j] == s[i] || p[j] == '?')) {
                i++; //move both pointers
                j++;
            }
            
            //pattern has '*'
            //store position of '*' and assume it matches empty for now
            else if (j < p.size() && p[j] == '*') {
                star = j;     //remember where '*' is
                match = i;    //remember current position in s
                j++;          //move pattern pointer forward
            }
            
            //mismatch BUT we saw a '*' before
            //try to expand '*' to cover one more character
            else if (star != -1) {
                j = star + 1; //go back to position after '*'
                match++;      //let '*' match one more character
                i = match;    //move string pointer accordingly
            }
            
            //mismatch and no '*' to adjust
            else {
                return false;
            }
        }
        
        //if pattern still has char left,
        //they must all be '*' to match empty sequence
        while (j < p.size() && p[j] == '*') {
            j++;
        }
        
        //if we reached end of pattern, it's a match
        return j == p.size();
    }
};