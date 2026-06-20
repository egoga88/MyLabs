export module classes;
import std;

export class SquareSequence {
private:
    int c;
public:
    SquareSequence() : c(0) {}
    SquareSequence(int value) : c(value) {}
    int operator()(int n) const {
        return n * n + c;
    }
    int GetC() const {
        return c;
    }
};

export class SequenceContainer {
private:
    std::vector<SquareSequence> vect;
    int _n;
public:
    SequenceContainer() : _n(0) {}
    const std::vector<SquareSequence>& getVector()const {
        return vect;
    }
    void AddSequence(size_t index, const SquareSequence& AddableSequence)
    {
        if (index > vect.size()) {
            throw std::out_of_range("Выход за границы!");
        }
        vect.insert(vect.begin() + index, AddableSequence);
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


