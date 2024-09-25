#ifndef STRLIB_H
#define STRLIB_H

#include <stdbool.h>

int str_length(const char* str);

// String prototyper
void str_at(const char* str, int index, char* output);
void str_charAt(const char* str, int index, char* output);
void str_concat(const char* str1, const char* str2, char* output);
void str_endsWith(const char* word, const char* end_with, bool* output);
void str_includes(const char* word, const char* substring, bool* output);
void str_indexOf(const char* word, const char* substring, int* output);
void str_lastIndexOf(const char* word, const char* substring, int* output);
void str_padEnd(const char* str, int targetLength, const char* padString, char* output);
void str_padStart(const char* str, int targetLength, const char* padString, char* output);
void str_repeat(const char* str, int count, char* output);
void str_slice(const char* str, int start, int end, char* output);
void str_startsWith(const char* str, const char* searchString, int position, bool* output);
void str_substring(const char* str, int start, int end, char* output);
void str_toLowerCase(const char* str, char* output);
void str_toUpperCase(const char* str, char* output);
void str_trim(const char* str, char* output);
void str_trimEnd(const char* str, char* output);
void str_trimStart(const char* str, char* output);

#endif