#include <iostream>
#include "Homework05.h"

using namespace std;

enum EMapEnv
{
	ROAD,
	WALL,
	START,
	END,
	PLAYER,
};

enum EDir
{
	UP,
	Down,
	Left,
	Right,
	EDirLength
};

//U, D, L, R 순의 방향 벡터
const int Dx[4] = { -1, 1, 0, 0 };
const int Dy[4] = { 0, 0, -1, 1 };

// 랜덤으로 적을 만날 확률
const int RandEncounterPerCentage = 30;

const int MazeRows = 10;
const int MazeCols = 20;

int PlayerX = 0;
int PlayerY = 0;

int Maze[MazeRows][MazeCols] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
	{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
	{1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
	{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
	{1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1},
	{1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
	{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,3,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int RandomRange(int Min, int Max)
{
	return rand() % (Max - Min + 1) + Min;
}

int RandomRange(int Max)
{
	return RandomRange(0, Max);
}

void Print2DMap()
{

	for (int i = 0; i < MazeRows; i++)
	{
		for (int j = 0; j < MazeCols; j++)
		{
			if ((i == PlayerX) && (j == PlayerY))
				printf("%c", 'P');
			else if (Maze[i][j] == ROAD)
				printf("%c", '.');
			else if (Maze[i][j] == WALL)
				printf("%c", '#');
			else if (Maze[i][j] == START)
				printf("%c", 'S');
			else if (Maze[i][j] == END)
				printf("%c", 'E');
			
		}
		printf("\n");

	}
}

void CheckDirCanGO(bool* DirArr, int PlayerX, int PlayerY)
{

	// 상 하 좌 우 방향으로 갈 수 있는지 기록
	for (int i = 0; i < 4; i++)
	{
		// 다음 좌표
		int NextX = PlayerX + Dx[i];
		int NextY = PlayerY + Dy[i];

		// 다음 좌표가 맵의 밖이면 불가
		if (NextX < 0 || NextX >= MazeRows || NextY < 0 || NextY >= MazeCols)
		{
			DirArr[i] = false;
			continue;
		}

		// 다음 좌표가 벽이면 불가
		if (Maze[NextX][NextY] == WALL)
		{
			DirArr[i] = false;
			continue;
		}

		//나머지 경우는 가능
		DirArr[i] = true;
	}
}

void PrintChoiceScreen(bool* DirArr)
{
	printf("이동할 방향을 선택하세요 (w: 위, s: 아래, a: 왼쪽, d: 오른쪽)\n");
	for (int i = 0; i < EDirLength; i++)
	{
		if (DirArr[i] == false) continue;
		switch (EDir(i))
		{
			case UP:
				printf("w(↑) ");
				break;
			case Down:
				printf("s(↓) ");
				break;
			case Right:
				printf("d(→) ");
				break;
			case Left:
				printf("a(←) ");
				break;
		}
	}
	printf("\n");
	printf("방향 입력: ");
}

int GetDirInput()
{
	char Input;
	cin >> Input;
	cin.clear();
	cin.ignore(10000, '\n');
	if (Input == 'w' || Input == 'W')
		return UP;
	if (Input == 's' || Input == 'S')
		return Down;
	if (Input == 'a' || Input == 'A')
		return Left;
	if (Input == 'd' || Input == 'D')
		return Right;

	return EDirLength;
}

bool RandEncounter()
{
	// 0부터 100까지 랜덤값이 29보다 작으면 (30프로)
	// Todo 검즘 한번하기
	if (RandomRange(100) < RandEncounterPerCentage)
		return true;
	return false;
}

void PrintHP(int YourHP, int MonsterHP)
{
	printf("\n당신의 체력: %d\n", YourHP);
	printf("몬스터의 체력: %d\n\n", MonsterHP);
}

int RollDice(int DiceMax)
{
	int Res = RandomRange(1, DiceMax);
	printf("주사위의 눈 : %d\n", Res);
	return Res;
}

int GetAttackDamage(int BaseDamage, int DiceMax)
{

	// 여기서 입력할때까지 대기

	cin.get();
	return BaseDamage + RollDice(DiceMax);
}

bool IsCritical(int CriticalPercentage)
{
	if (RandomRange(100) < CriticalPercentage)
		return true;
	return false;
}

bool TurnBasedCombat()
{
	const int BaseDamage = 5;
	const int DiceMax = 10;
	const int CriticalPercentage = 10;

	int YourHP = 100;
	int MonsterHP = 100;
	bool IsCrit = false;

	int Damage = 0;
	int FinalDamage = 0;

	printf("\n!적을 만났습니다!\n");
	printf("엔터를 눌러서 적과의 전투를 시작해 주세요\n");
	cin.get();

	while (0 < MonsterHP && 0 < YourHP)
	{
		//-----------------------
		//1. 당신의 턴			|
		//-----------------------
		// 값 초기화
		Damage = 0;
		FinalDamage = 0;
		IsCrit = false;

		system("cls");

		printf("\n-----------------당신의 차례------------------------\n");
		PrintHP(YourHP, MonsterHP);

		printf("10면체 주사위를 굴려 5 + [주사위 눈금]의 데미지를 줄 수 있습니다.");
		printf("엔터를 눌러서 주사위를 굴려주세요\n");

		//데미지 산출 
		Damage = GetAttackDamage(BaseDamage, DiceMax);
		//최종 데미지 계산
		IsCrit = IsCritical(CriticalPercentage);
		FinalDamage = IsCrit ? Damage * 2 : Damage;
		// 공격 처리
		MonsterHP -= FinalDamage;
		if (IsCrit)
			printf("\n 크리티컬이 발생하여");

		printf("%d의 데미지로 적을 공격했습니다!.\n", FinalDamage);
		
		// 종료조건 체크
		if (MonsterHP <= 0 || YourHP <= 0) break;
		printf("엔터를 눌러 턴을 넘기세요\n");
		printf("\n----------------------------------------------------\n");
		cin.get();


		printf("\n-----------------몬스터 차례------------------------\n");
		//-----------------------
		//2. 몬스터 턴			|
		//-----------------------
		PrintHP(YourHP, MonsterHP);
		// 값 초기화
		Damage = 0;
		FinalDamage = 0;
		IsCrit = false;

		printf("엔터를 눌러 적의 주사위를 확인하세요\n");

		//데미지 산출 
		Damage = GetAttackDamage(BaseDamage, DiceMax);
		//최종 데미지 계산
		IsCrit = IsCritical(CriticalPercentage);
		FinalDamage = IsCrit ? Damage * 2 : Damage;
		// 공격 처리
		YourHP -= FinalDamage;
		if (IsCrit)
			printf("\n 크리티컬이 발생하여");

		printf("%d의 데미지로공격 받았습니다!.\n", FinalDamage);

		if (MonsterHP <= 0 || YourHP <= 0) break;
		printf("엔터를 눌러 내턴을 시작하세요\n");
		printf("\n----------------------------------------------------\n");
		cin.get();
	}

	if (MonsterHP <= 0)
	{
		printf("당신이 승리하였습니다.");
		return true;
	}

	printf("당신이 패배하였습니다.");
	return false;
}

void Homework05_Run()
{
	printf("미로게임 턴제 전투 만들기\n");
	// 0.초기값 설정
	//다음을 반복
		// 1. 격자 출력
		// 2. 이동 가능 방향 판단
		// 3. 이동 가능 방향 출력
		// 4. 플레이어 입력
		// 5. 이동

		// 7. 종료조건 확인

	bool CanGo[EDirLength] = { false, false, false, false };

	// 시작 좌표 설정
	PlayerX = 1;
	PlayerY = 1;
	int Dir = EDirLength;

	//TODO몇번 만날건지 정하기
	bool bMetMonster = false;

	//탈출까지 반복
	while (true)
	{
		system("cls");
		// 0. 격자맵 출력
		Print2DMap();

		// 1. 이동가능 방향 판단
		CheckDirCanGO(CanGo, PlayerX, PlayerY);


		// 3. 이동 방향 입력
		while (Dir == EDirLength)
		{
			// 이동 선택 화면 출력
			PrintChoiceScreen(CanGo);
			Dir = GetDirInput();
			if (Dir == EDirLength || CanGo[Dir] == false)
			{
				printf("\n\n올바른 방향을 입력하세요\n\n");
				Dir = EDirLength;
			}
		}
		// 4.이동처리
		PlayerX += Dx[Dir];
		PlayerY += Dy[Dir];

		// 5. 종료 확인
		if (Maze[PlayerX][PlayerY] == END)
		{
			printf("탈출하였습니다! \n");
			break;
		}


		// 6. 일정확률로 적을 만남 (현재는 한번만 만남, 이래야 테스트 원활)
		bool bWon = false;
		if (RandEncounter() && bMetMonster == false)
		{
			bMetMonster = true;
			bWon = TurnBasedCombat();
			if (!bWon) break;

			printf("계속 탈출하려면 아무키나 누르세요");
			cin.get();
		}


		// 입력 변수 초기화
		Dir = EDirLength;
	}

}