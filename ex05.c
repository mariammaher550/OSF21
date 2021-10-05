#include <stdio.h>

int main()
{
    char foo[] = "Hello World";  // foo points to the head of string [first character]
    char *x = foo;              // x points to foo
    char **s = &x;              // s points to x
    printf("s is %s\n", *s);
    s[0] = foo;
    printf("s[0] is %c\n", **s); // the first character of the string.
    return 0;
}
