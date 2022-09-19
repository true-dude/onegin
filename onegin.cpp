#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "in_out_put.h"


struct String
{
    size_t len = 0;
    char* ptr = NULL;
};



int main()
{
    char file_name[] = "hamlet.txt";
    String* text = NULL;
    char* buf = NULL;
    size_t number_strings = 0;
    size_t number_chars = 0;
    readText(file_name, &text, &buf, &number_chars, &number_strings);
    //printf("!#!#!#!# bufff = %p\n", buf);
    //printf("!#!#!#!# textt = %p\n", text);

    //printf("TEXT = %p \nnum_str = %lu\n", text, number_strings);
    /*for (String* index = text; index->ptr != NULL; index++)
    {
        //printf("+++ %p\n", index);
        //printf("%s\n", index->ptr);
        index++;
        printf("iindex = %p \n", index->ptr);
    }*/

    quickSort(text, 0, number_strings - 1, sizeof(String), compStrings, swapStrings);

    for (String* index = text; index->ptr != NULL; index++)
    {
        //printf("+++ %p\n", index);
        printf("%s\n", index->ptr);
    }

    bubleSort(text, number_strings, sizeof(String), compStringsFromEnd, swapStrings);

    printStringsArray(text);

    /*for (String* index = text; index->ptr != NULL; index++)
    {
        //printf("+++ %p\n", index);
        printf("%s\n", index->ptr);
    }*/

    char output_file_name[] = "output.txt";
    printOriginalText(buf, number_chars, output_file_name);


    free(text);
    free(buf);


/*
    if (fp == NULL)
    {
        printf("File open error\n");
        abort();
    }

    struct stat stbuf;
    stat(file_name, &stbuf);
    printf("%ld\n", stbuf.st_size);

    size_t file_size = (size_t) stbuf.st_size;
    char* buf = (char*) malloc(file_size * sizeof(char));
    size_t number_of_read_chars = fread(buf, sizeof(char), file_size, fp);

    size_t number_of_strings = 0;
    for (size_t i = 0; i < file_size; i++)
    {
        if (buf[i] == '\n')
        {
            number_of_strings++;
            buf[i] = '\0';
        }
    }

    char* text = (char*) calloc(number_of_strings, sizeof(char*));
    char* run_ptr_buf = text;
    char* run_buf = buf;
    *ptr_buf = buf;
    for (size_t idx_buf = 1; idx_buf < file_size; idx_buf++)
    {
        if (buf[idx_buf - 1] == '\0')
        {
            text[idx_ptr] = &
        }
    }

    buf[file_size - 1] = '\0';

    printf("%s\n", buf);
    free(buf);
*/


}
