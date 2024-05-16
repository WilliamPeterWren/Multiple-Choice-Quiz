#include "MultipleQuiz.h"

// constructor
MultipleQuiz::MultipleQuiz() {
	this->question = L"";
	this->answer_a = L"";
	this->answer_b = L"";
	this->answer_c = L"";
	this->answer_d = L"";
	this->right_answer = L"";
}

// getter
std::wstring MultipleQuiz::getQuestion() {
	return this->question;
}
std::wstring MultipleQuiz::getAnswer_a() {
	return this->answer_a;
}
std::wstring MultipleQuiz::getAnswer_b() {
	return this->answer_b;
}
std::wstring MultipleQuiz::getAnswer_c() {
	return this->answer_c;
}
std::wstring MultipleQuiz::getAnswer_d() {
	return this->answer_d;
}
std::wstring MultipleQuiz::getRight_answer() {
	return this->right_answer;
}

//setter
void MultipleQuiz::setQuestion(std::wstring question) {
	this->question = question;
}
void MultipleQuiz::setAnswer_a(std::wstring answer_a) {
	this->answer_a = answer_a;
}
void MultipleQuiz::setAnswer_b(std::wstring answer_b) {
	this->answer_b = answer_b;
}
void MultipleQuiz::setAnswer_c(std::wstring answer_c) {
	this->answer_c = answer_c;
}
void MultipleQuiz::setAnswer_d(std::wstring answer_d) {
	this->answer_d = answer_d;
}
void MultipleQuiz::setRight_answer(std::wstring right_answer) {
	this->right_answer = right_answer;
}