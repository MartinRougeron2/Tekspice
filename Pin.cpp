/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-tekspice-martin.rougeron
** File description:
** IComponent
*/

#include "IComponent.hpp"

nts::Pin::Pin(std::string name)
{
    this->_name = name;
}

nts::Pin::Pin(nts::Pin *new_pin)
{
    this->_type = new_pin->get_type();
    this->_name = new_pin->get_name();
    this->_state = new_pin->get_state();
}

nts::Pin::~Pin()
{
    _fwd_linked_pin.clear();
}

nts::Tristate nts::Pin::get_state() const {
    return _state;
}

void nts::Pin::set_state(nts::Tristate state) {
    _state = state;
}

void nts::Pin::set_loaded_state(nts::Tristate state) {
    loaded_state = state;
}

nts::Tristate nts::Pin::get_loaded_state() {
    return loaded_state;
}

std::string nts::Pin::get_name() const {
    return _name;
}

void nts::Pin::set_name(std::string name) {
    _name = name;
}

std::string nts::Pin::get_type() const {
    return _type;
}

void nts::Pin::set_type(std::string type) {
    _type = type;
}

std::string nts::Pin::get_link_type() const {
    return _link_type;
}

void nts::Pin::set_link_type(std::string new_link_type) {
    _link_type = new_link_type;
}

std::vector<nts::Pin *> nts::Pin::get_fwd_linked_pin() const {
    return _fwd_linked_pin;
}

void nts::Pin::set_fwd_linked_pin(std::vector<Pin*> new_fwd_linked_pin) {
    _fwd_linked_pin = new_fwd_linked_pin;
}

void nts::Pin::push_fwd_linked_pin(Pin *new_fwd_linked_pin) {
    _fwd_linked_pin.push_back(new_fwd_linked_pin);
}

nts::Tristate nts::Pin::gate_operation(std::vector<Pin *> nodes, int output) {
    auto f = logical_operators[_link_type];
    return (this->*f)(nodes, output);
}

void nts::Pin::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pin = 0;
    otherPin = 0;
    (void)other;
}

void nts::Pin::setLink(std::size_t pin, nts::Pin *pin_other, std::size_t otherPin)
{
    pin = 0;
    otherPin = 0;
    this->push_fwd_linked_pin(pin_other);
}

void nts::Chipset::dump () const
{
    for (size_t i = 0; i < this->_outputs.size(); i++) {
        go_thg_node(this->_outputs[i]);
        std::cout << std::endl;
        std::cout << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const nts::Pin& pin) {
    std::string pins_linked_name = "";
    std::vector<nts::Pin *> linked_pins = pin.get_fwd_linked_pin();

    if (linked_pins.size() == 0)
        return out << pin.get_name() << ": type: " << pin.get_type() << "\nvalue :" << pin.get_state() <<
        "\vNo pins linked :(" << std::endl;
    for (size_t i=0;linked_pins.size() != i; i++)
        pins_linked_name.append(linked_pins[i]->get_name()).append(", ");
    return out << pin.get_name() << ": type: " << pin.get_type() << "\nvalue :" << pin.get_state() <<
     "\vPins linked : " << pins_linked_name << std::endl;
}

void  nts::Pin::simulate(std::size_t tick)
{
    ;
}

nts::Tristate nts::Pin::compute(std::size_t pin)
{
    ;
}

void  nts::Pin::dump () const
{
    std::cout << this->get_name() << std::endl;
}
