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

	system("C:\\Users\\������\\Desktop\\basource.mp4");	//����Ƶ����Ƶ�ļ���
	Sleep(3000);						
 
	//�Żõ�Ƭ��Sleep()�������ڲ����ٶ�
	for (i = 1; i <= 3005; i++)	//i �ķ�Χת��Ϊ(.txt)�ļ��ĸ���
	{
		sprintf(FileName,
			"E:\\����ҵ\\Debug\\bascii\\ba(%1d).txt",i);

        in = fopen(FileName, "r");
		assert(in != NULL);		
		fread(hi,1,4096, in);
		printf("%s\n%d", hi, i);
		gotoxy(1, 1);			
		Sleep(26);				
		fclose(in);
	}
}