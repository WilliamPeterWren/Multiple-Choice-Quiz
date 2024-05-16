#include <iostream>
#include <io.h> //set_mode()
#include <fcntl.h> //_O_WTEXT
#include <fstream>
#include <string>


/* Decrypt */
void xorEncrypt(const std::wstring& inputFileName, const std::wstring& outputFileName, const std::wstring& key) {
	// Đọc từ tệp đầu vào
	std::wifstream inputFile(inputFileName, std::ios::binary);

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

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stdin), _O_WTEXT);

	std::wstring filename, readfile, key = L"William";

	std::wcout << L"Nhập file in: ";
	std::getline(std::wcin, filename);

	std::wcout << L"Nhập file out: ";
	std::getline(std::wcin, readfile);

	/* Encrypt File */
	xorEncrypt(filename, readfile, key);

	return EXIT_SUCCESS;
}