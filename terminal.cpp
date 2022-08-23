/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-tekspice-martin.rougeron
** File description:
** terminal
*/

#include "IComponent.hpp"

extern bool _loop;

void nts::Chipset::read_input(std::vector<Input *> &inputs, std::vector<Clock *> &clocks)
{
    std::string user_input;
    std::vector <nts::Pin *> bad_inputs = {};
    std::cout << "> ";
    while (getline (std::cin, user_input)) {
        user_input.erase(std::remove(user_input.begin(), user_input.end(), ' '), user_input.end());
        user_input.erase(std::remove(user_input.begin(), user_input.end(), '\t'), user_input.end());
        if (user_input == "exit")
            break;
        else if (user_input == "display")
            this->display(inputs, clocks);
        else if (user_input == "simulate")
            this->simulate(this->tick);
        else if (user_input == "loop") {
            _loop = true;
            this->loop(inputs, clocks);
        }
        else if (user_input == "dump")
            this->dump();
        else if (user_input.find("=") != std::string::npos)
            this->modify_input(user_input, inputs, clocks);
        else if (user_input == "inputs?") {
            for (size_t i = 0; i < inputs.size(); i++)
                std::cout << inputs[i]->get_name() << "("
                << inputs[i] ->get_state() << "), ";
            std::cout << std::endl;
            for (size_t i = 0; i < clocks.size(); i++)
                std::cout << clocks[i]->get_name() << "("
                << clocks[i] ->get_state() << "), ";
            std::cout << std::endl;
        }
        else if (user_input == "outputs?") {
            for (size_t i = 0; i < this->_outputs.size(); i++)
                std::cout << this->_outputs[i]->get_name() << "("
                << this->_outputs[i] ->get_state() << "), ";
            std::cout << std::endl;
        }
        else if (user_input == "setall") {
            for (size_t i = 0; i < inputs.size(); i++)
                inputs[i]->set_state(nts::Tristate(std::rand() % 2 * (-1) * rand() % 2));
            for (size_t i = 0; i < clocks.size(); i++)
                clocks[i]->set_state(nts::Tristate(std::rand() % 2 * (-1) * rand() % 2));
        }
        else if (user_input == "") {}
        else
            std::cout << user_input << ": Unknown command\n";
        std::cout << "> ";
    }

}
