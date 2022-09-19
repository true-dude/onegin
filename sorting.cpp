#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include "sorting.h"
#include "../strings/str_funcs.h"

struct String
{
    size_t len = 0;
    char* ptr = NULL;
};

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
    void* ptr_i = (void*) ((char*) s + (i * elemSz));
    void* ptr_j = (void*) ((char*) s + (low * elemSz));
    for (size_t j = low; j < high; j++)
    {
        //printf("&*&*&* ptr->i = %p ptr->j = %p pivot = %p i_piv = %lu j_piv = %lu piv_piv = %lu %p \n", s + (i * elemSz), s + (j * elemSz), pivot, i, j, high, s + ((i + 1) * elemSz));
        //printf("\(*=*)/ %p \n", ((String*) pivot)->ptr);
        //printf("/(-_-)\ %d \n", compFun(s + (j * elemSz), pivot));
        printf("##############\n");
        printf("i = %lu \n", i);
        printf("j = %lu \n", j);
        printf("pivot = %lu \n", high);
        if (compFun(ptr_j, pivot) <= 0)
        {
            printf("@^@^@^@^@^\n");
            ptr_i += elemSz;
            //printf("!0!0! i = %lu", i);
            //printf("$*$*$*$*$ ptr->i = %p\n", s + (i * elemSz));
            swapEl(ptr_i, ptr_j);
        }

        ptr_j += elemSz;
    }

    ptr_i += elemSz;

    swapEl(ptr_i, pivot);
    //printf("!*!*!* %lu \n", i + 1);
    return ((char*) ptr_i - (char*) s) / elemSz;
}

void bubleSort(void* buf, size_t number_elems, size_t elemSz,
               long int (*compFun)(void* a, void* b), void (*swapEl)(void* x, void* y))
{
    void* ptr_i = buf;
    for (size_t i = 0; i < number_elems; i++)
    {
        void* ptr_j = buf + i * elemSz;
        for (size_t j = i; j < number_elems; j++)
        {
            if (compFun(ptr_i, ptr_j) > 0)
            {
                swapEl(ptr_i, ptr_j);
            }

            ptr_j += elemSz;
        }

        ptr_i += elemSz;
    }
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

    assert(s1 != NULL);
    assert(s2 != NULL);

    //printf("&^$&^$\n");

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
        //printf("&&**&& istr1 = %lu istr2 = %lu \n", ind_str1, ind_str2);
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
