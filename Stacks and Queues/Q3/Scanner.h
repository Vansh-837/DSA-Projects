/* 
 * Scanner.h 
 *
 * Description: Token scanner.  
 *              Given an input stream, will return a sequence
 *              of Tokens via successive calls to .getnext();
 *
 * Author:
 * Date:
 */
 
#ifndef SCANNER_H_
#define SCANNER_H_

#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

///////////////
// TokenType //
//           //////////////////
//  symbols:  +, -, *, /, (, )
// literals:  integer
//  special:  eof, err
///////////////////////////////
typedef enum { pltok, mitok, asttok, slashtok, lptok, rptok, integer, errtok, eof }
TokenType ;


//---------//
//  Token  //
//---------//
class Token {
    public:
        TokenType tt;
        string text;
        int val;
};


// Description: Display a Token
ostream &operator<<(ostream &lhs, Token &rhs);


// Description: Token scanner.  Given an input stream, will return a sequence
//       of Tokens via successive calls to .getnext();
class Scanner {
    private:
        int line;
        istream *str;
        char buf[2];
    public:
        Scanner(istream &str);
        Token getnext();
};

#endif 
