#include <stdio.h>
#include <conio.h>
#include <Windows.h>
// �� 0xa1e1 ��
// �� 0xa1dc ��
// �� 0xa1db ��������
// �� 0xa1df ��
#define ONE 20
#define TWO 51

void gotoxy(int x,int y,int f);
void move(int* x,int* y,int map[ONE][TWO],int gol[10][2],int gol_cnt);
void move_print();
int move_cnt;
int flag;
void gol_check(int cnt,int map[ONE][51],int check[10][2]);

void main()
{
	int key;
	int map[ONE][51] = 
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1.1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,4,4,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,4,4,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1},
		{1,1,1,1,0,0,0,0,0,0,0,0,3,3,0,0,0,0,3,3,9,9,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
		{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,0,0,1,1,0,0,1,1,3,3,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1.1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1.1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,0,0,0,0,0,0,4,4,1,1,0,0,1,1,1,1,0,0,0,0,0,0.1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,4,4,1,1,0,0,0,0,1,1,0,0,0,0,0,0,3,3,0,0,1,1.1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0.1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,4,4,1,1,0,0,0,0,1,1.1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,4,1,1.1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1.1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1.1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1.1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1.1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};
	int gol[10][2];
	int i,j;
	int x,y;
	int g=0;
	int golcnt=0;
	for(i=0;i<ONE;i++)
	{
		for(j=0;j<TWO;j+=2)
		{
			if((map[i][j]==1)&&(map[i][j+1]==1)) 
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
				printf("%c%c",0xa1,0xe1);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			}//��
			if((map[i][j]==3)&&(map[i][j+1]==3)) printf("%c%c",0xa1,0xdc); //��
			if((map[i][j]==4)&&(map[i][j+1]==4)) 
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),160);
				printf("%c%c",0xa1,0xdb);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				gol[g][0]=i;
				gol[g++][1]=j;
				golcnt++;
			}//��
			if((map[i][j]==9)&&(map[i][j+1]==9)) 
			{
				printf("%c%c",0xa1,0xdf);
				y=j;
				x=i;
			}//��
			if((map[i][j]==0)&&(map[i][j+1]==0)) printf("  ");
		}
		printf("\n");
	}
	i=0;
	while(flag==0)
	{
		move(&x,&y,map,gol,golcnt);
	}
	Sleep(5000);
	printf("\n");
	
}

void move(int *x,int *y,int map[ONE][TWO],int gol[10][2],int gol_cnt)
{
	int key;
	key=getch();
	if(key==224)
	{
		key=getch();
		switch(key)
		{
			case 75://�����̵�
				if((map[*x][(*y-1)]!=1)&&(map[*x][(*y-2)]!=1))
				{
					if((map[*x][(*y-1)]==0)&&(map[*x][(*y-2)]==0))
					{
						move_cnt++;
						move_print();
						map[*x][(*y-1)]=9;
						map[*x][(*y-2)]=9;
						map[*x][*y]=0;
						map[*x][(*y+1)]=0;
						gotoxy(*x,(*y-1),4);
						*y=(*y-2);
						gol_check(gol_cnt,map,gol);
					}
					else if((map[*x][(*y-1)]==3)&&(map[*x][(*y-2)]==3)) //�������� �̵��� ����������
					{
						if((map[*x][(*y-3)]!=1)&&(map[*x][(*y-4)]!=1)&&(map[*x][(*y-3)]!=3)&&(map[*x][(*y-4)]!=3)) //���ű�ٰ� �հ��°� ����
						{
							if((map[*x][(*y-3)]==4)&&(map[*x][(*y-4)]==4)) // �����̵����� ���� ���ڿ��־�����
							{
								move_cnt++;
								move_print();
								map[*x][(*y-3)]=3;
								map[*x][(*y-4)]=3;
								map[*x][(*y-1)]=9;
								map[*x][(*y-2)]=9;
								map[*x][*y]=0;
								map[*x][(*y+1)]=0;
								gotoxy(*x,(*y-1),9);
								*y=(*y-2);
								gol_check(gol_cnt,map,gol);
							}
							else
							{
								move_cnt++;
								move_print();
								map[*x][(*y-3)]=3;
								map[*x][(*y-4)]=3;
								map[*x][(*y-1)]=9;
								map[*x][(*y-2)]=9;
								map[*x][*y]=0;
								map[*x][(*y+1)]=0;
								gotoxy(*x,(*y-1),5);
								*y=(*y-2);
								gol_check(gol_cnt,map,gol);
							}
						}
					}
				}
				break;

			case 77 : //�����������̵�
				if((map[*x][(*y+2)]!=1)&&(map[*x][(*y+3)]!=1))
				{
					if((map[*x][(*y+2)]==0)&&(map[*x][(*y+3)]==0))
					{
						move_cnt++;
						move_print();
						map[*x][(*y+2)]=9;
						map[*x][(*y+3)]=9;
						map[*x][*y]=0;
						map[*x][(*y+1)]=0;
						gotoxy(*x,(*y+2),6);
						*y=(*y+2);
					}
					else if((map[*x][(*y+2)]==3)&&(map[*x][(*y+3)]==3)) // �������̵��� ���� ��������
					{
						if((map[*x][(*y+4)]!=1)&&(map[*x][(*y+5)]!=1)&&(map[*x][(*y+4)]!=3)&&(map[*x][(*y+5)]!=3)) // ���ű�ٰ� �հ��°� ����
						{
							if((map[*x][(*y+4)]==4)&&(map[*x][(*y+5)]==4)) // �������̵����� ���� ���ڿ� �־�����
							{
								move_cnt++;
								move_print();
								map[*x][(*y+4)]=3;
								map[*x][(*y+5)]=3;
								map[*x][(*y+3)]=9;
								map[*x][(*y+2)]=9;
								map[*x][(*y+1)]=0;
								map[*x][*y]=0;
								gotoxy(*x,(*y+4),10);
								*y=(*y+2);
								gol_check(gol_cnt,map,gol);
							}
							else
							{
								move_cnt++;
								move_print();
								map[*x][(*y+4)]=3;
								map[*x][(*y+5)]=3;
								map[*x][(*y+3)]=9;
								map[*x][(*y+2)]=9;
								map[*x][(*y+1)]=0;
								map[*x][*y]=0;
								gotoxy(*x,(*y+4),7);
								*y=(*y+2);
								gol_check(gol_cnt,map,gol);
							}
						}
					}
				}
				break;

			case 72://�����̵�
				if((map[(*x-1)][*y]!=1)&&(map[(*x-1)][(*y+1)]!=1))
				{
					if((map[(*x-1)][*y]==0)&&(map[(*x-1)][(*y+1)]==0))
					{
						move_cnt++;
						move_print();
						map[(*x-1)][*y]=9;
						map[(*x-1)][(*y+1)]=9;
						map[*x][*y]=0;
						map[*x][(*y+1)]=0;
						gotoxy((*x-1),*y,0);
						*x=(*x-1);
					}
					else if((map[(*x-1)][*y]==3)&&(map[(*x-1)][(*y+1)]==3))  //����������
					{
						if((map[(*x-2)][*y]!=1)&&(map[(*x-2)][(*y+1)]!=1)&&(map[(*x-2)][*y]!=3)&&(map[(*x-2)][(*y+1)]!=3))   //���ű�ٰ� �հ��°� ����
						{
							if((map[(*x-2)][*y]==4)&&(map[(*x-2)][(*y+1)]==4)) // �����̵��� �����־�����
							{
								move_cnt++;
								move_print();
								map[(*x-2)][*y]=3;
								map[(*x-2)][(*y+1)]=3;
								map[(*x-1)][*y]=9;
								map[(*x-1)][(*y+1)]=9;
								map[*x][*y]=0;
								map[*x][(*y+1)]=0;
								gotoxy((*x-2),*y,11);
								*x=(*x-1);
								gol_check(gol_cnt,map,gol);
							}
							else
							{
								move_cnt++;
								move_print();
								map[(*x-2)][*y]=3;
								map[(*x-2)][(*y+1)]=3;
								map[(*x-1)][*y]=9;
								map[(*x-1)][(*y+1)]=9;
								map[*x][*y]=0;
								map[*x][(*y+1)]=0;
								gotoxy((*x-2),*y,1);
								*x=(*x-1);
								gol_check(gol_cnt,map,gol);
							}
						}
					}
				}
				break;

			case 80: // �Ʒ����̵�
				if((map[(*x+1)][*y]!=1)&&(map[(*x+1)][(*y+1)]!=1))
				{
					if((map[(*x+1)][*y]==0)&&(map[(*x+1)][(*y+1)]==0))
					{
						move_cnt++;
						move_print();
						map[(*x+1)][*y]=9;
						map[(*x+1)][(*y+1)]=9;
						map[*x][*y]=0;
						map[*x][(*y+1)]=0;
						gotoxy((*x+1),*y,2);
						*x=(*x+1);
					}
					else if((map[(*x+1)][*y]==3)&&(map[(*x+1)][*y]==3)) //����������
					{
						if((map[(*x+2)][*y]!=1)&&(map[(*x+2)][(*y+1)]!=1)&&(map[(*x+2)][*y]!=3)&&(map[(*x+2)][(*y+1)]!=3)) // ���ű�ٰ� �հ��°� ����
						{
							if((map[(*x+2)][*y]==4)&&(map[(*x+2)][(*y+1)]==4)) // �Ʒ��� ���ھȿ� ���� �־�����
							{
								move_cnt++;
								move_print();
								map[(*x+2)][*y]=3;
								map[(*x+2)][(*y+1)]=3;
								map[(*x+1)][*y]=9;
								map[(*x+1)][(*y+1)]=9;
								map[*x][*y]=0;
								map[*x][(*y+1)]=0;
								gotoxy((*x+2),*y,12);
								*x=(*x+1); 
								gol_check(gol_cnt,map,gol);
							}
							else
							{
								move_cnt++;
								move_print();
								map[(*x+2)][*y]=3;
								map[(*x+2)][(*y+1)]=3;
								map[(*x+1)][*y]=9;
								map[(*x+1)][(*y+1)]=9;
								map[*x][*y]=0;
								map[*x][(*y+1)]=0;
								gotoxy((*x+2),*y,3);
								*x=(*x+1); 
								gol_check(gol_cnt,map,gol);
							}
						}
					}

				}
				break;
		}	
	}
}



void gotoxy(int y,int x,int f)
{
	COORD Pos;
	Pos.X=x;
	Pos.Y=y;
	if(f==8)
	{
		Pos.X=0;
		Pos.Y=20;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("�ڡڡڡڡڡڡڡڡڡ�");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		printf("~success~");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("�ڡڡڡڡڡڡڡڡڡ�");

	}
	else if(f==0) // �����̵�
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdf);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		Pos.Y+=1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("  ");
	}

	else if(f==1) // �����̵��� ������������
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdc);
		Pos.Y+=1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdf);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		Pos.Y+=1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("  ");
	}

	else if(f==2) // �Ʒ����̵�
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdf);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		Pos.Y-=1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("  ");
	}

	else if(f==3) //�Ʒ��� ����������
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdc);
		Pos.Y-=1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdf);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		Pos.Y-=1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("  ");
	}

	else if(f==4) // �����̵�
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("  ");
		Pos.X-=1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdf);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	}

	else if(f==5) // ���� ����������
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("  ");
		Pos.X-=1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdf);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		Pos.X-=2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdc);
	}
	
	else if(f==6) // �������̵�
	{	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdf);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		Pos.X-=2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("  ");
	}

	else if(f==7) // �������̵� ����������
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdc);
		Pos.X-=2;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdf);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		Pos.X-=2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("  ");
	}

	else if(f==8)
	{
		Pos.X=0;
		Pos.Y=20;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("�ڡڡڡڡڡڡڡڡڡڡڡ�");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		printf("~success~");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("�ڡڡڡڡڡڡڡڡڡڡڡ�");
		printf("\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	}

	else if(f==9) // �����̵����� ���ڿ� ���̵�����
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("  ");
		Pos.X-=1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdf);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		Pos.X-=2;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdc);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

	} 
	
	else if(f==10) // �������̵����� ���ڿ� ���̵�����
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdc);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		Pos.X-=2;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdf);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		Pos.X-=2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("  ");
	}
	
	else if(f==11) // �����̵����� ���ڿ� ���̵�����
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdc);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		Pos.Y+=1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdf);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		Pos.Y+=1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("  ");
	}

	else if(f==12) // �Ʒ����̵����� ���ڿ� ���̵�����
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdc);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		Pos.Y-=1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdf);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		Pos.Y-=1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("  ");
	}
}

void move_print()
{
	COORD Pos;
	Pos.X=21;
	Pos.Y=0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
	printf("Move : %d",move_cnt);
}

void gol_check(int cnt,int map[ONE][51],int check[10][2])
{
	int i;
	int v;
	int k;
	int _cnt=0; // �Լ� ȣ���Ҷ����� 0���� �ʱ�ȭ�� �׷��Ƿ� ������ �������� ����
	for(i=0;i<cnt;i++)
	{
		v=check[i][0];
		k=check[i][1];
		if(map[v][k]==3)
		{
			_cnt++;
		}
	}
	if(cnt==_cnt)
	{
		flag=1;
		gotoxy(3,3,8);
	}
}