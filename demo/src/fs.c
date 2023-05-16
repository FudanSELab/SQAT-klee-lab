#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[20];
    char ch;
    int option;

    printf("请选择操作：\n1. 读取文件\n2. 写入文件\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("请输入要读取的文件名：");
            scanf("%s", filename);
            file = fopen(filename, "r");
            if (file == NULL) {
                printf("无法打开文件 %s\n", filename);
                return 0;
            }

            while ((ch = fgetc(file)) != EOF)
                putchar(ch);
            fclose(file);
            break;

        case 2:
            printf("请输入要写入的文件名：");
            scanf("%s", filename);
            file = fopen(filename, "w");

            char str[50];
            printf("请输入要写入的内容：");
            scanf("%s", str);
            fputs(str, file);
            fclose(file);
            break;

        default:
            printf("输入有误，程序结束。\n");
            return 0;
    }

    return 0;
}
