#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

enum Cell {
	EMPTY,
	RED,
	YELLOW
};

const int di[] = { 1, 0, 1, 1 }; // с помощью этого массива двигаемся по строке 
const int dj[] = { 0, 1, -1, 1 }; // с помощью этого - по столбцам
// к примеру 1, 0 позволяет пройти по горизонтали
// 0, 1 позволяет идти по вертикали
// 1, -1 позволяет идти по обратной диагонали
// 1, 1 позволяет идти по обычной диагонали

class Field {

private:
	int FIELD_WIDTH = 6;
	int FIELD_HEIGHT = 7;
	Cell cells[6][7];
	bool isRedTurn; // очередь хода
	Cell winner; // кто победитель
	const int DIR_NUMBER = 4;
	const int WIN_LENGTH = 4;

public:
	//Field(bool isRedFirst); // constructor done
	//void clear(bool isRedFirst); // функция очистки поля после законченной игры done
	//bool makeTurn(int column); // функция хода done
	//bool isWon(bool red) const; // функция, проверяющая выиграл ли кто-то done
	//bool isOver() const; // функция, проверяющая закончилась ли игра done
	//Cell getCell(int i, int j) const; // функция, получающая клетку поля
	//bool isRedTurnNow() const; // функция, проверяющая, кто ходит в данный момент done
	//void print() const; // вывод поля done
	//void printResult() const; // вывод результатов 

	Field(bool isRedFirst) {
		clear(isRedFirst);
	}

	void clear(bool isRedFirst) // очистка поля, сразу же задаем очередность 
	{
		isRedTurn = isRedFirst;
		winner = EMPTY;
		for (int i = 0; i < FIELD_WIDTH; i++)
			for (int j = 0; j < FIELD_HEIGHT; j++)
				cells[i][j] = EMPTY;
	}

	void checkWinner() // проверка на победителя
	{
		for (int i = 0; i < FIELD_WIDTH; i++)
			for (int j = 0; j < FIELD_HEIGHT; j++)
			{
				Cell start = getCell(i, j);
				if (start == EMPTY) continue;
				for (int dir = 0; dir < DIR_NUMBER; dir++)
				{
					int length = 0, iline = i, jline = j;
					while (++length < WIN_LENGTH)
					{
						iline += di[dir];
						jline += dj[dir];
						if (iline < 0 || iline >= FIELD_WIDTH ||
							jline < 0 || jline >= FIELD_HEIGHT) // предотвращение выхода за пределы поля
							break;
						if (getCell(iline, jline) != start) break; // если следующая ячейка не равна стартовой - нет смысла проверять дальше
					}
					if (length == WIN_LENGTH) // если есть 4 в ряд, то объявляем виннера через ячейку
					{
						winner = start;
						return;
					}
				}
			}
	}

	bool isOver() const
	{
		if (winner != EMPTY)
			return true;
		for (int i = 0; i < FIELD_WIDTH; i++)
			for (int j = 0; j < FIELD_HEIGHT; j++)
				// Если хоть одна ячейка свободна,
				// игра не окончена
				if (getCell(i, j) == EMPTY)
					return false;
		// Все ячейки заняты
		return true;
	}

	// has to be done
	bool isWon(bool red) const {
		Cell cell;
		if (red) {
			cell = RED;
		}
		else {
			cell = YELLOW;
		}
		if (winner == cell) {
			return true;
		}
		else {
			return false;
		}
	}

	Cell getCell(int i, int j) const {
		return cells[i][j];
	}

	bool isRedTurnNow() const {
		return isRedTurn;
	}

	void print() const {
		for (int i = FIELD_WIDTH - 1; i >= 0; i--)
		{
			for (int j = 0; j < FIELD_HEIGHT; j++)
			{
				if (getCell(i, j) == RED) {
					cout << "R ";
				}
				else if (getCell(i, j) == YELLOW) {
					cout << "Y ";
				}
				else
				{
					cout << 0 << " ";
				}
			}
			cout << endl;
		}
	}

	void printResult() const {
		if (isWon(true)) {
			cout << "Game over! Red player has won!";
		}
		else if (!isWon(true)) {
			cout << "Game over! Yellow player has won!";
		}
	}
	//

	bool makeTurn(int column) //  функция хода
	{
		if (winner != EMPTY || column < 1 || column > FIELD_HEIGHT)
			return false;
		int j = column - 1;
		for (int i = 0; i < FIELD_WIDTH; i++)
			if (getCell(i, j) == EMPTY)
			{
				cells[i][j] = isRedTurn ? RED : YELLOW;
				checkWinner(); // проверка победы?
				isRedTurn = !isRedTurn;
				return true;
			}
		return false;
	}
};

int main()
{
	bool wannaContinue = true;
	bool turn = true;
	while (wannaContinue) {
		Field field(turn);
		while (!field.isOver())
		{
			field.print();
			cout << "Now it's " << (field.isRedTurnNow() ? "red player" : "yellow player") << " turn!" << " Player, make a move (1-7)!" << endl;
			int column; cin >> column;
			field.makeTurn(column);
		}
		field.printResult();
		while (true) {
			cout << "Do you want to continue? Y/N: ";
			string userRespond;
			cin >> userRespond;
			if (userRespond == "N") {
				wannaContinue = false;
				break;
			}
			else if (userRespond == "Y") {
				wannaContinue = true;
				break;
			}
			else {
				cout << "Cannot resolve your answer...\n";
			}
		}
		turn = !turn;
	}
}
