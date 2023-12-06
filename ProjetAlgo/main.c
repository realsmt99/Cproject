#include <stdio.h>
#include <stdlib.h>
#include "BST.c"
#include <string.h>

int main()
{

    COArbreR r;
    InitCourse(&r);
    parse_courses_csv("courses.csv", &r);
    InOrdre_course(r);
    printf("\n");

    return 0;
}
