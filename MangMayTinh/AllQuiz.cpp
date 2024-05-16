#include "AllQuiz.h"

/* Print question only from file */
void PrintQuestionView(const std::wstring& question) {

	std::wstringstream ss(question);
	std::wstring temp;

	while (ss >> temp) {
		if (temp == L"williammikiejames") {
			std::wcout << L"\n\t";
		}
		else {
			std::wcout << (temp);
			std::wcout << " ";
		}
	}
}

void ViewAllQuiz(std::vector<MultipleQuiz>& read_question) {

	char size = read_question.size();

	char color_random = 0;

	for (char index = 0; index < size; index++) {

		if (index == 0) {
			switch (size) {
			case 63:
				std::wcout << L"\n\tChapter 01";
				break;

			case 60:
				std::wcout << L"\n\tChapter 02";
				break;
			}
		}
		
		if (index % 10 == 0 && index > 0 || index == size) {
			SetColor(black);
			system("pause");
			system("cls");

			switch (size) {
			case 63:
				std::wcout << L"\n\tChapter 01";
				break;

			case 60:
				std::wcout << L"\n\tChapter 02";
				break;
			}
		}

		SetColor(lightyellow);

		

		std::wcout << L"\n\t---------------------------\n\t";
		std::wcout << L"Câu " << (short)index + 1 << ": ";

		/* print question */
		PrintQuestionView(read_question[index].getQuestion());

		/* print answer */
		color_random = rand() % (15 - 9 + 1) + 9;
		SetColor(color_random);
		std::wcout << L"\n\t";
		std::wcout << (read_question[index].getAnswer_a());

		color_random = rand() % (15 - 9 + 1) + 9;
		SetColor(color_random);
		std::wcout << L"\n\t";
		std::wcout << (read_question[index].getAnswer_b());

		color_random = rand() % (15 - 9 + 1) + 9;
		SetColor(color_random);
		std::wcout << L"\n\t";
		std::wcout << (read_question[index].getAnswer_c());

		color_random = rand() % (15 - 9 + 1) + 9;
		SetColor(color_random);
		std::wcout << L"\n\t";
		std::wcout << (read_question[index].getAnswer_d());

		SetColor(lightyellow);
		std::wcout << L"\n\n\tĐáp án: " << read_question[index].getRight_answer() << "\n";
	}
}