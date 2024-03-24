#include "Header.h"
#include <iostream>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <Windows.h>
#include <locale.h>

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "RU");

	int num;
	do
	{
		printf("Выберите команду\n"); printf("1 - Запуск первой версии игры \"Звездочки\"\n"); printf("2 - Запуск второй версии игры \"Звездочки\"\n"); printf("0 - Выход из программы\n");
		do
		{
			scanf_s("%d", &num);
			if (num != 1 && num != 0 && num != 2)
			{
				printf("Попробуйте ввести корректные данные\n");
			}
		} while (num != 1 && num != 0 && num != 2);
		clear();
		switch (num)
		{
		case 1:gameLogic(); break;
		case 2:gameLogicSecond(); break;
		case 0:printf("До свидания!\n"); break;
		}
	} while (num != 0);
	

	return 0;
}
