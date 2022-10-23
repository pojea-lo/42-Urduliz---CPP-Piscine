#include "Contact.hpp"

//constructor and destructor

//constructor vacio
Contact::Contact (void) {

	return;
}

Contact::~Contact (void) {
	
	return;
}

//getters and setters
std::string	Contact::getFirstName(void) const{
	
	return this->_firstName;
}
void	Contact::setFirstName (std::string	firstName) {

	this->_firstName = firstName;
	return;
}

std::string	Contact::getLastName(void) const{
	
	return this->_lastName;
}
void	Contact::setLastName (std::string	lastName) {

	this->_lastName = lastName;
	return;
}

std::string	Contact::getNickname(void) const{
	
	return this->_nickname;
}
void	Contact::setNickname (std::string	nickname) {

	this->_nickname = nickname;
	return;
}

std::string	Contact::getPhone(void) const{
	
	return this->_phone;
}
void	Contact::setPhone (std::string	phone) {

	this->_phone = phone;
	return;
}

std::string	Contact::getDarkestSecret(void) const{
	
	return this->_darkestSecret;
}
void	Contact::setDarkestSecret (std::string	darkestSecret) {

	this->_darkestSecret = darkestSecret;
	return;
}
