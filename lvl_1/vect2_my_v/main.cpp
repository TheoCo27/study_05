
// This main is not given with the subject

#include "vect2.hpp"


int main()
{
    vect2 v1; // 0, 0
    vect2 v2(1, 2); // 1, 2
    vect2 v4 = v2; // 1, 2
    const vect2 v3(v2);
    std::cout << "v1 = " << v1 << std::endl; // 0, 0
    std::cout << "v1 = " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl; //should be identical with revious line
    std::cout << "v2 = " << v2 << std::endl; // 1, 2
    std::cout << "v3 = " << v3 << std::endl; // 1, 2
    std::cout << "v4 = " << v4 << std::endl; // 1, 2
    std::cout << "v4++ = " << v4++ << std::endl; // 2, 3 (print 1, 2)
    std::cout << "++v4 = " << ++v4 << std::endl;// 3, 4
    std::cout << "v4-- = " << v4-- << std::endl;//2, 3 (print 3, 4)
    std::cout << "--v4 = " << --v4 << std::endl;//1, 2
	v2 += v3; // 2, 4
	std::cout << v2 << std::endl;
    v1 -= v2; // -2, -4
	std::cout << v1 << std::endl;
    v2 = v3 + v3 * 2; // 3, 6
	std::cout << v2 << std::endl;
    v2 = 3 * v2; // 9, 18
	std::cout << v2 << std::endl;
    v2 += v2 += v3;
	std::cout << "v2 += v2 += v3> " << v2 << std::endl;// 20, 40
    v1 *= 42; // -84, -168
	std::cout << v1 << std::endl;
    v1 = v1 - v1 + v1; // nothing change
	std::cout << v1 << std::endl;
    v1[1] = 12;
	std::cout << v1 << std::endl;
    std::cout << -v1 << std::endl;
    std::cout << v1[1] << std::endl;
    std::cout << (v1 == v3) << std::endl;
    std::cout << (v1 != v3) << std::endl;
}

// int main()
// {
//     vect2 v1; // 0, 0
//     vect2 v2(1, 2); // 1, 2
//     vect2 v4 = v2; // 1, 2
//     const vect2 v3(v2);
//     std::cout << "v1 = " << v1 << std::endl; // 0, 0
//     std::cout << "v1 = " << "{ " << v1[0] << ", " << v1[1] << "}" << std::endl; //should be identical with revious line
//     std::cout << "v2 = " << v2 << std::endl; // 1, 2
//     std::cout << "v3 = " << v3 << std::endl; // 1, 2
//     std::cout << "v4 = " << v4 << std::endl; // 1, 2
//     std::cout << "v4++ = " << v4++ << std::endl; // 2, 3 (print 1, 2)
//     std::cout << "++v4 = " << ++v4 << std::endl;// 3, 4
//     std::cout << "v4-- = " << v4-- << std::endl;//2, 3 (print 3, 4)
//     std::cout << "--v4 = " << --v4 << std::endl;//1, 2

//     v2 += v3; // 2, 4
//     v1 -= v2; // -2, -4
//     v2 = v3 + v3 * 2; // 3, 6
//     v2 = 3 * v2; // 9, 18
//     v1 *= 42; // -84, -168
//     v1 = v1 - v1 + v1; // nothing change
//     v[1] = 12;
//     std::cout << -v1 << std::endl;
//     std::cout << v1[1] << std::endl;
//     std::cout << v1 == v3 << std::endl;
//     std::cout << v1 != v3 << std::endl;

// }
