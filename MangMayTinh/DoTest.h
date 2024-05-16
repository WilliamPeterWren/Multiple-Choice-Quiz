#pragma once
#include "MultipleQuiz.h"
#include "FunctionSecondary.h"
#include "Function.h"

/* Test */
void DoTest(std::vector<MultipleQuiz>& read_question, std::vector<std::tuple<short, MultipleQuiz, std::wstring>>& incorrect_quiz, float& grade);


/* review incorrect answer */
void ReviewIncorrect(const std::vector<std::tuple<short, MultipleQuiz, std::wstring>>& incorrect_quiz);