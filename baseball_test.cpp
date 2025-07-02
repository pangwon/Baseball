#include "gmock/gmock.h"
#include "baseball.cpp"


class BaseballFixture : public testing::Test {
public:
	Baseball game;
	void assertilligalArgument(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {

		}
	}
};

TEST_F(BaseballFixture, WrongInputTest) {
	assertilligalArgument("12");
	assertilligalArgument("12s");
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}