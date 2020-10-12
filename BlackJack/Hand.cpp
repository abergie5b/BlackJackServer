#include "Hand.h"
#include <iostream>

namespace BlackJack
{

	void Hand::push_back(Card& card)
	{
		cards.push_back(card);
	}

	std::vector<Card> Hand::GetCards()
	{
		return cards;
	};

	short unsigned int Hand::GetValue()
	{

		unsigned short acecount = 0;
		unsigned short value = 0;
		for (Card& card : cards)
		{
			if (card.GetName() != CardNames::ACE)
			{
				short unsigned int highvalue = card.GetHighValue();
				short unsigned int lowvalue = card.GetLowValue();
				value += highvalue;
			}
			else
				++acecount;
		}

		if (acecount > 0)
			--acecount;

		for (Card& card : cards)
		{
			if (card.GetName() == CardNames::ACE)
			{
				short unsigned int highvalue = card.GetHighValue();
				short unsigned int lowvalue = card.GetLowValue();
				if (value + highvalue + acecount <= 21)
					value += highvalue;
				else
					value += lowvalue;
			}
		}
		return value;
	};

	short unsigned int Hand::GetDealerValue()
	{
		short unsigned int value = 0;
		for (Card& card : cards)
		{
			if (card.GetName() != CardNames::ACE)
			{
				short unsigned int highvalue = card.GetHighValue();
				short unsigned int lowvalue = card.GetLowValue();
				value += highvalue;
			}
		}

		for (Card& card : cards)
		{
			if (card.GetName() == CardNames::ACE)
			{
				short unsigned int highvalue = card.GetHighValue();
				short unsigned int lowvalue = card.GetLowValue();
				if (value + highvalue <= 21 && value + highvalue >= 17)
					value += highvalue;
				else
					value += lowvalue;
			}
		}
		return value;
	};

	bool Hand::IsBusted()
	{
		return GetValue() > 21;
	};

	void Hand::Print(Card& card)
	{
		std::cout << '\t' << Cards.at(card.GetName()) << " of " << Suites.at(card.GetSuite()) << std::endl;
	}

	void Hand::Print()
	{
		std::cout << "Points: " << GetValue() << std::endl;
		for (Card& card : cards)
			Print(card);
	}

	void Hand::FlipOne()
	{
		Print(cards[1]);
	}

}

