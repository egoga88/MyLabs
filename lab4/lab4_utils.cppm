export module lab4_utils
import std;
import LabUtils;


export class Sequence {
public:
	virtual int operator()(int n) const = 0;
	virtual ~Sequence() = default;
};
export class SquareSequence : public Sequence {
private:
	int c;
public:
	SquareSequence() : c(0) {}
	SquareSequence(int value) : c(value) {}
	int operator()(int n) const override {
		return n * n + c;
	}
	int GetC() const {
		return c;

	}
};
export class FactorialSequence : public Sequence {
public:
	int operator()(int n) const override {
		if (n <= 1) return 1;
		if (n > 1) {
			int res = 1;
			for (int i = n; i > 1; i--) {
				res *= i;
			}
			return res;
		}
	}
};
void OutputVector(const std::vector<std::unique_ptr<Sequence>>& vect, int n) {
	for (int i = 0; i < vect.size(); i++) {
		std::println("{}. {} при n: {}", i, (*vect.at(i))(n), n);
	}
}
void AddSequence(std::vector<std::unique_ptr<Sequence>>& vect) {
	std::print("Введите индекс вставки: ");
	int index = 0;
	std::cin >> index;
	if (vect.size() < index) {
		std::println("Вы вышли за границы");
		return;
	}
	int choice = 0;
	std::print("Выберите тип последовательности(0 - n*n/1 - n!): ");
	std::cin >> choice;

	if (choice == 0) {
		std::print("Введите значение сдвига с: ");
		int c = 0;
		std::cin >> c;
		vect.insert(vect.begin() + index, std::make_unique<SquareSequence>(c));
		std::println("Последовательность со сдвигом {} добавлена", c);
	}
	else {

		vect.insert(vect.begin() + index, std::make_unique<FactorialSequence>());
		std::println("Последовательность добавлена");
	}
}

void RemoveSequence(std::vector< std::unique_ptr<Sequence>>& vect) {
	std::print("Введите индекс элемента: ");
	int index = 0;
	std::cin >> index;
	if (index >= vect.size()) {
		std::println("Неверный аргумент");
	}
	else {
		vect.erase(vect.begin() + index);
		std::println("Поседовательность с индексом {} удалена", index);
	}

}
Sequence* FindSequenceWithMinValue(const std::vector<std::unique_ptr<Sequence>>& vect, int n) {
	if (vect.size() != 0) {
		int MinIndex = 0;
		int MinValue = (*vect[0])(n);
		for (int i = 0; i < vect.size(); i++) {
			if ((*vect[i])(n) < MinValue) {
				MinValue = (*vect[i])(n);
				MinIndex = i;
			}
		}
		return vect[MinIndex].get();
	}
	else {
		return nullptr;
	}
}

export void Menu(std::vector<std::unique_ptr<Sequence>>& vect) {

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

		switch (choice) {
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
			Sequence* ptr = FindSequenceWithMinValue(vect, n);
			if (ptr == nullptr) {
				std::println("Список пуст");
			}
			else {
				std::println("Последовательность с мин n-ым членом: {}", (*ptr)(n));
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