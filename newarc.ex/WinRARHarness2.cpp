#include <stdio.h>
#include "ace.h"

AceModule* pModule;

extern "C" __declspec(dllexport) __declspec(noinline) void fuzzme(char* lpFileName)
{
    printf("%s\n", lpFileName);
    
    pModule = new AceModule;
    pModule->Load();
    AceArchive* pArchive = pModule->OpenCreateArchive(lpFileName, NULL, NULL, false);
    pArchive->StartOperation(OPERATION_LIST, true);

    ArchiveItem* pItem = new ArchiveItem;
    memset(pItem, 0, sizeof(ArchiveItem));

    pArchive->GetArchiveItem(pItem);
    //printf("%s\n", pItem->lpFileName);
    //쓰레드 막힘?
}

int main(int argc, char** argv)
{
    fuzzme(argv[1]);
    return 0;
}
