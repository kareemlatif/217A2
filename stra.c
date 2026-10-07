/*--------------------------------------------------------------------*/
/* stra.c                                                             */
/* Array implemntation of the string module                           */
/* Author: Kareem Mohamed                                             */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <assert.h>

/*--------------------------------------------------------------------*/

/* Return the length of string pcSrc. */

size_t Str_getLength(const char pcSrc[])
{
    size_t uLength = 0;

    assert(pcSrc != NULL);

    while (pcSrc[uLength] != '\0')
        uLength++;

    return uLength;
}

/*--------------------------------------------------------------------*/

/* Copy string pcSrc to pcDest, and return pcDest. */

char *Str_copy(char pcDest[], const char pcSrc[])
{
    size_t uIndex = 0;

    assert(pcDest != NULL);
    assert(pcSrc != NULL);

    while (pcSrc[uIndex] != '\0')
    {
        pcDest[uIndex] = pcSrc[uIndex];
        uIndex++;
    }

    pcDest[uIndex] = '\0';
    return pcDest;
}

/*--------------------------------------------------------------------*/

/* Append string pcSrc to pcDest, and return pcDest. */

char *Str_concat(char pcDest[], const char pcSrc[])
{
    size_t uDestIndex = 0;
    size_t uSrcIndex = 0;

    assert(pcDest != NULL);
    assert(pcSrc != NULL);

    while (pcDest[uDestIndex] != '\0')
        uDestIndex++;

    while (pcSrc[uSrcIndex] != '\0')
    {
        pcDest[uDestIndex] = pcSrc[uSrcIndex];
        uDestIndex++;
        uSrcIndex++;
    }

    pcDest[uDestIndex] = '\0';
    return pcDest;
}

/*--------------------------------------------------------------------*/

/* Compare strings pcS1 and pcS2 lexicographically. */

int Str_compare(const char pcS1[], const char pcS2[])
{
    size_t uIndex = 0;

    assert(pcS1 != NULL);
    assert(pcS2 != NULL);

    while (pcS1[uIndex] == pcS2[uIndex] &&
           pcS1[uIndex] != '\0')
    {
        uIndex++;
    }

    return (int)(unsigned char)pcS1[uIndex]
         - (int)(unsigned char)pcS2[uIndex];
}

/*--------------------------------------------------------------------*/

/* Search string pcHaystack for the first occurrence of pcNeedle. */

char *Str_search(const char pcHaystack[], const char pcNeedle[])
{
    size_t uHaystackIndex;
    size_t uNeedleIndex;

    assert(pcHaystack != NULL);
    assert(pcNeedle != NULL);

    if (pcNeedle[0] == '\0')
        return (char *)pcHaystack;

    for (uHaystackIndex = 0;
         pcHaystack[uHaystackIndex] != '\0';
         uHaystackIndex++)
    {
        uNeedleIndex = 0;

        while (pcNeedle[uNeedleIndex] != '\0' &&
               pcHaystack[uHaystackIndex + uNeedleIndex] ==
                   pcNeedle[uNeedleIndex])
        {
            uNeedleIndex++;
        }

        if (pcNeedle[uNeedleIndex] == '\0')
            return (char *)&pcHaystack[uHaystackIndex];
    }

    return NULL;
}
