
#include <stdio.h>

char str[2][80];

int main()
{
   redirect();
   int data_set_count, k;
   void str_sort(int index);

   scanf("%d\n", &data_set_count);
   for ( k = 1;  k <= data_set_count;  ++k )
     {
      scanf("%s\n", &str[0][0]);
      scanf("%s\n", &str[1][0]);
      str_sort(0);
      str_sort(1);
      printf("Data set #%d: ", k);
      if ( strcmp(str[0],str[1]) > 0 )
         printf("First string is older\n\n");
      else if ( strcmp(str[0],str[1]) < 0 )
         printf("First string is younger\n\n");
      else
         printf("The two strings are the same age\n\n");
     }

}

void str_sort(int index) {
   int next_to_last, sorted, j;
   char temp;

   next_to_last = strlen(str[index]) - 2;
   sorted = 0;
   while ( !sorted )
     {
      sorted = 1;
      for ( j = 0;  j <= next_to_last;  ++j )
         if ( str[index][j] < str[index][j+1] )
           {
            temp = str[index][j];
            str[index][j] = str[index][j+1];
            str[index][j+1] = temp;
            sorted = 0;
           }

      next_to_last = next_to_last - 1;
     }
}


