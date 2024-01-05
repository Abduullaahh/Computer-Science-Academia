#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 100

int vowel_check(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void is_invert(char *word)
{
    int len = strlen(word);
    int i=0;
    for ( i = 0; i < len / 2; i++)
    {
        char temp = word[i];
        word[i] = word[len - i - 1];
        word[len - i - 1] = temp;
    }
}

int main()
{
    FILE *ptr1 = fopen("input.txt", "r");
    FILE *ptr2 = fopen("task4.txt", "w");
    int i=0;
	
    char word[LENGTH];
    while (fscanf(ptr1, "%s", word) != EOF)
    {
        int vowel_count = 0;
        for (i = 0; i < strlen(word); i++)
	{
            if (vowel_check(word[i])) 
	    {
                vowel_count = 1;
                break;
            }
        }
        if (vowel_count) 
	{
            is_invert(word);
        }
        fprintf(ptr2, "%s ", word);
    }

    fclose(ptr1);
    fclose(ptr2);

    return 0;
}

