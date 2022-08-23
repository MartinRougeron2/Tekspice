/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-tekspice-martin.rougeron
** File description:
** read_config
*/

#include "IComponent.hpp"

std::vector<std::string> split2(const std::string &str, char delim = ' ')
{
    std::vector<std::string> cont;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
    return cont;
}

std::map<std::string, std::vector<std::string>> read_config(std::string file_name)
{
    std::vector<std::string> input;
    std::vector<std::string> output;
    std::vector<std::string> clock;
    std::vector<std::string> true_;
    std::vector<std::string> false_;
    std::vector<std::string> line_read;
    std::vector<std::string> name;
    std::vector<std::string> links;
    std::string line;
    std::vector<std::string> filestring;
    size_t i;
    std::ifstream cFile (file_name);
    std::map<std::string, std::vector<std::string>> configuration;

    if (!cFile || file_name.find(".nts") == std::string::npos) {
        std::exit(84);
    }
    if (cFile.is_open()) {
        try {
            std::string fullfile((std::istreambuf_iterator<char>(cFile)),
            std::istreambuf_iterator<char>());
            std::regex expression { REGEX_CONFIG };
            if (!std::regex_match(fullfile, expression))
                throw "Bad config";
            std::regex search_chipset ("(^\\s*)([\\w]+)\\s*([\\w]+)(\\s*)$");
            std::regex search_links ("^(\\s*)(\\w+)(\\s*):(\\s*)(\\d+)\\s*(\\w+)(\\s*):(\\s*)(\\d+)(\\s*\n?)*$");
            filestring = split2(fullfile, '\n');


            for (i = 0; i < filestring.size(); i++) { // read Chipsets
                if(filestring[i][0] == '#' || filestring[i] == ".chipsets:" || filestring[i].empty())
                    continue;
                if (filestring[i] == ".links:")
                    break;
                filestring[i] = std::regex_replace(filestring[i], search_chipset , "$2 $3");
                line_read = split2(filestring[i]);
                if (line_read[0] == "input")
                    input.push_back(line_read[1]);
                else if (line_read[0] == "output")
                    output.push_back(line_read[1]);
                else if (line_read[0] == "clock")
                    clock.push_back(line_read[1]);
                else if (line_read[0] == "true")
                    true_.push_back(line_read[1]);
                else if (line_read[0] == "false")
                    false_.push_back(line_read[1]);
                else {
                    name.push_back(line_read[1]);
                    name.push_back(line_read[0]);
                }
            }
            for (;i < filestring.size(); i++) { // read links
                if (filestring[i][0] == '#' || filestring[i] == ".links:" || filestring[i].empty())
                    continue;
                filestring[i] = std::regex_replace(filestring[i], search_links, "$2:$5 $6:$9");
                links.push_back(filestring[i]);
            }
        } catch (const char *error_message) {
            std::cerr << error_message << std::endl;
            exit(84);
        }
    }
    else {
        std::cerr << "Couldn't open config file for reading.\n";
    }
    configuration = {{"input", input}, {"output", output},
    {"clock", clock}, {"true", true_}, {"false", false_},
    {"name", name}, {"links", links}};
    return configuration;
}

bool is_number_(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void nts::Chipset::link_pins(std::string &src,
std::vector<nts::Input *> &inputs, std::vector<nts::Output *> &outputs,
std::vector<nts::Clock *> &clocks, std::vector<nts::True *> &trues, std::vector<nts::False *> &falses)
{
    if (src == "")
        throw nts::UnknownPinException("");

    src = src.substr(0, src.find("#"));
    src.erase(src.begin(), std::find_if(src.begin(), src.end(), std::bind1st(std::not_equal_to<char>(), ' ')));

    std::string dest = src.substr(src.find(" ") + 1);
    src = src.substr(0, src.find(" "));
    src.erase(std::remove(src.begin(), src.end(), ' '), src.end());
    dest.erase(std::remove(dest.begin(), dest.end(), ' '), dest.end());

    std::vector<nts::Pin *> pins = this->_pins;
    nts::Pin *src_pin = NULL;
    nts::Pin *dest_pin = NULL;
    std::string src_name = src.substr(0, src.find(":"));
    std::string src_value = src.substr(src.find(":")+1, src.find(":"));
    std::string dest_name = dest.substr(0, dest.find(":"));
    std::string dest_value = dest.substr(dest.find(":")+1, dest.find(":"));


    pins.insert(pins.end(), inputs.begin(),       inputs.end());
    pins.insert(pins.end(), outputs.begin(),      outputs.end());
    pins.insert(pins.end(), clocks.begin(),       clocks.end());
    pins.insert(pins.end(), trues.begin(),        trues.end());
    pins.insert(pins.end(), falses.begin(),       falses.end());

    if (std::stoi(src_value) < 1 || std::stoi(dest_value) < 1) {
        throw nts::UnknownPinException(std::stoi(dest_value) < 1 ? dest_value : src_value);
    }

    if (src_name == this->_name) {
        if (std::stoul(src_value) > this->_pins.size()) {
            throw nts::UnknownPinException(src_value);
        }
        src_pin = this->_pins.at(std::stoi(src_value));
    } else {
        if (std::stoul(src_value) > 1) {
            throw nts::UnknownPinException(src_value);
        }
        for (size_t i = 0; i < pins.size(); i++) {
            if (src_name == pins[i]->get_name()) {
                src_pin = pins[i];
                break;
            }
        }
    }
    if (dest_name == this->_name) {
        if (std::stoul(dest_value) > this->_pins.size()) {
            throw nts::UnknownPinException(dest_value);
        }
        dest_pin = this->_pins.at(std::stoi(dest_value));
    } else {
        if (std::stoul(dest_value) > 1) {
            throw nts::UnknownPinException(dest_value);
        }
        for (size_t i = 0; i < pins.size(); i++) {
            if (dest_name == pins[i]->get_name()) {
                dest_pin = pins[i];
                break;
            }
        }
    }
    pins.clear();
    if (src_pin == NULL) {
        throw nts::UnknownComponentNameException(src_name);
    }
    if (dest_pin == NULL) {
        throw nts::UnknownComponentNameException(dest_name);
    }
    if (src_pin->get_type() == "output")
        src_pin->setLink(0, dest_pin, 0);
    else
        dest_pin->setLink(0, src_pin, 0);
}

bool component_share_names(std::map<std::string, std::vector<std::string>> configuration)
{
    std::vector<std::string> components = {};

    components.insert(components.end(), configuration["input"].begin(), configuration["input"].end());
    components.insert(components.end(), configuration["output"].begin(), configuration["output"].end());
    components.insert(components.end(), configuration["clock"].begin(), configuration["clock"].end());
    components.insert(components.end(), configuration["true"].begin(), configuration["true"].end());
    components.insert(components.end(), configuration["false"].begin(), configuration["false"].end());
    auto it = std::unique(components.begin(), components.end());
    if (!(it == components.end()))
    {
        throw nts::SamePinException(*it);
        return true;
    }
    return false;
}
