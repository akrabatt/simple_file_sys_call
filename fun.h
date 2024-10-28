#ifndef FUN_H
#define FUN_H

/**
 * @brief создаем файл и записываем в него стартовую фразу
 */
void create_file_and_write(int argc, char* argv[]);

/**
 * @brief функция по блокировки/разблокировки файла
 */
void lock_unlock_file(int argc, char* argv[]);

/**
 * @brief функция по записи в файл
 */
void write_inline_to_file(int argc, char* argv[]);

#endif // FUN_H
