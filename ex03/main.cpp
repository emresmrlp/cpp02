/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:53:52 by ysumeral          #+#    #+#             */
/*   Updated: 2025/09/04 21:12:40 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
    Point A(0.0f, 0.0f);
    Point B(5.0f, 0.0f);
    Point C(0.0f, 5.0f);
    Point inside(1.0f, 1.0f);
    Point outside(6.0f, 6.0f);
    Point onEdge(2.5f, 0.0f);
    Point vertex(0.0f, 0.0f);

    std::cout << "Inside point: " << bsp(A, B, C, inside) << std::endl;
    std::cout << "Outside point: " << bsp(A, B, C, outside) << std::endl;
    std::cout << "On edge point: " << bsp(A, B, C, onEdge) << std::endl;
    std::cout << "Vertex point: " << bsp(A, B, C, vertex) << std::endl;
    return 0;
}
