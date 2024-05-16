#include "FunctionSecondary.h"

void PrintWilliam() {

	std::wstring temp = L"\n\n\tCũng là in ra màn hình nhưng mà nó lạ lắm:\n\n\t\t";

	SetColor(lightblue);
	for (int i = 0; i < temp.size(); i++) {
		std::wcout << temp[i];
		std::this_thread::sleep_for(std::chrono::microseconds(20000));
	}

	SetColor(lightyellow);
	std::wstring william = L"Peter William Wren";
	int n = 0, i = 0;

	do {

		do {
			n = rand() % (64 - 32 + 1) + 32;
			if (n == 32) {
				break;
			}

			n = rand() % (122 - 65 + 1) + 65;

		} while (n > 90 && n < 97);

		std::wcout << char(n);

		if ((int)william[i] != n) {
			std::wcout << L"\b";
			std::this_thread::sleep_for(std::chrono::microseconds(50));
		}
		else {
			i++;
		}

		if (i >= william.size()) {
			break;
		}
	} while (1);

	std::this_thread::sleep_for(std::chrono::seconds(2));
}

void PrintHacked() {

	const std::wstring enter = L"\n\n\n\t";
	const std::wstring warning = L"Warning!";
	const std::wstring hacked = L"Hacked: ";

	std::this_thread::sleep_for(std::chrono::microseconds(500000));

	SetColor(yellow);
	PrintFunny(enter);
	PrintFunny(warning);

	std::this_thread::sleep_for(std::chrono::seconds(1));

	SetColor(lightred);
	PrintFunny(enter);
	PrintFunny(hacked);

	for (int i = 0; i <= 100; i++) {
		if (i < 10) {
			std::wcout << L"0" << i << L"%";
		}
		else {
			std::wcout << i << L"%";
		}

		std::this_thread::sleep_for(std::chrono::microseconds(200));
		std::wcout << L"\b\b\b";
	}
}

void Reconnect() {

	SetColor(gray);
	std::wstring temp = L"Back to menu... ";
	std::wcout << L"\n\n\n\t";

	for (int i = 0; i < temp.size(); i++) {
		std::wcout << temp[i];
		std::this_thread::sleep_for(std::chrono::microseconds(20000));
	}

	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void ConvertTime(double& real_time) {

	long long temp = real_time;
	double hour = 0, minute = 0;


	/* get hour */
	hour = temp / 3600;

	/* second left */
	temp = temp % 3600;

	/* get minute */
	minute = temp / 60;

	/* second left */
	temp %= 60;

	/* print */
	std::wcout << L"\tThời gian làm bài: ";

	/* print hour */
	if (hour > 0) {
		std::wcout << hour << L" giờ ";
	}

	/* print minute */
	if (minute > 0) {
		std::wcout << minute << L" phút ";
	}

	/* print second */
	std::wcout << temp << L" giây\n";
}

void FunnyGrade(const float& grade) {
	std::wcout << L"\t------------------------------------------\n";
	std::wcout << L"\t";

	if (grade == 10) {
		std::wcout << L"Qua môn chắc kèo!\n";
	}
	else if (grade > 9) {
		std::wcout << L"Xuất cmn sắc luôn!\n";
	}
	else if (grade > 8) {
		std::wcout << L"Cũng giỏi đấy!\n";
	}
	else if (grade > 6.5) {
		std::wcout << L"Khá lắm!\n";
	}
	else if (grade > 5) {
		std::wcout << L"Tạm được thôi!\n";
	}
	else {
		std::wcout << L"Rớt môn! Sao mà cứu được nữa!\n";
	}
	std::wcout << L"\t------------------------------------------\n";
}

/* reduce stress */
void PrintFunny(const std::wstring& text_input) {

	/* Use this code */
	for (int i = 0; i < text_input.size(); i++) {
		std::wcout << text_input[i];
		std::this_thread::sleep_for(std::chrono::microseconds(4));
	}

	/* Quick Test only */
	//std::wcout << text_input;
}