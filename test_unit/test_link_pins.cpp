/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-tekspice-martin.rougeron
** File description:
** test_link_pins
*/

#include <gtest/gtest.h>
#include "../IComponent.hpp"

TEST(linked_pins, good_pins)
{
    nts::Chipset chip = nts::Chipset("4071", "chip");
    std::vector<nts::Input *> inputs = {new nts::Input("in")};
    std::vector<nts::Output *> outputs = {new nts::Output("out")};
    std::vector<nts::Clock *> clocks = {new nts::Clock("cl")};
    std::vector<nts::True *> trues = {new nts::True("tr")};
    std::vector<nts::False *> falses = {new nts::False("fl")};
    std::vector<std::string> config_good = {
        "in:1 out:1",
        "out:1 in:1",
        " in:1 out:1",
        "in:1 out:1",
    };
    for (size_t i = 0; i < config_good.size(); i++) {
        std::cout << "# " << config_good[i] << " # => true" << std::endl;
    }
    std::cout << std::endl;
}
