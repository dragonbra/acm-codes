#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5 + 10;

char str[2][N];

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int main()
{
   redirect();
   int T, k;
   void str_sort(int index);

   scanf("%d\n", &T);
   for ( k = 1;  k <= T;  ++k )
     {
      scanf("%s", str[0]);
      scanf("%s", str[1]);
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


