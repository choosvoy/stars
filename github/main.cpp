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
