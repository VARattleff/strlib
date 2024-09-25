#include <stdio.h>
#include <stdbool.h>

int str_length(const char* str) 
{
    int len = 0;
    while (str[len] != '\0') 
    {
        len++;
    }
    return len;
}

// String.prototype.at()
void str_at(const char* str, int index, char* output) 
{
    int len = str_length(str);
    if (index < 0) 
    {
        index = len + index;
    }
    
    if (index < 0) 
    {
        *output = '\0';
    } else if (index >= len) 
    {
        *output = '\0';
    } else 
    {
        *output = str[index];
    }
}

// String.prototype.charAt()
void str_charAt(const char* str, int index, char* output) 
{
    int len = str_length(str);
    if (index < 0) 
    {
        index = len + index;
    }
    
    if (index < 0) 
    {
        *output = '\0';
    } else if (index >= len) 
    {
        *output = '\0';
    } else 
    {
        *output = str[index];
    }
}

// String.prototype.concat()
void str_concat(const char* str1, const char* str2, char* output) 
{
    int len_str1 = str_length(str1);
    int len_str2 = str_length(str2);
    int i, j;

    for (i = 0; i < len_str1; i++) 
    {
        output[i] = str1[i];
    }
    for (j = 0; j < len_str2; j++) 
    {
        output[i + j] = str2[j];
    }
    output[i + j] = '\0';
}

// String.prototype.endsWith()
void str_endsWith(const char* word, const char* end_with, bool* output) 
{
    int word_len = str_length(word);
    int end_with_len = str_length(end_with);
    int i;

    if (end_with_len > word_len) 
    {
        *output = false;
        return;
    }

    for (i = 0; i < end_with_len; i++) 
    {
        if (word[word_len - end_with_len + i] != end_with[i]) 
        {
            *output = false;
            return;
        }
    }
    *output = true;
}

// String.prototype.includes()
void str_includes(const char* word, const char* substring, bool* output) 
{
    int word_len = str_length(word);
    int sub_len = str_length(substring);
    int i, j;

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
            *output = true;
            return;
        }
    }
    *output = false;
}

// String.prototype.indexOf()
void str_indexOf(const char* word, const char* substring, int* output) 
{
    int word_len = str_length(word);
    int sub_len = str_length(substring);
    int i, j;

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
            *output = i;
            return;
        }
    }
    *output = -1;
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
    int i, j;

    for (i = 0; i < strLen; i++) 
    {
        output[i] = str[i];
    }

    j = 0;
    while (i < targetLength) 
    {
        output[i] = padString[j % padLen];
        i++;
        j++;
    }
    output[i] = '\0';
}

// String.prototype.padStart()
void str_padStart(const char* str, int targetLength, const char* padString, char* output) 
{
    int strLen = str_length(str);
    int padLen = str_length(padString);
    int paddings = targetLength - strLen;
    int i, j;

    j = 0;
    for (i = 0; i < paddings; i++) 
    {
        output[i] = padString[j % padLen];
        j++;
    }

    for (j = 0; j < strLen; j++) 
    {
        output[i + j] = str[j];
    }
    output[i + j] = '\0';
}

// String.prototype.repeat()
void str_repeat(const char* str, int count, char* output) 
{
    int strLen = str_length(str);
    int i, j;

    for (i = 0; i < count; i++) 
    {
        for (j = 0; j < strLen; j++) 
        {
            output[i * strLen + j] = str[j];
        }
    }
    output[i * strLen] = '\0';
}

// String.prototype.slice()
void str_slice(const char* str, int start, int end, char* output) 
{
    int strLen = str_length(str);
    int i, j;

    if (start < 0) start = strLen + start;
    if (end < 0) end = strLen + end;
    if (end > strLen) end = strLen;

    for (i = start, j = 0; i < end; i++, j++) 
    {
        output[j] = str[i];
    }
    output[j] = '\0';
}

// String.prototype.startsWith()
bool str_startsWith(const char* str, const char* searchString, int position) 
{
    int strLen = str_length(str);
    int searchLen = str_length(searchString);
    int i;

    if (position < 0) position = 0;
    if (position + searchLen > strLen) return false;

    for (i = 0; i < searchLen; i++) 
    {
        if (str[position + i] != searchString[i]) return false;
    }
    return true;
}

// String.prototype.substring()
void str_substring(const char* str, int start, int end, char* output) 
{
    int strLen = str_length(str);
    int i, j;

    if (start < 0) start = 0;
    if (end > strLen) end = strLen;
    if (start > end) 
    {
        int temp = start;
        start = end;
        end = temp;
    }

    for (i = start, j = 0; i < end; i++, j++) 
    {
        output[j] = str[i];
    }
    output[j] = '\0';
}

// String.prototype.toLowerCase()
void str_toLowerCase(const char* str, char* output) 
{
    int i;
    for (i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] >= 'A') 
        {
            if (str[i] <= 'Z') 
            {
                output[i] = str[i] + 32;
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
