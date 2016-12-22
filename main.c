#include <stdio.h>
#include <conio.h>
#include <Windows.h>
// ■ 0xa1e1 벽
// ● 0xa1dc 공
// ○ 0xa1db 골인지점
// ◆ 0xa1df 말
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
			}//벽
			if((map[i][j]==3)&&(map[i][j+1]==3)) printf("%c%c",0xa1,0xdc); //공
			if((map[i][j]==4)&&(map[i][j+1]==4)) 
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),160);
				printf("%c%c",0xa1,0xdb);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				gol[g][0]=i;
				gol[g++][1]=j;
				golcnt++;
			}//골
			if((map[i][j]==9)&&(map[i][j+1]==9)) 
			{
				printf("%c%c",0xa1,0xdf);
				y=j;
				x=i;
			}//말
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
			case 75://왼쪽이동
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
					else if((map[*x][(*y-1)]==3)&&(map[*x][(*y-2)]==3)) //왼쪽으로 이동시 공만났을때
					{
						if((map[*x][(*y-3)]!=1)&&(map[*x][(*y-4)]!=1)&&(map[*x][(*y-3)]!=3)&&(map[*x][(*y-4)]!=3)) //공옮기다가 뚫고가는거 방지
						{
							if((map[*x][(*y-3)]==4)&&(map[*x][(*y-4)]==4)) // 왼쪽이동으로 공을 상자에넣엇을때
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

			case 77 : //오른쪽으로이동
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
					else if((map[*x][(*y+2)]==3)&&(map[*x][(*y+3)]==3)) // 오른쪽이동중 말을 만났을떄
					{
						if((map[*x][(*y+4)]!=1)&&(map[*x][(*y+5)]!=1)&&(map[*x][(*y+4)]!=3)&&(map[*x][(*y+5)]!=3)) // 공옮기다가 뚫고가는거 방지
						{
							if((map[*x][(*y+4)]==4)&&(map[*x][(*y+5)]==4)) // 오른쪽이동으로 공을 상자에 넣었을때
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

			case 72://위쪽이동
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
					else if((map[(*x-1)][*y]==3)&&(map[(*x-1)][(*y+1)]==3))  //공만났을때
					{
						if((map[(*x-2)][*y]!=1)&&(map[(*x-2)][(*y+1)]!=1)&&(map[(*x-2)][*y]!=3)&&(map[(*x-2)][(*y+1)]!=3))   //공옮기다가 뚫고가는거 방지
						{
							if((map[(*x-2)][*y]==4)&&(map[(*x-2)][(*y+1)]==4)) // 위쪽이동시 공을넣었을때
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

			case 80: // 아래로이동
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
					else if((map[(*x+1)][*y]==3)&&(map[(*x+1)][*y]==3)) //공만났을때
					{
						if((map[(*x+2)][*y]!=1)&&(map[(*x+2)][(*y+1)]!=1)&&(map[(*x+2)][*y]!=3)&&(map[(*x+2)][(*y+1)]!=3)) // 공옮기다가 뚫고가는거 방지
						{
							if((map[(*x+2)][*y]==4)&&(map[(*x+2)][(*y+1)]==4)) // 아래쪽 상자안에 공을 넣었을때
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
		printf("★★★★★★★★★★");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		printf("~success~");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("★★★★★★★★★★");

	}
	else if(f==0) // 위로이동
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdf);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		Pos.Y+=1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("  ");
	}

	else if(f==1) // 위로이동시 말을만났을때
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

	else if(f==2) // 아래로이동
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdf);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		Pos.Y-=1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("  ");
	}

	else if(f==3) //아래쪽 공만났을때
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

	else if(f==4) // 왼쪽이동
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("  ");
		Pos.X-=1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdf);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	}

	else if(f==5) // 왼쪽 공만났을때
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
	
	else if(f==6) // 오른쪽이동
	{	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("%c%c",0xa1,0xdf);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		Pos.X-=2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
		printf("  ");
	}

	else if(f==7) // 오른쪽이동 공만났을때
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
		printf("★★★★★★★★★★★★");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		printf("~success~");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("★★★★★★★★★★★★");
		printf("\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	}

	else if(f==9) // 왼쪽이동으로 상자에 공이들어갔을때
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
	
	else if(f==10) // 오른쪽이동으로 상자에 공이들어갔을때
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
	
	else if(f==11) // 위쪽이동으로 상자에 공이들어갔을때
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

	else if(f==12) // 아래쪽이동으로 상자에 공이들어갔을때
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
	int _cnt=0; // 함수 호출할때마다 0으로 초기화됨 그러므로 모든곳에 들어가야지만 끝남
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