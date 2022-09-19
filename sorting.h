void quickSort(void* buf, size_t low, size_t high, size_t elemSz,
               long int (*compFun)(void* a, void* b),
               void     (*swapEl) (void* x, void* y));
size_t partit(void* s, size_t low, size_t high, size_t elemSz,
              long int (*compFun)(void* a, void* b),
              void     (*swapEl) (void* x, void* y));
void bubleSort(void* buf, size_t number_elems, size_t elemSz,
               long int (*compFun)(void* a, void* b), void (*swapEl)(void* x, void* y));
long int compStrings(void* a, void* b);
long int compStringsFromEnd(void* a, void* b);
void swapStrings           (void* a, void* b);
