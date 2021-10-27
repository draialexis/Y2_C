#include <stdio.h>
#include <stdlib.h>

typedef char *str;

#include "toolbox.h"
#include "tp3ex1.h"

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        str f_name = argv[1];
        str clip = argv[2];
        wri2k(f_name, clip);
    }
    return 0;
}