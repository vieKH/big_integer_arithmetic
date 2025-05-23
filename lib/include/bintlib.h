﻿#pragma once

#include <list>
#include <tuple>
#include <vector>
#include <string>
#include <iostream>
#include <exception>

class BigInt
{
private:
	bool _is_negative;
	std::vector<uint32_t> _chunks;
public:
	static const uint64_t BASE = (uint64_t)UINT32_MAX + 1;

	BigInt(uint32_t number = 0, bool is_negative = false);
	BigInt(const std::string& number);
	BigInt(const std::vector<uint32_t>& chunks, bool is_negative= false);

	static std::vector<uint32_t> parse_number(const std::string& number, uint64_t base = (uint64_t)UINT32_MAX + 1);
	static std::string concat_number(const std::vector<uint32_t>& chunks, bool is_negative = false, uint64_t base = (uint64_t)UINT32_MAX + 1);
	static int abs_cmp(const BigInt& number1, const BigInt& number2);
	static BigInt sub_chunks(const BigInt& lhs, const BigInt& rhs);
	static uint32_t leading_zeros(uint32_t value);
	static uint32_t estimate_quotient(const BigInt& dividend, const BigInt& divider);

	static BigInt abs(const BigInt& number);
	static BigInt sum(const BigInt& lhs, const BigInt& rhs);
	static BigInt sub(const BigInt& lhs, const BigInt& rhs);
	static BigInt simple_mul(const BigInt& lhs, const BigInt& rhs);
	static BigInt karatsuba_mul(const BigInt& lhs, const BigInt& rhs);
	static BigInt karatsuba_square(const BigInt& number);
	static std::pair<BigInt, BigInt> div(const BigInt& lhs, const BigInt& rhs);
	static BigInt mod(const BigInt& lhs, const BigInt& rhs);
	static BigInt gcd(const BigInt& lhs, const BigInt& rhs);
	static std::tuple<BigInt, BigInt, BigInt> extended_gcd(const BigInt& lhs, const BigInt& rhs);
	static BigInt BigInt::mod_inverse(const BigInt& a, const BigInt& m);
	static BigInt left_shift(const BigInt& number, uint32_t shift);
	static BigInt right_shift(const BigInt& number, uint32_t shift);
	static BigInt montgomery(const BigInt& rhs, const BigInt& lhs, const BigInt& module, const BigInt& R, const BigInt& n_prime);
	static BigInt montgomery_mul(const BigInt& rhs, const BigInt& lhs, const BigInt& module);
	static BigInt binary_pow(const BigInt& number, const BigInt& degree);
	static BigInt pow(const BigInt& number, const BigInt& degree, uint32_t base = 2);
	static BigInt montgomery_pow(const BigInt& number, const BigInt& degree, const BigInt& module, uint32_t base = 2);

	std::string to_string() const;
	double to_double() const;
	uint32_t BigInt::bit_length() const;

	BigInt& operator =(const BigInt& other);
	BigInt& operator =(const std::string& number_str);
	BigInt& operator +=(const BigInt& other);
	BigInt& operator -=(const BigInt& other);
	BigInt& operator *=(const BigInt& other);
	BigInt& operator /=(const BigInt& other);
	BigInt& operator %=(const BigInt& other);
	BigInt& operator >>=(uint32_t shift);
	BigInt& operator <<=(uint32_t shift);

	BigInt operator +(const BigInt& other) const;
	BigInt operator -(const BigInt& other) const;
	BigInt operator -() const;
	BigInt operator *(const BigInt& other) const;
	BigInt operator /(const BigInt& other) const;
	BigInt operator %(const BigInt& other) const;
	BigInt operator >>(uint32_t shift) const;
	BigInt operator <<(uint32_t shift) const;
	
	bool operator ==(const BigInt& other) const;
	bool operator !=(const BigInt& other) const;
	bool operator >(const BigInt& other) const;
	bool operator <(const BigInt& other) const;
	bool operator >=(const BigInt& other) const;
	bool operator <=(const BigInt& other) const;
	
	friend std::ostream& operator <<(std::ostream& os, const BigInt& number);
};