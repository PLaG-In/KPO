#pragma once
class LongNum
{
public:
	LongNum();
	LongNum(unsigned number);
	LongNum(pair<std::vector<int>, bool> number);
	~LongNum();

	static vector<int> ToVector(string const & str);

	LongNum& operator = (const LongNum &other);

	const LongNum operator + (LongNum const & other) const;
	const LongNum operator - (LongNum const & other) const;
	const LongNum operator * (LongNum const & other) const;
	const LongNum operator / (const LongNum &other) const;

	const bool operator > (LongNum const & other) const;
	const bool operator < (LongNum const & other) const;
	bool const operator <= (LongNum const & other) const;
	bool const operator >= (LongNum const & other) const;
	bool const operator == (LongNum const & other) const;

	size_t GetSize() const;
	std::vector<int> GetVector() const;
	std::string ToString();
	unsigned GetLevel(const size_t arg) const;

	const LongNum Sqr(const LongNum &number) const;
	const LongNum Sqrt(const LongNum &number) const;

private:
	void Increase();
	void DropZeros();
	bool m_isPositive;
	size_t m_size;
	std::vector<int> m_num;
};
