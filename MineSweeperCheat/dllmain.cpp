#include <Windows.h>
#include <iostream>
#include "Structures.hpp"

DWORD WINAPI DllStart(LPVOID param)
{
	std::cout << "****************************" << std::endl;
	std::cout << "MineSweeper x64 - Mine detector by morsisko" << std::endl;
	std::cout << "****************************" << std::endl << std::endl << std::endl;

	MineSweeper* mineSweeper = *(MineSweeper**)((DWORD)GetModuleHandleA("minesweeper.exe") + 0xAAA38);
	GameState* gameState = mineSweeper->gameState;
	SimpleArray* simpleArray = gameState->simpleArray;

	for (int i = 0; i != gameState->xSize; ++i)
	{
		for (int j = 0; j != gameState->ySize; j++)
		{
			MineArray* mineArray = simpleArray->array[j];
			std::cout << (int)mineArray->data[i];
		}
		std::cout << std::endl;
	}
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		AllocConsole();
		freopen("CONOUT$", "w", stdout);
		CreateThread(0, 0, DllStart, 0, 0, 0);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

