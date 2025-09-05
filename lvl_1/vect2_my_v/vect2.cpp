/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 21:34:07 by theog             #+#    #+#             */
/*   Updated: 2025/09/05 10:58:04 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2()
{
    vec.push_back(0);
    vec.push_back(0);
}

vect2::vect2(int a, int b)
{
    vec.push_back(a);
    vec.push_back(b);
}

vect2::vect2(const vect2& other)
{
    vec.push_back(other.vec[0]);
    vec.push_back(other.vec[1]);
}

int vect2::operator[](int index) const
{
    if (index < 0 || index >= 2)
        throw std::out_of_range("Index out of range");
    return vec[index];
}

int& vect2::operator[](int index)
{
    if (index < 0 || index >= 2)
        throw std::out_of_range("Index out of range");
    return vec[index];
}

vect2::~vect2()
{
    vec.clear();
}

vect2& vect2::operator=(const vect2& other) // <-- FIX ICI
{
    if (this != &other)
    {
        vec[0] = other.vec[0];
        vec[1] = other.vec[1];
    }
    return *this;
}

std::vector<int>& vect2::get_vec(void)
{
    return vec;
}


vect2 vect2::operator+(const vect2& other) const
{
    vect2 result;

    result.vec[0] = this->vec[0] + other.vec[0];
    result.vec[1] = this->vec[1] + other.vec[1];
    return result;
}

vect2 vect2::operator-(const vect2& other) const
{
    vect2 result;

    result.vec[0] = this->vec[0] - other.vec[0];
    result.vec[1] = this->vec[1] - other.vec[1];
    return result;
}

vect2 vect2::operator-(void)const
{
    vect2 result;

    result.vec[0] = -this->vec[0];
    result.vec[1] = -this->vec[1];
    return result;
}

vect2 vect2::operator++(void)
{
    this->vec[0] += 1;
    this->vec[1] += 1;
    return (*this);
}

vect2 vect2::operator++(int)
{
    vect2 copy(*this);

    this->vec[0] += 1;
    this->vec[1] += 1;
    return (copy);
}

vect2 vect2::operator--(void)
{
    this->vec[0] -= 1;
    this->vec[1] -= 1;
    return (*this);
}

vect2 vect2::operator--(int)
{
    vect2 copy(*this);

    this->vec[0] -= 1;
    this->vec[1] -= 1;
    return (copy);
}

vect2 vect2::operator*(const vect2& other) const
{
    vect2 result;

    result.vec[0] = this->vec[0] * other.vec[0];
    result.vec[1] = this->vec[1] * other.vec[1];
    return result;
}

vect2 vect2::operator*(int other) const
{
    vect2 result;

    result.vec[0] = this->vec[0] * other;
    result.vec[1] = this->vec[1] * other;
    return result;

}

vect2 operator*(const int other, const vect2& v)
{
    return (v * other);
}

vect2 vect2::operator+=(const vect2& other){
    *this = *this + other;
    return (*this);
}
vect2 vect2::operator-=(const vect2& other)
{
    *this = *this  - other;
    return (*this);
}
vect2 vect2::operator*=(const vect2& other)
{
    *this = *this * other;
    return(*this);
}

vect2 vect2::operator*=(int other)
{
    *this = *this * other;
    return(*this);
}

bool vect2::operator==(const vect2& other) const
{
    if (this->vec[0] == other.vec[0] && this->vec[1] == other.vec[1])
        return true;
    else
        return false;
}

bool vect2::operator!=(const vect2& other) const
{
    if (!(*this == other))
        return true;
    else    
        return false;
}

std::ostream& operator<<(std::ostream& stream, const vect2& to_print)
{
    stream << "{" << to_print[0] << ", " << to_print[1] << "}";
    return stream;
}
