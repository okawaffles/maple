#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <maple-pkg.h>
#include <maple-log.h>
#include <maple-dl.h>

#define THIS_PROCESS "maple"

int main(int argc, char *argv[])
{
    info("maple", "Welcome to Maple");
    bool success = true;

    if (argv[1])
    {
        if(!strcmp(argv[1], "dl"))
        {
            if(argv[2])
            {
                maple_dl(argv[2]);
            }
            else
            {
                err(THIS_PROCESS, "No URL provided.");
                success = false;
            }
        }
        else if (!strcmp(argv[1], "new"))
        {
            maplepkg(1, argv[2], argv[3], 0);
        }
        else if (!strcmp(argv[1], "build"))
        {
            maplepkg(2, argv[2], argv[2], 0);
        }
        else
        {
            err(THIS_PROCESS, "Unrecognized action.");
            success = false;
        }
    }
    else
    {
        err(THIS_PROCESS, "No action provided, stop.");
        success = false;
    }

    if (success) return 0; else return -1;
}