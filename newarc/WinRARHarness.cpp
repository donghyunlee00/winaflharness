#include <Windows.h>
#include <iostream>
#include "Ace.class.h"

typedef int(__stdcall* ACEINITDLL) (pACEInitDllStruc DllData);
typedef int(__stdcall* ACEEXTRACT) (LPSTR ArchiveName, pACEExtractStruc Extract);
ACEINITDLL m_pfnInitDll;
ACEEXTRACT m_pfnExtract;

extern "C" __declspec(dllexport) __declspec(noinline) void fuzzme(char* lpFileName)
{
    // printf("%s\n", lpFileName);

    AceModule* pModule = new AceModule;
    AceArchive* pArchive = new AceArchive(pModule, lpFileName, false);

    if (pArchive && pArchive->IsArchive())
    {
        printf("NAERROR_SUCCESS");
    }
}

int main(int argc, char** argv)
{
    SetDllDirectoryA("C:\\Program Files (x86)\\WinRAR\\Formats\\");
    HMODULE m_hModule = LoadLibraryA("UNACEV2.DLL");
    if (m_hModule == NULL)
    {
        printf("Failed to load UNACEV2.DLL\n");
        return 1;
    }

    m_pfnInitDll = (ACEINITDLL)GetProcAddress(m_hModule, "ACEInitDll");
    if (m_pfnInitDll == NULL) {
        printf("Failed to get address for ACEInitDll\n");
        return 1;
    }

    m_pfnExtract = (ACEEXTRACT)GetProcAddress(m_hModule, "ACEExtract");
    if (m_pfnExtract == NULL) {
        printf("Failed to get address for ACEExtract\n");
        return 1;
    }

    fuzzme(argv[1]);
    return 0;
}
