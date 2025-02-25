enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, EXPR, ERREUR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "EXPR", "ERREUR" };

class Symbole {
    protected:
    int ident;
    bool terminal;
    public:
    Symbole(int id) : ident(id) {}
    virtual ~Symbole() {}
    void print();
    operator int() const { return ident; }
    };