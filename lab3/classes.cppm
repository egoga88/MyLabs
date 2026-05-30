export module classes;


export class SquareSequence {
private:
	int c;
public:
	SquareSequence() : c(0) {}
	SquareSequence(int value) {
		c = value;
	}
	int operator()(int n) const {
		return n * n + c;
	}
	int GetC() const {
		return c;

	}
};
