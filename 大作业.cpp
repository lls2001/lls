#include <stdio.h>					
#include <string.h>					
#include <stdlib.h>					
#include <Windows.h>    		
#include <assert.h>					
 
void gotoxy(int x, int y)
{
	COORD pos; pos.X = x - 1; pos.Y = y - 1;			
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
 
int main()
{
	system("color f0");				
	long i;								
	char FileName[100];					
	char hi[4096];					
	FILE *in;							

	system("C:\\Users\\李连舒\\Desktop\\basource.mp4");	//打开视频或音频文件，
	Sleep(3000);						
 
	//放幻灯片，Sleep()函数调节播放速度
	for (i = 1; i <= 3005; i++)	//i 的范围转换为(.txt)文件的个数
	{
		sprintf(FileName,
			"E:\\大作业\\Debug\\bascii\\ba(%1d).txt",i);

        in = fopen(FileName, "r");
		assert(in != NULL);		
		fread(hi,1,4096, in);
		printf("%s\n%d", hi, i);
		gotoxy(1, 1);			
		Sleep(26);				
		fclose(in);
	}
}