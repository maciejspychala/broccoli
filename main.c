#include <stdio.h>
#include <string.h>

void handle_includes(FILE *file) {
    char type[32] = "";
    if (fscanf(file, "%s", type) != EOF) {
        if(strcmp(type, "header") == 0) {
            printf("this is header");
        } else if (strcmp(type, "footer") == 0) {
            printf("this is footer");
        } else if (strcmp(type, "body") == 0) {
            printf("this is content");
        }
    }
}

int main() {
    FILE *input = NULL;
    char flag;

    if (!(input= fopen("root.html", "r"))) {
        perror ("input failed");
        return 1;
    }

    while (fscanf(input, "%c", &flag) != EOF) {
        switch (flag) {
            case '$' :
                handle_includes(input);
                break;
            default :
                printf("%c", flag);
                break;
        }
    }

    return 0;
}
