/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-tekspice-martin.rougeron
** File description:
** commands
*/

#include "IComponent.hpp"

extern bool _loop;

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void nts::Chipset:: modify_input(std::string &user_input,
std::vector<Input *> &inputs, std::vector<Clock *> &clocks)
{
    std::string input = user_input.substr(0, user_input.find("="));
    std::string value = user_input.substr(user_input.find("=")+1, user_input.find("="));
    bool is_in = false;
    std::string all_in = "";

    if (value != "U" && !is_number(value)) {
        std::cout << value << " is not a possible value. Possible values are: 0 & 1" << std::endl;
        return;
    } else if (value == "U") {
        for (size_t i = 0; inputs.size() != i; i++) {
            all_in.append(inputs[i]->get_name()).append(" ");
            if (inputs[i]->get_name() == input) {
                is_in = true;
                inputs[i]->set_loaded_state(UNDEFINED);
            }
        }
        for (size_t i = 0; clocks.size() != i; i++) {
            all_in.append(clocks[i]->get_name()).append(" ");
            if (clocks[i]->get_name() == input) {
                is_in = true;
                clocks[i]->set_loaded_state(UNDEFINED);
            }
        }
        if (!is_in)
            std::cout << input << ": not in inputs. Possible inputs are: " << all_in << std::endl;
        return;
    }

    if (!(std::stoi(value) == 0 || std::stoi(value) == 1)) {
        std::cout << value << " is not a possible value. Possible values are: 0 & 1" << std::endl;
        return;
    }

    for (size_t i = 0; inputs.size() != i; i++) {
        all_in.append(inputs[i]->get_name()).append(" ");
        if (inputs[i]->get_name() == input) {
            is_in = true;
            inputs[i]->set_loaded_state(nts::Tristate(std::stoi(value)));
        }
    }
    for (size_t i = 0; clocks.size() != i; i++) {
        all_in.append(clocks[i]->get_name()).append(" ");
        if (clocks[i]->get_name() == input) {
            is_in = true;
            clocks[i]->set_loaded_state(nts::Tristate(std::stoi(value)));
        }
    }
    if (!is_in)
        std::cout << input << ": not in inputs. Possible inputs are: " << all_in << std::endl;
}

bool compareInterval(nts::Pin *i1, nts::Pin *i2)
{
    return (i1->get_name() < i2->get_name());
}

void nts::Chipset ::display(std::vector<Input *> inputs, std::vector<Clock *> clocks)
{
    std::string state = "";
    std::vector<Pin *> inputs_copy = {};

    inputs_copy.insert(inputs_copy.end(), inputs.begin(), inputs.end());
    inputs_copy.insert(inputs_copy.end(), clocks.begin(), clocks.end());

    std::sort(inputs_copy.begin(), inputs_copy.end(), compareInterval);

    std::cout << "tick: " << this->tick << std::endl;
    std::cout << "input(s):" << std::endl;

    for (size_t i = 0; i < inputs_copy.size(); i++) {
        state = (inputs_copy[i] ->get_state() == -1) ? "U" :
        std::to_string(inputs_copy[i] ->get_state());
        std::cout << "  " << inputs_copy[i]->get_name() << ": "
        << state << std::endl;
    }


    std::cout << "output(s):" << std::endl;

    for (size_t i = 0; i < _outputs.size(); i++) {
        state = (_outputs[i] ->get_state() == -1) ? "U" :
        std::to_string(_outputs[i] ->get_state());
        std::cout << "  " << _outputs[i]->get_name() << ": "
        << state << std::endl;
    }
    inputs_copy.clear();
}

nts::Tristate stimulate_node(nts::Pin *parent_node, int output)
{
    if (parent_node == NULL)
        return nts::UNDEFINED;
    if (parent_node->get_type() == "input" || parent_node->get_type() == "clock") {
        parent_node->set_state(parent_node->get_loaded_state());
    }
    std::vector<nts::Pin *> child_nodes = parent_node->get_fwd_linked_pin();
    if (child_nodes.size() == 0) {
        if (parent_node->get_type() == "clock") {
            parent_node->set_state(nts::Tristate(not parent_node->get_state()));
            return nts::Tristate(not parent_node->get_state());
        }
        return parent_node->get_state();
    }
    for (size_t i = 0; i < child_nodes.size(); i++) {
        if (child_nodes[i]->get_type() == "clock") {
            child_nodes[i]->set_state(nts::Tristate(not child_nodes[i]->get_state()));
        } else {
            child_nodes[i]->set_state(stimulate_node(child_nodes[i], output));
        }
    }
    if (parent_node->get_link_type() == "equal")
        return child_nodes[0]->get_state();
    else
        return parent_node->gate_operation(parent_node->get_fwd_linked_pin(), output);
}

void go_thg_node(nts::Pin *parent_node)
{
    if (parent_node == NULL)
        return;
    std::vector<nts::Pin *> child_nodes = parent_node->get_fwd_linked_pin();
    for (size_t i = 0; i < child_nodes.size(); i++) {
        go_thg_node(child_nodes[i]);
    }
    parent_node->dump();
}

void nts::Chipset:: loop(std::vector<nts::Input *> inputs, std::vector<nts::Clock *> clocks)
{
    while (_loop) {
        this->simulate(this->tick);
        this->display(inputs, clocks);
    }
}
