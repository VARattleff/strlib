#include <stdbool.h>

#ifndef STRLIB_H
#define STRLIB_H

void str_at(const char* str, int index, char* output);
void str_charAt(const char* str, int index, char* output);
void str_concat(const char* str1, const char* str2, char* output);
void str_endsWith(const char* word, const char* end_width, bool* output);

#endif 