#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question) : question(question) { }
	GuessResult guess(const string& guessNumber) {
		assertilligalArgument(guessNumber);
		if (guessNumber == question)
			return { true, 3, 0 };
		return { false, getStrikes(guessNumber), getBalls(guessNumber) };

	}

	void assertilligalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3)
			throw length_error("Must be length 3");

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicateNumber(guessNumber)) {
			throw invalid_argument("Must not have same number");
		}
	}


private:
	int getStrikes(const std::string& guessNumber)
	{
		int strikes = 0;
		for (int i = 0; i < question.length(); i++) {
			if (guessNumber[i] == question[i])
				strikes++;
		}
		return strikes;
	}

	int getBalls(const std::string& guessNumber)
	{
		int balls = 0;
		for (int i = 0; i < question.length(); i++) {
			if (guessNumber[i] != question[i] && question.find(guessNumber[i]) != string::npos)
				balls++;
		}
		return balls;
	}

	bool isDuplicateNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2];
	}

	string question;
};