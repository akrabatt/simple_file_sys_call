#ifndef GLOBAL_H
#define GLOBAL_H

extern int file_fd;   // дескриптор файла

extern int open_flags_create;  // флаги разрешения при открытии
extern mode_t file_perms;    // права доступа
extern char buff[MAIN_BUFF_SIZE];    // главный буффер для чтения
extern ssize_t num_read;

// текст для записи в первый файл
const char* text_for_write;
// текст для записи в потоке
const char* text_for_inline;

// структура блокировки файла
struct flock lock; 

extern struct flock lock;   // структура блокировки

#endif // GLOBAL_H
