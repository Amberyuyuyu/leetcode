/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** removeComments(char** source, int sourceSize, int* returnSize) {
    char** ret = (char**)calloc(sourceSize, sizeof(char*));
    char new_line[sourceSize * 100 + 1];
    int pos = 0;
    int new_line_pos = 0;
    bool in_block = false;
    for (int j = 0; j < sourceSize; j++) {//��������
        char* line = source[j];//ȡ��ǰ�ַ���
        int line_size = strlen(line);
        for (int i = 0; i < line_size; i++) {//ö��ÿһ���ַ�
            if (in_block) {
                //�ж�ע�ͽ���λ��
                if (i + 1 < line_size && line[i] == '*' && line[i + 1] == '/') {
                    in_block = false;
                    i++;
                }
            }
            else {
                //�ж�ע�Ϳ�ʼλ��
                if (i + 1 < line_size && line[i] == '/' && line[i + 1] == '*') {
                    in_block = true;
                    i++;
                }
                else if (i + 1 < line_size && line[i] == '/' && line[i + 1] == '/') {
                    //��ע�ͣ�ֱ��������ǰ�ַ���
                    break;
                }
                else {
                    //��Ч���룬��¼
                    new_line[new_line_pos++] = line[i];
                }
            }
        }
        //�洢��Ч�ַ���
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

