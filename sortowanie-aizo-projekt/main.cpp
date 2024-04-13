#include <iostream>,
#include "DataTypePicker.hpp"
#include "ActionTypePicker.hpp"
#include "ActionDataBundler.hpp"

int main()
{
    DataType datatype = DataTypePicker::pick();
    ActionType actiontype = ActionTypePicker::pick();
    ActionDataBundler::bundle(datatype, actiontype);
    return 0;
}