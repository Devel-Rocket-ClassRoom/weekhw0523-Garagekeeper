// HJ_HomeWork.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <time.h>
#include "Homework02.h"
#include "Homework03.h"
#include "Homework04.h"
#include "Homework05.h"

int main()
{
    int Seed = static_cast<unsigned int>(time(0));
    //int Seed = 228;
    //int Seed = 101;
    srand(Seed);

    //Homework02_Run();
    //Homework03_Run();
    //Homework04_Run();
    Homework05_Run();
}

