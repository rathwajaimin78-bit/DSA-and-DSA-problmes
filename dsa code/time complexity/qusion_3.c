/*random is evenly distributed within the range [0,n]. If the average processing time is T(n), what is the value of T(6)?*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int random(int n){
    int lower = 0, upper = n;
    int random_number;

    // Use current time as seed for random generator
    srand(time(0));

    // The formula is: (rand() % (upper - lower + 1)) + lower
   return random_number = (rand() % (upper - lower + 1)) + lower;

    

}

int function(int n) {
    int i = 0;
    if (n <= 0)
    {
        return 0;
    }
    else
    {
        i = random(n - 1);
        printf("this\n");
        return function(i) + function(n - 1 - i);
    }
}
int main()
{
    function( 10 );
    
return 0;
}