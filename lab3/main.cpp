import std;
import LabUtils;
import classes;
import lab3_utils;

using namespace std;

void PrintMenu() {
    PrintMetadata(3, 10);
    SequenceContainer container;
    int choice = 1;
    while (choice != 0) {
        std::println("[1] Добавить новую последовательность");
        std::println("[2] Удалить последовательность");
        std::println("[3] Вывести значения n-го члена всех последовательностей");
        std::println("[4] Найти последовательность с минимальным n-ым членом");
        std::println("[5] Задать значение n(текущее {})", container.getN());
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
        case 4: 
            OutputSequenceWithMinValue(container);
            PrintSeparLine(22);
            break;
        
        case 5: 
            InputN(container);
            PrintSeparLine(22);
            break;
        
        }
    }
}

int main() {
    PrintMenu();

    return 0;
}