export module lab3_utils;
import std;
import LabUtils;


export class SquareSequence {
private:
	int c;
public:
	SquareSequence() : c(0) {}
	SquareSequence(int value) : c(value) {}
	int operator()(int n) const {
		return n * n + c;
	}
	int GetC() const {
		return c;

	}
};

export void OutputVector(const std::vector<SquareSequence>& vect, int n) {
	for (int i = 0; i < vect.size(); i++) {
		std::println("{}. {} при n: {}",i,  vect.at(i)(n), n);
	}
}
export void AddSequence(std::vector<SquareSequence>& vect) {
	std::print("Введите индекс вставки: ");
	int index = 0;
	std::cin >> index;
	std::print("Введите значение сдвига с: ");
	int c = 0;
	std::cin >> c;
	if (vect.size() < index) {
		vect.resize(index);
	}
	vect.insert(vect.begin() + index, SquareSequence(c));
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
export int FindSequenceWithMinValue(const std::vector<SquareSequence>& vect, int n) {
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
export void Menu(std::vector<SquareSequence>& vect) {

	int choice = 1;
	int n = 1;
	while (choice != 0) {
		std::println("[1] Добавить новую последовательность");
		std::println("[2] Удалить последовательность");
		std::println("[3] Вывести значения n-го члена всех последовательностей");
		std::println("[4] Найти последовательность с минимальным n-ым членом");
		std::println("[5] Задать значение n(по умолчанию 1)");
		std::println("[0] Выход");
		std::print("Выберите пункт меню: ");
		std::cin >> choice;
		PrintSeparLine(22);

		switch(choice){
		case 1:
			AddSequence(vect);
			PrintSeparLine(22);
			break;
		case 2:
			RemoveSequence(vect);
			PrintSeparLine(22);
			break;
			
		case 3:
			OutputVector(vect, n);
			PrintSeparLine(22);
			break;
		case 4: {
			int idx = FindSequenceWithMinValue(vect, n);
			if (idx < 0) {
				std::println("Список пуст");
			}
			else {
				std::println("Последовательность с мин n-ым членом: {}. {}", idx, vect[idx](n));
				PrintSeparLine(22);	
			}
			break;
			
			
		}
			
		case 5:
			std::print("Введите n:");
			std::cin >> n;
			break;
		}
	}
}