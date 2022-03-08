#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100];
    char str1[100];
    
    scanf("%s", str);
    scanf("%s", str1);

    int result = strcmp(str,str1);

    if(result == 0)
        printf("identical");
    else
        printf("not");

    return 0;
}
