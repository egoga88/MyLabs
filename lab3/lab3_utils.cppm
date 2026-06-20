export module lab3_utils;
import std;
import classes;
using namespace std;

export int FindSequenceWithMinValue(const std::vector<SquareSequence>& vect, int n) {
    if (vect.size() != 0) {
        size_t MinIndex = 0;
        int MinValue = vect[0](n);
        for (size_t i = 0; i < vect.size(); i++) {
            if (vect[i](n) < MinValue) {
                MinValue = vect[i](n);
                MinIndex = i;
            }
        }
        return static_cast<int>(MinIndex);
    }
    else {
        return -1;
    }
}
export void AddSequence(SequenceContainer& container) {

    size_t index = 0;
    println("Введите индекс вставки: ");
    std::cin >> index;
    int c = 0;
    println("Введите значение сдвига с:");
    std::cin >> c;
    try
    {
        container.AddSequence(index, SquareSequence(c));
        std::println("Последовательность добавлена!");
    }
    catch (const std::exception& e)
    {
        std::println("Ошибка! {}", e.what());
    }

}
export void RemoveSequence(SequenceContainer& container) {
    size_t index = 0;
    println("Введите индекс: ");
    std::cin >> index;
    try
    {
        container.RemoveSequence(index);
        std::println("Последовательность удалена!");
    }
    catch (const std::exception& e)
    {
        std::println("Ошибка! {}", e.what());
    }
}
export void OutputSequenceWithMinValue(const SequenceContainer& container) {
    int minIndex = FindSequenceWithMinValue(container.getVector(), container.getN());
    if (minIndex >= 0) {
        println("Последовательность с минимальным n-ым членом: {}. {}", minIndex, container.getVector()[minIndex](container.getN()));
    }
    else {
        println("Список пуст");
    }

}
export void InputN(SequenceContainer& container) {
    int n = 0;
    print("Введите n:");
    cin >> n;
    container.setN(n);
}
export void OutputVector(const SequenceContainer& container) {
    vector<SquareSequence> vect = container.getVector();
    for (size_t i = 0; i < vect.size(); i++) {
        std::println("{}. {}", i, vect[i](container.getN()));
    }
}

