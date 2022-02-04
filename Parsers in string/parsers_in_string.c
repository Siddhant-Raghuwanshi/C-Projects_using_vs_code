#include <stdio.h>
#include <string.h>
void parser(char *str)
{
    int in, index = 0;
    int i;
    for (i = 0; i <= strlen(str); i++)
    {
        if (str[i] == '<')
        {
            in = 1;
            continue;
        }
        else if (str[i] == '>')
        {
            in = 0;
            continue;
        }
        if (in == 0)
        {
            str[index] = str[i];
            index++;
        }
    }
    str[index] = '\0';
    while (str[0] == ' ')
    {
        for (i = 0; i <= strlen(str); i++)
        {
            str[i] = str[i + 1];
        }
    }
    while (str[strlen(str) - 1] == ' ')
    {
        str[strlen(str) - 1] = '\0';
    }
}
int main()
{
    char str[] = "<head>   This piece of grabage runs successfully   <head>";
    parser(str);
    printf("This is the parsed string : ~~%s~~", str);
    return 0;
}