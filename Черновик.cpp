#include <SFML/Graphics.hpp>
#include <iostream>
#include "Chess.h"

using namespace sf;

int main()
{

	class chess chess;

	RenderWindow window(VideoMode(800, 800), "Chess");

	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;

	t1.loadFromFile("images/Board.png");
	t2.loadFromFile("images/PionNegru.png");
	t3.loadFromFile("images/PionAlb.png");
	t4.loadFromFile("images/TurnNegru.png");
	t5.loadFromFile("images/TurnAlb.png");
	t6.loadFromFile("images/CalAlb.png");
	t7.loadFromFile("images/CalNegru.png");
	t8.loadFromFile("images/NebunNegru.png");
	t9.loadFromFile("images/NebunAlb.png");
	t10.loadFromFile("images/ReginaAlb.png");
	t11.loadFromFile("images/ReginaNegru.png");
	t12.loadFromFile("images/RegeNegru.png");
	t13.loadFromFile("images/RegeAlb.png");
	t14.loadFromFile("images/TransformareAlb.png");
	t15.loadFromFile("images/TransformareNegru.png");

	Sprite tabla(t1);
	Sprite PionNegru(t2);
	Sprite PionAlb(t3);
	Sprite TurnNegru(t4);
	Sprite TurnAlb(t5);
	Sprite CalAlb(t6);
	Sprite CalNegru(t7);
	Sprite NebunNegru(t8);
	Sprite NebunAlb(t9);
	Sprite ReginaAlb(t10);
	Sprite ReginaNegru(t11);
	Sprite RegeNegru(t12);
	Sprite RegeAlb(t13);
	Sprite Mutare;
	Sprite TransformareALB(t14);
	Sprite TransformareNEGRU(t15);

	float dx = 0, dy = 0;
	int numarPiesaMutata = 0;

	while (window.isOpen())
	{
		Vector2i pos = Mouse::getPosition(window);
		chess.x = pos.x / chess.size;
		chess.y = pos.y / chess.size;
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			window.clear();
			if (e.type == Event::MouseButtonPressed)
			{
				if (e.key.code == Mouse::Left)
				{
					//std::cout << "x=" << x << " y=" << y << "\n";
					//std::cout << "pos_x=" << pos.x << " pos_y=" << pos.y << "\n";
					//std::cout << "board[y][x]=" << board[y][x] << "\n";
					//std::cout << "\n";
					if (chess.transformareAlb == 1)
					{
						if (pos.y >= transformA.y * chess.size && pos.y <= (transformA.y + 1) * chess.size && pos.x >= transformA.x * chess.size && pos.x <= (transformA.x + 1) * chess.size)
						{
							int xx = pos.x % 100, yy = pos.y % 100;
							//std::cout << "pos.y=" << yy << "\n";
							//std::cout << "pos.x=" << xx << "\n";
							if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
							{
								chess.board[transformA.y][transformA.x] = TurnALB;
								chess.transformareAlb = 0;
							}
							if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
							{
								chess.board[transformA.y][transformA.x] = ReginaALB;
								chess.transformareAlb = 0;
							}
							if (xx > 50 && xx < 100 && yy>50 && yy < 100)
							{
								chess.board[transformA.y][transformA.x] = CalALB;
								chess.transformareAlb = 0;
							}
							if (xx < 50 && xx>0 && yy > 50 && chess.y < 100)
							{
								chess.board[transformA.y][transformA.x] = NebunALB;
								chess.transformareAlb = 0;
							}
							if (chess.transformareAlb == 0)
							{
								chess.pozRegeNegru();
								int h = chess.RegeNegruSahCheck(regeleNegru.x, regeleNegru.y);
								if (h == 0)
								{
									chess.sahNegru = 1;
								}
							}
						}
					}
					if (chess.transformareNegru == 1)
					{
						if (pos.y >= transformN.y * chess.size && pos.y <= (transformN.y + 1) * chess.size && pos.x >= transformN.x * chess.size && pos.x <= (transformN.x + 1) * chess.size)
						{
							int xx = pos.x % 100, yy = pos.y % 100;
							//std::cout << "pos.y=" << yy << "\n";
							//std::cout << "pos.x=" << xx << "\n";
							if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
							{
								chess.board[transformN.y][transformN.x] = TurnNEGRU;
								chess.transformareNegru = 0;
							}
							if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
							{
								chess.board[transformN.y][transformN.x] = ReginaNEGRU;
								chess.transformareNegru = 0;
							}
							if (xx > 50 && xx < 100 && yy>50 && yy < 100)
							{
								chess.board[transformN.y][transformN.x] = CalNEGRU;
								chess.transformareNegru = 0;
							}
							if (xx < 50 && xx>0 && yy > 50 && chess.y < 100)
							{
								chess.board[transformN.y][transformN.x] = NebunNEGRU;
								chess.transformareNegru = 0;
							}
							if (chess.transformareNegru == 0)
							{
								chess.pozRegeAlb();
								int h = chess.RegeAlbSahCheck(regeleAlb.x, regeleAlb.y);
								if (h == 0)
								{
									chess.sahAlb = 1;
								}
							}
						}
					}
					if (chess.board[chess.y][chess.x] != 0)
					{
						dx = pos.x - chess.x * 100;
						dy = pos.y - chess.y * 100;
						if (chess.board[chess.y][chess.x] == PionNEGRU && chess.mutare == 1)
						{
							numarPiesaMutata = PionNEGRU;
							Mutare = PionNegru;
							chess.board[chess.y][chess.x] = 0;
						}
						if (chess.board[chess.y][chess.x] == PionALB && chess.mutare == 0)
						{
							numarPiesaMutata = PionALB;
							Mutare = PionAlb;
							chess.board[chess.y][chess.x] = 0;
						}
						if (chess.board[chess.y][chess.x] == TurnNEGRU && chess.mutare == 1)
						{
							numarPiesaMutata = TurnNEGRU;
							Mutare = TurnNegru;
							chess.board[chess.y][chess.x] = 0;

						}
						if (chess.board[chess.y][chess.x] == TurnALB && chess.mutare == 0)
						{
							numarPiesaMutata = TurnALB;
							Mutare = TurnAlb;
							chess.board[chess.y][chess.x] = 0;

						}
						if (chess.board[chess.y][chess.x] == CalALB && chess.mutare == 0)
						{
							numarPiesaMutata = CalALB;
							Mutare = CalAlb;
							chess.board[chess.y][chess.x] = 0;
						}
						if (chess.board[chess.y][chess.x] == CalNEGRU && chess.mutare == 1)
						{
							numarPiesaMutata = CalNEGRU;
							Mutare = CalNegru;
							chess.board[chess.y][chess.x] = 0;
						}
						if (chess.board[chess.y][chess.x] == NebunNEGRU && chess.mutare == 1)
						{
							numarPiesaMutata = NebunNEGRU;
							Mutare = NebunNegru;
							chess.board[chess.y][chess.x] = 0;
						}
						if (chess.board[chess.y][chess.x] == NebunALB && chess.mutare == 0)
						{
							numarPiesaMutata = NebunALB;
							Mutare = NebunAlb;
							chess.board[chess.y][chess.x] = 0;
						}
						if (chess.board[chess.y][chess.x] == ReginaALB && chess.mutare == 0)
						{
							numarPiesaMutata = ReginaALB;
							Mutare = ReginaAlb;
							chess.board[chess.y][chess.x] = 0;
						}
						if (chess.board[chess.y][chess.x] == ReginaNEGRU && chess.mutare == 1)
						{
							numarPiesaMutata = ReginaNEGRU;
							Mutare = ReginaNegru;
							chess.board[chess.y][chess.x] = 0;
						}
						if (chess.board[chess.y][chess.x] == RegeNEGRU && chess.mutare == 1)
						{
							numarPiesaMutata = RegeNEGRU;
							Mutare = RegeNegru;
							chess.board[chess.y][chess.x] = 0;
						}
						if (chess.board[chess.y][chess.x] == RegeALB && chess.mutare == 0)
						{
							numarPiesaMutata = RegeALB;
							Mutare = RegeAlb;
							chess.board[chess.y][chess.x] = 0;
						}
						if (chess.board[chess.y][chess.x] == 0)
						{
							chess.move = 1;
							oldPoz.x = chess.x;
							oldPoz.y = chess.y;
						}
					}
				}
			}
			if (e.type == Event::MouseButtonReleased)
			{
				if (e.key.code == Mouse::Left)
				{
					int ok = 2;
					if (numarPiesaMutata == PionALB && chess.move == 1)
					{
						ok = chess.PionA(oldPoz.x, oldPoz.y, chess.x, chess.y);
					}
					if (numarPiesaMutata == PionNEGRU && chess.move == 1)
					{
						ok = chess.PionN(oldPoz.x, oldPoz.y, chess.x, chess.y);
					}
					if (numarPiesaMutata == TurnALB && chess.move == 1)
					{
						ok = chess.TurnA(oldPoz.x, oldPoz.y, chess.x, chess.y);
						if (ok == 1 && chess.turnAlbStanga == 0 && oldPoz.y == 7 && oldPoz.x == 0)
						{
							chess.turnAlbStanga = 1;
							//std::cout << turnAlbStanga << "\n";
						}
						if (ok == 1 && chess.turnAlbDreapta == 0 && oldPoz.y == 7 && oldPoz.x == 7)
						{
							chess.turnAlbDreapta = 1;
							//std::cout << turnAlbDreapta << "\n";
						}
					}
					if (numarPiesaMutata == TurnNEGRU && chess.move == 1)
					{
						ok = chess.TurnN(oldPoz.x, oldPoz.y, chess.x, chess.y);
						if (ok == 1 && chess.turnNegruDreapta == 0 && oldPoz.y == 0 && oldPoz.x == 7)
						{
							chess.turnNegruDreapta = 1;
							//std::cout << turnNegruDreapta<< "\n";
						}
						if (ok == 1 && chess.turnNegruStanga == 0 && oldPoz.y == 0 && oldPoz.x == 0)
						{
							chess.turnNegruStanga = 1;
							//std::cout << turnNegruStanga << "\n";
						}
					}
					if (numarPiesaMutata == NebunALB && chess.move == 1)
					{
						ok = chess.NebunA(oldPoz.x, oldPoz.y, chess.x, chess.y);
					}
					if (numarPiesaMutata == NebunNEGRU && chess.move == 1)
					{
						ok = chess.NebunN(oldPoz.x, oldPoz.y, chess.x, chess.y);
					}
					if (numarPiesaMutata == ReginaALB && chess.move == 1)
					{
						ok = chess.ReginaA(oldPoz.x, oldPoz.y, chess.x, chess.y);
					}
					if (numarPiesaMutata == ReginaNEGRU && chess.move == 1)
					{
						ok = chess.ReginaN(oldPoz.x, oldPoz.y, chess.x, chess.y);
					}
					if (numarPiesaMutata == CalALB && chess.move == 1)
					{
						ok = chess.CalA(oldPoz.x, oldPoz.y, chess.x, chess.y);
					}
					if (numarPiesaMutata == CalNEGRU && chess.move == 1)
					{
						ok = chess.CalN(oldPoz.x, oldPoz.y, chess.x, chess.y);
					}
					if (numarPiesaMutata == RegeNEGRU && chess.move == 1)
					{
						ok = chess.RegeN(oldPoz.x, oldPoz.y, chess.x, chess.y);
						if (ok == 1 && chess.regeNegru == 0)
						{
							chess.regeNegru = 1;
							//	std::cout << regeNegru << "\n";
						}
					}
					if (numarPiesaMutata == RegeALB && chess.move == 1)
					{
						ok = chess.RegeA(oldPoz.x, oldPoz.y, chess.x, chess.y);
						if (ok == 1 && chess.regeAlb == 0)
						{
							chess.regeAlb = 1;
							//std::cout << "primaMutareREGEalb=" << regeAlb << "\n";
						}
					}
					if (ok == 1)
					{
						int nr = chess.board[chess.y][chess.x];
						chess.board[chess.y][chess.x] = numarPiesaMutata;
						if (chess.y == 0 && numarPiesaMutata == PionALB)
						{
							chess.transformareAlb = 1;
							transformA.x = chess.x;
							transformA.y = chess.y;
							chess.board[chess.y][chess.x] = 0;
						}
						if (chess.y == 7 && numarPiesaMutata == PionNEGRU)
						{
							chess.transformareNegru = 1;
							transformN.x = chess.x;
							transformN.y = chess.y;
							chess.board[chess.y][chess.x] = 0;
						}
						if (chess.mutare == 0) // albul a mutat si urmeaza negrul
						{
							if (chess.sahAlb == 1)
							{
								chess.pozRegeAlb();
								int s = chess.RegeAlbSahCheck(regeleAlb.x, regeleAlb.y);
								if (s == 0)
								{
									chess.board[oldPoz.y][oldPoz.x] = numarPiesaMutata;
									chess.board[chess.y][chess.x] = nr;
								}
								else
								{
									chess.sahAlb = 0;
									chess.pozRegeNegru();
									int sah = chess.RegeNegruSahCheck(regeleNegru.x, regeleNegru.y);
									if (sah == 0)
									{
										chess.sahNegru = 1;
									}
									chess.mutare = 1;
								}
							}
							else
							{
								chess.pozRegeAlb();
								int sa = chess.RegeAlbSahCheck(regeleAlb.x, regeleAlb.y);
								if (sa == 0)
								{
									chess.board[oldPoz.y][oldPoz.x] = numarPiesaMutata;
									chess.board[chess.y][chess.x] = nr;
								}
								else
								{
									chess.pozRegeNegru();
									int sah = chess.RegeNegruSahCheck(regeleNegru.x, regeleNegru.y);
									if (sah == 0)
									{
										chess.sahNegru = 1;
									}
									chess.mutare = 1;
								}
							}
						}
						else // negrul a mutat si urmeaza albul
						{
							if (chess.sahNegru == 1)
							{
								chess.pozRegeNegru();
								int s = chess.RegeNegruSahCheck(regeleNegru.x, regeleNegru.y);
								if (s == 0)
								{
									chess.board[oldPoz.y][oldPoz.x] = numarPiesaMutata;
									chess.board[chess.y][chess.x] = nr;
								}
								else
								{
									chess.sahNegru = 0;
									chess.pozRegeAlb();
									int sah = chess.RegeAlbSahCheck(regeleAlb.x, regeleAlb.y);
									if (sah == 0)
									{
										chess.sahAlb = 1;
									}
									chess.mutare = 0;
								}
							}
							else
							{
								chess.pozRegeNegru();
								int sa = chess.RegeNegruSahCheck(regeleNegru.x, regeleNegru.y);
								if (sa == 0)
								{
									chess.board[oldPoz.y][oldPoz.x] = numarPiesaMutata;
									chess.board[chess.y][chess.x] = nr;
								}
								else
								{
									chess.pozRegeAlb();
									int sah = chess.RegeAlbSahCheck(regeleAlb.x, regeleAlb.y);
									if (sah == 0)
									{
										chess.sahAlb = 1;
									}
									chess.mutare = 0;
								}
							}
						}
					}
					else if (ok == 0)
					{
						chess.board[oldPoz.y][oldPoz.x] = numarPiesaMutata;
					}
					chess.move = 0;
				}
			}
		}
		// afisare //
		window.clear();
		window.draw(tabla);
		if (chess.transformareAlb == 1)
		{
			TransformareALB.setPosition(transformA.x * chess.size, transformA.y * chess.size);
			window.draw(TransformareALB);
		}
		if (chess.transformareNegru == 1)
		{
			TransformareNEGRU.setPosition(transformN.x * chess.size, transformN.y * chess.size);
			window.draw(TransformareNEGRU);
		}
		if (chess.move == 1)
		{
			Mutare.setPosition(pos.x - dx, pos.y - dy);
			window.draw(Mutare);
		}
		for (int i = 0; i < LUNGIME; i++)
		{
			for (int j = 0; j < LUNGIME; j++)
			{

				if (chess.board[i][j] != 0)
				{
					if (chess.board[i][j] == PionNEGRU)
					{
						PionNegru.setPosition(j * chess.size, i * chess.size);
						window.draw(PionNegru);
					}
					if (chess.board[i][j] == PionALB)
					{
						PionAlb.setPosition(j * chess.size, i * chess.size);
						window.draw(PionAlb);
					}
					if (chess.board[i][j] == TurnNEGRU)
					{
						TurnNegru.setPosition(j * chess.size, i * chess.size);
						window.draw(TurnNegru);

					}
					if (chess.board[i][j] == TurnALB)
					{
						TurnAlb.setPosition(j * chess.size, i * chess.size);
						window.draw(TurnAlb);

					}
					if (chess.board[i][j] == CalALB)
					{
						CalAlb.setPosition(j * chess.size, i * chess.size);
						window.draw(CalAlb);
					}
					if (chess.board[i][j] == CalNEGRU)
					{
						CalNegru.setPosition(j * chess.size, i * chess.size);
						window.draw(CalNegru);
					}
					if (chess.board[i][j] == NebunNEGRU)
					{
						NebunNegru.setPosition(j * chess.size, i * chess.size);
						window.draw(NebunNegru);
					}
					if (chess.board[i][j] == NebunALB)
					{
						NebunAlb.setPosition(j * chess.size, i * chess.size);
						window.draw(NebunAlb);
					}
					if (chess.board[i][j] == ReginaALB)
					{
						ReginaAlb.setPosition(j * chess.size, i * chess.size);
						window.draw(ReginaAlb);
					}
					if (chess.board[i][j] == ReginaNEGRU)
					{
						ReginaNegru.setPosition(j * chess.size, i * chess.size);
						window.draw(ReginaNegru);
					}
					if (chess.board[i][j] == RegeNEGRU)
					{
						RegeNegru.setPosition(j * chess.size, i * chess.size);
						window.draw(RegeNegru);
					}
					if (chess.board[i][j] == RegeALB)
					{
						RegeAlb.setPosition(j * chess.size, i * chess.size);
						window.draw(RegeAlb);
					}
				}
			}
		}
		window.display();
	}
	return 0;
}