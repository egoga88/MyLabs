export module classes;
import std;


export class Sequence {
public:
	virtual int operator()(int n) const = 0;
	virtual ~Sequence() = default;
};
export class SquareSequence : public Sequence {
private:
	int c;
public:
	SquareSequence() : c(0) {}
	SquareSequence(int value) : c(value) {}
	int operator()(int n) const override {
		return n * n + c;
	}
	int GetC() const {
		return c;

	}
};
export class FactorialSequence : public Sequence {
public:
	int operator()(int n) const override {
		if (n <= 1) return 1;
		if (n > 1) {
			int res = 1;
			for (int i = n; i > 1; i--) {
				res *= i;
			}
			return res;
		}
	}
};

export class SequenceContainer {
private:
    std::vector<std::unique_ptr<Sequence>> vect;
    int _n;
public:
    SequenceContainer() : _n(0) {}
    const std::vector<std::unique_ptr<Sequence>>& getVector()const {
        return vect;
    }
    void AddSequence(size_t index, std::unique_ptr<Sequence> AddableSequence)
    {
        if (index > vect.size()) {
            throw std::out_of_range("Выход за границы!");
        }
        vect.insert(vect.begin() + index, std::move(AddableSequence));
    }
    void RemoveSequence(size_t index) {
        if (index >= vect.size()) {
            throw std::out_of_range("Выход за границы!");
        }
        vect.erase(vect.begin() + index);
    }
    void setN(int n) {
        _n = n;
    }
    int getN() const {
        return _n;
    }
};