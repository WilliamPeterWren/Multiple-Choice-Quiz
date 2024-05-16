#include "Function.h"


/* Mã hóa User name */
void xorEncryptDecryptUserName(std::wstring& username, const std::wstring& key) {

	size_t keyLength = key.length();
	for (size_t i = 0; i < username.length(); ++i) {
		username[i] = username[i] ^ key[i % keyLength];
	}
}


/* check input answer */
short CheckUserAnswer(std::wstring& user_answer, char& enter) {

	/* stringstream */
	std::wstringstream ss(user_answer);
	std::wstring temp;
	user_answer = L"";

	while (ss >> temp) {
		user_answer += temp;
	}
	
	if (user_answer.length() > 1) {
		std::wcout << L"\n\tNhập 1 đáp án a, b, c hoặc d thôi. Nhập gì nhiều thế!\n\tNhập lại đáp án coi: ";
		return -1;
	}

	if (user_answer.size() == 0) {

		/* enter alot */
		if (enter > 0) {
			std::wcout << L"\n\tEnter hơi nhiều rồi đó! Có nhập đáp án không thì bảo!\n\n\tKhông nhập không cho làm tiếp.\n\n\tNhập nghiêm túc nè:";
		}
		else {
			std::wcout << L"\n\tNhập đáp án đi... enter cái gì!\n\tNhập đáp án đi cho coi kết quả: ";
		}
		enter++;
		return -1;
	}
	
	switch (user_answer[0]) {
	case L'a':return 0;
	case L'b':return 1;
	case L'c':return 2;
	case L'd':return 3;		
	default: 
		std::wcout << L"\n\tĐáp án của người ta chỉ có a, b, c hoặc d thôi. Nhập cái gì dạiiiii má? Nhập lại coi!\n\tNhập lại đáp án xem coi có nhập bậy nữa không: ";
		return -1;
	}
}


/* set color question */
void SetColor(const char& color) {

	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}


/* sleep */
short SleepTime() {
	short sleep_time = 0;
	std::wstring temp, enter = L"\n\n\n\t";

	const std::wstring input = L"Thời gian chờ giữa các câu hỏi.\n\tEnter: Dừng vô thời hạn - Tối đa 60 giây.\n\n\tThích chờ bao lâu vậy bà nụi: ";
	const std::wstring input_charater = L"Nhập số thôi má! Nhập lại!";
	const std::wstring input_negative = L"Thời gian chờ mà âm hả má! Nhập lại!";
	const std::wstring input_maximum = L"Đã nói là tối đa 60 giây mà?!\n\tMuốn lâu hơn thì bỏ trống đi! Nhập lại!";
	const std::wstring sleep_time_zero = L"Thời gian chờ mà = 0 hẻ? Thui cho chờ vô thời hạn!";

	

	do {
		system("cls");		
		SetColor(lightyellow);

		PrintFunny(enter);
		PrintFunny(input);

		SetColor(lightaqua);
		std::getline(std::wcin, temp);

		if (temp.size() == 0) {
			return sleep_time;
		}

		try {			
			sleep_time = std::stoi(temp);

			if (sleep_time == 0) {
				PrintFunny(sleep_time_zero);
				std::this_thread::sleep_for(std::chrono::seconds(1));
				return sleep_time;
			}
		}
		catch (std::exception e) {
			PrintFunny(enter);
			PrintFunny(input_charater);
			PrintFunny(enter);
			sleep_time = 0;

			std::this_thread::sleep_for(std::chrono::seconds(2));
			continue;
		}

		if (sleep_time < 0) {
			PrintFunny(enter);
			PrintFunny(input_negative);
			PrintFunny(enter);

			std::this_thread::sleep_for(std::chrono::seconds(2));
			continue;
		}

		if (sleep_time > 60) {
			PrintFunny(enter);
			PrintFunny(input_maximum);
			PrintFunny(enter);

			std::this_thread::sleep_for(std::chrono::seconds(3));
			continue;
		}


	} while (sleep_time <= 0 || sleep_time > 60);

	return sleep_time;
}


/* User Name */
void UserName() {

	std::wstring username;

	// Tên file cần kiểm tra
	std::wstring tenFile = L"tmp.txt";

	// Mở file để đọc
	std::wifstream file(tenFile);

	// Kiểm tra xem file có mở thành công hay không
	const std::wstring enter = L"\n\n\n\t";
	const std::wstring username_deleted = L"Xóa mất file của người ta rồi còn đâu!";
	const std::wstring username_return = L"Trả lại file mới làm được bài!";

	if (!file.is_open()) {

		SetColor(lightred);
		PrintFunny(enter);
		PrintFunny(username_deleted);

		SetColor(lightyellow);
		PrintFunny(enter);
		PrintFunny(username_return);
		PrintFunny(enter);

		std::this_thread::sleep_for(std::chrono::seconds(2));
		exit(EXIT_FAILURE);
	}


	const std::wstring first_time = L"Lần đầu đặt chân trái đến đây đúng khum?!";
	const std::wstring question = L"Quần đảo Hoàng Sa và Trường Sa của nước nào?" + enter + L"Trả lời : ";
	const std::wstring right_answer = L"Tốt! 10 điểm!" + enter + L"Create username: ";
	const std::wstring study = L"Học bài tiếp hẻ? Siêng dị ";
	const std::wstring hidden = L"Ẩn file username.txt của người ta chi vậy cha nội?!" + enter + L"Bật file lại mới làm bài được";
	const std::wstring vietnam = L"Không phải con rồng cháu tiên không cho làm bài!";
	const std::wstring username_length = L"Nhập vừa phải thôi" + enter + L"Tên gì mà dài thế ? !" + enter + L"Nhập lại nào: ";

	/* UserName key */
	std::wstring key_username = L"Peter";

	// Kiểm tra xem file có rỗng hay không
	if (file.peek() == std::wifstream::traits_type::eof()) {

		PrintWilliam();
		system("cls");

		SetColor(lightyellow);
		PrintFunny(enter);
		PrintFunny(first_time);

		SetColor(lightgreen);
		PrintFunny(enter);
		PrintFunny(question);

		SetColor(lightaqua);
		std::getline(std::wcin, username);

		std::wstringstream wss(username);
		std::wstring temp, answer;
		while (wss >> temp) {
			answer += temp;
		}

		if (answer != L"ViệtNam") {
			PrintFunny(enter);
			PrintFunny(vietnam);
			PrintFunny(enter);

			std::this_thread::sleep_for(std::chrono::seconds(4));
			exit(EXIT_FAILURE);
		}

		SetColor(lightyellow);
		PrintFunny(enter);
		PrintFunny(right_answer);

		do {
			SetColor(lightaqua);
			std::getline(std::wcin, username);

			if (username.length() > 50) {
				PrintFunny(enter);
				PrintFunny(username_length);
				std::wcin.ignore();
			}

		} while (username.length() > 50);

		xorEncryptDecryptUserName(username, key_username);

		std::wofstream username_out(tenFile);

		/* can't create file */
		if (!username_out.is_open()) {
			PrintFunny(enter);
			PrintFunny(hidden);

			std::this_thread::sleep_for(std::chrono::seconds(4));
			exit(EXIT_FAILURE);
		}

		/* write username to file username.txt */
		username_out << username;

		username_out.close();
	}
	else {

		std::wstring temp;
		std::getline(file, temp);

		username = temp;
		xorEncryptDecryptUserName(username, key_username);

		SetColor(lightaqua);
		PrintFunny(enter);
		PrintFunny(study);

		/* read username from file username.txt */
		SetColor(lightyellow);
		std::wcout << username << std::endl;
	}

	file.close();
}


/* Check User input */
short CheckInput(const std::wstring& temp, char& count_negative, char& count_positive, char& enter) {

	/* option print */
	const std::wstring enterline = L"\n\n\t";
	const std::wstring input_character = enterline + L"Nhập số thôi! Ai mượn nhập chữ chi dậy!" + enterline + L"Có thấy người ta để lựa chọn là số không trời ?!" + enterline + L"Nhập lại xem coi : ";
	const std::wstring input_sixgrade = enterline + L"Lấy quyển toán lớp 6 ra học lại liền! Đã nói là nhập số LỚN HƠN 0 cơ mà!";
	const std::wstring negative_option = enterline + L"Lúc thì nhập số âm, lúc thì nhập số ngoài option!" + enterline + L"Bà nội muốn con sống sao ?!";
	const std::wstring negative_option2 = enterline + L"Lày nhá! Hết nhập số lớn quá giờ lại nhập số âm cho nhiều lần nữa!" + enterline + L"Biết hết đó đừng có đùa!" + enterline + L"Chấp niệm cái sự cố chấp này quá à!";
	const std::wstring negative = enterline + L"Thấy số không? Số 0 là nhỏ nhất rồi!" + enterline + L"Nhập lại coi đã biết đếm số chưa!" + enterline + L"Nhập lại nào : ";
	const std::wstring input_max = enterline + L"Sao mà cố chấp quá dị! Đã nói là số lớn nhất là số 6 gòi mà!";
	const std::wstring chapter_quiz = enterline + L"Nè người ta có 6 chương và 1 bài test à? Nhập số gì dạiii trời!" + enterline + L"Nhập lại coi nào : ";
	const std::wstring enter_first_time = enterline + L"Nhập số đi chứ ai mượn enter dị?!" + enterline + L"Nhập lại coi nào : ";
	const std::wstring enter_second_time = enterline + L"Kêu nhập số chứ không có kêu enter nha má!\n\tSao mà cố chấp dị chời." + enterline + L"Nhập lại đi má : ";


	std::wstringstream ss(temp);
	std::wstring container;

	/* user input option */
	short option = 0;

	while (ss >> container) {
		try {
			option = stod(container);

			/* if option is ok */
			if (option >= 0 && option <= 6) {
				return option;
			}

			if (option == 24) {
				return option;
			}
		}
		catch (std::exception e) {

			/* catch if not input number */
			PrintFunny(input_character);
			return -1;
		}
	}

	/* input negative number */
	if (option < 0) {
		count_negative++;
		if (count_negative > 1) {

			/* input negative number */
			PrintFunny(input_sixgrade);

			/* input bigger number */
			if (count_positive > 0) {
				PrintFunny(negative_option);
				PrintFunny(negative_option2);
			}
		}

		/* negative */
		PrintFunny(negative);
	}

	/* input bigger number */
	if (option > 2) {
		count_positive++;
		if (count_positive > 1) {

			/* print: input bigger number many times */
			PrintFunny(input_max);

			/* print: input wrong number many times */
			if (count_negative > 0) {
				PrintFunny(negative_option);
				PrintFunny(negative_option2);
			}
		}

		/* bigger */
		PrintFunny(chapter_quiz);
	}

	if (temp.size() == 0) {

		if (enter) {
			PrintFunny(enter_second_time);
		}
		else {
			PrintFunny(enter_first_time);
		}
		enter++;
	}

	return -1;
}


/* Read data from file */
void ReadFromFile(std::vector<MultipleQuiz>& read_question) {

	/* Read file temp.txt */
	std::wifstream inputFile(L"temp.txt");

	std::wstring enter = L"\n\n\t";

	/* can't read file */
	if (!inputFile) {
		std::wstring file_delete = enter + L"Xóa file của người ta hay gì?!" + enter + L"Tìm không có thấy file má ơiiii!" + enter + L"Chạy lại chương trình nha!";
		PrintFunny(file_delete + enter);

		std::this_thread::sleep_for(std::chrono::seconds(4));
		exit(EXIT_FAILURE);
	}

	/* locale: read file unicode */
	std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);
	inputFile.imbue(loc);

	std::wstring file_change = enter + L"Ai cho sửa file của người ta dị?!" + enter + L"Giờ mà không sửa lại file cũ là khỏi làm bài nha má!" + enter + L"Hư quá mà!";
	
	/* last_word: stop read question */
	std::wstring last_word = L"Đáp án:", temp, eof = L"End Of File";


	int i = 0;

	/* read from file */
	while (1) {

		MultipleQuiz fromFile;

		std::wstring question_temp;

		do {

			std::getline(inputFile, question_temp);

			if (question_temp == last_word) {
				temp += L" williammikiejames " + question_temp + L" williammikiejames ";
			}
			else {
				temp += question_temp + L" williammikiejames ";
			}

			if (question_temp == L"End Of File") {
				goto QUICKBREAK;
			}
		} while (question_temp != last_word);

		fromFile.setQuestion(temp);

		/* Get Answer A */
		std::getline(inputFile, temp);
		fromFile.setAnswer_a(temp);
		

		/* Get Answer B */
		std::getline(inputFile, temp);
		fromFile.setAnswer_b(temp);
		

		/* Get Answer C */
		std::getline(inputFile, temp);
		fromFile.setAnswer_c(temp);		
		

		/* Get Answer D */
		std::getline(inputFile, temp);
		fromFile.setAnswer_d(temp);
		

		/* Right Answer */
		std::getline(inputFile, temp);
		fromFile.setRight_answer(temp);
		

		read_question.push_back(fromFile);
		temp = L"";

	}

QUICKBREAK:

	inputFile.close();

	/* delete data in temp and quiz */
	std::wofstream outputFileTemp("temp.txt", std::ofstream::out | std::ofstream::trunc);
}


/* chuongxx_grade.txt */
void WriteGrade(const std::wstring& chapter, const float& grade) {

	std::wstring tenFile = L"score-board.txt";

	std::wofstream file(tenFile, std::ios::app);

	// Kiểm tra xem file có mở thành công hay không
	if (!file.is_open()) {
		exit(EXIT_FAILURE);
	}

	file << chapter << L" - score: " << std::setprecision(2) << grade << "\n";
	
	file.close();
}


/* decrypt */
void xorDecrypt(const std::wstring& inputFileName, const std::wstring& outputFileName, const std::wstring& key) {

	// Đọc từ tệp đầu vào
	std::wifstream inputFile(inputFileName, std::ios::binary);

	if (!inputFile.is_open()) {
		std::wcout << L"\n\n\tXóa file của người ta hay gì?\n\tKhông tìm thấy file!";

		SetColor(black);
		system("pause");
		inputFile.close();
		exit(EXIT_FAILURE);
	}


	// Ghi vào tệp đầu ra
	std::wofstream outputFile(outputFileName, std::ios::binary);

	wchar_t ch;
	size_t keyLength = key.length();

	// Mã hóa/Giải mã
	size_t i = 0;
	while (inputFile.get(ch)) {
		ch = ch ^ key[i % keyLength];
		outputFile.put(ch);
		++i;
	}

	// Đóng tệp
	inputFile.close();
	outputFile.close();
	
}


/* Print question only from file */
void PrintQuestion(const std::wstring& question) {
	
	std::wstringstream ss(question);
	std::wstring temp;

	while (ss >> temp) {
		if (temp == L"williammikiejames") {	
			std::wcout << L"\n\t";
		}
		else {
			//PrintFunny(temp);
			std::wcout << temp << " ";
			
		}
	}
}