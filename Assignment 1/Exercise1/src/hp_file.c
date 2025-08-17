#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf.h"
#include "hp_file.h"
#include "record.h"
#define HP_ERROR -1 
#define CALL_BF(call)       \
{                           \
  BF_ErrorCode code = call; \
  if (code != BF_OK) {         \
    BF_PrintError(code);    \
    return HP_ERROR;        \
  }                         \
}

int HP_CreateFile(char *fileName){ 
  BF_Block *block;
  HP_info *hpInfo;
  char *charblock; 
  CALL_BF(BF_Init(LRU));
  BF_Block_Init(block); // Initialize block for further use.
  CALL_BF(BF_CreateFile(fileName));
  int filedesc;
  CALL_BF(BF_OpenFile(fileName, &filedesc));
  CALL_BF(BF_AllocateBlock(filedesc, block));
  charblock = BF_Block_GetData(block);
  // INCLUDE METADATA
  memcpy(charblock, &hpInfo, sizeof(HP_info));
  BF_Block_SetDirty(block);
  CALL_BF(BF_UnpinBlock(block));
  CALL_BF(BF_CloseFile(filedesc));
}

HP_info* HP_OpenFile(char *fileName, int *file_desc){
    HP_info* hpInfo;    
    return hpInfo;
}

int HP_CloseFile(int file_desc,HP_info* hp_info ){
}

int HP_InsertEntry(int file_desc,HP_info* hp_info, Record record){
    return -1;
}

int HP_GetAllEntries(int file_desc,HP_info* hp_info, int value){    
    return -1;
}

