#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int integer_variable;
    float float_variable;
    double double_variable;
    integer_variable = INT_MAX;
    float_variable = FLT_MAX;
    double_variable = DBL_MAX;
    printf("%d %lu\n", integer_variable, sizeof(integer_variable));
    printf("%f %lu\n", float_variable, sizeof(float_variable));
    printf("%lf %lu\n", double_variable, sizeof(double_variable));
    return 0;
}
