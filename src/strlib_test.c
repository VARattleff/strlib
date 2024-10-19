#include <stdio.h>
#include "strlib.h"
#include <stdbool.h>

void print_separator(const char* function_name) 
{
    printf("\n-------- %s --------\n", function_name);
}

void test_utf8_functions() 
{
    // UTF-8 karakterer
    String utf8_str = str_construct("Hællø Wørld! 😊");
    printf("Original UTF-8 string: %s\n", str_valueOf(utf8_str));

    // String.prototype.at() og String.prototype.charAt()
    print_separator("String.prototype.at() og String.prototype.charAt()");
    String at_result = str_at(utf8_str, 7);
    printf("at(7): %s\n", str_valueOf(at_result));
    String at_neg_result = str_at(utf8_str, -1);
    printf("at(-1): %s\n", str_valueOf(at_neg_result));
    String charAt_result = str_charAt(utf8_str, 0);
    printf("charAt(0): %s\n", str_valueOf(charAt_result));

    // String.prototype.concat()
    print_separator("String.prototype.concat()");
    String str1 = str_construct("Hællø");
    String str2 = str_construct(" Wørld! 😊");
    String concat_result = str_concat(str1, str2);
    printf("concat('%s', '%s'): %s\n", str_valueOf(str1), str_valueOf(str2), str_valueOf(concat_result));

    // String.prototype.endsWith()
    print_separator("String.prototype.endsWith()");
    String end_test = str_construct("Wørld!");
    printf("'%s' endsWith 'Wørld!': %s\n", str_valueOf(utf8_str), 
           str_endsWith(utf8_str, end_test) ? "true" : "false");
    String emoji_test = str_construct("😊");
    printf("'%s' endsWith '😊': %s\n", str_valueOf(utf8_str), 
           str_endsWith(utf8_str, emoji_test) ? "true" : "false");

    // String.prototype.includes()
    print_separator("String.prototype.includes()");
    String include_test = str_construct("Wør");
    printf("'%s' includes 'Wør': %s\n", str_valueOf(utf8_str), 
           str_includes(utf8_str, include_test) ? "true" : "false");
    String xyz_test = str_construct("xyz");
    printf("'%s' includes 'xyz': %s\n", str_valueOf(utf8_str), 
           str_includes(utf8_str, xyz_test) ? "true" : "false");

    // String.prototype.indexOf() og String.prototype.lastIndexOf()
    print_separator("String.prototype.indexOf() og String.prototype.lastIndexOf()");
    String world_test = str_construct("Wørld");
    printf("indexOf('Wørld') in '%s': %d\n", str_valueOf(utf8_str), 
           str_indexOf(utf8_str, world_test));
    printf("lastIndexOf('Wørld') in '%s': %d\n", str_valueOf(utf8_str), 
           str_lastIndexOf(utf8_str, world_test));

    // String.prototype.padEnd() og String.prototype.padStart()
    print_separator("String.prototype.padEnd() og String.prototype.padStart()");
    String pad_str = str_construct("*");
    String hello = str_construct("Hællø");
    String world = str_construct("Wørld");
    String padEnd_result = str_padEnd(hello, 10, pad_str);
    printf("padEnd('Hællø', 10, '*'): %s\n", str_valueOf(padEnd_result));
    String padStart_result = str_padStart(world, 10, pad_str);
    printf("padStart('Wørld', 10, '*'): %s\n", str_valueOf(padStart_result));

    // String.prototype.repeat()
    print_separator("String.prototype.repeat()");
    String emoji = str_construct("😊");
    String repeat_result = str_repeat(emoji, 3);
    printf("repeat('😊', 3): %s\n", str_valueOf(repeat_result));

    // String.prototype.slice() og String.prototype.substring()
    print_separator("String.prototype.slice() og String.prototype.substring()");
    String slice_result = str_slice(utf8_str, 6, 11);
    printf("slice('%s', 6, 11): %s\n", str_valueOf(utf8_str), str_valueOf(slice_result));
    String substring_result = str_substring(utf8_str, 6, 11);
    printf("substring('%s', 6, 11): %s\n", str_valueOf(utf8_str), str_valueOf(substring_result));

    // String.prototype.startsWith()
    print_separator("String.prototype.startsWith()");
    String start_test = str_construct("Hællø");
    printf("'%s' startsWith 'Hællø': %s\n", str_valueOf(utf8_str), 
           str_startsWith(utf8_str, start_test, 0) ? "true" : "false");

    // String.prototype.toLowerCase() og String.prototype.toUpperCase()
    print_separator("String.prototype.toLowerCase() og String.prototype.toUpperCase()");
    String lower_result = str_toLowerCase(utf8_str);
    printf("toLowerCase('%s'): %s\n", str_valueOf(utf8_str), str_valueOf(lower_result));
    String upper_result = str_toUpperCase(utf8_str);
    printf("toUpperCase('%s'): %s\n", str_valueOf(utf8_str), str_valueOf(upper_result));

    // String.prototype.trim(), trimEnd(), og trimStart()
    print_separator("String.prototype.trim(), trimEnd(), og trimStart()");
    String trim_test = str_construct("  Hællø Wørld!  ");
    String trim_result = str_trim(trim_test);
    printf("trim('  Hællø Wørld!  '): '%s'\n", str_valueOf(trim_result));
    String trimEnd_test = str_construct("Hællø Wørld!  ");
    String trimEnd_result = str_trimEnd(trimEnd_test);
    printf("trimEnd('Hællø Wørld!  '): '%s'\n", str_valueOf(trimEnd_result));
    String trimStart_test = str_construct("  Hællø Wørld!");
    String trimStart_result = str_trimStart(trimStart_test);
    printf("trimStart('  Hællø Wørld!'): '%s'\n", str_valueOf(trimStart_result));

    // Cleanup
    str_destruct(utf8_str);
    str_destruct(at_result);
    str_destruct(at_neg_result);
    str_destruct(charAt_result);
    str_destruct(str1);
    str_destruct(str2);
    str_destruct(concat_result);
    str_destruct(end_test);
    str_destruct(emoji_test);
    str_destruct(include_test);
    str_destruct(xyz_test);
    str_destruct(world_test);
    str_destruct(pad_str);
    str_destruct(hello);
    str_destruct(world);
    str_destruct(padEnd_result);
    str_destruct(padStart_result);
    str_destruct(emoji);
    str_destruct(repeat_result);
    str_destruct(slice_result);
    str_destruct(substring_result);
    str_destruct(start_test);
    str_destruct(lower_result);
    str_destruct(upper_result);
    str_destruct(trim_test);
    str_destruct(trim_result);
    str_destruct(trimEnd_test);
    str_destruct(trimEnd_result);
    str_destruct(trimStart_test);
    str_destruct(trimStart_result);
}

int main() 
{
    test_utf8_functions();
    return 0;
}