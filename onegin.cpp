#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <cassert>
#include <ctype.h>
#include "../strings/str_funcs.h"

enum EXTRA_SPACE
{
    SPACE_FOR_NULL = 1
};

void readText(char* file_name, struct String** text, char** buf, size_t* number_chars, size_t* number_strings);
size_t countCh(char* s, char c);
void quickSort(void* buf, size_t low, size_t high, size_t elemSz,
               long int (*compFun)(void* a, void* b),
               void     (*swapEl) (void* x, void* y));
size_t partit(void* s, size_t low, size_t high, size_t elemSz,
              long int (*compFun)(void* a, void* b),
              void     (*swapEl) (void* x, void* y));
long int compStrings(void* a, void* b);
long int compStringsFromEnd(void* a, void* b);
void swapStrings           (void* a, void* b);
void printOriginalText(char* buf, size_t number_chars, char* file_name);

struct String
{
    size_t len = 0;
    char* ptr = NULL;
};

void printOriginalText(char* buf, size_t number_chars, char* file_name)
{
    FILE* fp = fopen(file_name, "w");

    if (fp == NULL)
    {
        printf("File open error \"%s\" \n", file_name);
        abort();
    }
    printf("nub_strs = %lu \n", number_chars);

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

void quickSort(void* buf, size_t low, size_t high, size_t elemSz,
               long int (*compFun)(void* a, void* b), void (*swapEl)(void* x, void* y))
{
    assert(buf     != NULL);
    assert(compFun != NULL);
    assert(elemSz  != 0);

    if ((int) low < (int) high)// && low + 1 != 0 && high + 1 != 0)
    {
        //printf("HIGH = %lu \n", high);
        size_t pivot = partit(buf, low, high, elemSz, compFun, swapEl);
        printf("#low = %lu \n", low);
        printf("#pivot = %lu \n", pivot);
        printf("#high = %lu \n", high);
        quickSort(buf, low, pivot - 1, elemSz, compFun, swapEl);
        quickSort(buf, pivot + 1, high, elemSz, compFun, swapEl);
    }
}

size_t partit(void* s, size_t low, size_t high, size_t elemSz,
              long int (*compFun)(void* a, void* b),
              void (*swapEl)(void* x, void* y))
{
    assert(s != NULL);
    assert(s != NULL);

    void * pivot = (void*) ((char*) s + (high * elemSz));
    //printf("HigH = %lu \n", high);
    size_t i = low - 1;
    printf("!!!!!\n");
    //printf("i = %lu \n", i);
    for (size_t j = low; j < high; j++)
    {
        //printf("&*&*&* ptr->i = %p ptr->j = %p pivot = %p i_piv = %lu j_piv = %lu piv_piv = %lu %p \n", s + (i * elemSz), s + (j * elemSz), pivot, i, j, high, s + ((i + 1) * elemSz));
        //printf("\(*=*)/ %p \n", ((String*) pivot)->ptr);
        //printf("/(-_-)\ %d \n", compFun(s + (j * elemSz), pivot));
        printf("##############\n");
        printf("i = %lu \n", i);
        printf("j = %lu \n", j);
        printf("pivot = %lu \n", high);
        if (compFun((void*) ((char*) s + (j * elemSz)), pivot) <= 0)
        {
            printf("@^@^@^@^@^\n");
            i++;
            //printf("!0!0! i = %lu", i);
            //printf("$*$*$*$*$ ptr->i = %p\n", s + (i * elemSz));
            swapEl((void*) ((char*) s + (i * elemSz)), (void*)((char*) s + (j * elemSz)));
        }
    }

    swapEl((void*) ((char*) s + ((i + 1) * elemSz)), (void*) ((char*) s + (high * elemSz)));
    //printf("!*!*!* %lu \n", i + 1);
    return (i + 1);
}

long int compStrings(void* a, void* b)
{
    String* str1 = (String*) a;
    String* str2 = (String*) b;

    char* s1 = str1->ptr;
    char* s2 = str2->ptr;

    while (!isalpha(*s1))
    {
        s1++;
    }

    while (!isalpha(*s2))
    {
        s2++;
    }

    return strcmp(s1, s2);
}

long int compStringsFromEnd(void* a, void* b)
{
    String* str1 = (String*) a;
    String* str2 = (String*) b;

    size_t ind_str1 = str1->len - 1;
    size_t ind_str2 = str2->len - 1;
    char* s1 = str1->ptr;
    char* s2 = str2->ptr;

    while (!isalpha(s1[ind_str1]) && ind_str1 > 0)
    {
        ind_str1--;
    }

    while (!isalpha(s2[ind_str2]) && ind_str2 > 0)
    {
        ind_str2--;
    }

    for (; ind_str1 > 0 && ind_str2 > 0; ind_str1--, ind_str2--)
    {
        printf("&&**&& istr1 = %lu istr2 = %lu \n", ind_str1, ind_str2);
        if (s1[ind_str1] != s2[ind_str2])
        {
            break;
        }
    }

    return s1[ind_str1] - s2[ind_str2];
}

void swapStrings(void* a, void* b)
{
    //printf("SW#SW#SW#SW\n");
    String* s1 = (String*) a;
    String* s2 = (String*) b;
    String tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
    //printf("RTRTRTTRR\n");
}

size_t countCh(char* s, char c)
{
    size_t n = 0;
    //printf("---- %p\n", s);
    while (*s)
    {
        //printf("*s = %c\n", *s);
        if (*s == c)
        {
            //printf("^^^^^\n");
            n++;
        }

        s++;
    }

    return n;
}

void readText(char* file_name, struct String** text, char** buf, size_t* number_chars, size_t* number_strings)
{
    struct stat stbuf;
    stat(file_name, &stbuf);
    printf("%ld\n", stbuf.st_size);

    size_t file_size = (size_t) stbuf.st_size;
    *buf = (char*) calloc(file_size + SPACE_FOR_NULL, sizeof(char));
    printf("!#!#!#!# BUF = %p\n", *buf);
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
    //printf("%s\n", *buf);
    //printf("pe = %p\n\n", &buf[number_chars]);

    *number_strings = countCh(*buf, '\n');
    *text = (String*) calloc(*number_strings + SPACE_FOR_NULL, sizeof(String)); //НЕ ИЗМЕНЯЕТСЯ текст НАДО ПОСМОТрЕТЬ*
    printf("!#!#!#!# TEXT = %p\n", text);
    String* run_text = *text;
    char* run_buf = *buf;

    size_t len = 0;
    run_text->ptr = *buf;
    while (*run_buf)
    {
        //printf("run_buf = %p\n", run_buf);
        //printf("run_text = %p---\n", run_text);
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
        //printf("*** %d \n", *run_buf);
    }
    printf("!@!@!@ %lu \n", run_buf - *buf);
    printf("chs = %lu \n", *number_chars);
    run_text->ptr = NULL;
    //printf("==== %p\n", run_text->ptr);
    fclose(fp);
}

int main()
{
    char file_name[] = "hamlet.txt";
    String* text = NULL;
    char* buf = NULL;
    String ss;
    size_t number_strings = 0;
    size_t number_chars = 0;
    readText(file_name, &text, &buf, &number_chars, &number_strings);
    printf("!#!#!#!# bufff = %p\n", buf);
    printf("!#!#!#!# textt = %p\n", text);

    size_t a = 0;
    /*a--;
    printf("%lu \n", a);
    a++;
    printf("%lu \n", a);
    */
    printf("TEXT = %p \nnum_str = %lu\n", text, number_strings);
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

    quickSort(text, 0, number_strings - 1, sizeof(String), compStringsFromEnd, swapStrings);

    for (String* index = text; index->ptr != NULL; index++)
    {
        //printf("+++ %p\n", index);
        printf("%s\n", index->ptr);
    }

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
