#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include "itoa.h"
#include <stdlib.h>
#include <stdint.h>

void arrayReverse(char * buffer)
{
    int i = strlen(buffer);
    char temp[strlen(buffer)];
    while(i > 0)
    {
        temp[strlen(buffer)-i] = buffer[i];
        i--;

    }
    buffer = temp;
}

void myPutchar(char *buffer){
    write(1,buffer,1);
}

void my_printf(char *format, ...)
{
    const unsigned long register ebp asm("ebp");
    char ** secondArgument = ebp + 12;

   // fprintf(stderr, "The second argument: %s\n", secondArgument[0]);
    int i;  
    int addition = 12;
    char ** Current = ebp + addition;
    char * integer = malloc(16);
    char * hex = malloc(16);
    char * unsignedVal = malloc(16);

    while(*format != '\0')
    {
        if (*format == '%')
        {
            *format++;
            switch (*format)
            {
            case 's':
                write(1, Current[0], strlen(Current[0]));
                addition += 4;
                Current = ebp + addition;
                break;
            case 'd':
                itoa(integer, 'd', Current[0]);
                write(1, integer, strlen(integer));
                addition += 4;
                Current = ebp + addition;
                break;
            case 'x':
                itoa(hex, 'x', Current[0]);
                write(1, hex, strlen(hex));
                addition += 4;
                Current = ebp + addition;
                break;
            case 'u':
                ultoa(Current[0], unsignedVal);
                write(1, unsignedVal, strlen(unsignedVal));
                addition += 4;
                Current = ebp + addition;
                break;
            case 'c':
                write(1, Current[0], 1);
                addition += 4;
                Current = ebp + addition;
                break;
            }
            *format++;
        }
        else
        {
            
            myPutchar(format);
            *format++;
        }
    }
}
