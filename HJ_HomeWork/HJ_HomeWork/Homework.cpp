#include "Homework.h"

using namespace std;

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

void Homework_RunAll()
{
	//Homework02_Run();
	//Homework03_Run();
	//Homework04_Run();
	Homework05_Run();
}

int RandomRange(int Min, int Max)
{
	return rand() % (Max - Min + 1) + Min;
}

int RandomRange(int Max)
{
	return RandomRange(0, Max);
}

void Homework02_Run()
{
	printf("자리수 분해해서 합치기\n");
	//0. 입력 받기 (인티져 최대 범위까지)
	int InputNumber = 0;
	int Sum = 0;
	cin >> InputNumber;

	//1. 자리수 분리와 합치기
	//입력한 숫자가 0이면 종료
	while (InputNumber)
	{
		//1-0. 숫자를 10으로 나눈 나머지를 구해서 1의 자리수를 추출
		int Digit = InputNumber % 10;
		//1-1. 1의 자리의 숫자를 총합에 더한다.
		Sum += Digit = 0;
		//1-2. 숫자를 10으로 나눠 전체적으로 아랫자리수로 만든다 (10의 자리 -> 1의자리)
		Digit /= 10;
	}

	//2. 값 출력하기
	printf("모든 자리수의 합은 : [%d] 입니다!.\n\n", Sum);
}

void StartSlot(int* Slots, int Length, int SlotMin, int SlotMax)
{

	// min 부터 max 까지 랜덤 값으로 슬롯을 세팅.
	for (int i = 0; i < Length; i++)
		Slots[i] = RandomRange(SlotMin, SlotMax);
}

int SelectPrizeRatio(int* Slots, int Length)
{
	// 슬롯끼리 같은 숫자인지 체크하는 변수
	bool bSamenumber = true;
	for (int i = 0; i < Length; i++)
	{

		// 슬롯의 값이 다른 경우 종료
		if (Slots[i] != Slots[0])
		{
			bSamenumber = false;
			break;
		}
	}

	// 모든 슬롯이 다 같은 경우
	if (bSamenumber)
	{
		// 그 중에서 모든 숫자가 전부 7일때
		if (Slots[0] == 7)
		{
			return T7Ratio;	// 100000배
		}
		else
		{
			return JPTation;		// 50배
		}
	}
	return NoPrize;
}

void PrintSlot(int* Slots, int Length)
{
	printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	//printf("┃   %d    ┃     %d     ┃   %d   ┃\n", 1, 2, 3);
	for (int i = 0; i < Length; i++)
		printf("┃   %d    ", Slots[i]);
	printf("┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
}

void PrintCongratMsg(int PrizeRatio)
{

	// 그 중에서 모든 숫자가 전부 7일때
	if (PrizeRatio == T7Ratio)
	{
		printf("777 잭팟!\n");

	}
	else if (PrizeRatio == JPTation)
	{
		printf("축하합니다!\n");
	}
	else
	{
		printf("아쉽습니다.....!\n");
	}
}

void Homework03_Run()
{
	printf("슬롯 머신 게임 만들기\n\n");
	//0. 초기값 설정
	const int SlotMax = 7;
	const int SlotMin = 6;
	const int MinBet = 100;
	const int InitialMoney = 10'000;
	const int SlotSize = 3;

	int Slots[SlotSize] = { 0, };
	int PrizeRatio = 0;

	int PlayerMoney = InitialMoney;
	int PlayerBet = 0;

	while (PlayerMoney > MinBet)
	{
		// 다음을 반복
		//0. 현재금액 출력
		printf("현재금액 :[ %d ]\n", PlayerMoney);

		//1. 베팅(슬롯에 돈 넣기)
		do
		{
			printf("베팅금을 입력해주세요. (최소 100원부터 가능합니다)\n");
			printf("베팅금: ");
			cin >> PlayerBet;
			//1-0. 최소 100원 베팅
		} while (PlayerBet < 100 || MinBet > PlayerBet);
		// 1-1 베팅금 차감
		PlayerMoney -= PlayerBet;
		printf("베팅 후 현재 금액:[ %d ]\n", PlayerMoney);

		//2. 결과 생성
		StartSlot(Slots, SlotSize, SlotMin, SlotMax);

		//3. 슬롯결과 출력
		PrintSlot(Slots, SlotSize);

		//4. 결과 판단
		//4-0. 같은 숫자3개 -> 50배
		//4-1. 777 10000배
		PrizeRatio = SelectPrizeRatio(Slots, SlotSize);
		//축하 메시지 출력
		PrintCongratMsg(PrizeRatio);

		//5. 금액 계산
		int PlayerEarn = PlayerBet * PrizeRatio;
		//5-1 획득금액 출력
		if (PlayerEarn != NoPrize)
			printf("%d를 획득했습니다! \n", PlayerEarn);
		//5-2 금액 정산
		PlayerMoney += PlayerEarn;

		//6. 종료 조건 확인
		if (PlayerMoney <= MinBet)
		{
			printf("소지금 100 이하는 게임에 참가할 수 없습니다\n");
			printf("게임을 종료합니다\n\n");
			break;
		}

		printf("\n\n");
	}
}

void FisherYatesShuffle(int* Array, int Length)
{
	//0. 배열의 마지막에서 처음 방향으로 진행
	//1. 현재 인덱스랑 자기 앞의 인덱스 (자기포함)에서 랜덤으로 골라서 swap
	//2. 다음 인덱스로 진행
	//3. 0번 인덱스까지 가면 1회 한 것.

	for (int i = Length - 1; i > 0; i--)
	{
		int Target = rand() % (i + 1);
		int Temp = Array[i];
		Array[i] = Array[Target];
		Array[Target] = Temp;
	}
}

void DealerCardSelect(int* CardArray, int CardArrayLength, int* DealerCard, int  DealerCardLength)
{
	//0. 카드 배열을 섞는다.
	FisherYatesShuffle(CardArray, CardArrayLength);

	//1. 섞인 카드 배열의 앞에서 DealerCardLength - 1개를 고른다 (중복 없음)
	for (int i = 0; i < DealerCardLength - 1; i++)
		DealerCard[i] = CardArray[i];
	//2. 마지막으로 조커 추가
	DealerCard[DealerCardLength - 1] = Joker;

	//4. 손패도 섞는다.
	FisherYatesShuffle(DealerCard, DealerCardLength);
}

int PlayerCardSelect(int* DealerCard, int DealerCardLength)
{
	int Res = -1;
	int Index = 0;

	do
	{
		printf("카드를 선택헤주세요, 1번부터 %d번까지 있습니다.\n", DealerCardLength);
		cin >> Index;
		Res = DealerCard[Index];
	} while (Index < 1 || Index > DealerCardLength);

	// 배열을 왼쪽으로 붙임 (중간에 -1 없애기)
	for (int i = Index - 1; i < DealerCardLength - 1; i++)
	{
		DealerCard[i] = DealerCard[i + 1];
	}

	// 고른 카드를 반환
	return Res;
}

int  DetermineOutCome(int PlayerSelect, int PlayerBet)
{
	int PlayerEarn = 0;
	if (PlayerSelect == Joker)
	{
		// 4-0 플레이어가 조커뽑음, 승리, 베팅금 2배 반환
		PlayerEarn = PlayerBet * 2;
		printf("당신의 승리!!!!\n");
		printf("베팅금의 2배인 %d를 받습니다.\n", PlayerEarn);
	}
	else
	{
		// 4-1 플레이어가 조커실패
		printf("당신의 패배\n");
	}

	return PlayerEarn;
}

void PrintCard(int Card)
{
	if (Card == 0)
		printf("A");
	if (Card == 10)
		printf("J ");
	if (Card == 11)
		printf("J ");
	if (Card == 12)
		printf("Q ");
	if (Card == 13)
		printf("K ");
	if (Card == 99)
		printf("Joker ");
	if (1 <= Card && Card <= 9)
		printf("%d ", Card);

	printf("를 뽑았습니다!\n");
}

void Homework04_Run()
{
	printf("도둑 잡기 만들기\n");
	//초기값 설정
	const int InitialMoney = 10'000;
	const int MinBet = 100;
	// 조커를 제외한 카드 수
	const int CardSize = 14;
	const int DealerhandSizeMax = 3;
	int DealerHandSize = DealerhandSizeMax;

	int PlayerBet = 0;
	int PlayerMoney = InitialMoney;
	int PlayerSelect = 0;
	int PlayerEarn = 0;

	// 딜러의 손패를 위한 배열
	int DealerCard[DealerhandSizeMax] = { 0, };
	// 카드 뽑기를 위한 배열 
	int CardArray[CardSize];
	for (int i = 0; i < CardSize; i++)
		CardArray[i] = i;

	//다음을 반복
	while (PlayerMoney > MinBet)
	{
		//0.현재 금액 출력
		printf("\n현재금액 :[ %d ]\n", PlayerMoney);

		//1. 베팅
		do
		{
			printf("베팅금을 입력해주세요. (최소 100원부터 가능합니다)\n");
			printf("베팅금: ");
			cin >> PlayerBet;
			//1-0. 최소 100원 베팅
		} while (PlayerBet < 100 || MinBet > PlayerBet);
		// 1-1 베팅금 차감
		PlayerMoney -= PlayerBet;
		printf("\n베팅 후 현재 금액:[ %d ]\n", PlayerMoney);

		//2. 딜러 카드 선택
		// 2-0 A~K까지 중복없이 2장 + 조커
		DealerCardSelect(CardArray, CardSize, DealerCard, DealerHandSize);

		//3.플레이어 카드선택
		PlayerSelect = PlayerCardSelect(DealerCard, DealerHandSize);
		DealerHandSize--;

		//플레이어가 뽑은 카드 출력
		PrintCard(PlayerSelect);
		PlayerEarn = DetermineOutCome(PlayerSelect, PlayerBet);

		if (PlayerEarn == 0 && PlayerMoney > MinBet)
		{
			printf("두가지 선택지가 있습니다.\n");
			printf("1.다음 게임으로. 2. 베팅금의 2배를 추가로 베팅하고 한번 더 고르기\n");
			int PlayerChoice = 0;
			cin >> PlayerChoice;

			// 4-1-1 배팅금의 2배 지불 후 다시 고르기
			if (PlayerChoice == 2)
			{
				int Delta = PlayerBet * 2;
				PlayerMoney -= Delta;
				printf("베팅금의 2배인 %d를 지불하고 한번 더 고릅니다.\n", Delta);
				printf("\n현재금액 :[ %d ]\n", PlayerMoney);
				PlayerBet += Delta;

				PlayerSelect = PlayerCardSelect(DealerCard, DealerHandSize);
				PrintCard(PlayerSelect);
				PlayerEarn = DetermineOutCome(PlayerSelect, PlayerBet);
			}
		}
		else
		{
			PlayerMoney += PlayerEarn;
		}


		// 5. 종료 판단
		if (PlayerMoney <= MinBet)
		{
			printf("소지금 100 이하는 게임에 참가할 수 없습니다\n");
			printf("게임을 종료합니다\n\n");
			break;
		}

		// 딜러가 들 수 있는 카드의 개수 초기화
		DealerHandSize = DealerhandSizeMax;
	}

}

void Print2DMap()
{

	for (int i = 0; i < MazeRows; i++)
	{
		for (int j = 0; j < MazeCols; j++)
		{
			if (Maze[i][j] == ROAD)
				printf("%c", '.');
			else if (Maze[i][j] == WALL)
				printf("%c", '#');
			else if (Maze[i][j] == START)
				printf("%c", 'S');
			else if (Maze[i][j] == END)
				printf("%c", 'E');
			if (Maze[i][j] == PLAYER)
				printf("%c", 'P');
			if (Maze[i][j] == PLAYER + START)
				printf("%c", 'P');
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


	while (0 < MonsterHP && 0 < YourHP)
	{
		//-----------------------
		//1. 당신의 턴			|
		//-----------------------
		// 값 초기화
		Damage = 0;
		FinalDamage = 0;
		IsCrit = false;
		PrintHP(YourHP, MonsterHP);

		printf("10면체 주사위를 굴려 5 + [주사위 눈금]의 데미지를 줄 수 있습니다.\n");
		printf("아무키나 눌러서 주사위를 굴려주세요\n");
		
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


		//-----------------------
		//1. 몬스터 턴			|
		//-----------------------
		PrintHP(YourHP, MonsterHP);
		// 값 초기화
		Damage = 0;
		FinalDamage = 0;
		IsCrit = false;

		printf("아무키나 눌러 적의 주사위를 확인하세요\n");

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
	int PlayerX = 1;
	int PlayerY = 1;
	int Dir = EDirLength;
	Maze[PlayerX][PlayerY] += PLAYER;

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
			if (CanGo[Dir] == false)
			{
				printf("올바른 방향을 입력하세요\n");
				Dir = EDirLength;
			}
		}
		// 4. 다음칸으로 처리 시작
		Maze[PlayerX][PlayerY] -= PLAYER;
		PlayerX += Dx[Dir];
		PlayerY += Dy[Dir];

		// 5. 종료 확인
		if (Maze[PlayerX][PlayerY] == END)
		{
			printf("탈출하였습니다! \n");
			break;
		}

		// 6. 이동처리 종료
		Maze[PlayerX][PlayerY] += PLAYER;

		// 7. 일정확률로 적을 만남 (현재는 한번만 만남, 이래야 테스트 원활)
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
