#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define PR "�����������"//Physical rhythm
#define ER "�����������"//Emotional rhythm
#define IR "�����������"//Intellectual rhythm 
#define CD "�պô���������"
#define HD "���ڸ߳��ڵ�"
#define MD "�պô����ٽ���"
#define LD "���ڵͳ��ڵ�"
 
int sum(int y,int m,int d)//�����ڴ���������������ɣ����������ɡ��������ɡ��������ɡ����ǵ����ڷֱ�Ϊ28�졢33�졢23�졣
{
	int md[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int i,s=0;
	for(i=1;i<y;i++)
	if(i%4==0&&i%100!=0||i%400==0)
	s+=366;
	else
	s+=365;
		
	if(y%4==0&&y%100!=0||y%400==0)
	md[1]=29;
		
	for(i=1;i<m;i++)
	s+=md[i];
	s+=d;
		
	return s; 
}

int main()
{
	int YB,MB,DB,YI,MI,DI,md[12]={31,28,31,30,31,30,31,31,30,31,30,31};//��������Ƶĳ��������յļ�дyear of birth������
 	printf("��������ĳ��������գ����ԡ��꣬�£��ա��ĸ�ʽ���룩���˳�����Լ����������������������ɣ�Ϊ�����ṩ�򵼣���ܷ��գ���Ϊ�͹۹��ɣ��������ţ���");
 	scanf("%d,%d,%d",&YB,&MB,&DB);
 	md[1]=YB%4==0&&YB%100!=0||YB%400==0?29:28; 
 	
 	if(YB>0&&MB>0&&DB>0&&MB<13&&DB<=md[MB-1])
 	    printf("����������֪�����ɵ�����(���ԡ��꣬�£��ա��ĸ�ʽ����)��");
 	else
	{
		printf("ʱ���ʽ�������");
    	exit(1);
	}
	scanf("%d,%d,%d",&YI,&MI,&DI);
	md[1]=YI%4==0&&YI%100!=0||YI%400==0?29:28;
	if((YI>YB&&MI>0&&DI>0&&MI<13&&DI<=md[MI-1])||(YI==YB&&MI>MB&&DI>0&&MI<13&&DI<=md[MI-1])||(YI==YB&&MI==MB&&DI>=DB&&MI<13&&DI<=md[MI-1])) 
	{
		int s1,s2;
    s1=sum(YB,MB,DB);
    s2=sum(YI,MI,DI);
	int day_diff;
	day_diff=s2-s1;

    int rm1,rm2,rm3;
    rm1=day_diff%23;
	rm2=day_diff%28;
	rm3=day_diff%33; 
	
	if(rm1==0)
	    printf("%s%s��\n",PR,CD);
	if(0<rm1&&rm1<12)
	    printf("%s%s%d�졣\n",PR,HD,rm1);
	if(rm1==12)
	    printf("%s%s��\n",PR,MD);
	if(12<rm1&&rm1<23)
	    printf("%s%s%d�졣\n",PR,LD,rm1-12);
	    
	if(rm2==0)
	    printf("%s%s��\n",ER,CD);
	if(0<rm2&&rm2<14)
	    printf("%s%s%d�졣\n",ER,HD,rm2);
	if(rm2==14)
	    printf("%s%s��\n",ER,MD);
	if(14<rm2&&rm2<28)
	    printf("%s%s%d�졣\n",ER,LD,rm2-14);
	
	if(rm3==0)
	    printf("%s%s��\n",IR,CD);
	if(0<rm3&&rm3<17)
	    printf("%s%s%d�졣\n",IR,HD,rm3);
	if(rm3==17)
	    printf("%s%s��\n",IR,MD);
	if(17<rm3&&rm3<33)
	    printf("%s%s%d�졣\n",IR,LD,rm3-17);
	}
		
	else 
	    {
		printf("ʱ���ʽ�������");
	    } 

	system("pause"); 
 } 
