export module lab2_utils;
import std;
import LabUtils;

void HandInputVector(int size, std::vector<int>& subsequence);
void RandInputVector(int size, std::vector<int>& subsequence);

export void OutputVector(int size, const std::vector<int>& subsequence) {
    std::print("Введенная последовательность: ");
    for (int i = 0; i < size; i++) {
        std::print("{} ", subsequence.at(i));
    }
    std::print("\n");

}

export void InputVector(std::vector<int>& subsequence) {
    bool isCorrect = true;
    do
    {

        int fillingMethod = 1;
        int n = 0;
        std::println("Выберите способ заполнения последовательности: ");
        std::println("[1] - Вручную \n[2] - Слуйчайно");
        std::print("> ");
        std::cin >> fillingMethod;
        PrintSeparLine(25);
        std::print("Введите размер последовательности: ");
        std::cin >> n;
        if (n < 1) {
            std::println("Вы ввели некорректные данные, попробуйте еще раз! ");
            isCorrect = false;
            continue;
        }
        if (fillingMethod == 1) {
            HandInputVector(n, subsequence);
            PrintSeparLine(25);
            OutputVector(n, subsequence);
        }
        else {
            RandInputVector(n, subsequence);
            PrintSeparLine(25);
            OutputVector(n, subsequence);
        }
        isCorrect = true;
    } while (isCorrect == false);
}



export int SumSubsequence(const std::vector<int>& subsequence) {

    int sum = 0;
    for (int i = 0; i < subsequence.size(); i++) {
        sum += subsequence.at(i);
    }
    return sum;
}

void HandInputVector(int size, std::vector<int>& subsequence) {
    std::print("Введите элементы последовательности(целые числа): ");
    for (int i = 0; i < size; i++) {
        int k = 0;
        std::cin >> k;
        subsequence.push_back(k);
    }
}

void RandInputVector(int size, std::vector<int>& subsequence) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-50, 50);

    for (int i = 0; i < size; i++) {
        subsequence.push_back(dist(gen));
    }
  
}
