#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include "win.h"
#pragma comment(lib, "user32.lib")
#define BUF_SIZE 8
#define my_turn 1
TCHAR szName[]=TEXT("Global\\MyFileMappingObject");
#define chess 'O'
int galoop()
{
   HANDLE hMapFile;
   LPTSTR pBuf;
   char c;
   

   hMapFile = OpenFileMapping(
                   FILE_MAP_ALL_ACCESS,   // read/write access
                   FALSE,                 // do not inherit the name
                   szName);               // name of mapping object

   if (hMapFile == NULL)
   {
      _tprintf(TEXT("Could not open file mapping object (%d).\n"),
             GetLastError());
      return 1;
   }

   pBuf = (LPTSTR) MapViewOfFile(hMapFile, // handle to map object
               FILE_MAP_ALL_ACCESS,  // read/write permission
               0,
               0,
               BUF_SIZE);
	

   if (pBuf == NULL )
   {
      _tprintf(TEXT("Could not map view of file (%d).\n"),
             GetLastError());

      CloseHandle(hMapFile);

      return 1;
   }
  
	set_OK(pBuf);
	while(1){
	board(pBuf);
	}
	sleep(30);
  /*
	while(1){
	
   if(pBuf[6]== 1){
	   printf("\n receive data %d & reply ack...\n",pBuf[0]);
	   pBuf[7] = 1;
	   
   
   }
   if(pBuf[7]==2)
	   break;
   printf("\r wait data ...");
   sleep(5);
}
*/
   UnmapViewOfFile(pBuf);

   CloseHandle(hMapFile);

   return 0;
}

int set_OK(char * pBuf)
{
	printf("wait rival\n");
	pBuf[1] = 1;
	while(pBuf[1]!=1);
	printf("rival is ok\n");
}
void board(char * pBuf)
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", pBuf[board_offset], pBuf[board_offset+1],pBuf[board_offset+2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", pBuf[board_offset+3], pBuf[board_offset+4], pBuf[board_offset+5]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", pBuf[board_offset+6], pBuf[board_offset+7], pBuf[board_offset+8]);

    printf("     |     |     \n\n");
	
	if(pBuf[whosturn] == my_turn){
		if(0){
		INPUT_ERR:	
		printf("vaild input\n");
			
		}
		printf("your turn\n");
		scanf("%d",&pBuf[30]);
		switch(pBuf[30]){
			case 1:
			if(pBuf[board_offset+pBuf[30]] == 0){
				pBuf[board_offset+pBuf[30]] = chess;
			}
			else{
				goto INPUT_ERR;
			}
			break;
			case 2:
			if(pBuf[board_offset+pBuf[30]] == 0){
				pBuf[board_offset+pBuf[30]] = chess;
			}
			else{
				goto INPUT_ERR;
			}
			break;
			case 3:
			if(pBuf[board_offset+pBuf[30]] == 0){
				pBuf[board_offset+pBuf[30]] = chess;
			}
			else{
				goto INPUT_ERR;
			}
			break;
			case 4:
			if(pBuf[board_offset+pBuf[30]] == 0){
				pBuf[board_offset+pBuf[30]] = chess;
			}
			else{
				goto INPUT_ERR;
			}
			break;
			case 5:
			if(pBuf[board_offset+pBuf[30]] == 0){
				pBuf[board_offset+pBuf[30]] = chess;
			}
			else{
				goto INPUT_ERR;
			}
			break;
			case 6:
			if(pBuf[board_offset+pBuf[30]] == 0){
				pBuf[board_offset+pBuf[30]] = chess;
			}
			else{
				goto INPUT_ERR;
			}
			break;
			case 7:
			if(pBuf[board_offset+pBuf[30]] == 0){
				pBuf[board_offset+pBuf[30]] = chess;
			}
			else{
				goto INPUT_ERR;
			}
			break;
			case 8:
			if(pBuf[board_offset+pBuf[30]] == 0){
				pBuf[board_offset+pBuf[30]] = chess;
			}
			else{
				goto INPUT_ERR;
			}
			break;
			case 0:
			if(pBuf[board_offset+pBuf[30]] == 0){
				pBuf[board_offset+pBuf[30]] = chess;
			}
			else{
				goto INPUT_ERR;
			}
			break;
			default:
			break;
			
			
		}
		pBuf[whosturn]^=1;
	}
	else{
		printf("enemy turn please wait\n");
	}
	
	
}