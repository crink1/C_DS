//bool isValid(char* s) {
//    int len = strlen(s);
//    int top = 0;
//    char stack[len];
//    for (int i = 0; i < len; i++) {
//        char c = s[i];
//        stack[top++] = c;
//        if (top >= 3 && strncmp(stack + top - 3, "abc", 3) == 0) {
//            top -= 3;
//        }
//    }
//    return top == 0;
//}
