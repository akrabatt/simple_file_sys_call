#include "includes.h"


int main(int argc, char* argv[])
{
    // создаем и открываем файл
    create_file(argc, argv);

    // записываем в файл
    write_data(argv);

    // закрываем файл
    if((close(file_fd)) < 0){printf("error close file!\n");}
    else{printf("file closed!\n");}
    return EXIT_SUCCESS;
}
