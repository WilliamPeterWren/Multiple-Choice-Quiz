#include "Menu.h"

char Menu() {

	system("cls");

	std::wstringstream wss;

	/* info */
	const std::wstring line = L"\t-------------------------------------\n";
	const std::wstring classid = L"\tÔn tập Pháp luật đại cương\n";
	const std::wstring author = L"\tProject by William PT\n\n";

	const std::wstring goodluck = L"\tChúc bạn 10 điểm.\n\n";

	const std::wstring chapter01 = L"\t\t01.  Chapter 01\n";
	const std::wstring chapter02 = L"\t\t02.  Chapter 02\n";
	const std::wstring chapter03 = L"\t\t03.  Chapter 03\n";
	const std::wstring chapter04 = L"\t\t04.  Chapter 04\n";
	const std::wstring chapter05 = L"\t\t05.  Chapter 05\n";

	//const std::wstring chapter06 = L"\n\t\t06.  Do Test\n\n";


	const std::wstring return_menu = L"\t\t0. Return\n";
	const std::wstring input = L"\tChọn chương nào thì nhập cho đúng nha\n\tNhập sai thử là biết liền : ";

	std::wcout << L"\n\n";
	SetColor(aqua);
	PrintFunny(line);

	SetColor(lightyellow);
	PrintFunny(author);
	PrintFunny(classid);

	/* good luck */
	SetColor(aqua);
	PrintFunny(line);
	PrintFunny(goodluck);
	PrintFunny(line);

	/* chapter choice */
	SetColor(lightyellow);
	PrintFunny(chapter01);
	PrintFunny(chapter02);
	PrintFunny(chapter03);
	PrintFunny(chapter04);
	PrintFunny(chapter05);


	SetColor(lightaqua);
	//PrintFunny(chapter06);


	/* return */
	SetColor(lightred);
	PrintFunny(return_menu);

	/* line */
	SetColor(lightyellow);
	PrintFunny(line);
	PrintFunny(input);


	char option = 0;
	char count_negative = 0, count_positive = 0, enter = 0;

	std::wstring temp;

	/* check input before doing test */
	do {
		std::getline(std::wcin, temp);

		option = CheckInput(temp, count_negative, count_positive, enter);

		if (option == 24) {
			return option;
		}

	} while (option < 0 || option > 6);

	return option;
}