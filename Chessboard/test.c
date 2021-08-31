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
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);

	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		yet = IsWin(board, ROW, COL);
		if (yet != 'C')
		{
			break;
		}
		
		//��������
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
		printf(" ���Ӯ\n");
	}
	if (yet =='#')
	{
		printf("����Ӯ\n");
	}
	if (yet == 'Q')
	{
		printf("ƽ��\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf(" �˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;

		}
	} while (input);
}



int main()
{
	test();



	return 0;
}