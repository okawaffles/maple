#include <maple-log.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void info(char *proc, char *msg)
{
    char tmp[256];
    strcat(tmp, "(");
    strcat(tmp, proc);
    strcat(tmp, ") INFO :: ");
    strcat(tmp, msg);
    printf("%s\n", tmp);
    memset(tmp, 0, 256);
}
void err(char *proc, char *msg)
{
    char tmp[256];
    strcat(tmp, "(");
    strcat(tmp, proc);
    strcat(tmp, ") ERR  :: ");
    strcat(tmp, msg);
    printf("%s\n", tmp);
    memset(tmp, 0, 256);
}
void dbg(char *proc, char *msg)
{
    char tmp[256];
    strcat(tmp, "(");
    strcat(tmp, proc);
    strcat(tmp, ") DBG  :: ");
    strcat(tmp, msg);
    printf("%s\n", tmp);
    memset(tmp, 0, 256);
}