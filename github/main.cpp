#include <iostream>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>


void clear()
{
	system("cls");
}


int gameMapWidth()
{
	int width;
	printf("Введите ширину игрового поля в диапозоне от 2 до 20\n");
	do
	{
		printf("Ширина игрового поля = "); scanf_s("%d", &width);
		if (width < 2 || width > 20)
		{
			printf("Введите верные значения!\n");
		}
		
	} while (width < 2 || width > 20);
	return width;
}

int gameMapHeight()
{
	int height;
	printf("Введите высоту игрового поля в диапозоне от 2 до 20\n");
	do
	{
		printf("Высота игрового поля = "); scanf_s("%d", &height);
		if (height < 2 || height > 20)
		{
			printf("Введите верные значения!\n");
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
	printf("Введите строку: ");
	scanf_s("%d", &x);
	printf("Введите столбец: ");
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
		printf("Число жизней: %d\n", lives);
		printf("\n");
			resetGameMap(arr, width, height);

		// Генерируем координаты и устанавливаем # в игровое поле
		srand(time(0));
		int randomNumWidth = rand() % width;
		int randomNumHeight = rand() % height;
		arr[randomNumWidth][randomNumHeight] = '#';

		printGameMap(arr, width, height);

		if (getPlayerAnswer(randomNumWidth, randomNumHeight) == 1)
		{
			printf("Вы угадали\n");
			points++;
		} else 
		{
			printf("Вы ошиблись\n");
			lives--;
		}
		clear();
	}
	
	printf("Игра закончена\n");
	if (points % 10 == 1 && points % 100 != 11)
	{
		printf("Вы заработали %d очко\n", points);
	}
	else if ((points % 100 < 10 || points % 100 > 20) && (points % 10 == 2 || points % 10 == 3 || points % 10 == 4))
	{
		printf("Вы заработали %d очка\n", points);
	}
	else
	{
		printf("Вы заработали %d очков\n", points);
	}
	printf("\n");

}

int main()
{
	setlocale(0, "");

	int num;
	do
	{
		printf("Выберите команду\n"); printf("1 - Запуск игры \"Звездочки\"\n"); printf("0 - Выход из программы\n");
		do
		{
			scanf_s("%d", &num);
			if (num != 1 && num != 0)
			{
				printf("Попробуйте ввести корректные данные\n");
			}
		} while (num != 1 && num != 0);
		clear();
		switch (num)
		{
		case 1:gameLogic();
		case 0:printf("До свидания!\n");
		}
	} while (num != 0);
	

	return 0;
}
