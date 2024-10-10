 

#include <stdio.h>
#include <stdlib.h>

 
 
double min_de_3(double val1, double val2, double val3) ;

int main(void) {

    printf("%lf\n", min_de_3(32, 2, 18) );
    printf("%lf\n", min_de_3(30, -40, 50) );

    return 0;
}

double min_de_3(double val1, double val2, double val3)
{
    double val1_abs, val2_abs, val3_abs;
    double min;

     
    val1_abs = val1<0 ? -val1 : val1;
    val2_abs = val2<0 ? -val2 : val2;
    val3_abs = val3<0 ? -val3 : val3;

    min = val1_abs;
    if(val2_abs < min )
    {
        min = val2_abs;
    }
    if(val3_abs < min )
    {
        min = val3_abs;
    }

    return min;
}