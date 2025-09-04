/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 21:26:44 by theog             #+#    #+#             */
/*   Updated: 2025/09/04 22:10:02 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <vector>
#include <iostream>

class vect2{
    private:
        std::vector<int> vec;
    public:
        vect2();
        vect2(int a, int b);
        vect2(const vect2& other);
        ~vect2();
        vect2& operator=(const vect2& other);
        std::vector<int> get_vec(void);
        int operator[](int index) const;
        int& operator[](int index);
        vect2 operator+(const vect2& other);
        vect2 operator++(void);
        vect2 operator++(int);
        vect2 operator--(void);
        vect2 operator--(int);
        vect2 operator*(const vect2& other);

};

std::ostream& operator<<(std::ostream& stream, const vect2& to_print);