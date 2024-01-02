class Solution {
private:
    unordered_map<string, char> map = {
        {"&quot;", '\"'},
        {"&apos;", '\''},
        {"&amp;", '&'},
        {"&gt;", '>'},
        {"&lt;", '<'},
        {"&frasl;", '/'}
    };
public:
    string entityParser(string text) {
        string output;
        int n = text.size();
        for (int i = 0; i < n;) {
            if (text[i] == '&') {
                int start = i;
                while (i < n - 1 && text[i] != ';') {
                    if (text[i] == '&') {
                        output += text.substr(start, i - start);
                        start = i;
                    }
                    ++i;
                }
                string substr = text.substr(start, ++i - start);
                if (map.find(substr) != map.end()) {
                    output += map[substr];
                }
                else {
                    output += substr;
                }
            }
            else {
                output += text[i];
                ++i;
            }
        }
        return output;
    }
};