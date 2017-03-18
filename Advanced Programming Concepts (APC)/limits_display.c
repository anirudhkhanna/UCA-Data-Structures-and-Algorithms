#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

    printf("CHAR_BIT      :   %d\n", CHAR_BIT);
    printf("CHAR_MAX      :   %d\n", CHAR_MAX);
    printf("CHAR_MIN      :   %d\n", CHAR_MIN);
    printf("\n");
    printf("INT_MAX       :   %d\n", INT_MAX);
    printf("INT_MIN       :   %d\n", INT_MIN);
    printf("\n");
    printf("SHRT_MAX      :   %d\n", SHRT_MAX);
    printf("SHRT_MIN      :   %d\n", SHRT_MIN);
    printf("\n");
    printf("LONG_MAX      :   %ld\n", (long) LONG_MAX);
    printf("LONG_MIN      :   %ld\n", (long) LONG_MIN);
    printf("\n");
    printf("LLONG_MAX     :   %lld\n", (long long) LLONG_MAX);    // Implementation dependent
    printf("LLONG_MIN     :   %lld\n", (long long) LLONG_MIN);    // Implementation dependent
    printf("\n");
    printf("SCHAR_MAX     :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN     :   %d\n", SCHAR_MIN);
    printf("\n");
    printf("UCHAR_MAX     :   %d\n", UCHAR_MAX);
    printf("UINT_MAX      :   %u\n", (unsigned int) UINT_MAX);
    printf("ULONG_MAX     :   %lu\n", (unsigned long) ULONG_MAX);
    printf("USHRT_MAX     :   %d\n", (unsigned short) USHRT_MAX);
    printf("\n");
    printf("FLT_MAX       :   %g\n", (float) FLT_MAX);
    printf("FLT_MIN       :   %g\n", (float) FLT_MIN);
    printf("-FLT_MAX      :   %g\n", (float) -FLT_MAX);
    printf("-FLT_MIN      :   %g\n", (float) -FLT_MIN);
    printf("\n");
    printf("DBL_MAX       :   %g\n", (double) DBL_MAX);
    printf("DBL_MIN       :   %g\n", (double) DBL_MIN);
    printf("-DBL_MAX      :   %g\n", (double) -DBL_MAX);
    printf("-DBL_MIN      :   %g\n", (double) -DBL_MIN);

    return 0;
}

/* OUTPUT:

CHAR_BIT      :   8
CHAR_MAX      :   127
CHAR_MIN      :   -128

INT_MAX       :   2147483647
INT_MIN       :   -2147483648

SHRT_MAX      :   32767
SHRT_MIN      :   -32768

LONG_MAX      :   2147483647
LONG_MIN      :   -2147483648

LLONG_MAX     :   9223372036854775807
LLONG_MIN     :   -9223372036854775808

SCHAR_MAX     :   127
SCHAR_MIN     :   -128

UCHAR_MAX     :   255
UINT_MAX      :   4294967295
ULONG_MAX     :   4294967295
USHRT_MAX     :   65535

FLT_MAX       :   3.40282e+38
FLT_MIN       :   1.17549e-38
-FLT_MAX      :   -3.40282e+38
-FLT_MIN      :   -1.17549e-38

DBL_MAX       :   1.79769e+308
DBL_MIN       :   2.22507e-308
-DBL_MAX      :   -1.79769e+308
-DBL_MIN      :   -2.22507e-308

*/