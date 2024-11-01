#include "includes.h"

/**
 * @brief создаем файл и НЕ закрываем его
 */
void create_file(int argc, char* argv[])
{
    // проверяем передано ли достаточное кол-во аргументов
    if(argc < 2){printf("Error add new target file! : %s\n", strerror(errno)); exit(EXIT_FAILURE);}
    else{printf("file created!\n");}

    // открываем файл
    if((file_fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0){printf("Error, cant create file! : %s\n", strerror(errno)); exit(EXIT_FAILURE); }    
    else{printf("file opened!\n");}
}


/**
 * @brief блокируем файл, записываем в него данные и разблокируем
 */
void write_data(char* argv[])
{
    //настраиваем структуру блокировки
    struct flock lock;
    memset(&lock, 0, sizeof(lock));
    lock.l_type = F_WRLCK;
    printf("lock.l_type = %d\n", lock.l_type);
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    // выполняем блокировку 
    if((fcntl(file_fd, F_SETLK, &lock)) < 0){printf("Error, cant lock file! : %s\n", strerror(errno)); exit(EXIT_FAILURE);} 
    else{printf("file locked!\n");}

    // выполняем запись в файл
    ssize_t bytes_written = write(file_fd, text, strlen(text));
    // выполняем проверку
    if(bytes_written < 0){printf("Error write text to file! : %s\n", strerror(errno)); close(file_fd); exit(EXIT_FAILURE);}
    else{printf("text written to file!\n");}

    // разблокировака файла
    lock.l_type = F_UNLCK;
    printf("lock.l_type = %d\n", lock.l_type);
    if((fcntl(file_fd, F_SETLK, &lock)) < 0){printf("Error, cant unlock file! : %s\n", strerror(errno)); close(file_fd); exit(EXIT_FAILURE);}
    else{printf("file unlocked!\n");}
}
