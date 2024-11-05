#include "includes.h"

int file_fd = 0;
int file_fd_2 = 0;
const char* text = "Hello! programm 1\nThis is text @12345\nTest text@#$%!!!\nbye!\n";
char buf[1024] = {0};
ssize_t bytes_read = 0;
