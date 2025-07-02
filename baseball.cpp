#include <stdexcept>

using namespace std;

class Baseball {
public:
	void guess(const string& guessNumber) {
		if (guessNumber.length() != 3)
			throw length_error("Must be length 3");

		for (char ch : guessNumber) {
			if (ch < '0' || ch > '9')
				throw invalid_argument("Must be number");
		}

		if (guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2]) {
				throw invalid_argument("Must not have same number");
			}

	}
};