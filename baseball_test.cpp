#include "gmock/gmock.h"
#include "baseball.cpp"

TEST(BaseballGame, TryGameTest) {
	EXPECT_EQ(1, 1);
}

TEST(BaseballGame, WrongInputTest) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}