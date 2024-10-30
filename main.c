#include "includes.h"


int main(int argc, char* argv[])
{
    create_file_and_write(argc, argv);
    lock_unlock_file(argc, argv);
    close(file_fd);
}
