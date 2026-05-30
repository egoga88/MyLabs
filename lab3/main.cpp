import std;
import LabUtils;
import lab3_utils;
import classes;
using namespace std;



void Menu(std::vector<SquareSequence>& vect) {
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
		case 1: {
			AddSequence(vect);
			PrintSeparLine(22);
			break;
		}	
		case 2:
			RemoveSequence(vect);
			PrintSeparLine(22);
			break;
		case 3:
			OutputVector(vect, n);
			PrintSeparLine(22);
			break;
		case 4: {
			OutputSequenceWithMinValue(vect, n);
			PrintSeparLine(22);
			break;
		}
		case 5:
			InputN(n);
			PrintSeparLine(22);
			break;
		}
	}
}

int main() {
	PrintMetadata(3, 10);
	vector<SquareSequence> vect;
	Menu(vect);
	return 0;
}