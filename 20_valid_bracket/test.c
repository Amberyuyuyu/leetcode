
typedef struct Stack {
    char* a;
    int top;
    int capacity;
}ST;

void StackInit(ST* ps) {
    assert(ps);
    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

void StackPush(ST* ps, char c) {
    assert(ps);
    if (ps->top == ps->capacity) {
        int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        char* tmp = realloc(ps->a, newCapacity * sizeof(char));
        if (tmp == NULL) {
            printf("realloc fail\n");
            exit(-1);
        }
        else {
            ps->a = tmp;
            ps->capacity = newCapacity;
        }
    }
    ps->a[ps->top] = c;
    ps->top++;
}
bool StackEmpty(ST* ps) {
    assert(ps);
    return ps->top == 0;
}
char StackTop(ST* ps) {
    assert(ps);
    assert(!StackEmpty(ps));
    return ps->a[ps->top - 1];
}


void StackPop(ST* ps) {
    assert(ps);
    assert(!StackEmpty(ps));
    ps->top--;
}

void StackDestroy(ST* ps) {
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

bool isValid(char* s) {
    ST st;
    StackInit(&st);
    while (*s) {
        if (*s == '('
            || *s == '['
            || *s == '{') {
            StackPush(&st, *s);
            ++s;
        }
        else {
            if (StackEmpty(&st)) {
                StackDestroy(&st);
                return false;
            }
            char top = StackTop(&st);
            StackPop(&st);
            if ((*s == '}' && top != '{')
                || (*s == ']' && top != '[')
                || (*s == ')' && top != '(')) {
                StackDestroy(&st);
                return false;
            }
            else {
                ++s;
            }
        }
    }
    bool ret = StackEmpty(&st);

    StackDestroy(&st);
    return ret;
}