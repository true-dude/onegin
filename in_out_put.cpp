#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <sys/stat.h>
#include "in_out_put.h"

struct String
{
    size_t len = 0;
    char* ptr = NULL;
};


void readText(char* file_name, struct String** text, char** buf, size_t* number_chars, size_t* number_strings)
{
    struct stat stbuf;
    stat(file_name, &stbuf);

    size_t file_size = (size_t) stbuf.st_size;
    *buf = (char*) calloc(file_size + SPACE_FOR_NULL, sizeof(char));
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("File open error\n");
        abort();
    }

    *number_chars = fread(*buf, sizeof(char), file_size, fp);
    if (*number_chars != file_size)
    {
        printf("File was considered incorrect\n"
               "%lu characters instead of %lu.\n",
                *number_chars,             file_size);
        abort();
    }
    if (feof(fp))
    {
        printf("Premature end of file.\n");
        abort();
    }
    if (ferror(fp))
    {
        printf("File read error.\n");\
        abort();
    }

    (*buf)[*number_chars] = '\0';

    *number_strings = countCh(*buf, '\n');
    *text = (String*) calloc(*number_strings + SPACE_FOR_NULL, sizeof(String));
    String* run_text = *text;
    char* run_buf = *buf;

    size_t len = 0;
    run_text->ptr = *buf;
    while (*run_buf)
    {
        len++;

        if ((run_buf != *buf) && (*(run_buf - 1) == '\0'))
        {
            run_text->ptr = run_buf;
        }

        if (*run_buf == '\n')
        {
                run_text->len = len;
                len = 0;
                *run_buf = '\0';
                run_text++;
        }

        run_buf++;
    }

    run_text->ptr = NULL;

    fclose(fp);
}

size_t countCh(char* s, char c)
{
    size_t n = 0;

    while (*s)
    {

        if (*s == c)
        {
            n++;
        }

        s++;
    }

    return n;
}

void printOriginalText(char* buf, size_t number_chars, char* file_name)
{
    FILE* fp = fopen(file_name, "w");

    if (fp == NULL)
    {
        printf("File open error \"%s\" \n", file_name);
        abort();
    }

    char* run_buf = buf;
    size_t idx = 0;
    while (idx < number_chars)
    {
        if (*run_buf == '\0')
        {
            *run_buf = '\n';
        }

        idx++;
        run_buf++;
    }

    *run_buf = '\0';

    size_t n = fwrite(buf, sizeof(char), number_chars - 1, fp);

    fclose(fp);
}

void printStringsArray(struct String* text)
{
    for (String* index = text; index->ptr != NULL; index++)
    {
        printf("%s\n", index->ptr);
    }
}
