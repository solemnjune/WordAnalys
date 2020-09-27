// Эта программа принимает текст и считает: количество символов, букв, гласных, согласных, цифр, пробелов и знаков препинания.
//А также выдаёт количество символов самого длинного слова


#include "pch.h"
#include <iostream>
using namespace std;
void Schet(int& probel, int& glas, int& soglas, int& znaki, int& ciphry, int& bukvi, char& letter) {
	if (letter == ' ') {
		probel++;
	}
	else if ((letter > 47) && (letter < 58)) {
		ciphry++;
	}
	else if (((letter >= 'A') && (letter <= 'Z')) || ((letter >= 'a') && (letter <= 'z'))) {
		bukvi++;
		if ((letter == 'a') || (letter == 'A') || (letter == 'e') || (letter == 'E') || (letter == 'u') || (letter == 'U') || (letter == 'i') || (letter == 'I') ||
			(letter == 'o') || (letter == 'O') || (letter == 'y') || (letter == 'Y')) {
			glas++;
		}
		else {
			soglas++;
		}
	}
	else {
		znaki++;
	}
}
void slovi(char& lastLetter, char& letter, int & slova) {
	
	if ((((lastLetter >= 'A') && (lastLetter <= 'Z')) || ((lastLetter >= 'a') && (lastLetter <= 'z'))) &&
		(((letter < 'A') || (letter > 'Z')) && ((letter < 'a') || (letter > 'z')))) {
		slova++;
	}
	lastLetter = letter;
}
int main()
{
	setlocale(LC_ALL, "Russian");

	int wordLength = 1;
	int longestWord = 0;
	int numbSymb = 0;
	char lastLetter = '\0';

	int probel = 0;
	int glas = 0;
	int soglas = 0;
	int znaki = 0;
	int ciphry = 0;
	int bukvi = 0;
	int slova = 0;

	cout << "Введите текст :" << endl;
	char letter = '\0';
	letter = cin.get();

	while (letter != 10) {
		numbSymb++;
		slovi(lastLetter, letter, slova);
		Schet( probel,  glas,  soglas,  znaki, ciphry,  bukvi, letter);

		if ((numbSymb == 1)&& ((letter < 'A') || (letter > 'Z'))&& (((letter < 'a') || (letter > 'z')))) {
			wordLength = 0;
		} 
		
		letter = cin.get();
		
		if (wordLength > longestWord) {
			longestWord = wordLength;
		}
		if (((letter <'A')||(letter >'Z'))&& ((letter < 'a') || (letter > 'z'))) {
			wordLength = 0;
		}
		else { wordLength++; }
		
	}
	slovi(lastLetter, letter, slova);

	cout << "Количество символов всего : " << numbSymb << endl;
	cout << "Длина самого длинного слова : "<<longestWord<< endl;
	cout << "Количество слов : "<< slova << endl;
	cout << "Количество букв : " << bukvi<< endl;
	cout << "Количество гласных : " << glas<< endl;
	cout << "Количество согласных : " << soglas << endl;
	cout << "Количество цифр : " << ciphry << endl;
	cout << "Количество пробелов : " << probel << endl;
	cout << "Количество знаков препинания : " << znaki << endl;



	return 0;
}

