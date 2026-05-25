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
/// 슬롯머신을을 시작하는(당기는) 함수
/// </summary>
/// <param name="Slots">슬롯 배열</param>
/// <param name="Length">슬롯 배열의 길이</param>
/// <param name="SlotMin">각 슬롯의 최솟값</param>
/// <param name="SlotMax">각 슬롯의 최댓값</param>
void StartSlot(int* Slots, int Length, int SlotMin, int SlotMax);

/// <summary>
/// 슬롯머신 결과에 따른 상금 비율을 정하고 반환합니다.
/// </summary>
/// <param name="Slots">슬롯 배열</param>
/// <param name="Length">슬롯 배열의길이</param>
/// <returns>일반 잭판은 JPTation, 777 잭팟은 T7Ratio, 꽝은 NoPrize를 반환합니다. </returns>
int SelectPrizeRatio(int* Slots, int Length);

/// <summary>
/// 현재 슬롯머신의 상태를 출력합니다.
/// </summary>
/// <param name="Slots">슬롯 배열</param>
/// <param name="Length">슬롯 배열의길이</param>
void PrintSlot(int* Slots, int Length);
/// <summary>
/// 축하메시지를 출력하는 함수 입니다. 상금 비율에 따라 메시지가 달라집니다.
/// </summary>
/// <param name="PrizeRatio">상금 비율</param>
void PrintCongratMsg(int PrizeRatio);
void Homework03_Run();