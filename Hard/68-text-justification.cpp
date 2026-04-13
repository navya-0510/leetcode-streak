class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLength = words[i].length();
            int j = i + 1;

            while (j < n && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length();
                j++;
            }

            int numWords = j - i;
            int totalSpaces = maxWidth;

            //calculate tot char (without spaces)
            for (int k = i; k < j; k++) {
                totalSpaces -= words[k].length();
            }

            string line = "";
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                //fill remaining spaces at end
                line += string(maxWidth - line.length(), ' ');
            }
            else {
                int spacesBetween = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        int spaces = spacesBetween;

                        //left slots get extra spaces
                        if (extraSpaces > 0) {
                            spaces++;
                            extraSpaces--;
                        }

                        line += string(spaces, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j; //move to next line
        }

        return result;
    }
};