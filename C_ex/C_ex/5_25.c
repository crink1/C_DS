//void get(const char* word, int* diff) {
//    int len = strlen(word);
//    for (int i = 0; i + 1 < len; i++) {
//        diff[i] = word[i + 1] - word[i];
//    }
//}
//
//char* oddString(char** words, int wordsSize) {
//    int len = strlen(words[0]);
//    int diff0[len - 1];
//    int diff1[len - 1];
//    int diff[len - 1];
//    get(words[0], &diff0);
//    get(words[1], &diff1);
//    if (memcmp(&diff0, &diff1, sizeof(int) * (len - 1)) == 0) {
//        for (int i = 2; i < wordsSize; i++) {
//            get(words[i], &diff);
//            if (memcmp(&diff0, &diff, sizeof(int) * (len - 1)) != 0) {
//                return words[i];
//            }
//        }
//    }
//    get(words[2], &diff);
//    return memcmp(&diff0, &diff, sizeof(int) * (len - 1)) == 0 ? words[1] : words[0];
//}