#include "includes.h"

void check_arguments(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
}


int open_file(const char* filename)
{

}
