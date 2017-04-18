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
	SimpleArray<SimpleArray<BYTE>*>* simpleArray = gameState->simpleArray;
	SimpleArray<SimpleArray<int>*>* flagsArray = gameState->flagsArray;
	GraphicArray* graphicArray = mineSweeper->graphicArray;

	for (int i = 0; i != gameState->xSize; ++i)
	{
		for (int j = 0; j != gameState->ySize; j++)
		{
			bool isMine = simpleArray->array[j]->array[i];
			std::cout << isMine;

			if (isMine)
			{
				flagsArray->array[j]->array[i] = 0xA;
				graphicArray->data[j]->array[i]->needUpdate = 1;
				gameState->markedMines++;
			}
		}
		std::cout << std::endl;
	}
	
	graphicArray->shouldUpdate = 1;
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

