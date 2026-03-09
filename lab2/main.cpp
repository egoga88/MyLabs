import std;
import LabUtils;
using namespace std;


int main(){
    printMetadata(2, "Аббасов Теймур");
    print("Введите кол-во элементов последовательности: ");
    


    int n = 0;
    cin >> n;
    vector<int>(n, 0);
    printSeparLine(22);
    println("Выберите способ заполнения: \n[1] - Вручную. \n[2] - Случайным образом.");
    print(">");
    int fillingMethod = 1;
    cin >> fillingMethod;
    printSeparLine(22);



    pause();
    return 0;
}