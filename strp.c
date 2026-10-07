/*--------------------------------------------------------------------*/
/* strp.c                                                             */
/* Pointer implemntation of the string module                         */
/* Author: Kareem Mohamed                                             */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <assert.h>

/*--------------------------------------------------------------------*/

/* Return the length of string pcSrc. */

size_t Str_getLength(const char *pcSrc)
{
    const char *pcEnd;

    assert(pcSrc != NULL);

    pcEnd = pcSrc;
    while (*pcEnd != '\0')
        pcEnd++;

    return (size_t)(pcEnd - pcSrc);
}

/*--------------------------------------------------------------------*/

/* Copy string pcSrc to pcDest, and return pcDest. */

char *Str_copy(char *pcDest, const char *pcSrc)
{
   char *pcDestStart;

   assert(pcDest != NULL);
   assert(pcSrc != NULL);

   pcDestStart = pcDest;

   while (*pcSrc != '\0')
   {
      *pcDest = *pcSrc;
      pcDest++;
      pcSrc++;
   }

   *pcDest = '\0';
   return pcDestStart;
    
}

/*--------------------------------------------------------------------*/

/* Append string pcSrc to pcDest, and return pcDest. */

char *Str_concat(char *pcDest, const char *pcSrc)
{
    char *pcDestStart;

    assert(pcDest != NULL);
    assert(pcSrc != NULL);

    pcDestStart = pcDest;

    while (*pcDest != '\0')
        pcDest++;

    while (*pcSrc != '\0')
    {
        *pcDest = *pcSrc;
        pcDest++;
        pcSrc++;
    }

    *pcDest = '\0';

    return pcDestStart;
}

/*--------------------------------------------------------------------*/

/* Compare strings pcS1 and pcS2 lexicographically. */

int Str_compare(const char *pcS1, const char *pcS2)
{
    assert(pcS1 != NULL);
    assert(pcS2 != NULL);

    while (*pcS1 == *pcS2 && *pcS1 != '\0')
    {
        pcS1++;
        pcS2++;
    }

    return (int)(unsigned char)*pcS1 - (int)(unsigned char)*pcS2;
}

/*--------------------------------------------------------------------*/

/* Search string pcHaystack for the first occurrence of pcNeedle. */

char *Str_search(const char *pcHaystack, const char *pcNeedle)
{
    const char *pcPossibleMatch;
    const char *pcHaystackCursor;
    const char *pcNeedleCursor;

    assert(pcHaystack != NULL);
    assert(pcNeedle != NULL);

    if (*pcNeedle == '\0')
        return (char *)pcHaystack;

    pcPossibleMatch = pcHaystack;
    while (*pcPossibleMatch != '\0')
    {
        pcHaystackCursor = pcPossibleMatch;
        pcNeedleCursor = pcNeedle;

        while (*pcHaystackCursor != '\0' &&
               *pcNeedleCursor != '\0' &&
               *pcHaystackCursor == *pcNeedleCursor)
        {
            pcHaystackCursor++;
            pcNeedleCursor++;
        }

        if (*pcNeedleCursor == '\0')
            return (char *)pcPossibleMatch;

        pcPossibleMatch++;
    }

    return NULL;
}
