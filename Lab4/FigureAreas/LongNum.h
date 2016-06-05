#pragma once
#include <vector>

using namespace std;

class LongNum final
{
public:
	LongNum();
	LongNum(unsigned number);
	LongNum(pair<vector<int>, bool> number);
	~LongNum();

	vector<int> ToVector(string const & str);

	LongNum& operator = (const LongNum &other);

	const LongNum operator + (LongNum const & other) const;
	const LongNum operator - (LongNum const & other) const;
	const LongNum operator * (LongNum const & other) const;
	const LongNum operator / (const LongNum &other) const;

	const bool operator > (LongNum const & other) const;
	const bool operator < (LongNum const & other) const;
	bool const operator <= (LongNum const & other) const;
	bool const operator >= (LongNum const & other) const;

	size_t GetSize() const;
	vector<int> GetVector() const;
	string ToString();
	unsigned GetLevel(const size_t arg) const;

private:
	void Increase();
	void DropZeros();
	bool m_isPositive;
	size_t m_size;
	vector<int> m_num;
};
bool const operator == (const LongNum &num1, const LongNum &num2);
LongNum Sqr(const LongNum &number);
LongNum Sqrt(const LongNum &number);