#include <stdio.h>

extern "C" __declspec(dllexport) __declspec(noinline) void fuzzme(char* lpFileName)
{
    printf("%s\n", lpFileName);
}

int main(int argc, char** argv)
{
    fuzzme(argv[1]);
    return 0;
}
