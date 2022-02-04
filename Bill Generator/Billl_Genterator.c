#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *replaceWord(const char *str, const char *oldWord, const char *newWord)
{
    char *resultString;
    int i, count = 0;
    int newWordLength = strlen(newWord);
    int oldWordLength = strlen(oldWord);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (strstr(&str[i], oldWord) == &str[i])
        {
            count++;

           
            i = i + oldWordLength - 1;
        }
    }

    resultString = (char *)malloc(i + count * (newWordLength - oldWordLength) + 1);

    i = 0;
    while (*str)
    {
        
        if (strstr(str, oldWord) == str)
        {
            strcpy(&resultString[i], newWord);
            i += newWordLength;
            str += oldWordLength;
        }
        else
        {
            resultString[i] = *str;
            i += 1;
            str += 1;
        }
    }
    resultString[i] = '\0';
    return resultString;
}

int main()
{
    FILE *ptr;
    FILE *ptr2;
    ptr = fopen("C:\\Users\\thaku\\C-Projects-in-VScode\\Projects\\Bill Generator\\bill.txt", "r");
    ptr2 = fopen("C:\\Users\\thaku\\C-Projects-in-VScode\\Projects\\Bill Generator\\generatedbill.txt", "w");
    char str[200];
    fgets(str, 200, ptr);
    printf("The given bill template was: %s\n", str);

   
    char *newStr;
    newStr = replaceWord(str, "{{item}}", "Table Fan");
    newStr = replaceWord(newStr, "{{outlet}}", "Ram Laxmi fan outlet");
    newStr = replaceWord(newStr, "{{name}}", "Sid");
    printf("The actual bill generated is: %s\n", newStr);
    printf("The generated bill has been written to the file genBill.txt\n");

    fprintf(ptr2, "%s", newStr);
    fclose(ptr);
    fclose(ptr2);
    return 0;
}
