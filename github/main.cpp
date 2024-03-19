#include <iostream>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <Windows.h>


void clear()
{
	system("cls");
}



int gameMapWidth()
{
	int width;
	printf("������� ������ �������� ���� � ��������� �� 2 �� 20\n");
	do
	{
		printf("������ �������� ���� = "); scanf_s("%d", &width);
		if (width < 2 || width > 20)
		{
			printf("������� ������ ��������!\n");
		}
		
	} while (width < 2 || width > 20);
	return width;
}

int gameMapHeight()
{
	int height;
	printf("������� ������ �������� ���� � ��������� �� 2 �� 20\n");
	do
	{
		printf("������ �������� ���� = "); scanf_s("%d", &height);
		if (height < 2 || height > 20)
		{
			printf("������� ������ ��������!\n");
		}

	} while (height < 2 || height > 20	);
	return height;
}

void resetGameMap(char arr[20][20], int width, int height)
{
	char star;
	star = '*';

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			arr[i][j] = star;
		}
	}
}

void printGameMap(char arr[20][20], int width, int height)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool getPlayerAnswer(int xCoordinate, int yCoordinate)
{
	int x, y;
	printf("������� ������: ");
	scanf_s("%d", &x);
	printf("������� �������: ");
	scanf_s("%d", &y);

	return xCoordinate == x - 1 && yCoordinate == y - 1;

	if (xCoordinate == x - 1 && yCoordinate == y - 1)
	{
		return 1;
	}
	return 0;
}




void gameLogic()
{
	char arr[20][20];
	int lives = 3;
	int points = 0;
	int width = gameMapWidth();
	int height = gameMapHeight();
	clear();

	while (lives != 0) {
		printf("����� ������: %d\n", lives);
		printf("\n");
			resetGameMap(arr, width, height);

		// ���������� ���������� � ������������� # � ������� ����
		srand(time(0));
		int randomNumWidth = rand() % width;
		int randomNumHeight = rand() % height;
		arr[randomNumWidth][randomNumHeight] = '#';

		printGameMap(arr, width, height);

		if (getPlayerAnswer(randomNumWidth, randomNumHeight) == 1)
		{
			printf("����������, �� �������!\n");
			points++;
		} 
		else 
		{
			lives--;
			clear();
			printf("� ���!!! �� ��������, ���������� �����\n");
		}
		Sleep(750);
		clear();
	}
	
	printf("���� ���������\n");
	if (points % 10 == 1 && points % 100 != 11)
	{
		printf("�� ���������� %d ����\n", points);
	}
	else if ((points % 100 < 10 || points % 100 > 20) && (points % 10 == 2 || points % 10 == 3 || points % 10 == 4))
	{
		printf("�� ���������� %d ����\n", points);
	}
	else
	{
		printf("�� ���������� %d �����\n", points);
	}
	Sleep(1500);
	clear();
}

void gameLogicSecond()
{
	char arr[20][20];
	int randomNumWidth, randomNumHeight;
	int lives = 3;
	int points = 0;
	int width = gameMapWidth();
	int height = gameMapHeight();
	int remainingStars = width * height;
	clear();
	resetGameMap(arr, width, height);
	while (lives != 0 && remainingStars != 0) {

		printf("����� ������: %d\n", lives);
		printf("\n");

		// ���������� ���������� � ������������� # � ������� ����
		srand(time(0));
		do
		{
			randomNumWidth = rand() % width;
			randomNumHeight = rand() % height;
		} while (arr[randomNumWidth][randomNumHeight] != '*');
		arr[randomNumWidth][randomNumHeight] = '#';
		
		printGameMap(arr, width, height);
		remainingStars--;
		if (getPlayerAnswer(randomNumWidth, randomNumHeight) == 1)
		{
			
			printf("����������, �� �������!\n");
		}
		else
		{
			lives--;
			clear();
			printf("� ���!!! �� ��������, ���������� �����\n");
			remainingStars = width * height;
			resetGameMap(arr, width, height);

		}
		Sleep(750);
		clear();
	}

	if (remainingStars == 0)
	{
		printf("�����������, �� ��������!\n");
	}

	else
	{
		printf("� ���������, �� ��������� :(\n");
	}
	Sleep(2250);
	clear();
}

int main()
{
	setlocale(0, "");

	int num;
	do
	{
		printf("�������� �������\n"); printf("1 - ������ ������ ������ ���� \"���������\"\n"); printf("2 - ������ ������ ������ ���� \"���������\"\n"); printf("0 - ����� �� ���������\n");
		do
		{
			scanf_s("%d", &num);
			if (num != 1 && num != 0 && num != 2)
			{
				printf("���������� ������ ���������� ������\n");
			}
		} while (num != 1 && num != 0 && num != 2);
		clear();
		switch (num)
		{
		case 1:gameLogic(); break;
		case 2:gameLogicSecond(); break;
		case 0:printf("�� ��������!\n"); break;
		}
	} while (num != 0);
	

	return 0;
}
