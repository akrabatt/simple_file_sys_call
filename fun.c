#include "includes.h"

/**
 * @brief создаем файл и записываем в него стартовую фразу
 */
void create_file_and_write(int argc, char* argv[])
{
    // проверяем введены ли 1 файл
    if(argc != 2){printf("Usage: %s old-file new-file \n", argv[0]); exit(EXIT_FAILURE);}

    // открываем файл создавая его и берем его дескриптор
    if((file_fd = open(argv[1], open_flags_create, file_perms)) < 0){printf("Error create and opening %s\n", argv[1]); exit(EXIT_FAILURE);}
    
    // записываем строки в файл
    if(write(file_fd, text_for_write, strlen(text_for_write)) < 0){printf("Error write data to file %s\n", argv[1]); close(file_fd); exit(EXIT_FAILURE);}
    // закрываем файл
    close(file_fd);
}


/**
 * @brief функция по блокировки/разблокировки файла
 */
void lock_unlock_file(int argc, char* argv[])
{
    char choice;
    printf("\nWhat needs to be done with the file?\n1 - lock file\n2 - unlock file\n...: ");
}

