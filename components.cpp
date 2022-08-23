/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-tekspice-martin.rougeron
** File description:
** components
*/

#include "IComponent.hpp"

nts::Gate::Gate(std::string name_): nts::Pin::Pin(name_)
{
    _name = name_;
    _type = "Gate";
}

nts::Input::Input(std::string name): nts::Pin::Pin(name)
{
    _name = name;
    _type = "input";
}

nts::Output::Output(std::string name): nts::Pin::Pin(name)
{
    _name = name;
    _type = "output";

}

nts::Clock::Clock(std::string name): nts::Pin::Pin(name)
{
    _name = name;
    _type = "clock";
}

nts::True::True(std::string name): nts::Pin::Pin(name)
{
    _name = name;
    _type = "true";
    _state = TRUE;
}

nts::False::False(std::string name): nts::Pin::Pin(name)
{
    _name = name;
    _type = "false";
    _state = FALSE;
}

std::vector<nts::Input *> populate_input(std::vector<std::string> inputs)
{
    std::vector<nts::Input *> Inputs;
    for (size_t i = 0; inputs.size() != i; i++)
        Inputs.push_back(new nts::Input(inputs[i]));
    return Inputs;
}

std::vector<nts::Output *> populate_output(std::vector<std::string> outputs)
{
    std::vector<nts::Output *> Outputs;
    for (size_t i = 0; outputs.size() != i; i++)
        Outputs.push_back(new nts::Output(outputs[i]));
    return Outputs;
}

std::vector<nts::Clock *> populate_clock(std::vector<std::string> clocks)
{
    std::vector<nts::Clock *> Clocks;
    for (size_t i = 0; clocks.size() != i; i++)
        Clocks.push_back(new nts::Clock(clocks[i]));
    return Clocks;
}

std::vector<nts::True *> populate_true(std::vector<std::string> trues)
{
    std::vector<nts::True *> Trues;
    for (size_t i = 0; trues.size() != i; i++)
        Trues.push_back(new nts::True(trues[i]));
    return Trues;
}

std::vector<nts::False *> populate_false(std::vector<std::string> falses)
{
    std::vector<nts::False *> Falses;
    for (size_t i = 0; falses.size() != i; i++)
        Falses.push_back(new nts::False(falses[i]));
    return Falses;
}

nts::Chipset::Chipset(std::string type_, std::string name_)
{
    std::vector<std::string> existing_types =
    {
        "4001", //: Four NOR gates.
        "4011", //: Four NAND gates.
        "4030", //: Four XOR gates.
        "4071", //: Four OR gates.
        "4081", //: Four AND gates.
        "4069", //: Six INVERTER gates.
        "4008", //: 4 bits adder.
        "4013", //: Dual Flip Flop.
        "4017", //: 10 bits Johnson decade.
        "4040", //: 12 bits counter.
        "4094", //: 8 bits shift register.
        "4512", //: 8 channel data selector.
        "4514", //: 4 bits decoder.
        "4801", //: Random access memory.
        "2716" //: Read only memory (memory init
    };
    auto index_of_type = std::find(existing_types.begin(), existing_types.end(), type_);
    this->_name = name_;
    this->tick = 0;
    if (index_of_type != existing_types.end()) // In
    {
        auto f = build_chipset[type_];
        (this->*f)();
    }
    else{
        throw nts::UnknownComponentException(type_);
    }
}

nts::Chipset::Chipset()
{
    this->_name = "";
    this->tick = 0;
}

nts::Chipset::~Chipset()
{

}

void nts::Chipset::simulate(std::size_t tick)
{
    this->tick = tick + 1;
    for (size_t i = 0; i < this->_outputs.size(); i++)
        this->_outputs[i]->set_state(stimulate_node(this->_outputs[i], i));
}

nts::Tristate nts::Chipset::compute(std::size_t pin)
{ //TODO

}
