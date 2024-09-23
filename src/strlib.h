#include <stdbool.h>

#ifndef STRLIB_H
#define STRLIB_H

void str_at(const char* str, int index, char* output);
void str_charAt(const char* str, int index, char* output);
void str_concat(const char* str1, const char* str2, char* output);
void str_endsWith(const char* word, const char* end_width, bool* output);
void str_includes(const char* word, const char* substring, bool* output);
void str_indexOf(const char* word, const char* substring, const char** output);

#endif 