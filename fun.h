#ifndef FUN_H
#define FUN_H

/**
 * @brief создаем файл и НЕ закрываем его
 */
void create_file(int argc, char* argv[]);


/**
 * @brief блокируем файл, записываем в него данные и разблокируем
 */
void write_data(char* argv[]);

#endif // FUN_H
