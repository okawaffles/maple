#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#include <maple-pkg.h>

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

int main(int argc, char *argv[])
{
    info("maple", "Welcome to MapleTools");
    bool success = true;

    if (argv[1])
    {
        if(!strcmp(argv[1], "dl"))
        {
            if(argv[2] && argv[3])
            {
                info("maple-dl", "Downloading file from OkayuCDN...");

                char cmd[256];
                memset(cmd, 0, 256);
                strcat(cmd, "wget https://okayu.okawaffles.com/content/");
                strcat(cmd, argv[2]);
                strcat(cmd, "/");
                strcat(cmd, argv[3]);

                if(system(cmd) == 0)
                {
                    info("maple-dl", "Finished!");
                }
                else
                {
                    err("maple-dl", "Failed to download file.");
                    success = false;
                }
            }
            else
            {
                err("maple-dl", "No user/file provided.");
                success = false;
            }
        }
        else if (!strcmp(argv[1], "new"))
        {
            maplepkg(1, argv[2], argv[3], 1);
        }
        else
        {
            err("maple", "Unrecognized action.");
            success = false;
        }
    }
    else
    {
        err("maple", "No action provided, stop.");
        success = false;
    }

    if (success) return 0; else return -1;
}