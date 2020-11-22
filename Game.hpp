/**
* @file Game.hpp
* Made by Antoni Kiedos (GitHub alias: Programista-Cpp)
* This game engine was made accidentally because I want to do electronical version of polish quiz show "Milionerzy" and it was too much lines of code, so I bring it to the another file -- Game.hpp
* Version: 0.1.0-alpha
* Version name: "You lose this quiz!"
*/

/**
* TO DO: Check if there are the female verbs for "lose" in other languages
* TO DO: Extend Question() to other languages
*/
#pragma once
namespace Player
{
	std::string name	= "";
	std::string nick	= "";
	unsigned short age	= 0;
	enum GENDER {MALE, FEMALE, null} gender = null; // null is to initialise the enum. Without initialisation the std::cin >> doesn't work properly
	enum NATIVECOUNTRY {PL, USA, GB, RU, HU, JP, FR, GER, CZ, ES, CN, MX, BR, POR, NOR, SWE, null} native_country = null; // NATIVECOUNTRY is for language packages
} // namespace Player
namespace Game
{
	namespace Events // This use language packages
	{
		void Lose() requires ((Player::native_country == GB) || (Player::native_country == USA) || (Player::native_country == CN))
		{
			std::cout << "You lose...\n";
		}
		void Lose() requires (Player::native_country == PL)
		{
			if(gender == FEMALE) std::cout << "Niestety przegralas...\n";
			else std::cout << "Niestety przegrales...\n";
		}
		void Lose() requires ((Player::native_country == MX) || (Player::native_country == ES))
		{
			std::cout << "Perdiste...\n";
		}
		void Lose() requires (Player::native_country == RU)
		{
			std::cout << "Ty proigrala...\n";
		}
		void Lose() requires (Player::native_country == GER)
		{
			std::cout << "Du hast verloren...\n";
		}
		void Lose() requires (Player::native_country == CZ)
		{
			std::cout << "Prohral jsi...\n";
		}
		void Lose() requires (Player::native_country == HU)
		{
			std::cout << "Vesztettel...\n";
		}
		void Lose() requires (Player::native_country == JP)
		{
			std::cout << "Anata ga maketa...\n";
		}
		void Lose() requires (Player::native_country == FR)
		{
			std::cout << "Tu as perdu...\n";
		}
		void Lose() requires ((Player::native_country == POR) || (Player::native_country == BR))
		{
			std::cout << "Voce perdeu...\n";
		}
		void Lose() requires (Player::natove_country == NOR)
		{
			std::cout << "Du tapte...\n";
		}
		void Lose() requires (Player::native_country == SWE)
		{
			std::cout << "Du forlorade...\n";
		}
	} // namespace Events
	namespace Quiz
	{
		char corr_ans = '\0';
		char user_ans = '\0';
		void Question(std::string q, std::string ans_A, std::string ans_B, std::string ans_C, std::string ans_D)
		{
			std::cout << q << "\nAnswers:\n\nA--" << ans_A << "\tB--" << ans_B << "\nC--" << ans_C << "\tD--" << ans_D << "\n\n";
		}
		void Answer(char correct_answer)
		{
			corr_ans = correct_answer;
			std::cin >> user_ans;
		}
	} // namespace Quiz
} // namespace Game
