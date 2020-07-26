#include <stdio.h>
# include <cs50.h>

int main(void)
{
   int n = 50;
   int *p = &n; // declare p
    printf("%p\n", &n); // & means 'get the address of the variable ' the location of n
    printf("%p\n", p);  // %p == pointer
    printf("%i\n", *p); //* means 'go to '

    char *s = "EMMA"; // == string s = "EMMA"
    printf("%s \n", s);
    printf("%p \n", s);
    printf("%p \n", &s[0]); // print first character of the string s
    printf("%c \n", *s);
    printf("%c \n", *(s+1));
}