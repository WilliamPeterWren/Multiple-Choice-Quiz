#pragma once
#include <iostream>
#include <io.h> //set_mode()
#include <fcntl.h> //_O_WTEXT
#include <fstream>
#include <codecvt>
#include <vector>
#include <string>
#include <string.h>
#include <Windows.h>
#include <iomanip>
#include <set>
#include <algorithm>
#include <sstream>
#include <thread>

#define black 0
#define blue 1
#define green 2
#define aqua 3
#define red 4
#define purple 5
#define yellow 6
#define white 7
#define gray 8
#define lightblue 9
#define lightgreen 10
#define lightaqua 11
#define lightred 12
#define lightpurple 13
#define lightyellow 14
#define lightwhite 15

class MultipleQuiz {
private:
	std::wstring question, answer_a, answer_b, answer_c, answer_d, right_answer;

public:

	// constructor
	MultipleQuiz();

	// getter
	std::wstring getQuestion();

	std::wstring getAnswer_a();

	std::wstring getAnswer_b();

	std::wstring getAnswer_c();

	std::wstring getAnswer_d();

	std::wstring getRight_answer();


	// setter
	void setQuestion(std::wstring question);

	void setAnswer_a(std::wstring answer_a);

	void setAnswer_b(std::wstring answer_b);

	void setAnswer_c(std::wstring answer_c);

	void setAnswer_d(std::wstring answer_d);

	void setRight_answer(std::wstring right_answer);
};