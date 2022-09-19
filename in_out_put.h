enum EXTRA_SPACE
{
    SPACE_FOR_NULL = 1
};

void readText(char* file_name, struct String** text, char** buf, size_t* number_chars, size_t* number_strings);
size_t countCh(char* s, char c);

void printOriginalText(char* buf, size_t number_chars, char* file_name);
void printStringsArray(struct String* text);
