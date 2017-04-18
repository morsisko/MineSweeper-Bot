#pragma once
#include <cstdint>
// Created with ReClass.NET by KN4CK3R

template <class T>
class SimpleArray
{
public:
	uint32_t size; //0x0000
	char pad_0004[12]; //0x0004
	T* array; //0x0010
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
	char pad_0024[44]; //0x0024
	SimpleArray<SimpleArray<int>*>* flagsArray; //0x0050
	SimpleArray<SimpleArray<BYTE>*>* simpleArray; //0x0058
	char pad_0060[48]; //0x0060
}; //Size: 0x0090

class GraphicField
{
public:
	char pad_0000[64]; //0x0000
	bool needUpdate; //0x0040
	char pad_0041[7]; //0x0041
}; //Size: 0x0048

class GraphicArray
{
public:
	char pad_0000[24]; //0x0000
	SimpleArray<GraphicField*>** data; //0x0018
	char pad_0020[244]; //0x0020
	uint8_t shouldUpdate; //0x0114
	char pad_0115[3]; //0x0115
}; //Size: 0x0118



class MineSweeper
{
public:
	char pad_0000[16]; //0x0000
	GraphicArray* graphicArray; //0x0010
	GameState* gameState; //0x0018
	char pad_0020[32]; //0x0020
}; //Size: 0x0040





