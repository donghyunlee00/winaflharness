#include <stdio.h>
#include "Ace.class.h"

AceModule* pModule;

extern "C" __declspec(dllexport) __declspec(noinline) void fuzzme(char* lpFileName)
{
    // printf("%s\n", lpFileName);

    AceArchive* pArchive = new AceArchive(pModule, lpFileName, false);

    if (pArchive && pArchive->IsArchive())
    {
        printf("NAERROR_SUCCESS\n");
    }
}

int main(int argc, char** argv)
{
    SetDllDirectoryA("C:\\Program Files (x86)\\WinRAR\\Formats\\");

    pModule = new AceModule;

    fuzzme(argv[1]);
    return 0;
}
