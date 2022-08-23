/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-tekspice-martin.rougeron
** File description:
** IComponent
*/

#ifndef ICOMPONENT
#define ICOMPONENT


#include <cstddef>
#include <string>
#include <memory>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <exception>
#include <csignal>
#include <regex>

namespace nts
{
    #define REGEX_CONFIG "(#.*\n)*(\\s*\\.chipsets:\\s*\n)(\\s*\\b(?:input|output|true|false|clock|2716|4001|4004|4008|4011|4013|4017|4030|4040|4069|4071|4081|4094|4512|4514|4801|)\\b\\s+\\w+\\s*\n)+(\\s*\\.links:\\s*\n)(\\s*\\w+\\s*:\\s*\\d+\\s*\\w+\\s*:\\s*\\d+\\s*\n?)+"
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true ,
        FALSE = false
    };
    class Pin;
    class IComponent {
        public :
            virtual ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump () const = 0;

        protected:
            std::vector<nts::Pin *> _fwd_linked_pin;
    };
    class Pin : public IComponent {
        public:
            Pin(std::string name="");
            ~Pin();
            Pin(nts::Pin *new_pin);
            Tristate get_state() const;
            void set_state(Tristate state);


            std::string get_name() const;
            void set_name(std::string name);

            std::string get_type() const;
            void set_type(std::string type);

            std::string get_link_type() const;
            void set_link_type(std::string new_link_type);

            void set_loaded_state(nts::Tristate state);
            nts::Tristate get_loaded_state();



            std::vector<Pin*> get_fwd_linked_pin() const;
            void set_fwd_linked_pin(std::vector<Pin*> new_fwd_linked_pin);
            void push_fwd_linked_pin(Pin *new_fwd_linked_pin);
            void pop_fwd_linked_pin();
            void clear_fwd_linked_pin();
            void insert_fwd_linked_pin(Pin *new_pin, int n_pin_pos, int pin_pos);

            Tristate gate_operation(std::vector<Pin *> nodes, int);

                Tristate AND_gate(std::vector<Pin *> A, int output);
                Tristate OR_gate(std::vector<Pin *> A, int output);
                Tristate NOT_gate(std::vector<Pin *> A, int output);
                Tristate NAND_gate(std::vector<Pin *> A, int output);
                Tristate NOR_gate(std::vector<Pin *> A, int output);
                Tristate EOR_gate(std::vector<Pin *> A, int output);
                Tristate ENOR_gate(std::vector<Pin *> A, int output);
                Tristate EQ_gate(std::vector<Pin *> A, int output);
                Tristate DEC_gate(std::vector<Pin *> A, int output);
                Tristate SEL_gate(std::vector<Pin *> A, int output);
                Tristate FLIP_gate(std::vector<Pin *> A, int output);
                Tristate DECADE_gate(std::vector<Pin *> A, int output);
                Tristate ADD_gate(std::vector<Pin *> A, int output);

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            void setLink(std::size_t pin, nts::Pin *pin_other, std::size_t otherPin);
            void dump () const;
            nts::Pin *operator=(const nts::IComponent *other);

        protected:
            nts::Tristate _state = UNDEFINED;
            nts::Tristate loaded_state = UNDEFINED;
            std::string _name;
            size_t _pos;
            std::string _type = "pin";

            std::map<std::string, nts::Tristate (Pin::*)(std::vector<Pin *>, int output)> logical_operators =
            {
                {"and", &Pin::AND_gate}, {"or", &Pin::OR_gate},
                {"not", &Pin::NOT_gate}, {"nand", &Pin::NAND_gate},
                {"nor", &Pin::NOR_gate}, {"eor", &Pin::EOR_gate},
                {"enor", &Pin::ENOR_gate}, {"equal", &Pin::EQ_gate},
                {"dec", &Pin::DEC_gate}, {"sel", &Pin::SEL_gate},
                {"flip", &Pin::FLIP_gate}, {"decade", &Pin::DECADE_gate},
                {"add", &Pin::ADD_gate},

            };
            std::string _link_type = "equal";
    };
    class Gate : public Pin {
        public:
            Gate(std::string name_);
    };
    class Input: public Pin {
        public:
            Input(std::string name);
    }; // a component with a single pin directly linked to the command line. Its value is initialized to undefined.
    class Output: public Pin {
        public:
            Output(std::string name);
    }; // a component with a single pin used as the output of a circuit.
    class Clock: public Pin {
        public:
            Clock(std::string name);
    }; // a component that works like an input, except its value is inverted after each simulation.
    class True: public Pin {
        public:
            True(std::string name);
    }; //: a component with a single pin that is always true.
    class False: public Pin {
        public:
            False(std::string name);
    }; //: a component with a single pin that is always false
    class Chipset {
        public:
            Chipset(std::string __type__, std::string __name__);
            Chipset();
            ~Chipset();
            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void dump () const;

            void create_4001();
            void create_4011();
            void create_4030();
            void create_4071();
            void create_4081();
            void create_4069();
            void create_4008();
            void create_4013();
            void create_4017();
            void create_4040();
            void create_4094();
            void create_4512();
            void create_4514();
            void create_4801();
            void create_2716();

            void display(std::vector<Input *> __inputs__, std::vector<Clock *> __clocks__);
            void stimulate();
            void loop(std::vector<Input *> __inputs__, std::vector<Clock *> __clocks__);
            void modify_input(std::string &, std::vector <Input *> &, std::vector <Clock *> &);

            void read_input(std::vector <Input *> &, std::vector<Clock *> &);
            void link_pins(std::string &, std::vector<nts::Input *> &, std::vector<nts::Output *> &,
            std::vector<nts::Clock *> &, std::vector<nts::True *> &, std::vector<nts::False *> &);

            std::vector<nts::Pin *> get_pins() {return this->_pins;}


            std::string _name;
            std::vector<Output *> _outputs;
            std::vector<Pin *> _pins;
            int tick;
        protected:
            std::map<std::string, void (Chipset::*)()> build_chipset =
            {
                {"2716", &Chipset::create_2716},
                {"4001", &Chipset::create_4001},
                {"4008", &Chipset::create_4008},
                {"4011", &Chipset::create_4011},
                {"4512", &Chipset::create_4512},
                {"4013", &Chipset::create_4013},
                {"4514", &Chipset::create_4514},
                {"4017", &Chipset::create_4017},
                {"4030", &Chipset::create_4030},
                {"4040", &Chipset::create_4040},
                {"4069", &Chipset::create_4069},
                {"4071", &Chipset::create_4071},
                {"4801", &Chipset::create_4801},
                {"4081", &Chipset::create_4081},
                {"4094", &Chipset::create_4094},
            };
    };
    class NanoException : public std::exception {
        public:
            NanoException(std::string msg_);
            ~NanoException();
            std::string msg;
            virtual const char* what() const noexcept override
            {
                return msg.c_str();
            }
    };
    class ConfigException : public NanoException {
        public:
            ConfigException(): NanoException("Error in configuration file") {}
    };
    class UnknownComponentException : public NanoException {
        public:
            UnknownComponentException(std::string msg_): NanoException(msg_) {
                msg = msg_ + std::string(": Unkown component");
            }
    };
    class UnknownComponentNameException : public NanoException {
        public:
            UnknownComponentNameException(std::string msg_): NanoException(msg_) {
                msg = msg_ + std::string(": Unknown component name");
            }
    };
    class UnknownPinException : public NanoException {
        public:
            UnknownPinException(std::string msg_): NanoException(msg_) {
                msg = msg_ + std::string(": Unknown pin");
            }
    };
    class SamePinException : public NanoException {
        public:
            SamePinException(std::string msg_): NanoException(msg_) {
                msg = msg_ + std::string(": components share this name");
            }
    };
    class NoChipsetException : public NanoException {
        public:
            NoChipsetException(std::string msg_): NanoException(msg_) {
                msg = msg_ + std::string("No chipsets in the circuit");
            }
    };
};

std::ostream& operator<<(std::ostream& out, const nts::Pin& pin);
std::vector<nts::Input *> populate_input(std::vector<std::string> __A_inputs__);
std::vector<nts::Output *> populate_output(std::vector<std::string> __A_outputs__);
std::vector<nts::Clock *> populate_clock(std::vector<std::string> __A_clocks__);
std::vector<nts::True *> populate_true(std::vector<std::string> __A_trues__);
std::vector<nts::False *> populate_false(std::vector<std::string> __A_falses__);
std::map<std::string, std::vector<std::string>> read_config(std::string __file_name__);
nts::Tristate stimulate_node(nts::Pin *__parent_node__, int);
std::vector<nts::Pin *> check_stimulate(std::vector<nts::Input *> __A_inputs__, std::vector<nts::Clock *> __A_clocks__);
void dump_node(nts::Pin *parent_node, int);
bool component_share_names(std::map<std::string, std::vector<std::string>> __configuration__);
void go_thg_node(nts::Pin *parent_node);
#endif
