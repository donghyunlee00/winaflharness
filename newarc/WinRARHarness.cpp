#include <stdio.h>
#include "ace.class.h"

AceModule* pModule;

extern "C" __declspec(dllexport) __declspec(noinline) void fuzzme(char* lpFileName)
{
    AceArchive* pArchive = new AceArchive(pModule, lpFileName, false);

    if (pArchive && pArchive->IsArchive())
    {
        printf("%s\n", pArchive->m_lpFileName);
    }

    pArchive->pOpenArchive(OM_LIST, NULL);

    ArchiveItemInfo* pItem = new ArchiveItemInfo;
    memset(pItem, 0, sizeof(ArchiveItemInfo));
    pArchive->pGetArchiveItem(pItem);

    //printf("%d\n", pItem->dwFlags);
    //printf("%s\n", pItem->pi.FindData.cFileName);
    //쓰레드 막힘?
}

int main(int argc, char** argv)
{
    SetDllDirectoryA("C:\\Program Files (x86)\\WinRAR\\Formats\\");

    pModule = new AceModule;

    fuzzme(argv[1]);
    return 0;
}
