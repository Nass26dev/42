/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 09:20:17 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/29 10:00:40 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    for (int i = 1; i < argc; i++)
    {
        std::string arg(argv[i]);
        
        for (size_t j = 0; j < arg.length(); j++)
            arg[j] = std::toupper(arg[j]);
        
        std::cout << arg;
        
        if (i < argc - 1)
            std::cout << " ";
    }
    
    std::cout << std::endl;
    return (0);
}
