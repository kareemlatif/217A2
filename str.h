/*--------------------------------------------------------------------*/
/* str.h                                                              */
/* Interface for string module                                        */
/* Author: Kareem Mohamed                                             */
/*--------------------------------------------------------------------*/

#ifndef STR_INCLUDED
#define STR_INCLUDED
#include <stddef.h>

/*--------------------------------------------------------------------*/

/* Return the number of characters in string pcSrc, excluding the
   terminating null character. */

size_t Str_getLength(const char *pcSrc);

/*--------------------------------------------------------------------*/

/* Copy string pcSrc, including its terminating null character, to
   pcDest, and return pcDest. */

char *Str_copy(char *pcDest, const char *pcSrc);

/*--------------------------------------------------------------------*/

/* Append string pcSrc to string pcDest, including its terminating
   null character, and return pcDest. */

char *Str_concat(char *pcDest, const char *pcSrc);

/*--------------------------------------------------------------------*/

/* Return an integer less than, equal to, or greater than zero if
   pcS1 is, respectively, less than, equal to, or greater than pcS2. */

int Str_compare(const char *pcS1, const char *pcS2);

/*--------------------------------------------------------------------*/

/* Return a pointer to the first occurrence of string pcNeedle in
   string pcHaystack, or NULL if pcNeedle is not found. */

char *Str_search(const char *pcHaystack, const char *pcNeedle);

#endif
