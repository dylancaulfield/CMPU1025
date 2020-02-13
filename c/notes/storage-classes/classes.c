#include <stdio.h>

int main()
{

    /*

        Auto variables

        - Also known as 'local' variables
        - Variables are auto by default
        - Auto variables lose their data when the function ends

    */

    auto int a;
    auto float b[5];

    /*

        Static variables

        - Static variables are also local variables
        - Static variables retain their data after the function ends

    */

    static int c;
    static float d[5];

    /*

        Register variables

        - Register variables have their memory allocated inside the CPU
        and not main memory (RAM)

    */

    register int e;
    register float f[5];

    /*

        Extern variables

        - Extern variables are very similar to global variables
        - 

   */

    extern int g;
    extern float h[5];

}