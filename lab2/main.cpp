import std;
import LabUtils;
using namespace std;
import lab2_utils;






int main(){
    PrintMetadata(2, "Аббасов Теймур");
  
    int n = 0;
    vector<int> vec(n, 0);

    ChoiceFillingMethod(n, vec);
    println("Сумма всех элементов последовательности: {}", SumSubsequence(n, vec));
    return 0;
}