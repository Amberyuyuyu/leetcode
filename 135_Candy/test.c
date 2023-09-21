#define max(a,b) (((a) > (b)) ? (a) : (b))
int* initArray(int size) {
    int* candyArr = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        candyArr[i] = 1;
    }
    return candyArr;
}

int candy(int* ratings, int ratingsSize) {
    int* candyArr = initArray(ratingsSize);
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candyArr[i] = candyArr[i - 1] + 1;
        }
    }
    for (int i = ratingsSize - 1; i > 0; i--) {
        if (ratings[i] < ratings[i - 1]) {
            candyArr[i - 1] = max(candyArr[i] + 1, candyArr[i - 1]);
        }
    }
    int ret = 0;
    for (int i = 0; i < ratingsSize; i++) {
        ret += candyArr[i];
    }
    return ret;
}