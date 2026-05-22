// HJ_HomeWork.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <time.h>
#include "Homework.h";

int main()
{
    //int Seed = time(0);
    int Seed = 0;
    srand(Seed);
    Homework_RunAll();
}

