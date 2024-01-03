#include <iostream>
#include <vector>
#include <algorithm>

enum class Rank {
    Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King
};

enum class Suit {
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

struct Card {
    Rank rank;
    Suit suit;
};

class Shoe {
private:
    std::vector<Card> cards;

public:
    Shoe(int nDecks) {
        for (int d = 1; d <= nDecks; ++d) {
            for (int s = static_cast<int>(Suit::Hearts); s <= static_cast<int>(Suit::Spades); ++s) {
                for (int r = static_cast<int>(Rank::Ace); r <= static_cast<int>(Rank::King); ++r) {
                    cards.push_back({ static_cast<Rank>(r), static_cast<Suit>(s) });
                }
            }
        }
    }

    Card drawCard(){
        Card drawnCard = cards.front();
        cards.erase(cards.begin());
        return drawnCard;
    }

    void shuffle() {
        std::random_shuffle(cards.begin(), cards.end());
    }

    void print() const {
        for (const auto& card : cards) {
        std::string rank;
        switch (card.rank) {
            case Rank::Ace:
                rank = "Ace";
                break;
            case Rank::Two:
                rank = "Two";
                break;
            case Rank::Three:
                rank = "Three";
                break;
            case Rank::Four:
                rank = "Four";
                break;
            case Rank::Five:
                rank = "Five";
                break;
            case Rank::Six:
                rank = "Six";
                break;
            case Rank::Seven:
                rank = "Seven";
                break;
            case Rank::Eight:
                rank = "Eight";
                break;
            case Rank::Nine:
                rank = "Nine";
                break;
            case Rank::Ten:
                rank = "Ten";
                break;
            case Rank::Jack:
                rank = "Jack";
                break;
            case Rank::Queen:
                rank = "Queen";
                break;
            case Rank::King:
                rank = "King";
                break;
        }

        std::string suit;
        switch (card.suit) {
            case Suit::Hearts:
                suit = "Hearts";
                break;
            case Suit::Diamonds:
                suit = "Diamonds";
                break;
            case Suit::Clubs:
                suit = "Clubs";
                break;
            case Suit::Spades:
                suit = "Spades";
                break;
        }

        std::cout << rank << " of " << suit << std::endl;
    }
}
};

int main() {
    Shoe shoe(2);
    std::cout << "Initial Shoe:" << std::endl;
    shoe.print();

    std::cout << "\nShuffling Shoe..." << std::endl;
    shoe.shuffle();

    std::cout << "\nShuffled Shoe:" << std::endl;
    shoe.print();

    return 0;
}
