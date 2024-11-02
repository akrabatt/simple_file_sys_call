#include "includes.h"

#define BUF_SIZE 1024

int file_fd = 0;
int file_fd_2 = 0;
const char* text = "Hello! programm 1\nThis is text @12345\nTest text@#$%!!!\nbye!\n";
char buf[BUF_SIZE] = {0};
ssize_t bytes_read = 0;
