#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;
int readpositivenumber(string messege) {
	int num;
	do {
		cout << messege;
		cin >> num;
	} while (num < 0);
	return num;
}
enum enQestionLevel { easy = 1, med = 2, hard = 3, mix = 4 };
enum enOperationType { add = 1, sub = 2, mul = 3, Div = 4, Mix = 5 };
struct stFinalResult {
	int NumberOfQs = 0;
	int RightAns = 0;
	int WrongAns = 0;
	string FinalResult = "";
};
struct stProblem {
	int Num1 = 0;
	int Num2 = 0;
	enOperationType Op{};
	enQestionLevel QuestionLvl{};
};
enOperationType randnumber(int from, int to) {
	int randnum = (rand() % (to - from + 1)) + from;
	return (enOperationType)randnum;
}
string ViewQuestionNames(stProblem problem) {
	string QuestionLevel[4] = { "easy" , "med" , "hard" , "mix" };
	return QuestionLevel[problem.QuestionLvl - 1];
}
char ViewOperationNames(stProblem problem) {


	char OperationType[4] = { '+' , '-', 'x' , '/' };
	return OperationType[problem.Op - 1];
}
enQestionLevel GetQuestionLevel() {
	int QLevel;
	cout << "\n[1] ==> Easy\n";
	cout << "[2] ==> Med\n";
	cout << "[3] ==> Hard\n";
	cout << "[4] ==> Mix\n";
	cout << "\nyour choice ? : ";
	cin >> QLevel;
	return (enQestionLevel)QLevel;
}
enOperationType GetOperationType() {
	int OperationType;
	cout << "\nAdd , Subtract , Multibly , Divide, mix [1 ==> 5]";
	cout << "\n\n\nwhich operation type you want to use ? : ";
	cin >> OperationType;
	return (enOperationType)OperationType;
}
int ProblemResultBasedOnOpTyp(stProblem problem) {
	char OperationType = ViewOperationNames(problem);

	switch (OperationType)
	{
	case '+': return problem.Num1 + problem.Num2;
	case '-': return problem.Num1 - problem.Num2;
	case 'x': return problem.Num1 * problem.Num2;
	case '/': return problem.Num1 / problem.Num2;
	}
	return 0;
}
void EasyProblem(stProblem problem, stFinalResult& FinalResults) {
	int Answer;
	problem.Num1 = randnumber(1, 10);
	problem.Num2 = randnumber(1, 10);

	cout << problem.Num1 << " " << ViewOperationNames(problem) << " " << problem.Num2 << "\n";
	int RightAnswer = ProblemResultBasedOnOpTyp(problem);
	cin >> Answer;
	if (RightAnswer != Answer) {
		system("color 4F");
		cout << "\athe right Answer is " << RightAnswer << "\n";
		FinalResults.WrongAns += 1;
		system("pause");
	}
	else {
		system("color 2F");
		cout << "Right Answer :-)\n";
		FinalResults.RightAns += 1;
		system("pause");
	}
}
void MedProblem(stProblem problem, stFinalResult& FinalResults) {
	int Answer;
	problem.Num1 = randnumber(1, 50);
	problem.Num2 = randnumber(1, 50);
	int RightAnswer = ProblemResultBasedOnOpTyp(problem);
	cout << problem.Num1 << " " << ViewOperationNames(problem) << " " << problem.Num2 << "\n";
	cin >> Answer;
	if (RightAnswer != Answer) {
		system("color 4F");
		cout << "\athe right Answer is " << RightAnswer << "\n";
		FinalResults.WrongAns += 1;
		system("pause");

	}
	else {
		cout << "Right Answer :-)\n";
		system("color 2F");
		FinalResults.RightAns += 1;
		system("pause");

	}
}
void HardProblem(stProblem problem, stFinalResult& FinalResults) {
	int Answer;
	problem.Num1 = randnumber(1, 100);
	problem.Num2 = randnumber(1, 100);
	int RightAnswer = ProblemResultBasedOnOpTyp(problem);
	cout << problem.Num1 << " " << ViewOperationNames(problem) << " " << problem.Num2 << "\n";
	cin >> Answer;
	if (RightAnswer != Answer) {
		system("color 4F");
		cout << "\athe right Answer is " << RightAnswer << "\n\n\n";
		FinalResults.WrongAns += 1;
		system("pause");

	}
	else {
		cout << "Right Answer :-)\n\n";
		system("color 2F");
		FinalResults.RightAns += 1;
		system("pause");

	}
}
void MixProblem(stProblem problem, stFinalResult& FinalResults) {
	int RandomChoice = randnumber(1, 3);
	if (RandomChoice == 1)  EasyProblem(problem, FinalResults);
	else if (RandomChoice == 2) MedProblem(problem, FinalResults);
	else if (RandomChoice == 3) HardProblem(problem, FinalResults), FinalResults;
}
void ResetScreen() {
	//system("pause");
	system("color 07");
	system("cls");
}
void DecideWhichFunctionBasedOnChoice(stProblem problem, stFinalResult& FinalResults) {
	switch (problem.QuestionLvl) {
	case enQestionLevel::easy: EasyProblem(problem, FinalResults); break;
	case enQestionLevel::med:  MedProblem(problem, FinalResults); break;
	case enQestionLevel::hard: HardProblem(problem, FinalResults); break;
	case enQestionLevel::mix:  MixProblem(problem, FinalResults); break;
	}
}
void PrintGameResults(stProblem problem, stFinalResult& FinalResults) {
	system("cls");

	if (FinalResults.RightAns >= FinalResults.WrongAns) {
		FinalResults.FinalResult = "Pass :-)";
		system("color 2F");
	}
	else {
		FinalResults.FinalResult = "Fail :-(";
		system("color 4F");
	}

	cout << "\n--------------------------" << FinalResults.FinalResult << "--------------------------\n";
	cout << "Number of Qs is	: " << FinalResults.NumberOfQs << "\n";
	cout << "the Qs Level: " << ViewQuestionNames(problem) << "\n";
	cout << "Number of Right Answers: " << FinalResults.RightAns << "\n";
	cout << "Number of Wrong Answers: " << FinalResults.WrongAns << "\n";
	cout << "\n------------------------------------------------------------\n";





}
void Game(stProblem problem, stFinalResult& FinalResults) {
	srand((unsigned)time(NULL));
	FinalResults.NumberOfQs = readpositivenumber("How Many Questions you want to solve ? : ");
	problem.QuestionLvl = GetQuestionLevel();
	problem.Op = GetOperationType();
		enOperationType TestEnum = problem.Op;
	for (int i = 1; i <= FinalResults.NumberOfQs; i++) {
		ResetScreen();
		cout << "\n\n\n\n";
		switch (TestEnum) {
		case enOperationType::Mix:
			problem.Op = randnumber(1, 4);
		}
		cout << "Question [" << i << "/" << FinalResults.NumberOfQs << "]\n";
		DecideWhichFunctionBasedOnChoice(problem, FinalResults);
	}
	PrintGameResults(problem, FinalResults);

}
int main() {
	char PlayAgain;
	srand((unsigned)time(NULL));
	do {
		stProblem problem{}; stFinalResult FinalResults{};
		PlayAgain = 1;
		ResetScreen();
		Game(problem, FinalResults);
		system("pause");
		cout << "play again ? : (y/n)";
		cin >> PlayAgain;
	} while (PlayAgain == 'y' || PlayAgain == 'Y');
	return 0;
}