#include <stdio.h>
#include "strlib.h"
#include <stdbool.h>

void print_separator(const char* function_name) 
{
    printf("\n-------- %s --------\n", function_name);
}

void test_utf8_functions() 
{
    char output[100];
    bool bool_output;
    int int_output;

    // UTF-8 karakterer
    const char* utf8_str = "Hællø Wørld! 😊"; 
    printf("Original UTF-8 string: %s\n", utf8_str);

    // String.prototype.at() og String.prototype.charAt()
    print_separator("String.prototype.at() og String.prototype.charAt()");
    str_at(utf8_str, 7, output); 
    printf("at(7): %s\n", output);
    str_at(utf8_str, -1, output);
    printf("at(-1): %s\n", output); 
    str_charAt(utf8_str, 0, output);
    printf("charAt(0): %s\n", output);

    // String.prototype.concat()
    print_separator("String.prototype.concat()");
    const char* str1 = "Hællø";
    const char* str2 = " Wørld! 😊";
    str_concat(str1, str2, output);
    printf("concat('%s', '%s'): %s\n", str1, str2, output);

    // String.prototype.endsWith()
    print_separator("String.prototype.endsWith()");
    str_endsWith(utf8_str, "Wørld!", &bool_output);
    printf("'%s' endsWith 'Wørld!': %s\n", utf8_str, bool_output ? "true" : "false");
    str_endsWith(utf8_str, "😊", &bool_output);
    printf("'%s' endsWith '😊': %s\n", utf8_str, bool_output ? "true" : "false");

    // String.prototype.includes()
    print_separator("String.prototype.includes()");
    str_includes(utf8_str, "Wør", &bool_output);
    printf("'%s' includes 'Wør': %s\n", utf8_str, bool_output ? "true" : "false");
    str_includes(utf8_str, "xyz", &bool_output);
    printf("'%s' includes 'xyz': %s\n", utf8_str, bool_output ? "true" : "false");

    // String.prototype.indexOf() og String.prototype.lastIndexOf()
    print_separator("String.prototype.indexOf() og String.prototype.lastIndexOf()");
    str_indexOf(utf8_str, "Wørld", &int_output);
    printf("indexOf('Wørld') in '%s': %d\n", utf8_str, int_output);
    str_lastIndexOf(utf8_str, "Wørld", &int_output);
    printf("lastIndexOf('Wørld') in '%s': %d\n", utf8_str, int_output);

    // String.prototype.padEnd() og String.prototype.padStart()
    print_separator("String.prototype.padEnd() og String.prototype.padStart()");
    str_padEnd("Hællø", 10, "*", output);
    printf("padEnd('Hællø', 10, '*'): %s\n", output);
    str_padStart("Wørld", 10, "*", output);
    printf("padStart('Wørld', 10, '*'): %s\n", output);

    // String.prototype.repeat()
    print_separator("String.prototype.repeat()");
    str_repeat("😊", 3, output);
    printf("repeat('😊', 3): %s\n", output);

    // String.prototype.slice() og String.prototype.substring()
    print_separator("String.prototype.slice() og String.prototype.substring()");
    str_slice(utf8_str, 6, 11, output); // 'Wørld'
    printf("slice('%s', 6, 11): %s\n", utf8_str, output);
    str_substring(utf8_str, 6, 11, output);
    printf("substring('%s', 6, 11): %s\n", utf8_str, output);

    // String.prototype.startsWith()
    print_separator("String.prototype.startsWith()");
    str_startsWith(utf8_str, "Hællø", 0, &bool_output);
    printf("'%s' startsWith 'Hællø': %s\n", utf8_str, bool_output ? "true" : "false");

    // String.prototype.toLowerCase() og String.prototype.toUpperCase()
    print_separator("String.prototype.toLowerCase() og String.prototype.toUpperCase()");
    str_toLowerCase(utf8_str, output);
    printf("toLowerCase('%s'): %s\n", utf8_str, output);
    str_toUpperCase(utf8_str, output);
    printf("toUpperCase('%s'): %s\n", utf8_str, output);

    // String.prototype.trim(), trimEnd(), og trimStart()
    print_separator("String.prototype.trim(), trimEnd(), og trimStart()");
    str_trim("  Hællø Wørld!  ", output);
    printf("trim('  Hællø Wørld!  '): '%s'\n", output);
    str_trimEnd("Hællø Wørld!  ", output);
    printf("trimEnd('Hællø Wørld!  '): '%s'\n", output);
    str_trimStart("  Hællø Wørld!", output);
    printf("trimStart('  Hællø Wørld!'): '%s'\n", output);
}

int main() 
{
    test_utf8_functions();
    return 0;
}