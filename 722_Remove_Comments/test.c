/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** removeComments(char** source, int sourceSize, int* returnSize) {
    char** ret = (char**)calloc(sourceSize, sizeof(char*));
    char new_line[81];
    int pos = 0;
    int new_line_pos = 0;
    bool in_block = false;
    for (int j = 0; j < sourceSize; j++) {//遍历代码
        char* line = source[j];//取当前字符串
        int line_size = strlen(line);
        for (int i = 0; i < line_size; i++) {//枚举每一个字符
            if (in_block) {
                //判断注释结束位置
                if (i + 1 < line_size && line[i] == '*' && line[i + 1] == '/') {
                    in_block = false;
                    i++;
                }
            }
            else {
                //判断注释开始位置
                if (i + 1 < line_size && line[i] == '/' && line[i + 1] == '*') {
                    in_block = true;
                    i++;
                }
                else if (i + 1 < line_size && line[i] == '/' && line[i + 1] == '/') {
                    //行注释，直接跳过当前字符串
                    break;
                }
                else {
                    //有效代码，记录
                    new_line[new_line_pos++] = line[i];
                }
            }
        }
        //存储有效字符串
        if (!in_block && new_line_pos > 0) {
            new_line[new_line_pos] = '\0';
            ret[pos] = (char*)calloc(new_line_pos + 1, sizeof(char));
            strcpy(ret[pos], new_line);
            pos++;
            new_line_pos = 0;
        }
        *returnSize = pos;
    }
    return ret;
}

