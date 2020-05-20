#include <iostream>
#include "Object.h"
#include "Person.h"
#include "Emloyee.h"
#include "Vector.h"
#include "Dialog.h"
using namespace std;

void main()
{
    cout << "Commands:\n>m(size) \t*Create new array;\n>+ \t\t*Add new element;\n>- \t\t*Delete element;\n>s \t\t*Show human class type;\n>z(number) \t*Show human name for number;\n>q \t\t*Command for exit;\n\n\n";
    Dialog D;
    D.Execute();
}
