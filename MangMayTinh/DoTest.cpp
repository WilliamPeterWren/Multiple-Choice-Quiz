#include "DoTest.h"

/* Test */
void DoTest(std::vector<MultipleQuiz>& read_question, std::vector<std::tuple<short, MultipleQuiz, std::wstring>>& incorrect_quiz, float& grade) {

	char quantity = read_question.size();

	/* n: Random color, quiz: random question */
	char color_random = 0, enter = 0, mark = 0;
	short rightAnswer = -1;
	const short sleep_time = SleepTime();

	std::set<short> st;
	std::wstring check_empty, user_answer, input_answer = L"\n\t----------------------------------\n\tNhập đáp án: ", chapter = L"Chapter 01", getRightAnswer;

	/* start Counting time do quiz */
	clock_t start_time = clock();


	switch (quantity) {
	case 78:
		chapter[9] = L'1';
		break;
	case 109:
		chapter[9] = L'2';
		break;
	case 70:
		chapter[9] = L'3';
		break;
	case 45:
		chapter[9] = L'4';
		break;
	case 28:
		chapter[9] = L'5';	
		break;
	}
	
	std::random_shuffle(read_question.begin(), read_question.end());

	quantity = quantity < 110 ? quantity : 60;


	/*  */
	for (short i = 0; i < quantity; i++) {
		system("cls");
		
		/* test print */
		SetColor(lightaqua);
		if (quantity == 60) {
			std::wcout << L"\n\tDo Test - 60 quiz.\n";
		}
		else {
			std::wcout << L"\n\t" << chapter << L" - " << (short)quantity << L" câu hỏi.\n";
		}

		SetColor(lightyellow);
		std::wcout << L"\t---------------------------\n\t";
		std::wcout << L"Câu " << i + 1 << ": ";

		/* print question */
		PrintQuestion(read_question[i].getQuestion());

		/* print answer */
		std::set<short> qr;
		std::wstring listABCD = L"ABCD", quest;

		while (qr.size() < 4) {

			wchar_t questRand = rand() % (100 - 97 + 1) + 97;

			if (qr.find(questRand) == qr.end()) {

				quest.push_back(questRand);

				color_random = rand() % (15 - 9 + 1) + 9;
				SetColor(color_random);
				std::wcout << L"\n\t" << listABCD[qr.size()] << L".\t";

				qr.insert(questRand);

				switch (questRand) {

				case L'a':
					//PrintFunny(read_question[i].getAnswer_a());
					std::wcout << read_question[i].getAnswer_a();
					break;

				case L'b':
					//PrintFunny(read_question[i].getAnswer_b());
					std::wcout << read_question[i].getAnswer_b();

					break;

				case L'c':
					//PrintFunny(read_question[i].getAnswer_c());
					std::wcout << read_question[i].getAnswer_c();
					break;

				case L'd':
					//PrintFunny(read_question[i].getAnswer_d());
					std::wcout << read_question[i].getAnswer_d();
					break;
				}

			}
		}


		// right answer
		for (short j = 0; j < 4; j++) {
			if (quest[j] == read_question[i].getRight_answer()[0]) {
				rightAnswer = j;

				switch (read_question[i].getRight_answer()[0]) {

				case L'a':
					getRightAnswer = (read_question[i].getAnswer_a());
					break;

				case L'b':
					getRightAnswer = (read_question[i].getAnswer_b());
					break;

				case L'c':
					getRightAnswer = (read_question[i].getAnswer_c());
					break;

				case L'd':
					getRightAnswer = (read_question[i].getAnswer_d());
					break;
				}

				break;
			}
		}


		/* Reset color for line */
		SetColor(lightyellow);
		//PrintFunny(input_answer);
		std::wcout << input_answer;

		short convertUserAnswer = -1;
		char enter = 0;
		do {

			std::getline(std::wcin, user_answer);

			/* stop doing test */
			if (user_answer == L"pt") {
				/* exit program */
				exit(EXIT_FAILURE);
			}

			convertUserAnswer = CheckUserAnswer(user_answer, enter);

		} while (convertUserAnswer == -1);

		/* Check user answer */
		if (convertUserAnswer == rightAnswer) {
			SetColor(lightblue);
			std::wcout << L"\n\tĐáp án ĐÚNG\n";
			mark++;
		}
		else {
			incorrect_quiz.push_back({ i, read_question[i], user_answer });

			SetColor(lightred);
			std::wcout << L"\n\tĐáp án SAI\n\tĐáp án: ";

			switch (rightAnswer) {
			case 0:
				std::wcout << L"A.\t" << getRightAnswer << "\n";
				break;

			case 1:
				std::wcout << L"B.\t" << getRightAnswer << "\n";
				break;

			case 2:
				std::wcout << L"C.\t" << getRightAnswer << "\n";
				break;

			case 3:
				std::wcout << L"D.\t" << getRightAnswer << "\n";
				break;
			}
		}
		
		if (sleep_time == 0) {
			SetColor(black);
			system("pause");
		}
		else {
			std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
		}
		
	}



	/* stop counting */
	clock_t end_time = clock();

	/* duration of doing test */
	double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

	system("cls");
	SetColor(lightyellow);
	std::wcout << L"\n\n\n\t------------------------------------------\n";
	ConvertTime(elapsed_time);

	grade = (float)mark * 10 / quantity;
	std::wcout << L"\t------------------------------------------\n";
	std::wcout << L"\n\tĐiểm của bạn: " << std::setprecision(2) << grade << L"\n\n";

	SetColor(lightaqua);
	FunnyGrade(grade);

	/* write file score */
	WriteGrade(chapter, grade);


	SetColor(black);
	system("pause");
	system("cls");
}


/* review incorrect answer */
void ReviewIncorrect(const std::vector<std::tuple<short, MultipleQuiz, std::wstring>>& incorrect_quiz) {

	char color_random = 0;
	std::wstring line = L"\n\t---------------------------\n\t";
	std::wstring user_answer = line + L"Đáp án của bạn: ";
	std::wstring right_answer = L"\n\n\tĐáp án Đúng: ";
	
	SetColor(lightaqua);
	std::wcout << L"\n\tĐây là câu hỏi và đáp án mặc định.\n\tTrong bài làm đáp án đã được thay đổi thứ tự.\n";

	for (std::tuple<int, MultipleQuiz, std::wstring> temp : incorrect_quiz) {
		/* Question number */
		SetColor(lightyellow);
		std::wcout << line;
		std::wcout << L"Câu " << std::get<0>(temp) + 1 << ": ";

		/* print question */
		PrintQuestion(std::get<1>(temp).getQuestion());

		/* print answer */
		color_random = rand() % (15 - 9 + 1) + 9;
		SetColor(color_random);
		std::wcout << L"\n\tA.\t";
		std::wcout << (std::get<1>(temp).getAnswer_a());

		color_random = rand() % (15 - 9 + 1) + 9;
		SetColor(color_random);
		std::wcout << L"\n\tB.\t";
		std::wcout << (std::get<1>(temp).getAnswer_b());

		color_random = rand() % (15 - 9 + 1) + 9;
		SetColor(color_random);
		std::wcout << L"\n\tC.\t";
		std::wcout << (std::get<1>(temp).getAnswer_c());

		color_random = rand() % (15 - 9 + 1) + 9;
		SetColor(color_random);
		std::wcout << L"\n\tD.\t";
		std::wcout << (std::get<1>(temp).getAnswer_d());

		/* User answer */
	/*	SetColor(lightwhite);
		PrintFunny(user_answer);
		SetColor(lightaqua);
		std::wcout << std::get<2>(temp) << "\n\t";*/

		/* Right answer */
		SetColor(lightyellow);
		std::wcout << (right_answer);
		SetColor(lightgreen);
		std::wcout << std::get<1>(temp).getRight_answer() << "\n\t";

	}
	std::wcout << L"\n\n\n\t";
	SetColor(black);
	system("pause");
}