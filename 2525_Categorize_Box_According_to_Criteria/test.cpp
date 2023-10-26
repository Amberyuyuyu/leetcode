class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long v = (long)length * width * height;
        int Bulky = (length >= 10000 || width >= 10000 || height >= 10000 || v >= 1000000000) ? 1 : 0;
        int Heavy = mass >= 100 ? 1 : 0;
        if (Bulky && Heavy) {
            return "Both";
        }
        if (!Bulky && !Heavy) {
            return "Neither";
        }
        if (Bulky && !Heavy) {
            return "Bulky";
        }
        return "Heavy";
    }
};