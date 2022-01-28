#include <iostream>
#include "ace.h"

AceModule* pModule;

extern "C" __declspec(dllexport) __declspec(noinline) void fuzzme(char* lpFileName)
{
    printf("%s\n", lpFileName);
    
    pModule = new AceModule;
    pModule->Load();
    AceArchive* pArchive{};
    pArchive = pModule->OpenCreateArchive(lpFileName, NULL, NULL, false);

    ArchiveItem* pItem = new ArchiveItem;
    memset(pItem, 0, sizeof(ArchiveItem));

    if (pArchive->StartOperation(OPERATION_LIST, true))
    {
        pArchive->GetArchiveItem(pItem);
        printf("%s\n", pItem->lpFileName);

        pArchive->EndOperation(OPERATION_LIST, true);
    }

    if (pArchive->StartOperation(OPERATION_EXTRACT, true))
    {
        string lpCurrentPath = pItem->lpFileName;
        CutToSlash(lpCurrentPath);

        pArchive->Extract(
            pItem,
            1,
            "C:\\Users\\user\\Desktop\\output_folders\\",
            lpCurrentPath
        );

        pArchive->EndOperation(OPERATION_EXTRACT, true);
    }

    pArchive->FreeArchiveItem(pItem);
    pModule->CloseArchive(pArchive);
    delete pModule;
}

int main(int argc, char** argv)
{
    SetDllDirectoryA("C:\\Program Files (x86)\\WinRAR\\Formats\\");

    fuzzme(argv[1]);
    return 0;
}
