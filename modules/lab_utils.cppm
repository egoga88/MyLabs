export module LabUtils;

export import std;


void PrintSeparLine(int size);

export void PrintMetadata(int labnum, int variant = 1, std::string author = "Аббасов Теймур",  std::string group = "6113") {
    PrintSeparLine(25);
    std::println("{:>15} №{}","Лабораторная", labnum);
    std::println("{:>7}: {}", "Группа", group);
    std::println("{:>7}: {}", "Автор", author);
    std::println("{:>7}: {}", "Вариант", variant);
    PrintSeparLine(25);
}

export void PrintSeparLine(int size = 15) {
    for (int i = 0; i < size; i++) {
        std::cout << "-";
    }
    std::cout << "\n";
}
