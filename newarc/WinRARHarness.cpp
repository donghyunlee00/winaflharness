#include <stdio.h>
#include "lib.part/Rtl.Base.h"
#include "ace.class.h"

AceModule* pModule;

extern "C" __declspec(dllexport) __declspec(noinline) void fuzzme(char* lpFileName)
{
    AceArchive* pArchive = new AceArchive(pModule, lpFileName, false);

    if (pArchive && pArchive->IsArchive())
    {
        printf("%s\n", pArchive->m_lpFileName);
    }

    ArchiveItemInfo* pItem = new ArchiveItemInfo;
    memset(pItem, 0, sizeof(ArchiveItemInfo));

    if(pArchive->pOpenArchive(OM_LIST, NULL))
    {
        int nResult = pArchive->pGetArchiveItem(pItem);
        printf("nResult: %d / %s\n", nResult, pItem->pi.FindData.cFileName);

        pArchive->pCloseArchive();
    }

    if (pArchive->pOpenArchive(OM_EXTRACT, NULL))
    {
        char *lpCurrentPath = StrDuplicate(pItem->pi.FindData.cFileName);
        CutToSlash(lpCurrentPath);

        int bResult = pArchive->pExtract(
            &pItem->pi,
            1,
            "C:\\Users\\user\\Desktop\\output_folders\\",
            lpCurrentPath
        );
        printf("bResult: %d\n", bResult);

        pArchive->pCloseArchive();
    }

    delete pArchive;
}

int main(int argc, char** argv)
{
    SetDllDirectoryA("C:\\Program Files (x86)\\WinRAR\\Formats\\");

    pModule = new AceModule;

    fuzzme(argv[1]);
    return 0;
}
