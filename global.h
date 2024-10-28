#ifndef GLOBAL_H
#define GLOBAL_H

#include "sys/types.h"
//#include "includes.h"

#define MAIN_BUFF_SIZE 1024

extern int file_fd;   // дескриптор файла

extern int open_flags_create;  // флаги разрешения при открытии
extern mode_t file_perms;    // права доступа
extern char buff[MAIN_BUFF_SIZE];    // главный буффер для чтения
extern ssize_t num_read;

// текст для записи в первый файл
extern const char* text_for_write;
// текст для записи в потоке
extern const char* text_for_inline;

// структура блокировки файла
extern struct flock lock; 

extern struct flock lock;   // структура блокировки

#endif // GLOBAL_H
