export module lab4_utils;
import std;
import LabUtils;
import classes;



export void OutputVector(const SequenceContainer& container) {
	const auto& vect = container.getVector();
	int n = container.getN();
	for (int i = 0; i < vect.size(); i++) {
		std::println("{}. {} при n: {}", i, (*vect.at(i))(n), n);
	}
}
export void AddSequence(SequenceContainer & container) {
	int choice = 0;
	std::println("[1] - Квадратичная\n[2] - Последовательность факториалов");
	std::println("Выберите тип последовательности:");
	std::cin >> choice;
	
	size_t index = 0;
	std::println("Введите индекс вставки: ");
	std::cin >> index;
	if (choice == 1) {
		int c = 0;
		std::println("Введите значение сдвига с:");
		std::cin >> c;
		try
		{
			container.AddSequence(index, std::make_unique<SquareSequence>(c));
			std::println("Последовательность добавлена!");
		}
		catch (const std::exception& e)
		{
			std::println("Ошибка! {}", e.what());
		}
	}
	else
	{
		try
		{
			container.AddSequence(index, std::make_unique<FactorialSequence>());
			std::println("Последовательность добавлена!");
		}
		catch (const std::exception& e)
		{
			std::println("Ошибка! {}", e.what());
		}

	}
}

export void RemoveSequence(SequenceContainer& container) {
	size_t index = 0;
	std::println("Введите индекс: ");
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
Sequence* FindSequenceWithMinValue(const SequenceContainer& container) {
	const auto& vect = container.getVector();
	int n = container.getN();
	if (vect.size() != 0) {
		size_t MinIndex = 0;
		int MinValue = (*vect[0])(n);
		for (size_t i = 0; i < vect.size(); i++) {
			if ((*vect[i])(n) < MinValue) {
				MinValue = (*vect[i])(n);
				MinIndex = i;
			}
		}
		return vect[MinIndex].get();
	}
	else {
		return nullptr;
	}
}

export void OutputSequenceWithMinValue(const SequenceContainer& container) {
	Sequence* seq = FindSequenceWithMinValue(container);
	if (seq != nullptr) {
		std::println("{}", (*seq)(container.getN()));
	}
	else
	{
		std::println("Список пуст");
	}
	
}
export void InputN(SequenceContainer& container) {
	int n = 0;
	std::print("Введите n: ");
	std::cin >> n;
	container.setN(n);
}
