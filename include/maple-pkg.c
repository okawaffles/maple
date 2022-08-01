#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <maple-pkg.h>
#include <maple-log.h>

#define THIS_PROCESS "maple-pkg"
#define DEFAULT_CHAR_SIZE 256

void preparePackage(char *name, char *pkg, int debug)
{
    if (!pkg)
    {
        info(THIS_PROCESS, "Making new directory with no template.");
        if (debug == 1)
            dbg(THIS_PROCESS, "strcat & mkdir...");
        char cmds[DEFAULT_CHAR_SIZE];
        memset(cmds, 0, DEFAULT_CHAR_SIZE);
        strcat(cmds, "mkdir ");
        strcat(cmds, name);
        system(cmds);
        if (debug == 1)
            dbg(THIS_PROCESS, "flush...");
        memset(cmds, 0, DEFAULT_CHAR_SIZE);
        if (debug == 1)
            dbg(THIS_PROCESS, "set up directory and file chars...");
        char path[DEFAULT_CHAR_SIZE];
        memset(path, 0, DEFAULT_CHAR_SIZE);
        strcat(path, "./");
        strcat(path, name);
        char cfgpath[DEFAULT_CHAR_SIZE];
        memset(cfgpath, 0, DEFAULT_CHAR_SIZE);
        strcpy(cfgpath, path);
        strcat(cfgpath, "/maple.cfg");
        char config[DEFAULT_CHAR_SIZE];
        memset(config, 0, DEFAULT_CHAR_SIZE);
        strcpy(config, name);
        strcat(config, ",0");
        if (debug == 1)
            dbg(THIS_PROCESS, "writing cfg file...");
        FILE *cfg = NULL;
        cfg = fopen(cfgpath, "w");
        if (cfg)
        {
            fprintf(cfg, "%s", config);
            fclose(cfg);
        }
    }
    else
    {
        info(THIS_PROCESS, "Making new directory with no template.");
        if (debug == 1)
            dbg(THIS_PROCESS, "strcat & mkdir...");
        char cmds[DEFAULT_CHAR_SIZE];
        memset(cmds, 0, DEFAULT_CHAR_SIZE);
        strcat(cmds, "mkdir ");
        strcat(cmds, name);
        system(cmds);
        if (debug == 1)
            dbg(THIS_PROCESS, "flush...");
        memset(cmds, 0, DEFAULT_CHAR_SIZE);
        if (debug == 1)
            dbg(THIS_PROCESS, "set up directory and file chars...");
        char path[DEFAULT_CHAR_SIZE];
        memset(path, 0, DEFAULT_CHAR_SIZE);
        strcat(path, "./");
        strcat(path, name);
        char cfgpath[DEFAULT_CHAR_SIZE];
        memset(cfgpath, 0, DEFAULT_CHAR_SIZE);
        strcpy(cfgpath, path);
        strcat(cfgpath, "/maple.cfg");
        char config[DEFAULT_CHAR_SIZE];
        memset(config, 0, DEFAULT_CHAR_SIZE);
        strcpy(config, name);
        strcat(config, ",0");
        if (debug == 1)
            dbg(THIS_PROCESS, "writing cfg file...");
        FILE *cfg = NULL;
        cfg = fopen(cfgpath, "w");
        if (cfg)
        {
            fprintf(cfg, "%s", config);
            fclose(cfg);
        }

        info(THIS_PROCESS, "Downloading package...");
        char pkgu[DEFAULT_CHAR_SIZE];
        memset(pkgu, 0, DEFAULT_CHAR_SIZE);
        strcat(pkgu, "wget -O maplepkg.tar.gz http://192.168.1.42:5555/s?p=");
        strcat(pkgu, pkg);
        system(pkgu);
        memset(path, 0, DEFAULT_CHAR_SIZE);
        strcat(path, "tar -xvzf maplepkg.tar.gz -C ./");
        strcat(path, name);
        system(path);
        info(THIS_PROCESS, "Finishing up...");
        remove("maplepkg.tar.gz");
    }
}

void buildPackage(char *name, int debug)
{
    char pathToIc[DEFAULT_CHAR_SIZE];
    memset(pathToIc, 0, DEFAULT_CHAR_SIZE);
    strcat(pathToIc, "./");
    strcat(pathToIc, name);
    strcat(pathToIc, "/maple_build.cfg");

    FILE *ic = NULL;
    ic = fopen(pathToIc, "r");

    if (ic) // checks if package can be built
    {
        info(THIS_PROCESS, "Building package...");

        char line[256];
        while (fgets(line, sizeof(line), ic))
        {
            system(line);
        }

        fclose(ic);
    }
    else
    {
        err(THIS_PROCESS, "Either package failed, doesn't exist, or there is no build config.");
    }
}

int maplepkg(int action, char *name, char *pkg, int debug)
{
    switch (action)
    {
    case 1: // remember to add checks later!
        preparePackage(name, pkg, debug);
        break;
    case 2:
        //preparePackage(pkg, pkg, debug);
        buildPackage(pkg, debug);
        break;
    }
    return 0;
}