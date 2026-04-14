import std;
import LabUtils;
using namespace std;


class SquareSequence{
	private:
		int c;
	public:
		SquareSequence(int value) : c(value){}
		int operator()(int n) {
			return n * n + c;
		}
		int GetC() {
			return c;

		}



};

void OutputVector(const std::vector<SquareSequence>& vect) {
	for (int i = 0; i < vect.size(); i++) {
		std::println("{}", vect.at(SquareSequence(i));
	}
}
void InputVector(std::vector<SquareSequence>& vect, int size) {
	int k = 0;
	for (int i = 0; i < size; i++) {
		cin >> k;
		vect.push_back(SquareSequence(k));
	}
}



int main() {
	PrintMetadata(2, "Аббасов Теймур", 10);

	vector< SquareSequence> vect;
	InputVector(vect, 3);
	OutputVector(vect);
	

	return 0;
}