/*!
-----------------------------

-----------------------------
*/
long int strlen(const char* s);
void strcpy(const char* s_from, char* s_to);
char* strchr(char* s, int c);
long int strcmp(const char s1[], const char s2[]);
char* strcat(const char s1[], char s2[]);
long int getline(FILE* fp, char* s, char sep);
void qSort(char** s, int low, int high);
int partition(char** s, int low, int high);
void swap(char** s1, char** s2);
void printArrayOfStrings(char** s, int n);

