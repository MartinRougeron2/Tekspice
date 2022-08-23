/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-tekspice-martin.rougeron
** File description:
** main
*/

#include "IComponent.hpp"

bool _loop;

void signalHandler( int signum ) {
    _loop = false;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;

    std::map<std::string, std::vector<std::string>> configuration = read_config(argv[1]);

    std::vector<nts::Input *> inputs = populate_input(configuration["input"]);
    std::vector<nts::Output *> outputs = populate_output(configuration["output"]);
    std::vector<nts::Clock *> clocks = populate_clock(configuration["clock"]);
    std::vector<nts::True *> trues = populate_true(configuration["true"]);
    std::vector<nts::False *> falses = populate_false(configuration["false"]);
    std::vector<std::string> links = configuration["links"];
    nts::Chipset *chipset;

   signal(SIGINT, signalHandler);

    if (configuration["name"].size() > 1)
        chipset = new nts::Chipset(configuration["name"].at(1), configuration["name"].at(0));
    else
        chipset = new nts::Chipset();
    if (chipset->_name == "ERROR")
        return 84;
    if (component_share_names(configuration))
        return 84;
    for (size_t y = 0; links.size() > y; y++) {
        try {
            chipset->link_pins(links[y], inputs, outputs, clocks, trues, falses);
        } catch (std::exception &ex) {
            std::cout << ex.what() << std::endl;
            return 84;
        }
    }
    chipset->_outputs = outputs;
    if (chipset->_name == "")
        chipset->simulate(-1);
    chipset->read_input(inputs, clocks);
    inputs.clear();
    outputs.clear();
    clocks.clear();
    trues.clear();
    falses.clear();
    links.clear();
    return 0;
}
