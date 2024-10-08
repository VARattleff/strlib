#include <stdio.h>
#include <stdbool.h>

//helper functions
static int utf8_char_length(const char *str) {
    if ((*str & 0x80) == 0) 
    {
        return 1;
    } else if ((*str & 0xE0) == 0xC0) 
    {
        return 2;
    } else if ((*str & 0xF0) == 0xE0) 
    {
        return 3;
    } else if ((*str & 0xF8) == 0xF0) 
    {
        return 4;
    } else 
    {
        return -1;
    }
}

static const char* utf8_next_char(const char* str) 
{
    int char_len = utf8_char_length(str);
    if (char_len > 0) 
    {
        return str + char_len;
    }
    return str;  
}

static const char* utf8_char_at(const char* str, int index) 
{
    int current_index = 0;
    while (*str) 
    {
        if (current_index == index) 
        {
            return str;
        }
        str = utf8_next_char(str);
        current_index++;
    }
    return NULL;  
}

static void utf8_copy_char(const char* src, char* dest) 
{
    int char_len = utf8_char_length(src);
    for (int i = 0; i < char_len; i++) 
    {
        dest[i] = src[i];
    }
    dest[char_len] = '\0';  
}

static int str_length(const char* str) 
{
    int length = 0;
    while (*str) 
    {
        str = utf8_next_char(str);
        length++;
    }
    return length;
}

// String.prototype.at()
void str_at(const char* str, int index, char* output) 
{
    int len = str_length(str);
    if (index < 0) 
    {
        index = len + index;  
    }
    const char* target_char = utf8_char_at(str, index);
    if (target_char) 
    {
        utf8_copy_char(target_char, output);
    } else 
    {
        output[0] = '\0';
    }
}

// String.prototype.charAt()
void str_charAt(const char* str, int index, char* output) 
{
    int len = str_length(str); 
    index = (index < 0) ? len + index : index;

    if (index < 0 || index >= len)
    {
        *output = '\0';
        return;
    }

    const char* current_char = str;
    int current_index = 0;
    
    while (*current_char)
    {
        if (current_index == index)
        {
            utf8_copy_char(current_char, output);
            return;
        }
        current_char = utf8_next_char(current_char);
        current_index++;
    }
    *output = '\0';  
}

// String.prototype.concat()
void str_concat(const char* str1, const char* str2, char* output) 
{
    const char* current = str1;
    
    while (*current) 
    {
        int char_len = utf8_char_length(current);
        for (int i = 0; i < char_len; i++) 
        {
            *output++ = current[i];
        }
        current = utf8_next_char(current);
    }
    
    current = str2;
    while (*current) 
    {
        int char_len = utf8_char_length(current);
        for (int i = 0; i < char_len; i++) 
        {
            *output++ = current[i];
        }
        current = utf8_next_char(current);
    }
    *output = '\0';
}

// String.prototype.endsWith()
void str_endsWith(const char* word, const char* end_with, bool* output) 
{
    int word_len = str_length(word);
    int end_with_len = str_length(end_with);
    
    if (end_with_len > word_len) 
    {
        *output = false;
        return;
    }

    const char* word_ptr = utf8_char_at(word, word_len - end_with_len);
    const char* end_ptr = end_with;
    
    while (*end_ptr) 
    {
        if (*word_ptr != *end_ptr) 
        {
            *output = false;
            return;
        }
        word_ptr = utf8_next_char(word_ptr);
        end_ptr = utf8_next_char(end_ptr);
    }
    *output = true;
}

// String.prototype.indexOf()
void str_indexOf(const char* word, const char* substring, int* output) 
{
    int word_len = str_length(word);
    int sub_len = str_length(substring);

    const char* word_ptr = word;
    for (int i = 0; i <= word_len - sub_len; i++) 
    {
        const char* word_iter = word_ptr;
        const char* sub_iter = substring;
        bool match = true;

        while (*sub_iter && match) 
        {
            if (*word_iter != *sub_iter) 
            {
                match = false;
                break;
            }
            word_iter = utf8_next_char(word_iter);
            sub_iter = utf8_next_char(sub_iter);
        }

        if (match && *sub_iter == '\0') 
        {
            *output = i;
            return;
        }
        word_ptr = utf8_next_char(word_ptr);
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

    const char* pad_ptr = padString;
    
    for (int i = 0; i < paddings; i++) 
    {
        int pad_char_len = utf8_char_length(pad_ptr);
        for (int j = 0; j < pad_char_len; j++) 
        {
            *output++ = pad_ptr[j];
        }
        pad_ptr = utf8_next_char(pad_ptr);

        if (*pad_ptr == '\0') pad_ptr = padString;  
    }

    while (*str) 
    {
        int char_len = utf8_char_length(str);
        for (int i = 0; i < char_len; i++) 
        {
            *output++ = str[i];
        }
        str = utf8_next_char(str);
    }
    
    *output = '\0';
}

// String.prototype.repeat()
void str_repeat(const char* str, int count, char* output) 
{
    const char* current_char = str;
    for (int i = 0; i < count; i++) 
    {
        current_char = str;
        while (*current_char) 
        {
            utf8_copy_char(current_char, output);
            output += utf8_char_length(current_char);
            current_char = utf8_next_char(current_char);
        }
    }
    *output = '\0';
}

// String.prototype.slice()
void str_slice(const char* str, int start, int end, char* output) 
{
    int strLen = str_length(str);

    if (start < 0) start += strLen;
    if (end < 0) end += strLen;
    if (end > strLen) end = strLen;

    const char* current_char = str;
    const char* slice_start = NULL;
    const char* slice_end = NULL;
    int current_index = 0;
    
    while (*current_char)
    {
        if (current_index == start) slice_start = current_char;
        if (current_index == end) 
        {
            slice_end = current_char;
            break;
        }
        current_char = utf8_next_char(current_char);
        current_index++;
    }
    if (!slice_end) slice_end = current_char;  
    
    while (slice_start < slice_end) 
    {
        int char_len = utf8_char_length(slice_start);
        for (int i = 0; i < char_len; i++) 
        {
            *output++ = slice_start[i];
        }
        slice_start = utf8_next_char(slice_start);
    }
    *output = '\0';
}

// String.prototype.startsWith()
void str_startsWith(const char* str, const char* searchString, int position, bool* output) 
{
    if (position < 0) position = 0;

    const char* str_ptr = str;
    const char* search_ptr = searchString;

    for (int i = 0; i < position && *str_ptr; i++) 
    {
        str_ptr = utf8_next_char(str_ptr);
    }

    while (*search_ptr) 
    {
        int str_len = utf8_char_length(str_ptr);
        int search_len = utf8_char_length(search_ptr);

        if (str_len != search_len) 
        {
            *output = false;
            return;
        }

        for (int i = 0; i < str_len; i++) 
        {
            if (str_ptr[i] != search_ptr[i]) 
            {
                *output = false;
                return;
            }
        }

        str_ptr = utf8_next_char(str_ptr);
        search_ptr = utf8_next_char(search_ptr);
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

    const char* current_char = str;
    int current_index = 0;
    
    while (*current_char) 
    {
        if (current_index >= start && current_index < end) 
        {
            utf8_copy_char(current_char, output);
            output += utf8_char_length(current_char);
        }
        current_char = utf8_next_char(current_char);
        current_index++;
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

