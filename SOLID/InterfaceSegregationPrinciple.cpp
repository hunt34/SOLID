#include <iostream>
using namespace std;


struct Document
{
    string content = "";
    Document(string val)
    {
        content+=val ;
    }
};

struct IPrinter
{
    virtual void print(Document* doc) = 0;
};

struct IScanner
{
    virtual void scan(Document* doc) = 0;
};

struct IFax
{
    virtual void fax(Document* doc) = 0;
};

struct Printer : IPrinter
{
    void print(Document* doc) override
    {
        cout << "Printer::print" << endl;
    }
};

struct Scanner : IScanner
{
    void scan(Document* doc) override
    {
        cout << "Scanner::scan" << endl;
    }
};

struct IMachine : IPrinter , IScanner{};

struct Machine : IMachine
{
    IPrinter* printer;
    IScanner* scanner;

    Machine() : printer{new Printer{}}, scanner{new Scanner{}} {}

    void print(Document* doc) override
    {
        printer->print(doc);
    }
    void scan(Document* doc) override
    {
        scanner->scan(doc);
    }

};


int main()
{
    Scanner scanner;
    scanner.scan(new Document{"scan doc"});

    Printer printer;
    printer.print(new Document{"print doc"});

    Machine m;
    m.print(new Document{"print doc"});
    m.scan(new Document{"scan doc"});
    return 0;
}