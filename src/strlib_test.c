#include <stdio.h>
#include "strlib.h"

int main() {
  
    printf("--------String.prototyp.at()--------\n");
    const char* string_prototyp_at_text = "Hello World";
    printf("Word: %s\n", string_prototyp_at_text);
    printf("Index 5  -> %c\n", str_at(string_prototyp_at_text, 7));
    printf("Index -1 -> %c\n", str_at(string_prototyp_at_text, -1)); 

    return 0;
}