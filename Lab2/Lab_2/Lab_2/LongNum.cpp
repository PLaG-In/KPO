#include "stdafx.h"
#include "LongNum.h"

LongNum::LongNum()
	: m_isPositive(true)
{
}

LongNum::LongNum(pair<vector<int>, bool> number)
	: m_num(number.first)
	, m_size(number.first.size())
	, m_isPositive(number.second)
{
}

LongNum::LongNum(unsigned number)
	: m_isPositive(true)
{
	unsigned int num = number;
	do
	{
		m_num.push_back(num % 10);
		num /= 10;
	} while (num);

	m_size = m_num.size();
}

LongNum::~LongNum()
{
}

vector<int> LongNum::ToVector(string const& str)
{
	vector<int> number;
	char z[1];
	for (int i = (int)str.length() - 1; i >= 0; i--)
	{
		z[0] = str[i];
		number.push_back(atoi(z));
	}
	while (number.size() > 1 && number.back() == 0)
	{
		number.pop_back();
	}

	return number;
}

const LongNum LongNum::Sqr(const LongNum &number) const
{
	return number * number;
}

const LongNum LongNum::Sqrt(const LongNum &number) const
{
	if (number.GetVector().size() == 1 && number.GetVector()[0] == 0)
	{
		return LongNum();
	}

	LongNum start;
	LongNum end = number;
	LongNum middle;
	for (;;)
	{
		middle = (start + end) / LongNum(2);
		if (middle * middle == number)
		{
			return middle;
		}
		else
		{
			if (middle * middle > number)
			{
				if (end == middle)
				{
					return middle;
				}
				end = middle;
			}
			else
			{
				if (middle * middle < number)
				{
					if (start == middle)
					{
						return middle;
					}
				}
				start = middle;
			}
		}
	}
}

string LongNum::ToString()
{
	string result = "";

	for (size_t i = 0; i < m_num.size(); ++i)
	{
		result = to_string(m_num[i]) + result;
	}
	if (!m_isPositive)
	{
		result = "-" + result;
	}
	return result;
}

size_t LongNum::GetSize() const
{
	return m_size;
}

vector<int> LongNum::GetVector() const
{
	return m_num;
}

LongNum& LongNum::operator = (const LongNum &other)
{
	if (addressof(other) != this)
	{
		vector<int> tmp;
		this->m_size = other.m_size;
		this->m_isPositive = other.m_isPositive;
		tmp = other.m_num;
		swap(m_num, tmp);
	}

	return *this;
}

const LongNum LongNum::operator + (const LongNum &other) const
{
	LongNum result;
	size_t length;
	if (m_num.size() > other.m_num.size())
	{
		length = m_num.size();
	}
	else
	{
		length = other.m_num.size();
	}

	unsigned part, overBase;
	overBase = 0;
	part = 0;

	for (size_t i = 0; i < length; i++)
	{
		part = 0;
		part = GetLevel(i) + other.GetLevel(i) + overBase;
		result.m_num.push_back(part % 10);
		overBase = part / 10;
	}

	if (overBase > 0)
	{
		result.m_num.push_back(overBase);
	}
	return result;
}

unsigned LongNum::GetLevel(const size_t arg) const
{
	if (m_num.size() > arg)
	{
		return m_num[arg];
	}
	return 0;
}

const LongNum LongNum::operator - (const LongNum &other) const
{
	if (other.m_num.size() == 1 && other.m_num[0] == 0)
	{
		return *this;
	}
	if (this->m_num.size() == 1 && this->m_num[0] == 0)
	{
		LongNum result = other;
		result.m_isPositive = false;
		return result;
	}

	if (*this <= other)
	{
		LongNum result = other;
		result.m_isPositive = false;
		size_t len = other.m_num.size();
		for (size_t i = 0; i < len; i++)
		{
			if (i < (len - 1))
			{
				result.m_num[i + 1] --;
				result.m_num[i] += 10;
			}
			result.m_num[i] -= this->GetLevel(i);
			if (result.m_num[i] / 10 > 0)
			{
				result.m_num[i + 1]++;
				result.m_num[i] %= 10;
			}
		}

		result.DropZeros();
		return result;
	}

	LongNum result = *this;
	size_t len = m_num.size();
	for (size_t i = 0; i < len; i++)
	{
		if (i < (len - 1))
		{
			result.m_num[i + 1] --;
			result.m_num[i] += 10;
		}
		result.m_num[i] -= other.GetLevel(i);
		if (result.m_num[i] / 10 > 0)
		{
			result.m_num[i + 1]++;
			result.m_num[i] %= 10;
		}
	}
	result.DropZeros();
	return result;
}

const LongNum LongNum::operator * (const LongNum &other) const
{
	if ((this->m_num.size() == 1 && this->m_num[0] == 0) || (other.m_num.size() == 1 && other.m_num[0] == 0))
	{
		return LongNum(0);
	}

	LongNum result;
	size_t len = m_num.size() + other.m_num.size() + 1;
	result.m_num.resize(len, 0);
	for (size_t i = 0; i < m_num.size(); ++i)
	{
		for (size_t j = 0; j < other.m_num.size(); j++)
		{
			result.m_num[i + j] += m_num[i] * other.m_num[j];
		}
	}
	for (size_t i = 0; i < len - 1; i++)
	{
		result.m_num[i + 1] += result.m_num[i] / 10;
		result.m_num[i] %= 10;
	}
	result.DropZeros();
	return result;
}

const LongNum LongNum::operator / (const LongNum &other) const
{
	if (other.m_num.size() == 1 && other.m_num[0] == 0)
	{
		throw runtime_error("Error: Division by zero");
	}
	if (*this < other)
	{
		return 0;
	}

	LongNum result;
	LongNum curValue;
	result.m_num.resize(m_num.size(), 0);
	for (int i = m_num.size() - 1; i >= 0; i--)
	{
		curValue.Increase();
		curValue.m_num[0] = m_num[i];
		int multiplier = 0;
		int lowerBound = 0;
		int upperBound = 10;
		while (lowerBound <= upperBound)
		{
			int m = (lowerBound + upperBound) / 2;
			LongNum cur = other * m;
			if (cur <= curValue)
			{
				multiplier = m;
				lowerBound = m + 1;
			}
			else
				upperBound = m - 1;
		}
		result.m_num[i] = multiplier;
		curValue = curValue - other * multiplier;
		curValue.DropZeros();
	}

	result.DropZeros();
	return result;
}

void LongNum::DropZeros()
{
	bool zeroFound = true;
	while ((m_num.size() > 0) && zeroFound)
	{
		zeroFound = false;
		if (m_num[m_num.size() - 1] == 0)
		{
			m_num.pop_back();
			zeroFound = true;
		}
	}
}

void LongNum::Increase()
{
	m_num.resize(m_num.size() + 1);
	for (int i = m_num.size() - 1; i >= 1; i--)
	{
		m_num[i] = m_num[i - 1];
	}
}

const bool LongNum::operator < (LongNum const & other) const
{
	size_t i = 0;
	if (m_num.size() < other.m_num.size())
	{
		return true;
	}
	if (m_num.size() > other.m_num.size())
	{
		return false;
	}
	if (m_num.size() == other.m_num.size())
	{
		for (int i = static_cast<int>(m_num.size() - 1); i >= 0; --i)
		{
			if (m_num[i] < other.m_num[i])
			{
				return true;
			}
			if (m_num[i] > other.m_num[i])
			{
				return false;
			}
		}
	}

	return false;
}

const bool LongNum::operator > (LongNum const & other) const
{
	if (m_num.size() > other.m_num.size())
	{
		return true;
	}
	if (m_num.size() < other.m_num.size())
	{
		return false;
	}
	if (m_num.size() == other.m_num.size())
	{
		for (int i = static_cast<int>(m_num.size() - 1); i >= 0; --i)
		{
			if (m_num[i] > other.m_num[i])
			{
				return true;
			}
			if (m_num[i] < other.m_num[i])
			{
				return false;
			}
		}
	}
	return false;
}

bool const LongNum::operator <= (LongNum const & other) const
{
	return !(*this > other);
}

bool const LongNum::operator >= (LongNum const & other) const
{
	return !(*this > other);
}

bool const LongNum::operator == (LongNum const & other) const
{
	return !(*this == other);
}