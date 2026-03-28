import std;
import LabUtils;
using namespace std;


int main(){
    PrintMetadata(1, "Аббасов Теймур");

    bool correct = true;

    do
    {
        print("Введите кол-во элементов последовательности: ");
        int n =0;
        cin >> n;
        if (n <1) {
            correct = false;
            println("Вы ввели некорректное число");
            continue;
        }
        print("Введите элементы последовательности: ");
        int sum = 0;
        for (int i = 0; i < n; i++){
            int k = 0;
            cin >> k;
            sum +=k;
        }
        println("---------------------------");
        println("Кол-во элементов полседовательности: {}", n);
        println("Сумма всех элементов: {}", sum);
        correct = true;
        
    } while (correct == false);
    
    return 0;
}

