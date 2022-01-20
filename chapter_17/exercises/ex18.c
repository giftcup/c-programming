#include <stdio.h>
#include <string.h>

#define MAX_CMD_LEN 11
#define FILE_SIZE (int)(sizeof(file_cmd)/sizeof(file_cmd[0]))

void new_cmd(void);
void open_cmd(void);
void close_cmd(void);
void close_all_cmd(void);
void save_cmd(void);
void save_as_cmd(void);
void save_all_cmd(void);
void print_cmd(void);
void exit_cmd(void);

struct
{
    char *cmd_name;
    void (*cmd_pointer)(void);
} file_cmd[] = 
    {{"new",                new_cmd},
     {"open",               open_cmd},
     {"close",              close_cmd},
     {"close all",          close_all_cmd},
     {"save",               save_cmd},
     {"save as",            save_as_cmd},
     {"save all",           save_all_cmd},
     {"print",              print_cmd},
     {"exit",               exit_cmd}
    };

int main(void) {
    char cmd[MAX_CMD_LEN];
    int i;

    printf("Enter command: ");
    fgets(cmd, sizeof(cmd), stdin);
    cmd[strlen(cmd) - 1] = '\0';
    
    for (i = 0; i < FILE_SIZE; i++) {
        if (strcmp(cmd, file_cmd[i].cmd_name) == 0) {
            file_cmd[i].cmd_pointer();
            break;
        }
    }
}

void new_cmd(void) {
    printf("new command\n");
}

void open_cmd(void) {
    printf("open command\n");
}

void close_cmd(void) {
    printf("close command\n");
}

void close_all_cmd(void) {
    printf("close all command\n");
}

void save_cmd(void) {
    printf("save command\n");
}

void save_as_cmd(void) {
    printf("save as command\n");
}

void save_all_cmd(void) {
    printf("save all command\n");
}

void print_cmd(void) {
    printf("print command\n");
}

void exit_cmd(void) {
    printf("exit command\n");
}