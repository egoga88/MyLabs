import std;
import LabUtils;
using namespace std;
import lab2_utils;






int main(){
    PrintMetadata(2, "Аббасов Теймур");
  
    
    vector<int> vec(0, 0);

    InputVector(vec);
    println("Сумма всех элементов последовательности: {}", SumSubsequence(vec));
    return 0;
}