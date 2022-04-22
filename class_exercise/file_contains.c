#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int get_line_count(char *pfName);
int get_word_count(char *pfName);
int get_char_count(char *pfName);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid command line arguments. Enter file name\n");
        exit(0);
    }

    int wordCount;
    int charCount;
    int lineCount;

    lineCount = get_line_count(argv[1]);
    printf("Line count in file %s: %d\n", argv[1], lineCount);

    wordCount = get_word_count(argv[1]);
    printf("Word count in file %s: %d\n", argv[1], wordCount);

    charCount = get_char_count(argv[1]);
    printf("Char count in file %s: %d\n", argv[1], charCount);

    return (0);
}

int get_line_count(char *pfName)
{
    char ch;
    int lineCount = 0;
    FILE *pFile;
    pFile = fopen(pfName, "r");
    assert(pFile != NULL);

    while ((ch = (char)fgetc(pFile)) != EOF)
    {
        if ((ch == '\n') || (ch == '\0'))
        {
            lineCount++;
        }
    }
    fclose(pFile);

    return lineCount;
}

int get_word_count(char *pfName)
{
    char ch;
    int wordCount = 0;
    FILE *pFile;
    pFile = fopen(pfName, "r");
    assert(pFile != NULL);

    while ((ch = fgetc(pFile)) != EOF)
    {
        if (ch == '\n' || ch == '\0' || ch == ' '  || ch == '\t')
        {
            wordCount ++;
        }
    }
    fclose(pFile);
    return wordCount;
}

int get_char_count(char *pfName)
{
    char ch;
    int charCount = 0;
    FILE *pFile;
    pFile = fopen(pfName, "r");
    assert(pFile != NULL);

    while ((ch = fgetc(pFile)) != EOF)
    {
        charCount++;
    }
    fclose(pFile);
    return charCount;
}