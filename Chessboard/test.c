#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"


void menu()
{
	printf("***************************\n");
	printf("***** 1.paly   0.exit *****\n");
	printf("***************************\n");

}

void game()
{
	char board[ROW][COL] = { 0 };
	char yet = 0;
	//初始化数组
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);

	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		yet = IsWin(board, ROW, COL);
		if (yet != 'C')
		{
			break;
		}
		
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		yet = IsWin(board, ROW, COL);
		if (yet != 'C')
		{
			break;
		}
	}
	if (yet == '*')
	{
		printf(" 玩家赢\n");
	}
	if (yet =='#')
	{
		printf("电脑赢\n");
	}
	if (yet == 'Q')
	{
		printf("平局\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf(" 退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;

		}
	} while (input);
}



int main()
{
	test();



	return 0;
}