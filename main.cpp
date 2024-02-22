#include <iostream>
#include <cstring>
using namespace std;
class User
{
private:
    char *name;
    char *telephone;
    int age;

protected:
    char *password;

public:
    User(char *, char *, char *, int);
    virtual bool logIn(const char *) = 0;
    void logOut();
    bool changePassword(char *oldPass, char *newPass);
};
User::User(char *name, char *password, char *telephone, int age)
{
    this->name = name;
    this->telephone = telephone;
    this->password = password;
    this->age = age;
}
void User::logOut()
{
    cout << "Logging Out..." << endl;
}
bool User::changePassword(char *oldPass, char *newPass)
{
    if (strcmp(oldPass, password) == 0)
    {
        password = newPass;
        return true;
    }
    else
    {
        return false;
    }
}
class Client : public User
{
public:
    Client(char *name, char *password, char *telephone, int age) : User(name, password, telephone, age){};
    bool logIn(const char *password);
    void comprar();
    void reclamar();
    void devolver();
};
bool Client::logIn(const char *password)
{
    if (strcmp(password, this->password) == 0)
    {
        cout << "Client ";
        return true;
    }
    else
    {
        return false;
    }
}
void Client::reclamar()
{
    cout << "Complainaing about Something" << endl;
}
void Client::comprar()
{
    cout << "Buying Something" << endl;
}
void Client::devolver()
{
    cout << "Returning Something" << endl;
}

class Seller : public User
{
public:
    Seller(char *name, char *password, char *telephone, int age) : User(name, password, telephone, age){};
    bool logIn(const char *password);
    void vender();
    void actualizarInventario();
};
bool Seller::logIn(const char *password)
{
    if (strcmp(password, this->password) == 0)
    {
        cout << "Seller ";
        return true;
    }
    else
    {
        return false;
    }
}
void Seller::vender()
{
    cout << "Selling Something" << endl;
}

void Seller::actualizarInventario()
{
    cout << "Updating Inventory" << endl;
}
void checkLogin(User &user, char *password)
{
    if (user.logIn(password))
    {
        cout << "Logged Successfully" << endl;
    }
    else
    {
        cout << "Wrong Password" << endl;
    }
}

int main()
{
    Client client = Client("Cliente1", "password1", "3311495152", 20);
    checkLogin(client, "password1");
    if(client.changePassword("password1", "newpassword1")){
        cout<<"Successfully changed password"<<endl;
    }else{
        cout<<"Error, old password doesnt match"<<endl;
    }
    checkLogin(client, "password1");
    checkLogin(client, "newpassword1");
    Seller seller = Seller("Seller1", "password2", "3336147698", 21);
    checkLogin(seller, "password2");
    if(seller.changePassword("password1", "newpassword2")){
        cout<<"Successfully changed password"<<endl;
    }else{
        cout<<"Error, old password doesnt match"<<endl;
    }
    checkLogin(seller, "newpassword2");
    checkLogin(seller, "password2");
    client.comprar();
    client.devolver();
    client.reclamar();
    seller.vender();
    seller.actualizarInventario();
    client.logOut();
    seller.logOut();
    return 0;
}
