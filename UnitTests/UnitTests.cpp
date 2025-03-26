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
}
