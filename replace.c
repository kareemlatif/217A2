/*--------------------------------------------------------------------*/
/* replace.c                                                             */
/* Replace charachters of one string wiht another                     */
/* Author: Kareem Mohamed                                             */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made. */

static size_t replaceAndWrite(const char *pcLine,
                              const char *pcFrom, const char *pcTo)
{
   const char *pcLineCursor;
   const char *pcMatch;
   size_t uFromLength;
   size_t uReplaceCount = 0;

   assert(pcLine != NULL);
   assert(pcFrom != NULL);
   assert(pcTo != NULL);

   /* Empty source string has no occurrences to replace. */
   if (*pcFrom == '\0')
   {
      fputs(pcLine, stdout);
      return 0;
   }

   uFromLength = Str_getLength(pcFrom);
   pcLineCursor = pcLine;
   pcMatch = Str_search(pcLineCursor, pcFrom);

   /* Write each unmatched portion followed by its replacement. */
   while (pcMatch != NULL)
   {
      while (pcLineCursor < pcMatch)
      {
         putchar(*pcLineCursor);
         pcLineCursor++;
      }

      fputs(pcTo, stdout);
      uReplaceCount++;
      pcLineCursor = pcMatch + uFromLength;
      pcMatch = Str_search(pcLineCursor, pcFrom);
   }

   /* Write the portion of the line following the final match. */
   fputs(pcLineCursor, stdout);
   return uReplaceCount;
}

/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  
   OTHERWISE: If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  
   OTHERWISE: Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0. */

int main(int argc, char *argv[])
{
   enum {MAX_LINE_SIZE = 4096};
   enum {PROPER_ARG_COUNT = 3};

   char acLine[MAX_LINE_SIZE];
   char *pcFrom;
   char *pcTo;
   size_t uReplaceCount = 0;

   if (argc != PROPER_ARG_COUNT)
   {
      fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
      return EXIT_FAILURE;
   }

   pcFrom = argv[1];
   pcTo = argv[2];

   while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL)
      uReplaceCount += replaceAndWrite(acLine, pcFrom, pcTo);

   fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
   return 0;
}
