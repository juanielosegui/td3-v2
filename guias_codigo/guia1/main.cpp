#include "funciones.h"
#include "iostream"

int main()
{
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "E.2)" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    std::cout << "sumSign(15, -25): " << std::endl;
    sumSign(15, -25);

    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "E.5)" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    std::cout << "Replace vowels with 'a': " << replaceVowelsWithA("paralelepipedo") << std::endl;

    std::cout << "sumsZero(3, -3): " << sumsZero(3, -3) << std::endl;

    std::cout << "max(10, 9): " << max(10, 9) << std::endl;

    std::cout << "vowelsAmt(\"paralelepipedo\"): " << vowelsAmt("paralelepipedo") << std::endl;
    
    std::cout << "isVowel('e'): "  << isVowel('e') << std::endl;

    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "E.6)" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    std::cout << "closeInBrackets(\"Aclaraciones\"): " << std::endl;
    std::string s = "aclaraciones";
    closeInBrackets(s);

    std::cout << "replaceNumber({10, 5, 10, 25, 10, 30}, 10): " << std::endl;
    std::vector<int> v = {10, 5, 10, 25, 10, 30};
    std::cout << replaceNumber(v, 10) << std::endl;

    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "E.8)" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    std::vector<int> numbers = {25, 827, 600, 45, 913, 105};
    std::cout << "sum({25, 827, 600, 45, 913, 105}): " << std::endl;
    std::cout << sum(v) << std::endl;

    std::cout << "fahrenheitToCelsius(55): " << std::endl;
    std::cout << fahrenheitToCelsius(55) << std::endl;

    std::cout << "printFahrValues30to100(): " << std::endl;
    printFahrValues30to100();

    std::cout << "isPrime(7): " << std::endl;
    std::cout << isPrime(7) << std::endl;

    std::cout << "printPrimesTo100(): " << std::endl;
    printPrimesTo100();

    std::cout << "isPalindrome(\"neuquen\"): " << std::endl;
    std::cout << isPalindrome("neuquen") << std::endl;

    std::cout << "concatenateStr({\"hola\", \"a\", \"todos\"}):" << std::endl;
    std::cout << concatenateStr({"hola", "a", "todos"}) << std::endl;

    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "E.9)" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    std::cout << "redCounter({Red, Black, Blue, Red}): " << std::endl;
    std::cout << redCounter({Color::Red, Color::Black, Color::Blue, Color::Red}) << std::endl;
    
    std::cout << "isWeekend(Sunday)" << std::endl;
    std::cout << isWeekend(Day::Sunday) << std::endl;
    
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "E.10)" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    std::cout << "newUser(\"Juani Elosegui\", \"mail@mail.com\"): " << std::endl;
    user u = newUser("Juani Elosegui", "mail@mail.com");
    std::cout << "Name: " << u.name << ", " << "E-mail: " << u.email << ", " << "Followers: " << u.amtFollowers << std::endl;

    std::cout << "tenYearsApart({\"Juani Elosegui\", 20, \"912\"}, {\"Julian Elosegui\", 14, \"333\"}): " << std::endl;
    std::cout << tenYearsApart({"Juani Elosegui", 20, "912"}, {"Julian Elosegui", 14, "333"}) << std::endl;

    person p1 = {"Juani Elosegui", 20, "912"};
    person p2 = {"Julian Elosegui", 14, "333"};
    person p3 = {"Nicolas Elosegui", 50, "124"};
    person p4 = {"Mariana Escudero", 47, "241"};
    std::cout << "eldestPerson({{\"Juani Elosegui\", 20, \"912\"}, {\"Julian Elosegui\", 14, \"333\"}, {\"Nicolas Elosegui\", 50, \"124\"}, {\"Mariana Escudero\", 47, \"241\"}}): " << std::endl;
    person res = eldestPerson({p1, p2, p3, p4});
    std::cout << res.name << std::endl;

    return 0;
}