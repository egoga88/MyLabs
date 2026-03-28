module; 
export import std;

export module LabUtils;

void PrintSeparLine(int size);

export void PrintMetadata(int labnum, std::string author, int variant = 1, std::string group = "6113") {
    PrintSeparLine(25);
    std::println("Лабораторная №{}", labnum);
    std::println("Группа: {}", group);
    std::println("Автор: {}", author);
    std::println("Вариант: {}", variant);
    PrintSeparLine(25);
}
export void Pause(std :: string text = "Нажмите enter, чтобы закрыть окно...") {
   std :: print("{}", text);
   std :: cin.clear();
   std::cin.ignore(std::numeric_limits<std::streamsize> ::max(), '\n');
   std::cin.get();
}
export void PrintSeparLine(int size = 15) {
    for (int i = 0; i < size; i++) {
        std::cout << "-";
    }
    std::cout << "\n";
}
