#include <stdio.h>
#include <stdbool.h>

int str_length(const char* str) 
{
    int length = 0;
    while (*str) 
    {
        
        if ((*str & 0x80) == 0) 
        {
            str += 1;
        } 
        
        else if ((*str & 0xE0) == 0xC0) 
        {
            str += 2;
        } 
        
        else if ((*str & 0xF0) == 0xE0) 
        {
            str += 3;
        } 
        
        else if ((*str & 0xF8) == 0xF0) 
        {
            str += 4;
        }
        length++;
    }
    return length;
}

// String.prototype.at()
void str_at(const char* str, int index, char* output) 
{
    int len = str_length(str);
    index = (index < 0) ? len + index : index;
    *output = (index < 0 || index >= len) ? '\0' : str[index];
}

// String.prototype.charAt()
void str_charAt(const char* str, int index, char* output) 
{
    int len = str_length(str);
    index = (index < 0) ? len + index : index;
    *output = (index < 0 || index >= len) ? '\0' : str[index];
}

// String.prototype.concat()
void str_concat(const char* str1, const char* str2, char* output) 
{
    int i = 0;
    while (*str1) 
    {
        output[i++] = *str1++;
    }
    while (*str2) 
    {
        output[i++] = *str2++;
    }
    output[i] = '\0';
}

// String.prototype.endsWith()
void str_endsWith(const char* word, const char* end_with, bool* output) 
{
    int word_len = str_length(word);
    int end_with_len = str_length(end_with);
    
    if (end_with_len > word_len) 
    {
        *output = false;
    } 
    else 
    {
        const char* word_ptr = word + word_len - end_with_len;
        *output = true;
        while (*end_with) 
        {
            if (*word_ptr++ != *end_with++) 
            {
                *output = false;
                break;
            }
        }
    }
}

// String.prototype.indexOf()
void str_indexOf(const char* word, const char* substring, int* output) 
{
    int word_len = str_length(word);
    int sub_len = str_length(substring);
    for (int i = 0; i <= word_len - sub_len; i++) 
    {
        int j = 0;
        while (j < sub_len) 
        {
            if (word[i + j] != substring[j]) 
            {
                break;
            }
            j++;
        }
        if (j == sub_len) 
        {
            *output = i;
            return;
        }
    }
    *output = -1;
}

// String.prototype.includes()
void str_includes(const char* word, const char* substring, bool* output) 
{
    int index;
    str_indexOf(word, substring, &index);
    *output = (index != -1);
}

// String.prototype.lastIndexOf()
void str_lastIndexOf(const char* word, const char* substring, int* output) 
{
    int word_len = str_length(word);
    int sub_len = str_length(substring);
    int i, j;
    int last_index = -1;

    for (i = 0; i <= word_len - sub_len; i++) 
    {
        for (j = 0; j < sub_len; j++) 
        {
            if (word[i + j] != substring[j]) 
            {
                break;
            }
        }
        if (j == sub_len) 
        {
            last_index = i;
        }
    }
    *output = last_index;
}

// String.prototype.padEnd()
void str_padEnd(const char* str, int targetLength, const char* padString, char* output) 
{
    int strLen = str_length(str);
    int padLen = str_length(padString);
    int i;

    for (i = 0; i < strLen; i++) 
    {
        output[i] = str[i];
    }

    for (int j = 0; i < targetLength; i++, j++) 
    {
        output[i] = padString[j % padLen];
    }
    output[i] = '\0';
}

// String.prototype.padStart()
void str_padStart(const char* str, int targetLength, const char* padString, char* output) 
{
    int strLen = str_length(str);
    int padLen = str_length(padString);
    int paddings = targetLength - strLen;
    int i = 0, j = 0;

    while (i < paddings) 
    {
        output[i++] = padString[j++ % padLen];
    }

    while (*str) 
    {
        output[i++] = *str++;
    }
    output[i] = '\0';
}

// String.prototype.repeat()
void str_repeat(const char* str, int count, char* output) 
{
    int strLen = str_length(str);
    for (int i = 0; i < count; i++) 
    {
        for (int j = 0; j < strLen; j++) 
        {
            output[i * strLen + j] = str[j];
        }
    }
    output[count * strLen] = '\0';
}

// String.prototype.slice()
void str_slice(const char* str, int start, int end, char* output) 
{
    int strLen = str_length(str);

    if (start < 0) start += strLen;
    if (end < 0) end += strLen;
    if (end > strLen) end = strLen;

    for (int i = start, j = 0; i < end; i++, j++) 
    {
        output[j] = str[i];
    }
    output[end - start] = '\0';
}

// String.prototype.startsWith()
void str_startsWith(const char* str, const char* searchString, int position, bool* output) 
{
    if (position < 0) position = 0;
    while (*searchString) 
    {
        if (str[position++] != *searchString++) 
        {
            *output = false;
            return;
        }
    }
    *output = true;
}

// String.prototype.substring()
void str_substring(const char* str, int start, int end, char* output) 
{
    int strLen = str_length(str);

    if (start < 0) start = 0;
    if (end > strLen) end = strLen;
    if (start > end) 
    {
        int temp = start;
        start = end;
        end = temp;
    }

    for (int i = start; i < end; i++) 
    {
        *output++ = str[i];
    }
    *output = '\0';
}

// String.prototype.toLowerCase()
void str_toLowerCase(const char* str, char* output) 
{
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] >= 'A') 
        {
            if (str[i] <= 'Z') 
            {
                output[i] = str[i] + 32;
            } 
            else 
            {
                output[i] = str[i];
            }
        } 
        else 
        {
            output[i] = str[i];
        }
    }
    output[str_length(str)] = '\0';
}

// String.prototype.toUpperCase()
void str_toUpperCase(const char* str, char* output) 
{
    int i;
    for (i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] >= 'a') 
        {
            if (str[i] <= 'z') 
            {
                output[i] = str[i] - 32;
            } else 
            {
                output[i] = str[i];
            }
        } else 
        {
            output[i] = str[i];
        }
    }
    output[i] = '\0';
}

// String.prototype.trim()
void str_trim(const char* str, char* output) 
{
    int start = 0, end = str_length(str) - 1;
    int i, j;

    while (1) {
        if (str[start] == ' ') 
        {
            start++;
        } else if (str[start] == '\t') 
        {
            start++;
        } else if (str[start] == '\n') 
        {
            start++;
        } else 
        {
            break;
        }
    }

    while (end > start) 
    {
        if (str[end] == ' ') 
        {
            end--;
        } else if (str[end] == '\t') 
        {
            end--;
        } else if (str[end] == '\n') 
        {
            end--;
        } else 
        {
            break;
        }
    }

    for (i = start, j = 0; i <= end; i++, j++) 
    {
        output[j] = str[i];
    }
    output[j] = '\0';
}

// String.prototype.trimEnd()
void str_trimEnd(const char* str, char* output) 
{
    int end = str_length(str) - 1;
    int i;

    while (end >= 0) 
    {
        if (str[end] == ' ') 
        {
            end--;
        } else if (str[end] == '\t') 
        {
            end--;
        } else if (str[end] == '\n') 
        {
            end--;
        } else 
        {
            break;
        }
    }


    for (i = 0; i <= end; i++) 
    {
        output[i] = str[i];
    }
    output[i] = '\0';
}

// String.prototype.trimStart()
void str_trimStart(const char* str, char* output) 
{
    int start = 0;
    int i, j;

    while (1) 
    {
        if (str[start] == ' ') 
        {
            start++;
        } else if (str[start] == '\t') 
        {
            start++;
        } else if (str[start] == '\n') 
        {
            start++;
        } else 
        {
            break;
        }
    }

    for (i = start, j = 0; str[i] != '\0'; i++, j++) 
    {
        output[j] = str[i];
    }
    output[j] = '\0';
}

