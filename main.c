#include "includes.h"


int main(int argc, char* argv[])
{
    // создаем и открываем файл
    create_file(argc, argv);

    // записываем в файл
    write_data(argv);

    // закрываем файл
    return EXIT_SUCCESS;
}
