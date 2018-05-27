#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <sstream>
#include <iomanip>

using std::ostream;
using std::ostringstream;

class Form {

public:
    Form(int p);
    
    virtual ~Form();

    Form& operator=(Form& form);
    friend ostream& operator<<(ostream& os, const Form& form);
    Form& operator()(double d);
    Form& scientific();
    Form& fixed();
    Form& precision(int p);

    int getPrecision() const;
    int getFormat() const;
    double getValue() const;
private:
    int pre;
    int format;
    double value;
};

#endif
