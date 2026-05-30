export module lab3_utils;
import std;
import LabUtils;
import classes;


export void OutputVector(const std::vector<SquareSequence>& vect, int n) {
	for (int i = 0; i < vect.size(); i++) {
		std::println("{}. {} при n: {}",i,  vect.at(i)(n), n);
	}
}
export void AddSequence(std::vector<SquareSequence>& vect) {
	std::print("Введите индекс вставки: ");
	int index = 0;
	std::cin >> index;
	if (vect.size() < index) {
		std::println("Вы вышли за границы");
		return;
	}
	std::print("Введите значение сдвига с: ");
	int c = 0;
	std::cin >> c;
	SquareSequence currentSequence(c);
	vect.insert(vect.begin() + index, currentSequence);
	std::println("Последовательность со сдвигом {} добавлена", c);
	
}
export void RemoveSequence(std::vector<SquareSequence>& vect) {
	std::print("Введите индекс элемента: ");
	int index = 0;
	std::cin >> index;
	if (index >= vect.size()) {
		std::println("Неверный аргумент");
	}
	else {
		vect.erase(vect.begin() + index);
		std::println("Поседовательность с индексом {} удалена",index );
	}

}
int FindSequenceWithMinValue(const std::vector<SquareSequence>& vect, int n) {
	if (vect.size() != 0) {
		int MinIndex = 0;
		int MinValue = vect[0](n);
		for (int i = 0; i < vect.size(); i++) {
			if (vect[i](n) < MinValue) {
				MinValue = vect[i](n);
				MinIndex = i;
			}
		}
		return MinIndex;
	}
	else {
		return -1;
	}
}
export void OutputSequenceWithMinValue(const std::vector<SquareSequence>& vect, int n) {
	int idx = FindSequenceWithMinValue(vect, n);
	if (idx < 0) {
		std::println("Список пуст");
	}
	else {
		std::println("Последовательность с мин n-ым членом: {}. {}", idx, vect[idx](n));
		
	}
}
export void InputN(int& n) {
	std::print("Введите n:");
	std::cin >> n;
}