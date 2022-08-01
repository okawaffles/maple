#include <maple-dl.h>
#include <maple-log.h>

#include <string.h>
#include <stdlib.h>

#define THIS_PROCESS "maple-dl"

void maple_dl_okayu(char *user, char *file)
{
    info(THIS_PROCESS, "Downloading file from OkayuCDN...");

    char cmd[256];
    memset(cmd, 0, 256);
    strcat(cmd, "wget https://okayu.okawaffles.com/content/");
    strcat(cmd, user);
    strcat(cmd, "/");
    strcat(cmd, file);

    if (system(cmd) == 0)
    {
        info(THIS_PROCESS, "Finished!");
    }
    else
    {
        err(THIS_PROCESS, "Failed to download file.");
    }
}

void maple_dl(char *url)
{
    info(THIS_PROCESS, "Downloading file...");

    char cmd[256];
    memset(cmd, 0, 256);
    strcat(cmd, "wget ");
    strcat(cmd, url);

    if (system(cmd) == 0)
    {
        info(THIS_PROCESS, "Finished!");
    }
    else
    {
        err(THIS_PROCESS, "Failed to download file.");
    }
}