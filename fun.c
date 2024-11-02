#include "global.h"
#include "includes.h"

/**
 * @brief создаем файл и НЕ закрываем его
 */
void create_file(int argc, char* argv[])
{
    // проверяем передано ли достаточное кол-во аргументов
    if(argc < 3){printf("Error, need 2 files! : %s\n", strerror(errno)); exit(EXIT_FAILURE);}
    else{printf("file created!\n");}

    // открываем файл исходный
    if((file_fd = open(argv[1], O_WRONLY, 0666)) < 0){printf("Error, cant open file! : %s\n", strerror(errno)); exit(EXIT_FAILURE); }    
    else{printf("file opened!\n");}

    // создаем второй файл
    if((file_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0){printf("Error, cant create file! : %s\n", strerror(errno)); exit(EXIT_FAILURE); }    
    else{printf("file opened!\n");}

}


/**
 * @brief блокируем файл, записываем в него данные и разблокируем
 */
void write_data()
{
    //настраиваем структуру блокировки
    struct flock lock;
    memset(&lock, 0, sizeof(lock));
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    // выполняем блокировку исходного файла
    if((fcntl(file_fd, F_SETLK, &lock)) < 0){printf("Error, cant lock 1th file! : %s\n", strerror(errno)); exit(EXIT_FAILURE);} 
    else{printf("file locked!\n");}

    // выполняем блокировку нового файла
    if((fcntl(file_fd_2, F_SETLK, &lock)) < 0){printf("Error, cant lock 2th file! : %s\n", strerror(errno)); exit(EXIT_FAILURE);} 
    else{printf("file locked!\n");}

    // выполняем чтение из файла
    bytes_read = read(file_fd, buf, sizeof(buf));
    if(bytes_read < 0){printf("Error, read 1th file : %s\n", strerror(errno) - 1);}

    // выполняем запись в файл
    // ssize_t bytes_written = write(file_fd, text, strlen(text));
    // выполняем проверку
    // if(bytes_written < 0){printf("Error write text to file! : %s\n", strerror(errno)); close(file_fd); exit(EXIT_FAILURE);}
    // else{printf("text written to file!\n");}

    // разблокировака первого файла
    lock.l_type = F_UNLCK;
    if((fcntl(file_fd, F_SETLK, &lock)) < 0){printf("Error, cant unlock 1th file! : %s\n", strerror(errno)); close(file_fd); exit(EXIT_FAILURE);}
    else{printf("file unlocked!\n");}

    // разблокировка второго файла
    if((fcntl(file_fd_2, F_SETLK, &lock)) < 0){printf("Error, cant unlock 2th file! : %s\n", strerror(errno)); close(file_fd); exit(EXIT_FAILURE);}
    else{printf("file unlocked!\n");}


    // закрытие файлов
    close(file_fd);
    close(file_fd_2);

    printf("lock.l_type = %d\n", lock.l_type);
}
