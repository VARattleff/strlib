#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//String.prototyp.at()
void str_at(const char* str, int index, char* output) {
    int len = strlen(str);
    index = (index < 0) ? len + index : index;
    *output = (index < 0 || index >= len) ? '\0' : str[index];
}

//String.prototype.charAt()
void str_charAt(const char* str, int index, char* output)
{
    int len = strlen(str);
    index = (index < 0) ? len + index : index;
    *output = (index < 0 || index >= len) ? '\0' : str[index];
}


//String.prototype.concat()
void str_concat(const char* str1, const char* str2, char* output) 
{
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    char* result = (char*)malloc(len_str1 + len_str2 + 1); 

    if (result == NULL) 
    {
        *output = '\0'; 
        return;
    }

    strcpy(result, str1);
    strcat(result, str2);

    strcpy(output, result); 
    free(result);
}

//String.prototype.endsWith()
void str_endsWith(const char* word, const char* end_width, bool* output) 
{
    int word_len = strlen(word);
    int end_width_len = strlen(end_width);

    if (end_width_len > word_len) 
    {
        *output = false;
        return;
    }

    const char* word_end = word + (word_len - end_width_len);
    *output = (strcmp(word_end, end_width) == 0);
}

//String.prototype.includes()
void str_includes(const char* word, const char* substring, bool* output) 
{
    *output = (strstr(word, substring) != NULL);
}

//String.prototype.indexOf()
void str_indexOf(const char* word, const char* substring, const char** output) 
{
    *output = strstr(word, substring); 
}

//String.prototype.lastIndexOf()

//String.prototype.localeCompare()

//String.prototype.padEnd()

//String.prototype.padStart()

//String.prototype.repeat()

//String.prototype.slice()

//String.prototype.startsWith()

//String.prototype.substring()

//String.prototype.[Symbol.iterator]()

//String.prototype.toLocaleLowerCase()

//String.prototype.toLocaleUpperCase()

//String.prototype.toLowerCase()

//String.prototype.toString()

//String.prototype.toUpperCase()

//String.prototype.trim()

//String.prototype.trimEnd()

//String.prototype.trimStart()

//String.prototype.valueOf()

