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
    // подготовка переменных
    char choice; // переменная для хранения результата ввода
    // настраиваем структуру для блокировки
    memset(&lock, 0, sizeof(lock));
    //lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    // вывод информации
    printf("\nWhat needs to be done with the created file?\n1 - lock file\n2 - unlock file\n3 - try to write inline text to file\n4 - quit\n...: ");
    // получаем информацию
    choice = getchar();

    // очищаем буффер ввода
    while(getchar() != '\n');
   
    // если пользователь просто нажмет enter 
    if(choice == '\n'){lock_unlock_file(argc, argv); return;}
    // проверяем на соответствие
    if((choice != '1') && (choice != '2') && (choice != '3') && (choice != '4'))
    {
        printf("\nInvalid value! Try again!\n"); 
        lock_unlock_file(argc, argv);
        return;
    }
    printf("your choice: %c\n", choice);

    switch(choice)
    {
        case '1':    // блокировать файл
        {
            printf("...\nlocking file for write...\n"); 
            // открываем файл в режиме записи
            if((file_fd = open(argv[1], O_WRONLY)) < 0){printf("Cant open file for write lock! : %s\n", strerror(errno)); exit(EXIT_FAILURE);} 
            
            //memset(&lock, 0, sizeof(lock));
            //lock.l_type = F_WRLCK;
            // получаем информацию о текущем состоянии структуры блокировки файла
            if(fcntl(file_fd, F_GETLK, &lock) < 0){printf("Cant get lock struct!\n"); lock_unlock_file(argc, argv); return;}

            // проверка занятости блокировки
            if((lock.l_type == 1) || (lock.l_type == 2)) 
            {
                printf("File is already locked by another process.\n");
            } else {
                lock.l_type = F_WRLCK; // Устанавливаем свою на запись
                if(fcntl(file_fd, F_SETLK, &lock) < 0) 
                {
                    printf("Error: can't set lock on file! : %s\n", strerror(errno));
                    close(file_fd);
                    exit(EXIT_FAILURE);
                }
                printf("File locked successfully\n");
            }
            close(file_fd); // Правильное закрытие файла
            lock_unlock_file(argc, argv);
            return;
        }
        case '2':
        {

        }
    }
}

