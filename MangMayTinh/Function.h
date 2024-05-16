#pragma once
#include "MultipleQuiz.h"
#include "FunctionSecondary.h"


/* decrypt file .txt */
void xorEncryptDecryptUserName(std::wstring& username, const std::wstring& key);


/* check input answer */
short CheckUserAnswer(std::wstring& user_answer, char& enter);

/* set color question */
void SetColor(const char& color);


/* sleep */
short SleepTime();


/* User Name */
void UserName();


/* Check User input */
short CheckInput(const std::wstring& temp, char& count_negative, char& count_positive, char& enter);


/* Read data from file */
void ReadFromFile(std::vector<MultipleQuiz>& read_question);


/* chuongxx_grade.txt */
void WriteGrade(const std::wstring& chapter, const float& grade);


/* decrypt */
void xorDecrypt(const std::wstring& inputFileName, const std::wstring& outputFileName, const std::wstring& key);


/* Print question only from file */
void PrintQuestion(const std::wstring& question);