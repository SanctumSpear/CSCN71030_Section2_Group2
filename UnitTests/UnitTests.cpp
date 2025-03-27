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

	TEST_CLASS(HandTests) {
	public:

		TEST_METHOD(HandTest_DrawToPlayer) {
			DECK deck = createDeck();
			CARD c01 = drawPlayer(&deck);
			CARD c02 = hand[0][1];
			Assert::AreEqual(c01, c02);
		}

		TEST_METHOD(HandTest_DrawToDealer) {
			DECK deck = createDeck();
			CARD c01 = drawDealer(&deck);
			CARD c02 = hand[0][0];
			Assert::AreEqual(c01, c02);
		}

		TEST_METHOD(HandTest_AddPlayerHand) {
			CARD c01 = createCard(4, 2);
			CARD c02 = createCard(1, 4);
			CARD c03 = createCard(9, 1);
			hand[0][1] = c01;
			hand[1][1] = c02;
			hand[2][1] = c03;
			int realTotal = 24;
			int total = addPlayer();
			Assert::AreEqual(realTotal, total);
		}

		TEST_METHOD(HandTest_AddDealerHand) {
			CARD c01 = createCard(2, 2);
			CARD c02 = createCard(12, 4);
			CARD c03 = createCard(10, 1);
			hand[0][0] = c01;
			hand[1][0] = c02;
			hand[2][0] = c03;
			int realTotal = 22;
			int total = addPlayer();
			Assert::AreEqual(realTotal, total);
		}

		TEST_METHOD(HandTest_BeginningDeal) {
			DECK deck = createDeck();
			deal(&deck);
			Assert::IsNotNull(&hand[0][0].value);
			Assert::IsNotNull(&hand[1][0].value);
			Assert::IsNotNull(&hand[0][1].value);
			Assert::IsNotNull(&hand[1][1].value);
		}

		TEST_METHOD(HandTest_ClearHand) {
			CARD blank = createCard(0, 0);
			hand[2][0] = createCard(8, 2);
			hand[1][1] = createCard(13, 1);
			clearHand();
			Assert::AreEqual(hand[2][0], blank);
			Assert::AreEqual(hand[1][1], blank);
		}
	};

	TEST_CLASS(BetTests) {

		TEST_METHOD(BetTest_WritingAndReadingFile) {
			int chips = 250;
			char* file = "chips.txt";
			writeChipsFile(chips, file);
			int read = readChipsFile(file);
			Assert::AreEqual(chips, read);
		}

		TEST_METHOD(BetTest_ReturnBet) {
			char* file = "chips.txt";
			int chips = 100;
			int stock = 350;
			returnBet(chips, stock, file);
			int read = readChipsFile(file);
			Assert::AreEqual(read, chips + stock);
		}

		TEST_METHOD(BetTest_BetLoss) {
			int bet = 100;
			int test = betLoss(bet);
			int loss = 50;
			Assert::AreEqual(test, loss);
		}

		TEST_METHOD(BetTest_BetWon) {
			int bet = 100;
			int test = betWon(bet);
			int won = 200;
			Assert::AreEqual(test, won);
		}
	};
}
