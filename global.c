#include "includes.h"

#define MAIN_BUFF_SIZE 1024

int file_fd = 0;   // дескриптор файла

int open_flags_create = O_CREAT | O_WRONLY | O_TRUNC;  // флаги разрешения при открытии
mode_t file_perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;    // права доступа
char buff[MAIN_BUFF_SIZE];    // главный буффер для чтения
ssize_t num_read;

// текст для записи в первый файл
const char* text_for_write = "Hello!\nMy n@me is Dima.\nThis's text for my test programm:-)\ndon't use it in work!\nbye!\n";
// текст для записи во второй файл
const char* text_for_inline = "!!!INLINE_TEXT!!!";

// структура блокировки файлов
struct flock lock;

