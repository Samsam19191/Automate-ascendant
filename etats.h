#include <string>

class Automate;
class Symbole;

class Etat
{
public:
    Etat();
    virtual ~Etat();
    virtual void print() const;
    virtual bool transition(Automate &automate, Symbole *s) = 0;
};

class E0 : public Etat
{
    public :
        E0();
        ~E0();
        bool transition(Automate &automate, Symbole *s);
        virtual void print() const;
};

class E1 : public Etat
{
public:
    E1();
    ~E1();
    bool transition(Automate &automate, Symbole *s);
    virtual void print() const;
};

class E2 : public Etat
{
public:
    E2();
    ~E2();
    bool transition(Automate &automate, Symbole *s);
    virtual void print() const;
};

class E3 : public Etat
{
public:
    E3();
    ~E3();
    bool transition(Automate &automate, Symbole *s);
    virtual void print() const;
};

class E4 : public Etat
{
public:
    E4();
    ~E4();
    bool transition(Automate &automate, Symbole *s);
    virtual void print() const;
};

class E5 : public Etat
{
public:
    E5();
    ~E5();
    bool transition(Automate &automate, Symbole *s);
    virtual void print() const;
};

class E6 : public Etat
{
public:
    E6();
    ~E6();
    bool transition(Automate &automate, Symbole *s);
    virtual void print() const;
};

class E7 : public Etat
{
public:
    E7();
    ~E7();
    bool transition(Automate &automate, Symbole *s);
    virtual void print() const;
};

class E8 : public Etat
{
public:
    E8();
    ~E8();
    bool transition(Automate &automate, Symbole *s);
    virtual void print() const;
};

class E9 : public Etat
{
public:
    E9();
    ~E9();
    bool transition(Automate &automate, Symbole *s);
    virtual void print() const;
};