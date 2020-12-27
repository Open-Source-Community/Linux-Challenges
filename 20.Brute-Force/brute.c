#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char f[] = "B:Fq)DL?EHC)DJUL*H?78B)Is";
void print_flag() {
    int len = strlen(f);
    for (int i = 0; i < len; i++) {
        f[i] = f[i] + 10;
    }
    printf("%s\n", f);
}
int main()
{
    char *password = malloc(100*sizeof(char));
   
    printf("Password: ");
    scanf("%s", password);
    char user=0, pass=0;

    
    if (!strcmp(password, "7786"))
        pass=1;

    if (pass)
        print_flag();
    else
        printf("%s", "Wrong!\n");    
}
