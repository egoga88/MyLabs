import std;
import LabUtils;
import lab5_utils;
using namespace std;




int main() {
	PrintMetadata(5, 1);

	std::string GLOBAL_PATH = "C:\\Users\\Teymur\\Desktop\\OOP\\LABS\\MyLabs\\lab5\\";
	std::string text = "A_Journey_to_the_Centre_of_the_Earth_by_Jules_Verne.txt";
	std::string ignored = "IgnoredWords.txt";
	try {
		Text newText(GLOBAL_PATH + text, GLOBAL_PATH + ignored);

		std::println("Анализируемый текст: \"{}\"", text);

		std::println("Всего слов в тексте: {}", newText.getVector().size());

		PrintSeparLine(40);
		const auto& ignoredWords = newText.getIgnoredWords();
		std::println("Незначимые слова: ");
		for (const auto& words : ignoredWords) {
			std::print("\"{}\" ", words);
		}
		std::println("");
		PrintSeparLine(40);

		std::println("Кол-во уникальных слов в тексте: {}", newText.CountUniqueWords());

		std::println("Количество вхождений самого популярного слова: {}", newText.FindMostPopularWord().first);
		std::println("Самые популярные слова: ");
		for (const auto& words : newText.FindMostPopularWord().second) {
			std::println("{}", words);
		}
	}
	catch (const std::exception& e) {
		std::println("Ошибка: {}", e.what());
	}
	
	
	return 0;
}