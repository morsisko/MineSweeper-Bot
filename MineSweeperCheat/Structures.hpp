#pragma once
#include <cstdint>
// Created with ReClass.NET by KN4CK3R

class MineArray
{
public:
	uint32_t size; //0x0000
	char pad_0004[12]; //0x0004
	BYTE* data; //0x0010
	char pad_0018[40]; //0x0018
}; //Size: 0x0040

class SimpleArray
{
public:
	uint32_t size; //0x0000
	char pad_0004[12]; //0x0004
	MineArray** array; //0x0010
	char pad_0018[72]; //0x0018
}; //Size: 0x0060



class GameState
{
public:
	uint64_t vTable; //0x0000
	uint32_t totalMines; //0x0008
	uint32_t xSize; //0x000C
	uint32_t ySize; //0x0010
	uint32_t markedMines; //0x0014
	uint32_t collapsedFields; //0x0018
	uint32_t leftClicked; //0x001C
	float elapsedTime; //0x0020
	char pad_0024[52]; //0x0024
	SimpleArray* simpleArray; //0x0058
	char pad_0060[40]; //0x0060


}; //Size: 0x0088

class MineSweeper
{
public:
	char pad_0000[24]; //0x0000
	GameState* gameState; //0x0018
	char pad_0020[32]; //0x0020
}; //Size: 0x0040




