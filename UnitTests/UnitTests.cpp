#include "CppUnitTest.h"
#include <stdbool.h>
#include <string.h>

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

	TEST_CLASS(DeckTests) {
	public:
		TEST_METHOD(DeckTest_DrawCardTest_1) {
			DECK deck1 = createDeck();
			DECK deck2 = createDeck();

			srand(1);
			CARD card1 = drawCard(&deck1);

			srand(1);
			CARD card2 = drawCard(&deck2);

			Assert::AreEqual(card1.value, card2.value);
			Assert::AreEqual(card1.suit, card2.suit);
		}

		TEST_METHOD(DeckTest_DrawCardTest_2) {
			DECK deck1 = createDeck();
			DECK deck2 = createDeck();

			srand(2);
			CARD card1 = drawCard(&deck1);

			srand(2);
			CARD card2 = drawCard(&deck2);

			Assert::AreEqual(card1.value, card2.value);
			Assert::AreEqual(card1.suit, card2.suit);
		}

		TEST_METHOD(DeckTest_DrawCardTest_3) {
			DECK deck1 = createDeck();
			DECK deck2 = createDeck();

			srand(3);
			CARD card1 = drawCard(&deck1);

			srand(3);
			CARD card2 = drawCard(&deck2);

			Assert::AreEqual(card1.value, card2.value);
			Assert::AreEqual(card1.suit, card2.suit);
		}
	};

	TEST_CLASS(CardTests) {
	public:

		TEST_METHOD(CardTest_CreateCardTest_ValidCardValue) {
			int value = 1;
			int suit = 1;
			char name[MAX_NAME_SIZE] = "Ace of Spades";

			CARD actual = createCard(value, suit);

			Assert::AreEqual(value, actual.value);
		}

		TEST_METHOD(CardTest_CreateCardTest_ValidCardSuit) {
			int value = 6;
			int suit = 3;
			char name[MAX_NAME_SIZE] = "Six of Hearts";

			CARD actual = createCard(value, suit);

			Assert::AreEqual(suit, actual.suit);
		}

		TEST_METHOD(CardTest_CreateCardTest_ValidCardName) {
			int value = 11;
			int suit = 2;
			char name[MAX_NAME_SIZE] = "Jack of Clubs";

			CARD actual = createCard(value, suit);

			Assert::AreEqual(name, actual.name);
		}

		TEST_METHOD(CardTest_CreateCardTest_InvalidCardValueOver) {
			int value = 17;
			int suit = 4;
			char name[MAX_NAME_SIZE] = "Invalid Input of Diamonds";

			CARD actual = createCard(value, suit);

			Assert::AreEqual(name, actual.name);
		}

		TEST_METHOD(CardTest_CreateCardTest_InvalidCardValueUnder) {
			int value = -2;
			int suit = 2;
			char name[MAX_NAME_SIZE] = "Invalid Input of Clubs";

			CARD actual = createCard(value, suit);

			Assert::AreEqual(name, actual.name);
		}

		TEST_METHOD(CardTest_CreateCardTest_InvalidCardSuitOver) {
			int value = 9;
			int suit = 75;
			char name[MAX_NAME_SIZE] = "Nine of Invalid Input";

			CARD actual = createCard(value, suit);

			Assert::AreEqual(name, actual.name);
		}

		TEST_METHOD(CardTest_CreateCardTest_InvalidCardSuitUnder) {
			int value = 13;
			int suit = -13;
			char name[MAX_NAME_SIZE] = "King of Invalid Input";

			CARD actual = createCard(value, suit);

			Assert::AreEqual(name, actual.name);
		}

		TEST_METHOD(CardTest_CreateCardTest_InvalidCardBothOver) {
			int value = 93;
			int suit = 16;
			char name[MAX_NAME_SIZE] = "Invalid Input of Invalid Input";

			CARD actual = createCard(value, suit);

			Assert::AreEqual(name, actual.name);
		}

		TEST_METHOD(CardTest_CreateCardTest_InvalidCardBothUnder) {
			int value = -7;
			int suit = -193;
			char name[MAX_NAME_SIZE] = "Invalid Input of Invalid Input";

			CARD actual = createCard(value, suit);

			Assert::AreEqual(name, actual.name);
		}

		TEST_METHOD(CardTest_CreateCardTest_InvalidCardUnderOver) {
			int value = -43;
			int suit = 7;
			char name[MAX_NAME_SIZE] = "Invalid Input of Invalid Input";

			CARD actual = createCard(value, suit);

			Assert::AreEqual(name, actual.name);
		}

		TEST_METHOD(CardTest_CreateCardTest_InvalidCardOverUnder) {
			int value = 72;
			int suit = -3;
			char name[MAX_NAME_SIZE] = "Invalid Input of Invalid Input";

			CARD actual = createCard(value, suit);

			Assert::AreEqual(name, actual.name);
		}
	};

	TEST_CLASS(HandTests) {
	public:

		TEST_METHOD(HandTest_DrawToPlayer) {
			DECK deck = createDeck();
			CARD c01 = drawPlayer(&deck);
			CARD c02 = hand[0][1];
			Assert::AreEqual(c01.value, c02.value);
		}

		TEST_METHOD(HandTest_DrawToDealer) {
			DECK deck = createDeck();
			CARD c01 = drawDealer(&deck);
			CARD c02 = hand[0][0];
			Assert::AreEqual(c01.value, c02.value);
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

	TEST_CLASS(ResolvingGameCases) {
		TEST_METHOD(RGM_01) {
			int fakeDealerTotal = 20;
			int fakePlayerTotal = 23;
			bool test = overTwenty(fakeDealerTotal, fakePlayerTotal);
			bool correct = true;
			Assert::AreEqual(test, correct);
		}
		TEST_METHOD(RGM_02) {
			int fakeDealerTotal = 7;
			int fakePlayerTotal = 19;
			int test = endResult(fakeDealerTotal, fakePlayerTotal);
			int correct = 2;
			Assert::AreEqual(test, correct);
		}

		TEST_METHOD(RGM_03) {
			int fakeDealerTotal = 19;
			int fakePlayerTotal = 7;
			int test = endResult(fakeDealerTotal, fakePlayerTotal);
			int correct = 3;
			Assert::AreEqual(test, correct);
		}
		TEST_METHOD(RGM_04) {
			int fakeDealerTotal = 19;
			int fakePlayerTotal = 19;
			int test = endResult(fakeDealerTotal, fakePlayerTotal);
			int correct = 1;
			Assert::AreEqual(test, correct);
		}
		TEST_METHOD(RGM_05) {
			int fakeDealerTotal = 22;
			int fakePlayerTotal = 22;
			int test = endResult(fakeDealerTotal, fakePlayerTotal);
			int correct = 2;
			Assert::AreEqual(test, correct);
		}
	};
}
