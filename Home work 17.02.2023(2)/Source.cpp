
#include <iostream>
#include <string>


// ������� �����
class IParcer {
public:
    virtual ~IParcer() {}
    virtual std::string getName() const = 0;
};

// ����������� ������ 
class INI : public IParcer {
public:
    std::string getName() const override {
        return "ParcerINI";
    }
};

class JSON : public IParcer {
public:
    std::string getName() const override {
        return "ParserJSON";
    }
};

class YAML : public IParcer {
public:
    std::string getName() const override {
        return "ParcerYAML";
    }
};



// ��������� �������
class Parcer {
public:
    virtual ~Parcer() {}
    virtual IParcer* createParcer() = 0;
};

// ����������� ������ ������
class ParcerINI : public Parcer {
public:
    IParcer* createParcer() override {
        return new INI();
    }
};

class ParcerJSON : public Parcer {
public:
    IParcer* createParcer() override {
        return new JSON();
    }
};

class ParcerYAML : public Parcer {
public:
    IParcer* createParcer() override {
        return new YAML();
    }
};


int main() {



    ParcerINI parcerINI;
    ParcerJSON parcerJSON;
    ParcerYAML parcerYAML;

    IParcer* INI = parcerINI.createParcer();
    IParcer* JSON = parcerJSON.createParcer();
    IParcer* YAML = parcerYAML.createParcer();

    std::cout << INI->getName() << std::endl; // "INI"
    std::cout << JSON->getName() << std::endl; // "JSON"
    std::cout << YAML->getName() << std::endl; // "YAML"

    delete INI;
    delete JSON;
    delete YAML;

   
}
