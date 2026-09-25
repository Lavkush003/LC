class Solution {
public:
    set<string> parse(string s, int &i) {
        set<string> result;
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {
                i++; // skip '{'

                set<string> inside = parse(s, i);

                i++; // skip '}'

                set<string> temp;

                // Concatenate current with inside
                for (string a : current) {
                    for (string b : inside) {
                        temp.insert(a + b);
                    }
                }

                current = temp;
            }
            else if (s[i] == ',') {
                i++; // skip ','

                // Add current part to result
                result.insert(current.begin(), current.end());

                current = {""};
            }
            else {
                // Normal character
                char c = s[i];

                set<string> temp;

                for (string x : current) {
                    temp.insert(x + c);
                }

                current = temp;
                i++;
            }
        }

        // Add last part
        result.insert(current.begin(), current.end());

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};