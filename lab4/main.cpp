import std;
import LabUtils;
import lab4_utils;
import classes;


void Menu() {

	int choice = 1;
	SequenceContainer container;
	while (choice != 0) {
		std::println("[1] Добавить новую последовательность");
		std::println("[2] Удалить последовательность");
		std::println("[3] Вывести значения n-го члена всех последовательностей");
		std::println("[4] Найти последовательность с минимальным n-ым членом");
		std::println("[5] Задать значение n(текущий {})", container.getN());
		std::println("[0] Выход");
		std::print("Выберите пункт меню: ");
		std::cin >> choice;
		PrintSeparLine(22);
		switch (choice) {
		case 1:
			AddSequence(container);
			PrintSeparLine(22);
			break;
		case 2:
			RemoveSequence(container);
			PrintSeparLine(22);
			break;

		case 3:
			OutputVector(container);
			PrintSeparLine(22);
			break;
		case 4: {
			OutputSequenceWithMinValue(container);
			PrintSeparLine(22);
			break;
		}
		case 5:
			InputN(container);
			break;
		}
	}
}





int main() {
	PrintMetadata(4, 10);
	Menu();

	return 0;
}