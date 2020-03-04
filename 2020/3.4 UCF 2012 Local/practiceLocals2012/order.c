

#include <stdio.h>

FILE  *in_fptr,
      *fopen();

main()
{
   int   a, b, c, count, k;
   void  sort2();

   if ( (in_fptr = fopen("order.in", "r")) == NULL )
     {
      printf("*** can't open input file *** \n");
      exit();
     }

   fscanf(in_fptr, "%d", &count);
   for ( k = 1;  k <= count;  ++k )
     {
      fscanf(in_fptr, "%d %d %d", &a, &b, &c);
      printf("Data set #%d:\n", k);
      printf("   Original order: %d %d %d\n", a, b, c);
      /* bubble sort (kind of) */
      sort2(&a,&b);
      sort2(&b,&c);
      sort2(&a,&b);
      printf("   Smallest to largest: %d %d %d\n\n", a, b, c);
     }/* end for */

   if ( fclose(in_fptr) == EOF )
     {
      printf("*** can't close input file *** \n");
      exit();
     }

}/* end main */

/* ******************************************************** */

void sort2(int *p1, int *p2)
{
   int  temp;

   if ( *p1 > *p2 )
     {/* swap */
      temp = *p1;
      *p1 = *p2;
      *p2 = temp;
     }

}/* end sort2 */

/* ******************************************************** */

