#include <stdio.h>
#include <string.h>

//String.prototyp.at()
int str_at(const char* str, int index)
{
    int len = strlen(str);
    index = (index < 0) ? len + index : index;
    return (index < 0 || index >= len) ? '\0' : str[index];
}

//String.prototype.charAt()

//String.prototype.concat()

//String.prototype.endsWith()

//String.prototype.includes()

//String.prototype.indexOf()

//String.prototype.lastIndexOf()

//String.prototype.localeCompare()

//String.prototype.padEnd()

//String.prototype.padStart()

//String.prototype.repeat()

//String.prototype.slice()

//String.prototype.startsWith()

//String.prototype.substring()

//String.prototype.[Symbol.iterator]()

//String.prototype.toLocaleLowerCase()

//String.prototype.toLocaleUpperCase()

//String.prototype.toLowerCase()

//String.prototype.toString()

//String.prototype.toUpperCase()

//String.prototype.trim()

//String.prototype.trimEnd()

//String.prototype.trimStart()

//String.prototype.valueOf()

