#include <stdio.h>
#include "ace.h"

AceModule* pModule;

extern "C" __declspec(dllexport) __declspec(noinline) void fuzzme(char* lpFileName)
{
    printf("%s\n", lpFileName);

    pModule->Load();

}

int main(int argc, char** argv)
{
    fuzzme(argv[1]);
    return 0;
}
