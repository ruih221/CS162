#include <stdio.h>
int main(int argc, char *argv[]) {
    int num_lines = 0, num_char = 0, num_words = 0;
    char c, pre_char;
    FILE* IF = NULL;
    if (argv[1]) {
        if ((IF = fopen(argv[1], "r")) == NULL)
            printf("Error reading file");
        while ((c = fgetc(IF)) != EOF) {
            if (c == '\n') {
                num_lines++;
                num_words++;
            }
            if ((c == ' ') | (c == '\t')) {
                num_words++;
            }
            num_char++;
            pre_char = c;
        }
        fclose(IF);
    } else {
        while ((c = getc(stdin)) != EOF) {
            if (c == '\n') {
                num_lines++;
                num_words++;
            }
            if ((c == ' ') | (c == '\t')) {
                num_words++;
            }
            num_char++;
            pre_char = c;
        }
    }
    if (pre_char != '\n') num_words++;
    printf("%7d %7d %7d\n",num_lines, num_words, num_char);
    return 0;
}
