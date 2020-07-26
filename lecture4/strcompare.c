#include <stdio.h>
# include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    string str = get_string("str: "); // this part: t will copy teh same thing as str
    string t = str;
    t[0] = toupper (t[0]); // capitalize the first letter of t
    printf("str: %s \n", str); // now str and t will have the same cap letter
    printf("t: %s \n", t);

    char *s = get_string("s: "); // this part: tt will copy the same thing as s, but it also capitalize the first letter
    char *tt = malloc(strlen(s) + 1); // pass the bytes in memory, malloc has a return value
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        tt[i] = s[i];
    }
    tt[0] = toupper(tt[0]);
    printf("s: %s \n", s);
    printf("tt: %s \n", tt);

    // easier way to copy string s to string t
    char *string = get_string("s: ");
    char *text = malloc(strlen(string) + 1);
    strcpy(text, string); // copy to text in the content of string
    t[0] = toupper(t[0]);
    printf("%s \n", s);
    printf("%s \n", t);
}