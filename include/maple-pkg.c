#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <maple-pkg.h>


void preparePackage(char *name, char *pkg, int debug)
{
    if (!pkg)
    {
        printf("(maple-pkg) INFO :: Making new project with no template.\n");
        if (debug == 1) printf("(maple-pkg) DBG  :: strcat & mkdir...\n");
        char cmds[256];
        memset(cmds, 0, 256);
        strcat(cmds, "mkdir ");
        strcat(cmds, name);
        system(cmds);
        if (debug == 1) printf("(maple-pkg) DBG  :: flush\n");
        memset(cmds, 0, 256);
        if (debug == 1) printf("(maple-pkg) DBG  :: set up directory and file chars\n");
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
        if (debug == 1) printf("(maple-pkg) DBG  :: write cfg file\n");
        FILE *cfg = NULL;
        cfg = fopen(cfgpath, "w");
        if(cfg) {
            fprintf(cfg, config);
            fclose(cfg);
        }
    }
    else
    {
        printf("(maple-pkg) INFO :: Making new project with a template.\n");
        if (debug == 1) printf("(maple-pkg) DBG  :: strcat & mkdir...\n");
        char cmds[256];
        memset(cmds, 0, 256);
        strcat(cmds, "mkdir ");
        strcat(cmds, name);
        system(cmds);
        if (debug == 1) printf("(maple-pkg) DBG  :: flush\n");
        memset(cmds, 0, 256);
        if (debug == 1) printf("(maple-pkg) DBG  :: set up directory and file chars\n");
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
        if (debug == 1) printf("(maple-pkg) DBG  :: write cfg file\n");
        FILE *cfg = NULL;
        cfg = fopen(cfgpath, "w");
        if(cfg) {
            fprintf(cfg, config);
            fclose(cfg);
        }

        printf("(maple-pkg) INFO :: Downloading package...\n");
        char pkgu[256];
        memset(pkgu, 0, 256);
        strcat(pkgu, "wget -O maplepkg.tar.gz http://192.168.1.42:5555/s?p=");
        strcat(pkgu, pkg);
        system(pkgu);
        memset(path, 0, 256);
        strcat(path, "tar -xvzf maplepkg.tar.gz -C ./");
        strcat(path, name);
        system(path);
        printf("(maple-pkg) INFO :: Finishing up...\n");
        remove("maplepkg.tar.gz");
    }
}



int maplepkg(int action, char *name, char *pkg, int debug)
{
    switch (action)
    {
        case 1:
            preparePackage(name, pkg, debug);
            break;
    }
    return 0;
}