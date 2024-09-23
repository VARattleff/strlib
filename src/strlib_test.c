#include <stdio.h>
#include "strlib.h"

int main() {
    
    #pragma region String.prototyp.at()
    
    printf("--------String.prototyp.at()--------\n");

    const char* string_prototyp_at_text = "Hello World";
    char output_at; 

    printf("Word: %s\n", string_prototyp_at_text);
    
    str_at(string_prototyp_at_text, 7, &output_at);
    printf("Index 7  -> %c\n", output_at);

    str_at(string_prototyp_at_text, -1, &output_at);
    printf("Index -1 -> %c\n", output_at);

    #pragma endregion

    #pragma region String.prototyp.charAt()
    
    printf("--------String.prototyp.charAt()--------\n");

    const char* string_prototyp_charAt_text = "Hello World";
    char output_charAt; 

    printf("Word: %s\n", string_prototyp_charAt_text);
    
    str_charAt(string_prototyp_charAt_text, 7, &output_charAt);
    printf("Index 7  -> %c\n", output_charAt);

    str_charAt(string_prototyp_charAt_text, -1, &output_charAt);
    printf("Index -1 -> %c\n", output_charAt);

    #pragma endregion

    return 0;
}