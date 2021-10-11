/*
Developed by Hyper Lab Inc.
Hyper Disk Operating System 1

Desc: Hyper Lab's DOS System
*/

//header
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

int build=21;

//main kernal
int main(void){
    char command[1024];
    char keyinput;
    int *memory;
    int mallocbyte;
    //intro booting
    printf("Hyper Disk Operating System 1\nBooting...");
    while (1){
        printf("\n(Enter HELP to see commands) Enter the Command...\n>");
        gets(command);
        printf("\n");
        if ((!(strcmp(command, "INFO"))) || (!(strcmp(command, "OPEN INFO.EXE"))))
        {
            printf("OS: Hyper Disk Operating System\nVersion:1.%d\nBuild:%d\n\nMade By Hyper Lab Inc. 2021", build, build);
        }
        else if ((!(strcmp(command, "BUILD"))) || (!(strcmp(command, "OPEN BUILD.EXE"))))
        {
            printf("Build:%d\n\n", build);
        }
        else if ((!(strcmp(command, "SHUTDOWN"))) || (!(strcmp(command, "OPEN SHUTDOWN.EXE"))))
        {
            printf("PC has been shut downed. Press Enter to reboot. Press Enter+C to shut down.\n");
            scanf("%c", &keyinput);
            if (keyinput=='c'){printf("PC has been shut downed."); free(memory); return 0;} else{printf("PC has been rebooted.");}
        }
        else if ((!(strcmp(command, "MALLOC"))) || (!(strcmp(command, "OPEN MALLOC.EXE"))))
        {
            printf("Please Enter the Byte of Memory to allocate.\n>");
            scanf("%d", &mallocbyte);
            memory=malloc(mallocbyte);
            if (memory!=NULL){
                printf("Successfully to allocate %d byte(s) at %p.\n", mallocbyte, memory);
            }
            else{printf("Failed to allocate memory.");}
        }
        else if ((!(strcmp(command, "FREEMEM"))) || (!(strcmp(command, "OPEN FREEMEM.EXE")))){
            free(memory);
            printf("Successful to disable %d byte(s) of memory.\n", mallocbyte);
        }
        else if ((!(strcmp(command, "TBETA"))) || (!(strcmp(command, "OPEN TBETA.EXE")))){
            printf("Visit https://github.com/lucas7234/hyperdos to download latest RTM build of Hyper DOS 1 and feedback for us.\n");
        }
        else if ((!(strcmp(command, "HELP"))) || (!(strcmp(command, "OPEN HELP.EXE")))){
            printf("\nEnter 'Command' or 'OPEN Command.EXE' to run the command.\nINFO-See the info of HDOS1 such as build or credit.\nSHUTDOWN-Shut down or Reboot PC.\nMALLOC-Allocate memory for PC.\nFREEMEM - Direct disable memory.\nTBETA-Give Infos for HDOS1 Beta Testing.\nHELP-Give Infos about HDOS1 commands.");
        }

    }
}
