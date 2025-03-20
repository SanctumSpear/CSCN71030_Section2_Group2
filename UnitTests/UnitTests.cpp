#include "CppUnitTest.h"
#include <stdbool.h>

extern "C" {
	#include "../CSCN71030_Section2_Group2/Bet.h"
#include "../CSCN71030_Section2_Group2/Card.h"
#include "../CSCN71030_Section2_Group2/Deck.h"
#include "../CSCN71030_Section2_Group2/Dealer.h"
#include "../CSCN71030_Section2_Group2/Hand.h"
#include "../CSCN71030_Section2_Group2/Player.h"
#include "../CSCN71030_Section2_Group2/ResolvingGame.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTests
{
	TEST_CLASS(PlayerTests) {
	public:
		
		TEST_METHOD(PlayerTest_RememberToDoNamingConvention) {

		}
	};

	TEST_CLASS(DealerTests) {
	public:

		TEST_METHOD(DealerTest_RememberToDoNamingConvention) {

		}
	};

	TEST_CLASS(CardTests) {
	public:

		TEST_METHOD(CardTest_CreationTestValidCard) {
		
		}
	};
}
