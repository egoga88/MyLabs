r#include <iostream>
#include <fstream>
#include <print>
#include <vector>
#include <unordered_set>
#include <utility>
#include <set>
#include <unordered_map>
using namespace std;


std::string PATH = "C:\\Users\\Teymur\\Desktop\\OOP\\LABS\\MyLabs\\lab5";

std::string Normilize(const std::string& word);



std::unordered_set<std::string> LoadIgnoreWords(std::string PATH) {
	std::unordered_set<std::string> ignoreWords;
	std::ifstream file(PATH);
	if (!file.is_open()) {
		throw std::runtime_error("Ошибка чтения файла");
	}
	std::string word;
	while (file >> word) {
		ignoreWords.insert(word);
	}
	return ignoreWords;
}

std::vector<std::string> ReadFile(const std::string& PATH) {
	std::vector<std::string> vect;
	std::ifstream file(PATH);
	if (!file.is_open()) {
		throw std::runtime_error("Ошибка чтения файла");
	}
	std::string word;
	while (file >> word) {
		std::string normalizedWord = Normilize(word);
		if (!normalizedWord.empty()) {
			vect.push_back(normalizedWord);
		}
	}
	return vect;
}
std::string Normilize(const std::string& word) {
	std::string correctWord = "";
	for (int i = 0; i < word.size(); i++) {
		unsigned char currentChar = word[i];
		if (std::isalpha(currentChar) )
		{
			correctWord.push_back(std::tolower(currentChar));
		}
	}
	return correctWord;
}

int CountUniqueWords(const std::vector<std::string>& words,const std::unordered_set<std::string>& ignoredWords) {

	std::unordered_set<std::string> uniqueWords;
	for (int i = 0; i < words.size(); i++) {
		if (ignoredWords.find(words[i]) == ignoredWords.end()) {
			uniqueWords.insert(words[i]);
		}
	}
	
	return uniqueWords.size();
}
std::pair<int, std::set<std::string>> FindMostPopularWord(const std::vector<std::string>& words, const std::unordered_set<std::string>& ignoredWords) {
	std::unordered_map<std::string, int> wordsCount;
	int MaxCount = 0;
	for (int i = 0; i < words.size(); i++) {
		if (ignoredWords.find(words[i]) == ignoredWords.end()) {
			wordsCount[words[i]]++;
			if (MaxCount < wordsCount[words[i]]) {
				MaxCount = wordsCount[words[i]];
			}
		}

	}

	std::set<std::string> mostPopularWords;
	
	if (MaxCount > 0) { // Проверяем, что были значимые слова
		for (const auto& pair : wordsCount) {
			if (pair.second == MaxCount) {
				mostPopularWords.insert(pair.first);
			}
		}
	}

	// 3. Возврат результата
	return { MaxCount, mostPopularWords };
}

int CountWord(const std::vector<std::string>& words, std::string word) {
	int count = 0;
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == word) {
			count++;

		}
	}
	return count;
}




void OutputVector(const std::vector<std::string>& vect) {
	for (int i = 0; i < vect.size(); i++) {
		std::cout << vect[i] << " ";
	}
}


int main() {
	string textPath = PATH + "\\1.txt";
	string ignorePath = PATH + "\\IgnoredWords.txt";
	vector<string> vect = ReadFile(textPath);
	unordered_set<string> ignoredWords = LoadIgnoreWords(ignorePath);
	cout << "Колво слов в тексте:" << vect.size() << endl;
	cout << "Колво уникальных слов в тексте:" << CountUniqueWords(vect, ignoredWords) << endl;
	auto pair = FindMostPopularWord(vect, ignoredWords);
	cout << "Самые популярные слова: ";
	for (const std::string& word : pair.second) {
		std::cout << word << " ";
	}
	cout << endl;
	cout << "Кол-во упоминаний: " << pair.first << endl;

	while (true) {
		std::string word = "";
		cout << "Введите слово: ";
		cin >> word;
		cout << "Слово " << word << " встречается в этом тексте ровно " << CountWord(vect, word) << " раз" << endl;
	}

	return 0;
}