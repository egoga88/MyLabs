export module lab5_utils;
import std;


export class Text {
private:
	std::vector<std::string> vect;
	std::unordered_set<std::string> ignored_words;
	std::string normalize(const std::string& word) {
		std::string correctWord = "";
		for (int i = 0; i < word.size(); i++) {
			unsigned char currentChar = word[i];
			if (std::isalpha(currentChar))
			{
				correctWord.push_back(std::tolower(currentChar));
			}
		}
		return correctWord;
	}
	void loadIgnoredWords(const std::string& PATH) {
		std::ifstream file(PATH);
		if (!file.is_open()) {
			throw std::runtime_error("Ошибка чтения файла");
		}
		std::string word;
		while (file >> word) {
			ignored_words.insert(word);
		}
	}
public:
	Text(const std::string& PATH_TO_TEXT, const std::string& PATH_TO_IGNORE_WORDS) {
		load(PATH_TO_TEXT);
		loadIgnoredWords(PATH_TO_IGNORE_WORDS);
	}
	void load(const std::string& PATH) {
		std::ifstream file(PATH);
		if (!file.is_open()) {
			throw std::runtime_error("Ошибка чтения файла");
		}
		std::string word;
		while (file >> word) {
			std::string normalizedWord = normalize(word);
			if (!normalizedWord.empty()) {
				vect.push_back(normalizedWord);
			}
		}
	}
	const std::vector<std::string>& getVector()const {
		return vect;
	}
	const std::unordered_set<std::string>& getIgnoredWords() const {
		return ignored_words;
	}
	size_t CountUniqueWords() const {
		std::unordered_set<std::string> uniqueWords;
		for (size_t i = 0; i < vect.size(); i++) {
			if (ignored_words.find(vect[i]) == ignored_words.end()) {
				uniqueWords.insert(vect[i]);
			}
		}
		return uniqueWords.size();
	}
	std::pair<int, std::set<std::string>> FindMostPopularWord() const {
		std::unordered_map<std::string, int> wordsCount;

		int MaxCount = 0;
		for (size_t i = 0; i < vect.size(); i++) {
			if (ignored_words.find(vect[i]) == ignored_words.end()) {
				wordsCount[vect[i]]++;
				if (MaxCount < wordsCount[vect[i]]) {
					MaxCount = wordsCount[vect[i]];
				}
			}

		}
		std::set<std::string> mostPopularWords;
		if (MaxCount > 0) {
			for (const auto& pair : wordsCount) {
				if (pair.second == MaxCount) {
					mostPopularWords.insert(pair.first);
				}
			}
		}
		return { MaxCount, mostPopularWords };
	}




};