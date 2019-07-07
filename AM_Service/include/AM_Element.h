#ifndef AM_ELEMENT_H
#define AM_ELEMENT_H

class IElement {

protected:
    int pin;

public:
    IElement(int tpin) : pin(tpin) {}
    virtual ~IElement() {};
    virtual bool init() = 0;
};

#endif
