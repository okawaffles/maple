#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <maple-pkg.h>
#include <maple-log.h>

#define THIS_PROCESS "maple-pkg"

void preparePackage(char *name, char *pkg, int debug)
{
    if (!pkg)
    {
        info(THIS_PROCESS, "Making new project with no template.");
        if (debug == 1) dbg(THIS_PROCESS, "strcat & mkdir...");
        char cmds[256];
        memset(cmds, 0, 256);
        strcat(cmds, "mkdir ");
        strcat(cmds, name);
        system(cmds);
        if (debug == 1) dbg(THIS_PROCESS, "flush...");
        memset(cmds, 0, 256);
        if (debug == 1) dbg(THIS_PROCESS, "set up directory and file chars...");
        char path[256];
        memset(path, 0, 256);
        strcat(path, "./");
        strcat(path, name);
        char cfgpath[256];
        memset(cfgpath, 0, 256);
        strcpy(cfgpath, path);
        strcat(cfgpath, "/maple.cfg");
        char config[256];
        memset(config, 0, 256);
        strcpy(config, name);
        strcat(config, ",0");
        if (debug == 1) dbg(THIS_PROCESS, "writing cfg file...");
        FILE *cfg = NULL;
        cfg = fopen(cfgpath, "w");
        if(cfg) {
            fprintf(cfg, "%s", config);
            fclose(cfg);
        }
    }
    else
    {
        info(THIS_PROCESS, "Making new project with no template.");
        if (debug == 1) dbg(THIS_PROCESS, "strcat & mkdir...");
        char cmds[256];
        memset(cmds, 0, 256);
        strcat(cmds, "mkdir ");
        strcat(cmds, name);
        system(cmds);
        if (debug == 1) dbg(THIS_PROCESS, "flush...");
        memset(cmds, 0, 256);
        if (debug == 1) dbg(THIS_PROCESS, "set up directory and file chars...");
        char path[256];
        memset(path, 0, 256);
        strcat(path, "./");
        strcat(path, name);
        char cfgpath[256];
        memset(cfgpath, 0, 256);
        strcpy(cfgpath, path);
        strcat(cfgpath, "/maple.cfg");
        char config[256];
        memset(config, 0, 256);
        strcpy(config, name);
        strcat(config, ",0");
        if (debug == 1) dbg(THIS_PROCESS, "writing cfg file...");
        FILE *cfg = NULL;
        cfg = fopen(cfgpath, "w");
        if(cfg) {
            fprintf(cfg, "%s", config);
            fclose(cfg);
        }

        info(THIS_PROCESS, "Downloading package...");
        char pkgu[256];
        memset(pkgu, 0, 256);
        strcat(pkgu, "wget -O maplepkg.tar.gz http://192.168.1.42:5555/s?p=");
        strcat(pkgu, pkg);
        system(pkgu);
        memset(path, 0, 256);
        strcat(path, "tar -xvzf maplepkg.tar.gz -C ./");
        strcat(path, name);
        system(path);
        info(THIS_PROCESS, "Finishing up...");
        remove("maplepkg.tar.gz");
    }
}

void installPackage(char *name, int debug)
{
    // tbf
}



int maplepkg(int action, char *name, char *pkg, int debug)
{
    switch (action)
    {
        case 1:
            preparePackage(name, pkg, debug);
            break;
        case 2:
            preparePackage(name, pkg, debug);
            installPackage(name, debug);
            break;
    }
    return 0;
}