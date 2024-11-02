#include "funciones.h"

int main()
{
    cout << "------------------------------------------------" << endl;
    cout << "E.2)" << endl;
    cout << "------------------------------------------------" << endl;

    cout << "sumSign(15, -25): " << endl;
    sumSign(15, -25);

    cout << "------------------------------------------------" << endl;
    cout << "E.5)" << endl;
    cout << "------------------------------------------------" << endl;

    cout << "Replace vowels with 'a': " << replaceVowelsWithA("paralelepipedo") << endl;

    cout << "sumsZero(3, -3): " << sumsZero(3, -3) << endl;

    cout << "max(10, 9): " << max(10, 9) << endl;

    cout << "vowelsAmt(\"paralelepipedo\"): " << vowelsAmt("paralelepipedo") << endl;
    
    cout << "isVowel('e'): "  << isVowel('e') << endl;

    cout << "------------------------------------------------" << endl;
    cout << "E.6)" << endl;
    cout << "------------------------------------------------" << endl;

    cout << "closeInBrackets(\"Aclaraciones\"): " << endl;
    string s = "aclaraciones";
    closeInBrackets(s);

    cout << "replaceNumber({10, 5, 10, 25, 10, 30}, 10): " << endl;
    vector<int> v = {10, 5, 10, 25, 10, 30};
    cout << replaceNumber(v, 10) << endl;

    cout << "------------------------------------------------" << endl;
    cout << "E.8)" << endl;
    cout << "------------------------------------------------" << endl;

    vector<int> numbers = {25, 827, 600, 45, 913, 105};
    cout << "sum({25, 827, 600, 45, 913, 105}): " << endl;
    cout << sum(v) << endl;

    cout << "fahrenheitToCelsius(55): " << endl;
    cout << fahrenheitToCelsius(55) << endl;

    cout << "printFahrValues30to100(): " << endl;
    printFahrValues30to100();

    cout << "isPrime(7): " << endl;
    cout << isPrime(7) << endl;

    cout << "printPrimesTo100(): " << endl;
    printPrimesTo100();

    cout << "isPalindrome(\"neuquen\"): " << endl;
    cout << isPalindrome("neuquen") << endl;

    cout << "concatenateStr({\"hola\", \"a\", \"todos\"}):" << endl;
    cout << concatenateStr({"hola", "a", "todos"}) << endl;

    cout << "------------------------------------------------" << endl;
    cout << "E.9)" << endl;
    cout << "------------------------------------------------" << endl;

    cout << "redCounter({Red, Black, Blue, Red}): " << endl;
    cout << redCounter({Color::Red, Color::Black, Color::Blue, Color::Red}) << endl;
    
    cout << "isWeekend(Sunday)" << endl;
    cout << isWeekend(Day::Sunday) << endl;
    
    cout << "------------------------------------------------" << endl;
    cout << "E.10)" << endl;
    cout << "------------------------------------------------" << endl;

    cout << "newUser(\"Juani Elosegui\", \"mail@mail.com\"): " << endl;
    user u = newUser("Juani Elosegui", "mail@mail.com");
    cout << "Name: " << u.name << ", " << "E-mail: " << u.email << ", " << "Followers: " << u.amtFollowers << endl;

    cout << "tenYearsApart({\"Juani Elosegui\", 20, \"912\"}, {\"Julian Elosegui\", 14, \"333\"}): " << endl;
    cout << tenYearsApart({"Juani Elosegui", 20, "912"}, {"Julian Elosegui", 14, "333"}) << endl;

    person p1 = {"Juani Elosegui", 20, "912"};
    person p2 = {"Julian Elosegui", 14, "333"};
    person p3 = {"Nicolas Elosegui", 50, "124"};
    person p4 = {"Mariana Escudero", 47, "241"};
    cout << "eldestPerson({{\"Juani Elosegui\", 20, \"912\"}, {\"Julian Elosegui\", 14, \"333\"}, {\"Nicolas Elosegui\", 50, \"124\"}, {\"Mariana Escudero\", 47, \"241\"}}): " << endl;
    person res = eldestPerson({p1, p2, p3, p4});
    cout << res.name << endl;

    return 0;
}