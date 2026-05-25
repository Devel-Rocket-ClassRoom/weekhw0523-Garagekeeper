#pragma once

/// <summary>
/// Min 부터 Max사이의 랜덤 값을 반환하는 함수
/// </summary>
/// <param name="Min">랜덤값의 최소</param>
/// <param name="Max">랜덤값의 최대</param>
/// <returns>Min 부터 Max사이의 랜덤 값</returns>
int RandomRange(int Min, int Max);

/// <summary>
/// 0 부터 Max사이의 랜덤 값을 반환하는 함수
/// </summary>
/// <param name="Max">랜덤값의 최대</param>
/// <returns>0 부터 Max사이의 랜덤 값</returns>
int RandomRange(int Max);


/// <summary>
/// 맵을 출력하는 함수
/// </summary>
void Print2DMap();
/// <summary>
/// 주어진 좌표를 기준으로 상하좌우로 갈 수 있는지 판단하는 함수
/// </summary>
/// <param name="DirArr">상하좌우의 가능여부를 담는 배열</param>
/// <param name="PlayerX">플레이어의 X좌표</param>
/// <param name="PlayerY">플레이어의 ㅛ좌표</param>
void CheckDirCanGO(bool* DirArr, int PlayerX, int PlayerY);

/// <summary>
/// 이동할 수 있는 방향을 출력하는 함수
/// </summary>
/// <param name="DirArr">상하좌우의 가능여부를 담는 배열</param>
void PrintChoiceScreen(bool* DirArr);

/// <summary>
/// 방향을 입력받는 함수 (wasd로 입력받아 방향값으로 반환)
/// </summary>
/// <returns>입력받은 방향</returns>
int GetDirInput();

/// <summary>
/// 적을 만나는지의 여부를 반환하는
/// </summary>
/// <returns> 적을 만나는지 여부</returns>
bool RandEncounter();

/// <summary>
/// 나와 몬스터의 체력을 출력하는 함수
/// </summary>
/// <param name="YoursHp">당신의 체력</param>
/// <param name="MonstersHP">몬스터의 체력</param>
void PrintHP(int YoursHp, int MonstersHP);

/// <summary>
/// DiceMax면체의 주사위를 굴려서 반환하는 함수
/// </summary>
/// <param name="DiceMax">주사위의 최대값</param>
/// <returns></returns>
int RollDice(int DiceMax);

/// <summary>
/// 공격 데미지를 계산해서 반환하는 함수
/// </summary>
/// <param name="BaseDamage">기본 데미지</param>
/// <param name="DiceMax">주사위의 최대값</param>
/// <returns></returns>
int GetAttackDamage(int BaseDamage, int DiceMax);

/// <summary>
/// 크리티컬의 적용여부 반환
/// </summary>
/// <param name="CriticalPercentage">크리티컬 페선테이지</param>
/// <returns>크리티컬 여부</returns>
bool IsCritical(int CriticalPercentage);
/// <summary>
/// 턴제 전투를 진행하는 함수
/// </summary>
/// <returns>승리 여부</returns>
bool TurnBasedCombat();
void Homework05_Run();