module; 
export import std;

export module LabUtils;


export void printMetadata(int labnum, std::string author, int variant = 1, std::string group = "6113") {
    std::println("-----------------------");
    std::println("Лабораторная №{}", labnum);
    std::println("Группа: {}", group);
    std::println("Автор: {}", author);
    std::println("Вариант: {}", variant);
    std::println("-----------------------");
}
export void pause(std :: string text = "Нажмите enter, чтобы закрыть окно...") {
   std :: print("{}", text);
   std :: cin.clear();
   std::cin.ignore(std::numeric_limits<std::streamsize> ::max(), '\n');
   std::cin.get();
}
export void printSeparLine(int size = 15) {
    for (int i = 0; i < size; i++) {
        std::cout << "-";
    }
    std::cout << "\n";
}
