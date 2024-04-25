#include <iostream>,
#include "DataTypePicker.hpp"
#include "ActionTypePicker.hpp"
#include "ActionDataBundler.hpp"
#include "RandomFloatGenerator.hpp"

int main()
{
    DataType datatype = DataTypePicker::pick();
    ActionType actiontype = ActionTypePicker::pick();
    ActionDataBundler::bundle(datatype, actiontype);
    std::cin.ignore(1);
    std::cout << "Nacisnij dowolny klawisz aby zakonczyc program." << std::endl;
    std::cin.get();
    return 0;
}