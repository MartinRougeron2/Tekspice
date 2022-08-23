/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-tekspice-martin.rougeron
** File description:
** careate_chipset
*/

#include "IComponent.hpp"


//: Four NOR gates.
void nts::Chipset::create_4001()
{  //: Four NOR gates.
    nts::Gate *gate1 = new Gate("Gate1");
    nts::Gate *gate2 = new Gate("Gate2");
    nts::Gate *gate3 = new Gate("Gate3");
    nts::Gate *gate4 = new Gate("Gate4");
    nts::Pin *pin0 = new Pin("0");
    nts::Pin *pin1 = new Pin("1");
    nts::Pin *pin2 = new Pin("2");
    nts::Pin *pin3 = new Pin("3");
    nts::Pin *pin4 = new Pin("4");
    nts::Pin *pin5 = new Pin("5");
    nts::Pin *pin6 = new Pin("6");
    nts::Pin *pin7 = new Pin("7");
    nts::Pin *pin8 = new Pin("8");
    nts::Pin *pin9 = new Pin("9");
    nts::Pin *pin10 = new Pin("10");
    nts::Pin *pin11 = new Pin("11");
    nts::Pin *pin12 = new Pin("12");
    nts::Pin *pin13 = new Pin("13");
    nts::Pin *pin14 = new Pin("14");


    gate1->push_fwd_linked_pin(pin1);
    gate1->push_fwd_linked_pin(pin2);
    pin3->push_fwd_linked_pin(gate1);


    gate2->push_fwd_linked_pin(pin6);
    gate2->push_fwd_linked_pin(pin5);
    pin4->push_fwd_linked_pin(gate2);

    gate3->push_fwd_linked_pin(pin8);
    gate3->push_fwd_linked_pin(pin9);
    pin10->push_fwd_linked_pin(gate3);

    gate4->push_fwd_linked_pin(pin13);
    gate4->push_fwd_linked_pin(pin12);
    pin11->push_fwd_linked_pin(gate4);

    gate1->set_link_type("nor");
    gate2->set_link_type("nor");
    gate3->set_link_type("nor");
    gate4->set_link_type("nor");

    this->_pins = {pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7,
    pin8, pin9, pin10, pin11, pin12, pin13, pin14};
}

//: Four NAND gates.
void nts::Chipset::create_4011()
{  //: Four NAND gates.
    nts::Gate *gate1 = new Gate("Gate1");
    nts::Gate *gate2 = new Gate("Gate2");
    nts::Gate *gate3 = new Gate("Gate3");
    nts::Gate *gate4 = new Gate("Gate4");
    nts::Pin *pin0 = new Pin("0");
    nts::Pin *pin1 = new Pin("1");
    nts::Pin *pin2 = new Pin("2");
    nts::Pin *pin3 = new Pin("3");
    nts::Pin *pin4 = new Pin("4");
    nts::Pin *pin5 = new Pin("5");
    nts::Pin *pin6 = new Pin("6");
    nts::Pin *pin7 = new Pin("7");
    nts::Pin *pin8 = new Pin("8");
    nts::Pin *pin9 = new Pin("9");
    nts::Pin *pin10 = new Pin("10");
    nts::Pin *pin11 = new Pin("11");
    nts::Pin *pin12 = new Pin("12");
    nts::Pin *pin13 = new Pin("13");
    nts::Pin *pin14 = new Pin("14");


    gate1->push_fwd_linked_pin(pin1);
    gate1->push_fwd_linked_pin(pin2);
    pin3->push_fwd_linked_pin(gate1);


    gate2->push_fwd_linked_pin(pin6);
    gate2->push_fwd_linked_pin(pin5);
    pin4->push_fwd_linked_pin(gate2);

    gate3->push_fwd_linked_pin(pin8);
    gate3->push_fwd_linked_pin(pin9);
    pin10->push_fwd_linked_pin(gate3);

    gate4->push_fwd_linked_pin(pin13);
    gate4->push_fwd_linked_pin(pin12);
    pin11->push_fwd_linked_pin(gate4);

    gate1->set_link_type("nand");
    gate2->set_link_type("nand");
    gate3->set_link_type("nand");
    gate4->set_link_type("nand");

    this->_pins = {pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7,
    pin8, pin9, pin10, pin11, pin12, pin13, pin14};
}

//: Four XOR gates.
void nts::Chipset::create_4030()
{  //: Four XOR gates.
    nts::Gate *gate1 = new Gate("Gate1");
    nts::Gate *gate2 = new Gate("Gate2");
    nts::Gate *gate3 = new Gate("Gate3");
    nts::Gate *gate4 = new Gate("Gate4");
    nts::Pin *pin0 = new Pin("0");
    nts::Pin *pin1 = new Pin("1");
    nts::Pin *pin2 = new Pin("2");
    nts::Pin *pin3 = new Pin("3");
    nts::Pin *pin4 = new Pin("4");
    nts::Pin *pin5 = new Pin("5");
    nts::Pin *pin6 = new Pin("6");
    nts::Pin *pin7 = new Pin("7");
    nts::Pin *pin8 = new Pin("8");
    nts::Pin *pin9 = new Pin("9");
    nts::Pin *pin10 = new Pin("10");
    nts::Pin *pin11 = new Pin("11");
    nts::Pin *pin12 = new Pin("12");
    nts::Pin *pin13 = new Pin("13");
    nts::Pin *pin14 = new Pin("14");


    gate1->push_fwd_linked_pin(pin1);
    gate1->push_fwd_linked_pin(pin2);
    pin3->push_fwd_linked_pin(gate1);


    gate2->push_fwd_linked_pin(pin6);
    gate2->push_fwd_linked_pin(pin5);
    pin4->push_fwd_linked_pin(gate2);

    gate3->push_fwd_linked_pin(pin8);
    gate3->push_fwd_linked_pin(pin9);
    pin10->push_fwd_linked_pin(gate3);

    gate4->push_fwd_linked_pin(pin13);
    gate4->push_fwd_linked_pin(pin12);
    pin11->push_fwd_linked_pin(gate4);

    gate1->set_link_type("eor");
    gate2->set_link_type("eor");
    gate3->set_link_type("eor");
    gate4->set_link_type("eor");

    this->_pins = {pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7,
    pin8, pin9, pin10, pin11, pin12, pin13, pin14};
}

//: Four OR gates.
void nts::Chipset::create_4071()
{  //: Four OR gates.
    nts::Gate *gate1 = new Gate("Gate1");
    nts::Gate *gate2 = new Gate("Gate2");
    nts::Gate *gate3 = new Gate("Gate3");
    nts::Gate *gate4 = new Gate("Gate4");
    nts::Pin *pin0 = new Pin("0");
    nts::Pin *pin1 = new Pin("1");
    nts::Pin *pin2 = new Pin("2");
    nts::Pin *pin3 = new Pin("3");
    nts::Pin *pin4 = new Pin("4");
    nts::Pin *pin5 = new Pin("5");
    nts::Pin *pin6 = new Pin("6");
    nts::Pin *pin7 = new Pin("7");
    nts::Pin *pin8 = new Pin("8");
    nts::Pin *pin9 = new Pin("9");
    nts::Pin *pin10 = new Pin("10");
    nts::Pin *pin11 = new Pin("11");
    nts::Pin *pin12 = new Pin("12");
    nts::Pin *pin13 = new Pin("13");
    nts::Pin *pin14 = new Pin("14");


    gate1->push_fwd_linked_pin(pin1);
    gate1->push_fwd_linked_pin(pin2);
    pin3->push_fwd_linked_pin(gate1);


    gate2->push_fwd_linked_pin(pin6);
    gate2->push_fwd_linked_pin(pin5);
    pin4->push_fwd_linked_pin(gate2);

    gate3->push_fwd_linked_pin(pin8);
    gate3->push_fwd_linked_pin(pin9);
    pin10->push_fwd_linked_pin(gate3);

    gate4->push_fwd_linked_pin(pin13);
    gate4->push_fwd_linked_pin(pin12);
    pin11->push_fwd_linked_pin(gate4);

    gate1->set_link_type("or");
    gate2->set_link_type("or");
    gate3->set_link_type("or");
    gate4->set_link_type("or");

    this->_pins = {pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7,
    pin8, pin9, pin10, pin11, pin12, pin13, pin14};
}

//: Four AND gates.
void nts::Chipset::create_4081()
{  //: Four AND gates.
    nts::Gate *gate1 = new Gate("Gate1");
    nts::Gate *gate2 = new Gate("Gate2");
    nts::Gate *gate3 = new Gate("Gate3");
    nts::Gate *gate4 = new Gate("Gate4");
    nts::Pin *pin0 = new Pin("0");
    nts::Pin *pin1 = new Pin("1");
    nts::Pin *pin2 = new Pin("2");
    nts::Pin *pin3 = new Pin("3");
    nts::Pin *pin4 = new Pin("4");
    nts::Pin *pin5 = new Pin("5");
    nts::Pin *pin6 = new Pin("6");
    nts::Pin *pin7 = new Pin("7");
    nts::Pin *pin8 = new Pin("8");
    nts::Pin *pin9 = new Pin("9");
    nts::Pin *pin10 = new Pin("10");
    nts::Pin *pin11 = new Pin("11");
    nts::Pin *pin12 = new Pin("12");
    nts::Pin *pin13 = new Pin("13");
    nts::Pin *pin14 = new Pin("14");


    gate1->push_fwd_linked_pin(pin1);
    gate1->push_fwd_linked_pin(pin2);
    pin3->push_fwd_linked_pin(gate1);


    gate2->push_fwd_linked_pin(pin6);
    gate2->push_fwd_linked_pin(pin5);
    pin4->push_fwd_linked_pin(gate2);

    gate3->push_fwd_linked_pin(pin8);
    gate3->push_fwd_linked_pin(pin9);
    pin10->push_fwd_linked_pin(gate3);

    gate4->push_fwd_linked_pin(pin13);
    gate4->push_fwd_linked_pin(pin12);
    pin11->push_fwd_linked_pin(gate4);

    gate1->set_link_type("and");
    gate2->set_link_type("and");
    gate3->set_link_type("and");
    gate4->set_link_type("and");

    this->_pins = {pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7,
    pin8, pin9, pin10, pin11, pin12, pin13, pin14};
}

//: Six INVERTER gates.
void nts::Chipset::create_4069()
{  //: Six INVERTER gates.
    nts::Gate *gate1 = new Gate("Gate1");
    nts::Gate *gate2 = new Gate("Gate2");
    nts::Gate *gate3 = new Gate("Gate3");
    nts::Gate *gate4 = new Gate("Gate4");
    nts::Gate *gate5 = new Gate("Gate5");
    nts::Gate *gate6 = new Gate("Gate6");
    nts::Pin *pin0 = new Pin("0");
    nts::Pin *pin1 = new Pin("1");
    nts::Pin *pin2 = new Pin("2");
    nts::Pin *pin3 = new Pin("3");
    nts::Pin *pin4 = new Pin("4");
    nts::Pin *pin5 = new Pin("5");
    nts::Pin *pin6 = new Pin("6");
    nts::Pin *pin7 = new Pin("7");
    nts::Pin *pin8 = new Pin("8");
    nts::Pin *pin9 = new Pin("9");
    nts::Pin *pin10 = new Pin("10");
    nts::Pin *pin11 = new Pin("11");
    nts::Pin *pin12 = new Pin("12");
    nts::Pin *pin13 = new Pin("13");
    nts::Pin *pin14 = new Pin("14");



    gate1->push_fwd_linked_pin(pin1);
    pin2->push_fwd_linked_pin(gate1);


    gate2->push_fwd_linked_pin(pin3);
    pin4->push_fwd_linked_pin(gate2);

    gate3->push_fwd_linked_pin(pin5);
    pin6->push_fwd_linked_pin(gate3);

    gate4->push_fwd_linked_pin(pin8);
    pin9->push_fwd_linked_pin(gate4);

    gate5->push_fwd_linked_pin(pin10);
    pin11->push_fwd_linked_pin(gate5);

    gate6->push_fwd_linked_pin(pin12);
    pin13->push_fwd_linked_pin(gate6);


    gate1->set_link_type("not");
    gate2->set_link_type("not");
    gate3->set_link_type("not");
    gate4->set_link_type("not");
    gate5->set_link_type("not");
    gate6->set_link_type("not");

    this->_pins = {pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7,
    pin8, pin9, pin10, pin11, pin12, pin13, pin14};
}

//: 4 bits adder.
void nts::Chipset::create_4008()
{  //: 4 bits adder.
    nts::Gate *gate1 = new Gate("Gate1");
    nts::Gate *gate2 = new Gate("Gate2");
    nts::Gate *gate3 = new Gate("Gate3");
    nts::Gate *gate4 = new Gate("Gate4");
    nts::Pin *pin0 = new Pin("0");
    nts::Pin *pin1 = new Pin("1");
    nts::Pin *pin2 = new Pin("2");
    nts::Pin *pin3 = new Pin("3");
    nts::Pin *pin4 = new Pin("4");
    nts::Pin *pin5 = new Pin("5");
    nts::Pin *pin6 = new Pin("6");
    nts::Pin *pin7 = new Pin("7");
    nts::Pin *pin8 = new Pin("8");
    nts::Pin *pin9 = new Pin("9");
    nts::Pin *pin10 = new Pin("10");
    nts::Pin *pin11 = new Pin("11");
    nts::Pin *pin12 = new Pin("12");
    nts::Pin *pin13 = new Pin("13");
    nts::Pin *pin14 = new Pin("14");
    nts::Pin *pin15 = new Pin("15");

    pin1->push_fwd_linked_pin(gate1);
    pin15->push_fwd_linked_pin(gate1);
    gate1->push_fwd_linked_pin(pin13);
    gate1->push_fwd_linked_pin(pin14);

    pin2->push_fwd_linked_pin(gate2);
    pin3->push_fwd_linked_pin(gate2);
    gate2->push_fwd_linked_pin(gate1);
    gate2->push_fwd_linked_pin(pin12);

    pin4->push_fwd_linked_pin(gate3);
    pin5->push_fwd_linked_pin(gate3);
    gate3->push_fwd_linked_pin(gate2);
    gate3->push_fwd_linked_pin(pin11);

    pin6->push_fwd_linked_pin(gate4);
    pin7->push_fwd_linked_pin(gate4);
    pin9->push_fwd_linked_pin(gate4);
    gate4->push_fwd_linked_pin(gate3);
    gate4->push_fwd_linked_pin(pin10);

    gate1->set_link_type("add");
    gate2->set_link_type("add");
    gate3->set_link_type("add");
    gate4->set_link_type("add");

    this->_pins = {pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7,
    pin8, pin9, pin10, pin11, pin12, pin13, pin14};
}

//: Dual Flip Flop.
void nts::Chipset::create_4013()
{  //: Dual Flip Flop.
    nts::Gate *gate1 = new Gate("Gate1");
    nts::Gate *gate2 = new Gate("Gate2");
    nts::Pin *pin0 = new Pin("0");
    nts::Pin *pin1 = new Pin("1");
    nts::Pin *pin2 = new Pin("2");
    nts::Pin *pin3 = new Pin("3");
    nts::Pin *pin4 = new Pin("4");
    nts::Pin *pin5 = new Pin("5");
    nts::Pin *pin6 = new Pin("6");
    nts::Pin *pin7 = new Pin("7");
    nts::Pin *pin8 = new Pin("8");
    nts::Pin *pin9 = new Pin("9");
    nts::Pin *pin10 = new Pin("10");
    nts::Pin *pin11 = new Pin("11");
    nts::Pin *pin12 = new Pin("12");
    nts::Pin *pin13 = new Pin("13");
    nts::Pin *pin14 = new Pin("14");

    gate1->push_fwd_linked_pin(pin1);
    gate1->push_fwd_linked_pin(pin2);
    pin3->push_fwd_linked_pin(gate1);
    pin4->push_fwd_linked_pin(gate1);
    pin5->push_fwd_linked_pin(gate1);
    pin6->push_fwd_linked_pin(gate1);

    pin8->push_fwd_linked_pin(gate2);
    pin9->push_fwd_linked_pin(gate2);
    pin10->push_fwd_linked_pin(gate2);
    pin11->push_fwd_linked_pin(gate2);
    gate2->push_fwd_linked_pin(pin12);
    gate2->push_fwd_linked_pin(pin13);

    gate1->set_link_type("flip");
    gate2->set_link_type("flip");

    this->_pins = {pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7,
    pin8, pin9, pin10, pin11, pin12, pin13, pin14};
}

//: 10 bits Johnson decade.
void nts::Chipset::create_4017()
{  //: 10 bits Johnson decade.
    nts::Gate *gate1 = new Gate("Gate1");
    nts::Pin *pin0 = new Pin("0");
    nts::Pin *pin1 = new Pin("1");
    nts::Pin *pin2 = new Pin("2");
    nts::Pin *pin3 = new Pin("3");
    nts::Pin *pin4 = new Pin("4");
    nts::Pin *pin5 = new Pin("5");
    nts::Pin *pin6 = new Pin("6");
    nts::Pin *pin7 = new Pin("7");
    nts::Pin *pin8 = new Pin("8");
    nts::Pin *pin9 = new Pin("9");
    nts::Pin *pin10 = new Pin("10");
    nts::Pin *pin11 = new Pin("11");
    nts::Pin *pin12 = new Pin("12");
    nts::Pin *pin13 = new Pin("13");
    nts::Pin *pin14 = new Pin("14");
    nts::Pin *pin15 = new Pin("15");

    pin13->push_fwd_linked_pin(gate1);
    pin14->push_fwd_linked_pin(gate1);
    pin15->push_fwd_linked_pin(gate1);

    gate1->push_fwd_linked_pin(pin1);
    gate1->push_fwd_linked_pin(pin2);
    gate1->push_fwd_linked_pin(pin3);
    gate1->push_fwd_linked_pin(pin4);
    gate1->push_fwd_linked_pin(pin5);
    gate1->push_fwd_linked_pin(pin6);
    gate1->push_fwd_linked_pin(pin7);
    gate1->push_fwd_linked_pin(pin9);
    gate1->push_fwd_linked_pin(pin10);
    gate1->push_fwd_linked_pin(pin11);
    gate1->push_fwd_linked_pin(pin12);

    gate1->set_link_type("decade");

    this->_pins = {pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7,
    pin8, pin9, pin10, pin11, pin12, pin13, pin14, pin15};
}

//: 12 bits counter.
void nts::Chipset::create_4040()
{  //: 12 bits counter.

}

//: 8 bits shift register.
void nts::Chipset::create_4094()
{  //: 8 bits shift register.

}

//: 8 channel data selector.
void nts::Chipset::create_4512()
{  //: 8 channel data selector.
    nts::Gate *gate1 = new Gate("Gate1");
    nts::Pin *pin0 = new Pin("0");
    nts::Pin *pin1 = new Pin("1");
    nts::Pin *pin2 = new Pin("2");
    nts::Pin *pin3 = new Pin("3");
    nts::Pin *pin4 = new Pin("4");
    nts::Pin *pin5 = new Pin("5");
    nts::Pin *pin6 = new Pin("6");
    nts::Pin *pin7 = new Pin("7");
    nts::Pin *pin8 = new Pin("8");
    nts::Pin *pin9 = new Pin("9");
    nts::Pin *pin10 = new Pin("10");
    nts::Pin *pin11 = new Pin("11");
    nts::Pin *pin12 = new Pin("12");
    nts::Pin *pin13 = new Pin("13");
    nts::Pin *pin14 = new Pin("14");
    nts::Pin *pin15 = new Pin("15");
    nts::Pin *pin16 = new Pin("16");

    pin1->push_fwd_linked_pin(gate1);
    pin2->push_fwd_linked_pin(gate1);
    pin3->push_fwd_linked_pin(gate1);
    pin4->push_fwd_linked_pin(gate1);
    pin5->push_fwd_linked_pin(gate1);
    pin6->push_fwd_linked_pin(gate1);
    pin7->push_fwd_linked_pin(gate1);
    pin9->push_fwd_linked_pin(gate1);
    gate1->push_fwd_linked_pin(pin10);
    gate1->push_fwd_linked_pin(pin11);
    gate1->push_fwd_linked_pin(pin12);
    gate1->push_fwd_linked_pin(pin13);
    pin14->push_fwd_linked_pin(gate1);
    gate1->push_fwd_linked_pin(pin15);

    gate1->set_link_type("sel");
    this->_pins = {pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7,
    pin8, pin9, pin10, pin11, pin12, pin13, pin14, pin15, pin16};
}

//: 4 bits decoder.
void nts::Chipset::create_4514()
{  //: 4 bits decoder.
    nts::Gate *gate1 = new Gate("Gate1");
    nts::Pin *pin0 = new Pin("0");
    nts::Pin *pin1 = new Pin("1");
    nts::Pin *pin2 = new Pin("2");
    nts::Pin *pin3 = new Pin("3");
    nts::Pin *pin4 = new Pin("4");
    nts::Pin *pin5 = new Pin("5");
    nts::Pin *pin6 = new Pin("6");
    nts::Pin *pin7 = new Pin("7");
    nts::Pin *pin8 = new Pin("8");
    nts::Pin *pin9 = new Pin("9");
    nts::Pin *pin10 = new Pin("10");
    nts::Pin *pin11 = new Pin("11");
    nts::Pin *pin12 = new Pin("12");
    nts::Pin *pin13 = new Pin("13");
    nts::Pin *pin14 = new Pin("14");
    nts::Pin *pin15 = new Pin("15");
    nts::Pin *pin16 = new Pin("16");
    nts::Pin *pin17 = new Pin("17");
    nts::Pin *pin18 = new Pin("18");
    nts::Pin *pin19 = new Pin("19");
    nts::Pin *pin20 = new Pin("20");
    nts::Pin *pin21 = new Pin("21");
    nts::Pin *pin22 = new Pin("22");
    nts::Pin *pin23 = new Pin("23");
    nts::Pin *pin24 = new Pin("24");

    gate1->push_fwd_linked_pin(pin1);
    gate1->push_fwd_linked_pin(pin2);
    gate1->push_fwd_linked_pin(pin3);
    gate1->push_fwd_linked_pin(pin22);
    gate1->push_fwd_linked_pin(pin21);

    pin4->push_fwd_linked_pin(gate1);
    pin5->push_fwd_linked_pin(gate1);
    pin6->push_fwd_linked_pin(gate1);
    pin7->push_fwd_linked_pin(gate1);
    pin8->push_fwd_linked_pin(gate1);
    pin9->push_fwd_linked_pin(gate1);
    pin10->push_fwd_linked_pin(gate1);
    pin11->push_fwd_linked_pin(gate1);
    pin13->push_fwd_linked_pin(gate1);
    pin14->push_fwd_linked_pin(gate1);
    pin15->push_fwd_linked_pin(gate1);
    pin16->push_fwd_linked_pin(gate1);
    pin17->push_fwd_linked_pin(gate1);
    pin18->push_fwd_linked_pin(gate1);
    pin19->push_fwd_linked_pin(gate1);
    pin20->push_fwd_linked_pin(gate1);
    pin23->push_fwd_linked_pin(gate1);

    gate1->set_link_type("dec");

    this->_pins = {pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7,
    pin8, pin9, pin10, pin11, pin12, pin13, pin14, pin15, pin16, pin17, pin18, pin19,
    pin20, pin21, pin22, pin23, pin24,};
}

//: Random access memory.
void nts::Chipset::create_4801()
{  //: Random access memory.

}

//: Read only memory (memory initiliazed for./rom.bin).
void nts::Chipset::create_2716()
{ //: Read only memory (memory initiliazed for./rom.bin).

}
