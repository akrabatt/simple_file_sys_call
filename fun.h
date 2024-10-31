#ifndef FUN_H
#define FUN_H

void check_arguments(int argc, char* argv[]);

int open_file(const char* filename);

int lock_file(int file_fd);

int write_to_file(int file_fd, const char* text);

int unlock_file(int file_fd);

void close_file(int file_fd);

#endif // FUN_H
