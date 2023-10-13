#include <stdio.h>

int x(char* str){
    int a = 0;

    for (int i = 0; str[i] != '\0'; ++i){
        a = a * 10 + str[i] - '0';
    }
    return a;
}

int main(){
    char ff[100];
    printf("ENTER A NUMBER: ");
    gets(ff);
    int k = x(ff);
    printf("%d",k);
    return 0;
}


