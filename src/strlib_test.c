#include <stdio.h>
#include "strlib.h"
#include <stdbool.h>

void print_separator(const char* function_name) 
{
    printf("\n-------- %s --------\n", function_name);
}

int main() 
{
    char output[100];
    bool bool_output;
    int int_output;

    #pragma region String.prototype.at() og String.prototype.charAt()
    print_separator("String.prototype.at() og String.prototype.charAt()");
    const char* str = "Hello World";
    printf("Original string: %s\n", str);
    
    str_at(str, 7, output);
    printf("at(7): %c\n", output[0]);
    str_at(str, -1, output);
    printf("at(-1): %c\n", output[0]);
    
    str_charAt(str, 0, output);
    printf("charAt(0): %c\n", output[0]);
    #pragma endregion

    #pragma region  String.prototype.concat()
    print_separator("String.prototype.concat()");
    const char* str1 = "Hello";
    const char* str2 = " World";
    str_concat(str1, str2, output);
    printf("concat('%s', '%s'): %s\n", str1, str2, output);
    #pragma endregion

    #pragma region String.prototype.endsWith()
    print_separator("String.prototype.endsWith()");
    str_endsWith("Hello World", "World", &bool_output);
    printf("'Hello World' endsWith 'World': %s\n", bool_output ? "true" : "false");
    str_endsWith("Hello World", "Hello", &bool_output);
    printf("'Hello World' endsWith 'Hello': %s\n", bool_output ? "true" : "false");
    #pragma endregion

    #pragma region  String.prototype.includes()
    print_separator("String.prototype.includes()");
    str_includes("Hello World", "Wor", &bool_output);
    printf("'Hello World' includes 'Wor': %s\n", bool_output ? "true" : "false");
    str_includes("Hello World", "xyz", &bool_output);
    printf("'Hello World' includes 'xyz': %s\n", bool_output ? "true" : "false");
    #pragma endregion

    #pragma region  String.prototype.indexOf() og String.prototype.lastIndexOf()
    print_separator("String.prototype.indexOf() og String.prototype.lastIndexOf()");
    str_indexOf("Hello World World", "World", &int_output);
    printf("indexOf('World') in 'Hello World World': %d\n", int_output);
    str_lastIndexOf("Hello World World", "World", &int_output);
    printf("lastIndexOf('World') in 'Hello World World': %d\n", int_output);
    #pragma endregion

    #pragma region  String.prototype.padEnd() og String.prototype.padStart()
    print_separator("String.prototype.padEnd() og String.prototype.padStart()");
    str_padEnd("Hello", 10, "*", output);
    printf("padEnd('Hello', 10, '*'): %s\n", output);
    str_padStart("Hello", 10, "*", output);
    printf("padStart('Hello', 10, '*'): %s\n", output);
    #pragma endregion

    #pragma region  String.prototype.repeat()
    print_separator("String.prototype.repeat()");
    str_repeat("Ha", 3, output);
    printf("repeat('Ha', 3): %s\n", output);
    #pragma endregion

    #pragma region  String.prototype.slice() og String.prototype.substring()
    print_separator("String.prototype.slice() og String.prototype.substring()");
    str_slice("Hello World", 6, 11, output);
    printf("slice('Hello World', 6, 11): %s\n", output);
    str_substring("Hello World", 6, 11, output);
    printf("substring('Hello World', 6, 11): %s\n", output);
    #pragma endregion

    #pragma region  String.prototype.startsWith()
    print_separator("String.prototype.startsWith()");
    bool_output = str_startsWith("Hello World", "Hello", 0);
    printf("'Hello World' startsWith 'Hello': %s\n", bool_output ? "true" : "false");
    #pragma endregion

    #pragma region  String.prototype.toLowerCase() og String.prototype.toUpperCase()
    print_separator("String.prototype.toLowerCase() og String.prototype.toUpperCase()");
    str_toLowerCase("Hello World", output);
    printf("toLowerCase('Hello World'): %s\n", output);
    str_toUpperCase("Hello World", output);
    printf("toUpperCase('Hello World'): %s\n", output);
    #pragma endregion

    #pragma region  String.prototype.trim(), trimEnd(), og trimStart()
    print_separator("String.prototype.trim(), trimEnd(), og trimStart()");
    str_trim("  Hello World  ", output);
    printf("trim('  Hello World  '): '%s'\n", output);
    str_trimEnd("Hello World  ", output);
    printf("trimEnd('Hello World  '): '%s'\n", output);
    str_trimStart("  Hello World", output);
    printf("trimStart('  Hello World'): '%s'\n", output);
    #pragma endregion

    return 0;
}