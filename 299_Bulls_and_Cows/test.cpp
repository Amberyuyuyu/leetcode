class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int A = 0;
        int B = 0;
        int CA[10];
        int CB[10];
        memset(CA, 0, sizeof(CA));
        memset(CB, 0, sizeof(CB));
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                A++;
            }
            CA[secret[i] - '0']++;
            CB[guess[i] - '0']++;
        }
        for (int i = 0; i < 10; i++) {
            B += min(CA[i], CB[i]);
        }
        B -= A;
        string ans = "";
        ans = to_string(A) + "A" + to_string(B) + "B";
        return ans;
    }
};