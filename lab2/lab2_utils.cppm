export module lab2_utils;
import std;
import LabUtils;

export void HandInputVector(int& size, std::vector<int>& subsequence) {
    bool isCorrect = true;
    do
    {
        std::print("Введите размер последовательности: ");
        std::cin >> size;
        if (size < 1) {
            std::println("Вы ввели некорректные данные, попробуйте еще раз! ");
            isCorrect = false;
            continue;
        }
        std::print("Введите элементы последовательности(целые числа): ");
        for (int i = 0; i < size; i++) {
            int k = 0;
            std::cin >> k;
            subsequence.push_back(k);
        }
        isCorrect = true;
    } while (isCorrect == false);
}

export void RandInputVector(int& size, std::vector<int>& subsequence) {
    bool isCorrect = true;
    do
    {
        std::print("Введите размер последовательности: ");
        std::cin >> size;
        if (size < 1) {
            std::println("Вы ввели некорректные данные, попробуйте еще раз! ");
            isCorrect = false;
            continue;
        }


        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, 100);

        for (int i = 0; i < size; i++) {
            subsequence.push_back(dist(gen));
        }


        isCorrect = true;
    } while (isCorrect == false);


}

export void OutputVector(int size, const std::vector<int>& subsequence) {
    std::print("Введенная последовательность: ");
    for (int i = 0; i < size; i++) {
        std::print("{} ", subsequence.at(i));
    }
    std::print("\n");

}

export void ChoiceFillingMethod(int& size, std::vector<int>& subsequence) {

    int fillingMethod = 1;
    std::println("Выберите способ заполнения последовательности: ");
    std::println("[1] - Вручную \n[2] - Слуйчайно");
    std::print("> ");
    std::cin >> fillingMethod;
    PrintSeparLine(25);
    if (fillingMethod == 1) {
        HandInputVector(size, subsequence);
        PrintSeparLine(25);
        OutputVector(size, subsequence);
    }
    else if (fillingMethod == 2) {
        RandInputVector(size, subsequence);
        PrintSeparLine(25);
        OutputVector(size, subsequence);
    }
    else {
        RandInputVector(size, subsequence);
        PrintSeparLine(25);
        OutputVector(size, subsequence);
    }
}

export int SumSubsequence(int size, const std::vector<int>& subsequence) {

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += subsequence.at(i);
    }
    return sum;
}