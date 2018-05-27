#include "Form.h"

Form::Form(int p) : pre(p), format(0){
}

Form::~Form(){}

Form& Form::operator=(Form& form){
    form.precision(this->pre);

    return form;
}

ostream& operator<<(ostream& os, const Form& form){
    ostringstream oss;

    oss.precision(form.getPrecision());
    oss.setf((std::ios_base::fmtflags)form.getFormat(), std::ios_base::floatfield);
    oss << form.getValue();

    return os << oss.str();
}

Form& Form::operator()(double d){
    this->value = d;
    return *this;
}

Form& Form::scientific(){
    this->format = std::ios_base::scientific;
    
    return *this;
}

Form& Form::fixed(){
    this->format = std::ios_base::fixed;

    return *this;
}

Form& Form::precision(int p){
    this->pre = p;

    return *this;
}

int Form::getPrecision() const{
    return this->pre;
}

int Form::getFormat() const{
    return this->format;
}

double Form::getValue() const{
    return this->value;
}
