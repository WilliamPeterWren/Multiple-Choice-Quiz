#include "MultipleQuiz.h"
#include "DoTest.h"
#include "Menu.h"
#include "Function.h"
#include "FunctionSecondary.h"
#include "AllQuiz.h"


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stdin), _O_WTEXT);

	srand((unsigned int)time(NULL));

	UserName();
	PrintHacked();
	Reconnect();

	std::wstring chapter = L"chapter01en.txt", key_chapter = L"William";

	/* incorrect answer in Quiz: short: ordinal number, MultipleQuiz: incorrect quiz, wstring: user_answer */
	std::vector<std::tuple<short, MultipleQuiz, std::wstring>> incorrect_quiz;

	std::vector<MultipleQuiz> read_question;


	float grade = 0;
	char option = 0;

	while (!option) {

		bool admin = false;

		option = Menu();

		switch (option) {
		case 0:
			return EXIT_SUCCESS;

		case 1:
			chapter[8] = '1';
			break;

		case 2:
			chapter[8] = '2';
			break;

		case 3:
			chapter[8] = '3';
			break;

		case 4:
			chapter[8] = '4';
			break;

		case 5:
			chapter[8] = '5';
			break;
		

		case 6:			
			break;

		case 24:
			admin = true;
			break;
		}

		if (option == 6) {

			/* CHAPTER 01 */
			chapter[8] = '1';			
			xorDecrypt(chapter, L"temp.txt", key_chapter);
			ReadFromFile(read_question);

			/* CHAPTER 02 */
			chapter[8] = '2';
			xorDecrypt(chapter, L"temp.txt", key_chapter);
			ReadFromFile(read_question);

			/* CHAPTER 03 */
			chapter[8] = '3';
			xorDecrypt(chapter, L"temp.txt", key_chapter);
			ReadFromFile(read_question);

			/* CHAPTER 04 */
			chapter[8] = '4';
			xorDecrypt(chapter, L"temp.txt", key_chapter);
			ReadFromFile(read_question);

			/* CHAPTER 05 */
			chapter[8] = '5';
			xorDecrypt(chapter, L"temp.txt", key_chapter);
			ReadFromFile(read_question);	

			
		}
		else {
			/* Decrypt file Chapter */
			xorDecrypt(chapter, L"temp.txt", key_chapter);

			/* read data from file */
			ReadFromFile(read_question);
		}
		

		if (admin) {

			/* Chapter 01 */
			system("cls");	
			ViewAllQuiz(read_question);	;

			/* Chapter 02 */
			system("cls");
			chapter[8] = '2';
			xorDecrypt(chapter, L"temp.txt", key_chapter);
			ReadFromFile(read_question);
			ViewAllQuiz(read_question);
			SetColor(black);
			system("pause");

			/* Chapter 3 */
			system("cls");
			chapter[8] = '3';
			xorDecrypt(chapter, L"temp.txt", key_chapter);
			ReadFromFile(read_question);
			ViewAllQuiz(read_question);
			SetColor(black);
			system("pause");

			/* Chapter 04 */
			system("cls");
			chapter[8] = '4';
			xorDecrypt(chapter, L"temp.txt", key_chapter);
			ReadFromFile(read_question);
			ViewAllQuiz(read_question);
			SetColor(black);
			system("pause");

			/* Chapter 05 */
			system("cls");
			chapter[8] = '5';
			xorDecrypt(chapter, L"temp.txt", key_chapter);
			ReadFromFile(read_question);
			ViewAllQuiz(read_question);		
			SetColor(black);
			system("pause");

			continue;
		}

		

		/* Do test*/
		DoTest(read_question, incorrect_quiz, grade);


		/* review incorret answer */
		ReviewIncorrect(incorrect_quiz);


		// refresh		
		system("cls");

		SetColor(lightaqua);
		std::wcout << L"\n\n\t---------- Làm xong rồi chứ gì ----------\n\n";

		SetColor(lightyellow);
		std::wcout << L"\tLàm lại đề khác: Bấm cái gì cũng được!\n";
		std::wcout << L"\tThôi dẹp nghỉ khỏe không làm nữa: bấm Enter!\n";
		std::wcout << L"\tSuy nghĩ kỹ coi nên chọn cái gì: ";

		SetColor(lightwhite);

		/* Exit DoTest */
		std::wstring input;
		std::getline(std::wcin, input);

		if (input == L"") {
			exit(EXIT_FAILURE);
		}
		else {
			option = 0;
		}
	}


	return EXIT_SUCCESS;
}