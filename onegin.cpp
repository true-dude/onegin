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
    String* text = NULL;
    char* buf = NULL;

    char file_name[] = "hamlet.txt";
    size_t number_strings = 0;
    size_t number_chars = 0;
    readText(file_name, &text, &buf, &number_chars, &number_strings);

    quickSort(text, 0, number_strings - 1, sizeof(String), compStrings, swapStrings);
    printStringsArray(text);

    bubleSort(text, number_strings, sizeof(String), compStringsFromEnd, swapStrings);
    printStringsArray(text);

    char output_file_name[] = "output.txt";
    printOriginalText(buf, number_chars, output_file_name);

    free(text);
    free(buf);


}
