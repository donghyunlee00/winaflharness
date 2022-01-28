#pragma once
#include "ace.h"

int OnInitialize(StartupInfo* pInfo);
int OnFinalize();
int OnQueryArchive(QueryArchiveStruct* pQAS);
int OnOpenCreateArchive(OpenCreateArchiveStruct* pOAS);
int OnCloseArchive(CloseArchiveStruct* pCAS);
int OnStartOperation(OperationStruct* pOS);
int OnEndOperation(OperationStruct* pOS);
int OnGetArchiveModuleInfo(ArchiveModuleInfo* ai);
int OnGetArchiveItem(GetArchiveItemStruct* pGAI);
bool OnFreeArchiveItem(FreeArchiveItemStruct* pFAI);
int OnExtract(ExtractStruct* pES);
int OnGetDefaultCommand(GetDefaultCommandStruct* pGDC);
int OnAdd(AddStruct* pAS);
int OnDelete(DeleteStruct* pDS);
