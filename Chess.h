#pragma once

#define LUNGIME 8
#define PionNEGRU 1
#define PionALB -1
#define TurnNEGRU 2
#define TurnALB -2
#define CalALB -3
#define CalNEGRU 3
#define NebunNEGRU 4
#define NebunALB -4
#define ReginaALB -5
#define ReginaNEGRU 5
#define RegeNEGRU 6
#define RegeALB -6

struct poz
{
	int x, y;
} oldPoz, regeleAlb, regeleNegru, transformA, transformN;

class chess {
public:
	int  size = 100, move = 0, x, y;
	int board[8][8] =
	{ 2, 3, 4, 5, 6, 4, 3, 2,
	  1, 1, 1, 1, 1, 1, 1, 1,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	 -1,-1,-1,-1,-1,-1,-1,-1,
	 -2,-3,-4,-5,-6,-4,-3,-2, };

	int turnAlbDreapta = 0, turnAlbStanga = 0, regeAlb = 0;
	int turnNegruDreapta = 0, turnNegruStanga = 0, regeNegru = 0;

	int mutare = 0; 

	int sahAlb = 0, sahNegru = 0;

	int transformareAlb = 0, transformareNegru = 0;

public:

	int PionA(int ox, int oy, int nx, int ny);
	int PionN(int ox, int oy, int nx, int ny);
	int TurnA(int ox, int oy, int nx, int ny);
	int TurnN(int ox, int oy, int nx, int ny);
	int NebunA(int ox, int oy, int nx, int ny);
	int NebunN(int ox, int oy, int nx, int ny);
	int ReginaA(int ox, int oy, int nx, int ny);
	int ReginaN(int ox, int oy, int nx, int ny);
	int CalA(int ox, int oy, int nx, int ny);
	int CalN(int ox, int oy, int nx, int ny);
	int PionASah(int posx, int posy, int regex, int regey);
	int TurnASah(int ox, int oy, int regex, int regey);
	int NebunASah(int ox, int oy, int regex, int regey);
	int ReginaASah(int ox, int oy, int regex, int regey);
	int CalASah(int ox, int oy, int regex, int regey);
	int RegeASah(int ox, int oy, int regex, int regey);
	int PionNSah(int ox, int oy, int regex, int regey);
	int TurnNSah(int ox, int oy, int regex, int regey);
	int NebunNSah(int ox, int oy, int regex, int regey);
	int ReginaNSah(int ox, int oy, int regex, int regey);
	int CalNSah(int ox, int oy, int regex, int regey);
	int RegeNSah(int ox, int oy, int regex, int regey);
	int RegeNegruSahCheck(int posRegex, int posRegey);
	int RegeN(int ox, int oy, int nx, int ny);
	int RegeAlbSahCheck(int posRegex, int posRegey);
	int RegeA(int ox, int oy, int nx, int ny);
	void pozRegeAlb();
	void pozRegeNegru();
	
};