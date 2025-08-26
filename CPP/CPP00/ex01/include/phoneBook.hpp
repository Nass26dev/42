/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:47:04 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/29 15:31:44 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
# include <iostream>
# include <iomanip>
# include <sstream>

class PhoneBook {
private:
    Contact contacts[8];
    int nbContacts;
    int oldestIndex;
public:
    PhoneBook();
    void addContact(const Contact& c);
    void displayContacts() const;
    void displayContactDetail(int index) const;
    int getNbContacts() const;
    bool isValidIndex(int index) const;
};

#endif
