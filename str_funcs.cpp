#include <stdio.h>
#include <assert.h>
#include "str_funcs.h"


long int strlen(const char* s)
{
    assert(s != NULL);

    const char* s1 = s;

    while (*s1)
    {
        s1++;
    }

    return s1 - s;
}


void strcpy(const char* s_from, char* s_to)
{
    assert(s_from != NULL);
    assert(s_to != NULL);
    assert(s_from != s_to);

    do
    {
        *s_to = *s_from;
        s_to++;
        s_from++;
    } while (*s_from != '\0');

    *s_to = '\0';
}


char* strchr(char* s, int c)
{
    assert(s != NULL);


    while (*s)
    {
        if (*s == c)
        {
            return s;
        }

        s++;
    }

    return NULL;
}


long int strcmp(const char* s1, const char* s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);
    //assert(s1 != s2);

    do
    {
        if (*s1 != *s2)
        {
            return *s1 - *s2;
        }
        s1++;
        s2++;

    } while (*s1 && *s2);

    return *s1 - *s2;
}


char* strcat(const char* s1, char* s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);
    assert(s1 != s2);

    while (*s2)
    {
        s2++;
    }

    while (*s1)
    {
        *s2 = *s1;
        s1++;
        s2++;
    }

    *s2 = '\0';

    return s2;
}


long int getline(FILE* fp, char* s, char sep)
{
    char* s1 = s;

    if (fp == NULL)
    {
        printf("File error: pointer on file equals NULL\n");
        return 0;
    }

    int c = getc(fp);
    while (c != '\n' && c != EOF && c != sep)
    {
        *s1 = (char) c;
        c = getc(fp);
        s1++;
    }

    *s1 = '\0';

    return s1 - s;
}


void qSort(char** s, int low, int high)
{
    assert(s != NULL);
    if (low < high)
    {
        int pivot = partition(s, low, high);
        printf("#low = %d \n", low);
        printf("#pivot = %d \n", pivot);
        printf("#high = %d \n", high);
        qSort(s, low, pivot - 1);
        qSort(s, pivot + 1, high);
    }
}


int partition(char** s, int low, int high)
{
    assert(s != NULL);

    char * pivot = s[high];

    int i = low - 1;
    printf("!!!!!\n");
    for (int j = low; j < high; j++)
    {
        printf("##############\n");
        printf("i = %d \n", i);
        printf("j = %d \n", j);
        printf("pivot = %lu \n", high);
        if (strcmp(s[j], pivot) <= 0)
        {
            printf("@^@^@^@^@^\n");
            i++;
            swap(&s[i], &s[j]);
        }
    }

    swap(&s[i + 1], &s[high]);

    return (i + 1);
}


void swap(char** s1, char** s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    char* tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

void printArrayOfStrings(char** s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", s[i]);
    }

    printf("\n");
}
