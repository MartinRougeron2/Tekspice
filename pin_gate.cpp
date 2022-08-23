/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-tekspice-martin.rougeron
** File description:
** pin_gate
*/

#include "IComponent.hpp"

nts::Tristate NOT(nts::Tristate boolean)
{
    if (boolean == nts::UNDEFINED)
        return nts::UNDEFINED;
    else if (boolean == nts::TRUE)
        return nts::Tristate(false);
    return nts::Tristate(true);
}


nts::Tristate nts::Pin::AND_gate(std::vector<nts::Pin *> A, int output)
{
    (void)output;
    if (A[0]->get_state() == FALSE || A[1]->get_state() == FALSE)
        return FALSE;
    if (A[0]->get_state() == UNDEFINED || A[1]->get_state() == UNDEFINED)
        return UNDEFINED;
    return TRUE;
}

nts::Tristate nts::Pin::OR_gate(std::vector<nts::Pin *> A, int output)
{
    (void)output;
    if (A[0]->get_state() == TRUE || A[1]->get_state() == TRUE)
        return TRUE;
    if (A[0]->get_state() == UNDEFINED || A[1]->get_state() == UNDEFINED)
        return UNDEFINED;
    return FALSE;
}

nts::Tristate nts::Pin::NOT_gate(std::vector<nts::Pin *> A, int output)
{
    (void)output;
    return NOT(A[0]->get_state());
}

nts::Tristate nts::Pin::EQ_gate(std::vector<nts::Pin *> A, int output)
{
    (void)output;
    return nts::Tristate((A[0]->get_state()));
}

nts::Tristate nts::Pin::NAND_gate(std::vector<nts::Pin *> A, int output)
{
    (void)output;
    return NOT(A[0]->AND_gate(A, output));
}

nts::Tristate nts::Pin::NOR_gate(std::vector<nts::Pin *> A, int output)
{
    (void)output;
    return NOT(A[0]->OR_gate(A, output));
}

nts::Tristate nts::Pin::EOR_gate(std::vector<nts::Pin *> A, int output)
{
    (void)output;
    return nts::Tristate((A[0]->get_state() != A[1]->get_state()));
}

nts::Tristate nts::Pin::ENOR_gate(std::vector<nts::Pin *> A, int output)
{
    (void)output;
    return nts::Tristate((A[0]->get_state() == A[1]->get_state()));
}

nts::Tristate nts::Pin::FLIP_gate(std::vector<nts::Pin *> A, int output)
{
    (void)output;
    return A[0]->get_state();
}

nts::Tristate nts::Pin::DECADE_gate(std::vector<nts::Pin *> A, int output)
{
    (void)output;
    return A[0]->get_state();
}

nts::Tristate nts::Pin::ADD_gate(std::vector<nts::Pin *> A, int output)
{
    (void)output;
    return A[0]->get_state();
}

nts::Tristate nts::Pin::DEC_gate(std::vector<nts::Pin *> A, int output)
{
    (void)output;
        if (A[0]->get_state() == UNDEFINED || A[1]->get_state() == UNDEFINED || A[2]->get_state() == UNDEFINED || A[3]->get_state() == UNDEFINED)
        return UNDEFINED;
    return nts::Tristate((A[0]->get_state() == UNDEFINED && A[1]->get_state() == UNDEFINED && A[2]->get_state() == UNDEFINED && A[3]->get_state() == UNDEFINED));
}

nts::Tristate nts::Pin::SEL_gate(std::vector<nts::Pin *> A, int output)
{
    if (A[0]->get_state() == nts::Tristate(UNDEFINED) ||
    A[1]->get_state() == nts::Tristate(UNDEFINED) ||
    A[2]->get_state() == nts::Tristate(UNDEFINED))
        return UNDEFINED;
    int res = A[0]->get_state() + A[1]->get_state() * 2 + A[2]->get_state() * 4;
    if (res == 0 && output == 0)
        return TRUE;
    else if (res == 4 && output == 1)
        return TRUE;
    else if (res == 2 && output == 2)
        return TRUE;
    else if (res == 6 && output == 3)
        return TRUE;
    else if (res == 1 && output == 4)
        return TRUE;
    else if (res == 5 && output == 5)
        return TRUE;
    else if (res == 3 && output == 6)
        return TRUE;
    else if (res == 7 && output == 7)
        return TRUE;
    else
        return FALSE;
}
