import std;
import LabUtils;


int main() {
	PrintMetadata(4, 10);
	std::vector< std::unique_ptr<Sequence>> vect;
	Menu(vect);

	return 0;
}