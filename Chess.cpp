#include "Chess.h"

int chess::PionA(int ox, int oy, int nx, int ny) {
	if (oldPoz.y == 6)
	{
		if ((ny == oy - 1 && nx == ox && board[oy - 1][ox] == 0) || (ny == oy - 2 && nx == ox && board[oy - 1][ox] == 0 && board[oy - 2][ox] == 0))
		{
			return 1;
		}
	}
	else if (ny == oy - 1 && nx == ox && board[oy - 1][ox] == 0)
	{
		return 1;
	}
	if (board[oy - 1][ox - 1] > 0)
	{
		if (ny == oy - 1 && nx == ox - 1)
		{
			return 1;
		}
	}
	if (board[oy - 1][ox + 1] > 0)
	{
		if (ny == oy - 1 && nx == ox + 1)
		{
			return 1;
		}
	}
	return 0;
}

int chess::PionN(int ox, int oy, int nx, int ny) {
	if (oldPoz.y == 1)
	{
		if ((ny == oy + 1 && nx == ox && board[oy + 1][ox] == 0) || (ny == oy + 2 && nx == ox && board[oy + 1][ox] == 0 && board[oy + 2][ox] == 0))
		{
			return 1;
		}
	}
	else if (ny == oy + 1 && nx == ox && board[oy + 1][ox] == 0)
	{
		return 1;
	}
	if (board[oy + 1][ox - 1] < 0)
	{
		if (ny == oy + 1 && nx == ox - 1)
		{
			return 1;
		}
	}
	if (board[oy + 1][ox + 1] < 0)
	{
		if (ny == oy + 1 && nx == ox + 1)
		{
			return 1;
		}
	}
	return 0;
}

int chess::TurnA(int ox, int oy, int nx, int ny) {
	for (int i = ox - 1; i >= 0; i--) // spre stanga
	{
		if (board[oy][i] >= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus
	{
		if (board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // spre dreapta
	{
		if (board[oy][i] >= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // jos
	{
		if (board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int chess::TurnN(int ox, int oy, int nx, int ny) {
	for (int i = ox - 1; i >= 0; i--) // spre stanga
	{
		if (board[oy][i] <= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus
	{
		if (board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // spre dreapta
	{
		if (board[oy][i] <= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // jos
	{
		if (board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int chess::NebunA(int ox, int oy, int nx, int ny){
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // spre dreapta jos
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int chess::NebunN(int ox, int oy, int nx, int ny) {
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // spre dreapta jos
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int chess::ReginaA(int ox, int oy, int nx, int ny) {
	for (int i = ox - 1; i >= 0; i--) // spre stanga
	{
		if (board[oy][i] >= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus
	{
		if (board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // spre dreapta
	{
		if (board[oy][i] >= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // jos
	{
		if (board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // spre dreapta jos
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int chess::ReginaN(int ox, int oy, int nx, int ny) {
	for (int i = ox - 1; i >= 0; i--) // spre stanga
	{
		if (board[oy][i] <= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus
	{
		if (board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // spre dreapta
	{
		if (board[oy][i] <= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // jos
	{
		if (board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // spre dreapta jos
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int chess::CalA(int ox, int oy, int nx, int ny) {
	if (oy - 2 >= 0 && ox - 1 >= 0 && ny == oy - 2 && nx == ox - 1 && board[ny][nx] >= 0)
	{
		return 1; // stanga sus
	}
	if (oy - 2 >= 0 && ox + 1 < LUNGIME && ny == oy - 2 && nx == ox + 1 && board[ny][nx] >= 0)
	{
		return 1; // dreapta sus
	}
	if (oy - 1 >= 0 && ox + 2 < LUNGIME && ny == oy - 1 && nx == ox + 2 && board[ny][nx] >= 0)
	{
		return 1; // dreapta 1
	}
	if (oy + 1 >= 0 && ox + 2 < LUNGIME && ny == oy + 1 && nx == ox + 2 && board[ny][nx] >= 0)
	{
		return 1; // dreapta 2
	}
	if (oy + 2 < LUNGIME && ox + 1 < LUNGIME && ny == oy + 2 && nx == ox + 1 && board[ny][nx] >= 0)
	{
		return 1; // jos 1
	}
	if (oy + 2 < LUNGIME && ox - 1 >= 0 && ny == oy + 2 && nx == ox - 1 && board[ny][nx] >= 0)
	{
		return 1; //jos 2
	}
	if (oy + 1 < LUNGIME && ox - 2 >= 0 && ny == oy + 1 && nx == ox - 2 && board[ny][nx] >= 0)
	{
		return 1; // stanga 1
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && ny == oy - 1 && nx == ox - 2 && board[ny][nx] >= 0)
	{
		return 1;
	}
	return 0;
}

int chess::CalN(int ox, int oy, int nx, int ny) {
	if (oy - 2 >= 0 && ox - 1 >= 0 && ny == oy - 2 && nx == ox - 1 && board[ny][nx] <= 0)
	{
		return 1; // stanga sus
	}
	if (oy - 2 >= 0 && ox + 1 < LUNGIME && ny == oy - 2 && nx == ox + 1 && board[ny][nx] <= 0)
	{
		return 1; // dreapta sus
	}
	if (oy - 1 >= 0 && ox + 2 < LUNGIME && ny == oy - 1 && nx == ox + 2 && board[ny][nx] <= 0)
	{
		return 1; // dreapta 1
	}
	if (oy + 1 >= 0 && ox + 2 < LUNGIME && ny == oy + 1 && nx == ox + 2 && board[ny][nx] <= 0)
	{
		return 1; // dreapta 2
	}
	if (oy + 2 < LUNGIME && ox + 1 < LUNGIME && ny == oy + 2 && nx == ox + 1 && board[ny][nx] <= 0)
	{
		return 1; // jos 1
	}
	if (oy + 2 < LUNGIME && ox - 1 >= 0 && ny == oy + 2 && nx == ox - 1 && board[ny][nx] <= 0)
	{
		return 1; //jos 2
	}
	if (oy + 1 < LUNGIME && ox - 2 >= 0 && ny == oy + 1 && nx == ox - 2 && board[ny][nx] <= 0)
	{
		return 1; // stanga 1
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && ny == oy - 1 && nx == ox - 2 && board[ny][nx] <= 0)
	{
		return 1;
	}
	return 0;
}

int chess::PionASah(int posx, int posy, int regex, int regey) {
	//std::cout << "ox=" << posx << " oy=" << posy << " regex=" << regex << " regey=" << regey << "\n\n\n";
	if (board[posy - 1][posx - 1] >= 0)
	{
		if (posy - 1 == regey && posx - 1 == regex)
		{
			return 1;
		}
	}
	if (board[posy - 1][posx + 1] >= 0)
	{
		//std::cout << "da";
		if (posy - 1 == regey && posx + 1 == regex)
		{
			return 1;
		}
	}
	return 0;
}

int chess::TurnASah(int ox, int oy, int regex, int regey) {
	for (int i = ox - 1; i >= 0; i--) // spre stanga
	{
		if (board[oy][i] >= 0 && (regex == i && regey == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus
	{
		if (board[i][ox] >= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < LUNGIME; i++) // spre dreapta
	{
		if (board[oy][i] >= 0 && (regey == oy && regex == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < LUNGIME; i++) // jos
	{
		if (board[i][ox] >= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int chess::NebunASah(int ox, int oy, int regex, int regey) {
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // spre dreapta jos
	{
		if (board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int chess::ReginaASah(int ox, int oy, int regex, int regey) {
	for (int i = ox - 1; i >= 0; i--) // spre stanga
	{
		if (board[oy][i] >= 0 && (regex == i && regey == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus
	{
		if (board[i][ox] >= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < LUNGIME; i++) // spre dreapta
	{
		if (board[oy][i] >= 0 && (regey == oy && regex == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < LUNGIME; i++) // jos
	{
		if (board[i][ox] >= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i < LUNGIME; i++)  // spre dreapta jos
	{
		if (board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int chess::CalASah(int ox, int oy, int regex, int regey) {
	if (oy - 2 >= 0 && ox - 1 >= 0 && regey == oy - 2 && regex == ox - 1 && board[regey][regex] >= 0)
	{
		return 1; // stanga sus
	}
	if (oy - 2 >= 0 && ox + 1 < LUNGIME && regey == oy - 2 && regex == ox + 1 && board[regey][regex] >= 0)
	{
		return 1; // dreapta sus
	}
	if (oy - 1 >= 0 && ox + 2 < LUNGIME && regey == oy - 1 && regex == ox + 2 && board[regey][regex] >= 0)
	{
		return 1; // dreapta 1
	}
	if (oy + 1 >= 0 && ox + 2 < LUNGIME && regey == oy + 1 && regex == ox + 2 && board[regey][regex] >= 0)
	{
		return 1; // dreapta 2
	}
	if (oy + 2 < LUNGIME && ox + 1 < LUNGIME && regey == oy + 2 && regex == ox + 1 && board[regey][regex] >= 0)
	{
		return 1; // jos 1
	}
	if (oy + 2 < LUNGIME && ox - 1 >= 0 && regey == oy + 2 && regex == ox - 1 && board[regey][regex] >= 0)
	{
		return 1; //jos 2
	}
	if (oy + 1 < LUNGIME && ox - 2 >= 0 && regey == oy + 1 && regex == ox - 2 && board[regey][regex] >= 0)
	{
		return 1; // stanga 1
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && regey == oy - 1 && regex == ox - 2 && board[regey][regex] >= 0)
	{
		return 1;
	}
	return 0;
}

int chess::RegeASah(int ox, int oy, int regex, int regey) {
	if (ox - 1 >= 0 && oy - 1 >= 0 && regey == oy - 1 && regex == ox - 1 && board[regey][regex] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && regex == ox && regey == oy - 1 && board[regey][regex] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 1 < LUNGIME && regex == ox + 1 && regey == oy - 1 && board[regey][regex] <= 0)
	{
		return 1;
	}
	if (ox + 1 < LUNGIME && regey == oy && regex == ox + 1 && board[regey][regex] <= 0)
	{
		return 1;
	}
	if (ox + 1 < LUNGIME && oy + 1 < LUNGIME && regey == oy + 1 && regex == ox + 1 && board[regey][regex] <= 0)
	{
		return 1;
	}
	if (oy + 1 < LUNGIME && regey == oy + 1 && regex == ox && board[regey][regex] <= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && oy + 1 < LUNGIME && regex == ox - 1 && regey == oy + 1 && board[regey][regex] <= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && regey == oy && regex == ox - 1 && board[regey][regex] <= 0)
	{
		return 1;
	}
	return 0;
}

int chess::PionNSah(int ox, int oy, int regex, int regey) {
	if (board[oy + 1][ox - 1] <= 0)
	{
		if (regey == oy + 1 && regex == ox - 1)
		{
			return 1;
		}
	}
	if (board[oy + 1][ox + 1] <= 0)
	{
		if (regey == oy + 1 && regex == ox + 1)
		{
			return 1;
		}
	}
	return 0;
}

int chess::TurnNSah(int ox, int oy, int regex, int regey) {
	for (int i = ox - 1; i >= 0; i--) // spre stanga
	{
		if (board[oy][i] <= 0 && (regex == i && regey == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus
	{
		if (board[i][ox] <= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < LUNGIME; i++) // spre dreapta
	{
		if (board[oy][i] <= 0 && (regey == oy && regex == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < LUNGIME; i++) // jos
	{
		if (board[i][ox] <= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int chess::NebunNSah(int ox, int oy, int regex, int regey) {
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // spre dreapta jos
	{
		if (board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int chess::ReginaNSah(int ox, int oy, int regex, int regey) {
	for (int i = ox - 1; i >= 0; i--) // spre stanga
	{
		if (board[oy][i] <= 0 && (regex == i && regey == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus
	{
		if (board[i][ox] <= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < LUNGIME; i++) // spre dreapta
	{
		if (board[oy][i] <= 0 && (regey == oy && regex == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < LUNGIME; i++) // jos
	{
		if (board[i][ox] <= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i < LUNGIME; i++)  // spre dreapta jos
	{
		if (board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int chess::CalNSah(int ox, int oy, int regex, int regey) {
	if (oy - 2 >= 0 && ox - 1 >= 0 && regey == oy - 2 && regex == ox - 1 && board[regey][regex] <= 0)
	{
		return 1; // stanga sus
	}
	if (oy - 2 >= 0 && ox + 1 < LUNGIME && regey == oy - 2 && regex == ox + 1 && board[regey][regex] <= 0)
	{
		return 1; // dreapta sus
	}
	if (oy - 1 >= 0 && ox + 2 < LUNGIME && regey == oy - 1 && regex == ox + 2 && board[regey][regex] <= 0)
	{
		return 1; // dreapta 1
	}
	if (oy + 1 >= 0 && ox + 2 < LUNGIME && regey == oy + 1 && regex == ox + 2 && board[regey][regex] <= 0)
	{
		return 1; // dreapta 2
	}
	if (oy + 2 < LUNGIME && ox + 1 < LUNGIME && regey == oy + 2 && regex == ox + 1 && board[regey][regex] <= 0)
	{
		return 1; // jos 1
	}
	if (oy + 2 < LUNGIME && ox - 1 >= 0 && regey == oy + 2 && regex == ox - 1 && board[regey][regex] <= 0)
	{
		return 1; //jos 2
	}
	if (oy + 1 < LUNGIME && ox - 2 >= 0 && regey == oy + 1 && regex == ox - 2 && board[regey][regex] <= 0)
	{
		return 1; // stanga 1
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && regey == oy - 1 && regex == ox - 2 && board[regey][regex] <= 0)
	{
		return 1;
	}
	return 0;
}

int chess::RegeNSah(int ox, int oy, int regex, int regey) {
	if (ox - 1 >= 0 && oy - 1 >= 0 && regey == oy - 1 && regex == ox - 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && regex == ox && regey == oy - 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 1 < LUNGIME && regex == ox + 1 && regey == oy - 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (ox + 1 < LUNGIME && regey == oy && regex == ox + 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (ox + 1 < LUNGIME && oy + 1 < LUNGIME && regey == oy + 1 && regex == ox + 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (oy + 1 < LUNGIME && regey == oy + 1 && regex == ox && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && oy + 1 < LUNGIME && regex == ox - 1 && regey == oy + 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && regey == oy && regex == ox - 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	return 0;
}

int chess::RegeNegruSahCheck(int posRegex, int posRegey) {
	int ok = 0;
	for (int i = 0; i < LUNGIME; i++)
	{
		for (int j = 0; j < LUNGIME; j++)
		{
			if (board[i][j] < 0)
			{
				if (board[i][j] == PionALB)
				{
					ok = PionASah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == TurnALB)
				{
					ok = TurnASah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == CalALB)
				{
					ok = CalASah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == NebunALB)
				{
					ok = NebunASah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == ReginaALB)
				{
					ok = ReginaASah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == RegeALB)
				{
					ok = RegeASah(j, i, posRegex, posRegey);
				}
				if (ok == 1)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int chess::RegeN(int ox, int oy, int nx, int ny) {
	if (ox - 1 >= 0 && oy - 1 >= 0 && ny == oy - 1 && nx == ox - 1 && board[ny][nx] <= 0)
	{
		int ok = RegeNegruSahCheck(ox - 1, oy - 1);
		if (ok == 1)
		{
			return 1;  // stanga sus
		}
	}
	if (oy - 1 >= 0 && nx == ox && ny == oy - 1 && board[ny][nx] <= 0)
	{
		int ok = RegeNegruSahCheck(ox, oy - 1);
		if (ok == 1)
		{
			return 1; // sus
		}
	}
	if (oy - 1 >= 0 && ox + 1 < LUNGIME && nx == ox + 1 && ny == oy - 1 && board[ny][nx] <= 0)
	{
		int ok = RegeNegruSahCheck(ox + 1, oy - 1);
		if (ok == 1)
		{
			return 1; // dreapta sus
		}
	}
	if (ox + 1 < LUNGIME && ny == oy && nx == ox + 1 && board[ny][nx] <= 0)
	{
		int ok = RegeNegruSahCheck(ox + 1, oy);
		if (ok == 1)
		{
			return 1; // dreapta
		}
	}
	if (ox + 1 < LUNGIME && oy + 1 < LUNGIME && ny == oy + 1 && nx == ox + 1 && board[ny][nx] <= 0)
	{
		int ok = RegeNegruSahCheck(ox + 1, oy + 1);
		if (ok == 1)
		{
			return 1; // dreapta jos
		}
	}
	if (oy + 1 < LUNGIME && ny == oy + 1 && nx == ox && board[ny][nx] <= 0)
	{
		int ok = RegeNegruSahCheck(ox, oy + 1);
		if (ok == 1)
		{
			return 1; // jos
		}
	}
	if (ox - 1 >= 0 && oy + 1 < LUNGIME && nx == ox - 1 && ny == oy + 1 && board[ny][nx] <= 0)
	{
		int ok = RegeNegruSahCheck(ox - 1, oy + 1);
		if (ok == 1)
		{
			return 1; // stanga jos
		}
	}
	if (ox - 1 >= 0 && ny == oy && nx == ox - 1 && board[ny][nx] <= 0)
	{
		int ok = RegeNegruSahCheck(ox - 1, oy);
		if (ok == 1)
		{
			return 1; // stanga
		}
	}
	// rocada in dreapta
	if (turnNegruDreapta == 0 && regeNegru == 0 && board[0][5] == 0 && board[0][6] == 0 && ny == 0 && nx == 6)
	{
		int ok = RegeNegruSahCheck(4, 0);
		if (ok == 1)
		{
			ok = RegeNegruSahCheck(5, 0);
			if (ok == 1)
			{
				ok = RegeNegruSahCheck(6, 0);
				if (ok == 1)
				{
					regeNegru = 1;
					turnNegruDreapta = 1;
					board[0][7] = 0;
					board[0][5] = TurnNEGRU;
					return 1;
				}
			}
		}
	}
	if (turnNegruStanga == 0 && regeNegru == 0 && board[0][3] == 0 && board[0][2] == 0 && board[0][1] == 0 && ny == 0 && nx == 2)
	{
		int ok = RegeNegruSahCheck(4, 0);
		if (ok == 1)
		{
			ok = RegeNegruSahCheck(3, 0);
			if (ok == 1)
			{
				ok = RegeNegruSahCheck(2, 0);
				if (ok == 1)
				{
					ok = RegeNegruSahCheck(1, 0);
					if (ok == 1)
					{
						regeNegru = 1;
						turnNegruStanga = 1;
						board[0][0] = 0;
						board[0][3] = TurnNEGRU;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int chess::RegeAlbSahCheck(int posRegex, int posRegey) {
	int ok = 0;
	for (int i = 0; i < LUNGIME; i++)
	{
		for (int j = 0; j < LUNGIME; j++)
		{
			if (board[i][j] > 0)
			{
				if (board[i][j] == PionNEGRU)
				{
					ok = PionNSah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == TurnNEGRU)
				{
					ok = TurnNSah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == CalNEGRU)
				{
					ok = CalNSah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == NebunNEGRU)
				{
					ok = NebunNSah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == ReginaNEGRU)
				{
					ok = ReginaNSah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == RegeNEGRU)
				{
					ok = RegeNSah(j, i, posRegex, posRegey);
				}
				if (ok == 1)
				{
					//	std::cout << "da" << "\n";
					return 0;
				}
			}
		}
	}
	return 1;
}

int chess::RegeA(int ox, int oy, int nx, int ny) {
	if (ox - 1 >= 0 && oy - 1 >= 0 && ny == oy - 1 && nx == ox - 1 && board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox - 1, oy - 1);
		if (ok == 1)
		{
			return 1;  // stanga sus
		}
	}
	if (oy - 1 >= 0 && nx == ox && ny == oy - 1 && board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox, oy - 1);
		if (ok == 1)
		{
			return 1; // sus
		}
	}
	if (oy - 1 >= 0 && ox + 1 < LUNGIME && nx == ox + 1 && ny == oy - 1 && board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox + 1, oy - 1);
		if (ok == 1)
		{
			return 1; // dreapta sus
		}
	}
	if (ox + 1 < LUNGIME && ny == oy && nx == ox + 1 && board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox + 1, oy);
		if (ok == 1)
		{
			return 1; // dreapta
		}
	}
	if (ox + 1 < LUNGIME && oy + 1 < LUNGIME && ny == oy + 1 && nx == ox + 1 && board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox + 1, oy + 1);
		if (ok == 1)
		{
			return 1; // dreapta jos
		}
	}
	if (oy + 1 < LUNGIME && ny == oy + 1 && nx == ox && board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox, oy + 1);
		if (ok == 1)
		{
			return 1; // jos
		}
	}
	if (ox - 1 >= 0 && oy + 1 < LUNGIME && nx == ox - 1 && ny == oy + 1 && board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox - 1, oy + 1);
		if (ok == 1)
		{
			return 1; // stanga jos
		}
	}
	if (ox - 1 >= 0 && ny == oy && nx == ox - 1 && board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox - 1, oy);
		if (ok == 1)
		{
			return 1; // stanga
		}
	}
	// rocada in dreapta
	if (regeAlb == 0 && turnAlbDreapta == 0 && board[7][5] == 0 && board[7][6] == 0 && ny == 7 && nx == 6)
	{
		int ok = 1;
		ok = RegeAlbSahCheck(4, 7);
		if (ok == 1)
		{
			ok = RegeAlbSahCheck(5, 7);
			if (ok == 1)
			{
				ok = RegeAlbSahCheck(6, 7);
				if (ok == 1)
				{
					board[7][7] = 0;
					board[7][5] = TurnALB;
					regeAlb = 1;
					turnAlbDreapta = 1;
					return 1;
				}
			}
		}
	}
	// rocada in stanga
	if (regeAlb == 0 && turnAlbDreapta == 0 && board[7][3] == 0 && board[7][2] == 0 && board[7][1] == 0 && ny == 7 && nx == 2)
	{
		int ok = 1;
		ok = RegeAlbSahCheck(4, 7);
		if (ok == 1)
		{
			ok = RegeAlbSahCheck(3, 7);
			if (ok == 1)
			{
				ok = RegeAlbSahCheck(2, 7);
				if (ok == 1)
				{
					ok = RegeAlbSahCheck(1, 7);
					if (ok == 1)
					{
						board[7][0] = 0;
						board[7][3] = TurnALB;
						regeAlb = 1;
						turnAlbStanga = 1;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

void chess::pozRegeAlb() {
	for (int i = 0; i < LUNGIME; i++)
	{
		for (int j = 0; j < LUNGIME; j++)
		{
			if (board[i][j] == RegeALB)
			{
				regeleAlb.x = j;
				regeleAlb.y = i;
				break;
			}
		}
	}
}

void chess::pozRegeNegru() {
	for (int i = 0; i < LUNGIME; i++)
	{
		for (int j = 0; j < LUNGIME; j++)
		{
			if (board[i][j] == RegeNEGRU)
			{
				regeleNegru.y = i;
				regeleNegru.x = j;
				break;
			}
		}
	}
}