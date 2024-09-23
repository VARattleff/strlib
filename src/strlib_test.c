#include <stdio.h>
#include "strlib.h"
#include <stdbool.h>

int main() {
    
    #pragma region String.prototyp.at()
    
    printf("--------String.prototyp.at()--------\n");

    const char* string_prototyp_at_text = "Hello World";
    char output_at; 

    printf("str: %s\n", string_prototyp_at_text);

    str_at(string_prototyp_at_text, 7, &output_at);
    printf("Index 7  -> %c\n", output_at);

    str_at(string_prototyp_at_text, -1, &output_at);
    printf("Index -1 -> %c\n", output_at);

    #pragma endregion

    #pragma region String.prototyp.charAt()
    
    printf("--------String.prototyp.charAt()--------\n");

    const char* string_prototyp_charAt_text = "Hello World";
    char output_charAt; 

    printf("str: %s\n", string_prototyp_charAt_text);
    
    str_charAt(string_prototyp_charAt_text, 7, &output_charAt);
    printf("Index 7  -> %c\n", output_charAt);

    str_charAt(string_prototyp_charAt_text, -1, &output_charAt);
    printf("Index -1 -> %c\n", output_charAt);

    #pragma endregion

    #pragma region String.prototyp.concat()

    printf("--------String.prototyp.concat()--------\n");

    const char* string_prototyp_concat_str1 = "Hello";
    const char* string_prototyp_concat_str2 = "World";
    char output_concat[100]; 

    printf("str1 -> : %s\n", string_prototyp_concat_str1);
    printf("str2 -> : %s\n", string_prototyp_concat_str2);

    str_concat(string_prototyp_concat_str1, string_prototyp_concat_str2, output_concat);
    printf("str1 + str2  -> %s\n", output_concat); 

    #pragma endregion

    #pragma region String.prototyp.endsWith()

    printf("--------String.prototyp.endsWith()--------\n");
    bool output_endsWith; 

    const char* string_prototyp_endsWith_str = "Hello";
    const char* string_prototyp_endsWith_word = "World";
    printf("%s endsWith %s -> ", string_prototyp_endsWith_str, string_prototyp_endsWith_word);
    str_endsWith(string_prototyp_endsWith_str, string_prototyp_endsWith_word, &output_endsWith);
    printf("%s\n", output_endsWith ? "true" : "false"); 


    const char* string_prototyp_endsWith_str2 = "Hello";
    const char* string_prototyp_endsWith_word2 = "lo";
    printf("%s endsWith %s -> ", string_prototyp_endsWith_str2, string_prototyp_endsWith_word2);
    str_endsWith(string_prototyp_endsWith_str2, string_prototyp_endsWith_word2, &output_endsWith);
    printf("%s\n", output_endsWith ? "true" : "false"); 

    #pragma endregion

    #pragma region String.prototyp.includes()

    printf("--------String.prototyp.includes()--------\n");

    bool output_includes; 

    const char* string_prototyp_includes_str = "Hello world";
    const char* string_prototyp_includes_substring = "world";

    printf("str -> : %s\n", string_prototyp_includes_str);
    printf("substring -> : %s\n", string_prototyp_includes_substring);

    str_includes(string_prototyp_includes_str, string_prototyp_includes_substring, &output_includes);

    printf("result -> %s\n", output_includes ? "true" : "false"); 

    
    #pragma endregion

     #pragma region String.prototyp.indexOf()

    printf("--------String.prototyp.indexOf()--------\n");

    const char* string_prototyp_indexOf_str = "Hello world";
    const char* string_prototyp_indexOf_substring = "world";
    const char* result;

    printf("str -> : %s\n", string_prototyp_indexOf_str);
    printf("substring -> : %s\n", string_prototyp_indexOf_substring);

    str_indexOf(string_prototyp_indexOf_str, string_prototyp_indexOf_substring, &result);
    
    if (result != NULL) 
    {
        printf("result -> found at index: %ld\n", result - string_prototyp_indexOf_str); 
    } else 
    {
        printf("result -> not found\n");
    }

    const char* not_found_substring = "dunno";
    printf("substring -> : %s\n", not_found_substring);
    str_indexOf(string_prototyp_indexOf_str, not_found_substring, &result);
    
    if (result != NULL) 
    {
        printf("result -> found at index: %ld\n", result - string_prototyp_indexOf_str);
    } else 
    {
        printf("result -> not found\n"); 
    }

    #pragma endregion

    return 0;
}