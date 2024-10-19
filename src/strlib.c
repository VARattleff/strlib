#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "strlib.h"

// Helper functions
static int utf8_char_length(const char *str) 
{
    if ((*str & 0x80) == 0) return 1;
    else if ((*str & 0xE0) == 0xC0) return 2;
    else if ((*str & 0xF0) == 0xE0) return 3;
    else if ((*str & 0xF8) == 0xF0) return 4;
    else return -1;
}

static const char* utf8_next_char(const char* str) 
{
    int char_len = utf8_char_length(str);
    if (char_len > 0) return str + char_len;
    return str;
}

String str_construct(const char* str) 
{
    String result;
    if (str == NULL) 
    {
        result.data = NULL;
        result.byte_length = 0;
        result.char_length = 0;
        result.owns_data = false;
        return result;
    }
    
    size_t byte_len = 0;
    size_t char_len = 0;
    const char* p = str;
    while (*p) 
    {
        int char_size = utf8_char_length(p);
        byte_len += char_size;
        char_len++;
        p += char_size;
    }
    
    result.data = (char*)malloc(byte_len + 1);
    for (size_t i = 0; i <= byte_len; i++) 
    {
        result.data[i] = str[i];
    }
    result.byte_length = byte_len;
    result.char_length = char_len;
    result.owns_data = true;
    
    return result;
}

void str_destruct(String str) 
{
    if (str.owns_data && str.data != NULL) 
    {
        free(str.data);
    }
}

char* str_valueOf(String str) 
{
    char* result = (char*)malloc(str.byte_length + 1);
    for (size_t i = 0; i <= str.byte_length; i++) 
    {
        result[i] = str.data[i];
    }
    return result;
}

// String.prototype.at()
String str_at(String str, int index) 
{
    if (index < 0) 
    {
        index = str.char_length + index;
    }
    
    if (index < 0 || index >= str.char_length) 
    {
        return str_construct("");
    }
    
    const char* current = str.data;
    for (int i = 0; i < index; i++) 
    {
        current = utf8_next_char(current);
    }
    
    int char_len = utf8_char_length(current);
    char temp[5] = {0}; 
    for (int i = 0; i < char_len; i++) 
    {
        temp[i] = current[i];
    }
    
    return str_construct(temp);
}

// String.prototype.charAt()
String str_charAt(String str, int index) 
{
    return str_at(str, index); 
}

// String.prototype.concat()
String str_concat(String str1, String str2) 
{
    String result;
    result.byte_length = str1.byte_length + str2.byte_length;
    result.char_length = str1.char_length + str2.char_length;
    result.data = (char*)malloc(result.byte_length + 1);
    result.owns_data = true;
    
    for (size_t i = 0; i < str1.byte_length; i++) 
    {
        result.data[i] = str1.data[i];
    }
    
    for (size_t i = 0; i < str2.byte_length; i++) 
    {
        result.data[str1.byte_length + i] = str2.data[i];
    }
    
    result.data[result.byte_length] = '\0';
    return result;
}

// String.prototype.endsWith()
bool str_endsWith(String str, String searchStr) 
{
    if (searchStr.char_length > str.char_length) 
    {
        return false;
    }
    
    const char* str_end = str.data + str.byte_length - searchStr.byte_length;
    return memcmp(str_end, searchStr.data, searchStr.byte_length) == 0;
}

// String.prototype.indexOf()
int str_indexOf(String str, String searchStr) 
{
    if (searchStr.char_length > str.char_length) 
    {
        return -1;
    }
    
    const char* haystack = str.data;
    size_t char_pos = 0;
    
    while (*haystack) 
    {
        if (memcmp(haystack, searchStr.data, searchStr.byte_length) == 0) 
        {
            return char_pos;
        }
        haystack = utf8_next_char(haystack);
        char_pos++;
    }
    
    return -1;
}

// String.prototype.includes()
bool str_includes(String str, String searchStr) 
{
    return str_indexOf(str, searchStr) != -1;
}

// String.prototype.lastIndexOf()
int str_lastIndexOf(String str, String searchStr) 
{
    if (searchStr.char_length > str.char_length) 
    {
        return -1;
    }
    
    int last_found = -1;
    const char* haystack = str.data;
    size_t char_pos = 0;
    
    while (*haystack) 
    {
        if (memcmp(haystack, searchStr.data, searchStr.byte_length) == 0) 
        {
            last_found = char_pos;
        }
        haystack = utf8_next_char(haystack);
        char_pos++;
    }
    
    return last_found;
}

// String.prototype.padEnd()
String str_padEnd(String str, size_t targetLength, String padStr) 
{
    if (str.char_length >= targetLength) 
    {
        return str_construct(str.data);
    }
    
    size_t pad_chars_needed = targetLength - str.char_length;
    String result;
    result.data = (char*)malloc(str.byte_length + (pad_chars_needed * padStr.byte_length / padStr.char_length) + 1);
    result.owns_data = true;
    
    memcpy(result.data, str.data, str.byte_length);
    
    size_t current_pos = str.byte_length;
    const char* pad_ptr = padStr.data;
    for (size_t i = 0; i < pad_chars_needed; i++) 
    {
        int char_len = utf8_char_length(pad_ptr);
        memcpy(result.data + current_pos, pad_ptr, char_len);
        current_pos += char_len;
        pad_ptr = utf8_next_char(pad_ptr);
        if (*pad_ptr == '\0') pad_ptr = padStr.data;
    }
    
    result.data[current_pos] = '\0';
    result.byte_length = current_pos;
    result.char_length = targetLength;
    
    return result;
}

// String.prototype.padStart()
String str_padStart(String str, size_t targetLength, String padStr) 
{
    if (str.char_length >= targetLength) 
    {
        return str_construct(str.data);
    }
    
    size_t pad_chars_needed = targetLength - str.char_length;
    String result;
    result.data = (char*)malloc(str.byte_length + (pad_chars_needed * padStr.byte_length / padStr.char_length) + 1);
    result.owns_data = true;
    
    size_t current_pos = 0;
    const char* pad_ptr = padStr.data;
    for (size_t i = 0; i < pad_chars_needed; i++) 
    {
        int char_len = utf8_char_length(pad_ptr);
        memcpy(result.data + current_pos, pad_ptr, char_len);
        current_pos += char_len;
        pad_ptr = utf8_next_char(pad_ptr);
        if (*pad_ptr == '\0') pad_ptr = padStr.data;
    }
    
    memcpy(result.data + current_pos, str.data, str.byte_length);
    current_pos += str.byte_length;
    
    result.data[current_pos] = '\0';
    result.byte_length = current_pos;
    result.char_length = targetLength;
    
    return result;
}

// String.prototype.repeat()
String str_repeat(String str, size_t count) 
{
    if (count == 0) 
    {
        return str_construct("");
    }
    
    String result;
    result.byte_length = str.byte_length * count;
    result.char_length = str.char_length * count;
    result.data = (char*)malloc(result.byte_length + 1);
    result.owns_data = true;
    
    size_t current_pos = 0;
    for (size_t i = 0; i < count; i++) 
    {
        memcpy(result.data + current_pos, str.data, str.byte_length);
        current_pos += str.byte_length;
    }
    
    result.data[result.byte_length] = '\0';
    return result;
}

// String.prototype.slice()
String str_slice(String str, int start, int end) 
{
    if (start < 0) start += str.char_length;
    if (end < 0) end += str.char_length;
    if (end > str.char_length) end = str.char_length;
    if (start > end) start = end;
    
    if (start < 0) start = 0;
    if (end < 0) end = 0;
    
    const char* start_ptr = str.data;
    for (int i = 0; i < start && *start_ptr; i++) 
    {
        start_ptr = utf8_next_char(start_ptr);
    }
    
    const char* end_ptr = start_ptr;
    for (int i = start; i < end && *end_ptr; i++) 
    {
        end_ptr = utf8_next_char(end_ptr);
    }
    
    size_t byte_len = end_ptr - start_ptr;
    String result;
    result.data = (char*)malloc(byte_len + 1);
    result.owns_data = true;
    memcpy(result.data, start_ptr, byte_len);
    result.data[byte_len] = '\0';
    result.byte_length = byte_len;
    result.char_length = end - start;
    
    return result;
}

// String.prototype.startsWith()
bool str_startsWith(String str, String searchStr, size_t position) 
{
    if (position >= str.char_length) 
    {
        return false;
    }
    
    const char* start_ptr = str.data;
    for (size_t i = 0; i < position; i++) 
    {
        start_ptr = utf8_next_char(start_ptr);
    }
    
    return memcmp(start_ptr, searchStr.data, searchStr.byte_length) == 0;
}

// String.prototype.substring()
String str_substring(String str, int start, int end) 
{
    if (start < 0) start = 0;
    if (end > str.char_length) end = str.char_length;
    if (start > end) 
    {
        int temp = start;
        start = end;
        end = temp;
    }
    
    return str_slice(str, start, end);
}

// String.prototype.toLowerCase()
String str_toLowerCase(String str) 
{
    String result;
    result.data = (char*)malloc(str.byte_length + 1);
    result.owns_data = true;
    result.byte_length = str.byte_length;
    result.char_length = str.char_length;
    
    for (size_t i = 0; i < str.byte_length; i++) 
    {
        if (str.data[i] >= 'A' && str.data[i] <= 'Z') 
        {
            result.data[i] = str.data[i] + 32;
        } else 
        {
            result.data[i] = str.data[i];
        }
    }
    
    result.data[str.byte_length] = '\0';
    return result;
}

// String.prototype.toUpperCase()
String str_toUpperCase(String str) 
{
    String result;
    result.data = (char*)malloc(str.byte_length + 1);
    result.owns_data = true;
    result.byte_length = str.byte_length;
    result.char_length = str.char_length;
    
    for (size_t i = 0; i < str.byte_length; i++) 
    {
        if (str.data[i] >= 'a' && str.data[i] <= 'z') 
        {
            result.data[i] = str.data[i] - 32;
        } else 
        {
            result.data[i] = str.data[i];
        }
    }
    
    result.data[str.byte_length] = '\0';
    return result;
}
// String.prototype.trim()
String str_trim(String str) 
{
    if (str.char_length == 0) 
    {
        return str_construct("");
    }

    const char* start = str.data;
    const char* end = str.data + str.byte_length - 1;

    while (*start && (*start == ' ' || *start == '\t' || *start == '\n')) 
    {
        start = utf8_next_char(start);
    }

    while (end > start && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\0')) 
    {
        end--;
    }

    size_t new_byte_length = end - start + 1;
    
    String result;
    result.data = (char*)malloc(new_byte_length + 1);
    result.owns_data = true;
    
    memcpy(result.data, start, new_byte_length);
    result.data[new_byte_length] = '\0';
    result.byte_length = new_byte_length;
    
    result.char_length = 0;
    const char* p = result.data;
    while (*p) 
    {
        p = utf8_next_char(p);
        result.char_length++;
    }
    
    return result;
}

// String.prototype.trimEnd()
String str_trimEnd(String str) 
{
    if (str.char_length == 0) 
    {
        return str_construct("");
    }

    const char* end = str.data + str.byte_length - 1;

    while (end > str.data && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\0')) 
    {
        end--;
    }

    size_t new_byte_length = end - str.data + 1;
    
    String result;
    result.data = (char*)malloc(new_byte_length + 1);
    result.owns_data = true;
    
    memcpy(result.data, str.data, new_byte_length);
    result.data[new_byte_length] = '\0';
    result.byte_length = new_byte_length;
    
    result.char_length = 0;
    const char* p = result.data;
    while (*p) 
    {
        p = utf8_next_char(p);
        result.char_length++;
    }
    
    return result;
}

// String.prototype.trimStart()
String str_trimStart(String str) 
{
    if (str.char_length == 0) 
    {
        return str_construct("");
    }

    const char* start = str.data;

    while (*start && (*start == ' ' || *start == '\t' || *start == '\n')) 
    {
        start = utf8_next_char(start);
    }

    size_t new_byte_length = (str.data + str.byte_length) - start;
    
    String result;
    result.data = (char*)malloc(new_byte_length + 1);
    result.owns_data = true;
    
    memcpy(result.data, start, new_byte_length);
    result.data[new_byte_length] = '\0';
    result.byte_length = new_byte_length;
    
    result.char_length = 0;
    const char* p = result.data;
    while (*p) 
    {
        p = utf8_next_char(p);
        result.char_length++;
    }
    
    return result;
}