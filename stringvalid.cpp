#include <stdio.h>
#include <ctype.h>
int alpha_only ( const char *s )
{
   if ( !*s )
   {
      return 0;
   }
   for ( ; *s; ++s )
   {
      if ( !isalpha ( *s ) )
      {
         return 0;
      }
   }
   return 1;
}

int main ( void )
{
   const char *text[] = 
   {
      "AlphasOnly",
      "(apple",
   };
   size_t i;
   for ( i = 0; i < sizeof text / sizeof *text; ++i )
   {
      printf("\"%s\" : %s\n", text [ i ], 
             alpha_only ( text [ i ] ) ? "valid string" : "invalid string" );
   }
   return 0;
}
