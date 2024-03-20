#pragma once
void clear();
int gameMapWidth();
int gameMapHeight();
void resetGameMap(char arr[20][20], int width, int height);
void printGameMap(char arr[20][20], int width, int height);
bool getPlayerAnswer(int xCoordinate, int yCoordinate);
void gameLogic();
void gameLogicSecond();
